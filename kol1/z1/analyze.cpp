#include <iostream>
#include "Generator.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <random>
#include <TROOT.h>
#include <TFile.h>
#include <TChain.h>
#include <TApplication.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <random>
#include <fstream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TApplication.h>



int main()
{
	Generator *analysis;
	analysis=new Generator();
	int number_of_events=100000;
	analysis->GeneratePDF(number_of_events); 	
//	analysis->Plot();
}
