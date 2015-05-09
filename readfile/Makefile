CC=gcc
CXX=g++
CXXLD=g++
CCLD=gcc

ROOTSYS="/mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09"

DDASLIB_DIR="/user/e14066/ddasdumper"

DDASHEADER_DIR="/user/e14066/ddasdumper"


CXXFLAGS=-g -I. -I$(DDASHEADER_DIR) 


LDFLAGS=-L$(DDASLIB_DIR) \
                -L/usr/lib -lpthread -lrt 

ROOTCFLAGS   := $(shell ${ROOTSYS}/bin/root-config --cflags)
ROOTGLIBS    := $(shell ${ROOTSYS}/bin/root-config --glibs)
ROOTLDFLAGS  := $(shell ${ROOTSYS}/bin/root-config --ldflags)

LIBS  = -lm $(ROOTGLIBS) -L$(DAQLIB_DIR) -L$(shell pwd) -lddaschannel

CXXFLAGS+=$(ROOTCFLAGS)

O_FILES  = main_readFile.o readfile.o BetaDecay.o Correlator.o BetaDecayDict.o

readFile:$(O_FILES)

	$(CXXLD) -o readFile $(O_FILES) $(LDFLAGS) $(LIBS) 

clean:
	rm -f *.o readFile* *~

cleandict:
	rm -f *Dict.C

depend:
	makedepend $(CXXFLAGS) *.cpp *.C

BetaDecayDict.C: BetaDecay.h  Correlator.h BetaDecayLinkDef.h
	@echo "Building dictionary..."
	@rootcint -f $@ -c $^


# DO NOT DELETE

AnalysisClass_2.o: AnalysisClass_2.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TROOT.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDirectory.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TNamed.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TObject.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Rtypes.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/RConfig.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/RVersion.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/DllImport.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Rtypeinfo.h
AnalysisClass_2.o: /usr/include/stdio.h /usr/include/features.h
AnalysisClass_2.o: /usr/include/libio.h /usr/include/_G_config.h
AnalysisClass_2.o: /usr/include/wchar.h /usr/include/string.h
AnalysisClass_2.o: /usr/include/xlocale.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/snprintf.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/strlcpy.h
AnalysisClass_2.o: /usr/include/unistd.h /usr/include/getopt.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TGenericClassInfo.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TSchemaHelper.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TStorage.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TVersionCheck.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Riosfwd.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TBuffer.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TString.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TMathBase.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TList.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TSeqCollection.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TCollection.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TIterator.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDatime.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TUUID.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TChain.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TTree.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TBranch.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TObjArray.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttFill.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDataType.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDictionary.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Property.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttLine.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttMarker.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArrayD.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArray.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArrayI.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TClass.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TObjString.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TVirtualTreePlayer.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TFile.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDirectoryFile.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TMap.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/THashTable.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TUrl.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TH2.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TH1.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAxis.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttAxis.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArrayC.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArrayS.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArrayF.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Foption.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TVectorFfwd.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TVectorDfwd.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TFitResultPtr.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TMatrixFBasefwd.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TMatrixDBasefwd.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TStyle.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttText.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TCanvas.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TPad.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TVirtualPad.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttPad.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TVirtualX.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/GuiTypes.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Buttons.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TQObject.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttCanvas.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TCanvasImp.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TH2I.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TH1F.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TH1I.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TCutG.h
AnalysisClass_2.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TGraph.h
AnalysisClass.o: AnalysisClass.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TROOT.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDirectory.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TNamed.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TObject.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Rtypes.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/RConfig.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/RVersion.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/DllImport.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Rtypeinfo.h
AnalysisClass.o: /usr/include/stdio.h /usr/include/features.h
AnalysisClass.o: /usr/include/libio.h /usr/include/_G_config.h
AnalysisClass.o: /usr/include/wchar.h /usr/include/string.h
AnalysisClass.o: /usr/include/xlocale.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/snprintf.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/strlcpy.h
AnalysisClass.o: /usr/include/unistd.h /usr/include/getopt.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TGenericClassInfo.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TSchemaHelper.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TStorage.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TVersionCheck.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Riosfwd.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TBuffer.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TString.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TMathBase.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TList.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TSeqCollection.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TCollection.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TIterator.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDatime.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TUUID.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TChain.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TTree.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TBranch.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TObjArray.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttFill.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDataType.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDictionary.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Property.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttLine.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttMarker.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArrayD.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArray.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArrayI.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TClass.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TObjString.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TVirtualTreePlayer.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TFile.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDirectoryFile.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TMap.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/THashTable.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TUrl.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TH2.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TH1.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAxis.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttAxis.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArrayC.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArrayS.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArrayF.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Foption.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TVectorFfwd.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TVectorDfwd.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TFitResultPtr.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TMatrixFBasefwd.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TMatrixDBasefwd.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TStyle.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttText.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TCanvas.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TPad.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TVirtualPad.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttPad.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TVirtualX.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/GuiTypes.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Buttons.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TQObject.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttCanvas.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TCanvasImp.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TH2I.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TH1F.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TCutG.h
AnalysisClass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TGraph.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TApplication.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TObject.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Rtypes.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/RConfig.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/RVersion.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/DllImport.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Rtypeinfo.h
main_readFile.o: /usr/include/stdio.h /usr/include/features.h
main_readFile.o: /usr/include/libio.h /usr/include/_G_config.h
main_readFile.o: /usr/include/wchar.h /usr/include/string.h
main_readFile.o: /usr/include/xlocale.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/snprintf.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/strlcpy.h
main_readFile.o: /usr/include/unistd.h /usr/include/getopt.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TGenericClassInfo.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TSchemaHelper.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TStorage.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TVersionCheck.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Riosfwd.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TBuffer.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TQObject.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TApplicationImp.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TString.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TMathBase.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TROOT.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDirectory.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TNamed.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TList.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TSeqCollection.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TCollection.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TIterator.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDatime.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TUUID.h
main_readFile.o: readfile.C
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TTree.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TBranch.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TObjArray.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttFill.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDataType.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDictionary.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Property.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttLine.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttMarker.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArrayD.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArray.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArrayI.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TClass.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TObjString.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TVirtualTreePlayer.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TChain.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TFile.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDirectoryFile.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TMap.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/THashTable.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TUrl.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TH1I.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TSystem.h
main_readFile.o: /usr/include/ctype.h /usr/include/endian.h
main_readFile.o: /usr/include/fcntl.h /usr/include/time.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TInetAddress.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TTimer.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TSysEvtHandler.h
main_readFile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TTime.h
main_readFile.o: /user/e14066/ddasdumper/DDASEvent.h
main_readFile.o: /user/e14066/ddasdumper/ddaschannel.h /usr/include/stdlib.h
main_readFile.o: /usr/include/alloca.h /usr/include/stdint.h
main_readFile.o: /user/e14066/ddasdumper/ddaschannel.h
myclass.o: myclass.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TROOT.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDirectory.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TNamed.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TObject.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Rtypes.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/RConfig.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/RVersion.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/DllImport.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Rtypeinfo.h
myclass.o: /usr/include/stdio.h /usr/include/features.h /usr/include/libio.h
myclass.o: /usr/include/_G_config.h /usr/include/wchar.h
myclass.o: /usr/include/string.h /usr/include/xlocale.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/snprintf.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/strlcpy.h
myclass.o: /usr/include/unistd.h /usr/include/getopt.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TGenericClassInfo.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TSchemaHelper.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TStorage.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TVersionCheck.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Riosfwd.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TBuffer.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TString.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TMathBase.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TList.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TSeqCollection.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TCollection.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TIterator.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDatime.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TUUID.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TChain.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TTree.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TBranch.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TObjArray.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttFill.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDataType.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDictionary.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Property.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttLine.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttMarker.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArrayD.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArray.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArrayI.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TClass.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TObjString.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TVirtualTreePlayer.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TFile.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDirectoryFile.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TMap.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/THashTable.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TUrl.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TH2.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TH1.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAxis.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttAxis.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArrayC.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArrayS.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArrayF.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Foption.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TVectorFfwd.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TVectorDfwd.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TFitResultPtr.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TMatrixFBasefwd.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TMatrixDBasefwd.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TStyle.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttText.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TCanvas.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TPad.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TVirtualPad.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttPad.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TVirtualX.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/GuiTypes.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Buttons.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TQObject.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttCanvas.h
myclass.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TCanvasImp.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TTree.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TBranch.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TObjArray.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttFill.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDataType.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDictionary.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Property.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttLine.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TAttMarker.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArrayD.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArray.h
readfile.o: /usr/include/string.h /usr/include/features.h
readfile.o: /usr/include/xlocale.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TArrayI.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TClass.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TObjString.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TVirtualTreePlayer.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TChain.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TFile.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TDirectoryFile.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TMap.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/THashTable.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TUrl.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TH1I.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TSystem.h
readfile.o: /usr/include/stdio.h /usr/include/libio.h
readfile.o: /usr/include/_G_config.h /usr/include/wchar.h
readfile.o: /usr/include/ctype.h /usr/include/endian.h /usr/include/fcntl.h
readfile.o: /usr/include/time.h /usr/include/unistd.h /usr/include/getopt.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TInetAddress.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TTimer.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TSysEvtHandler.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TTime.h
readfile.o: /user/e14066/ddasdumper/DDASEvent.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TObject.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Rtypes.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/RConfig.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/RVersion.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/DllImport.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Rtypeinfo.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/snprintf.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/strlcpy.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TGenericClassInfo.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TSchemaHelper.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TStorage.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TVersionCheck.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/Riosfwd.h
readfile.o: /mnt/misc/sw/x86_64/Debian/7/root/gnu/5.34.09/include/TBuffer.h
readfile.o: /user/e14066/ddasdumper/ddaschannel.h /usr/include/stdlib.h
readfile.o: /usr/include/alloca.h /usr/include/stdint.h
readfile.o: /user/e14066/ddasdumper/ddaschannel.h
