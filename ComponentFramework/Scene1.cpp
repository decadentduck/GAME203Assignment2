#include "Scene1.h"

using namespace GAME;
using namespace MATH;

Scene1::Scene1(class Window& windowRef) : Scene(windowRef), model(nullptr)
{
	trackball = new Trackball();
	/*projectionMatrix.loadIdentity();
	viewMatrix.loadIdentity();*/
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

Scene1::~Scene1()
{
	OnDestroy();
}

bool Scene1::OnCreate()
{
	

	getchar();
	
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
}

void Scene1::Update(const float deltaTime)
{
	
}

void Scene1::Render() const
{
	//loop through the array of objects, print them out in their respective locations and orientations
	for (int i = 0; i < NUM_OBJECTS; i++ )
	{
		//draw things idfk man
	}
}


bool Scene1::LoadFile(string fileName)
{
	/*if (scene == 1) { pugi::xml_parse_result result = doc.load_file("World1.xml"); }
	else if (scene == 2) { pugi::xml_parse_result result = doc.load_file("World2.xml"); }



	fileInput.open(filename);
	if (fileInput.fail()) { std::cout << "Opening File failed. \n" << endl; }

	int i = 0;

	getline(fileInput, next);

	if (next == "<objects>")
	{
		getline(fileInput, next);
		while (next != "</objects>")
		{
			if (next == "\t<object>") { getline(fileInput, next); }
			else if (next == "\t\t<name>") {}
			else if (next == "\t\t<posX>") {}
			else if (next == "\t\t<posY>") {}
			else if (next == "\t\t<posZ>") {}
			else if (next == "\t\t<rotX>") {}
			else if (next == "\t\t<rotY>") {}
			else if (next == "\t\t<rotZ>") {}
			else if (next == "\t</object>")
			{
				Objects[i] = new Object(name, pX, pY, pZ, rX, rY, rZ);
				name.erase(0, name.length());
				pX = NULL;
				pY = NULL;
				pZ = NULL;
				rX = NULL;
				rY = NULL;
				rZ = NULL;
				i++;
			}
		}
	}*/

	//while (getline(fileInput, next))
	//{
	//	do
	//	{
	//		loc_name = next.find("<name>");
	//		loc_pX = next.find("<posX>");
	//		loc_pY = next.find("<posY>");
	//		loc_pZ = next.find("<posZ>");
	//		loc_rX = next.find("<rotX>");
	//		loc_rY = next.find("<rotY>");
	//		loc_rZ = next.find("<rotZ>");
	//		loc_end = next.find("</objects>");

	//		if ((loc_name >= 0) && (loc_name < next.length())) { name = next.substr(0, 5); }
	//		if ((loc_pX >= 0) && (loc_pX < next.length())) { pX = stoi(next.substr(0, 5)); }
	//		if ((loc_pY >= 0) && (loc_pY < next.length())) { pY = stoi(next.substr(0, 5)); }
	//		if ((loc_pZ >= 0) && (loc_pZ < next.length())) { pZ = stoi(next.substr(0, 5)); }
	//		if ((loc_rX >= 0) && (loc_rX < next.length())) { rX = stoi(next.substr(0, 5)); }
	//		if ((loc_rY >= 0) && (loc_rY < next.length())) { rY = stoi(next.substr(0, 5)); }
	//		if ((loc_rZ >= 0) && (loc_rZ < next.length())) { rZ = stoi(next.substr(0, 5)); }
	//	} while (((loc_end < 0) || (loc_end >= next.length())) && (getline(fileInput, next)));

	//	//This sets the values obtained above into the array
	//	//Objects[i] = new Object(name, pX, pY, pZ, rX, rY, rZ);

	//	std::cout << name << " " << pX << " " << pY << " " << pZ << " " << rX << " " << rY << " " << rZ << endl;

	//	name.erase(0, name.length());
	//	pX = NULL;
	//	pY = NULL;
	//	pZ = NULL;
	//	rX = NULL;
	//	rY = NULL;
	//	rZ = NULL;
	//	i++;
	//}
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
					//if (activeScene == 1) { activeScene = 2; OnCreate(1); }
					//else { activeScene = 1; }
				}
				break;

			default:
				break;
		}
	}
}