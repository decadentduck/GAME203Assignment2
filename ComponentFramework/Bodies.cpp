#include "Bodies.h"

using namespace GAME;
using namespace MATH;

Bodies::Bodies(Vec3 pos, Vec3 rot, float scale_, std::vector<Model2*> models_)
{
	position = pos;
	rotation = rot;
	scale = scale_;
	
	models = models_;
}

void GAME::Bodies::setPosition(Vec3 position_)
{
	position = position_;
	for (Model2* model : models)
	{
		model->setPos(position);
	}
}

void GAME::Bodies::setRotation(Vec3 rotation_)
{
	rotation = rotation_;
	for (Model2* model : models)
	{
		model->setOrientation(position);
	}
}

void GAME::Bodies::setScale(float scale_)
{
	scale = scale_;
	for (Model2* model : models)
	{
		model->setScale(scale);
	}
}

Bodies::Bodies() {}
Bodies::~Bodies()
{
}