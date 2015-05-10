
#include <iostream>
#include <TApplication.h>
#include "TROOT.h"
#include <cstdlib>
#include <iomanip>
#include "readfile.h"

using namespace std;

int main(int argc,char **argv){
  
  Char_t *input_file_name;
  Char_t *output_file_name;
  Int_t numberOfEvtFiles;
  
  if(argc==1){
    cout<<"Usage: "<<argv[0]<<" <run_name> <# .evt files> <outputfile>"<<endl; 
    return 1;
  }
  else if(argc==2){
    input_file_name=argv[1];
    numberOfEvtFiles=1;
    sprintf(output_file_name,"outputFile.root");
  }
  else if(argc==3){
    input_file_name=argv[1];
    numberOfEvtFiles=atoi(argv[2]);
    sprintf(output_file_name,"outputFile.root");
  }
  else{
    input_file_name=argv[1];
    numberOfEvtFiles=atoi(argv[2]);
    output_file_name=argv[3];
  }
  //TApplication *theApp=new TApplication("cona",&argc,argv);
  cout<<input_file_name<<endl;
  readfile_fun(input_file_name,numberOfEvtFiles,output_file_name);
  //theApp->Run();
  return 0;
}
