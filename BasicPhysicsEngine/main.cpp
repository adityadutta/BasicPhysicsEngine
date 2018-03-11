#include<iostream>
#include<fstream>
#include"World.h"

int main(int argc, char* args[])
{
	gdVec2 gravity(0.0, -9.8);				//variable to hold gravity
	gdVec2 windForce(0.0, 0.0);				//variable to hold wind force
	World* world = new World(gravity, windForce);	//instantiating new world with gravity and wind

	gdVec2 force(1000.0, 0.0);   //variable to hold force applied

	gdBody* body1 = new gdBody(2.0);	//instantiating gdBody object body 1
	gdBody* body2 = new gdBody(4.0);	//instantiating gdBody object body 2

	//setting body positions at 200.0 units on the y axis
	body1->position.Set(0.0, 200.0);
	body2->position.Set(0.0, 200.0);

	//pushing the each body in the list
	world->AddBody(body1);
	world->AddBody(body2);

	double timeStep = 0.1;				//timeStep to update the world

	//creating object of ofstream class
	std::ofstream outputFileStream;
	//opening output file
	outputFileStream.open("gravity.csv");

	//write values to output files
	outputFileStream << "Time (s), Position x 1 (m), Position y 1 (m), Position x 2 (m), Position y 2 (m)" << std::endl;

	//print the table in console
	std::cout << "Time (s)\tPosition x 1 (m)\tPosition y 1 (m)\tPosition x 2 (m)\tPosition y 2 (m)" << std::endl;

	//loop to simulate the bodies until they go below 0 in the y axis
	while (body1->position.y >= -1.0 && body2->position.y >= -1.0)
	{
		//applying a force in the first frame
		if (world->elapsedTime >= 0 && world->elapsedTime <= 0.1) {
			//for each loop to check each body in vector list
			for (auto body : world->bodies) {
				body->ApplyForceToCentre(force);
			}
			//setting force to zero
			force.SetZero();
		}

		//output in console
		std::cout << world->elapsedTime << "\t\t\t" << body1->position.x << "\t\t\t" << body1->position.y << "\t\t\t" << body2->position.x << "\t\t\t" << body2->position.y << std::endl;

		//output to file
		outputFileStream << world->elapsedTime << ", " << body1->position.x << ", " << body1->position.y << ", " << body2->position.x << ", " << body2->position.y << std::endl;

		//calling update function to run with a timeStep of 0.1s
		world->Update(timeStep);
	}

	//test 
	std::cout << "Output 1 in filename : gravity.csv " << std::endl;

	//close the output file
	outputFileStream.close();

	//----------------------------------------------------------GRAVITY WITH WIND----------------------------------------------------------------------------//
	force.Set(1000.0, 0.0);				//setting force to 1000N
	world->elapsedTime = 0.0;			//setting elapsed time to zero
	world->windForce.Set(-20.0, 0.0);	//setting wind force to -20N on the x axis
	for (auto body : world->bodies) {
		body->linearVelocity.SetZero();
		body->acceleration.SetZero();
		body->position.Set(0.0, 200.0);	//resetting the position of bodies
	}

	//opening output file
	outputFileStream.open("gravityWithWind.csv");

	//write values to output files
	outputFileStream << "Time (s), Position x 1 (m), Position y 1 (m), Position x 2 (m), Position y 2 (m)" << std::endl;

	//print the table in console
	std::cout << "\n\n//---------------------------------GRAVITY WITH WIND-----------------------------------------//\n\n\n";
	std::cout << "Time (s)\tPosition x 1 (m)\tPosition y 1 (m)\tPosition x 2 (m)\tPosition y 2 (m)" << std::endl;

	//loop to simulate the bodies until they go below 0 in the y axis
	while (body1->position.y > -1.0 && body2->position.y > -1.0)
	{
		//applying a force in the first frame
		if (world->elapsedTime >= 0 && world->elapsedTime <= 0.1) {
			//for each loop to check each body in vector list
			for (auto body : world->bodies) {
				body->ApplyForceToCentre(force);
			}
			//setting force to zero
			force.SetZero();
		}
		else if (world->elapsedTime > 0.1) {
			//looping through each body in list and applying the wind force
			for (auto body : world->bodies) {
				body->ApplyForceToCentre(world->windForce);
			}
		}

		//output in console
		std::cout << world->elapsedTime << "\t\t\t" << body1->position.x << "\t\t\t" << body1->position.y << "\t\t\t" << body2->position.x << "\t\t\t" << body2->position.y << std::endl;

		//output to file
		outputFileStream << world->elapsedTime << ", " << body1->position.x << ", " << body1->position.y << ", " << body2->position.x << ", " << body2->position.y << std::endl;

		//calling update function to run with a timeStep of 0.1s
		world->Update(timeStep);
	}

	//test 
	std::cout << "Output 2 in filename : gravityWithWind.csv" << std::endl;

	//close the output file
	outputFileStream.close();

	//delete world pointer and set it to null
	if (world) {
		delete world;
		world = nullptr;
	}

	getchar();
	return 0;
}