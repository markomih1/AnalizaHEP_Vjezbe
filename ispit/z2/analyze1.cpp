#include<Analyzer1.h>
int main()
{
  Analyzer *analyzer=new Analyzer();

 // cout<<analyzer->CPinterval(0.683,10)<<endl;
cout<<analyzer->CPinterval(0.90,10).first<<endl;
cout<<analyzer->CPinterval(0.90,10).second<<endl;
  analyzer->~Analyzer();
  return 0;
}
