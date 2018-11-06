#include "Scene2.h"

using namespace GAME;
using namespace MATH;

Scene2::Scene2(class Window& windowRef) : Scene(windowRef), model(nullptr)
{
	trackball = new Trackball();
	projectionMatrix.loadIdentity();
	viewMatrix.loadIdentity();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

Scene2::~Scene2()
{
	OnDestroy();
}

bool Scene2::OnCreate()
{

	return true;
}


void Scene2::OnResize(int w_, int h_)
{

}

void Scene2::OnDestroy()
{
}

void Scene2::Update(const float deltaTime)
{

}

void Scene2::Render() const
{
}

void Scene2::HandleEvents(const SDL_Event& SDLEvent)
{
}