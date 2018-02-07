#include "gdVec2.h"
#include<math.h>



gdVec2::gdVec2()
{
	SetZero();
}

gdVec2::gdVec2(double _x, double _y)
{
	Set(_x, _y);
}

//using pythagorean theorem to find length of vector
double gdVec2::Length() const
{
	double length;
	length = sqrt(x*x + y*y);
	return length;
}

//normalizing vector to 1
void gdVec2::Normalize()
{
	x /= Length();
	y /= Length();
}

//dot product of given vector
double gdVec2::Dot(const gdVec2& V) const
{
	double tempX, tempY, dotProduct;
	tempX = x * V.x;
	tempY = y * V.y;
	dotProduct = tempX + tempY;
	return dotProduct;
}

//passing the parameters in the class
void gdVec2::Set(double _x, double _y)
{
	x = _x;
	y = _y;
}

//calling th set function to set the values to zero
void gdVec2::SetZero()
{
	Set(0, 0);
}

//overloading the binary operator += to add two vectors and set the values
void gdVec2::operator += (const gdVec2& v)
{
	Set(x + v.x, y + v.y);
}

//overloading the binary operator -= to subtract vectors and set the values
void gdVec2::operator -= (const gdVec2& v)
{
	Set(x + v.x, y + v.y);
}

//overloading the binary operator *= to multiply the vector with a constant and set the values
void gdVec2::operator *= (double a)
{
	Set(x * a, y * a);
}

//negate the given vector
gdVec2 gdVec2::operator -() const
{
	return gdVec2(-x, -y);
}

//overloading unary operator / to divide a vector with a constant
gdVec2 gdVec2::operator /(double a) 
{
	return gdVec2(x / a, y / a);
}

//overloading unary operator * to multiply a vector with a constant NOTE:this doesn't change the values of the given vector
gdVec2 gdVec2::operator *(double a)
{
	return gdVec2(x * a, y * a);
}

//overloading unary operator + to add two vectors NOTE:this doesn't change the values of the given vector
gdVec2 gdVec2::operator +(const gdVec2& v)
{
	return gdVec2(x + v.x, y + v.y);
}

