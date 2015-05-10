
#include <iostream>
#include "BetaDecay.h"


ClassImp(BetaDecay)

BetaDecay::BetaDecay(){
  ;
}

BetaDecay::~BetaDecay(){
  ;
}



void Clock::Reset(){
  fast=0;
  slow=0;
  cfd=0;
  current=0;
  //initial=0;
}

void Tac::Reset(){
  pin01rf=0;
  pin01xfp=0;
  sega=0;
}

void GeDSSD::Reset(){
  for(Int_t k=0;k<16;k++){
    Hienergycal[k]=0;
    Hitimecfd[k]=0;
    Hitimelow[k]=0;
    Hitimehigh[k]=0;
    Hieventtime[k]=0;

    Loenergy[k]=0;
    Loenergycal[k]=0;
    Lotimecfd[k]=0;
    Lotimelow[k]=0;
    Lotimehigh[k]=0;
    Loeventtime[k]=0;
  }
    implant_cent=0;
    decay_cent=0;

    implant_max=0;
    implant_timecfd=0;
    implant_timelow=0;
    implant_timehigh=0;

    decay_max=0;
    decay_timecfd=0;
    decay_timelow=0;
    decay_timehigh=0;

    implant_timediff=0;
    decay_timediff=0;

    implant_max_channel=-1;
    decay_max_channel=-1;

    implant_multiplicity=0;
    decay_multiplicity=0;

    implant_sum=0;
    decay_sum=0;

    implant_energydiff=0;
    decay_energy_diff=0;

    Lohit=kFALSE;
    Hihit=kFALSE;

}

void Sega::Reset(){

  for(Int_t k=0;k<16;k++){
    energy[k]=0;
    goodenergy[k]=0;
    energycal[k]=0;
    timecfd[k]=0;
    timelow[k]=0;
    timehigh[k]=0;
    time[k]=0;
  }
    multiplicity=0;
    totalEnergy=0;
    hit=kFALSE;

}

void Pin::Reset(){
  energy=0;
  time=0;
  timecfd=0;
  timelow=0;
  timehigh=0;

  hit=kFALSE;
}

void Scint::Reset(){
  energy=0;
  time=0;
  timecfd=0;
  timelow=0;
  timehigh=0;

  hit=kFALSE;
}


void PID::Reset(){
  de1=0;
  de2=0;
  rftof=0;
  xfptof=0;
}

void BetaDecayCorrelator::Reset(){
    dt_implant=0;
    implant_time=0;
    implant_de1=0;
    implant_de2=0;
    implant_tof=0;

    gamma_timecal=0;
    gamma_time=0;
    gamma_de1=0;
    gamma_de2=0;
    gamma_tof=0;

    decay_timecal=0;
    decay_time=0;
    decay_de1=0;
    decay_de2=0;
    decay_tof=0;

    flag=0;
    implant_mult=0;
    decay_mult=0;


    front_implant_max_channel=-1;
    front_decay_max_channel=-1;

    back_implant_max_channel=-1;
    back_decay_max_channel=-1;

   //  front_implant_max=0;
   //  front_decay_max=0;

   // back_implant_max=0;
   // back_decay_max=0;

}


void BetaDecay::Reset(){
 
  //std::cout<<"Reseting ..."<<std::endl;
   theClock.Reset();
   theTac.Reset();
   thefrontGeDSSD.Reset();
   thebackGeDSSD.Reset();
   theSega.Reset();
   thepin1.Reset();
   thepin2.Reset();
   thePID.Reset();
   thescint.Reset();
   theCorrelator.Reset();
  
}
