
#include<iostream>
#include<cstdlib>
#include <cmath>
#include <ctime>
#include <random>
#include <fstream>
#include "Generator.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


using namespace std;

Generator::Generator()
{
	cout<<"Objekt je uspješno kreiran!"<<endl;
}


void Generator::GeneratePDF(int n){
int INTERVAL, i;
double rand_x,value;
double f[INTERVAL*INTERVAL];
INTERVAL=n;
srand(time(NULL));



for(i=0;i<(INTERVAL * INTERVAL); i++) {
	rand_x = double(rand() % (INTERVAL + 1)) /INTERVAL;
	f[i]=double (-1)*(rand_x+3)*(rand_x-9);
	value=f[i];
}


TH1F *h1;
h1=new TH1F("value","distribution",100,-3,9);

h1->Fill(f[i]);
TCanvas* canvas=new TCanvas("canvas","canvas",1000,1000);
gStyle->SetOptStat(0);
	canvas->cd(1);
	h1->Draw("HISTO");
	h1->GetXaxis()->SetTitle("distribution");
	h1->SetLineColor(kRed);

canvas->SaveAs("Histo.png");

}


