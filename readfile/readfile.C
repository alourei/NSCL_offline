//Simple Analysis file for 31Cl experiment
//DPL 02/26/2014
//DPL 02/27/2014 Solved Problem with statistics
#include <TTree.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1I.h>
#include <TH2F.h>
#include <TCanvas.h>
#include <TSystem.h>
#include <iostream>
#include <vector>
#include <cmath>
//#include "/projects/e12028/ddasdumper/libddaschannel.so"
#include "/user/e14066/ddasdumper/DDASEvent.h"
#include "/user/e14066/ddasdumper/ddaschannel.h"
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "readfile.h"
#include "BetaDecay.h"
//#include "Correlator.h"


#define VERBOSE 0
#define DEBUG 0

#define NUM_DETECTORS 16
#define NUM_STRIPS 16



//vector <ddaschannel*> channellist;
//vector <ddaschannel*>::iterator channellist_it;


//Correlator theCorrelator;

//TH2F *pid=new TH2F("PID","Pid",1024,5000,25000,1024,0,32768);
Int_t total_number=0;
//TCanvas *canvas=new TCanvas();
//void readfile_fun(const Char_t*,const Int_t,const Char_t *);




//Thresholds for Sega
UInt_t SegaThreshold[16];


//Thresholds for the PINs
UInt_t Pin1Threshold=100;
UInt_t Pin1ImplantThreshold=7000;
UInt_t Pin2Threshold=20;
UInt_t Pin2ImplantThreshold=8000;

//Thresholds for the Scint
UInt_t ScintThreshold=10;


//Calibration Parameters Pins
Double_t Pin1Slope=1;
Double_t Pin1Intercept=0;
Double_t Pin2Slope=1;
Double_t Pin2Intercept=0;

//Calibration Parameters SeGA
Double_t SegaSlope[16];
Double_t SegaIntercept[16];



void readfile_fun(const Char_t* run_name,const Int_t numberOfFiles,const Char_t * outputname)
{


  srand(time(NULL));
  Int_t timewindow = 1000; // *10 ns
  Int_t startTime=time(NULL);
  Char_t filename[256];
  Int_t event_count=0;
  Int_t decays=0;
  //TFile *file=new TFile(runname);
  //TTree *T=(TTree*)file->Get("dchan");


  UInt_t lasttimelow;
  UInt_t lasttimehigh;

  UInt_t currenttimelow;
  UInt_t currenttimehigh;

  Double_t lastcompoundtime;
  Double_t currentcompoundtime;

  Double_t lasttime;
  Double_t currenttime;
  
  TChain *T= new TChain("dchan");
  

  Char_t dummy[256];
  Char_t dummy2[256];
  Char_t runname[256];

  Char_t cona[256];

  strcpy(dummy,run_name);

  sprintf(runname,"/events/e14066/rootdata/%s",dummy);

  cout<<runname<<endl;

  for(Int_t i=0;i<numberOfFiles;i++)
    {
      sprintf(filename,"%s-%d.root",runname,i);
      T->Add(filename);
      cout<<filename<<" attached to Chain"<<endl;
    }

  //Pointer to the DDAS Event
  DDASEvent *theDDASevent=new DDASEvent();
  T->SetBranchAddress("ddasevent",&theDDASevent);
  
  //Pointer to the BetaDecay
  BetaDecay *theBetaDecay=new BetaDecay();
	
  TFile *outFile=new TFile(outputname,"RECREATE");
  TTree *tree_out=new TTree("T","The Data Tree");
  
  Int_t filenumber;
  Int_t lastfilenumber=-1;

  tree_out->Branch("BetaDecay","BetaDecay",&theBetaDecay,32000,99);
  


  //ddaschannel *thechannel;
  
  //T->SetBranchAddress("dchan",&thechannel);
  
  T->SetBranchAddress("ddasevent",&theDDASevent);
  //Loop on entries
  Int_t nentries=T->GetEntries();
  //Int_t nentries=2;
  //Int_t nentries=5000000;
  cout<<nentries<<" in the ROOT file"<<endl;
  
  //BEGINNING OF EVENT LOOP
  for(Int_t ientry=0;ientry<nentries;ientry++)
    {
     if(ientry%100000==0)
	cout<<"."<<flush;
      
     T->GetEntry(ientry);
     if(DEBUG>0)
     cout<<"entries in the Event "<<theDDASevent->GetNEvents()<<endl;

     sprintf(cona,T->GetFile()->GetName());
     Char_t *pch=strchr(cona,'-');
     filenumber=atoi(pch+1);
     if(filenumber!=lastfilenumber){
       sprintf(dummy2,"%s-%02d_params.dat",dummy,filenumber);
       //cout<<dummy2<<endl;
       //ReadCalibrationParameters(dummy2);
       ReadCalibrationParameters("Calib_params_DPL.dat");
       lastfilenumber=filenumber; 
     }
     
 
    //for(Int_t j=0;j<theDDASevent->GetNEvents();j++){
  
      ddaschannel * thechannel=theDDASevent->GetData()[0];
     //cout<<cona<<" "<<pch+1<<" "<<filenumber<<endl;
      if(ientry==0){
	lasttime=thechannel->GetTime();
	lasttimelow=thechannel->timelow;
	lasttimehigh=thechannel->timehigh;
	lastcompoundtime=4294967296*lasttimehigh+lasttimelow;
	cout<<"First time:"<<lasttime<<" "<<lastcompoundtime<<endl;
      }

      //cout<<"Lasttime "<<lasttime<<endl;
      Double_t deltaT=0;

      if(thechannel->GetTime()<lasttime){

	cout<<endl;
	cout<<"****************PROBLEMS with time**************************"<<endl;
      }
      else{
	currenttimelow=thechannel->timelow;
	currenttimehigh=thechannel->timehigh;
	currentcompoundtime=4294967296*currenttimehigh+currenttimelow;
	//deltaT=thechannel->GetTime()-lasttime;
	deltaT=currentcompoundtime-lastcompoundtime;
	//cout<<"DeltaT "<<deltaT<<endl;
      }
      if(deltaT>timewindow){
	//cout<<"End of Event"<<endl;
	//ResetChannelList();
	//Here goes the Unpacker
	DDAS2Event(theBetaDecay,theDDASevent);
	//cout<<theBetaDecay->thepin1.energy<<"\t "<<theBetaDecay->theTac.pin01xfp<<endl;	
	SortPID(theBetaDecay);
 
	CalculateTimes(theBetaDecay);
	
	//Int_t flag=theCorrelator.Correlate(theBetaDecay);
	//if(flag==16){
	  //cout<<event_count<<" "<<flag<<endl;
	//decays++;
	//}
	tree_out->Fill();
	//here goes the sorting
	//SortPID(theBetaDecay);
	//Reset
	//ResetChannelList();
	//channellist.push_back(thechannel);
	event_count++;
	//if(theBetaDecay->thepin1.energy>0)
	  //cout<<"Before "<<theBetaDecay->thepin1.energy<<endl;
	lasttimelow=currenttimelow;
	lasttimehigh=currenttimehigh;
	lastcompoundtime=4294967296*lasttimehigh+lasttimelow;	
	//cout<<"After "<<theBetaDecay->thepin1.energy<<endl;
	}

      else{
         ;	
	//Accumulate the channel
	//cout<<"here"<<endl;
	//channellist.push_back(thechannel);
      }
     //}          
      //pid->Draw("zcol");
      //canvas->Update();
   
      }//END OF EVENT LOOP
	
	
  //pid->Draw("zcol");
  cout<<endl;
  tree_out->Write();
  cout<<"DONE!!"<<endl;
  
  //h2->Draw();
  
  cout<<endl;
  Int_t endTime=time(NULL);
  Int_t total_time= endTime-startTime;
  
  if(total_time<60)
    cout<<"Total running time "<<total_time<<" s."<<endl;
  else
    cout<<"Total running time "<<total_time/60<<" min."<<endl;
  cout<<"Number of events processed "<<event_count<<endl;
  cout<<"Number of buffers "<<nentries<<endl;
  cout<<"Number decays "<<decays<<endl;
  
  return;
}


 //void ResetChannelList(){
    
   //Int_t listSize = channellist.size();

   //cout<<listSize<<endl;
   //channellist_it=channellist.begin();

   //for(channellist_it=channellist.begin();channellist_it<channellist.end();channellist_it++){
   //delete *channellist_it;
   //}

  //channellist.clear();

 //}

void DDAS2Event(BetaDecay *bdecay,DDASEvent * theDDASevent){

  bdecay->Reset();

  //channellist_it=channellist.begin();
  //Int_t size=channellist.size();

  //if(size>4)
  //cout<<channellist.size()<<endl;

  //Loop on list of channels
  //for(channellist_it=channellist.begin();channellist_it<channellist.end();channellist_it++){

  Int_t sizeOfEvent=theDDASevent->GetNEvents();
  for(Int_t jevent=0;jevent<sizeOfEvent;jevent++){

    ddaschannel *localchannel=theDDASevent->GetData()[jevent];
    Int_t theCrate=localchannel->GetCrateID();
    Int_t theSlot=localchannel->GetSlotID();
    Int_t theChannel=localchannel->GetChannelID();
    UInt_t theEnergy=localchannel->GetEnergy();
    UInt_t theTimeLow=localchannel->GetTimeLow();
    UInt_t theTimeHigh=localchannel->GetTimeHigh();
    UInt_t theTimeCFD=localchannel->GetCFDTime();
    Double_t theTime=localchannel->GetTime();

    if(VERBOSE>2){
     
      cout<<"The Crate: "<<theCrate<<endl;
      cout<<"The Slot: "<<theSlot<<endl;
      cout<<"The Channel: "<<theChannel<<endl;
      cout<<"The Energy: "<<theEnergy<<endl;
    }//if(VERBOSE)




    //The time of an event is taken as the tiem of the first channel
    if(jevent==0){
      bdecay->theClock.fast=theTimeLow;
      bdecay->theClock.slow=theTimeHigh;
      bdecay->theClock.cfd=theTimeCFD;
     
    }//if(jevent==0)

    ULong64_t temp_time= bdecay->theClock.fast*10. + 4294967296.*bdecay->theClock.slow*10.;
    bdecay->theClock.current=(long)(floor)(temp_time/1000000.); 

    Double_t ran = ( static_cast<Double_t>(rand())) / (static_cast<Double_t>(RAND_MAX));

    if(theSlot==5){
      //cout<<total_number<<" "<<(*channellist_it)->GetTime()<<" Slot "<<theSlot<<" "<<theChannel<<" "<<theEnergy<<endl;
      total_number++;
    }
    if(theCrate==0){
      switch(theSlot){
	
       case 2:
	bdecay->theSega.energy[theChannel] = theEnergy;
	bdecay->theSega.timecfd[theChannel] = theTimeCFD;
	bdecay->theSega.timelow[theChannel] = theTimeLow;
	bdecay->theSega.timehigh[theChannel] = theTimeHigh;

	bdecay->theSega.energycal[theChannel] = SegaSlope[theChannel]*(theEnergy+ran)+ SegaIntercept[theChannel];

	if(bdecay->theSega.energycal[theChannel]>SegaThreshold[theChannel]){
	  bdecay->theSega.hit=kTRUE;
	  bdecay->theSega.multiplicity++;
	  bdecay->theSega.totalEnergy+=bdecay->theSega.energycal[theChannel];
	}

	break;
      case 3:
	if(theChannel==0){
	  bdecay->thepin1.energy = theEnergy;
	  //bdecay->thepin1.time = theTime;
	  bdecay->thepin1.timecfd = theTimeCFD;
	  bdecay->thepin1.timelow = theTimeLow;
	  bdecay->thepin1.timehigh = theTimeHigh;
	  if(bdecay->thepin1.energy>Pin1Threshold)	
	    bdecay->thepin1.hit=kTRUE;	    
	}
	break;

     case 4:
	if(theChannel==0){
	  bdecay->thescint.energy = theEnergy;
	  bdecay->thescint.time = theTime;
	  bdecay->thescint.timecfd = theTimeCFD;
	  bdecay->thescint.timelow = theTimeLow;
	  bdecay->thescint.timehigh = theTimeHigh;
	  if(bdecay->thescint.energy>ScintThreshold)	
	    bdecay->thescint.hit=kTRUE;	    
	}
	break;

      case 5:
	if(theChannel==0)
	  bdecay->theTac.pin01xfp = theEnergy;
	else if(theChannel==1)
	  bdecay->theTac.pin01rf = theEnergy;
	else if(theChannel==4)
	  bdecay->theTac.sega = theEnergy;
	break;
      default:
	break;
      }//switch(slot)
      //SortPID(bdecay);     
    }//if(crate==0)
    else
      cout<<"Wrong crate number!"<<endl;
    }//for(jevent=0)...
  //}//for(channellist_it=channellist.begin()...
  return;
}


void SortPID(BetaDecay *bdecay){
  
  Double_t ran = ( static_cast<Double_t>(rand())) / (static_cast<Double_t>(RAND_MAX));
  
  if(bdecay->thepin1.energy>Pin1Threshold)
    bdecay->thePID.de1=bdecay->thepin1.energy+ran;
  if(bdecay->thepin2.energy>Pin2Threshold)
    bdecay->thePID.de2=bdecay->thepin2.energy+ran;
  if(bdecay->theTac.pin01rf>0)
    bdecay->thePID.rftof=bdecay->theTac.pin01rf+ran;
  if(bdecay->theTac.pin01xfp>0)
    bdecay->thePID.xfptof=bdecay->theTac.pin01xfp+ran;

  //if(bdecay->thepin1.energy&&bdecay->thePID.xfptof)
  //pid->Fill(bdecay->thePID.xfptof,bdecay->thepin1.energy);
  return;
}



void CalculateTimes(BetaDecay *bdecay){

  Double_t ran = ( static_cast<Double_t>(rand())) / (static_cast<Double_t>(RAND_MAX));


  Double_t GeDSSD_time=bdecay->thefrontGeDSSD.decay_timecfd/65536.+ bdecay->thefrontGeDSSD.decay_timelow+ bdecay->thefrontGeDSSD.decay_timehigh*4294967296.;

  Double_t GeDSSD_implant_time=bdecay->thefrontGeDSSD.implant_timecfd/65536.+ bdecay->thefrontGeDSSD.implant_timelow+ bdecay->thefrontGeDSSD.implant_timehigh*4294967296.;

  Double_t PIN1_time=bdecay->thepin1.timecfd/65536.+ bdecay->thepin1.timelow+ bdecay->thepin1.timehigh*4294967296.;

  Double_t PIN2_time=bdecay->thepin2.timecfd/65536.+ bdecay->thepin2.timelow+ bdecay->thepin2.timehigh*4294967296.;

  Double_t Scint_time=bdecay->thescint.timecfd/65536.+ bdecay->thescint.timelow+ bdecay->thescint.timehigh*4294967296.;


  if(GeDSSD_implant_time>0&&PIN1_time>0){    
    bdecay->thepin1.time=GeDSSD_implant_time-PIN1_time+3000;
    if(VERBOSE>0)
      cout<<" front GeDSSD_time: "<<GeDSSD_implant_time<<" PIN1_time: "<<PIN1_time<<"->"<<bdecay->thepin1.time<<endl;
  }
  if(GeDSSD_implant_time>0&&PIN2_time>0){    
    bdecay->thepin2.time=GeDSSD_implant_time-PIN2_time+3000;
    if(VERBOSE>0)      
    cout<<" front GeDSSD_time: "<<GeDSSD_implant_time<<" PIN2_time: "<<PIN2_time<<"->"<<bdecay->thepin2.time<<endl;
  }
   for(Int_t i=0;i<16;i++){

    Double_t SeGA_time=bdecay->theSega.timecfd[i]/65536.+ bdecay->theSega.timelow[i]+ bdecay->theSega.timehigh[i]*4294967296.; 

    Double_t DeltaT= Scint_time - SeGA_time + 10000+ran;

    if(Scint_time>0&&SeGA_time>0){    
      bdecay->theSega.time[i]=DeltaT;
      if(VERBOSE>1)
	cout<<" Scint_time: "<<Scint_time<<" SeGA_time["<<i<<"]: "<<SeGA_time<<"->"<<DeltaT<<endl;
    }
    else
       bdecay->theSega.time[i]=-1e9;
   }
}





void ReadCalibrationParameters(Char_t * name){
  cout<<"Reading Calibration Parameters from "<<name<<endl;
  Char_t line[256];
  sprintf(line,"Parameters/%s",name);
  ifstream *file =new ifstream(line);
  if(!file->good()){
    cout<<"ERROR! File not found"<<endl;
    return;
  }
  file->getline(line,256);
  //cout<<line<<endl;
  Int_t channel;
  Double_t Slope;
  Double_t Intercept;
  while(*file>>channel>>Slope>>Intercept){
    SegaSlope[channel]=Slope;
    SegaIntercept[channel]=Intercept;
    cout<<channel<<"\t"<<Slope<<"\t"<<Intercept<<endl;
  }
  cout<<"Done!"<<endl;
}
