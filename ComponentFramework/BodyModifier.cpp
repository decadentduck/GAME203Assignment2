#include "BodyModifier.h"
#include <math.h>

using namespace GAME;

BodyModifier::BodyModifier(Bodies &ParentBody_, Bodies &ChildBody_)
{
	/*Storing Positions of each Model
	for Reference to be used in the class */
	Parent->position = ParentBody_.position;
	Child->position = ChildBody_.position;

}

void BodyModifier::CalculateChildParameters()
{

	//Parent gets translated x coordinates.
		//Child then would move x coordinates
	//Parent is rotated x angle 
		//Child is rotated x angle locally

	NormalizedPosition = Parent->position /
		(
			sqrt
			(
				pow(Parent->position.x, 2) + pow(Parent->position.y, 2) + pow(Parent->position.z, 2)
			)
			);

	/*
	glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glPushMatrix(); // put current matrix on stack
//glTranslatef(0.0f, 0.0f, 0.0f);
//glTranslatef(-4*1.5, 0.0, 4*1.5);
glTranslatef(xpos, ypos, zpos);
glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f); // rotate the robot on its y-axis
DrawRobot(xpos, ypos, zpos); // draw the robot
glPopMatrix();
	*/

}

void BodyModifier::RotateBodies(Vec3 RotationDirection, float angle_)
{
	/*
	Translate Child Positions back to parent and have parent as origin
	Then Rotating the Child by the angle
	Translate Child back to original spot
	*/
	Child->position - Parent->position;
	glRotatef(angle_, RotationDirection.x, RotationDirection.y, RotationDirection.z);
	Child->position + Parent->position;
}

void BodyModifier::TranslateBodies(Vec3 Translation)
{
	Parent->position = Translation;
	Child->position = Translation;
}



BodyModifier::~BodyModifier()
{
}