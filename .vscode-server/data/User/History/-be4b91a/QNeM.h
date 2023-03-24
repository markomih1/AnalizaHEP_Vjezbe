#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TString.h>
#include <TLegend.h>
#include <TLorentzVector.h>
#include <THStack.h>
#include <TGraph.h>
#include <TH2F.h>
#include <TF1.h>
#include<TMath.h>
#include<TPad.h>
//C++ libraries
#include <iostream>
#include <vector>
#include <TStyle.h>

using namespace std;

class Analyzer
{
  public:
    Analyzer();
    ~Analyzer();
    void Plot();
  

  private:
    TFile *file;
    TTree *tree;
    TF1 *f;
    TH1F *h;
    TCanvas *canvas1;
    Float_t x_observed;
    Int_t i,nentries;
};