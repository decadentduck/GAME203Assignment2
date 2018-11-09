#ifndef BODYMODIFIER_H
#define BODYMODIFIER_H
#include "Bodies.h"
#include <memory>
#include "Vector.h"
#include <vector>

namespace GAME
{
	class BodyModifier
	{
		template<class T, class U>
		std::unique_ptr<T> make_unique(U&& u) {
			return std::unique_ptr<T>(new T(std::forward<U>(u)));
		}

	private:
		std::unique_ptr<Bodies> Parent;
		std::unique_ptr<std::vector<Bodies>> Children;
		//std::unique_ptr<Bodies> Child;

		Vec3 NormalizedPosition;

	public:

		MATH::Matrix4 ParentMatrix;
		std::vector<MATH::Matrix4> ChildMatrix;

		BodyModifier(Bodies &ParentBody_, std::vector<Bodies> &ChildrenBodies_);
		void CalculateChildParameters();
		void TranslateBodies(MATH::Matrix4 translation_);
		void RotateBodies(MATH::Matrix4 rotation_, float angle_);
		void TranslateBodies(Vec3 Translation);
		~BodyModifier();

	};
}

#endif // ! BODYMODIFIER_H

/*
Body location , rotation,
Body 2 needs to know normal
*/
