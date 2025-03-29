#pragma once

// class and constructors

template<typename T>
concept fp = std::floating_point<T>;

template<fp T>
class complex
{
T real_part;
T imaginary_part;

public:
complex();
complex(T re, T im);
complex(const T& num);
T re() const;
T im() const;
complex<T> conjugate() const;

complex& operator+=(const complex<T>& other);
complex operator+(const complex<T>& other) const;
complex& operator*=(const complex<T>& other);
complex operator*(const complex<T>& other) const;

complex& operator+=(const T& number);
complex operator+(const T& number) const;
complex& operator*=(const T& number);
complex operator*(const T& number) const;
};

// defining constructors
template<fp T>

complex<T>::complex() {
real_part = 0;
imaginary_part = 0;
}

template<fp T>

complex<T>::complex(T re, T im) {
real_part = re;
imaginary_part = im;
}

// real and imaginary part:

template<fp T>

T complex<T>::re() const {
return real_part;
}

template<fp T>

T complex<T>::im() const {
return imaginary_part;
}


// conjugate

template<fp T>

complex<T> complex<T>::conjugate() const {

return complex<T>(real_part, -imaginary_part);
}


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

// overload of operator += and +

template<fp T>

complex<T>& complex<T>::operator+=(const complex<T>& other) {
real_part += other.real_part;
imaginary_part += other.imaginary_part;
return *this;
}

template<fp T>

complex<T> complex<T>::operator+(const complex<T>& other) const {
complex<T> a = *this;
a += other;
return a;
}

template<fp T>

complex<T>& complex<T>::operator+=(const T& other) {
real_part += other;
return *this;
}

template<fp T>

complex<T> complex<T>::operator+(const T& other) const {
complex<T> a = *this;
a += other;
return a;
}

// overload of operator *= and *

template<fp T>

complex<T>& complex<T>::operator*=(const complex<T>& other) {
T a = real_part;
T b = imaginary_part;
T c = other.real_part;
T d = other.imaginary_part;
real_part = a*c - b*d;
imaginary_part = a*d + b*c;
return *this;
}

template<fp T>

complex<T> complex<T>::operator*(const complex<T>& other) const {
complex<T> a = *this;
a *= other;
return a;
}

template<fp T>

complex<T>& complex<T>::operator+=(const T& other) {
real_part *= other;
imaginary_part *= other;
return *this;
}

template<fp T>

complex<T> complex<T>::operator*(const T& other) const {
complex<T> a = *this;
a *= other;
return a;
}