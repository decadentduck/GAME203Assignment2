#ifndef BODYMODIFIER_H
#define BODYMODIFIER_H
#include "Bodies.h"
class BodyModifier 
{
	
private:
	Bodies Parent;
	Bodies Child;
	
public:
	BodyModifier(Bodies ParentBody, Bodies ChildBody);

	~BodyModifier();
	


};


#endif // ! BODYMODIFIER_H

/*
Body location , rotation,
Body 2 needs to know normal 

*/

