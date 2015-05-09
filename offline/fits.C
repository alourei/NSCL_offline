//Macro for reading text file and creating a ROOT histogram
//David Perez-Loureiro perez-loureiro@nscl.msu.edu
//History:
//10/18/2013: First Version
//10/29/2013: New version with background independent fitting
//04/30/2014: Added new Calibration from Mg-24
#include "TH1.h"
#include "TF1.h"
#include "TSpectrum.h"


//Function for plotting ASCII spectra
TH1I* histogram(Char_t *histoname="h",Char_t *filename="sega-tacdxy-tot_9Jul2013_sort.txt",Int_t nbins=8192){
  //Added new Calibration
  TF1 *calib=new TF1("calibration","pol1",0,8192);
  //calib->SetParameters(-1.343,1.);
  //calib->SetParameters( 1.13859e-01, 9.99894e-01);


ifstream *in=new ifstream(filename);
if(!in->is_open()){
cout<<"File not found!!"<<endl;
return NULL;
}

Int_t channel,counts;
TH1I *spectrum =new TH1I(histoname,"SeGA Spectrum",nbins,0,8192);
 while(*in>>channel>>counts){
  Float_t energy=calib->Eval(channel+1);
  //spectrum->SetBinContent(channel+1,counts);
  Int_t bin=spectrum->FindBin(channel);
 //cout<<energy<<" "<<bin<<endl;
  	spectrum->SetBinContent(bin,counts);
 }
return spectrum;
}

//Function for calculating background
TH1I* background_sp(TH1* histo){
TSpectrum *sp=new TSpectrum();
TH1I *background=sp->Background(histo,20,"nosmoothingBackOrder4Compton");
return background;
}

//Function for calculating background suppressed spectrum
TH1I *substract_background(TH1I *histo, TH1I *background){
TH1I* dummy=(TH1I*)histo->Clone("clone");
dummy->Add(background,-1);
return dummy;
}


void draw(){
TH1I *sp=histogram();
TH1I *back=background_sp(sp);
back->SetLineColor(2);
TH1I *sp_back=substract_background(sp,back);
sp_back->SetLineColor(3);
sp->Draw();
back->Draw("same");
sp_back->Draw("same");
}



//************Defining fit functions *****************//

//Normalized gaussian
Double_t Norm_gaus(Double_t *x,Double_t *par){

  Double_t pi=TMath::Pi();
  Double_t exponent=pow((x[0]-par[1])/par[2],2)/2.;
  Double_t val=par[0]/sqrt(2*pi)/par[2]*exp(-exponent);
  return val;   
}

//Exponentially modified gaussian
Double_t exp_gaus(Double_t *x,Double_t *par){
Double_t xx=x[0];
Double_t val=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  return val;  
}

Double_t exp_gaus2(Double_t *x,Double_t *par){
  Double_t xx=x[0];
  Double_t val=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  val+=(par[5]/(2*par[0]))*(1-TMath::Erf(((xx-par[4])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[4])/par[0]);
  return val;  
}


Double_t exp_gaus3(Double_t *x,Double_t *par){
  Double_t xx=x[0];
  Double_t val=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  val+=(par[5]/(2*par[0]))*(1-TMath::Erf(((xx-par[4])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[4])/par[0]);
  val+=(par[7]/(2*par[0]))*(1-TMath::Erf(((xx-par[6])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[6])/par[0]);
  return val;  
}

Double_t exp_gaus_Doppler(Double_t *x,Double_t *par){
  Double_t xx=x[0];
  Double_t val=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2]+par[4])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  val+=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2]+0.5*par[4])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  val+=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2]+0.25*par[4])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  val+=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  val+=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2]-0.25*par[4])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  val+=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2]-0.5*par[4])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  val+=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2]-par[4])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  return val;  
}
 
Double_t exp_gaus_Doppler2(Double_t *x,Double_t *par){
  Double_t xx=x[0];
  Double_t val=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2]+par[4])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  val+=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2]+0.5*par[4])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  val+=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2]+0.25*par[4])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  val+=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  val+=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2]-0.25*par[4])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  val+=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2]-0.5*par[4])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  val+=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2]-par[4])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  
  val+=(par[6]/(2*par[0]))*(1-TMath::Erf(((xx-par[5])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[5])/par[0]);
  return val;  
}

Double_t exp_gaus_Doppler3(Double_t *x,Double_t *par){
  Double_t xx=x[0];
  Double_t val=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2]+par[4])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  val+=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2]+0.5*par[4])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  val+=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2]+0.25*par[4])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  val+=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  val+=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2]-0.25*par[4])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  val+=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2]-0.5*par[4])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  val+=(par[3]/(2*par[0]))*(1-TMath::Erf(((xx-par[2]-par[4])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[2])/par[0]);
  
  val+=(par[6]/(2*par[0]))*(1-TMath::Erf(((xx-par[6])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[4])/par[0]);

  val+=(par[8]/(2*par[0]))*(1-TMath::Erf(((xx-par[7]+par[9])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[7])/par[0]);
  val+=(par[8]/(2*par[0]))*(1-TMath::Erf(((xx-par[7]+0.5*par[9])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[7])/par[0]);
  val+=(par[8]/(2*par[0]))*(1-TMath::Erf(((xx-par[7]+0.25*par[9])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[7])/par[0]);
  val+=(par[8]/(2*par[0]))*(1-TMath::Erf(((xx-par[7])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[7])/par[0]);
  val+=(par[8]/(2*par[0]))*(1-TMath::Erf(((xx-par[7]-0.25*par[9])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[7])/par[0]);
  val+=(par[8]/(2*par[0]))*(1-TMath::Erf(((xx-par[7]-0.5*par[9])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[7])/par[0]);
  val+=(par[8]/(2*par[0]))*(1-TMath::Erf(((xx-par[7]-par[9])/par[1]+par[1]/par[0])/sqrt(2)))*TMath::Exp(0.5*par[1]*par[1]/(par[0]*par[0])+(xx-par[7])/par[0]);
  return val;  
}

//2nd-Order polynomial background
Double_t background2(Double_t *x,Double_t *par){
return par[0] + par[1]*x[0] + par[2]*x[0]*x[0];
}

//Linear background
Double_t background(Double_t *x,Double_t *par){
return par[0] + par[1]*x[0];
}

//Peak Rejection 2nd-Order polynomial background fit
Bool_t reject=kTRUE;
Double_t x0=0;
Double_t xf=0;
Double_t background_rej(Double_t *x, Double_t *par)
{
    if (reject && x[0] > x0 && x[0] < xf) {
      TF1::RejectPoint();
      return 0;
   }
   return par[0] + par[1]*x[0];
}

Double_t background_rej2(Double_t *x, Double_t *par)
{
    if (reject && x[0] > x0 && x[0] < xf) {
      TF1::RejectPoint();
      return 0;
   }
   return par[0] + par[1]*x[0] + par[2]*x[0]*x[0];
}

Double_t background_rej3(Double_t *x, Double_t *par)
{
    if (reject && x[0] > x0 && x[0] < xf) {
      TF1::RejectPoint();
      return 0;
   }
   return par[0] + par[1]*x[0] + par[2]*x[0]*x[0]+par[3]*x[0]*x[0]*x[0];
}

//Chris' function
Double_t local26PfitExpgauss(Double_t *x, Double_t *par){
  
  //Parabolic BackGround+EMGs
  Double_t val;
  Double_t xx=x[0];
  
  val=par[0];
  val+=par[1]*xx;
  val+=par[2]*xx*xx;
  
  //EMG par[3] decay par[4]=width par[5] pos par[6] ampl
  val+=(par[6]/(2*par[3]))*(1-TMath::Erf(((xx-par[5])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[5])/par[3]);

  val+=(par[8]/(2*par[3]))*(1-TMath::Erf(((xx-par[7])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[7])/par[3]);

  val+=(0.2803*par[8]/(2*par[3]))*(1-TMath::Erf(((xx-par[7]-32.2)/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[7]-32.2)/par[3]);

  val+=(par[10]/(2*par[3]))*(1-TMath::Erf(((xx-par[9])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[9])/par[3]);

  val+=(par[11]/(2*par[3]))*(1-TMath::Erf(((xx-par[7]+2.4)/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[7]+2.4)/par[3]);

  val+=(5.37*par[11]/(2*par[3]))*(1-TMath::Erf(((xx-par[7]-32.5)/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[7]-32.5)/par[3]);

  val+=(5.37*par[13]/(2*par[3]))*(1-TMath::Erf(((xx-par[12])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[12])/par[3]);


  val+=(par[15]/(2*par[3]))*(1-TMath::Erf(((xx-par[14]+par[16])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[14]+par[16])/par[3]);

  val+=(par[15]/(2*par[3]))*(1-TMath::Erf(((xx-par[14]+.5*par[16])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[14]+.5*par[16])/par[3]);

  val+=(par[15]/(2*par[3]))*(1-TMath::Erf(((xx-par[14])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[14])/par[3]);

  val+=(par[15]/(2*par[3]))*(1-TMath::Erf(((xx-par[14]-.5*par[16])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[14]-.5*par[16])/par[3]);

  val+=(par[15]/(2*par[3]))*(1-TMath::Erf(((xx-par[14]-par[16])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[14]-par[16])/par[3]);
  

  val+=(par[18]/(2*par[3]))*(1-TMath::Erf(((xx-par[17]+par[19])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[17]+par[19])/par[3]);

  val+=(par[18]/(2*par[3]))*(1-TMath::Erf(((xx-par[17]+.5*par[19])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[17]+.5*par[19])/par[3]);

  val+=(par[18]/(2*par[3]))*(1-TMath::Erf(((xx-par[17])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[17])/par[3]);

  val+=(par[18]/(2*par[3]))*(1-TMath::Erf(((xx-par[17]-.5*par[19])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[17]-.5*par[19])/par[3]);

  val+=(par[18]/(2*par[3]))*(1-TMath::Erf(((xx-par[17]-par[19])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[17]-par[19])/par[3]);


  val+=(par[20]/(2*par[3]))*(1-TMath::Erf(((xx-par[17]+par[21])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[17]+par[21])/par[3]);

  val+=(par[20]/(2*par[3]))*(1-TMath::Erf(((xx-par[17]+.5*par[21])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[17]+.5*par[21])/par[3]);

  val+=(par[20]/(2*par[3]))*(1-TMath::Erf(((xx-par[17])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[17])/par[3]);

  val+=(par[20]/(2*par[3]))*(1-TMath::Erf(((xx-par[17]-.5*par[21])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[17]-.5*par[21])/par[3]);

  val+=(par[20]/(2*par[3]))*(1-TMath::Erf(((xx-par[17]-par[21])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[17]-par[21])/par[3]);


  val+=(par[22]/(2*par[3]))*(1-TMath::Erf(((xx-par[23])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[23])/par[3]);

  val+=(par[24]/(2*par[3]))*(1-TMath::Erf(((xx-par[25])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[25])/par[3]);
 
  val+=(par[27]/(2*par[3]))*(1-TMath::Erf(((xx-par[26]+par[28])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[26]+par[28])/par[3]);

  val+=(par[27]/(2*par[3]))*(1-TMath::Erf(((xx-par[26]+.5*par[28])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[26]+.5*par[28])/par[3]);

  val+=(par[27]/(2*par[3]))*(1-TMath::Erf(((xx-par[26])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[26])/par[3]);

  val+=(par[27]/(2*par[3]))*(1-TMath::Erf(((xx-par[26]-.5*par[28])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[26]-.5*par[28])/par[3]);

  val+=(par[27]/(2*par[3]))*(1-TMath::Erf(((xx-par[26]-par[28])/par[4]+par[4]/par[3])/sqrt(2)))*TMath::Exp(0.5*par[4]*par[1]/(par[3]*par[3])+(xx-par[26]-par[28])/par[3]);

  return val;

}




//The total fit function
Double_t myfitfunction(Double_t *x,Double_t *par){
return background(x,par)+exp_gaus(x,&par[2]);
}

//The total fit function(Pol2 BG+ 1peak)
Double_t myfitfunction2(Double_t *x,Double_t *par){

  return background2(x,par)+exp_gaus(x,&par[3]);
}

Double_t myfitfunction2peaks(Double_t *x,Double_t *par){

  return background(x,par)+exp_gaus2(x,&par[2]);
}

Double_t myfitfunction2peaks2(Double_t *x,Double_t *par){

  return background2(x,par)+exp_gaus2(x,&par[3]);
}

Double_t myfitfunction3peaks(Double_t *x,Double_t *par){

  return background(x,par)+exp_gaus3(x,&par[2]);
}

Double_t myfitfunction3peaks2(Double_t *x,Double_t *par){

  return background2(x,par)+exp_gaus3(x,&par[3]);
}

Double_t  myfitfunctionDoppler_lin(Double_t *x,Double_t *par){

  return background(x,par)+exp_gaus_Doppler3(x,&par[2]);
}

Double_t  myfitfunctionDoppler_par(Double_t *x,Double_t *par){

  return background2(x,par)+exp_gaus_Doppler3(x,&par[3]);
}

//The total fit function(2peaks)
Double_t myfitfunction3(Double_t *x,Double_t *par){
return background(x,par)+exp_gaus(x,&par[2])+exp_gaus(x,&par[6]);
}

//The total fit function(3peaks)
Double_t myfitfunction4(Double_t *x,Double_t *par){
return background(x,par)+exp_gaus(x,&par[2])+exp_gaus(x,&par[6])+exp_gaus(x,&par[10]);
}
 
//The total fit function(4peaks)
Double_t myfitfunction4(Double_t *x,Double_t *par){
return background(x,par)+exp_gaus(x,&par[2])+exp_gaus(x,&par[6])+exp_gaus(x,&par[10])++exp_gaus(x,&par[14]);
}
 

void dofit(TH1F *sp,Double_t x_initial,Double_t x_final){
  //TF1 *peak=fit_peak(x_initial,x_final);
  //TF1 *peak=fit_peak2(x_initial,x_final);
  //TF1 *total=fit_total(x_initial,x_final,peak);
  Double_t parameters[]={1166.2,-0.53404,0,1.202,1.536,1741.6,175.15,1732.2,389.05,1735,0,85.597,1759.4,
			 213.87,1775.1,296.1,3.8194,1789.5,216.99,1.7202,212.24,6.5266,30108,1797,
			 1267.9,1800.8,1809.8,43.409,3.4258};
  TF1 *fit=fun_Chris(x_initial,x_final,parameters);
  //fit->SetRange(1780,1820);
  reject= kTRUE;
  x0=x_initial;
  xf=x_final;
  //TF1 *back=new TF1("bck",background_rej,x0-10,xf+10,3);
  //TH1I *sp=histogram();
  sp->Draw();
  //fit->Draw("same");
  //fit->FixParameter(2,0);
  //fit->FixParameter(3,1.202);
  //fit->FixParameter(4,1.536);
  //fit->FixParameter(9,1735);
  //fit->FixParameter(10,0);
  //fit->FixParameter(17,1789.5);
  //fit->FixParameter(26,1809.8);
  sp->Fit("func","R");
 //TF1 *fback=new TF1("funback","pol2",x0-10,xf+10);
 //fback->SetParameters(back->GetParameters());
 //fback->SetLineColor(5);
 //fback->Draw("same");
}

TF1 *fun_Chris(Double_t x_0,Double_t x_f,Double_t *parameters){

  TF1 *func=new TF1("func",local26PfitExpgauss,x_0,x_f,29);
  func->SetParameters(parameters);
  func->FixParameter(2,0);
  func->FixParameter(3,1.202);
  func->FixParameter(4,1.536);
  //func->SetParLimits(5,1740,1744);
  //func->SetParLimits(6,100,200);
  //func->SetParLimits(7,1729,1735);
  //func->SetParLimits(8,100,400);
  func->FixParameter(9,1735);
  func->FixParameter(10,0);
  //func->SetParLimits(11,70,90);
  //func->SetParLimits(12,1756,1762);
  //func->SetParLimits(13,0,500);
  //func->SetParLimits(14,1771,1778);
  //func->SetParLimits(15,0,400);
  //func->SetParLimits(16,0,10);
  func->FixParameter(17,1789.5);
  //func->SetParLimits(18,0,400);
  //func->SetParLimits(19,0,2);
  //func->SetParLimits(20,0,300);
  //func->SetParLimits(21,0,9);
  //func->SetParLimits(22,0,60000);
  //func->SetParLimits(23,1790,1800);
  //func->SetParLimits(24,1265,1270);
  //func->SetParLimits(25,1795,1803);
  func->FixParameter(26,1809.8);
  //func->SetParLimits(27,0,50);
  //func->SetParLimits(28,0,6);

  return func;


}

TF1* fit_spectrum(TH1I *sp,Double_t x_0,Double_t x_f,Double_t peak_0,Double_t peak_f,
	Double_t peak1,Double_t peak2=0,Double_t peak3=0,Double_t peak4=0){
x0=peak_0;
xf=peak_f;
//Background
TF1 *background=new TF1("background",background_rej,x_0,x_f,2);
TF1 *background2=new TF1("background2",background_rej2,x_0,x_f,3);
TF1 *background3=new TF1("background3",background_rej3,x_0,x_f,4);
background->SetLineColor(3);
background3->SetLineColor(4);
sp->Fit("background","QNR");
cout<<"Chi2/NDF: "<<background->GetChisquare()/background->GetNDF()<<endl;
cout<<"Probability: "<<background->GetProb()<<endl;
sp->Fit("background2","RN");
cout<<"Chi2/NDF: "<<background2->GetChisquare()/background2->GetNDF()<<endl;
sp->Fit("background3","QRN");
cout<<"Chi2/NDF: "<<background3->GetChisquare()/background3->GetNDF()<<endl;
//sp->Draw("");
//background->Draw("same");
//background2->Draw("same");
//background3->Draw("same");

//Background+Peaks
if(peak4!=0){

TF1 *fit=new TF1("fit",myfitfunction4,x_0,x_f,18);
fit->SetParameter(0,background->GetParameter(0));
fit->SetParameter(1,background->GetParameter(1));
fit->SetParLimits(2,0.6,0.8);
fit->SetParameter(2,0.7);
fit->SetParameter(3,1.6);
fit->SetParameter(4,peak1);
fit->SetParLimits(5,0,200000);
fit->SetParameter(5,2000);

fit->SetParLimits(6,0.6,0.8);
fit->SetParameter(6,0.7);
fit->SetParameter(7,1.6);
fit->SetParameter(8,peak2);
fit->SetParLimits(9,0,200000);
fit->SetParameter(9,2000);

fit->SetParLimits(10,0.6,0.8);
fit->SetParameter(10,0.7);
fit->SetParameter(11,1.6);
fit->SetParameter(12,peak3);
fit->SetParLimits(13,0,200000);
fit->SetParameter(13,2000);

fit->SetParLimits(14,0.6,0.8);
fit->SetParameter(14,0.7);
fit->SetParameter(15,1.6);
fit->SetParameter(16,peak4);
fit->SetParLimits(17,0,200000);
fit->SetParameter(17,2000);
}
else if(peak4==0&&peak3!=0){
TF1 *fit=new TF1("fit",myfitfunction4,x_0,x_f,14);
fit->SetParameter(0,background->GetParameter(0));
fit->SetParameter(1,background->GetParameter(1));
fit->SetParLimits(2,0.6,0.8);
//fit->SetParameter(2,0.7);
//fit->SetParameter(3,1.6);
fit->FixParameter(2,1.202);
fit->FixParameter(3,1.536);
fit->SetParameter(4,peak1);
fit->SetParLimits(5,0,200000);
fit->SetParameter(5,2000);

fit->SetParLimits(6,0.6,0.8);
//fit->SetParameter(6,0.7);
//fit->SetParameter(7,1.6);
fit->FixParameter(6,1.202);
fit->FixParameter(7,1.536);
fit->SetParameter(8,peak2);
fit->SetParLimits(9,0,200000);
fit->SetParameter(9,2000);

fit->SetParLimits(10,0.6,0.8);
//fit->SetParameter(10,0.7);
//fit->SetParameter(11,1.6);
fit->FixParameter(10,1.202);
fit->FixParameter(11,1.536);
fit->SetParameter(12,peak3);
fit->SetParLimits(13,0,200000);
fit->SetParameter(13,2000);


}
// else if(peak3==0&&peak2!=0){
// TF1 *fit=new TF1("fit",myfitfunction3,x_0,x_f,10);
// fit->SetParameter(0,background->GetParameter(0));
// fit->SetParameter(1,background->GetParameter(1));
// fit->SetParLimits(2,0.6,0.8);
// //fit->SetParameter(2,.7);
// fit->FixParameter(2,1.202);
// fit->FixParameter(3,1.536);
// //fit->SetParameter(3,1.6);
// fit->SetParameter(4,peak1);
// fit->SetParLimits(5,0,200000);
// fit->SetParameter(5,20000);

// fit->SetParLimits(6,0.6,0.8);
// //fit->SetParameter(6,.7);
// //fit->SetParameter(7,1.6);
// fit->FixParameter(6,1.202);
// fit->FixParameter(7,1.536);
// fit->SetParameter(8,peak2);
// fit->SetParLimits(9,0,200000);
// fit->SetParameter(9,20000);
// }

else{
TF1 *fit=new TF1("fit",myfitfunction2,x_0,x_f,9);
fit->SetParameter(0,background2->GetParameter(0));
fit->SetParameter(1,background2->GetParameter(1));
fit->SetParameter(2,background2->GetParameter(2));
//fit->SetParLimits(2,0,50);
//fit->SetParLimits(3,0.6,50);
//fit->SetParLimits(4,0.6,50);
//fit->FixParameter(2,0);
fit->SetParName(3,"#tau");
fit->SetParName(4,"#sigma");
fit->SetParName(5,"#mu_{1}");
fit->SetParName(6,"Constant_{1}");
fit->SetParName(7,"#mu_{2}");
fit->SetParName(8,"Constant_{2}");

fit->SetParameter(3,0.98);
fit->SetParameter(4,1.57);
//fit->FixParameter(3,1.12);
//fit->FixParameter(4,1.54);
fit->SetParameter(5,peak1);
fit->SetParameter(6,200000);
//fit->FixParameter(7,0);
//fit->FixParameter(8,0);
fit->SetParameter(7,peak2);
fit->SetParameter(8,100000);
//fit->SetParLimits(6,0,20000000);
}

sp->Fit(fit,"R");
//cout<<"Chi2/NDF: "<<fit->GetChisquare()/fit->GetNDF()<<endl;
cout<<"Probability: "<<fit->GetProb()<<endl;
return fit;
}



TF1 *fit_spectrum2(Bool_t write,TH1I* sp,Double_t x_0,Double_t x_f,Double_t peak_0,Double_t peak_f,Double_t tau,Double_t sigma,Double_t peak1, Double_t Norm1, Double_t peak2=0,Double_t Norm2=0,Double_t peak3=0,Double_t Norm3=0){

  //First I fit background
  x0=peak_0;
  xf=peak_f;
  Bool_t Fix_Tau=kFALSE;
  //Bool_t Fix_Sigma=kTRUE;
  //Bool_t Fix_Tau=kTRUE;
  Bool_t Fix_Sigma=kFALSE;
  //Bool_t write=kFALSE;
  //if(write)
    ofstream * out=new ofstream("Fit_parameters_SRMSource.txt",ios::app);
  TF1 *background=new TF1("background",background_rej,x_0,x_f,2);
  TF1 *background2=new TF1("background2",background_rej2,x_0,x_f,3);
  background->SetLineColor(3);
  background2->SetLineColor(4);
  sp->Fit(background,"R");
  cout<<"Chi2/NDF: "<<background->GetChisquare()/background->GetNDF()<<endl;
  Double_t reducedChiSq_lin=background->GetChisquare()/background->GetNDF();
  cout<<"Probability: "<<background->GetProb()<<endl;
  sp->Fit(background2,"R+");
  cout<<"Chi2/NDF: "<<background2->GetChisquare()/background2->GetNDF()<<endl;
  Double_t reducedChiSq_par=background2->GetChisquare()/background2->GetNDF();
  TF1 *fit;
  TF1* fit2;
  Char_t pm=177;
  //Double_t tau=0.5.;
  //Double_t sigma=1.1;
  if(peak2==0){
  //We do both fits
  fit=new TF1("fit1",myfitfunction,x_0,x_f,6);
  fit->SetParName(2,"tau");
  fit->SetParName(3,"sigma");
  fit->SetParName(4,"mu_1");
  fit->SetParName(5,"C_1");
  fit->SetParameter(0,background->GetParameter(0));
  fit->SetParameter(1,background->GetParameter(1));
  //fit->SetParLimits(2,0.5,1.9);
  //fit->SetParLimits(3,1.4,2.5);
  if(Fix_Tau)
    fit->FixParameter(2,tau);
  else
    fit->SetParameter(2,tau);
  if(Fix_Sigma)
    fit->FixParameter(3,sigma);
  else
    fit->SetParameter(3,sigma);
  fit->SetParameter(4,peak1);
  fit->SetParameter(5,Norm1);
  sp->Fit(fit,"REML+");
  cout<<"Chi2/NDF: "<<fit->GetChisquare()/fit->GetNDF()<<endl;
  cout<<"Probability: "<<fit->GetProb()<<endl;
  reducedChiSq_lin=fit->GetChisquare()/fit->GetNDF();
  fit2=new TF1("fit1",myfitfunction2,x_0,x_f,7);
  fit2->SetParName(3,"tau");
  fit2->SetParName(4,"sigma");
  fit2->SetParName(5,"mu_1");
  fit2->SetParName(6,"C_1");
  fit2->SetParameter(0,background2->GetParameter(0));
  fit2->SetParameter(1,background2->GetParameter(1));
  fit2->SetParameter(2,background2->GetParameter(2));
  //fit2->SetParLimits(3,0.5,1.9);
  //fit2->SetParLimits(4,1.4,2.5);
  if(Fix_Tau)
    fit2->FixParameter(3,tau);
  else
   fit2->SetParameter(3,tau);
  if(Fix_Sigma)
    fit2->FixParameter(4,sigma);
  else
    fit2->SetParameter(4,sigma);
  fit2->SetParameter(5,peak1);
  fit2->SetParameter(6,Norm1);
  sp->Fit(fit2,"REML+");
  cout<<"Chi2/NDF: "<<fit2->GetChisquare()/fit2->GetNDF()<<endl;
  cout<<"Probability: "<<fit2->GetProb()<<endl;
  reducedChiSq_par=fit2->GetChisquare()/fit2->GetNDF();
  if(write){
  *out<<"Linear Background"<<endl;
  for(Int_t k=0;k<fit->GetNpar();k++){
    *out<<fit->GetParName(k)<<"\t"<<fit->GetParameter(k)<<" "<<pm<<" "<<fit->GetParError(k)<<"\t"<<fit->GetParError(k)*sqrt(reducedChiSq_lin)<<endl;
  }
  *out<<"Chi2/NDF: "<<fit->GetChisquare()/fit2->GetNDF()<<endl;
  *out<<"Probability: "<<fit->GetProb()<<endl;
  *out<<"------------------------------------------------------------------------------------"<<endl;
  *out<<"Cuadratic Background"<<endl;
  for(Int_t k=0;k<fit2->GetNpar();k++){
    *out<<fit2->GetParName(k)<<"\t"<<fit2->GetParameter(k)<<" "<<pm<<" "<<fit2->GetParError(k)<<"\t"<<fit2->GetParError(k)*sqrt(reducedChiSq_par)<<endl;
  }
  *out<<"Chi2/NDF: "<<fit2->GetChisquare()/fit2->GetNDF()<<endl;
  *out<<"Probability: "<<fit2->GetProb()<<endl;
  *out<<"====================================================================================="<<endl;
  }
  }
  else if(peak3==0){
  fit=new TF1("fit1",myfitfunction2peaks,x_0,x_f,8);
  fit->SetParName(2,"tau");
  fit->SetParName(3,"sigma");
  fit->SetParName(4,"mu_1");
  fit->SetParName(5,"C_1");
  fit->SetParName(6,"mu_2");
  fit->SetParName(7,"C_2");
  fit->SetParameter(0,background->GetParameter(0));
  fit->SetParameter(1,background->GetParameter(1));
  //fit->SetParLimits(2,0.5,1.9);
  //fit->SetParLimits(3,1.4,2.5);
  if(Fix_Tau)
    fit->FixParameter(2,tau);
  else
    fit->SetParameter(2,tau);
  if(Fix_Sigma)
    fit->FixParameter(3,sigma);
  else
    fit->SetParameter(3,sigma);
  fit->SetParameter(4,peak1);
  fit->SetParameter(5,Norm1);
  fit->SetParameter(6,peak2);
  fit->SetParameter(7,Norm2);
  sp->Fit(fit,"REML+");
  cout<<"Chi2/NDF: "<<fit->GetChisquare()/fit->GetNDF()<<endl;
  cout<<"Probability: "<<fit->GetProb()<<endl;
  reducedChiSq_lin=fit->GetChisquare()/fit->GetNDF();
  fit2=new TF1("fit1",myfitfunction2peaks2,x_0,x_f,9);
  fit2->SetParName(3,"tau");
  fit2->SetParName(4,"sigma");
  fit2->SetParName(5,"mu_1");
  fit2->SetParName(6,"C_1");
  fit2->SetParName(7,"mu_2");
  fit2->SetParName(8,"C_2");
  fit2->SetParameter(0,background2->GetParameter(0));
  fit2->SetParameter(1,background2->GetParameter(1));
  fit2->SetParameter(2,background2->GetParameter(2));
  //fit2->SetParLimits(3,0.5,1.9);
  //fit2->SetParLimits(4,1.4,2.5);
  if(Fix_Tau)
    fit2->FixParameter(3,tau);
  else
   fit2->SetParameter(3,tau);
  if(Fix_Sigma)
    fit2->FixParameter(4,sigma);
  else
    fit2->SetParameter(4,sigma);
  fit2->SetParameter(5,peak1);
  fit2->SetParameter(6,Norm1);
  fit2->SetParameter(7,peak2);
  fit2->SetParameter(8,Norm2);
  sp->Fit(fit2,"REML+");
  cout<<"Chi2/NDF: "<<fit2->GetChisquare()/fit2->GetNDF()<<endl;
  cout<<"Probability: "<<fit2->GetProb()<<endl;
  reducedChiSq_par=fit2->GetChisquare()/fit2->GetNDF();
  if(write){
  *out<<"Linear Background"<<endl;
  for(Int_t k=0;k<fit->GetNpar();k++){
    *out<<fit->GetParName(k)<<"\t"<<fit->GetParameter(k)<<" "<<pm<<" "<<fit->GetParError(k)<<"\t"<<fit->GetParError(k)*sqrt(reducedChiSq_lin)<<endl;
  }
  *out<<"Chi2/NDF: "<<fit->GetChisquare()/fit->GetNDF()<<endl;
  *out<<"Probability: "<<fit->GetProb()<<endl;
  *out<<"------------------------------------------------------------------------------------"<<endl;
  *out<<"Cuadratic Background"<<endl;
  for(Int_t k=0;k<fit2->GetNpar();k++){
    *out<<fit2->GetParName(k)<<"\t"<<fit2->GetParameter(k)<<" "<<pm<<" "<<fit2->GetParError(k)<<"\t"<<fit2->GetParError(k)*sqrt(reducedChiSq_par)<<endl;
  }
  *out<<"Chi2/NDF: "<<fit2->GetChisquare()/fit2->GetNDF()<<endl;
  *out<<"Probability: "<<fit2->GetProb()<<endl;
  *out<<"====================================================================================="<<endl;
  }
  }
  else{
  fit=new TF1("fit1",myfitfunction3peaks,x_0,x_f,10);
  fit->SetParName(2,"tau");
  fit->SetParName(3,"sigma");
  fit->SetParName(4,"mu_1");
  fit->SetParName(5,"C_1");
  fit->SetParName(6,"mu_2");
  fit->SetParName(7,"C_2");
  fit->SetParName(8,"mu_3");
  fit->SetParName(9,"C_3");
  fit->SetParameter(0,background->GetParameter(0));
  fit->SetParameter(1,background->GetParameter(1));
  //fit->SetParLimits(2,0.5,1.9);
  //fit->SetParLimits(3,1.4,2.5);
  if(Fix_Tau)
    fit->FixParameter(2,tau);
  else
    fit->SetParameter(2,tau);
  if(Fix_Sigma)
    fit->FixParameter(3,sigma);
  else
    fit->SetParameter(3,sigma);
  fit->SetParameter(4,peak1);
  fit->SetParameter(5,Norm1);
  fit->SetParameter(6,peak2);
  fit->SetParameter(7,Norm2);
  fit->SetParameter(8,peak3);
  fit->SetParameter(9,Norm3);
  sp->Fit(fit,"REML+");
  cout<<"Chi2/NDF: "<<fit->GetChisquare()/fit->GetNDF()<<endl;
  cout<<"Probability: "<<fit->GetProb()<<endl;
  reducedChiSq_lin=fit->GetChisquare()/fit->GetNDF();
  fit2=new TF1("fit1",myfitfunction3peaks2,x_0,x_f,11);
  fit2->SetParName(3,"tau");
  fit2->SetParName(4,"sigma");
  fit2->SetParName(5,"mu_1");
  fit2->SetParName(6,"C_1");
  fit2->SetParName(7,"mu_2");
  fit2->SetParName(8,"C_2");
  fit2->SetParName(9,"mu_3");
  fit2->SetParName(10,"C_3");
  fit2->SetParameter(0,background2->GetParameter(0));
  fit2->SetParameter(1,background2->GetParameter(1));
  fit2->SetParameter(2,background2->GetParameter(2));
  //fit2->SetParLimits(3,0.5,1.9);
  //fit2->SetParLimits(4,1.4,2.5);
  if(Fix_Tau)
    fit2->FixParameter(3,tau);
  else
   fit2->SetParameter(3,tau);
  if(Fix_Sigma)
    fit2->FixParameter(4,sigma);
  else
    fit2->SetParameter(4,sigma);
  fit2->SetParameter(5,peak1);
  fit2->SetParameter(6,Norm1);
  fit2->SetParameter(7,peak2);
  fit2->SetParameter(8,Norm2);
  fit2->SetParameter(9,peak3);
  fit2->SetParameter(10,Norm3);
  sp->Fit(fit2,"REML+");
  cout<<"Chi2/NDF: "<<fit2->GetChisquare()/fit2->GetNDF()<<endl;
  cout<<"Probability: "<<fit2->GetProb()<<endl;
  reducedChiSq_par=fit2->GetChisquare()/fit2->GetNDF();
  if(write){
  *out<<"Linear Background"<<endl;
  for(Int_t k=0;k<fit->GetNpar();k++){
    *out<<fit->GetParName(k)<<"\t"<<fit->GetParameter(k)<<" "<<pm<<" "<<fit->GetParError(k)<<"\t"<<fit->GetParError(k)*sqrt(reducedChiSq_lin)<<endl;
  }
  *out<<"Chi2/NDF: "<<fit->GetChisquare()/fit->GetNDF()<<endl;
  *out<<"Probability: "<<fit->GetProb()<<endl;
  *out<<"------------------------------------------------------------------------------------"<<endl;
  *out<<"Cuadratic Background"<<endl;
  for(Int_t k=0;k<fit2->GetNpar();k++){
    *out<<fit2->GetParName(k)<<"\t"<<fit2->GetParameter(k)<<" "<<pm<<" "<<fit2->GetParError(k)<<"\t"<<fit2->GetParError(k)*sqrt(reducedChiSq_par)<<endl;
  }
  *out<<"Chi2/NDF: "<<fit2->GetChisquare()/fit2->GetNDF()<<endl;
  *out<<"Probability: "<<fit2->GetProb()<<endl;
  *out<<"====================================================================================="<<endl;
  }
  }
  
  cout<<"Chi2/NDF: "<<fit->GetChisquare()<<"/"<<fit->GetNDF()<<endl;
  cout<<"Probability: "<<fit->GetProb()<<endl;
  cout<<"Chi2/NDF: "<<fit2->GetChisquare()<<"/"<<fit2->GetNDF()<<endl;
  cout<<"Probability: "<<fit2->GetProb()<<endl;
  if(reducedChiSq_par<reducedChiSq_lin)
    return fit2;
  else
    return fit;
}


TF1* fit_spectrum3(TH1I*sp,Double_t tau=1.3,Double_t sigma=2.0){

  x0=3600;
  xf=3740;
  Bool_t Fix_Tau=kTRUE;
  Bool_t Fix_Sigma=kTRUE;
  Bool_t write=kFALSE;

  Double_t x_0=3580;
  Double_t x_f=3760;

  Double_t peak1=3627;
  Double_t Norm1=239;
  Double_t Stretch1=2;

  Double_t peak2=3689;
  Double_t Norm2=192;

  Double_t peak3=3726;
  Double_t Norm3=211;
  Double_t Stretch3=2;

  ofstream * out=new ofstream("Fit_parameters_Apr92014.txt",ios::app);
  TF1 *background=new TF1("background",background_rej,x_0,x_f,2);
  TF1 *background2=new TF1("background2",background_rej2,x_0,x_f,3);
  background->SetLineColor(3);
  background2->SetLineColor(4);
  sp->Fit(background,"R");
  cout<<"Chi2/NDF: "<<background->GetChisquare()/background->GetNDF()<<endl;
  Double_t reducedChiSq_lin=background->GetChisquare()/background->GetNDF();
  cout<<"Probability: "<<background->GetProb()<<endl;
  sp->Fit(background2,"R+");
  cout<<"Chi2/NDF: "<<background2->GetChisquare()/background2->GetNDF()<<endl;
  Double_t reducedChiSq_par=background2->GetChisquare()/background2->GetNDF();
  TF1 *fit;
  TF1* fit2;
  Char_t pm=177;

  fit=new TF1("fit1",myfitfunctionDoppler_lin,x_0,x_f,12);
  fit->SetParName(2,"tau");
  fit->SetParName(3,"sigma");
  fit->SetParName(4,"mu_1");
  fit->SetParName(5,"C_1");
  fit->SetParName(6,"Stretch_1");
  fit->SetParName(7,"mu_2");
  fit->SetParName(8,"C_2");
  fit->SetParName(9,"mu_3");
  fit->SetParName(10,"C_3");
  fit->SetParName(11,"Strecth_3");
  fit->SetParameter(0,background->GetParameter(0));
  fit->SetParameter(1,background->GetParameter(1));
  if(Fix_Tau)
    fit->FixParameter(2,tau);
  else
    fit->SetParameter(2,tau);
  if(Fix_Sigma)
    fit->FixParameter(3,sigma);
  else
    fit->SetParameter(3,sigma);
  fit->SetParameter(4,peak1);
  fit->SetParameter(5,Norm1);
  fit->SetParameter(6,Stretch1);
  fit->SetParameter(7,peak2);
  fit->SetParameter(8,Norm2);
  fit->SetParameter(9,peak3);
  fit->SetParameter(10,Norm3);
  fit->SetParameter(11,Stretch3);
  sp->Fit(fit,"REML+");
  cout<<"Chi2/NDF: "<<fit->GetChisquare()/fit->GetNDF()<<endl;
  cout<<"Probability: "<<fit->GetProb()<<endl;
  reducedChiSq_lin=fit->GetChisquare()/fit->GetNDF();

  fit2=new TF1("fit2",myfitfunctionDoppler_par,x_0,x_f,13);
  fit2->SetParName(3,"tau");
  fit2->SetParName(4,"sigma");
  fit2->SetParName(5,"mu_1");
  fit2->SetParName(6,"C_1");
  fit2->SetParName(7,"Stretch_1");
  fit2->SetParName(8,"mu_2");
  fit2->SetParName(9,"C_2");
  fit2->SetParName(10,"mu_3");
  fit2->SetParName(11,"C_3");
  fit2->SetParName(12,"Strecth_3");
  fit2->SetParameter(0,background2->GetParameter(0));
  fit2->SetParameter(1,background2->GetParameter(1));
  fit2->SetParameter(2,background2->GetParameter(2));
  if(Fix_Tau)
    fit2->FixParameter(3,tau);
  else
    fit2->SetParameter(3,tau);
  if(Fix_Sigma)
    fit2->FixParameter(4,sigma);
  else
    fit2->SetParameter(4,sigma);
  fit2->SetParameter(5,peak1);
  fit2->SetParameter(6,Norm1);
  fit2->SetParameter(7,Stretch1);
  fit2->SetParameter(8,peak2);
  fit2->SetParameter(9,Norm2);
  fit2->SetParameter(10,peak3);
  fit2->SetParameter(11,Norm3);
  fit2->SetParameter(12,Stretch3);
  sp->Fit(fit2,"REML+");
  cout<<"Chi2/NDF: "<<fit2->GetChisquare()/fit2->GetNDF()<<endl;
  cout<<"Probability: "<<fit2->GetProb()<<endl;
  reducedChiSq_par=fit2->GetChisquare()/fit2->GetNDF();
  if(write){
  *out<<"Linear Background"<<endl;
  for(Int_t k=0;k<fit->GetNpar();k++){
    *out<<fit->GetParName(k)<<"\t"<<fit->GetParameter(k)<<" "<<pm<<" "<<fit->GetParError(k)<<"\t"<<fit->GetParError(k)*sqrt(reducedChiSq_lin)<<endl;
  }
  *out<<"Chi2/NDF: "<<fit->GetChisquare()/fit->GetNDF()<<endl;
  *out<<"Probability: "<<fit->GetProb()<<endl;
  *out<<"------------------------------------------------------------------------------------"<<endl;
  *out<<"Cuadratic Background"<<endl;
  for(Int_t k=0;k<fit2->GetNpar();k++){
    *out<<fit2->GetParName(k)<<"\t"<<fit2->GetParameter(k)<<" "<<pm<<" "<<fit2->GetParError(k)<<"\t"<<fit2->GetParError(k)*sqrt(reducedChiSq_par)<<endl;
  }
  *out<<"Chi2/NDF: "<<fit2->GetChisquare()/fit2->GetNDF()<<endl;
  *out<<"Probability: "<<fit2->GetProb()<<endl;
  *out<<"====================================================================================="<<endl;
  }
  
  
  cout<<"Chi2/NDF: "<<fit->GetChisquare()<<"/"<<fit->GetNDF()<<endl;
  cout<<"Probability: "<<fit->GetProb()<<endl;
  cout<<"Chi2/NDF: "<<fit2->GetChisquare()<<"/"<<fit2->GetNDF()<<endl;
  cout<<"Probability: "<<fit2->GetProb()<<endl;
  if(reducedChiSq_par<reducedChiSq_lin)
    return fit2;
  else
    return fit;
}


TF1 *fit_spectrum4(Bool_t write,TH1F* sp,Double_t x_0,Double_t x_f,Double_t peak_0,Double_t peak_f,Double_t tau,Double_t sigma,Double_t peak1, Double_t Norm1, Double_t peak2=0,Double_t Norm2=0,Double_t peak3=0,Double_t Norm3=0){

  //First I fit background
  x0=peak_0;
  xf=peak_f;
  //Bool_t Fix_Tau=kTRUE;
  //Bool_t Fix_Sigma=kTRUE;
  Bool_t Fix_Tau=kFALSE;
  Bool_t Fix_Sigma=kFALSE;
  //Bool_t write=kFALSE;
  //if(write)
    ofstream * out=new ofstream("Fit_parameters_56Co29July.txt",ios::app);
  TF1 *background=new TF1("background",background_rej,x_0,x_f,2);
  TF1 *background2=new TF1("background2",background_rej2,x_0,x_f,3);
  background->SetLineColor(3);
  background2->SetLineColor(4);
  sp->Fit(background,"R");
  cout<<"Chi2/NDF: "<<background->GetChisquare()/background->GetNDF()<<endl;
  Double_t reducedChiSq_lin=background->GetChisquare()/background->GetNDF();
  cout<<"Probability: "<<background->GetProb()<<endl;
  sp->Fit(background2,"R+");
  cout<<"Chi2/NDF: "<<background2->GetChisquare()/background2->GetNDF()<<endl;
  Double_t reducedChiSq_par=background2->GetChisquare()/background2->GetNDF();
  TF1 *fit;
  TF1* fit2;
  Char_t pm=177;
  //Double_t tau=0.5.;
  //Double_t sigma=1.1;
  if(peak2==0){
  //We do both fits
  fit=new TF1("fit1",myfitfunction,x_0,x_f,6);
  fit->SetParName(2,"tau");
  fit->SetParName(3,"sigma");
  fit->SetParName(4,"mu_1");
  fit->SetParName(5,"C_1");
  fit->SetParameter(0,background->GetParameter(0));
  fit->SetParameter(1,background->GetParameter(1));
  //fit->SetParLimits(2,0.5,1.9);
  //fit->SetParLimits(3,1.4,2.5);
  if(Fix_Tau)
    fit->FixParameter(2,tau);
  else
    fit->SetParameter(2,tau);
  if(Fix_Sigma)
    fit->FixParameter(3,sigma);
  else
    fit->SetParameter(3,sigma);
  fit->SetParameter(4,peak1);
  fit->SetParameter(5,Norm1);
  sp->Fit(fit,"REML+");
  cout<<"Chi2/NDF: "<<fit->GetChisquare()/fit->GetNDF()<<endl;
  cout<<"Probability: "<<fit->GetProb()<<endl;
  reducedChiSq_lin=fit->GetChisquare()/fit->GetNDF();
  fit2=new TF1("fit1",myfitfunction2,x_0,x_f,7);
  fit2->SetParName(3,"tau");
  fit2->SetParName(4,"sigma");
  fit2->SetParName(5,"mu_1");
  fit2->SetParName(6,"C_1");
  fit2->SetParameter(0,background2->GetParameter(0));
  fit2->SetParameter(1,background2->GetParameter(1));
  fit2->SetParameter(2,background2->GetParameter(2));
  //fit2->SetParLimits(3,0.5,1.9);
  //fit2->SetParLimits(4,1.4,2.5);
  if(Fix_Tau)
    fit2->FixParameter(3,tau);
  else
   fit2->SetParameter(3,tau);
  if(Fix_Sigma)
    fit2->FixParameter(4,sigma);
  else
    fit2->SetParameter(4,sigma);
  fit2->SetParameter(5,peak1);
  fit2->SetParameter(6,Norm1);
  sp->Fit(fit2,"REML+");
  cout<<"Chi2/NDF: "<<fit2->GetChisquare()/fit2->GetNDF()<<endl;
  cout<<"Probability: "<<fit2->GetProb()<<endl;
  reducedChiSq_par=fit2->GetChisquare()/fit2->GetNDF();
  if(write){
  *out<<"Linear Background"<<endl;
  for(Int_t k=0;k<fit->GetNpar();k++){
    *out<<fit->GetParName(k)<<"\t"<<fit->GetParameter(k)<<" "<<pm<<" "<<fit->GetParError(k)<<"\t"<<fit->GetParError(k)*sqrt(reducedChiSq_lin)<<endl;
  }
  *out<<"Chi2/NDF: "<<fit->GetChisquare()/fit2->GetNDF()<<endl;
  *out<<"Probability: "<<fit->GetProb()<<endl;
  *out<<"------------------------------------------------------------------------------------"<<endl;
  *out<<"Cuadratic Background"<<endl;
  for(Int_t k=0;k<fit2->GetNpar();k++){
    *out<<fit2->GetParName(k)<<"\t"<<fit2->GetParameter(k)<<" "<<pm<<" "<<fit2->GetParError(k)<<"\t"<<fit2->GetParError(k)*sqrt(reducedChiSq_par)<<endl;
  }
  *out<<"Chi2/NDF: "<<fit2->GetChisquare()/fit2->GetNDF()<<endl;
  *out<<"Probability: "<<fit2->GetProb()<<endl;
  *out<<"====================================================================================="<<endl;
  }
  }
  else if(peak3==0){
  fit=new TF1("fit1",myfitfunction2peaks,x_0,x_f,8);
  fit->SetParName(2,"tau");
  fit->SetParName(3,"sigma");
  fit->SetParName(4,"mu_1");
  fit->SetParName(5,"C_1");
  fit->SetParName(6,"mu_2");
  fit->SetParName(7,"C_2");
  fit->SetParameter(0,background->GetParameter(0));
  fit->SetParameter(1,background->GetParameter(1));
  //fit->SetParLimits(2,0.5,1.9);
  //fit->SetParLimits(3,1.4,2.5);
  if(Fix_Tau)
    fit->FixParameter(2,tau);
  else
    fit->SetParameter(2,tau);
  if(Fix_Sigma)
    fit->FixParameter(3,sigma);
  else
    fit->SetParameter(3,sigma);
  fit->SetParameter(4,peak1);
  fit->SetParameter(5,Norm1);
  fit->SetParameter(6,peak2);
  fit->SetParameter(7,Norm2);
  sp->Fit(fit,"REML+");
  cout<<"Chi2/NDF: "<<fit->GetChisquare()/fit->GetNDF()<<endl;
  cout<<"Probability: "<<fit->GetProb()<<endl;
  reducedChiSq_lin=fit->GetChisquare()/fit->GetNDF();
  fit2=new TF1("fit1",myfitfunction2peaks2,x_0,x_f,9);
  fit2->SetParName(3,"tau");
  fit2->SetParName(4,"sigma");
  fit2->SetParName(5,"mu_1");
  fit2->SetParName(6,"C_1");
  fit2->SetParName(7,"mu_2");
  fit2->SetParName(8,"C_2");
  fit2->SetParameter(0,background2->GetParameter(0));
  fit2->SetParameter(1,background2->GetParameter(1));
  fit2->SetParameter(2,background2->GetParameter(2));
  //fit2->SetParLimits(3,0.5,1.9);
  //fit2->SetParLimits(4,1.4,2.5);
  if(Fix_Tau)
    fit2->FixParameter(3,tau);
  else
   fit2->SetParameter(3,tau);
  if(Fix_Sigma)
    fit2->FixParameter(4,sigma);
  else
    fit2->SetParameter(4,sigma);
  fit2->SetParameter(5,peak1);
  fit2->SetParameter(6,Norm1);
  fit2->SetParameter(7,peak2);
  fit2->SetParameter(8,Norm2);
  sp->Fit(fit2,"REML+");
  cout<<"Chi2/NDF: "<<fit2->GetChisquare()/fit2->GetNDF()<<endl;
  cout<<"Probability: "<<fit2->GetProb()<<endl;
  reducedChiSq_par=fit2->GetChisquare()/fit2->GetNDF();
  if(write){
  *out<<"Linear Background"<<endl;
  for(Int_t k=0;k<fit->GetNpar();k++){
    *out<<fit->GetParName(k)<<"\t"<<fit->GetParameter(k)<<" "<<pm<<" "<<fit->GetParError(k)<<"\t"<<fit->GetParError(k)*sqrt(reducedChiSq_lin)<<endl;
  }
  *out<<"Chi2/NDF: "<<fit->GetChisquare()/fit->GetNDF()<<endl;
  *out<<"Probability: "<<fit->GetProb()<<endl;
  *out<<"------------------------------------------------------------------------------------"<<endl;
  *out<<"Cuadratic Background"<<endl;
  for(Int_t k=0;k<fit2->GetNpar();k++){
    *out<<fit2->GetParName(k)<<"\t"<<fit2->GetParameter(k)<<" "<<pm<<" "<<fit2->GetParError(k)<<"\t"<<fit2->GetParError(k)*sqrt(reducedChiSq_par)<<endl;
  }
  *out<<"Chi2/NDF: "<<fit2->GetChisquare()/fit2->GetNDF()<<endl;
  *out<<"Probability: "<<fit2->GetProb()<<endl;
  *out<<"====================================================================================="<<endl;
  }
  }
  else{
  fit=new TF1("fit1",myfitfunction3peaks,x_0,x_f,10);
  fit->SetParName(2,"tau");
  fit->SetParName(3,"sigma");
  fit->SetParName(4,"mu_1");
  fit->SetParName(5,"C_1");
  fit->SetParName(6,"mu_2");
  fit->SetParName(7,"C_2");
  fit->SetParName(8,"mu_3");
  fit->SetParName(9,"C_3");
  fit->SetParameter(0,background->GetParameter(0));
  fit->SetParameter(1,background->GetParameter(1));
  //fit->SetParLimits(2,0.5,1.9);
  //fit->SetParLimits(3,1.4,2.5);
  if(Fix_Tau)
    fit->FixParameter(2,tau);
  else
    fit->SetParameter(2,tau);
  if(Fix_Sigma)
    fit->FixParameter(3,sigma);
  else
    fit->SetParameter(3,sigma);
  fit->SetParameter(4,peak1);
  fit->SetParameter(5,Norm1);
  fit->SetParameter(6,peak2);
  fit->SetParameter(7,Norm2);
  fit->SetParameter(8,peak3);
  fit->SetParameter(9,Norm3);
  sp->Fit(fit,"REML+");
  cout<<"Chi2/NDF: "<<fit->GetChisquare()/fit->GetNDF()<<endl;
  cout<<"Probability: "<<fit->GetProb()<<endl;
  reducedChiSq_lin=fit->GetChisquare()/fit->GetNDF();
  fit2=new TF1("fit1",myfitfunction3peaks2,x_0,x_f,11);
  fit2->SetParName(3,"tau");
  fit2->SetParName(4,"sigma");
  fit2->SetParName(5,"mu_1");
  fit2->SetParName(6,"C_1");
  fit2->SetParName(7,"mu_2");
  fit2->SetParName(8,"C_2");
  fit2->SetParName(9,"mu_3");
  fit2->SetParName(10,"C_3");
  fit2->SetParameter(0,background2->GetParameter(0));
  fit2->SetParameter(1,background2->GetParameter(1));
  fit2->SetParameter(2,background2->GetParameter(2));
  //fit2->SetParLimits(3,0.5,1.9);
  //fit2->SetParLimits(4,1.4,2.5);
  if(Fix_Tau)
    fit2->FixParameter(3,tau);
  else
   fit2->SetParameter(3,tau);
  if(Fix_Sigma)
    fit2->FixParameter(4,sigma);
  else
    fit2->SetParameter(4,sigma);
  fit2->SetParameter(5,peak1);
  fit2->SetParameter(6,Norm1);
  fit2->SetParameter(7,peak2);
  fit2->SetParameter(8,Norm2);
  fit2->SetParameter(9,peak3);
  fit2->SetParameter(10,Norm3);
  sp->Fit(fit2,"REML+");
  cout<<"Chi2/NDF: "<<fit2->GetChisquare()/fit2->GetNDF()<<endl;
  cout<<"Probability: "<<fit2->GetProb()<<endl;
  reducedChiSq_par=fit2->GetChisquare()/fit2->GetNDF();
  if(write){
  *out<<"Linear Background"<<endl;
  for(Int_t k=0;k<fit->GetNpar();k++){
    *out<<fit->GetParName(k)<<"\t"<<fit->GetParameter(k)<<" "<<pm<<" "<<fit->GetParError(k)<<"\t"<<fit->GetParError(k)*sqrt(reducedChiSq_lin)<<endl;
  }
  *out<<"Chi2/NDF: "<<fit->GetChisquare()/fit->GetNDF()<<endl;
  *out<<"Probability: "<<fit->GetProb()<<endl;
  *out<<"------------------------------------------------------------------------------------"<<endl;
  *out<<"Cuadratic Background"<<endl;
  for(Int_t k=0;k<fit2->GetNpar();k++){
    *out<<fit2->GetParName(k)<<"\t"<<fit2->GetParameter(k)<<" "<<pm<<" "<<fit2->GetParError(k)<<"\t"<<fit2->GetParError(k)*sqrt(reducedChiSq_par)<<endl;
  }
  *out<<"Chi2/NDF: "<<fit2->GetChisquare()/fit2->GetNDF()<<endl;
  *out<<"Probability: "<<fit2->GetProb()<<endl;
  *out<<"====================================================================================="<<endl;
  }
  }
  
  cout<<"Chi2/NDF: "<<fit->GetChisquare()<<"/"<<fit->GetNDF()<<endl;
  cout<<"Probability: "<<fit->GetProb()<<endl;
  cout<<"Chi2/NDF: "<<fit2->GetChisquare()<<"/"<<fit2->GetNDF()<<endl;
  cout<<"Probability: "<<fit2->GetProb()<<endl;
  if(reducedChiSq_par<reducedChiSq_lin)
    return fit2;
  else
    return fit;
}

