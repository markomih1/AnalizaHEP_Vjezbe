#include<iostream>
#include <TROOT.h>
#include <TH1F.h>
#include <TMath.h>
#include<THStack.h>
#include<TCanvas.h>
#include<TStyle.h>
#include<TLine.h>
using namespace std;



class Analyzer
{
  public:
	Analyzer();
	~Analyzer();
	double Binom(int, double, int);
	int R0(int, double, double);

 private:
	double P, p, ep;
	int N, r;   
};
