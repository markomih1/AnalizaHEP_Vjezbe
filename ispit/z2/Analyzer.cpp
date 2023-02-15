#include <Analyzer.h>
#include <cmath>
Analyzer::Analyzer()
{

}
Analyzer::~Analyzer()
{

}


double Analyzer::CPinterval(double CL, int N)
{
int r;
double lambda=49.999;
double sum=0.;
	
while(sum<(1-CL)){
sum=0.;
	for(r=0;r<N;r++){
	sum+=TMath::Poisson(r,lambda);
	}

	lambda-=0.001;

}

return lambda+0.001;

}

