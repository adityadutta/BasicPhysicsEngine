#ifndef VECTOR3_H
#define VECTOR3_H
class Vector3
{
public:
public:
	double x;							//variable to hold the x component of the vector
	double y;							//variable to hold the y component of the vector
	double z;

	Vector3();
	Vector3(double _x, double _y, double _z);

	double Length() const;				// return the length (magnitude) of the vector
	void Normalize();					// converts vector into the unit vector
	double Dot(const Vector3& V) const;  // returns the dot product
	void Set(double _x, double _y, double _z);
	void SetZero();						// set x and y to zero

	void operator += (const Vector3& v); // add a vector. Using pass-by-const-reference
	void operator -= (const Vector3& v); // subtract a vector to this vector
	void operator *= (double a);		// multiply by a number “a” and set its value
	Vector3 operator -() const;			// negate vector. Const member can’t modify object
	Vector3 operator /(double a);		// divide by a number "a"
	Vector3 operator *(double a);		// multiply by a number "a"
	Vector3 operator +(const Vector3& v);	//add two vectors without changing values

};

#endif //!VECTOR3_H

