#ifndef BODIES_H
#define BODIES_H
#include "Model0.h"

class Bodies 
{
	friend class BodyModifier;
protected:
	Vec3 position;
	Vec3 rotationDirection;
	float rotationAngle;
	GAME::Model0 model; 
public:
	Bodies();
	~Bodies();
};
#endif // !BODIES_H


