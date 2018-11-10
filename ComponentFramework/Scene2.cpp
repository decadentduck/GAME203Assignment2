#include "Scene2.h"
#include <GL/glew.h>
#include <SDL.h>
#include <iostream>
#include "MMath.h"
#include "Window.h"
#include "Shader.h"
#include "SceneEnvironment.h"
#include "Trackball.h"
#include "Model1.h"
#include "ObjLoader.h"
#include "Bodies.h"
using namespace GAME;
using namespace MATH;

Scene2::Scene2(class Window& windowRef) : Scene(windowRef)
{
	
	trackball = new Trackball();
	//projectionMatrix.loadIdentity();
	//viewMatrix.loadIdentity();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	//ProjectionMatrix:: close = 0.75f && far = 100.0f

}

Scene2::~Scene2()
{
	OnDestroy();
}

bool Scene2::OnCreate()
{
	/// Load Assets: as needed 
	if (addModel("Tree1.obj") == false) {
		return false;
	}
	if (addModel("Tree1.obj") == false) {
		return false;
	}
	eye = Vec3(0.0f, 3.0f, 10.0f);
	at = Vec3(0.0f, 0.0f, 0.0f);
	up = Vec3(0.0f, 1.0f, 0.0f);
	if (addReferenceModel("skull.obj",at) == false)
	{
		return false;
	}
	
	Vec3 pos = Vec3(0.0f, 0.0f, 0.0f);
	Vec3 rot = Vec3(0.0f, 0.0f, 0.0f);
	Vec3 vel = Vec3(0.0f, 0.0f, 0.0f);
	lightPos = Vec3(10.0f, 3.0f, 10.0f);

	/*Add Models*/

//	body = new Bodies(pos, rot, Vec3(1.0f, 1.0f,1.0f), models);
	SceneEnvironment::getInstance()->setLight(Vec3(0.0f, 3.0f, 7.0f));
	OnResize(windowPtr->getWidth(), windowPtr->getHeight());
	return true;
}


void Scene2::OnResize(int w_, int h_)
{
	//Updating Window Size
	windowPtr->setWindowSize(w_, h_);
	glViewport(0, 0, windowPtr->getWidth(), windowPtr->getHeight());
	//Updating Camera
	if (camera) delete camera;
	camera = new Camera(w_, h_, Vec3(0.0f, 0.0f, 10.0f));
	Camera::currentCamera = camera;
	Trackball::getInstance()->setWindowDimensions(windowPtr->getWidth(), windowPtr->getHeight());

	
}

void Scene2::OnDestroy()
{
	if (camera)
	{
		camera = nullptr;
		delete camera;
	}
	for (Model2* model : models) {
		if (model)
		{
			model = nullptr;
			delete model;
		}
	}
}

void Scene2::Update(const float deltaTime)
{
	for (Model2* model : models) {
		model->Update(deltaTime);
	}
	
	models[refNumber]->setPos(at);
	
	negativeRefPosition = eye - at;
	positiveRefPosition = eye - negativeRefPosition;
	
}

void Scene2::Render() const
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/// Draw your scene here
	for (Model2* model : models) {
		model->Render();
	}
	SDL_GL_SwapWindow(windowPtr->getSDLWindow());

}

void Scene2::HandleEvents(const SDL_Event& SDLEvent)
{
	if (SDLEvent.type == SDL_KEYDOWN)
	{
		switch (SDLEvent.key.keysym.sym)
		{
		case SDLK_w:
			eye = MMath::translate(0.0f, 0.0f, -1.0f) * eye;
			at = MMath::translate(0.0f, 0.0f, -1.0f) * at;
			
			break;
		case SDLK_s:
			eye = MMath::translate(0.0f, 0.0f, 1.0f) * eye;
			at = MMath::translate(0.0f, 0.0f, 1.0f) * at;
			
			break;
		case SDLK_a:
			eye = MMath::translate(-1.0f, 0.0f, 0.0f) * eye;
			at = MMath::translate(-1.0f, 0.0f, 0.0f) * at;
			
			break;
		case SDLK_d:
			eye = MMath::translate(1.0f, 0.0f, 0.0f) * eye;
			at = MMath::translate(1.0f, 0.0f, 0.0f) * at;
		
			break;
		case SDLK_UP:
			at = MMath::translate(0.0f, 0.0f, -1.0f) * at;
			
			break;
		case SDLK_DOWN:
			at = MMath::translate(0.0f, 0.0f, 1.0f) * at;
			
			break;
		case SDLK_LEFT:
			at = MMath::translate(-1.0f, 0.0f, 0.0f) * at;
			
			break;
		case SDLK_RIGHT:
			at = MMath::translate(1.0f, 0.0f, 0.0f) * at;
			
			break;
		default:
			break;
		}
		
		camera->SetCamera(eye, at, up);
		Camera::currentCamera = camera;
		printf("Camera: [%f,%f,%f][%f,%f,%f][%f,%f,%f]\n", eye.x, eye.y, eye.z, at.x, at.y, at.z, up.x, up.y, up.z);
		
		
	}
	if (SDLEvent.type == SDL_EventType::SDL_MOUSEBUTTONDOWN) {
		Trackball::getInstance()->onLeftMouseDown(SDLEvent.button.x, SDLEvent.button.y);
	}
	else if (SDLEvent.type == SDL_EventType::SDL_MOUSEBUTTONUP) {
		Trackball::getInstance()->onLeftMouseUp(SDLEvent.button.x, SDLEvent.button.y);
	}
	else if (SDLEvent.type == SDL_EventType::SDL_MOUSEMOTION &&
		SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
		Trackball::getInstance()->onMouseMove(SDLEvent.button.x, SDLEvent.button.y);
	}

}

bool GAME::Scene2::addModel(const char* filename)
{
	models.push_back(new Model2(Vec3(2.2f, 0.0f, 2.2f), Vec3(0.0f, 0.0f, 0.0f), 90.0f, 0.05f));
	models[models.size() - 1]->OnCreate();

	if (models[models.size() - 1]->LoadMesh(filename) == false) {
		return false;
	}
	return true;
}

bool GAME::Scene2::addReferenceModel(const char* filename, Vec3 at_)
{
	models.push_back(new Model2(at_, Vec3(0.0f, 0.0f, 0.0f), 90.0f, 0.05f));
	models[models.size() - 1]->OnCreate();
	refNumber = models.size() - 1;
	if (models[models.size() - 1]->LoadMesh(filename) == false) {
		return false;
	}
	return true;
}
