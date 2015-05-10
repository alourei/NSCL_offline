
/*      File: BetaDecay.h
	Class for beta Decay Events
	Author: David Perez-Loureiro
	Date: June 2014
*/

#ifndef __BETADECAY_H
#define __BETADECAY_H

#include <TObject.h>
class Clock{
 public:
  UInt_t fast;
  UInt_t slow;
  UInt_t cfd;
  Double_t current;
  Double_t initial;
  void Reset();
};

class Tac{
 public:
  UInt_t pin01rf;
  UInt_t pin01xfp;
  UInt_t sega;
  void Reset();
};

class GeDSSD{
 public:
  Bool_t Lohit;
  Bool_t Hihit;
  UInt_t Hienergy[16];
  Double_t Hienergycal[16];
  UInt_t Hitimecfd[16];
  UInt_t Hitimelow[16];
  UInt_t Hitimehigh[16];
  Double_t Hieventtime[16];

  UInt_t Loenergy[16];
  Double_t Loenergycal[16];
  UInt_t Lotimecfd[16];
  UInt_t Lotimelow[16];
  UInt_t Lotimehigh[16];
  Double_t Loeventtime[16];

  UInt_t implant_cent;
  UInt_t decay_cent;

  UInt_t implant_max;
  UInt_t implant_timecfd;
  UInt_t implant_timelow;
  UInt_t implant_timehigh;

  UInt_t decay_max;
  UInt_t decay_timecfd;
  UInt_t decay_timelow;
  UInt_t decay_timehigh;

  UInt_t implant_timediff;
  UInt_t decay_timediff;

  Int_t implant_max_channel;
  Int_t decay_max_channel;

  UInt_t implant_multiplicity;
  UInt_t decay_multiplicity;

  UInt_t implant_sum;
  UInt_t decay_sum;

  UInt_t implant_energydiff;
  UInt_t decay_energy_diff;
  void Reset();
};

class Sega{
 public:
  Bool_t hit;
  UInt_t timecfd[16];
  UInt_t timelow[16];
  UInt_t timehigh[16];
  Double_t time[16];
  UInt_t energy[16];
  Double_t goodenergy[16];
  Double_t energycal[16];

  UInt_t multiplicity;
  UInt_t totalEnergy;
  void Reset();
};

class Pin{
 public:
  Bool_t hit;
  UInt_t energy;
  UInt_t timecfd;
  UInt_t timelow;
  UInt_t timehigh;
  Double_t time;
  void Reset();
};


class Scint{
 public:
  Bool_t hit;
  UInt_t energy;
  UInt_t timecfd;
  UInt_t timelow;
  UInt_t timehigh;
  Double_t time;
  void Reset();
};

class PID{

 public:
  Double_t de1;
  Double_t de2;
  Double_t rftof;
  Double_t xfptof;
  void Reset();

};

class BetaDecayCorrelator{
 public:

  Double_t dt_implant;
  Double_t implant_time;
  Double_t implant_de1;
  Double_t implant_de2;
  Double_t implant_tof;

  Double_t gamma_timecal;
  Double_t gamma_time;
  Double_t gamma_de1;
  Double_t gamma_de2;
  Double_t gamma_tof;

  Double_t decay_timecal;
  Double_t decay_time;
  Double_t decay_de1;
  Double_t decay_de2;
  Double_t decay_tof;

  Int_t front_implant_max_channel;
  Int_t front_decay_max_channel;
  Int_t back_implant_max_channel;
  Int_t back_decay_max_channel;

  /* Double_t front_implant_max; */
  /* Double_t front_decay_max; */

  /* Double_t back_implant_max; */
  /* Double_t back_decay_max; */

  Int_t flag;

  Int_t implant_mult;
  Int_t decay_mult;


  void Reset();
};

class BetaDecay: public TObject
{
 public:
  Clock theClock;
  Tac theTac;
  GeDSSD thefrontGeDSSD;
  GeDSSD thebackGeDSSD;
  Sega theSega;
  Pin thepin1;
  Pin thepin2;
  PID thePID;
  Scint thescint;
  BetaDecayCorrelator theCorrelator;  
  BetaDecay();
  ~BetaDecay();
  void Reset();

  ClassDef(BetaDecay,2);
};
#endif
