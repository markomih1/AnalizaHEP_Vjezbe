#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


void Analyzer::CompareHypothesis()
{
   TCanvas *c3 = new TCanvas("graf","graf",700,700);

   testStatistic_H0 = new TH1F("testStatistic_H0","H_0 Test Statistic PDF",150,0.,15.);
   testStatistic_H1 = new TH1F("testStatistic_H1","H_1 Test Statistic PDF",150,0.,15.);

   double sum_x_H0;
   double sum_x_H1;

   for (int i=0; i < 1000000 ; i++)
   {
     sum_x_H0 = 0.;
     sum_x_H1 = 0.;

     for (int j=0; j < 100000; j++)
     {
         sum_x_H0 += r3->Gaus(3,1.5);
         sum_x_H1 += r3->Gaus(7,1.5);
     }

     testStatistic_H0->Fill(sum_x_H0/100000.);
     testStatistic_H1->Fill(sum_x_H1/100000.);

   }

   testStatistic_H0->SetFillColor(kRed-2);
   testStatistic_H0->SetLineColor(kRed-2);

   testStatistic_H0->SetTitle("Hypoyhesis testing");
   testStatistic_H0->GetXaxis()->SetTitle("x");

   testStatistic_H0->Scale(1./testStatistic_H0->Integral());
   testStatistic_H0->Draw("HIST");

   testStatistic_H1->SetFillColor(kBlue-4);
   testStatistic_H1->SetLineColor(kBlue-4);

   testStatistic_H1->SetTitle("Hypoyhesis testing");
   testStatistic_H1->GetXaxis()->SetTitle("x");

   testStatistic_H1->Scale(1./testStatistic_H1->Integral());
   testStatistic_H1->Draw("HIST SAME");


   TLegend *leg = new TLegend(0.7,0.6,0.9,0.9);
   leg->AddEntry(testStatistic_H0, "x0", "f");
   leg->AddEntry(testStatistic_H1, "x1", "f");
   leg->Draw();

   c3->SaveAs("TestStatistic_.pdf");


}



void Analyzer::PValueCalculation()
{
   TCanvas *c2 = new TCanvas("c2","c2",700,700);

   x_obs = 0.;
   double p_value = 0.;

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      x_obs+=x_observed;
   }

   x_obs = x_obs/100000.;

   testStatistic_PDF->SetFillColor(kRed-2);
   testStatistic_PDF->SetLineColor(kRed-2);

   testStatistic_PDF->SetTitle("Test Statistic PDF distribution");
   testStatistic_PDF->GetXaxis()->SetTitle("x");

   testStatistic_PDF->Scale(1./testStatistic_PDF->Integral());
   testStatistic_PDF->Draw("HIST");

   

   c2->SaveAs("TestStatistic_PDF.pdf");

   p_value = testStatistic_PDF->Integral(testStatistic_PDF->FindBin(x_obs),100000);
   cout << "p-value for the null hypothesis is: " << p_value << endl;


}

void Analyzer::Generate_TestStatistic_H0()
{
  TCanvas *c = new TCanvas("c","c",700,700);

  gStyle->SetOptStat(0);

  testStatistic_PDF = new TH1F("testStatistic_PDF","Test Statistic PDF",150,0.,15.);

  double sum_x=0.;

  for (int i=0; i < 1000000 ; i++)
  {
    

    sum_x += r3->Gaus(3,1.5);
    

    //testStatistic_PDF->Fill(sum_x/100000.);

  }

  c->cd();
  testStatistic_PDF->SetFillColor(kRed-2);
  testStatistic_PDF->SetLineColor(kRed-2);

  testStatistic_PDF->SetTitle("Test Statistic PDF distribution");
  testStatistic_PDF->GetXaxis()->SetTitle("x");

  testStatistic_PDF->Scale(1./testStatistic_PDF->Integral());
   testStatistic_PDF->Draw("HIST");
   c->SaveAs("TestStatistic1_PDF.pdf");
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
