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
 file = new TFile("/home/public/data/Lifetime/Lifetime.root");
  tree = (TTree*)file->Get("Tree");
  tree->SetBranchAddress("var",&var);
  HistoLikelihood = new TH1F("Likelihood", "Likelihood", 1, 0.0, 50.);

 funkc= new TF1("funkcija","[0]*(exp(-x/4.)+exp(-1*TMath::Power((x-3.),2)/2*0.09)",0.1,10.);
 funkc->SetParameter(0,100.);
 
nentries=tree->GetEntries();
  for(i=0;i<nentries;i++)
  {
    tree->GetEntry(i);
    HistoLikelihood->Fill(var);
    
  }

 //HistoLikelihood->Fit(funkc,"L");

  canvas1=new TCanvas("canvas1","canvas1",600,400);
  HistoLikelihood->GetXaxis()->SetTitle("t/s");
  HistoLikelihood->GetYaxis()->SetTitle("N");
  HistoLikelihood->Draw();
  canvas1->SaveAs("Lifelihood.pdf");

}

