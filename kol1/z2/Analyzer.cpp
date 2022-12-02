#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

Analyzer::Analyzer()
{
}

Analyzer::~Analyzer()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}
void Analyzer::Plot()
{
TH2F *h1;
h1=new TH2F("mass  vs dR","2D histogram mass  vs dR", 100,2,4,100,0,1.5); 

 if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<100000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

//reconstruciton mass

      ele0.SetPtEtaPhiM(ele_pt->at(0),ele_eta->at(0),ele_phi->at(0),0.);
      ele1.SetPtEtaPhiM(ele_pt->at(1),ele_eta->at(1),ele_phi->at(1),0.);

	if ((eleeleId->at(0) + eleeleId->at(1)) == 0)
	{
		mass=ele0+ele1;
	}
	
h1->Fill(mass.M(),dR);


h1->GetXaxis()->SetTitle("Mass[GeV]");
h1->GetYaxis()->SetTitle("dR");	
h1->Draw("COLZ");	

}
