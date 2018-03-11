#include "World.h"


World::World(gdVec2& initialGravityAcceleration, gdVec2& initialWindForce)
{
	gravityAcceleration = initialGravityAcceleration;
	windForce = initialWindForce;
}

void World::Update(double timeStep)
{
	for (auto body : bodies) {

		//Update position from velocity times timeStep
		//position = position(init) + linearVelocity * time + 0.5 * acceleration * time ^2
		body->position += body->linearVelocity * timeStep + (body->acceleration + gravityAcceleration) * 0.5 * timeStep * timeStep;

		//Update velocity from acceleration times timeStep
		//linearVelocity = linearVelocity(init) + acceleration * time;
		body->linearVelocity += (body->acceleration + gravityAcceleration) * timeStep;

		//setting acceleration to zero
		body->acceleration.SetZero();
	}

	//update elapsed time by time step
	elapsedTime += timeStep;
}

void World::AddBody(gdBody* body)
{
	bodies.push_back(body);
}

World::~World()
{
	for (auto body : bodies) {
		delete body;
		body = nullptr;
	}
}
