//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri May  8 13:21:03 2015 by ROOT version 5.34/09
// from TTree T/The Data Tree
// found on file: /events/e14066/rootdata/sorted/run23_sorted.root
//////////////////////////////////////////////////////////

#ifndef BetaDecayAnalyzer_h
#define BetaDecayAnalyzer_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
//#include "/scratch/blair/root/core/base/inc/TObject.h"

// Fixed size dimensions of array or collections stored in the TTree if any.

class BetaDecayAnalyzer {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
 //BetaDecay       *BetaDecay;
   UInt_t          fUniqueID;
   UInt_t          fBits;
   UInt_t          theClock_fast;
   UInt_t          theClock_slow;
   UInt_t          theClock_cfd;
   Double_t        theClock_current;
   Double_t        theClock_initial;
   UInt_t          theTac_pin01rf;
   UInt_t          theTac_pin01xfp;
   UInt_t          theTac_sega;
   Bool_t          thefrontGeDSSD_Lohit;
   Bool_t          thefrontGeDSSD_Hihit;
   UInt_t          thefrontGeDSSD_Hienergy[16];
   Double_t        thefrontGeDSSD_Hienergycal[16];
   UInt_t          thefrontGeDSSD_Hitimecfd[16];
   UInt_t          thefrontGeDSSD_Hitimelow[16];
   UInt_t          thefrontGeDSSD_Hitimehigh[16];
   Double_t        thefrontGeDSSD_Hieventtime[16];
   UInt_t          thefrontGeDSSD_Loenergy[16];
   Double_t        thefrontGeDSSD_Loenergycal[16];
   UInt_t          thefrontGeDSSD_Lotimecfd[16];
   UInt_t          thefrontGeDSSD_Lotimelow[16];
   UInt_t          thefrontGeDSSD_Lotimehigh[16];
   Double_t        thefrontGeDSSD_Loeventtime[16];
   UInt_t          thefrontGeDSSD_implant_cent;
   UInt_t          thefrontGeDSSD_decay_cent;
   UInt_t          thefrontGeDSSD_implant_max;
   UInt_t          thefrontGeDSSD_implant_timecfd;
   UInt_t          thefrontGeDSSD_implant_timelow;
   UInt_t          thefrontGeDSSD_implant_timehigh;
   UInt_t          thefrontGeDSSD_decay_max;
   UInt_t          thefrontGeDSSD_decay_timecfd;
   UInt_t          thefrontGeDSSD_decay_timelow;
   UInt_t          thefrontGeDSSD_decay_timehigh;
   UInt_t          thefrontGeDSSD_implant_timediff;
   UInt_t          thefrontGeDSSD_decay_timediff;
   Int_t           thefrontGeDSSD_implant_max_channel;
   Int_t           thefrontGeDSSD_decay_max_channel;
   UInt_t          thefrontGeDSSD_implant_multiplicity;
   UInt_t          thefrontGeDSSD_decay_multiplicity;
   UInt_t          thefrontGeDSSD_implant_sum;
   UInt_t          thefrontGeDSSD_decay_sum;
   UInt_t          thefrontGeDSSD_implant_energydiff;
   UInt_t          thefrontGeDSSD_decay_energy_diff;
   Bool_t          thebackGeDSSD_Lohit;
   Bool_t          thebackGeDSSD_Hihit;
   UInt_t          thebackGeDSSD_Hienergy[16];
   Double_t        thebackGeDSSD_Hienergycal[16];
   UInt_t          thebackGeDSSD_Hitimecfd[16];
   UInt_t          thebackGeDSSD_Hitimelow[16];
   UInt_t          thebackGeDSSD_Hitimehigh[16];
   Double_t        thebackGeDSSD_Hieventtime[16];
   UInt_t          thebackGeDSSD_Loenergy[16];
   Double_t        thebackGeDSSD_Loenergycal[16];
   UInt_t          thebackGeDSSD_Lotimecfd[16];
   UInt_t          thebackGeDSSD_Lotimelow[16];
   UInt_t          thebackGeDSSD_Lotimehigh[16];
   Double_t        thebackGeDSSD_Loeventtime[16];
   UInt_t          thebackGeDSSD_implant_cent;
   UInt_t          thebackGeDSSD_decay_cent;
   UInt_t          thebackGeDSSD_implant_max;
   UInt_t          thebackGeDSSD_implant_timecfd;
   UInt_t          thebackGeDSSD_implant_timelow;
   UInt_t          thebackGeDSSD_implant_timehigh;
   UInt_t          thebackGeDSSD_decay_max;
   UInt_t          thebackGeDSSD_decay_timecfd;
   UInt_t          thebackGeDSSD_decay_timelow;
   UInt_t          thebackGeDSSD_decay_timehigh;
   UInt_t          thebackGeDSSD_implant_timediff;
   UInt_t          thebackGeDSSD_decay_timediff;
   Int_t           thebackGeDSSD_implant_max_channel;
   Int_t           thebackGeDSSD_decay_max_channel;
   UInt_t          thebackGeDSSD_implant_multiplicity;
   UInt_t          thebackGeDSSD_decay_multiplicity;
   UInt_t          thebackGeDSSD_implant_sum;
   UInt_t          thebackGeDSSD_decay_sum;
   UInt_t          thebackGeDSSD_implant_energydiff;
   UInt_t          thebackGeDSSD_decay_energy_diff;
   Bool_t          theSega_hit;
   UInt_t          theSega_timecfd[16];
   UInt_t          theSega_timelow[16];
   UInt_t          theSega_timehigh[16];
   Double_t        theSega_time[16];
   UInt_t          theSega_energy[16];
   Double_t        theSega_goodenergy[16];
   Double_t        theSega_energycal[16];
   UInt_t          theSega_multiplicity;
   UInt_t          theSega_totalEnergy;
   Bool_t          thepin1_hit;
   UInt_t          thepin1_energy;
   UInt_t          thepin1_timecfd;
   UInt_t          thepin1_timelow;
   UInt_t          thepin1_timehigh;
   Double_t        thepin1_time;
   Bool_t          thepin2_hit;
   UInt_t          thepin2_energy;
   UInt_t          thepin2_timecfd;
   UInt_t          thepin2_timelow;
   UInt_t          thepin2_timehigh;
   Double_t        thepin2_time;
   Double_t        thePID_de1;
   Double_t        thePID_de2;
   Double_t        thePID_rftof;
   Double_t        thePID_xfptof;
   Bool_t          thescint_hit;
   UInt_t          thescint_energy;
   UInt_t          thescint_timecfd;
   UInt_t          thescint_timelow;
   UInt_t          thescint_timehigh;
   Double_t        thescint_time;
   Double_t        theCorrelator_dt_implant;
   Double_t        theCorrelator_implant_time;
   Double_t        theCorrelator_implant_de1;
   Double_t        theCorrelator_implant_de2;
   Double_t        theCorrelator_implant_tof;
   Double_t        theCorrelator_gamma_timecal;
   Double_t        theCorrelator_gamma_time;
   Double_t        theCorrelator_gamma_de1;
   Double_t        theCorrelator_gamma_de2;
   Double_t        theCorrelator_gamma_tof;
   Double_t        theCorrelator_decay_timecal;
   Double_t        theCorrelator_decay_time;
   Double_t        theCorrelator_decay_de1;
   Double_t        theCorrelator_decay_de2;
   Double_t        theCorrelator_decay_tof;
   Int_t           theCorrelator_front_implant_max_channel;
   Int_t           theCorrelator_front_decay_max_channel;
   Int_t           theCorrelator_back_implant_max_channel;
   Int_t           theCorrelator_back_decay_max_channel;
   Int_t           theCorrelator_flag;
   Int_t           theCorrelator_implant_mult;
   Int_t           theCorrelator_decay_mult;

   // List of branches
   TBranch        *b_BetaDecay_fUniqueID;   //!
   TBranch        *b_BetaDecay_fBits;   //!
   TBranch        *b_BetaDecay_theClock_fast;   //!
   TBranch        *b_BetaDecay_theClock_slow;   //!
   TBranch        *b_BetaDecay_theClock_cfd;   //!
   TBranch        *b_BetaDecay_theClock_current;   //!
   TBranch        *b_BetaDecay_theClock_initial;   //!
   TBranch        *b_BetaDecay_theTac_pin01rf;   //!
   TBranch        *b_BetaDecay_theTac_pin01xfp;   //!
   TBranch        *b_BetaDecay_theTac_sega;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_Lohit;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_Hihit;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_Hienergy;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_Hienergycal;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_Hitimecfd;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_Hitimelow;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_Hitimehigh;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_Hieventtime;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_Loenergy;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_Loenergycal;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_Lotimecfd;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_Lotimelow;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_Lotimehigh;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_Loeventtime;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_implant_cent;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_decay_cent;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_implant_max;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_implant_timecfd;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_implant_timelow;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_implant_timehigh;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_decay_max;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_decay_timecfd;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_decay_timelow;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_decay_timehigh;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_implant_timediff;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_decay_timediff;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_implant_max_channel;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_decay_max_channel;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_implant_multiplicity;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_decay_multiplicity;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_implant_sum;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_decay_sum;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_implant_energydiff;   //!
   TBranch        *b_BetaDecay_thefrontGeDSSD_decay_energy_diff;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_Lohit;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_Hihit;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_Hienergy;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_Hienergycal;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_Hitimecfd;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_Hitimelow;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_Hitimehigh;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_Hieventtime;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_Loenergy;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_Loenergycal;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_Lotimecfd;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_Lotimelow;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_Lotimehigh;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_Loeventtime;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_implant_cent;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_decay_cent;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_implant_max;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_implant_timecfd;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_implant_timelow;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_implant_timehigh;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_decay_max;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_decay_timecfd;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_decay_timelow;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_decay_timehigh;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_implant_timediff;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_decay_timediff;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_implant_max_channel;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_decay_max_channel;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_implant_multiplicity;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_decay_multiplicity;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_implant_sum;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_decay_sum;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_implant_energydiff;   //!
   TBranch        *b_BetaDecay_thebackGeDSSD_decay_energy_diff;   //!
   TBranch        *b_BetaDecay_theSega_hit;   //!
   TBranch        *b_BetaDecay_theSega_timecfd;   //!
   TBranch        *b_BetaDecay_theSega_timelow;   //!
   TBranch        *b_BetaDecay_theSega_timehigh;   //!
   TBranch        *b_BetaDecay_theSega_time;   //!
   TBranch        *b_BetaDecay_theSega_energy;   //!
   TBranch        *b_BetaDecay_theSega_goodenergy;   //!
   TBranch        *b_BetaDecay_theSega_energycal;   //!
   TBranch        *b_BetaDecay_theSega_multiplicity;   //!
   TBranch        *b_BetaDecay_theSega_totalEnergy;   //!
   TBranch        *b_BetaDecay_thepin1_hit;   //!
   TBranch        *b_BetaDecay_thepin1_energy;   //!
   TBranch        *b_BetaDecay_thepin1_timecfd;   //!
   TBranch        *b_BetaDecay_thepin1_timelow;   //!
   TBranch        *b_BetaDecay_thepin1_timehigh;   //!
   TBranch        *b_BetaDecay_thepin1_time;   //!
   TBranch        *b_BetaDecay_thepin2_hit;   //!
   TBranch        *b_BetaDecay_thepin2_energy;   //!
   TBranch        *b_BetaDecay_thepin2_timecfd;   //!
   TBranch        *b_BetaDecay_thepin2_timelow;   //!
   TBranch        *b_BetaDecay_thepin2_timehigh;   //!
   TBranch        *b_BetaDecay_thepin2_time;   //!
   TBranch        *b_BetaDecay_thePID_de1;   //!
   TBranch        *b_BetaDecay_thePID_de2;   //!
   TBranch        *b_BetaDecay_thePID_rftof;   //!
   TBranch        *b_BetaDecay_thePID_xfptof;   //!
   TBranch        *b_BetaDecay_thescint_hit;   //!
   TBranch        *b_BetaDecay_thescint_energy;   //!
   TBranch        *b_BetaDecay_thescint_timecfd;   //!
   TBranch        *b_BetaDecay_thescint_timelow;   //!
   TBranch        *b_BetaDecay_thescint_timehigh;   //!
   TBranch        *b_BetaDecay_thescint_time;   //!
   TBranch        *b_BetaDecay_theCorrelator_dt_implant;   //!
   TBranch        *b_BetaDecay_theCorrelator_implant_time;   //!
   TBranch        *b_BetaDecay_theCorrelator_implant_de1;   //!
   TBranch        *b_BetaDecay_theCorrelator_implant_de2;   //!
   TBranch        *b_BetaDecay_theCorrelator_implant_tof;   //!
   TBranch        *b_BetaDecay_theCorrelator_gamma_timecal;   //!
   TBranch        *b_BetaDecay_theCorrelator_gamma_time;   //!
   TBranch        *b_BetaDecay_theCorrelator_gamma_de1;   //!
   TBranch        *b_BetaDecay_theCorrelator_gamma_de2;   //!
   TBranch        *b_BetaDecay_theCorrelator_gamma_tof;   //!
   TBranch        *b_BetaDecay_theCorrelator_decay_timecal;   //!
   TBranch        *b_BetaDecay_theCorrelator_decay_time;   //!
   TBranch        *b_BetaDecay_theCorrelator_decay_de1;   //!
   TBranch        *b_BetaDecay_theCorrelator_decay_de2;   //!
   TBranch        *b_BetaDecay_theCorrelator_decay_tof;   //!
   TBranch        *b_BetaDecay_theCorrelator_front_implant_max_channel;   //!
   TBranch        *b_BetaDecay_theCorrelator_front_decay_max_channel;   //!
   TBranch        *b_BetaDecay_theCorrelator_back_implant_max_channel;   //!
   TBranch        *b_BetaDecay_theCorrelator_back_decay_max_channel;   //!
   TBranch        *b_BetaDecay_theCorrelator_flag;   //!
   TBranch        *b_BetaDecay_theCorrelator_implant_mult;   //!
   TBranch        *b_BetaDecay_theCorrelator_decay_mult;   //!

   BetaDecayAnalyzer(TTree *tree=0);
   virtual ~BetaDecayAnalyzer();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(Int_t nevents=-1);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef BetaDecayAnalyzer_cxx
BetaDecayAnalyzer::BetaDecayAnalyzer(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/events/e14066/rootdata/sorted/run23_sorted.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/events/e14066/rootdata/sorted/run23_sorted.root");
      }
      f->GetObject("T",tree);

   }
   Init(tree);
}

BetaDecayAnalyzer::~BetaDecayAnalyzer()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t BetaDecayAnalyzer::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t BetaDecayAnalyzer::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void BetaDecayAnalyzer::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("fUniqueID", &fUniqueID, &b_BetaDecay_fUniqueID);
   fChain->SetBranchAddress("fBits", &fBits, &b_BetaDecay_fBits);
   fChain->SetBranchAddress("theClock.fast", &theClock_fast, &b_BetaDecay_theClock_fast);
   fChain->SetBranchAddress("theClock.slow", &theClock_slow, &b_BetaDecay_theClock_slow);
   fChain->SetBranchAddress("theClock.cfd", &theClock_cfd, &b_BetaDecay_theClock_cfd);
   fChain->SetBranchAddress("theClock.current", &theClock_current, &b_BetaDecay_theClock_current);
   fChain->SetBranchAddress("theClock.initial", &theClock_initial, &b_BetaDecay_theClock_initial);
   fChain->SetBranchAddress("theTac.pin01rf", &theTac_pin01rf, &b_BetaDecay_theTac_pin01rf);
   fChain->SetBranchAddress("theTac.pin01xfp", &theTac_pin01xfp, &b_BetaDecay_theTac_pin01xfp);
   fChain->SetBranchAddress("theTac.sega", &theTac_sega, &b_BetaDecay_theTac_sega);
   fChain->SetBranchAddress("thefrontGeDSSD.Lohit", &thefrontGeDSSD_Lohit, &b_BetaDecay_thefrontGeDSSD_Lohit);
   fChain->SetBranchAddress("thefrontGeDSSD.Hihit", &thefrontGeDSSD_Hihit, &b_BetaDecay_thefrontGeDSSD_Hihit);
   fChain->SetBranchAddress("thefrontGeDSSD.Hienergy[16]", thefrontGeDSSD_Hienergy, &b_BetaDecay_thefrontGeDSSD_Hienergy);
   fChain->SetBranchAddress("thefrontGeDSSD.Hienergycal[16]", thefrontGeDSSD_Hienergycal, &b_BetaDecay_thefrontGeDSSD_Hienergycal);
   fChain->SetBranchAddress("thefrontGeDSSD.Hitimecfd[16]", thefrontGeDSSD_Hitimecfd, &b_BetaDecay_thefrontGeDSSD_Hitimecfd);
   fChain->SetBranchAddress("thefrontGeDSSD.Hitimelow[16]", thefrontGeDSSD_Hitimelow, &b_BetaDecay_thefrontGeDSSD_Hitimelow);
   fChain->SetBranchAddress("thefrontGeDSSD.Hitimehigh[16]", thefrontGeDSSD_Hitimehigh, &b_BetaDecay_thefrontGeDSSD_Hitimehigh);
   fChain->SetBranchAddress("thefrontGeDSSD.Hieventtime[16]", thefrontGeDSSD_Hieventtime, &b_BetaDecay_thefrontGeDSSD_Hieventtime);
   fChain->SetBranchAddress("thefrontGeDSSD.Loenergy[16]", thefrontGeDSSD_Loenergy, &b_BetaDecay_thefrontGeDSSD_Loenergy);
   fChain->SetBranchAddress("thefrontGeDSSD.Loenergycal[16]", thefrontGeDSSD_Loenergycal, &b_BetaDecay_thefrontGeDSSD_Loenergycal);
   fChain->SetBranchAddress("thefrontGeDSSD.Lotimecfd[16]", thefrontGeDSSD_Lotimecfd, &b_BetaDecay_thefrontGeDSSD_Lotimecfd);
   fChain->SetBranchAddress("thefrontGeDSSD.Lotimelow[16]", thefrontGeDSSD_Lotimelow, &b_BetaDecay_thefrontGeDSSD_Lotimelow);
   fChain->SetBranchAddress("thefrontGeDSSD.Lotimehigh[16]", thefrontGeDSSD_Lotimehigh, &b_BetaDecay_thefrontGeDSSD_Lotimehigh);
   fChain->SetBranchAddress("thefrontGeDSSD.Loeventtime[16]", thefrontGeDSSD_Loeventtime, &b_BetaDecay_thefrontGeDSSD_Loeventtime);
   fChain->SetBranchAddress("thefrontGeDSSD.implant_cent", &thefrontGeDSSD_implant_cent, &b_BetaDecay_thefrontGeDSSD_implant_cent);
   fChain->SetBranchAddress("thefrontGeDSSD.decay_cent", &thefrontGeDSSD_decay_cent, &b_BetaDecay_thefrontGeDSSD_decay_cent);
   fChain->SetBranchAddress("thefrontGeDSSD.implant_max", &thefrontGeDSSD_implant_max, &b_BetaDecay_thefrontGeDSSD_implant_max);
   fChain->SetBranchAddress("thefrontGeDSSD.implant_timecfd", &thefrontGeDSSD_implant_timecfd, &b_BetaDecay_thefrontGeDSSD_implant_timecfd);
   fChain->SetBranchAddress("thefrontGeDSSD.implant_timelow", &thefrontGeDSSD_implant_timelow, &b_BetaDecay_thefrontGeDSSD_implant_timelow);
   fChain->SetBranchAddress("thefrontGeDSSD.implant_timehigh", &thefrontGeDSSD_implant_timehigh, &b_BetaDecay_thefrontGeDSSD_implant_timehigh);
   fChain->SetBranchAddress("thefrontGeDSSD.decay_max", &thefrontGeDSSD_decay_max, &b_BetaDecay_thefrontGeDSSD_decay_max);
   fChain->SetBranchAddress("thefrontGeDSSD.decay_timecfd", &thefrontGeDSSD_decay_timecfd, &b_BetaDecay_thefrontGeDSSD_decay_timecfd);
   fChain->SetBranchAddress("thefrontGeDSSD.decay_timelow", &thefrontGeDSSD_decay_timelow, &b_BetaDecay_thefrontGeDSSD_decay_timelow);
   fChain->SetBranchAddress("thefrontGeDSSD.decay_timehigh", &thefrontGeDSSD_decay_timehigh, &b_BetaDecay_thefrontGeDSSD_decay_timehigh);
   fChain->SetBranchAddress("thefrontGeDSSD.implant_timediff", &thefrontGeDSSD_implant_timediff, &b_BetaDecay_thefrontGeDSSD_implant_timediff);
   fChain->SetBranchAddress("thefrontGeDSSD.decay_timediff", &thefrontGeDSSD_decay_timediff, &b_BetaDecay_thefrontGeDSSD_decay_timediff);
   fChain->SetBranchAddress("thefrontGeDSSD.implant_max_channel", &thefrontGeDSSD_implant_max_channel, &b_BetaDecay_thefrontGeDSSD_implant_max_channel);
   fChain->SetBranchAddress("thefrontGeDSSD.decay_max_channel", &thefrontGeDSSD_decay_max_channel, &b_BetaDecay_thefrontGeDSSD_decay_max_channel);
   fChain->SetBranchAddress("thefrontGeDSSD.implant_multiplicity", &thefrontGeDSSD_implant_multiplicity, &b_BetaDecay_thefrontGeDSSD_implant_multiplicity);
   fChain->SetBranchAddress("thefrontGeDSSD.decay_multiplicity", &thefrontGeDSSD_decay_multiplicity, &b_BetaDecay_thefrontGeDSSD_decay_multiplicity);
   fChain->SetBranchAddress("thefrontGeDSSD.implant_sum", &thefrontGeDSSD_implant_sum, &b_BetaDecay_thefrontGeDSSD_implant_sum);
   fChain->SetBranchAddress("thefrontGeDSSD.decay_sum", &thefrontGeDSSD_decay_sum, &b_BetaDecay_thefrontGeDSSD_decay_sum);
   fChain->SetBranchAddress("thefrontGeDSSD.implant_energydiff", &thefrontGeDSSD_implant_energydiff, &b_BetaDecay_thefrontGeDSSD_implant_energydiff);
   fChain->SetBranchAddress("thefrontGeDSSD.decay_energy_diff", &thefrontGeDSSD_decay_energy_diff, &b_BetaDecay_thefrontGeDSSD_decay_energy_diff);
   fChain->SetBranchAddress("thebackGeDSSD.Lohit", &thebackGeDSSD_Lohit, &b_BetaDecay_thebackGeDSSD_Lohit);
   fChain->SetBranchAddress("thebackGeDSSD.Hihit", &thebackGeDSSD_Hihit, &b_BetaDecay_thebackGeDSSD_Hihit);
   fChain->SetBranchAddress("thebackGeDSSD.Hienergy[16]", thebackGeDSSD_Hienergy, &b_BetaDecay_thebackGeDSSD_Hienergy);
   fChain->SetBranchAddress("thebackGeDSSD.Hienergycal[16]", thebackGeDSSD_Hienergycal, &b_BetaDecay_thebackGeDSSD_Hienergycal);
   fChain->SetBranchAddress("thebackGeDSSD.Hitimecfd[16]", thebackGeDSSD_Hitimecfd, &b_BetaDecay_thebackGeDSSD_Hitimecfd);
   fChain->SetBranchAddress("thebackGeDSSD.Hitimelow[16]", thebackGeDSSD_Hitimelow, &b_BetaDecay_thebackGeDSSD_Hitimelow);
   fChain->SetBranchAddress("thebackGeDSSD.Hitimehigh[16]", thebackGeDSSD_Hitimehigh, &b_BetaDecay_thebackGeDSSD_Hitimehigh);
   fChain->SetBranchAddress("thebackGeDSSD.Hieventtime[16]", thebackGeDSSD_Hieventtime, &b_BetaDecay_thebackGeDSSD_Hieventtime);
   fChain->SetBranchAddress("thebackGeDSSD.Loenergy[16]", thebackGeDSSD_Loenergy, &b_BetaDecay_thebackGeDSSD_Loenergy);
   fChain->SetBranchAddress("thebackGeDSSD.Loenergycal[16]", thebackGeDSSD_Loenergycal, &b_BetaDecay_thebackGeDSSD_Loenergycal);
   fChain->SetBranchAddress("thebackGeDSSD.Lotimecfd[16]", thebackGeDSSD_Lotimecfd, &b_BetaDecay_thebackGeDSSD_Lotimecfd);
   fChain->SetBranchAddress("thebackGeDSSD.Lotimelow[16]", thebackGeDSSD_Lotimelow, &b_BetaDecay_thebackGeDSSD_Lotimelow);
   fChain->SetBranchAddress("thebackGeDSSD.Lotimehigh[16]", thebackGeDSSD_Lotimehigh, &b_BetaDecay_thebackGeDSSD_Lotimehigh);
   fChain->SetBranchAddress("thebackGeDSSD.Loeventtime[16]", thebackGeDSSD_Loeventtime, &b_BetaDecay_thebackGeDSSD_Loeventtime);
   fChain->SetBranchAddress("thebackGeDSSD.implant_cent", &thebackGeDSSD_implant_cent, &b_BetaDecay_thebackGeDSSD_implant_cent);
   fChain->SetBranchAddress("thebackGeDSSD.decay_cent", &thebackGeDSSD_decay_cent, &b_BetaDecay_thebackGeDSSD_decay_cent);
   fChain->SetBranchAddress("thebackGeDSSD.implant_max", &thebackGeDSSD_implant_max, &b_BetaDecay_thebackGeDSSD_implant_max);
   fChain->SetBranchAddress("thebackGeDSSD.implant_timecfd", &thebackGeDSSD_implant_timecfd, &b_BetaDecay_thebackGeDSSD_implant_timecfd);
   fChain->SetBranchAddress("thebackGeDSSD.implant_timelow", &thebackGeDSSD_implant_timelow, &b_BetaDecay_thebackGeDSSD_implant_timelow);
   fChain->SetBranchAddress("thebackGeDSSD.implant_timehigh", &thebackGeDSSD_implant_timehigh, &b_BetaDecay_thebackGeDSSD_implant_timehigh);
   fChain->SetBranchAddress("thebackGeDSSD.decay_max", &thebackGeDSSD_decay_max, &b_BetaDecay_thebackGeDSSD_decay_max);
   fChain->SetBranchAddress("thebackGeDSSD.decay_timecfd", &thebackGeDSSD_decay_timecfd, &b_BetaDecay_thebackGeDSSD_decay_timecfd);
   fChain->SetBranchAddress("thebackGeDSSD.decay_timelow", &thebackGeDSSD_decay_timelow, &b_BetaDecay_thebackGeDSSD_decay_timelow);
   fChain->SetBranchAddress("thebackGeDSSD.decay_timehigh", &thebackGeDSSD_decay_timehigh, &b_BetaDecay_thebackGeDSSD_decay_timehigh);
   fChain->SetBranchAddress("thebackGeDSSD.implant_timediff", &thebackGeDSSD_implant_timediff, &b_BetaDecay_thebackGeDSSD_implant_timediff);
   fChain->SetBranchAddress("thebackGeDSSD.decay_timediff", &thebackGeDSSD_decay_timediff, &b_BetaDecay_thebackGeDSSD_decay_timediff);
   fChain->SetBranchAddress("thebackGeDSSD.implant_max_channel", &thebackGeDSSD_implant_max_channel, &b_BetaDecay_thebackGeDSSD_implant_max_channel);
   fChain->SetBranchAddress("thebackGeDSSD.decay_max_channel", &thebackGeDSSD_decay_max_channel, &b_BetaDecay_thebackGeDSSD_decay_max_channel);
   fChain->SetBranchAddress("thebackGeDSSD.implant_multiplicity", &thebackGeDSSD_implant_multiplicity, &b_BetaDecay_thebackGeDSSD_implant_multiplicity);
   fChain->SetBranchAddress("thebackGeDSSD.decay_multiplicity", &thebackGeDSSD_decay_multiplicity, &b_BetaDecay_thebackGeDSSD_decay_multiplicity);
   fChain->SetBranchAddress("thebackGeDSSD.implant_sum", &thebackGeDSSD_implant_sum, &b_BetaDecay_thebackGeDSSD_implant_sum);
   fChain->SetBranchAddress("thebackGeDSSD.decay_sum", &thebackGeDSSD_decay_sum, &b_BetaDecay_thebackGeDSSD_decay_sum);
   fChain->SetBranchAddress("thebackGeDSSD.implant_energydiff", &thebackGeDSSD_implant_energydiff, &b_BetaDecay_thebackGeDSSD_implant_energydiff);
   fChain->SetBranchAddress("thebackGeDSSD.decay_energy_diff", &thebackGeDSSD_decay_energy_diff, &b_BetaDecay_thebackGeDSSD_decay_energy_diff);
   fChain->SetBranchAddress("theSega.hit", &theSega_hit, &b_BetaDecay_theSega_hit);
   fChain->SetBranchAddress("theSega.timecfd[16]", theSega_timecfd, &b_BetaDecay_theSega_timecfd);
   fChain->SetBranchAddress("theSega.timelow[16]", theSega_timelow, &b_BetaDecay_theSega_timelow);
   fChain->SetBranchAddress("theSega.timehigh[16]", theSega_timehigh, &b_BetaDecay_theSega_timehigh);
   fChain->SetBranchAddress("theSega.time[16]", theSega_time, &b_BetaDecay_theSega_time);
   fChain->SetBranchAddress("theSega.energy[16]", theSega_energy, &b_BetaDecay_theSega_energy);
   fChain->SetBranchAddress("theSega.goodenergy[16]", theSega_goodenergy, &b_BetaDecay_theSega_goodenergy);
   fChain->SetBranchAddress("theSega.energycal[16]", theSega_energycal, &b_BetaDecay_theSega_energycal);
   fChain->SetBranchAddress("theSega.multiplicity", &theSega_multiplicity, &b_BetaDecay_theSega_multiplicity);
   fChain->SetBranchAddress("theSega.totalEnergy", &theSega_totalEnergy, &b_BetaDecay_theSega_totalEnergy);
   fChain->SetBranchAddress("thepin1.hit", &thepin1_hit, &b_BetaDecay_thepin1_hit);
   fChain->SetBranchAddress("thepin1.energy", &thepin1_energy, &b_BetaDecay_thepin1_energy);
   fChain->SetBranchAddress("thepin1.timecfd", &thepin1_timecfd, &b_BetaDecay_thepin1_timecfd);
   fChain->SetBranchAddress("thepin1.timelow", &thepin1_timelow, &b_BetaDecay_thepin1_timelow);
   fChain->SetBranchAddress("thepin1.timehigh", &thepin1_timehigh, &b_BetaDecay_thepin1_timehigh);
   fChain->SetBranchAddress("thepin1.time", &thepin1_time, &b_BetaDecay_thepin1_time);
   fChain->SetBranchAddress("thepin2.hit", &thepin2_hit, &b_BetaDecay_thepin2_hit);
   fChain->SetBranchAddress("thepin2.energy", &thepin2_energy, &b_BetaDecay_thepin2_energy);
   fChain->SetBranchAddress("thepin2.timecfd", &thepin2_timecfd, &b_BetaDecay_thepin2_timecfd);
   fChain->SetBranchAddress("thepin2.timelow", &thepin2_timelow, &b_BetaDecay_thepin2_timelow);
   fChain->SetBranchAddress("thepin2.timehigh", &thepin2_timehigh, &b_BetaDecay_thepin2_timehigh);
   fChain->SetBranchAddress("thepin2.time", &thepin2_time, &b_BetaDecay_thepin2_time);
   fChain->SetBranchAddress("thePID.de1", &thePID_de1, &b_BetaDecay_thePID_de1);
   fChain->SetBranchAddress("thePID.de2", &thePID_de2, &b_BetaDecay_thePID_de2);
   fChain->SetBranchAddress("thePID.rftof", &thePID_rftof, &b_BetaDecay_thePID_rftof);
   fChain->SetBranchAddress("thePID.xfptof", &thePID_xfptof, &b_BetaDecay_thePID_xfptof);
   fChain->SetBranchAddress("thescint.hit", &thescint_hit, &b_BetaDecay_thescint_hit);
   fChain->SetBranchAddress("thescint.energy", &thescint_energy, &b_BetaDecay_thescint_energy);
   fChain->SetBranchAddress("thescint.timecfd", &thescint_timecfd, &b_BetaDecay_thescint_timecfd);
   fChain->SetBranchAddress("thescint.timelow", &thescint_timelow, &b_BetaDecay_thescint_timelow);
   fChain->SetBranchAddress("thescint.timehigh", &thescint_timehigh, &b_BetaDecay_thescint_timehigh);
   fChain->SetBranchAddress("thescint.time", &thescint_time, &b_BetaDecay_thescint_time);
   fChain->SetBranchAddress("theCorrelator.dt_implant", &theCorrelator_dt_implant, &b_BetaDecay_theCorrelator_dt_implant);
   fChain->SetBranchAddress("theCorrelator.implant_time", &theCorrelator_implant_time, &b_BetaDecay_theCorrelator_implant_time);
   fChain->SetBranchAddress("theCorrelator.implant_de1", &theCorrelator_implant_de1, &b_BetaDecay_theCorrelator_implant_de1);
   fChain->SetBranchAddress("theCorrelator.implant_de2", &theCorrelator_implant_de2, &b_BetaDecay_theCorrelator_implant_de2);
   fChain->SetBranchAddress("theCorrelator.implant_tof", &theCorrelator_implant_tof, &b_BetaDecay_theCorrelator_implant_tof);
   fChain->SetBranchAddress("theCorrelator.gamma_timecal", &theCorrelator_gamma_timecal, &b_BetaDecay_theCorrelator_gamma_timecal);
   fChain->SetBranchAddress("theCorrelator.gamma_time", &theCorrelator_gamma_time, &b_BetaDecay_theCorrelator_gamma_time);
   fChain->SetBranchAddress("theCorrelator.gamma_de1", &theCorrelator_gamma_de1, &b_BetaDecay_theCorrelator_gamma_de1);
   fChain->SetBranchAddress("theCorrelator.gamma_de2", &theCorrelator_gamma_de2, &b_BetaDecay_theCorrelator_gamma_de2);
   fChain->SetBranchAddress("theCorrelator.gamma_tof", &theCorrelator_gamma_tof, &b_BetaDecay_theCorrelator_gamma_tof);
   fChain->SetBranchAddress("theCorrelator.decay_timecal", &theCorrelator_decay_timecal, &b_BetaDecay_theCorrelator_decay_timecal);
   fChain->SetBranchAddress("theCorrelator.decay_time", &theCorrelator_decay_time, &b_BetaDecay_theCorrelator_decay_time);
   fChain->SetBranchAddress("theCorrelator.decay_de1", &theCorrelator_decay_de1, &b_BetaDecay_theCorrelator_decay_de1);
   fChain->SetBranchAddress("theCorrelator.decay_de2", &theCorrelator_decay_de2, &b_BetaDecay_theCorrelator_decay_de2);
   fChain->SetBranchAddress("theCorrelator.decay_tof", &theCorrelator_decay_tof, &b_BetaDecay_theCorrelator_decay_tof);
   fChain->SetBranchAddress("theCorrelator.front_implant_max_channel", &theCorrelator_front_implant_max_channel, &b_BetaDecay_theCorrelator_front_implant_max_channel);
   fChain->SetBranchAddress("theCorrelator.front_decay_max_channel", &theCorrelator_front_decay_max_channel, &b_BetaDecay_theCorrelator_front_decay_max_channel);
   fChain->SetBranchAddress("theCorrelator.back_implant_max_channel", &theCorrelator_back_implant_max_channel, &b_BetaDecay_theCorrelator_back_implant_max_channel);
   fChain->SetBranchAddress("theCorrelator.back_decay_max_channel", &theCorrelator_back_decay_max_channel, &b_BetaDecay_theCorrelator_back_decay_max_channel);
   fChain->SetBranchAddress("theCorrelator.flag", &theCorrelator_flag, &b_BetaDecay_theCorrelator_flag);
   fChain->SetBranchAddress("theCorrelator.implant_mult", &theCorrelator_implant_mult, &b_BetaDecay_theCorrelator_implant_mult);
   fChain->SetBranchAddress("theCorrelator.decay_mult", &theCorrelator_decay_mult, &b_BetaDecay_theCorrelator_decay_mult);
   Notify();
}

Bool_t BetaDecayAnalyzer::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void BetaDecayAnalyzer::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t BetaDecayAnalyzer::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef BetaDecayAnalyzer_cxx
