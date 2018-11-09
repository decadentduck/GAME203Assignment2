#include "Scene3.h"
#include "ModelTree.h"
#include "Camera.h"

using namespace GAME;
using namespace MATH;

Scene3::Scene3(class Window& windowRef) : Scene(windowRef)
{
	trackball = new Trackball();
	projectionMatrix.loadIdentity();
	viewMatrix.loadIdentity();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

Scene3::~Scene3()
{
	OnDestroy();
}

bool Scene3::OnCreate()
{
	lightPos = Vec3(10.0f, 3.0f, 10.0f);
	CreateForest();

	eye = Vec3(0.0f, 3.0f, 10.0f);
	at = Vec3(0.0f, 0.0f, 0.0f);
	up = Vec3(0.0f, 1.0f, 0.0f);
	Camera::GetInstance()->SetLookAt(eye, at, up);
	return true;
}

void Scene3::CreateForest()
{
	Model *m = new ModelTree;
	Vec3 pos = Vec3(0.0f, 0.0f, 0.0f);
	Vec3 rot = Vec3(0.0f, 0.0f, 0.0f);
	Vec3 vel = Vec3(0.0f, 0.0f, 0.0f);
	m->SetVel(vel);
	m->SetPos(pos);
	bodies[0] = new Bodies(pos, rot, Vec3(1.0f, 1.0f, 1.0f), m);

	//TODO fill trees array with trees

	//random pos, rotat, model(from a few choices)
	//maybe scale....
}

void Scene3::OnResize(int w_, int h_)
{
	windowPtr->SetWindowSize(w_, h_);
	glViewport(0, 0, windowPtr->GetWidth(), windowPtr->GetHeight());
	float aspect = float(windowPtr->GetWidth()) / float(windowPtr->GetHeight());

	projectionMatrix = MMath::perspective(45.0f, aspect, 1.0f, 100.0f);

	viewMatrix = MMath::lookAt(
		Vec3(0.0f, 0.0f, 10.0f),
		Vec3(0.0f, 0.0f, 0.0f),
		Vec3(0.0f, 1.0f, 0.0f));
}

void Scene3::OnDestroy()
{
	//TODO delete trees array	
}

void Scene3::Update(const float deltaTime)
{
	//TODO camera position via handle events
}

void Scene3::Render() const
{
	//TODO Draw the trees in array
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	bodies[0]->model->SetLightPos(lightPos);
	bodies[0]->model->Render(Camera::GetInstance()->GetProjection(), Camera::GetInstance()->GetView(), Matrix3());
	SDL_GL_SwapWindow(windowPtr->getSDLWindow());
}

void Scene3::HandleEvents(const SDL_Event& SDLEvent)
{
	//Handle camera via keyboard input
	if (SDLEvent.type == SDL_KEYUP)
	{
		switch (SDLEvent.key.keysym.sym)
		{
		case SDLK_UP:
			eye = MMath::translate(0.0f, 0.0f, -1.0f) * eye;
			Camera::GetInstance()->SetLookAt(eye, at, up);
			break;
		case SDLK_DOWN:
			eye = MMath::translate(0.0f, 0.0f, 1.0f) * eye;
			Camera::GetInstance()->SetLookAt(eye, at, up);
			break;
		case SDLK_LEFT:
			at = MMath::translate(-1.0f, 0.0f, 0.0f) * at;
			Camera::GetInstance()->SetLookAt(eye, at, up);
			break;
		case SDLK_RIGHT:
			at = MMath::translate(1.0f, 0.0f, 0.0f) * at;
			Camera::GetInstance()->SetLookAt(eye, at, up);
			break;
		default:
			break;
		}
	}
}