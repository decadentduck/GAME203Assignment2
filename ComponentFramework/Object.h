#ifndef OBJECT_H
#define OBJECT_H
#include <string>

class Object
{
public:
	std::string name;
	float posX, posY, posZ, rotX, rotY, rotZ;
	Object(std::string name_, float pX, float pY, float pZ, float rX, float rY, float rZ);
	~Object();
};
#endif 
