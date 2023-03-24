#include<TROOT.h>
#include<TH1F.h>
#include<TMath.h>
#include<TCanvas.h>
#include<TStyle.h>
#include<iostream>

using namespace std;


class Analyzer{

 public:
	Analyzer();
	~Analyzer();
	double BinomialProb(int, double, int);
	int BIN(int, double, double);

 private:
	double sum, p, eps;
	int N, r; 

};