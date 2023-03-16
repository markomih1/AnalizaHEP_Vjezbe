#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

//ROOT headers
#include <TROOT.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TApplication.h>
#include <TString.h>
#include <TGraphErrors.h>
#include <TF1.h>
#include <TLine.h>
#include<TChain.h>
#include<TFile.h>
#include <TH2F.h>
using namespace std;

// Declare class Analyzer
class Analyzer
{
  // public member declaration
  public:
    Analyzer( );
    ~Analyzer( );

    void ChiSquareFit();

  // private member declaration
  private:
	TFile *file;
	TTree *tree;	
	Float_t x;
	Float_t y;
	Float_t error; 
   TCanvas *c;
	//TH2F *gr;
    TGraphErrors *gr;
    TF1 *f;
    Float_t sigmax;
};
