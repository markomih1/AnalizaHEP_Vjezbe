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

void Analyzer::volumen(float a, float b, float c,int n){

    srand(time(NULL));
    int unutra=0.,vanka=0.;
    float v,rand_x,rand_y,rand_z,el;

    for (int i = 0; i < n; i++) {
        float rand_x = -a+2*a*(float)rand()/RAND_MAX;
        float rand_y = -b+2*b*(float)rand()/RAND_MAX;
        float rand_z = -c+2*c*(float)rand()/RAND_MAX;

        el=pow(rand_x / a, 2) + pow(rand_y / b, 2) + pow(rand_z / c, 2);
        if (el <= 1) {
            unutra++;
        }
        vanka++;
        v=(8*a*b*c)*(unutra/vanka);

    }


    cout<<"Procjena volumena: "<<v<<endl;


}