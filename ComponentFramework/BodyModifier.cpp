#include "BodyModifier.h"
#include <math.h>

using namespace GAME;

BodyModifier::BodyModifier(Bodies &ParentBody_, std::vector<Bodies> &ChildrenBodies_)
{
	/*Storing Positions of each Model
	for Reference to be used in the class */
	*Parent = ParentBody_;
	*Children = ChildrenBodies_;

	ParentMatrix = Parent->model->modelMatrix;
	for (std::vector<Bodies>::iterator i = Children->begin(); i < Children->end(); i++)
	{
		//Oh man this looks UGLY!
		//Grabs the Matrix
		ChildMatrix.push_back(Children->back().model->modelMatrix);

	}//end for (std::vector<Bodies>::iterator i = Children->begin(); i < Children->end(); i++)

}

void BodyModifier::TranslateBodies(MATH::Matrix4 Translation_)
{
	/*
	To
	Translate Child Positions back to parent and have parent as origin
	Then Rotating the Child by the angle
	Translate Child back to original spot
	*/

	//Matrix Multiplication is read from right to left
	//Order Matters
	ParentMatrix = Translation_ * ParentMatrix;
	Parent->model->modelMatrix = ParentMatrix;
	/*Apply Translation_ to Children*/
	for (std::vector<Bodies>::iterator i = Children->begin(); i < Children->end(); i++)
	{
		//Grabs the Matrix
		ChildMatrix.back() = Translation_ * ChildMatrix.back();
		Children->end()->model->modelMatrix = ChildMatrix.back();

		//Consider Removing and Changing ORDER OF REMOVING STACKS??
		//Takes off the stack
		ChildMatrix.pop_back();

	}//end for (std::vector<Bodies>::iterator i = Children->begin(); i < Children->end(); i++)



}

//glRotatef(angle_, RotationDirection.x, RotationDirection.y, RotationDirection.z);



BodyModifier::~BodyModifier()
{
}