#include "Scene3.h"
#include "Model0.h"

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

	return true;
}

void Scene3::CreateForest()
{
	Model *m = new Model0;
	Vec3 pos = Vec3(0.0f, 0.0f, 0.0f);
	Vec3 rot = Vec3(0.0f, 0.0f, 0.0f);
	Vec3 vel = Vec3(0.0f, 0.0f, 0.0f);
	m->SetVel(vel);
	m->SetPos(pos);
	bodies[0] = new Bodies(pos, rot, m);

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
	bodies[0]->model->Render(projectionMatrix, viewMatrix * MMath::translate(0, 0, -1), Matrix3());
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
			viewMatrix = viewMatrix * MMath::translate(0, 0, -0.1);
			break;
		case SDLK_DOWN:
			viewMatrix = viewMatrix * MMath::translate(0, 0, 0.1);
			break;
		case SDLK_LEFT:
			viewMatrix = viewMatrix * MMath::rotate(5, 0, 1, 0);
			break;
		case SDLK_RIGHT:
			viewMatrix = viewMatrix * MMath::rotate(-5, 0, 1, 0);
			break;
		default:
			break;
		}
	}
}