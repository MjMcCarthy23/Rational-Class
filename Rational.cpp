//
// Created by Michael McCarthy on 2021-10-31.
//

#include "Rational.h"

using namespace std;

//constructor
Rational::Rational(Integer num, Integer den)
: num{num}, den{den}{

}

/*default constructor: delegates to the 2 arg constructor
 initialize num = 1, den = 0*/
Rational::Rational()
: Rational {0,1}{

}

// move constructor commented out because it is not used
/*Rational::Rational(Rational&& rhs) noexcept
: num{rhs.num},den{rhs.den}  {
    std::cout<<"move constructor"<<std::endl;

}*/

// copy constructor
Rational::Rational(Rational& rhs)
: num{rhs.num},den{rhs.den}  {

}

// move assignment
Rational &Rational::operator=(const Rational&& rhs){

    if (this == &rhs)
        return *this;

    this -> num = rhs.num;
    this -> den = rhs.den;


    return *this;
}

// copy assignment
Rational &Rational::operator=(const Rational &rhs){
    std::cout<<"copy assignment"<<std::endl;
    // checking the objects are not the same
    if (this == &rhs)
        return *this;
    // setting the new objects attributes = to the copied objects attributes
    this -> num = rhs.num;
    this -> den = rhs.den;

    return *this;
}

//************************ Description of following code can be found in header file *******************************
Rational Rational::operator+(const Rational &rhs) {
    Rational sum;
    sum.num = num*rhs.den + den*rhs.num;
    sum.den = den*rhs.den;

    return sum;
}

Rational Rational::operator-(const Rational &rhs) {
    Rational diff;
    diff.num = num * rhs.den - den * rhs.num;
    diff.den = den * rhs.den;

    return diff;
}

Rational Rational::operator*(const Rational &rhs) {
    Rational prod;
    prod.num = num * rhs.num;
    prod.den = den * rhs.den;

    return prod;
}

Rational Rational::operator/(const Rational &rhs) {
    Rational quotient;
    quotient.num = num * rhs.den;
    quotient.den = den * rhs.num;

    return quotient;
}

Rational Rational::operator+=(const Rational &rhs) {return *this = (*this+rhs);}

Rational Rational::operator-=(const Rational &rhs) {return *this = *this-rhs;}

Rational Rational::operator*=(const Rational &rhs) {return *this = *this*rhs;}

Rational Rational::operator/=(const Rational &rhs) {return *this = *this/rhs;}


ostream &operator<<(ostream &os,Rational &rhs){
    os << rhs.num << "/" << rhs.den;
    return os;
}

double Rational::toDouble() {
    // Type cast double to num and den to return a double.
    return ((double)num)/((double)den);
}







































