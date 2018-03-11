#ifndef GDBODY_H
#define GDBODY_H

#include"gdVec2.h"
class gdBody
{

public:
	double mass;									//variable to hold the value of mass
	gdVec2 position;								//variable to hold the value of position
	gdVec2 linearVelocity;							//variable to hold the value of velocity
	gdVec2 acceleration;							//variable to hold the value of acceleration

	gdBody(double _mass);
	gdBody(double _mass, gdVec2 _position, gdVec2 _linearVelocity, gdVec2 _acceleration);
	void ApplyForceToCentre(const gdVec2& force);   // update acceleration using a = F/m

};
#endif //!GDBODY_H