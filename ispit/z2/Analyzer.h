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
	//pair<double,double> CPinterval(double CL, int N); 
	double CPinterval(double CL, int N);


 private:
	double lambda;
	int N, r; 

};
