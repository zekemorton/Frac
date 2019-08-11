//Zeke Morton
//Project 1 Fractional Class test

#include <iostream>
#include <sstream>
#include <string>
#include "Frac.h"

using namespace std;

int main()
{
  cout<<"This Program tests the Frac Class.";
  Frac a;
  cout << "\nCreated default Frac a as " << a;
  Frac s("26/62");
  cout << "\nCreated Frac s(\"26/62\") as " << s;
  Frac x(3,4);
  Frac y(1,2);
  cout << "\nCreated Frac x(3,4) as " << x;
  cout << "\nCreated Frac y(1,2) as " << y;

  Frac z(x);
  cout << "\nCopy constructed z as x: " << z<<endl;

  Frac v;
  v = x + y;
  cout << x<< " + "<< y <<" is: " << v<<endl;

  v = x - y;
  cout << x<< " - "<< y<< " is: " << v<<endl;

  v = x * y;
  cout << x<< " * "<< y <<" is: " << v<<endl;

  v = x / y;
  cout << x<< " / "<< y<< " is: " << v<<endl;

  cout<<x<<" Incremented is ";
  ++x;
  cout<<x<<endl;

  cout<<x<<" Decremented is ";
  --x;
  cout<<x<<endl;

  cout<<"The numerator of "<<x<<" is "<<x.getNum()<<" and the Denominator is "<<x.getDen()<<endl;

  if (y+z > z){
    cout<< y<< " > "<< z<<endl;
  }
  else{
    cout<<y<< " < "<< z<<endl;
  }
  if (y == z){
    cout<< y<< " == "<< z<<endl;
  }
  else{
    cout<<y<< " != "<< z<<endl;
  }
  if (z == z){
    cout<< z<< " == "<< z<<endl;
  }
  else{
    cout<<z<< " != "<< z<<endl;
  }

  v = 5.5;
  cout<<"The number 5.5 as a fraction is: "<<v<<endl;

  v = 6.24;
  cout<<"The number 6.24 as a fraction is: "<<v<<endl;

  Frac d;
  cout<<"Please enter a Frac "<<endl;
  cin>>d;
  cout<<"Here is the Frac you entered: "<<d<<endl;

  cout<<"Here is the implementation for bouns points: "<<endl;
  int a2 = 1;
  float b2 = 2.2;
  Frac f1, f2;

  f1 = b2;
  f2 = (f1 - a2);
  cout<<"Assign Frac f1 with float b2 = 2.2  gives f1 = "<<f1<<endl;
  cout<<"Assign Frac f2 with f1 - int a2 = 1 gives f2  = "<<f2<<endl;
}
