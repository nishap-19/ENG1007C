/*
Nozzle Project, Calculations
Purpose: Write a program that calculates the range the water will shoot from
the nozzle and the max height the water will reach
Student Name: Nisha Patel
*/

#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14159265

int main() {

	double nozzleRadius, hoseFlow, nozzleVelocity, height,
		time, angle, nozzleArea, DistanceX, DistanceY;

	//8 l/min = 1.33 x 10-4 m3/s
	hoseFlow = 1.33 * 0.0001;

	cout << "Enter the nozzle exit radius in inches: ";
	cin >> nozzleRadius;
	cout << endl;

	//1 inch = 0.0254 meters
	nozzleRadius = nozzleRadius * 0.0254;

	cout << "Enter the angle the nozzle is set at in degrees: ";
	cin >> angle;
	cout << endl;

	cout << "Enter the height the nozzle is placed in inches: ";
	cin >> height;
	cout << endl;

	//1 inch = 0.0254 meters
	height = height * 0.0254;

	//calculate area pi * r^2
	nozzleArea = PI * pow(nozzleRadius, 2);

	//calculate velocity A1V1=A2V2 V2=(A1V1/A2)
	nozzleVelocity = hoseFlow / nozzleArea;

	cout << "nozzle area = " << nozzleArea << endl;

	cout << "A nozzle with a radius of " << nozzleRadius << " meters has a velocity of " << nozzleVelocity
		<< "m/s." << endl << "It is placed at " << angle << " degrees and is " << height << " meters off the ground."
		<< endl;

	/*
	max height:
	V^2 = Vo^2+2aY
	2aY = V^2-Vo^2
	Y = (V^2-Vo^2)/2a
	*/

	DistanceY = ((pow(nozzleVelocity*sin(angle*PI / 180), 2)) / (2 * 9.8)) + height;
	cout << "The water flow's max height is " << DistanceY << " meters." << endl;

	/*
	max distance:
	Y=Yo+Vot+1/2at^2
	Y=height+(hypotenuse)cos(theta)(time)+(1/2)(acceleration)(time)^2
	a=(1/2)(acceleration)
	b=(hypotenuse)cos(theta)
	c=height
	time=(-b+/-sqrt(b^2-4ac))/2a
	X=Xo+Vot
	X=0+(hypotenuse)cos(theta)(time)
	*/

	double a = -4.9, b = nozzleVelocity * sin(angle*PI / 180), c = height;

	cout << "a = " << a << " b = " << b << " c = " << c << endl;

	time = ((-b) - (sqrt(pow(b, 2) - (4 * a * c)))) / (2 * a);

	cout << "time = " << time << endl;

	DistanceX = nozzleVelocity * cos(angle*PI / 180)*time;

	cout << "The water flow's max distance is " << DistanceX << " meters." << endl;

	//inches
	int feetY = (DistanceY / 0.0254) / 12;
	double inchesY = (DistanceY / 0.0254) - feetY*12;
	cout << "The water flow's max height is " << feetY << " feet and " << inchesY << " inches." << endl;
	int feetX = (DistanceX / 0.0254) / 12;
	double inchesX = (DistanceX / 0.0254) - feetX*12;
	cout << "The water flow's max distance is " << feetX << " feet and " << inchesX << " inches." << endl;

	return 0;
}