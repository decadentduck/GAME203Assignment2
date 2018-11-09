
#ifndef _ENTITY_H
#define _ENTITY_H

#include "VMath.h"

namespace GAME {

	using namespace MATH;

	class Entity {

	protected:

		Vec3 pos;					/// of just the data in the PhysicsModel
		Vec3 at;			/// based on Euler angles
		Vec3 normal;


	public:

		Entity() {};
		virtual ~Entity() {};

		virtual void setPos(const Vec3& pos_) { pos = pos_; }
		virtual void setCamera(const Vec3& eye_, const Vec3& at_, const Vec3& up_) { pos = eye_; at = at_; normal = up_; }
		virtual void setAt(const Vec3& at_) { at = at_; }
		virtual void setNormal(const Vec3& normal_) { normal = normal_; }
		virtual void Translate(const Vec3& vec) { setPos(pos + vec); }
		
	
	};
}

#endif