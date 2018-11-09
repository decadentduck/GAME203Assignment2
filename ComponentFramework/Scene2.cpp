#include "Scene2.h"

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
	currentCamera() = //Camera::Camera(ViewportWidth, ViewportHeight, CameraPosition)
		Camera::Camera
		(
			//ViewportWidth           ViewportHeight        CameraPosition
			windowRef.getWidth(), windowRef.getHeight(), Vec3(0.0f, 0.0f, 0.0f)
		);
}

Scene2::~Scene2()
{
	OnDestroy();
}

bool Scene2::OnCreate()
{
	Model *m;
	/* Re-adjusts Camera in case scene is changed   */	
	
	
	
	eye = Vec3(0.0f, 3.0f, 10.0f);
	at = Vec3(0.0f, 0.0f, 0.0f);
	up = Vec3(0.0f, 1.0f, 0.0f);
	
	Vec3 pos = Vec3(0.0f, 0.0f, 0.0f);
	Vec3 rot = Vec3(0.0f, 0.0f, 0.0f);
	Vec3 vel = Vec3(0.0f, 0.0f, 0.0f);
	lightPos = Vec3(10.0f, 3.0f, 10.0f);

	m->setPos(pos);

	body = new Bodies(pos, rot, Vec3(1.0f, 1.0f,1.0f), m);
	return true;
}


void Scene2::OnResize(int w_, int h_)
{
	currentCamera() = Camera::Camera(w_, h_, Vec3(0.0f, 0.0f, 0.0f));
	//windowPtr->SetWindowSize(w_, h_);
	//glViewport(0, 0, windowPtr->GetWidth(), windowPtr->GetHeight());
	//float aspect = float(windowPtr->GetWidth()) / float(windowPtr->GetHeight());

	//projectionMatrix = MMath::perspective(45.0f, aspect, 1.0f, 100.0f);
	////position , at , up
	//viewMatrix = MMath::lookAt(Vec3(0.0f, 0.0f, 100.0f),
	//							Vec3(0.0f, 0.0f, 0.0f),
	//							Vec3(0.0f, 1.0f, 0.0f));
}

void Scene2::OnDestroy()
{
	//Delete All Pointers
}

void Scene2::Update(const float deltaTime)
{

}

void Scene2::Render() const
{
	/*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	body->model->SetLightPos(viewMatrix * lightPos);
	body->model->Render(projectionMatrix, trackball->GetMatrix4() *  viewMatrix, trackball->GetMatrix3());
	SDL_GL_SwapWindow(windowPtr->getSDLWindow());*/
}

void Scene2::HandleEvents(const SDL_Event& SDLEvent)
{
	/*if (SDLEvent.type == SDL_EventType::SDL_MOUSEBUTTONDOWN)
	{
		trackball->OnLeftMouseDown(SDLEvent.button.x, SDLEvent.button.y);
	}
	if (SDLEvent.type == SDL_EventType::SDL_MOUSEMOTION &&
		SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		trackball->OnMouseMove(SDLEvent.button.x, SDLEvent.button.y);
	}*/

}