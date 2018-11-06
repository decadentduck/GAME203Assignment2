#ifndef BODYMODIFIER_H
#define BODYMODIFIER_H
#include "Bodies.h"
#include <memory>
class BodyModifier 
{
	template<class T, class U>
	std::unique_ptr<T> make_unique(U&& u) {
		return std::unique_ptr<T>(new T(std::forward<U>(u)));
	}
	
private:
	std::unique_ptr<Bodies> Parent;
	std::shared_ptr<Bodies> Children[10];
	
	Vec3 NormalizedPosition;

public:
	BodyModifier(Bodies &ParentBody, Bodies ChildrenBody[]);
	void CalculateChildParameters();
	void RotateBodies(Vec3 RotationDirection, float angle_);
	void TranslateBodies(Vec3 Translation);
	~BodyModifier();
	


};


#endif // ! BODYMODIFIER_H

/*
Body location , rotation,
Body 2 needs to know normal 

*/

