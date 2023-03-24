#include <Analyzer.h>
#include <cmath>

Analyzer::Analyzer(){

}

void Analyzer::CIP(double CL,int N,int m){
double sum,sumd,sumdw;
int r;
double Lup=49.999;
double Ld=0.001;
double increment=0.001;
    while(sum<(1-CL)){
        sum=0.;
        for (r=0;r<=N;r++)
        {
                sum+=TMath::Poisson(r,Lup) ;  
        }
        Lup-=increment;
    }
    

     while(sumdw<(1-CL)){
        sumd=0.;
        for (r=m;r<=N;r++)
        {
                sumd+=TMath::Poisson(r,Ld)  ;
                sumdw=1-sumd;
        }
        Ld+=increment;
    }


     cout << "lamdba_minus = " <<   Ld << "\n";
    cout << "lambda_plus = " << Lup << "\n";

}

