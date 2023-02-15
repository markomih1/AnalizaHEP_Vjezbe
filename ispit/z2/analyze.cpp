#include<Analyzer.h>
int main()
{
  Analyzer *analyzer=new Analyzer();
  
  cout<<analyzer->CPinterval(0.683,10)<<endl;
// cout<<analyzer->CPinterval(0.683,10).first<<endl;
  analyzer->~Analyzer();
  return 0;
}
