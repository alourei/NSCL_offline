#define BetaDecayAnalyzer_cxx
#include "BetaDecayAnalyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include <cstdio>
#include <iostream>
#include <TH1I.h>
#include <TH1F.h>
#include <TFile.h>
#include <TF1.h>
#include <TF2.h>
#include <TMath.h>
#include <TRandom2.h>
#include <TCutG.h>

#define DEBUG 0
using namespace std;

void BetaDecayAnalyzer::Loop(Int_t nevents)
//void BetaDecayAnalyzer::Loop(Int_t nevents=-1,Char_t filename*="histos.root")
{
//   In a ROOT session, you can do:
//      Root > .L BetaDecayAnalyzer.C
//      Root > BetaDecayAnalyzer t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

Double_t LoTime[16];
Double_t HiTime[16];

LoTime[0]= 2982.045410;
HiTime[0]= 3133.047852;

LoTime[1]= 2972.045410;
HiTime[1]= 3116.047607;

LoTime[2]= 2976.045410;
HiTime[2]= 3125.047607;

LoTime[3]= 2980.045654;
HiTime[3]= 3129.047852;

LoTime[4]= 2975.045410;
HiTime[4]= 3108.047363;

LoTime[5]= 2984.045654;
HiTime[5]= 3144.048096;

LoTime[6]= 2989.045654;
HiTime[6]= 3116.047607;

LoTime[7]= 2984.045654;
HiTime[7]= 3136.047852;

LoTime[8]= 2982.045410;
HiTime[8]= 3103.047363;

LoTime[9]= 2987.045654;
HiTime[9]= 3117.047607;

LoTime[10]= 2977.045410;
HiTime[10]= 3117.047607;

LoTime[11]= 2986.045654;
HiTime[11]= 3135.047852;

LoTime[12]= 2947.044922;
HiTime[12]= 3140.047852;

LoTime[13]= 2965.045166;
HiTime[13]= 3132.047852;

LoTime[14]= 2984.045654;
HiTime[14]= 3135.047852;

LoTime[15]= 2981.045410;
HiTime[15]= 3125.047607;

 for(Int_t j=0;j<16;j++){
   LoTime[15]= 0;
   HiTime[15]= 0;
}

 Int_t Sci_threshold=10;

 TFile *fil=new TFile("histos_sorted.root","RECREATE");
 
 Int_t Nbins=9500; 

  TH1F *hSeGAtot2=new TH1F("SeGAtot2","Total SeGA coincidence with Scint",Nbins,0,Nbins);
  TH1F *hSeGAtot3=new TH1F("SeGAtot3","Total SeGA ",Nbins,0,Nbins);


  TH1F *hSega_gated238=new TH1F("SeGAtot_g238","Total SeGA gated 238",Nbins,0,Nbins);

  TH1F *hSega_gated275=new TH1F("SeGAtot_g275","Total SeGA gated 275",Nbins,0,Nbins);

  TH1F *hSega_gated984=new TH1F("SeGAtot_g984","Total SeGA gated 984",Nbins,0,Nbins);

  TH1F *hSega_gated1298=new TH1F("SeGAtot_g1298","Total SeGA gated 1298",Nbins,0,Nbins);

  TH1F *hSega_gated1634=new TH1F("SeGAtot_g1634","Total SeGA gated 1634",Nbins,0,Nbins);

  TH1F *hSega_gated3332=new TH1F("SeGAtot_g3332","Total SeGA gated 3332",Nbins,0,Nbins);


   TH1F *sega[16];
   TH1F *sega_gated[16];

   TH1F *hScint=new TH1F("hScint","Scintillator Energy",8192,0,65536);

  for(Int_t m=0;m<16;m++){

    Char_t histoName[256];
    Char_t histoTitle[256];
    sprintf(histoName,"h_SeGA_%d",m);
    sprintf(histoTitle,"h_SeGA_%d Ungated",m);
    sega[m]=new TH1F(histoName,histoTitle,Nbins,0,Nbins);
    sprintf(histoName,"h_SeGA_gated_%d",m);
    sprintf(histoTitle,"h_SeGA_%d Gated on GeDSSD",m);
    sega_gated[m]=new TH1F(histoName,histoTitle,Nbins,0,Nbins);
  }

  Bool_t inside238;
  Int_t channel_238=-1;

  Float_t Lo238=236;
  Float_t Hi238=242;

  Bool_t inside275;
  Int_t channel_275=-1;

  Float_t Lo275=273;
  Float_t Hi275=278;


  Bool_t inside984;
  Int_t channel_984=-1;

  Float_t Lo984=0;
  Float_t Hi984=0;

  Bool_t inside1298;
  Int_t channel_1298=-1;

  Float_t Lo1298=0;
  Float_t Hi1298=0;

  Bool_t inside1634;
  Int_t channel_1634=-1;

  Float_t Lo1634=0;
  Float_t Hi1634=0;

  Bool_t inside3332;
  Int_t channel_3332=-1;
  
  Float_t Lo3332=0;
  Float_t Hi3332=0;

  TH2F *hPID_total=new TH2F("PID2","PID",1024,0,20000,1024,0,25000);

  TTree *ch=fChain;
  hSeGAtot2->SetLineColor(2);
  hSeGAtot3->SetLineColor(3);
  Char_t hname[256];
  Char_t htitle[256];

  if (fChain == 0) return;
  
  fChain->SetBranchStatus("*",0);  // disable all branches
  fChain->SetBranchStatus("theSega.energy[16]",1);  // activate branchname
  fChain->SetBranchStatus("theSega.energycal[16]",1);  // activate branchname
  fChain->SetBranchStatus("theSega.time[16]",1);  // activate branchname
  
  fChain->SetBranchStatus("thePID.de1",1);  // activate branchname
  fChain->SetBranchStatus("thePID.xfptof",1);  // activate branchname

  fChain->SetBranchStatus("thescint.energy",1);  // activate branchname

  TRandom2 ran;
  Long64_t nentries;

  if(nevents==-1)
    nentries = fChain->GetEntries();
  else
    nentries = nevents;

   Long64_t nbytes = 0, nb = 0;
 
   Int_t fiveper=(Int_t)(nentries*0.05);
 
   for (Long64_t jentry=0; jentry<nentries;jentry++) {

     if(jentry % fiveper ==0){
       cout<<"Events processed "<<jentry<<" "<<(Int_t)(jentry/fiveper)*5<<"% do\
ne"<<flush;
       cout<<"\r"<<flush;
}
     inside238=kFALSE;
     channel_238=-1;
     
     inside275=kFALSE;
     channel_275=-1;
     
     inside984=kFALSE;
     channel_984=-1;
     
     inside1298=kFALSE;
     channel_1298=-1;
     
     inside1634=kFALSE;
     channel_1634=-1;
     
     inside3332=kFALSE;
     channel_3332=-1;

      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);
      nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if(thePID_de1&&thePID_xfptof)
        hPID_total->Fill(thePID_xfptof,thePID_de1);

      //if(thescint_hit)
	hScint->Fill(thescint_energy);
      
      for(Int_t k=0;k<16;k++){

	// if(theSega_energycal[k]>0 && (theSega_time[k]>LoTime[k] && theSega_time[k]<HiTime[k])){
       if(theSega_energycal[k]>0){

	 if(DEBUG>2){
	   cout<<"theSega_energycal[k] "<<theSega_energycal[k]<<endl;
	   cout<<"theScint[k] "<<thescint_energy<<endl;
	  
	 }
          sega[k]->Fill(theSega_energycal[k]);
	  if((k==5&&theSega_energycal[k]>5900)||(k==11&&theSega_energycal[k]>8250))
	    continue;
	  
          if(theSega_energycal[k]>Lo238 && theSega_energycal[k]<Hi238){
            inside238=kTRUE;
            channel_238=k;
          }
	  
          if(theSega_energycal[k]>Lo275 && theSega_energycal[k]<Hi275){
            inside275=kTRUE;
            channel_275=k;
          }
	  
          if(theSega_energycal[k]>Lo984 && theSega_energycal[k]<Hi984){
            inside984=kTRUE;
            channel_984=k;
          }
	  
          if(theSega_energycal[k]>Lo1298 && theSega_energycal[k]<Hi1298){
            inside1298=kTRUE;
            channel_1298=k;
          }
	  
	  if(theSega_energycal[k]>Lo1634 && theSega_energycal[k]<Hi1634){
            inside1634=kTRUE;
            channel_1634=k;
          }
	  
	  if(theSega_energycal[k]>Lo3332 && theSega_energycal[k]<Hi3332){
            inside3332=kTRUE;
            channel_3332=k;
          }
	  
	  if(thescint_energy>Sci_threshold){
	    hSeGAtot2->Fill(theSega_energycal[k]);
	    sega_gated[k]->Fill(theSega_energycal[k]);
	  }  
	  if(theSega_energycal[k]>0){
	    if(k==5&&theSega_energycal[k]>5900||(k==11&&theSega_energycal[k]>8250))
	      continue;
	    else
	      hSeGAtot3->Fill(theSega_energycal[k]);
	  
	  }
       }
       else continue;
      }
      
     for(Int_t k=0;k<16;k++){

       //if(theSega_energycal[k]>0 && (theSega_time[k]>LoTime[k] && theSega_time[k]<HiTime[k])){
        if(theSega_energycal[k]>0){

          if(inside238==kTRUE && k!=channel_238)
            hSega_gated238->Fill(theSega_energycal[k]);

          if(inside275==kTRUE && k!=channel_275)
            hSega_gated275->Fill(theSega_energycal[k]);

          if(inside984==kTRUE && k!=channel_984)
            hSega_gated984->Fill(theSega_energycal[k]);

          if(inside1298==kTRUE && k!=channel_1298)
            hSega_gated1298->Fill(theSega_energycal[k]);

          if(inside1634==kTRUE && k!=channel_1634)
            hSega_gated1634->Fill(theSega_energycal[k]);

          if(inside3332==kTRUE && k!=channel_3332)
            hSega_gated3332->Fill(theSega_energycal[k]);
 	}

   }

   }//End of event Loop
   hSeGAtot3->Draw();

   fChain->Write("T");
   fil->Write();

   cout<<endl;

}

