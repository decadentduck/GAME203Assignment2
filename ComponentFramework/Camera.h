#ifndef _CAMERA_H
#define _CAMERA_H

#include "Entity.h"
#include "MMath.h"

namespace GAME {

	using namespace MATH;

	class Camera : public Entity {

	private:
		Matrix4 projectionMatrix;
		Matrix4 viewMatrix;
		Vec3 eye, at, up;

	private:
		void updateViewMatrix();

	public:

		static Camera* currentCamera;

		Camera(const int viewportWidth, const int viewportHeight, const Vec3 pos_);
		~Camera();

		Matrix4&  getProjectionMatrix();
		Matrix4&  getViewMatrix();

		void setPos(const Vec3& pos_) override;
		void setPos(const Vec3& eye_, const Vec3& at_, const Vec3& up_);
		void setOrientation(const Vec3& orienration_) override;



	};

}
#endif