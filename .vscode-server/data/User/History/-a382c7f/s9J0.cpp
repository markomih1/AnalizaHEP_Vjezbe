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
gr->SetTitle("ChiSquareTree");

	Long64_t nentries = tree -> GetEntriesFast();
	for (int i = 0; i < nentries; i++){

		tree -> GetEntry(i);
		gr -> Fill(x,y);
	}
f= new TF1("fit funkcija", "TMath::Exp(-[0]*x) * TMath::Sin([1]*x) ",0.,10.);
f -> SetParameter(0, 0.2);
f -> SetParameter(1, 2.);
gr->Fit(f,"L","",0,10);
gr->SetMarkerColor(kBlack);
 gr->SetMarkerStyle(21);
gr-> GetXaxis() -> SetTitle("x");
gr-> GetYaxis() -> SetTitle("y");

gr->Draw("P");
f->Draw("Same");


c -> Print ("zad1.pdf");

cout << "alfa =" << f -> GetParameter(0) << "±" << f -> GetParError(0) << endl;
cout << "beta = " << f -> GetParameter(1) << "±" << f -> GetParError(1) << endl;
}
