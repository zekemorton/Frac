//Zeke Morton
//Project 1 Fractional Class definition

#include <iostream>
#include <sstream>
#include <string>
#include "Frac.h"


using namespace std;

//find gcd
long Frac::gcd(long a, long b)
{
  if (a == 0 | b == 0)
  return 1;
  long temp;
  if (a < b){
    temp = a;
    a = b;
    b =temp;
  }
  temp = a%b;
  if (temp == 0){
    return b;
  }
  else {
    return Frac::gcd(b,temp);
  }
}

//reduce the fraction
void Frac::reduce()
{
  long divisor = gcd(num,den);
  if (num != 0 && den != 0)
  {
    num /= divisor;
    den/= divisor;
  }


}

//take in a string argument
Frac::Frac(string s)
{
  stringstream ss(s);
  ss >> num;
  char peekchar = ss.peek();
  if( ss && peekchar == '/' ) {
      ss.get();
      ss >> den;
    }
  reduce();
}
Frac::Frac(int num_ , int den_)
{
  num = num_;
  den = den_;
  reduce();
}
int Frac::getNum()
{
  return num;
}
int Frac::getDen()
{
  return den;
}
Frac::Frac( Frac& rhs)
{
  num = rhs.getNum();
  den = rhs.getDen();
  reduce();
}
Frac Frac::operator=(Frac& rhs)
{
  num = rhs.num;
  den = rhs.den;
  reduce();
  return *this;
}
Frac Frac::operator=(int& rhs)
{
  num = rhs;
  reduce();
  return *this;
}
Frac Frac::operator=(double rhs)
{
  double temp = rhs;
  int temp1 =temp;
  int denom = 1;
  //getting fractions accurate up to 4 decimal places
  while (temp != temp1 && denom < 1000)
  {
    temp *=10;
    temp1 = temp;
    denom *=10;
  }
  num = temp;
  den = denom;
  reduce();
  return *this;
}
Frac Frac::operator=(string rhs)
{
  stringstream ss(rhs);
  ss >> num;
  char peekchar = ss.peek();
  if( ss && peekchar == '/' ) {
      ss.get();
      ss >>den;
    }

  reduce();
  return *this;
}

string Frac::getFrac()
{
  string frac;
  stringstream ss;
  ss << num;
  ss << den;
  frac = ss.str();
  return frac;
}

void Frac::setNum(int num_)
{
  num = num_;
  reduce ();
}
void Frac::setDen(int den_)
{
  den = den_;
  reduce();
}

// math + - * must be minimum term, i.e. no 2/8
Frac Frac::operator + (Frac &rhs)
{
  Frac temp;
  int num1, den1,num2, den2;
  num1 = num * rhs.den;
  num2 = rhs.num * den;

  den1 = den * rhs.den;
  den2 = rhs.den * den;

  temp.num = num1 + num2;
  temp.den = den1;
  temp.reduce();
  return temp;
}
Frac Frac::operator - (Frac &rhs)
{
  Frac temp;
  int num1, den1,num2, den2;
  num1 = num * rhs.den;
  num2 = rhs.num * den;

  den1 = den * rhs.den;
  den2 = rhs.den * den;

  temp.num = num1 - num2;
  temp.den = den1;
  temp.reduce();
  return temp;
}
Frac Frac::operator - (int &rhs)
{
  Frac temp;
  int num1, den1,num2, den2;
  num1 = num;
  num2 = rhs * den;

  den1 = den;
  den2 = den;

  temp.num = num1 - num2;
  temp.den = den1;
  temp.reduce();
  return temp;
}

Frac Frac::operator * (Frac &rhs)
{
  Frac temp;
  temp.num = num * rhs.getNum();
  temp.den = den * rhs.getDen();

  temp.reduce();
  return temp;
}
Frac Frac::operator / (Frac &rhs)
{
  Frac temp;
  temp.den = den * rhs.getNum();
  temp.num = num * rhs.getDen();

  temp.reduce();

  return temp;
}


// increment ++ decrement --
Frac Frac::operator++()
{
  num += den;
  reduce();
  return *this;
}
Frac Frac::operator++(int)
{
  Frac temp(num, den);
  num += den;
  reduce();
  return temp;
}
Frac Frac::operator--()
{
  num -= den;
  reduce();
  return *this;
}
Frac Frac::operator--(int)
{
  Frac temp(num, den);
  num -= den;
  reduce();
  return temp;
}
// comparators
bool Frac::operator == (Frac &f2)
{
  if (num == f2.getNum() && den == f2.getDen())
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
bool Frac::operator != (Frac &f2)
{
  if (num == f2.getNum() && den == f2.getDen())
  {
    return 0;
  }
  else
  {
    return 1;
  }
}
bool Frac::operator < (Frac &f2)
{
  int num1, num2;
  num1 = num * f2.getDen();
  num2 = f2.getNum() * den;

  if (num1 < num2){
    return 1;
  }
  else{
    return 0;
  }
}
bool Frac::operator > (Frac &rhs)
{
  int num1, num2;
  num1 = num * rhs.getDen();
  num2 = rhs.getNum() * den;

  if (num1 > num2){
    return 1;
  }
  else{
    return 0;
  }
}
bool Frac::operator <= (Frac &f2)
{
  int num1, num2;
  num1 = num * f2.getDen();
  num2 = f2.getNum() * den;

  if (num1 <= num2){
    return 1;
  }
  else{
    return 0;
  }
}
bool Frac::operator >= (Frac &f2)
{
  int num1, num2;
  num1 = num * f2.getDen();
  num2 = f2.getNum() * den;

  if (num1 >= num2){
    return 1;
  }
  else{
    return 0;
  }
}
