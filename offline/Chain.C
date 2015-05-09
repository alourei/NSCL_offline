TChain *Chain(Int_t *nfiles){

  TChain *ch=new TChain("T");
  Char_t filename[256];
  while(*nfiles!=0){
    sprintf(filename,"/events/e14066/rootdata/sorted/run%d_sorted.root",*nfiles);
    cout<<filename<<endl;
    ch->Add(filename);
    nfiles++;
  }
  return ch;
}
