#include <GL/glew.h>
#include <SDL.h>
#include <iostream>
#include "MMath.h"
#include "Window.h"
#include "Shader.h"
#include "Scene0.h"
#include "SceneEnvironment.h"
#include "Trackball.h"
#include "Model1.h"
#include "ObjLoader.h"

using namespace GAME;
using namespace MATH;


Scene0::Scene0(Window& windowRef) :Scene(windowRef) {

}


bool Scene0::OnCreate() {

	camera = nullptr;


	/// Load Assets: as needed 
	if (addModel("Tree1.obj") == false) {
		return false;
	}

	/// Create a shader with attributes
	SceneEnvironment::getInstance()->setLight(Vec3(0.0f, 3.0f, 7.0f));

	OnResize(windowPtr->getWidth(), windowPtr->getHeight());
	return true;
}


bool GAME::Scene0::addModel(const char* filename)
{
	models.push_back(new Model(Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 90.0f, 0.05f));
	models[models.size() - 1]->OnCreate();

	if (models[models.size() - 1]->LoadMesh(filename) == false) {
		return false;
	}
	return true;
}

void Scene0::OnResize(int w_, int h_) {
	windowPtr->setWindowSize(w_, h_);
	glViewport(0, 0, windowPtr->getWidth(), windowPtr->getHeight());
	if (camera) delete camera;
	camera = new Camera(w_, h_, Vec3(0.0f, 0.0f, 10.0f));
	Camera::currentCamera = camera;
	Trackball::getInstance()->setWindowDimensions(windowPtr->getWidth(), windowPtr->getHeight());
}

void Scene0::Update(const float deltaTime) {
	for (Model* model : models) {
		model->Update(deltaTime);
	}
}

void Scene0::Render() const {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/// Draw your scene here
	for (Model* model : models) {
		model->Render();
	}
	SDL_GL_SwapWindow(windowPtr->getSDLWindow());

}

void Scene0::HandleEvents(const SDL_Event& SDLEvent) {
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

Scene0::~Scene0() {
	OnDestroy();
}

void Scene0::OnDestroy() {
	/// Cleanup Assets
	if (camera) camera = nullptr; delete camera;
	for (Model* model : models) {
		if (model) model = nullptr; delete model;
	}
}
