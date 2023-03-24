
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#define Analyzer_cxx
Analyzer::Analyze(){

}

void Analyzer::Loop()
{
//   In a ROOT session, you can do:
//      root> .L Analyzer.C
//      root> Analyzer t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
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

 if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   int i = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
   
      x_arr[i] = x;
      y_arr[i] = y;
      error_arr[i] = error;
      errorx_arr[i] = 0;
      i++;

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