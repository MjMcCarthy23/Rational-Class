//
// Created by Michael McCarthy on 2021-10-31.
//

#pragma once
#include <iostream>

using namespace std;

class Rational
{
public:

    // Create alias name for type int
    typedef int Integer;

    //default constructor
    Rational();

    // Constructor to give object a numerator and denominator
    Rational(Integer num , Integer den );

    // Move constructor: commented out because it is not used
    //Rational(Rational&& rhs) noexcept;

    // Copy constructor
    Rational(Rational& rhs);

    /* overloading operator = to copy an object to a new object via
    copy constructor.*/
    Rational& operator=(const Rational& rhs);


    /*overloading = to set a temporary objects attributes(numerator
     * and denominator to the original object VIA move constructor*/
    Rational& operator=(const Rational&& rhs);

    /* add two objects, and create a new object with the result*/
    Rational operator+(const Rational& rhs);

    /* subtract two objects, and create a new object with the result*/
    Rational operator-(const Rational& rhs);

    /* multiply two objects, and create a new object with the result*/
    Rational operator*(const Rational& rhs);

    /* divide two objects, and create a new object with the result*/
    Rational operator/(const Rational& rhs);

    /*add two objects and move the result to the attributes of
     * the LHS object
     * Need to use move constructor*/
    Rational operator+=(const Rational& rhs);

    /*subtract two objects and move the result to the attributes of
     * the LHS object
     * Need to use move constructor*/
    Rational operator-=(const Rational& rhs);

    /*multiply two objects and move the result to the attributes of
     * the LHS object
     * Need to use move constructor*/
    Rational operator*=(const Rational& rhs);

    /*divide two objects and move the result to the attributes of
     * the LHS object
     * Need to use move constructor*/
    Rational operator/=(const Rational& rhs);

    /* overload the output stream operator, so you can cout
     * an object as you would traditionally (cout<<object;)*/
    friend ostream& operator<<( ostream &os, Rational &rhs);

    /* divide an the object attributes and return a decimal
     * approximation*/
    double toDouble();

private:
    Integer num;
    Integer den;
};