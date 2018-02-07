#include "gdBody.h"

//constructor to pass values in the class
gdBody::gdBody(double _mass, gdVec2 _position, gdVec2 _linearVelocity, gdVec2 _acceleration)
{
	mass = _mass;
	position = _position;
	linearVelocity = _linearVelocity;
	acceleration = _acceleration;
}

void gdBody::Update(double timeStep)
{
	//Update velocity from acceleration times timeStep
	//v = v(init) + a * time;
	//linearVelocity = linearVelocity * acceleration;
	//acceleration *= timeStep;
	linearVelocity += acceleration * timeStep;

	//Update position from velocity times timeStep
	//position = position(init) + linearVelocity * time + 0.5f * acceleration * time ^2
	position += linearVelocity * timeStep + acceleration * 0.5f * timeStep * timeStep;
}

void gdBody::ApplyForceToCentre(const gdVec2& force)
{
	//a = f/m
	gdVec2 temp(force);
	acceleration = temp / mass;
}
