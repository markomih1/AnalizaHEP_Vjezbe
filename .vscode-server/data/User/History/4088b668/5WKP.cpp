
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
Analyzer::Analyzer()
{

}

Analyzer::~Analyzer()
{

}
void Analyzer::ChiSq(){

c= new TCanvas("c","c",1200,800);
gStyle->SetOptFit();

float x_arr[11];
float y_arr[11];
float error_arr[11];
float errorx_arr[11];

f=new TF1("fit","TMath::Exp(-[0]*x)*TMath::Sin([1]*x)",0.1,10);
f-> SetParName(0, "alpha");
f-> SetParName(1, "beta");
f-> SetParameter(0, 0.2);
f-> SetParameter(1, 2);

 file = new TFile("/home/public/data/Toy/ChiSquareTree.root ");
  tree = (TTree*)file->Get("tree");
  tree->SetBranchAddress("x",&x);
  tree->SetBranchAddress("y",&y);
  tree->SetBranchAddress("error",&error);
  
  nentries=tree->GetEntries();
  for(i=0;i<nentries;i++)
  {
   
   x_arr[i]=x;
   y_arr[i]=y;
   error_arr[i]=error;
   errorx_arr[i]=0;
  }
   gr=new TGraphErrors(11,x_arr,y_arr,errorx_arr,error_arr);

   gr->Fit(f);

    gr -> SetTitle("Chi-Square function fit");
   gr -> SetMarkerColor(kBlack);
   gr -> SetMarkerStyle(21);
   gr -> SetMaximum(0.9);
   gr -> SetMinimum(-0.7); 
   gr -> GetXaxis() -> SetTitle("x");
   gr -> GetYaxis() -> SetTitle("y");
   gr -> Draw("AP");
   
   c -> SaveAs("histo.pdf");







}