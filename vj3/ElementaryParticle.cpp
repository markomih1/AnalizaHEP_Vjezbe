#include<ElementaryParticle.h>

ElementaryParticle::ElementaryParticle(string _name, float _mass, bool _isBoson)
{
  name=_name;
  mass=_mass;
  isBoson=_isBoson;
 

}


void ElementaryParticle::printInfo()
{
  cout<<"Particle properties"<<endl<<"name:"<<name<<endl<<"mass:"<<mass<<endl<<"isBoson:"<<isBoson<<endl;
}

double ElementaryParticle::Energy(double px, double py, double pz)
{
return sqrt((px*px+py*py+pz*py)+mass*mass);

}
void pTrans(double px, double py)
{
	cout<< "pTrans="<<sqrt(px*px+py*py)<<endl;
}

void ElementaryParticle::InsertInfo()
{
cout<<"Impuls x="; cin >> px;
cout<<"Impuls y="; cin >> py;
cout<<"Impuls z="; cin >> pz;

}
