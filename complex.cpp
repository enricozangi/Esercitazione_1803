#include <iostream>
#include <iomanip>

#include "complex.hpp"

int main()
{
complex<float> c1(.323,.21);
complex<double> c2(2, -3);
complex<double> c3(1,3.14);
complex<float> c4 = c1.conjugate();

std::cout << "the conjugate of " << c1 << " is " << c4 << "\n" << std::endl;
std::cout << c2 << " + " << c3 << " = " << c2 +c3 << "\n" << std::endl;
std::cout << c3 << " + " << "2.1" << " = " << c3 + 2.1 << "\n" << std::endl;
std::cout << "2.1" << " * " << c3 << " = " << 2.1 * c3 << "\n" << std::endl;

return 0;
}