#include "Scene3.h"

using namespace GAME;
using namespace MATH;

Scene3::Scene3(class Window& windowRef) : Scene(windowRef), model(nullptr)
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
	return true;
}


void Scene3::OnResize(int w_, int h_)
{

}

void Scene3::OnDestroy()
{
}

void Scene3::Update(const float deltaTime)
{

}

void Scene3::Render() const
{
}

void Scene3::HandleEvents(const SDL_Event& SDLEvent)
{
}