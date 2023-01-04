#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

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


void Analyzer::Plot2DHistogram()
{
canvas = new TCanvas ();
	canvas -> SetCanvasSize (900, 900);
	canvas -> SetTitle ("dR vs J/#psi reconstructed mass");

h1=new TH2F("mass  vs dR","2D histogram mass  vs dR", 100,2,4,100,0,1.5); 

 if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<100000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

//reconstruciton mass

      elektron.SetPtEtaPhiM(ele_pt->at(0),ele_eta->at(0),ele_phi->at(0),0.);
      pozitron.SetPtEtaPhiM(ele_pt->at(1),ele_eta->at(1),ele_phi->at(1),0.);
	Jpsi=elektron+pozitron;
	
	h1->Fill(Jpsi.M(),dR);
}

h1->Draw("COLZ");	
canvas -> Print ("zad2.pdf");
	canvas -> Print ("zad2.png");
	canvas -> Print ("zad2.root");
}
