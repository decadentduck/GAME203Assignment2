#include "Scene3.h"

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
	
	CreateForest();

	return true;
}

void Scene3::CreateForest()
{
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

	viewMatrix = MMath::lookAt(Vec3(0.0f, 0.0f, 10.0f),
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
}

void Scene3::HandleEvents(const SDL_Event& SDLEvent)
{
	//TODO Handle camera via keyboard input
}