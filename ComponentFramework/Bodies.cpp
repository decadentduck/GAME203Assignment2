#include "Bodies.h"

using namespace GAME;
using namespace MATH;

Bodies::Bodies(Vec3 pos, Vec3 rot, Vec3 scale_, Model *model_)
{
	position = pos;
	rotation = rot;
	scale = scale_;
	model = model_;
}

Bodies::Bodies() {}
Bodies::~Bodies()
{
}