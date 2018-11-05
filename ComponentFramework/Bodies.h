#ifndef BODIES_H
#define BODIES_H
#include "Model0.h"

class Model0;
class Bodies 
{
	friend class BodyModifier;
protected:
	Vec3 position;
<<<<<<< HEAD
	Vec3 rotationDirection;
	float rotationAngle;
	GAME::Model0 model; 
=======
	Vec3 rotation;
	Model0 *model;
>>>>>>> fc52593aa6a4719842114f4017795b2c59af2d67
public:
	Bodies(Vec3 pos, Vec3 rot, Model0* m);
	Bodies();
	~Bodies();
};
#endif // !BODIES_H


