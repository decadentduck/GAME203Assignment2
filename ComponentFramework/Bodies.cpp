#include "Bodies.h"

using namespace GAME;
using namespace MATH;

Bodies::Bodies(Vec3 pos, Vec3 rot, Model *model_)
{
	position = pos;
	rotation = rot;
	model = model_;
}

Bodies::Bodies() {}
Bodies::~Bodies()
{
}