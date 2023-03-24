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

   double sum_x_H0=0.;
   double sum_x_H1=0.;

   for (int i=0; i < 10000 ; i++)
   {
    

      
        sum_x_H0= r3->Gaus(3.,1.5);
         sum_x_H1= r3->Gaus(7.,1.5);
     

     testStatistic_H0->Fill(sum_x_H0);
     testStatistic_H1->Fill(sum_x_H1);

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




   double x_obs = 0.;
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

   x_obs = x_obs/10000.;

   p_value = testStatistic_H0->Integral(testStatistic_H0->FindBin(x_obs),1.);
   cout << "p-value for the null hypothesis is: " << p_value << endl;


}

