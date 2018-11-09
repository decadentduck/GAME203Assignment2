#include "Camera.h"

namespace GAME {

	Camera* Camera::currentCamera = nullptr;

	Camera::Camera(const int viewportWidth, const int viewportHeight, const Vec3 pos_)
	{
		pos = pos_;
		
		at = Vec3(0.0f, 0.0f, 0.0f);
		normal = Vec3(0.0f, 1.0f, 0.0f);
		float aspect = float(viewportWidth) / float(viewportHeight);
		projectionMatrix = MMath::perspective(45.0f, aspect, 0.75f, 100.0f);
		updateViewMatrix();
	}

	Camera::~Camera() {}

	void Camera::updateViewMatrix(){
		
		viewMatrix = MMath::lookAt(pos, at, normal);

	}

	Matrix4&  Camera::getProjectionMatrix() {
		return projectionMatrix;
	}


	Matrix4&  Camera::getViewMatrix(){
		return viewMatrix;
	}

	void Camera::setPos(const Vec3& pos_){
		Entity::setPos(pos_);
		updateViewMatrix();
	}
	void Camera::setCamera(const Vec3& eye_, const Vec3& at_, const Vec3& up_)
	{
		pos = eye_;
		at = at_;
		normal = up_;
		updateViewMatrix();
	}
	void Camera::setAt(const Vec3& at_){
		Entity::setAt(at_);
		updateViewMatrix();
	}
	void Camera::setNormal(const Vec3& up_)
	{
		Entity::setNormal(up_);
		updateViewMatrix();
	}

}