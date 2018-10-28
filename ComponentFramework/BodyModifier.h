#ifndef BODYMODIFIER_H
#define BODYMODIFIER_H
#include "Bodies.h"
class BodyModifier 
{
	
private:
	Bodies ParentBody;
	Bodies ChildBody;
	Vec3 ParentLocation;
	Vec3 ParentRotation;
	Vec3 ChildLocation;
	Vec3 ChildRotation;
public:
	BodyModifier(Bodies ParentBody, Bodies ChildBody);

	~BodyModifier();
	


};


#endif // ! BODYMODIFIER_H

/*
Body location , rotation,
Body 2 needs to know normal 

*/

