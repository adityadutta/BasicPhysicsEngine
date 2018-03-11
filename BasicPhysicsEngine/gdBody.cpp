#include "gdBody.h"

gdBody::gdBody(double _mass)
{
	mass = _mass;
}

//constructor to pass values in the class
gdBody::gdBody(double _mass, gdVec2 _position, gdVec2 _linearVelocity, gdVec2 _acceleration)
{
	mass = _mass;
	position = _position;
	linearVelocity = _linearVelocity;
	acceleration = _acceleration;
}

void gdBody::ApplyForceToCentre(const gdVec2& force)
{
	//a = f/m
	gdVec2 temp(force);
	acceleration = temp / mass;
}
