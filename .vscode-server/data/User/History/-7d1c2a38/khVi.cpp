#include <Analyzer.h>
#include <cmath>
Analyzer::Analyzer()
{

}
Analyzer::~Analyzer()
{

}
double Analyzer::BinomialProb(int r, double p, int N)
{
  return TMath::Binomial(N,r)*pow(p,r)*pow((1-p),N-r);
}

int Analyzer::BIN(int N,double eps,double p){

double sum=0.;
    while (sum<eps)
    {
        for(r=0;r<=N;r++)
        sum+=BinomialProb(r,p,N);
    }
return r;

}