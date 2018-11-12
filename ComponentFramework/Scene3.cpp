#include <GL/glew.h>
#include <SDL.h>
#include <iostream>
#include "MMath.h"
#include "Window.h"
#include <random>
#include "Shader.h"
#include "Scene3.h"
#include "SceneEnvironment.h"
#include "Trackball.h"
#include "Model1.h"
#include "ObjLoader.h"

using namespace GAME;
using namespace MATH;


Scene3::Scene3(Window& windowRef) :Scene(windowRef) { }


bool Scene3::OnCreate()
{
	eye = Vec3(0.0f, 0.0f, 10.0f);
	at = Vec3(0.0f, 0.0f, -1.0f);
	up = Vec3(0.0f, 1.0f, 0.0f);
	camera = nullptr;

	if (!addModel("Plane1.obj")) return false;

	CreateForest();

	/// Create a shader with attributes
	SceneEnvironment::getInstance()->setLight(Vec3(0.0f, 10.0f, 0.0f));

	OnResize(windowPtr->getWidth(), windowPtr->getHeight());
	return true;
}

bool Scene3::CreateForest()
{
	for (int i = 0; i < 50; i++) 
	{ 
		int tree = r.rand(1, 4);
		if (tree == 1) 
		{
			if(!addModel("Tree2.obj")) return false; 
		}
		else
		{
			if (!addModel("Tree1.obj")) return false;
		}
	}
	return true;
}

bool GAME::Scene3::addModel(const char* filename)
{
	if (filename == "Plane1.obj")
	{
		models.push_back(new Model(Vec3(6.0f, 28.0f, 2.0f), Vec3(0.0f, 0.0f, 0.0f), 0.0f, Vec3(2.0f, 1.0f, 2.0f)));
		models[models.size() - 1]->OnCreate();

		if (models[models.size() - 1]->LoadMesh(filename) == false)
		{
			return false;
		}
	}
	else
	{
		Vec3 pos = Vec3(r.rand(1.0, 250.0) - 125.0f, 0, r.rand(1.0, 250.0) - 125.0f);
		if (filename == "Tree2.obj") pos.y -= 10.0f;
		float rot = r.rand(1, 360);
		pos.print();
		Vec3 scale = Vec3(r.rand(0.05, 0.06), r.rand(0.04, 0.07), r.rand(0.05, 0.06));
		models.push_back(new Model(pos, Vec3(0.0f, 0.0f, 0.0f), rot, scale));
		models[models.size() - 1]->OnCreate();

		if (models[models.size() - 1]->LoadMesh(filename) == false)
		{
			return false;
		}
	}
	
	return true;
}

void Scene3::OnResize(int w_, int h_) 
{
	windowPtr->setWindowSize(w_, h_);
	glViewport(0, 0, windowPtr->getWidth(), windowPtr->getHeight());
	if (camera) delete camera;
	camera = new Camera(w_, h_, Vec3(0.0f, 0.0f, 10.0f));
	camera->SetCamera(eye, at, up);
	Camera::currentCamera = camera;
}

void Scene3::Update(const float deltaTime) 
{
	for (Model* model : models) { model->Update(deltaTime); }
}

void Scene3::Render() const 
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/// Draw your scene here
	for (Model* model : models) { model->Render(); }
	SDL_GL_SwapWindow(windowPtr->getSDLWindow());
}

void Scene3::HandleEvents(const SDL_Event& SDLEvent) 
{
	//Handle camera via keyboard input
	if (SDLEvent.type == SDL_KEYDOWN)
	{
		printf("KEYPRESS\n");
		switch (SDLEvent.key.keysym.sym)
		{
		case SDLK_UP:
			eye = MMath::translate(0.0f, 0.0f, -1.0f) * eye;
			at = MMath::translate(0.0f, 0.0f, -1.0f) * at;
			break;
		case SDLK_DOWN:
			eye = MMath::translate(0.0f, 0.0f, 1.0f) * eye;
			at = MMath::translate(0.0f, 0.0f, 1.0f) * at;
			break;
		case SDLK_LEFT:
			at = at - eye;
			at = MMath::rotate(5, 0.0f, 1.0f, 0.0f) * at;
			at = at + eye;
			break;
		case SDLK_RIGHT:
			at = at - eye;
			at = MMath::rotate(-5, 0.0f, 1.0f, 0.0f) * at;
			at = at + eye;
			break;
		default:
			break;
		}
		camera->SetCamera(eye, at, up);
		eye.print();
		at.print();
		up.print();
		Camera::currentCamera = camera;
	}
}

Scene3::~Scene3()
{
	OnDestroy();
}

void Scene3::OnDestroy()
{
	/// Cleanup Assets
	if (camera)
	{
		camera = nullptr;
		delete camera;
	}
	for (Model* model : models)
	{
		if (model)
		{
			model = nullptr;
			delete model;
		}
	}
}
