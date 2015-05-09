void DumpHisto2ASCII(TH1 *hist){

  Char_t *histoname=hist->GetName();
  Char_t filename[256];
  sprintf(filename,"%s.txt",histoname);
  ofstream *out=new ofstream(filename);

  cout<<"BinNumber\t BinContent"<<endl;
  *out<<hist->GetTitle()<<endl;
  *out<<"BinNumber\t BinContent"<<endl;

  Int_t nBins=hist->GetNbinsX();

  for(Int_t j=1;j<=nBins;j++){
   
    cout<<j<<"\t"<<hist->GetBinContent(j)<<endl;;
    *out<<j<<"\t"<<hist->GetBinContent(j)<<endl;;
  }
  
  cout<<"Done!"<<endl;

}
