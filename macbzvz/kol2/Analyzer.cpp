#include<Analyzer.h>

Analyzer::Analyzer()
{

}
void Analyzer::Plot(){

gStyle->SetOptStat(0);
  file = new TFile("/home/public/data/Toy/ToyTree.root");
  tree = (TTree*)file->Get("tree");
  tree->SetBranchAddress("var",&var);
  h = new TH1F("Graf", "Graf", 50, 0.0, 10.0);
  f=new TF1("funkcija","[0]*( TMath::Exp(-x/[1]) + TMath::Exp(-(x-[2])*(x-[2])/2./[3]/[3]) )",0.0,10.0);
    f->SetParameter(0,250.);
    f->SetParameter(1,4.);
    f->SetParameter(2,3.);
    f->SetParameter(3,0.3);

  nentries=tree->GetEntries();
  for(i=0;i<nentries;i++)
  {
    tree->GetEntry(i);
    h->Fill(var);
    
  }

  h->Fit(f,"L");

  canvas1=new TCanvas("canvas1","canvas1",600,400);
  h->GetXaxis()->SetTitle("var");
  h->Draw();
  canvas1->SaveAs("graf.pdf");

}