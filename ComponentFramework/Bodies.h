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
		Vec3 position, rotation, scale;
		Model *model;
		Bodies(Vec3 pos, Vec3 rot, Vec3 scale_, Model *model_);
		Bodies();
		~Bodies();
	};
}

#endif // !BODIES_H
