#ifndef BODIES_H
#define BODIES_H
#include "Model0.h"

class Model0;
class Bodies 
{
	friend class BodyModifier;
protected:
	Vec3 position;

	Vec3 rotationDirection;
	float rotationAngle;
	

	Vec3 rotation;
	

public:
	Bodies(Vec3 pos, Vec3 rot);
	Bodies();
	~Bodies();
};
#endif // !BODIES_H


