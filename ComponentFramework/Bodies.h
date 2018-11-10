#ifndef BODIES_H
#define BODIES_H
#include "Vector.h"
#include "Model2.h"
#include <vector>

namespace GAME
{
	class Bodies
	{
		friend class BodyModifier;
	private:
		Vec3 rotationDirection;
		float rotationAngle, scale;
		Vec3 position, rotation;
		std::vector<Model2*> models;
	public:
		
		Bodies(Vec3 pos_, Vec3 rot_, float scale_, std::vector<Model2*> models_);
		bool onCreate(const char* filename);
		bool onCreate(const char* filenames[]);
		void Update(float deltatime);
		void setPosition(Vec3 position_);
		void setRotation(Vec3 rotation_);
		void setScale(float scale_);
		Bodies();
		~Bodies();
	};
}

#endif // !BODIES_H
