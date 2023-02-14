#include<Analyzer.h>
Analyzer::Analyzer()
{

}

Analyzer::~Analyzer()
{

}


void Analyzer::Toy(){

gStyle->SetOptStat(0);
  file = new TFile("/home/public/data/Toy/ToyTree.root");
  tree = (TTree*)file->Get("tree");
  tree->SetBranchAddress("var",&var);
  histo = new TH1F("Toy", "Toy", 50, 0.1, 10.0);
  f= new TF1("funkcija","[0] * (TMath::Exp(-(x/[1]))*TMath::Exp(-(x*[3])*(x-[3])/2/[4]/[4]))",0.1,10.);

//funkc->SetParameter(0,224.);
//funkc->SetParameter(1,4.);
//funkc->SetParameter(2,3.);
//funkc->SetParameter(3,0.3);

Long64_t nentries=tree->GetEntries();
  for(i=0;i<nentries;i++)
  {
    tree->GetEntry(i);
    histo->Fill(var);
    
  }
canvas1=new TCanvas("canvas1","canvas1",600,600);
 histo->Draw("HIST");
canvas1->SaveAs("LiKelihood.pdf");


}
