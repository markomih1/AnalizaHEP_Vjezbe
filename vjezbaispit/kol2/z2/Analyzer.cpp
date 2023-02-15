#include <Analyzer.h>

Analyzer::Analyzer()
{

}
Analyzer::~Analyzer(){


}

double Analyzer::Binom(int r, double p, int N)
{
  return TMath::Binomial(N,r)*pow(p,r)*pow((1-p),N-r);
}


int Analyzer::R0(int N,double ep,double p){


double sum=0.;
int r;

while(sum<ep){
	sum+=Binom(r,p,N);
	r++;


	}
return r;

}
