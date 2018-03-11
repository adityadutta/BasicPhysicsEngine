#include "Vector3.h"
#include<math.h>



Vector3::Vector3()
{
	SetZero();
}

Vector3::Vector3(double _x, double _y, double _z)
{
	Set(_x, _y, _z);
}

//using pythagorean theorem to find length of vector
double Vector3::Length() const
{
	double length;
	length = sqrt(x*x + y*y);
	return length;
}

//normalizing vector to 1
void Vector3::Normalize()
{
	x /= Length();
	y /= Length();
}

//dot product of given vector
double Vector3::Dot(const Vector3& V) const
{
	double tempX, tempY, dotProduct;
	tempX = x * V.x;
	tempY = y * V.y;
	dotProduct = tempX + tempY;
	return dotProduct;
}

//passing the parameters in the class
void Vector3::Set(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
}

//calling th set function to set the values to zero
void Vector3::SetZero()
{
	Set(0.0, 0.0, 0.0);
}

//overloading the binary operator += to add two vectors and set the values
void Vector3::operator += (const Vector3& v)
{
	Set(x + v.x, y + v.y, z + v.z);
}

//overloading the binary operator -= to subtract vectors and set the values
void Vector3::operator -= (const Vector3& v)
{
	Set(x - v.x, y - v.y, z - v.z);
}

//overloading the binary operator *= to multiply the vector with a constant and set the values
void Vector3::operator *= (double a)
{
	Set(x * a, y * a, z * a);
}

//negate the given vector
Vector3 Vector3::operator -() const
{
	return Vector3(-x, -y, -z);
}

//overloading unary operator / to divide a vector with a constant
Vector3 Vector3::operator /(double a)
{
	return Vector3(x / a, y / a, z / a);
}

//overloading unary operator * to multiply a vector with a constant NOTE:this doesn't change the values of the given vector
Vector3 Vector3::operator *(double a)
{
	return Vector3(x * a, y * a, z * a);
}

//overloading unary operator + to add two vectors NOTE:this doesn't change the values of the given vector
Vector3 Vector3::operator+(const Vector3& v)
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}

