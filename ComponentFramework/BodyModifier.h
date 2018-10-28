#ifndef BODYMODIFIER_H
#define BODYMODIFIER_H
#include "Bodies.h"
class BodyModifier 
{
	
private:
	Bodies Parent;
	Bodies Child;
	Vec3 NormalizedPosition, NormalizedRotation;

public:
	BodyModifier(Bodies ParentBody, Bodies ChildBody);
	void CalculateChildParameters();
	~BodyModifier();
	


};


#endif // ! BODYMODIFIER_H

/*
Body location , rotation,
Body 2 needs to know normal 

*/

