/*      File: Correlator.h
	Class for beta decay Correlation Events
	Author: David Perez-Loureiro
	Date: June 2014
*/

#ifndef __CORRELATOR_H
#define __CORRELATOR_H

#include <TObject.h>
#include <TCutG.h>
#include "BetaDecay.h"

class Implant{
 public:
  Bool_t implanted;
  UInt_t timehigh;
  UInt_t timelow;
  UInt_t timecfd;

  Double_t time;

  //Energy loss from PINs
  Double_t dE1;
  Double_t dE2;

  //Sum and max energies from GeDSSD low gain
  Double_t implant_sum;
  Double_t implant_max;

  //Time-of-Flight
  Double_t tof;

  //Time since last implant;
  Double_t dt;
  
  //number of times implant correlated
  Int_t numcorr;

};

class Decay{
 public:

  UInt_t timehigh;
  UInt_t timelow;
  UInt_t timecfd;

  Double_t time;

  //Energy loss from PINs
  Double_t dE1;
  Double_t dE2;

  //Sum and max energies from GeDSSD low gain
  Double_t implant_sum;
  Double_t implant_max;

  //Time-of-Flight
  Double_t tof;

  //Time since last implant;
  Double_t dt;
  
  //Time since last decay
  Double_t dt_decay;  
  //number of times decay correlated
  Int_t dnumcorr;

};

class Correlator:public TObject{
  
 public:

  Implant theImplant[16][16];
  Decay theDecay[16][16];
  TCutG* P26;
  Long_t eventcount;

  Correlator();
  ~Correlator();
  Double_t Correlate(BetaDecay *);
  void Reset();
  ClassDef(Correlator,1);
};

#endif
