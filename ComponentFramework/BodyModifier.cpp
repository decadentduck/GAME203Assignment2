#include "BodyModifier.h"
#include <math.h>



BodyModifier::BodyModifier(Bodies ParentBody_, Bodies ChildBody_)
{
	Parent = ParentBody_;
    Child= ChildBody_;
	
}

void BodyModifier::CalculateChildParameters()
{

	//Parent gets translated x coordinates.
		//Child then would move x coordinates
	//Parent is rotated x angle 
		//Child is rotated x angle locally

	NormalizedPosition = Parent.position / 
		(
			sqrt
			(
				pow(Parent.position.x, 2) + pow(Parent.position.y, 2) + pow(Parent.position.z, 2)
			)
		);
	NormalizedRotation = Parent.rotation /
		(
			sqrt
			(
				pow(Parent.rotation.x,2) + pow(Parent.rotation.y,2) + pow(Parent.rotation.z,2)
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


BodyModifier::~BodyModifier()
{
}
