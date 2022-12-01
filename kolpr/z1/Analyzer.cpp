#include<iostream>
#include<cstdlib>
#include <cmath>
#include <ctime>
#include <random>
#include <fstream>
#include "Analyzer.h"

using namespace std;
Analyzer::Analyzer()
{
}

void Analyzer::CalculatePi(int n)
{
int  i,interval;
double rand_x, rand_y,d, pi;
int incircle = 0, all = 0;
interval=n;

srand(time(NULL));

for (i = 0; i < (interval*interval); i++) {
    rand_x = double(rand()%(interval+1))/interval;
    rand_y = double(rand()%(interval+1))/interval;
    d=rand_x * rand_x + rand_y * rand_y;
  
if (d <= 1)
        incircle++;
 	all++;
        pi = double(4*incircle)/all;


}
    cout<<"Procjena broja pi za "<<n<<"*"<<n<<" događaja: "<<pi<<endl;
}
