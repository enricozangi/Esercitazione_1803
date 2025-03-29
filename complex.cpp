#include <iostream>
#include <iomanip>

#include "complex.hpp"

int main()
{
complex<float> c1(.323,.21);
complex<float> c2(2, -3);
complex<float> c3(0,0);
complex<float> c4 = c1.conjugate();
complex<float> c5 = c4 * 3;


std::cout << c1 << "\n" << c2 << "\n" << c3 << "\n" << c4 << "\n" << c5 << std::endl;

return 0;
}