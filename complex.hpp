#pragma once
#include <iostream>

// defining class

template<typename T>
concept fp = std::floating_point<T>;

template<fp T>
class complex
{
T real_part;
T imaginary_part;

public:

// defining constructors

complex(): real_part(0), imaginary_part(0) {}

explicit complex(T re): real_part(re), imaginary_part(0){}

complex(T re, T im): real_part(re), imaginary_part(im){}

// real and imaginary part:

T re() const {
return real_part;
}

T im() const {
return imaginary_part;
}

// conjugate

complex<T> conjugate() const {

return complex<T>(real_part, -imaginary_part);
}

// overload of operator += and +

complex& operator+=(const complex& other) {
real_part += other.real_part;
imaginary_part += other.imaginary_part;
return *this;
}

complex operator+(const complex& other) const {
complex a = *this;
a += other;
return a;
}

complex& operator+=(const T& other) {
real_part += other;
return *this;
}

complex operator+(const T& other) const {
complex a = *this;
a += other;
return a;
}

// overload of operator *= and *

complex& operator*=(const complex& other) {

T a = real_part;
T b = imaginary_part;
T c = other.real_part;
T d = other.imaginary_part;

real_part = a*c - b*d;
imaginary_part = a*d + b*c;
return *this;
}

complex operator*(const complex& other) const {
complex a = *this;
a *= other;
return a;
}

complex& operator*=(const T& other) {
real_part *= other;
imaginary_part *= other;
return *this;
}

complex operator*(const T& other) const {
complex a = *this;
a *= other;
return a;
}
};

// overload of << :

template<fp T>
std::ostream&
operator<<(std::ostream& os, const complex<T>& c) {
if(c.re() != 0) {
if(c.im() > 0) {
os << c.re() << "+" << c.im() << "i";
}
else if(c.im() < 0) {
os << c.re() << c.im() << "i";
}
else {
os << c.re();
}}

else if (c.im() != 0) {
os << c.im() << "i";
}

else {
os << c.re();
}

return os;
}

template<fp T>

complex<T> operator+(const T& number1, const complex<T>& number2) {
return complex(number1)+number2;
}

template<fp T>

complex<T> operator*(const T& number1, const complex<T>& number2) {
return complex(number1)*number2;
}

