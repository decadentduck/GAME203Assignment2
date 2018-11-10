#ifndef _CAMERA_H
#define _CAMERA_H
#include "Entity.h"
#include "MMath.h"

namespace GAME {

	using namespace MATH;

	class Camera : public Entity 
	{
	private:
		Matrix4 projectionMatrix;
		Matrix4 viewMatrix;
		Vec3 at, up;
		void updateViewMatrix();
	public:
		static Camera* currentCamera;
		Camera(const int viewportWidth, const int viewportHeight, const Vec3 pos_);
		~Camera();
		Matrix4&  getProjectionMatrix();
		Matrix4&  getViewMatrix();
		void setPos(const Vec3& pos_);
		void setAt(const Vec3& at_);
		void setNormal(const Vec3& up_);
		void setCamera(const Vec3& eye_, const Vec3& at_, const Vec3& up_);
	};
}
#endif