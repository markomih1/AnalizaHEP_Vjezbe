#include"Analyzer.h"

int main(void){

Analyzer *analyzer = new Analyzer();
cout << "r0 = " << analyzer -> BIN(10, 0.9, 0.9) << endl;
analyzer -> ~Analyzer();

return 0;
}