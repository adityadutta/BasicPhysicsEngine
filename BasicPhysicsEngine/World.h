#ifndef WORLD_H
#define WORLD_H
#include"gdBody.h"
#include<vector>

class World
{
public:
	std::vector<gdBody*> bodies;										// A vector list of Body pointers
	double elapsedTime;
	gdVec2 gravityAcceleration;
	gdVec2 windForce;


	World(gdVec2& initialGravityAcceleration, gdVec2& initialWindForce); // The constructor
	~World();															 // The destructor. Delete the Body pointers
	void Update(double timeStep);										 // Update all the bodies
	void AddBody(gdBody* body);											 // Add a Body pointer to the vector list of bodies
};

#endif //!WORLD_H

