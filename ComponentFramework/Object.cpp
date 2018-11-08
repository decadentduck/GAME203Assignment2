#include "Object.h"



Object::Object(std::string name_, float pX, float pY, float pZ, float rX, float rY, float rZ)
{
	name = name_;
	posX = pX;
	posY = pY;
	posZ = pZ;
	rotX = rX;
	rotY = rY;
	rotZ = rZ;
}


Object::~Object()
{
}
