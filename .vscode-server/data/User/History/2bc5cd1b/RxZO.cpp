// C++
#include <iostream>
#include <fstream>

// My own class
#include <Analyzer.h>

using namespace std;

int main()
{
  // Declare Analyzer
  Analyzer *analyzer;

  analyzer = new Analyzer();

  analyzer->Generate_TestStatistic_H0();
  analyzer->PValueCalculation();

  analyzer->CompareHypothesis();


  delete analyzer;

  return 0;
}