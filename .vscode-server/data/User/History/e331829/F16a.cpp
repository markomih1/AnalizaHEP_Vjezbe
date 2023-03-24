#include <Analyzer.h>
#include <cmath>

Analyzer::Analyzer(){

}

void Analyzer::CIP(double CL,int N){
double sum,sumd,sumdw;
int r;
double Lup=49.999;
double Ld=0.001;
double increment=0.001;
    while(sum<(1-CL)/2.){
        sum=0.;
        for (r=0;r<=N;r++)
        {
                sum+=TMath::Poisson(r,Lup) ;  
        }
        Lup-=increment;
    }
    

     while(sumdw<(1-CL)/2.){
        sumd=0.;
        for (r=0;r<=N-1;r++)
        {
                sumd+=TMath::Poisson(r,Ld)  ;
                sumdw=1-sumd;
        }
        Ld+=increment;
    }


     cout << "lamdba_minus = " <<   Ld << "\n";
    cout << "lambda_plus = " << Lup << "\n";

}

