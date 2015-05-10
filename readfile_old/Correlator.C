/*Correlator.C
  Author: David Perez-Loureiro
  Date: June 2014 
*/

/********************************************/
/* Correlation flags:                       */
/*                                          */
/*   4 - invalid DSSD implant pixel         */
/*   8 - invalid DSSD decay pixel           */
/*  12 - implantation event                 */
/*  16 - decay event                        */
/*  20 - unknown event                      */
/*  24 - front, no back decay               */
/*  28 - back, no front decay               */
/*  32 - back-2-back implantations          */
/*  36 - back-2-back decays                 */
/*  40 - invalid implant time               */
/*  44 - invalid decay time                 */
/*  48 - exceeded correlation time          */
/*  52 - long-lived implant rejection       */
/*  56 - reset correlation array            */
/*  72 - no implant                         */
/*                                          */
/********************************************/


#include<iostream>

#include "Correlator.h"
#include "BetaDecay.h"

#define CORRELATION 1

using namespace std;


ClassImp(Correlator)

Bool_t resetFlag=kTRUE;
Double_t Min_implant_time= 1.;
Double_t Clock_scale = 1.;
Double_t Clock_max = 50.; //ms

Correlator::Correlator(){

P26=new TCutG("good PID",17);

 P26->SetPoint(0,10862.3,13017.2);
 P26->SetPoint(1,11215.8,13097.9);
 P26->SetPoint(2,11542.9,12914.5);
 P26->SetPoint(3,11896.3,12540.3);
 P26->SetPoint(4,12149.5,11975.4);
 P26->SetPoint(5,11980.7,11417.8);
 P26->SetPoint(6,11611.4,11080.3);
 P26->SetPoint(7,11147.2,10926.2);
 P26->SetPoint(8,10698.8,10896.9);
 P26->SetPoint(9,10355.9,11131.6);
 P26->SetPoint(10,10139.6,11461.8);
 P26->SetPoint(11,10023.5,11975.4);
 P26->SetPoint(12,10065.7,12290.8);
 P26->SetPoint(13,10218.7,12562.3);
 P26->SetPoint(14,10435,12745.7);
 P26->SetPoint(15,10519.4,12841.1);
 P26->SetPoint(16,10862.3,13017.2);

}

Correlator::~Correlator(){
delete P26 ;
}

void Correlator::Reset(){

  eventcount=0;


  for(Int_t i=0;i<16;i++){
    for(Int_t j=0;j<16;j++){
      
      theImplant[i][j].implanted=kFALSE;
      theImplant[i][j].timehigh=0;
      theImplant[i][j].timelow=0;
      theImplant[i][j].timecfd=0;
      
      theImplant[i][j].time=0;
      
      theImplant[i][j].dE1=0;
      theImplant[i][j].dE2=0;
      
      theImplant[i][j].implant_sum=0;
      theImplant[i][j].implant_max=0;
      
      theImplant[i][j].tof=0;
      
      theImplant[i][j].dt=0;
      
      theImplant[i][j].numcorr=0;
      
      theDecay[i][j].timehigh=0;
      theDecay[i][j].timelow=0;
      theDecay[i][j].timecfd=0;

      theDecay[i][j].time=0;

      theDecay[i][j].dE1=0;
      theDecay[i][j].dE2=0;
      
      theDecay[i][j].implant_sum=0;
      theDecay[i][j].implant_max=0;

      theDecay[i][j].tof=0;

      theDecay[i][j].dt=0;
  
      theDecay[i][j].dt_decay=0;  
      
      theDecay[i][j].dnumcorr=0;
      
    }
  }
 
}


Double_t Correlator::Correlate(BetaDecay* theBetaDecay){

  //cout<<"I am inside the correlator"<<endl;

  eventcount++;

  //Define auxiliary variables


  Double_t outval;

  Int_t returnval;

  Int_t numcorr =-1;
  Int_t condition=0;
  Int_t resetcheck=0;

  Int_t implant_backch=100;
  Int_t implant_frontch=100;

  Int_t decay_backch=100;
  Int_t decay_frontch=100;

  Int_t implant_frontmult=0;
  Int_t implant_backmult=0;

  Bool_t implant_event=kFALSE;
  Bool_t implant_tof=kFALSE;

  Bool_t decay_event=kFALSE;

  Bool_t sega_only=kFALSE;

  Bool_t unknown_event =kFALSE;

  Bool_t decay_energy=kFALSE;

  Bool_t implanted=kFALSE;


  if(resetFlag){
    cout<<"Reseting Correlator..."<<endl;
    Correlator::Reset();
    resetcheck=56;
    resetFlag=kFALSE;
  }





  //Implant decay Correlations

  //Implant Location
  implant_frontch=theBetaDecay->thefrontGeDSSD.implant_max_channel;
  implant_backch=theBetaDecay->thebackGeDSSD.implant_max_channel;

 


  //Decay Location
  decay_frontch=theBetaDecay->thebackGeDSSD.decay_max_channel;
  decay_backch=theBetaDecay->thebackGeDSSD.decay_max_channel;

  //Low gain events in Pin1,Pin2 and GeDSSD -> Implant 

  if(theBetaDecay->thepin1.hit&&theBetaDecay->thepin2.hit&&theBetaDecay->thefrontGeDSSD.Lohit&&theBetaDecay->thebackGeDSSD.Lohit){
    implant_event=kTRUE;
    returnval=+2;
  }

  else
    implant_event=kFALSE;

  //Checking PID

  if(P26->IsInside(theBetaDecay->thePID.xfptof,theBetaDecay->thePID.de1))
    implant_event=kTRUE;
  else
    implant_event=kFALSE;

  //Hi gain events with no Pin1,Pin2 -> Decay

  if(!theBetaDecay->thepin1.hit&&!theBetaDecay->thepin2.hit&&theBetaDecay->thefrontGeDSSD.Hihit&&theBetaDecay->thebackGeDSSD.Hihit){
    decay_event=kTRUE;
    returnval=+16;
  }
    

  //SeGA only events - correlated with implants for isomers

  if(!theBetaDecay->thepin1.hit&&!theBetaDecay->thepin2.hit&&!theBetaDecay->thefrontGeDSSD.Lohit&&!theBetaDecay->thebackGeDSSD.Lohit
     &&!theBetaDecay->thefrontGeDSSD.Hihit&&!theBetaDecay->thebackGeDSSD.Hihit&&theBetaDecay->theSega.hit){
    sega_only=kTRUE;
    returnval+=64;
  }

  //Construct the full time

  Double_t current_time=0;

  current_time=ULong_t(theBetaDecay->theClock.fast*10+theBetaDecay->theClock.slow*10*4294967296)/1000000.; //time in ms

  //DPL clock

 
  //IMPLANTS

  if(implant_event){
    
    //check for implantation pixel in GeDSSD

    if((implant_backch>=0&&implant_backch<16)&&(implant_frontch>=0&&implant_frontch<16)){

      condition=12;
      returnval=1024;

      // if(theImplant[implant_backch][implant_frontch].implanted)
      // 	condition=32;
      // else
	theImplant[implant_backch][implant_frontch].implanted=kTRUE;	

      Double_t implant_time=0;      
      implant_time=ULong_t(theImplant[implant_backch][implant_frontch].timelow*10+theImplant[implant_backch][implant_frontch].timehigh*10*4294967296)/1000000.;

      
      if(implant_time>current_time)
	condition=40;
      
      Double_t deltaT;
      
      deltaT=current_time-implant_time;
      
      //cout<<"delta_time "<<deltaT<<endl;
     
      theImplant[implant_backch][implant_frontch].dt=deltaT; //in ms
	
	//Update times
      theImplant[implant_backch][implant_frontch].time=current_time;
      theImplant[implant_backch][implant_frontch].timelow=theBetaDecay->theClock.fast;
      theImplant[implant_backch][implant_frontch].timehigh=theBetaDecay->theClock.slow;
      theImplant[implant_backch][implant_frontch].timecfd=theBetaDecay->theClock.cfd;
      theImplant[implant_backch][implant_frontch].tof=theBetaDecay->thePID.xfptof;
      
      //Update energies
      theImplant[implant_backch][implant_frontch].dE1=theBetaDecay->thePID.de1;
      theImplant[implant_backch][implant_frontch].dE2=theBetaDecay->thePID.de2;
      
      //Reset Counter
      theImplant[implant_backch][implant_frontch].numcorr=0;
      
      //Store the information in theBetaDecay Correlator class

      theBetaDecay->theCorrelator.dt_implant=theImplant[implant_backch][implant_frontch].dt;
      theBetaDecay->theCorrelator.implant_time=theImplant[implant_backch][implant_frontch].time;
      theBetaDecay->theCorrelator.implant_de1=theImplant[implant_backch][implant_frontch].dE1;
      theBetaDecay->theCorrelator.implant_de2=theImplant[implant_backch][implant_frontch].dE2;
      theBetaDecay->theCorrelator.implant_tof=theImplant[implant_backch][implant_frontch].tof;
      // theBetaDecay->theCorrelator.front_implant_max_channel=implant_frontch;
      // theBetaDecay->theCorrelator.back_implant_max_channel=implant_backch;
      
    } //if((implant_backch>=0&&implant_backch<16)&&(imp...
    else
      condition = 4;
    
  }//if(implant_event)
  
  else if(decay_event){

    returnval+=2048;

    Int_t num_corr=0;
    
    //Search over the nearest pixels to find the most recent implant to correlate

    Int_t corr_limit=(CORRELATION -1)/2;
    Int_t frontLoLimit=decay_frontch-corr_limit;
    Int_t frontHiLimit=decay_frontch+corr_limit;
    Int_t backLoLimit=decay_backch-corr_limit;
    Int_t backHiLimit=decay_backch+corr_limit;

    Int_t front=500;
    Int_t back=500;

    Int_t tdiffold = 1000000000;
    
    //Loop on neighboring pixels
    for(Int_t k=frontLoLimit;k<frontHiLimit+1;k++){
      for(Int_t l=backLoLimit;l<backHiLimit+1;l++){
	if( (k >=0) && (k<16) && (l>=0) && l<16){
	  if(theImplant[l][k].implanted){
	    implanted=kTRUE;
	    Double_t temp_implant_time=ULong_t(theImplant[l][k].timelow*10+theImplant[l][k].timehigh*10*4294967296)/1000000.; //ms
	    Double_t time_diff=current_time-temp_implant_time;
	    //cout<<"temp_implant_time "<<temp_implant_time<<" "<<time_diff<<endl;
	    if(time_diff<tdiffold && time_diff>0){
	      num_corr++;
	      tdiffold=time_diff;
	      front=k;
	      back=l;
	    }
	  }
	}
      }
    }//for(In_t k=frontLoLimit;k<frontHiLimit+1;k++)

    if(implanted){

      //Store the information in theBetaDecay Correlator
      theBetaDecay->theCorrelator.implant_mult=num_corr;
 

      if( (front>=0) && (front<16) && (back>=0) && back<16){
	condition=16;

	if(theImplant[back][front].implanted){
	  Double_t implant_time=0;
	  implant_time=ULong_t(theImplant[back][front].timelow*10+theImplant[back][front].timehigh*10*4294967296)/1000000.; 
	  Double_t decay_time=0;
	  decay_time=ULong_t(theDecay[back][front].timelow*10+theDecay[back][front].timehigh*10*4294967296)/1000000.; 
	  



	  if(implant_time>current_time)
	    condition=44;
	  Double_t deltaT;
	  deltaT=current_time-implant_time; //ms

	  //cout<<"current"<<current_time<<" Implant "<<implant_time<<"DeltaT "<<deltaT<<" ClockMax "<<Clock_max<<endl;
	  
	  if(theImplant[back][front].dt>=Min_implant_time*Clock_scale || theImplant[back][front].dt==0){
	    if(deltaT<Clock_max){
	      //DPL
	      //cout<<"Here!"<<endl;	      
	      theDecay[back][front].time=theBetaDecay->theClock.current;
	      theDecay[back][front].timehigh=theBetaDecay->theClock.slow;
	      theDecay[back][front].timelow=theBetaDecay->theClock.fast;
	      theDecay[back][front].timecfd==theBetaDecay->theClock.cfd;
	      theDecay[back][front].dt=theImplant[back][front].dt;
	      theDecay[back][front].dE1=theImplant[back][front].dE1;
	      theDecay[back][front].dE2=theImplant[back][front].dE2;
	      theDecay[back][front].tof=theImplant[back][front].tof;
	      theDecay[back][front].dt_decay=deltaT;
	      theImplant[back][front].numcorr++;
	      theDecay[back][front].dnumcorr=theImplant[back][front].numcorr;

	      //Store the information in theBetaDecay Correlator

	      theBetaDecay->theCorrelator.decay_timecal=theDecay[back][front].dt*Clock_scale;
	      theBetaDecay->theCorrelator.decay_time=theDecay[back][front].time;
	      theBetaDecay->theCorrelator.decay_de1=theDecay[back][front].dE1;
	      theBetaDecay->theCorrelator.decay_de2=theDecay[back][front].dE2;
	      theBetaDecay->theCorrelator.decay_tof=theDecay[back][front].tof;
	      theBetaDecay->theCorrelator.decay_mult=theDecay[back][front].dnumcorr;
	      theBetaDecay->theCorrelator.front_decay_max_channel=decay_frontch;
	      theBetaDecay->theCorrelator.back_decay_max_channel=decay_backch;
	      theBetaDecay->theCorrelator.front_implant_max_channel=implant_frontch;
	      theBetaDecay->theCorrelator.back_implant_max_channel=implant_backch;
      
	      // for(Int_t ch=0;ch<16;ch++){
	      // 	if(theBetaDecay->theSega.energycal[ch])
	      // 	  theBetaDecay->theSega.goodenergy[ch]=theBetaDecay->theSega.energycal[ch];
	      // 	  else
	      // 	    continue;
	      // }


	    }//if(deltaT<Clock_max)
	    else
	      condition=48;
	  }//if(theImplant[back][front].dt>=Min_implant_
	  else 
	    condition=52;
	}//if(theImplant[back][front].implanted)
	else
	  condition =36;     
      }//if( (front>=0) && (front<16) && (back>=0) && back<16){
      else
	condition = 8;
    }//if(implanted)
    else
      condition = 72;
    
    if(theBetaDecay->thefrontGeDSSD.decay_max >0 && theBetaDecay->thebackGeDSSD.decay_max>0){
      ; //correlations with gammas
    }
  }//else if(decay_event)
  
  else if(sega_only){
    condition=120;
    returnval=8192;

    Double_t    dt=100000;
    Double_t dE1;
    Double_t dE2;
    Double_t tof;

    //Look for implants

    for(Int_t i=0;i<16;i++){
      for(Int_t j=0;j<16;j++){
	if(theImplant[i][j].implanted){
	  if(current_time!=0){
	    Double_t min_imp_time;
	    Double_t implant_time=0;
	    implant_time=ULong_t(theImplant[i][j].timelow*10+theImplant[i][j].timehigh*10*4294967296)/1000000.;
	    Double_t deltaT;
	    deltaT=current_time-implant_time;
	    if(implant_time>current_time)
	      condition=144;
	    if(deltaT>0 &&deltaT<0.2 ) {// 200us
	      dt=theImplant[i][j].dt;
	      if(deltaT<dt){

		dt=deltaT*1000; //us
		dE1=theImplant[i][j].dE1;
		dE2=theImplant[i][j].dE2;
		tof=theImplant[i][j].tof;
	      }//if(deltaT<dt)
	    }//if(deltaT>0 &&deltaT<0.2 )
	  }//if(current_time!=0)
	}//if(theImplant[i][j].implanted)
      }//for(Int_t j=0;j<16<j++)
    }//for(Int_t i=0;i<16;i++)

    theBetaDecay->theCorrelator.gamma_timecal=dt*Clock_scale;
    theBetaDecay->theCorrelator.gamma_de1=dE1;
    theBetaDecay->theCorrelator.gamma_de2=dE2;
    theBetaDecay->theCorrelator.gamma_tof=tof;
    
  }//else if(sega_only)

  else{
    unknown_event=kTRUE;
    condition=20;
    if(theBetaDecay->thefrontGeDSSD.Hihit&&!theBetaDecay->thebackGeDSSD.Hihit)
      condition=24;
    if(!theBetaDecay->thefrontGeDSSD.Hihit&&theBetaDecay->thebackGeDSSD.Hihit)
      condition=28;

  }  
 
  if (resetcheck != 0) {
    condition = resetcheck; /* Reset array flag */
  }
  
  theBetaDecay->theCorrelator.flag=condition;

  //return returnval;
  return condition;
  
}//Correlate
