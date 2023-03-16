#include <Analyzer1.h>
#include <cmath>
Analyzer::Analyzer()
{

}
Analyzer::~Analyzer()
{

}


pair<double,double> Analyzer::CPinterval(double CL, int N)
{
int r;
double lambda1=49.999,lambda2=0.;
double sum1=0.,sum2=0;

while(sum1<(1-CL)){
sum1=0.;
       	for(r=0;r<N;r++){
        sum1+=TMath::Poisson(r,lambda);
        }

	lambda1-=0.001;

}

while(sum2<CL){
sum2=0.;
       	for(r=0;r<N-1;r++){
        sum2+=TMath::Poisson(r,lambda);
        }

	lambda2+=0.001;

}

if(lambda2-2*0.001<0)
  return make_pair(0,lambda1+2*0.001);
  else if(lambda1+2*0.001>1)
  return make_pair(lambda2-2*0.001, 50);
  else
  return make_pair(lambda2-2*0.001, lambda1+2*0.001);
}



