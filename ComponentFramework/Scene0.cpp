#include <GL/glew.h>
#include <SDL.h>
#include "Scene0.h"
#include <iostream>
#include "MMath.h"
#include "QuadSphere.h"
#include "Model0.h"
#include "Trackball.h"

using namespace GAME;
using namespace MATH;

Scene0::Scene0(class Window& windowRef):  Scene(windowRef), model0(nullptr) 
{ 
	trackball = new Trackball();
	projectionMatrix.loadIdentity();
	viewMatrix.loadIdentity();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

Scene0::~Scene0()
{ 
	OnDestroy();
}

bool Scene0::OnCreate() 
{
	OnResize(windowPtr->GetWidth(),windowPtr->GetHeight());

	/// Load Assets: as needed 
	lightPos = Vec3(10.0f, 3.0f, 10.0f);
	model0 = new Model0();
	model0->SetVel(Vec3(0.0f,0.0f,0.0f));
	model0->SetPos(Vec3(0.0f,0.0f,0.0f));
	return true;
}


void Scene0::OnResize(int w_, int h_)
{
	windowPtr->SetWindowSize(w_,h_);
	glViewport(0,0,windowPtr->GetWidth(),windowPtr->GetHeight());
	float aspect = float(windowPtr->GetWidth()) / float(windowPtr->GetHeight());
	
	projectionMatrix = MMath::perspective(45.0f, aspect, 1.0f, 100.0f); //for the love of whatever you hold dear DO NOT CHANGE THIS... (yet)

	viewMatrix = MMath::lookAt(Vec3(0.0f, 0.0f, 10.0f), //(camera) pos
							   Vec3(0.0f, 0.0f, 0.0f),  // At (looking at this location)
							   Vec3(0.0f, 1.0f, 0.0f)); // where is up
}

void Scene0::OnDestroy()
{
	/// Cleanup Assets
	if(model0) delete model0;
	model0 = nullptr;
	if(trackball) delete trackball;
	trackball = nullptr;
}

void Scene0::Update(const float deltaTime)
{
	model0->Update(deltaTime);	
}

void Scene0::Render() const
{
	/// Draw your scene here
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	model0->SetLightPos(lightPos);
	model0->Render(projectionMatrix, viewMatrix * MMath::translate(0, 0, 0), Matrix3());
	SDL_GL_SwapWindow(windowPtr->getSDLWindow());
}

void Scene0::HandleEvents(const SDL_Event& SDLEvent)
{
	if(SDLEvent.type == SDL_EventType::SDL_MOUSEBUTTONDOWN)
	{
		trackball->OnLeftMouseDown(SDLEvent.button.x,SDLEvent.button.y);
	}
	if (SDLEvent.type == SDL_EventType::SDL_MOUSEMOTION && 
		SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) 
	{
		trackball->OnMouseMove(SDLEvent.button.x,SDLEvent.button.y);
	}
	
}