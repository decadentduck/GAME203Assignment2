#ifndef BODIES_H
#define BODIES_H
#include "Vector.h"
#include "Model.h"

namespace GAME
{
	class Bodies
	{
		friend class BodyModifier;
	protected:
		Vec3 rotationDirection;
		float rotationAngle;

	public:
		Vec3 position, rotation;
		Model *model;
		Bodies(Vec3 pos, Vec3 rot, Model *model_);
		Bodies();
		~Bodies();
	};
}

#endif // !BODIES_H


