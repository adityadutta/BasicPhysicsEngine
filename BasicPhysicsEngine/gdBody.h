#ifndef GDBODY_H
#define GDBODY_H

#include"gdVec2.h"
class gdBody
{

public:
	double mass;
	gdVec2 position;
	gdVec2 linearVelocity;
	gdVec2 acceleration;

	gdBody(double _mass, gdVec2 _position, gdVec2 _linearVelocity, gdVec2 _acceleration);
	void Update(double timeStep);					// update position and velocity using equations of motion
	void ApplyForceToCentre(const gdVec2& force);   // update acceleration using a = F/m

};
#endif //!GDBODY_H