#include "Scene1.h"

using namespace GAME;
using namespace MATH;

Scene1::Scene1(class Window& windowRef) : Scene(windowRef), model(nullptr)
{
	trackball = new Trackball();
	projectionMatrix.loadIdentity();
	viewMatrix.loadIdentity();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

Scene1::~Scene1()
{
	OnDestroy();
}

bool Scene1::OnCreate()
{
	
	return true;
}


void Scene1::OnResize(int w_, int h_)
{

}

void Scene1::OnDestroy()
{
}

void Scene1::Update(const float deltaTime)
{

}

void Scene1::Render() const
{
}

void Scene1::HandleEvents(const SDL_Event& SDLEvent)
{
}