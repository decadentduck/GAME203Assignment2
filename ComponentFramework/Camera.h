#ifndef CAMERA_H
#define CAMERA_H
#include "MMath.h"

using namespace MATH;

class Camera
{
public:
	~Camera();
	static Camera* GetInstance();
	Matrix4 GetProjection();
	Matrix4 GetView();
	void SetPerspective(float fovy_, float aspect_, float near_, float far_);
	void SetLookAt(Vec3 eye, Vec3 at, Vec3 up);
private:
	Camera();
	static Camera *instance;
	Matrix4 Projection;
	Matrix4 View;
	float aspect, fovy, near, far;
};

#endif