#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void Analyzer::Plot()
{
   TCanvas *c3 = new TCanvas("graf","graf",700,700);

   testStatistic_H0 = new TH1F("testStatistic_H0","H_0 Test Statistic PDF",150,0.,15.);
   testStatistic_H1 = new TH1F("testStatistic_H1","H_1 Test Statistic PDF",150,0.,15.);

   double x_H0;
   double x_H1;

   for (int i=0; i < 1000000 ; i++)
   {
     x_H0 = 0.;
     x_H1 = 0.;

     for (int j=0; j < 100000; j++)
     {
         x_H0 += r3->Gaus(3,1.5);
         x_H1 += r3->Gaus(7,1.5);
     }

     testStatistic_H0->Fill(x_H0/100000.);
     testStatistic_H1->Fill(x_H1/100000.);

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

   

   c3->SaveAs("TestStatistic.pdf");
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
   testStatistic_PDF->GetXaxis()->SetTitle("#bar{h} [cm]");

   testStatistic_PDF->Scale(1./testStatistic_PDF->Integral());
   testStatistic_PDF->Draw("HIST");


   c2->SaveAs("TestStatistic_PDF.pdf");
   p_value = testStatistic_PDF->Integral(testStatistic_PDF->FindBin(x_obs),100000);
   cout << "p-value for the null hypothesis is: " << p_value << endl;
  

}