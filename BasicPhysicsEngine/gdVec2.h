#ifndef GDVEC2_H
#define GDVEC2_H

class gdVec2
{
public:
	double x;
	double y;

	gdVec2();
	gdVec2(double _x, double _y);

	double Length() const;				// return the length (magnitude) of the vector
	void Normalize();					// converts vector into the unit vector
	double Dot(const gdVec2& V) const;  // returns the dot product
	void Set(double _x, double _y);
	void SetZero();						// set x and y to zero

	void operator += (const gdVec2& v); // add a vector. Using pass-by-const-reference
	void operator -= (const gdVec2& v); // subtract a vector to this vector
	void operator *= (double a);		// multiply by a number “a” and set its value
	gdVec2 operator -() const;			// negate vector. Const member can’t modify object
	gdVec2 operator /(double a);		// divide by a number "a"
	gdVec2 operator *(double a);		// multiply by a number "a"
	gdVec2 operator +(const gdVec2& v);	//add two vectors without changing values
	

};
#endif //!GDVEC2_H

