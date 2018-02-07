#include<iostream>
#include<fstream>
#include"gdVec2.h"
#include"gdBody.h"

int main()
{

	gdVec2 force(500.0, 0.0);   //variable to hold force applied

	double mass = 200.0;		//mass of object
	gdVec2 acceleration;	//initial acceleration
	gdVec2 linearVelocity;//initial velocity
	gdVec2 position;		//initial position

	gdBody jetSki(mass, position, linearVelocity, acceleration);	//instatiating gdBody object jetski

	//creating object of ofstream class
	std::ofstream outputFileStream;
	//opening output file
	outputFileStream.open("table.csv");

	//write values to output files
	outputFileStream << "Time (s), Force (N), Accel. (m/s2), Velocity (m/s), Position (m)" << std::endl;

	//print the table in console
	std::cout << "Time (s)\tForce (N)\tAccel. (m/s2)\tVelocity (m/s)\tPosition (m)" << std::endl;

	//loop to simulate the jetSkis' motion for 15 seconds
	for (double currentTime = 0.0; currentTime <= 15.0; currentTime += 0.5)
	{
		//applying a force of 500N at t=0s
	    if (currentTime >= 0 && currentTime < 5.5)
		{
			jetSki.ApplyForceToCentre(force);
		}
		//applying a force of 0N at t=5.5s
		else if (currentTime >= 5.5 && currentTime < 10)
		{
			force.Set(0.0, 0.0);
			jetSki.ApplyForceToCentre(force);
		}
		//applying a force of -625N at  t=10s
		else if (currentTime >= 10) 
		{
			force.Set(-625.0, 0.0);
			jetSki.ApplyForceToCentre(force);
		}
		if (jetSki.linearVelocity.x <= 0.0 && currentTime >= 10) {
			force.SetZero();
			jetSki.ApplyForceToCentre(force);
		}

		//output in console
		std::cout << currentTime << "\t\t" << force.x << "\t\t" << jetSki.acceleration.x << "\t\t" << jetSki.linearVelocity.x << "\t\t" << jetSki.position.x << std::endl;

		//output to file
		outputFileStream << currentTime << ", " << force.x << ", " << jetSki.acceleration.x << ", " << jetSki.linearVelocity.x << ", " << jetSki.position.x << std::endl;

		//calling update function to run with a timeStamp of 0.5s
		jetSki.Update(0.5);
	}
	//close the output file
	outputFileStream.close();

	getchar();
	return 0;
}