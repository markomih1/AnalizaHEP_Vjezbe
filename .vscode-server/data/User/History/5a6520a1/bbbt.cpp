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


void Analyzer::Plot()
{
   TCanvas *c3 = new TCanvas("graf","graf",700,700);

   testStatistic_H0 = new TH1F("testStatistic_H0","H_0 Test Statistic PDF",150,0.,15.);
   testStatistic_H1 = new TH1F("testStatistic_H1","H_1 Test Statistic PDF",150,0.,15.);

   double sum_height_H0;
   double sum_height_H1;

   for (int i=0; i < 1000000 ; i++)
   {
     sum_height_H0 = 0.;
     sum_height_H1 = 0.;

     for (int j=0; j < 100; j++)
     {
         sum_height_H0 += r3->Gaus(168.0,7.0);
         sum_height_H1 += r3->Gaus(mu,sigma);
     }

     testStatistic_H0->Fill(sum_height_H0/100.);
     testStatistic_H1->Fill(sum_height_H1/100.);

   }

   testStatistic_H0->SetFillColor(kRed-2);
   testStatistic_H0->SetLineColor(kRed-2);

   testStatistic_H0->SetTitle("Hypoyhesis testing");
   testStatistic_H0->GetXaxis()->SetTitle("#bar{h} [cm]");

   testStatistic_H0->Scale(1./testStatistic_H0->Integral());
   testStatistic_H0->Draw("HIST");

   testStatistic_H1->SetFillColor(kBlue-4);
   testStatistic_H1->SetLineColor(kBlue-4);

   testStatistic_H1->SetTitle("Hypoyhesis testing");
   testStatistic_H1->GetXaxis()->SetTitle("#bar{h} [cm]");

   testStatistic_H1->Scale(1./testStatistic_H1->Integral());
   testStatistic_H1->Draw("HIST SAME");

   TLine *line = new TLine(t_obs, 0. , t_obs, 0.04);
   line->SetLineWidth(3);
   line->Draw();

   TLegend *leg = new TLegend(0.7,0.6,0.9,0.9);
   leg->AddEntry(testStatistic_H0, "Spain", "f");
   leg->AddEntry(testStatistic_H1, country, "f");
   leg->Draw();

   c3->SaveAs("TestStatistic_SpainVs"+ country + ".pdf");
testStatistic_H0 = new TH1F("testStatistic_H0"+country,"H_0 Test Statistic PDF",150,160.,175.);
   testStatistic_H1 = new TH1F("testStatistic_H1"+country,"H_1 Test Statistic PDF",150,160.,175.);

   double sum_height_H0;
   double sum_height_H1;

   for (int i=0; i < 1000000 ; i++)
   {
     sum_height_H0 = 0.;
     sum_height_H1 = 0.;

     for (int j=0; j < 100; j++)
     {
         sum_height_H0 += r3->Gaus(168.0,7.0);
         sum_height_H1 += r3->Gaus(mu,sigma);
     }

     testStatistic_H0->Fill(sum_height_H0/100.);
     testStatistic_H1->Fill(sum_height_H1/100.);

   }

   testStatistic_H0->SetFillColor(kRed-2);
   testStatistic_H0->SetLineColor(kRed-2);

   testStatistic_H0->SetTitle("Hypoyhesis testing");
   testStatistic_H0->GetXaxis()->SetTitle("#bar{h} [cm]");

   testStatistic_H0->Scale(1./testStatistic_H0->Integral());
   testStatistic_H0->Draw("HIST");

   testStatistic_H1->SetFillColor(kBlue-4);
   testStatistic_H1->SetLineColor(kBlue-4);

   testStatistic_H1->SetTitle("Hypoyhesis testing");
   testStatistic_H1->GetXaxis()->SetTitle("#bar{h} [cm]");

   testStatistic_H1->Scale(1./testStatistic_H1->Integral());
   testStatistic_H1->Draw("HIST SAME");

   TLine *line = new TLine(t_obs, 0. , t_obs, 0.04);
   line->SetLineWidth(3);
   line->Draw();

   TLegend *leg = new TLegend(0.7,0.6,0.9,0.9);
   leg->AddEntry(testStatistic_H0, "Spain", "f");
   leg->AddEntry(testStatistic_H1, country, "f");
   leg->Draw();

   c3->SaveAs("TestStatistic_SpainVs"+ country + ".pdf");

}