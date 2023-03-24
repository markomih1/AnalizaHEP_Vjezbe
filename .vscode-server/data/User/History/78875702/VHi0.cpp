#include<Analyzer.h>
#include<iostream>
#include<cstdlib>
#include <cmath>
#include <ctime>
#include <random>
#include <fstream>


using namespace std;

Analyzer::Analyzer()
{

}

void Analyzer::volumen(double a, double b, double c,int n){

    srand(time(NULL));
    int unutra=0.,vanka=0.;
    double v,rand_x,rand_y,rand_z,el;

    for (int i = 0; i < n; i++) {
         rand_x = -a+2*a*(double)rand()/RAND_MAX;
         rand_y = -b+2*b*(double)rand()/RAND_MAX;
         rand_z = -c+2*c*(double)rand()/RAND_MAX;

        el=pow(rand_x / a, 2) + pow(rand_y / b, 2) + pow(rand_z / c, 2);
        if (el <= 1) {
            unutra++;
        }
        vanka++;


        v=double(8*a*b*c)*(unutra/vanka);

    }


    cout<<"Procjena volumena: "<<v<<endl;


}