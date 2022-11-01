#include<iostream>

using namespace std;

class ElementaryParticle
{
   public:
   ElementaryParticle(string _name, float _mass, bool _isBoson);
   void printInfo();
   string name;
   float mass;
   bool isBoson;
   double px;
   double py;
   double py;
   double E;
   double pt;	

   void Energy(double, double, double);
   void pTrans(double, double);

   void InsertInfo();

};
