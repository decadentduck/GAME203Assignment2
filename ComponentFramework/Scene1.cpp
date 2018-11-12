#include "Scene1.h"

using namespace GAME;
using namespace MATH;

Scene1::Scene1(Window& windowRef) :Scene(windowRef) { }

Scene1::~Scene1()
{
	OnDestroy();
}

bool Scene1::OnCreate()
{
	LoadFile(1);
	
	return true;
}

void Scene1::OnResize(int w_, int h_)
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

void Scene1::OnDestroy()
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

void Scene1::Update(const float deltaTime)
{
	
}

void Scene1::Render() const
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/// Draw your scene here
	for (Model* model : models) { model->Render(); }
	SDL_GL_SwapWindow(windowPtr->getSDLWindow());
}


bool Scene1::LoadFile(int scene)
{
	pugi::xml_document doc;
	pugi::xml_parse_result result;

	//temp values
	string name = string("");
	Vec3 pos = Vec3(0, 0, 0);
	int rot = 0;

	if (scene == 1) { result = doc.load_file("World1.xml"); }
	else if (scene == 2) { result = doc.load_file("World2.xml"); }

	if (result)
	{
		pugi::xml_node parent = doc.child("objects");

		for (pugi::xml_node child : parent.children())
		{
			for (pugi::xml_attribute attr : child.attributes())
			{
				if (attr.name() == "name") name = attr.value();
			}

			for (pugi::xml_node grandChild : child.children("pos"))
			{
				float x, y, z;
				x = y = z = 0.0f;
				for (pugi::xml_attribute attr : grandChild.attributes())
				{
					if (attr.name() == "X") x = atof(attr.value());
					else if (attr.name() == "Y") y = atof(attr.value());
					else if (attr.name() == "Z") z = atof(attr.value());
				}
				pos = Vec3(x, y, z);

			}
			//instantiate the object here
			if (!addModel(name, pos, rot)) return false;
			//empty temp values
			name = "";
			pos = Vec3(0.0f, 0.0f, 0.0f);
			rot = 0.0f;
		}
	}
	else { return false; }

	return true;
}

bool GAME::Scene1::addModel(const string tree, const Vec3 pos, const float rot)
{

	models.push_back(new Model(pos, Vec3(0.0f, 0.0f, 0.0f), rot, Vec3(0.05f, 0.05f, 0.05f)));
	models[models.size() - 1]->OnCreate();
	if (tree == "Tree1")
	{
		if (models[models.size() - 1]->LoadMesh("Tree1.obj") == false)
		{
			return false;
		}
	}
	else
	{
		if (models[models.size() - 1]->LoadMesh("Tree2.obj") == false)
		{
			return false;
		}
	}

	return true;
}

void Scene1::HandleEvents(const SDL_Event& SDLEvent)
{
	SDL_Event event;
	//pressing a key switches which file it reads from
	if (SDL_PollEvent(&event) != 0) {
		switch (event.type) 
		{
			case SDL_KEYUP:
				if (event.key.keysym.sym == SDLK_RETURN)
				{
					LoadFile(2);
				}
				break;

			default:
				break;
		}
	}
}