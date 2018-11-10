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
	at = Vec3(0.0f, 0.0f, 0.0f);
	up = Vec3(0.0f, 1.0f, 0.0f);
	camera = nullptr;

	/// Load Assets: as needed 
	if (addModel("Tree1.obj") == false) { return false; }

	CreateForest();

	/// Create a shader with attributes
	SceneEnvironment::getInstance()->setLight(Vec3(0.0f, 3.0f, 7.0f));

	OnResize(windowPtr->getWidth(), windowPtr->getHeight());
	return true;
}

void Scene3::CreateForest()
{
	for (int i = 0; i < 10; i++) { addModel("Tree1.obj"); }
}

bool GAME::Scene3::addModel(const char* filename)
{
	

	Vec3 pos = Vec3(Random(1, 10), 0, Random(1, 10));
	float rot = 0;// Random(1, 360);
	float scale = 0.05f;
	models.push_back(new Model(pos, Vec3(0.0f, 0.0f, 0.0f), rot, scale));
	models[models.size() - 1]->OnCreate();

	if (models[models.size() - 1]->LoadMesh(filename) == false) 
	{
		return false;
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
	if (SDLEvent.type == SDL_KEYUP)
	{
		printf("KEYPRESS\n");
		switch (SDLEvent.key.keysym.sym)
		{
		case SDLK_UP:
			eye = MMath::translate(0.0f, 0.0f, -1.0f) * eye;
			break;
		case SDLK_DOWN:
			eye = MMath::translate(0.0f, 0.0f, 1.0f) * eye;
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
	}
}

float Scene3::Random(float min, float max)
{
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);
	return(dist(rng));
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
