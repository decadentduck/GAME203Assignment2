#include "Scene3.h"
//#include "ModelTree.h"
#include "Camera.h"

using namespace GAME;
using namespace MATH;

Scene3::Scene3(class Window& windowRef) : Scene(windowRef)
{
	//projectionMatrix.loadIdentity();
	//viewMatrix.loadIdentity();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

Scene3::~Scene3()
{
	OnDestroy();
}

bool Scene3::OnCreate()
{
	camera = nullptr;
	lightPos = Vec3(10.0f, 3.0f, 10.0f);
	/// Load Assets: as needed 
	
	CreateForest();

	eye = Vec3(0.0f, 3.0f, 10.0f);
	at = Vec3(0.0f, 0.0f, 0.0f);
	up = Vec3(0.0f, 1.0f, 0.0f);

	if (addModel("Tree1.obj") == false) { return false; }

	/// Create a shader with attributes
	SceneEnvironment::getInstance()->setLight(Vec3(0.0f, 3.0f, 7.0f));

	OnResize(windowPtr->getWidth(), windowPtr->getHeight());
	return true;
}

void Scene3::CreateForest()
{
	/*Model *m = new ModelTree;
	Vec3 pos = Vec3(0.0f, 0.0f, 0.0f);
	Vec3 rot = Vec3(0.0f, 0.0f, 0.0f);
	Vec3 vel = Vec3(0.0f, 0.0f, 0.0f);
	m->SetVel(vel);
	m->SetPos(pos);
	bodies[0] = new Bodies(pos, rot, Vec3(1.0f, 1.0f, 1.0f), m);
*/
	//TODO fill trees array with trees

	//random pos, rotat, model(from a few choices)
	//maybe scale....
}

void Scene3::OnResize(int w_, int h_)
{
	windowPtr->setWindowSize(w_, h_);
	glViewport(0, 0, windowPtr->getWidth(), windowPtr->getHeight());
	if (camera) delete camera;
	camera = new Camera(w_, h_, Vec3(0.0f, 0.0f, 10.0f));
	Camera::currentCamera = camera;
}

bool GAME::Scene3::addModel(const char* filename)
{
	models.push_back(new Model1(Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 90.0f, 0.05f));
	models[models.size() - 1]->OnCreate();

	if (models[models.size() - 1]->LoadMesh(filename) == false) {
		return false;
	}
	return true;
}

void Scene3::OnDestroy()
{
	//TODO delete trees array	
}

void Scene3::Update(const float deltaTime) 
{
	for (Model1* model : models) {
		model->Update(deltaTime);
	}
}

void Scene3::Render() const 
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/// Draw your scene here
	for (Model1* model : models) {
		model->Render();
	}
	SDL_GL_SwapWindow(windowPtr->getSDLWindow());

}

void Scene3::HandleEvents(const SDL_Event& SDLEvent)
{
	//Handle camera via keyboard input
	if (SDLEvent.type == SDL_KEYUP)
	{
		switch (SDLEvent.key.keysym.sym)
		{
		case SDLK_UP:
			eye = MMath::translate(0.0f, 0.0f, -1.0f) * eye;
			camera->SetCamera(eye, at, up);
			break;
		case SDLK_DOWN:
			eye = MMath::translate(0.0f, 0.0f, 1.0f) * eye;
			camera->SetCamera(eye, at, up);
			break;
		case SDLK_LEFT:
			at = MMath::translate(-1.0f, 0.0f, 0.0f) * at;
			camera->SetCamera(eye, at, up);
			break;
		case SDLK_RIGHT:
			at = MMath::translate(1.0f, 0.0f, 0.0f) * at;
			camera->SetCamera(eye, at, up);
			break;
		default:
			break;
		}
		Camera::currentCamera = camera;
	}
}