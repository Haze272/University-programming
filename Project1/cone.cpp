// Solving the volume and surface area of the cone
// Stepan Berkunov

#define USE_MATH_DEFINES // для C++
#define M_PI 3.14159265358979323846
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	double volume, height, radiusOut, radiusIn, surfaceArea, forming;

	std::cout << "Enter the height value" << std::endl;
	cin >> height;

	std::cout << "Enter the smaller radius value" << std::endl;
	cin >> radiusIn;

	std::cout << "Enter the bigger radius value" << std::endl;
	cin >> radiusOut;

	std::cout << "Enter the forming value" << std::endl;
	cin >> forming;

	volume = M_PI * height * (pow(radiusOut, 2) + radiusOut * radiusIn + pow(radiusIn, 2)) / 3;
	std::cout << "Volume is: " << volume << std::endl;

	surfaceArea = M_PI * (pow(radiusOut, 2) + forming * (radiusOut + radiusIn) + pow(radiusIn, 2));
	std::cout << "Surface area is: " << surfaceArea << std::endl;
}

// Antihype!