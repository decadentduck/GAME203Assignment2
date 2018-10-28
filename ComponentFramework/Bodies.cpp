#include "Bodies.h"

Bodies::Bodies(Vec3 pos, Vec3 rot, Model0* m)
{
	position = pos;
	rotation = rot;
	model = m;
}

Bodies::Bodies() {}
Bodies::~Bodies()
{
}
