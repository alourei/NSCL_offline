
void PID_analysis(TH2F *hist,Double_t mu_x,Double_t sigma_x,Double_t mu_y,Double_t sigma_y,Char_t *name,Int_t run,Bool_t implant=kTRUE){

  Char_t filename[256];

  if(implant)
    sprintf(filename,"Counts_%s_implant_4Aug.dat",name);
  else
    sprintf(filename,"Counts_%s_total_4Aug.dat",name);
  ofstream *out=new ofstream(filename,ios::app);
  //ofstream *out2=new ofstream("Counts_26P.dat",ios::app);

  TCutG *cut=new TCutG("1sigma",51);
  TCutG *cut2=new TCutG("2sigma",51);
  TCutG *cut3=new TCutG("3sigma",51);

  cut->SetLineWidth(2);
  cut2->SetLineWidth(2);
  cut3->SetLineWidth(2);
  cut2->SetLineColor(2);
  cut3->SetLineColor(6);

  for(Int_t k=0;k<51;k++){

    Double_t X=mu_x+sigma_x*cos(2*k*TMath::Pi()/50);
    Double_t Y=mu_y+sigma_y*sin(2*k*TMath::Pi()/50);
    cut->SetPoint(k,X,Y);
    X=mu_x+2*sigma_x*cos(2*k*TMath::Pi()/50);
    Y=mu_y+2*sigma_y*sin(2*k*TMath::Pi()/50);
    cut2->SetPoint(k,X,Y);
    X=mu_x+3*sigma_x*cos(2*k*TMath::Pi()/50);
    Y=mu_y+3*sigma_y*sin(2*k*TMath::Pi()/50);
    cut3->SetPoint(k,X,Y);
  }
  //hist->Draw("colz"); 
  cut->Draw("LP");
  cut2->Draw("LP");
  cut3->Draw("LP");

  cout<<cut->GetName()<<"\t"<<cut->IntegralHist(hist)<<"\t"<<Int_t(sqrt(cut->IntegralHist(hist)))<<endl;
  cout<<cut2->GetName()<<"\t"<<cut2->IntegralHist(hist)<<"\t"<<Int_t(sqrt(cut2->IntegralHist(hist)))<<endl;
  cout<<cut3->GetName()<<"\t"<<cut3->IntegralHist(hist)<<"\t"<<Int_t(sqrt(cut3->IntegralHist(hist)))<<endl;
 
  
  *out<<run<<"\t"<<cut->GetName()<<"\t"<<cut->IntegralHist(hist)<<"\t"<<sqrt(cut->IntegralHist(hist))<<endl;
  *out<<run<<"\t"<<cut2->GetName()<<"\t"<<cut2->IntegralHist(hist)<<"\t"<<sqrt(cut2->IntegralHist(hist))<<endl;
  *out<<run<<"\t"<<cut3->GetName()<<"\t"<<cut3->IntegralHist(hist)<<"\t"<<sqrt(cut3->IntegralHist(hist))<<endl;
  *out<<endl;
}


void DrawHistos(TTree *T,Int_t run){

  TCanvas *c=new TCanvas("c1","Cona",1650,500);
  c->Divide(3,1);
  c->cd(1);

  Double_t mu_x;
  Double_t mu_y;
  
  Double_t sigma_x;
  Double_t sigma_y;
  
  Double_t mu_x2;
  Double_t mu_y2;
  
  Double_t sigma_x2;
  Double_t sigma_y2;
  
  Double_t mu_x3;
  Double_t sigma_x3;

  Double_t mu_y3;
  Double_t sigma_y3;

  Double_t mu_x4;
  Double_t sigma_x4;

  Double_t mu_y4;
  Double_t sigma_y4;

  //if((run<37||run>=45)){
  if(run>0&&run<37){


    mu_x=1.09814e4;
    mu_y=1.17761e4;
  
    sigma_x=3.58162e2;
    sigma_y=3.48345e2;
  
    mu_x2=8.89660e+03 ;
    mu_y2= 8.94606e+03 ;
  
    sigma_x2= 3.95809e+02;
    sigma_y2= 2.28936e+02 ;




    mu_x3= 1.17658e+04;
    sigma_x3=  3.14530e+02;

    mu_y3= 1.73811e+04 ;
    sigma_y3=  3.98281e+02;

    mu_x4=8.96145e+03 ;
    sigma_x4=2.46508e+02 ;

    mu_y4= 1.30124e+04 ;
    sigma_y4= 3.01349e+02;
  }

  else if(run>=37&&run<45){

    mu_x=1.09814e4;
    mu_y=1.17761e4;
  
    sigma_x=3.58162e2;
    sigma_y=3.48345e2;
  
    mu_x2= 9.55828e+03;
    sigma_x2= 4.21368e+02 ;
    
    mu_y2=9.79860e+03 ;
    sigma_y2= 2.86978e+02;

    mu_x3= 1.17658e+04;
    sigma_x3=  3.14530e+02;

    mu_y3= 1.73811e+04 ;
    sigma_y3=  3.98281e+02;

    mu_x4=9.79860e+03 ;
    sigma_x4= 2.86978e+02;

    mu_y4=1.45032e+04  ;
    sigma_y4=3.33781e+02 ;
  }

  else if(run==0||run>=45){

    mu_x=1.09814e4;
    mu_y=1.17761e4;
  
    sigma_x=3.58162e2;
    sigma_y=3.48345e2;
  
    mu_x2= 8.9828e+03;
    sigma_x2= 4.21368e+02 ;
    
    mu_y2=9.889860e+03 ;
    sigma_y2= 2.86978e+02;

    mu_x3= 1.17658e+04;
    sigma_x3=  3.14530e+02;

    mu_y3= 1.73811e+04 ;
    sigma_y3=  3.98281e+02;

    mu_x4=9.79860e+03 ;
    sigma_x4= 2.86978e+02;

    mu_y4=1.45032e+04  ;
    sigma_y4=3.33781e+02 ;
  }
//   else{
 
//     mu_x=1.09814e4;
//     mu_y=1.17761e4;
  
//     sigma_x=3.58162e2;
//     sigma_y=3.48345e2;

//     mu_x2= 9.55828e+03;
//     sigma_x2= 4.21368e+02 ;
    
//     mu_y2=9.79860e+03 ;
//     sigma_y2= 2.86978e+02;


//     mu_x3= 1.17658e+04;
//     sigma_x3=  3.14530e+02;

//     mu_y3= 1.73811e+04 ;
//     sigma_y3=  3.98281e+02;

//     mu_x4=10.579860e+03 ;
//     sigma_x4= 2.86978e+02;

//     mu_y4=1.5545032e+04  ;
//     sigma_y4=3.33781e+02 ;

// }

  cout<< mu_x4<<" "<<mu_y4<<endl;

  TCutG *cut3=new TCutG("cut3",51);
  TCutG *cut4=new TCutG("cut4",51);
  cut3->SetVarX("thePID.xfptof");
  cut3->SetVarY("thePID.de1");
  cut4->SetVarX("thePID.xfptof");
  cut4->SetVarY("thePID.de1");
  
  TCutG *cut5=new TCutG("z15",51);
  cut5->SetVarY("thePID.de2");
  cut5->SetVarX("thePID.de1");

  TCutG *cut6=new TCutG("z13",51);
  cut6->SetVarY("thePID.de2");
  cut6->SetVarX("thePID.de1");

  for(Int_t k=0;k<51;k++){
    
    Double_t X=mu_x+3*sigma_x*cos(2*k*TMath::Pi()/50);
    Double_t Y=mu_y+3*sigma_y*sin(2*k*TMath::Pi()/50);
    cut3->SetPoint(k,X,Y);
    X=mu_x2+3*sigma_x2*cos(2*k*TMath::Pi()/50);
    Y=mu_y2+3*sigma_y2*sin(2*k*TMath::Pi()/50);
    cut4->SetPoint(k,X,Y);
    X=mu_x3+3*sigma_x3*cos(2*k*TMath::Pi()/50);
    Y=mu_y3+3*sigma_y3*sin(2*k*TMath::Pi()/50);
    cut5->SetPoint(k,X,Y);
    X=mu_x4+3*sigma_x4*cos(2*k*TMath::Pi()/50);
    Y=mu_y4+3*sigma_y4*sin(2*k*TMath::Pi()/50);
    cut6->SetPoint(k,X,Y);
  }
 
  cut3->SetLineWidth(2);
  cut4->SetLineWidth(2);
  cut5->SetLineWidth(2);
  cut6->SetLineWidth(2);

  TH2F * his=new TH2F("PID","PID Ungated",1024,4000,15000,1024,1000,20000);
  TH2F * his2=new TH2F("PID_g","PID Gated on GeDSSD",1024,4000,15000,1024,1000,20000);

  //Int_t nimplants=T->Draw("thePID.de1:thePID.xfptof>>PID_g","!(z13||z15)&&thePID.de2>0&&thefrontGeDSSD.Lohit==1&&thebackGeDSSD.Lohit==1","colz");
  Int_t nimplants=T->Draw("thePID.de1:thePID.xfptof>>PID_g","(z13||z15)&&thePID.de2>0&&thefrontGeDSSD.Lohit==1&&thebackGeDSSD.Lohit==1","colz");
  cut3->Draw("same");
  cut4->Draw("same");
  c->cd(2);
  Int_t nparticles=T->Draw("thePID.de1:thePID.xfptof>>PID","(z13||z15)&&thePID.de2>0","colz");
  //Int_t nparticles=T->Draw("thePID.de1:thePID.xfptof>>PID","!(z13||z15)&&thePID.de2>0","colz");
  cut3->Draw("same");
  cut4->Draw("same");
  
  c->cd(3);

  //T->Draw("thePID.xfptof>>h2(250,4000,15000)","thefrontGeDSSD.Lohit==1&&thebackGeDSSD.Lohit==1","");
  T->Draw("thePID.de2:thePID.de1>>h2(1024,200,25000,1024,200,25000)","thefrontGeDSSD.Lohit==1&&thebackGeDSSD.Lohit==1","colz");
  cut5->Draw("same");
  cut6->Draw("same");
  //T->Draw("thePID.de2:thePID.de1>>h2(1024,200,25000,1024,200,25000)","!(z13||z15)","colz");
  //T->Draw("thePID.de2:thePID.de1>>hg(1024,200,25000,1024,200,25000)","cut4&&thefrontGeDSSD.Lohit==1&&thebackGeDSSD.Lohit==1","same");
  
  //c->cd(1);

  //T->Draw("thePID.de1>>h3(250,200,25000)","thefrontGeDSSD.Lohit==1&&thebackGeDSSD.Lohit==1","");

  c->cd(2);



  //cout<< nparticles<<"\t"<<nimplants<<"\t"<<Float_t(nimplants)/nparticles*100<<endl;


  if(run!=0){
    PID_analysis(his,mu_x,sigma_x,mu_y,sigma_y,"26P",run,0);
    cout<<"----------------------------------------------"<<endl;
    PID_analysis(his,mu_x2,sigma_x2,mu_y2,sigma_y2,"24Al",run,0);
    cout<<"**********************************************"<<endl;
    PID_analysis(his2,mu_x,sigma_x,mu_y,sigma_y,"26P",run);
    cout<<"----------------------------------------------"<<endl;
    PID_analysis(his2,mu_x2,sigma_x2,mu_y2,sigma_y2,"24Al",run);
  }
}

void DrawGeDSSD(TTree *T){

  TCanvas *c=new TCanvas("c1","Cona",1100,500);
  c->Divide(2,2);
  c->cd(1);

  Double_t mu_x=1.09814e4;
  Double_t mu_y=1.17761e4;

  Double_t sigma_x=3.58162e2;
  Double_t sigma_y=3.48345e2;

  Double_t mu_x2=8.89660e+03 ;
  Double_t mu_y2= 8.94606e+03 ;

  Double_t sigma_x2= 3.95809e+02;
  Double_t sigma_y2= 2.28936e+02 ;

  Double_t mu_x3= 1.17658e+04;
  Double_t sigma_x3=  3.14530e+02;

  Double_t mu_y3= 1.73811e+04 ;
  Double_t sigma_y3=  3.98281e+02;

  TCutG *cut3=new TCutG("cut3",51);
  TCutG *cut4=new TCutG("cut4",51);
  TCutG *cut5=new TCutG("z15",51);
  cut3->SetVarX("thePID.xfptof");
  cut3->SetVarY("thePID.de1");
  cut4->SetVarX("thePID.xfptof");
  cut4->SetVarY("thePID.de1");
  cut5->SetVarY("thePID.de2");
  cut5->SetVarX("thePID.de1");

 for(Int_t k=0;k<51;k++){

    Double_t X=mu_x+3*sigma_x*cos(2*k*TMath::Pi()/50);
    Double_t Y=mu_y+3*sigma_y*sin(2*k*TMath::Pi()/50);
    cut3->SetPoint(k,X,Y);
    X=mu_x2+3*sigma_x2*cos(2*k*TMath::Pi()/50);
    Y=mu_y2+3*sigma_y2*sin(2*k*TMath::Pi()/50);
    cut4->SetPoint(k,X,Y);
    X=mu_x3+3*sigma_x3*cos(2*k*TMath::Pi()/50);
    Y=mu_y3+3*sigma_y3*sin(2*k*TMath::Pi()/50);
    cut5->SetPoint(k,X,Y);
 }

 //Int_t nimplants=T->Draw("thePID.de1:thePID.xfptof>>h(1024,4000,15000,1024,1000,20000)","cut3&&(thefrontGeDSSD.Lohit==1||thebackGeDSSD.Lohit==1)","colz");

 //c->cd(2);
 //Int_t nparticles=T->Draw("thePID.de1:thePID.xfptof>>he(1024,4000,15000,1024,1000,20000)","cut3&&thePID.de2>0","colz");

 //cut3->Draw();
 //cut4->Draw();
 //c->cd(2);

 TH2F *h_26P=new TH2F("h_26P","Implant Distribution ^{26}P",16,0,16,16,0,16);
 TF2 *gaus_2D=new TF2("gaus_2D",g2,0,16,0,16,5);
 T->Draw("thefrontGeDSSD.implant_max_channel:thebackGeDSSD.implant_max_channel>>h_26P","cut3&&thefrontGeDSSD.Lohit==1&&thebackGeDSSD.Lohit==1","zcol");
 
 c->cd(2);

 T->Draw("thefrontGeDSSD.implant_max_channel:thebackGeDSSD.implant_max_channel>>h_rest(16,0,16,16,0,16)","!cut3&&thefrontGeDSSD.Lohit==1&&thebackGeDSSD.Lohit==1","zcol");

 c->cd(3);
 
 TH1F *h_front=new TH1F("h_front","Implant Distribution front ^{26}P",16,0,16);
 TF1 *gaus_front=new TF1("gaus_front","gaus",0,16);
 T->Draw("thefrontGeDSSD.implant_max_channel>>h_front","cut3&&thefrontGeDSSD.Lohit==1&&thebackGeDSSD.Lohit==1","");
 h_front->Fit(gaus_front,"REM");
 Double_t *params_front=gaus_front->GetParameters();
 c->cd(4);
 TH1F *h_back=new TH1F("h_back","Implant Distribution back ^{26}P",16,0,16);
 TF1 *gaus_back=new TF1("gaus_back","gaus",0,16);
 T->Draw("thebackGeDSSD.implant_max_channel>>h_back","cut3&&thefrontGeDSSD.Lohit==1&&thebackGeDSSD.Lohit==1","");
 h_back->Fit(gaus_back,"REM");
 Double_t *params_back=gaus_back->GetParameters();

 c->cd(2);
 gaus_2D->SetParameter(0,params_front[0]*params_back[0]);
 gaus_2D->SetParameter(3,params_front[1]);
 gaus_2D->SetParameter(4,params_front[2]);
 gaus_2D->SetParameter(1,params_back[1]);
 gaus_2D->SetParameter(2,params_back[2]);
 
 h_26P->Draw("");
 h_26P->Fit(gaus_2D,"REM");
 //gaus_2D->Draw("same surf");

 // cout<< nparticles<<"\t"<<nimplants<<"\t"<<Float_t(nimplants)/nparticles*100<<endl;
}



Double_t g2(Double_t *x, Double_t *par) {
   Double_t r1 = Double_t((x[0]-par[1])/par[2]);
   Double_t r2 = Double_t((x[1]-par[3])/par[4]);
   return par[0]*TMath::Exp(-0.5*(r1*r1+r2*r2));
}   



void doCuts(){
  Double_t mu_x=1.09814e4;
  Double_t mu_y=1.17761e4;

  Double_t sigma_x=3.58162e2;
  Double_t sigma_y=3.48345e2;

  Double_t mu_x2=8.89660e+03 ;
  Double_t mu_y2= 8.94606e+03 ;

  Double_t sigma_x2= 3.95809e+02;
  Double_t sigma_y2= 2.28936e+02 ;

  Double_t mu_y3= 1.17658e+04;
  Double_t sigma_y3=  3.14530e+02;

  Double_t mu_x3= 1.73811e+04 ;
  Double_t sigma_x3=  3.98281e+02;


  TCutG *cut3=new TCutG("cut3",51);
  TCutG *cut4=new TCutG("cut4",51);
  TCutG *cut5=new TCutG("z15",51);
  cut3->SetVarX("thePID.xfptof");
  cut3->SetVarY("thePID.de1");
  cut4->SetVarX("thePID.xfptof");
  cut4->SetVarY("thePID.de1");
  cut5->SetVarY("thePID.de1");
  cut5->SetVarX("thePID.de2");

 for(Int_t k=0;k<51;k++){

    Double_t X=mu_x+3*sigma_x*cos(2*k*TMath::Pi()/50);
    Double_t Y=mu_y+3*sigma_y*sin(2*k*TMath::Pi()/50);
    cut3->SetPoint(k,X,Y);
    X=mu_x2+3*sigma_x2*cos(2*k*TMath::Pi()/50);
    Y=mu_y2+3*sigma_y2*sin(2*k*TMath::Pi()/50);
    cut4->SetPoint(k,X,Y);
    Y=mu_x3+3*sigma_x3*cos(2*k*TMath::Pi()/50);
    X=mu_y3+3*sigma_y3*sin(2*k*TMath::Pi()/50);
    cut5->SetPoint(k,X,Y);
 }

}
