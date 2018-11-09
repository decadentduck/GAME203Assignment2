#include "Camera.h"

namespace GAME {

	Camera* Camera::currentCamera = nullptr;

	Camera::Camera(const int viewportWidth, const int viewportHeight, const Vec3 pos_)
	{
		pos = pos_;
		orientation = Vec3(0.0f, 0.0f, 0.0f);
		normal = Vec3(0.0f, 1.0f, 0.0f);
		float aspect = float(viewportWidth) / float(viewportHeight);
		projectionMatrix = MMath::perspective(45.0f, aspect, 0.75f, 100.0f);
		updateViewMatrix();
	}

	Camera::~Camera() {}

	void Camera::updateViewMatrix(){
		viewMatrix = MMath::lookAt
		(
			pos, //Position
			orientation, //At Allows Rotation to look left, up, down, and right 
			normal //Which way is up?
		);
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

	void Camera::setOrientation(const Vec3& orientation_){
		Entity::setOrientation(orientation_);
		updateViewMatrix();
	}
	void Camera::setNormal(const Vec3& normal_)
	{
		Entity::setNormal(normal_);
		updateViewMatrix();
	}

}