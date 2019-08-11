// Function Prototypes for Overloaded Stream Operators
// Forward declaration needs to be filled
// if multifiles are used, make sure to place the inclusion guard.

#ifndef ANGLE_H
#define ANGLE_H

#include <iostream>

using namespace std;

class Frac {
private:
    int num, den;
    long gcd(long a, long b);
    void reduce();
public:
    Frac(string s);
    Frac(int num_=0, int den_= 1);
    Frac(Frac& rhs);
    Frac operator=(Frac& rhs);
    Frac operator=(int& rhs);
    Frac operator=(double rhs);
    Frac operator=(string rhs);

    //get and set
    string getFrac();
    int getNum();
    int getDen();
    void setNum(int num_);
    void setDen(int den_);

    // math + - * must be minimum term, i.e. no 2/8
    Frac operator + (Frac &rhs);
    Frac operator - (Frac &rhs);
    Frac operator - (int &rhs);
    Frac operator * (Frac &rhs);
    Frac operator / (Frac &rhs);

    // increment ++ decrement --
    Frac operator++();
    Frac operator++(int);
    Frac operator--();
    Frac operator--(int);

    // comparators
    bool operator == (Frac &f2);
    bool operator != (Frac &f2);
    bool operator < (Frac &f2);
    bool operator > (Frac &rhs);
    bool operator <= (Frac &f2);
    bool operator >= (Frac &f2);

    //Obeject conversion
    operator double()
    {
      double temp1,temp2;
      temp1 = num;
      temp2 = temp1/den;
      return temp2;
    };

    operator int()
    {
      int temp1;
      temp1 = num/den;
      return temp1;
    };



    // overloading >> << stream operators
    // overloading >> << stream operators
    friend istream& operator>>(istream& strm, Frac& f)
    {
        cout << "Enter Numerator: ";
        strm >> f.num;
        cout << "Enter Denominator: ";
        strm >> f.den;
        f.reduce();
        return strm;
    };
    friend ostream& operator<<(ostream& strm, Frac& f)
    {
        strm << f.num<<"/"<<f.den;
        return strm;
    };
};

#endif
