#include<Analyzer.h>

Analyzer::Analyzer()
{

}

Analyzer::~Analyzer()
{

}


void Analyzer::Funkcija()
{


 gStyle->SetOptStat(0);
 file = new TFile("/home/public/data/Toy/ToyTree.root");
  tree = (TTree*)file->Get("tree");
  tree->SetBranchAddress("var",&var);
  HistoLikelihood = new TH1F("Likelihood", "Likelihood", 100, 0.0, 10.);

funkc= new TF1("funkcija","[0]* (TMath::Exp(-x/[1])+TMath::Exp(-(x-[2])*(x-[2])/(2.*[3]*[3])))",0.,10.);
 funkc->SetParameter(0,224.);
funkc->SetParameter(1,4.);
funkc->SetParameter(2,3.);
funkc->SetParameter(3,0.3);
//funkc->Draw(); 
Long64_t nentries=tree->GetEntries();
  for(i=0;i<nentries;i++)
  {
    tree->GetEntry(i);
    HistoLikelihood->Fill(var);
    
  }

HistoLikelihood->Fit(funkc,"L","",0,10);

  canvas1=new TCanvas("canvas1","canvas1",600,600);

  HistoLikelihood->Draw("HIST");
  canvas1->SaveAs("LiKelihood.pdf");

}

