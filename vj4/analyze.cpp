// My own class
#include <Analyzer.h>

int main()
{
  // Declare Analyzer
  Analyzer *analyzer;

  analyzer = new Analyzer();

  analyzer->ReadTxtFile("../vj3/Analysis.txt");
  analyzer->ConvertTxtToRootFile("../vj3/Analysis.txt","Analysis.root");

  analyzer->~Analyzer();

  return 0;
}
