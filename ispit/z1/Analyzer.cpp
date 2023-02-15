#include"Analyzer.h"
#include <TH2.h>

Analyzer::Analyzer(){



}


Analyzer::~Analyzer(){



}

void Analyzer::ChiSquareFit()
{
  c = new TCanvas("c","c",1200,800);
  


	file = new TFile("/home/public/data/Toy/ChiSquareTree.root");
	tree = (TTree*)file -> Get("tree");
	tree -> SetBranchAddress("x", &x);
	tree -> SetBranchAddress("y", &y);
	tree -> SetBranchAddress("error", &error);

gr = new TH2F("ChiSquare","ChiSquare",100,0.,10.,100,0.,1.);
gr->SetTitle("x value");

	Long64_t nentries = tree -> GetEntriesFast();
	for (int i = 0; i < nentries; i++){

		tree -> GetEntry(i);
		gr -> Fill(x,y);
	}
//f= new TF1("fit funkcija", "TMath::Exp ")

gr->SetMarkerColor(kBlack);
  gr->SetMarkerStyle(21);
  gr->Draw("HISTO");
c -> Print ("zad1.pdf");
}
