#include "Camera.h"

Camera* Camera::instance = nullptr;

Camera* Camera::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new Camera();
	}
	return instance;
}


Camera::Camera()
{
	fovy = 45.0f;
	aspect = 1.0f;
	near = 1.0f;
	far = 100.0f;

	Projection = MMath::perspective(fovy, aspect, near, far);

	View = MMath::lookAt(Vec3(0.0f, 0.0f, 10.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 1.0f, 0.0f));

}

void Camera::SetPerspective(float fovy_, float aspect_, float near_, float far_)
{
	Projection = MMath::perspective(fovy_, aspect_, near_, far_);
}

void Camera::SetLookAt(Vec3 eye, Vec3 at, Vec3 up)
{
	View = MMath::lookAt(eye, at, up);
}

Camera::~Camera()
{
}

Matrix4 Camera::GetProjection()
{
	return Projection;
}

Matrix4 Camera::GetView()
{
	return View;
}