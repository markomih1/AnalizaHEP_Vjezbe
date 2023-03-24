#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

Analyzer::Analyzer()
{

}
void Analyzer::Plot()
{
   TCanvas *c3 = new TCanvas(country,country,700,700);

   testStatistic_H0 = new TH1F("testStatistic_H0","H_0 Test Statistic PDF",150,0.,15.);
   testStatistic_H1 = new TH1F("testStatistic_H1","H_1 Test Statistic PDF",150,0.,15.);

   double sum_H0=0.;
   double sum_H1=0.;

   for (int i=0; i < 1000000 ; i++)
   {
    
         sum_H0 += r3->Gaus(3,1.5);
         sum_H1 += r3->Gaus(7,1.5);
     

     testStatistic_H0->Fill(sum_H0);
     testStatistic_H1->Fill(sum_H1);

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

  
   

   c3->SaveAs("TestStatistic_SpainVs"+ country + ".pdf");
}