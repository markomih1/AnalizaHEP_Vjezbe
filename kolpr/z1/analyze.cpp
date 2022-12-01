#include <iostream>
#include "Analyzer.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <random>

int main()
{
	Analyzer *analysis;
	analysis=new Analyzer();
	int events=5000;
	analysis->CalculatePi(events); 	
}
