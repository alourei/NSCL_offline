#include "Chain.C"
void macro(){
  gROOT->ProcessLine(".L BetaDecayAnalyzer.C+");
  //Int_t files[]={17,21,22,23,24,25,26,27,28,29,32,37,38,39,40,41,42,43,44,45,46,
  //		 49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,0};
  //Add here the list of runs you want to analize ending with 0
  Int_t files[]={56,0};
  TChain *ch=Chain(files);
  BetaDecayAnalyzer *theAnalyzer=new BetaDecayAnalyzer(ch);
  Char_t filename[256]="histograms.root";
  theAnalyzer->Loop(-1);
}
