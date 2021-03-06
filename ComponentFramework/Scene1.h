#ifndef Scene1_H
#define Scene1_H
#define NUM_OBJECTS 6
#include <GL/glew.h>
#include <SDL.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Scene.h"
#include "Window.h"
#include "MMath.h"
#include "QuadSphere.h"
#include "Trackball.h"
#include "Object.h"
#include "Camera.h"
#include "pugixml.hpp"
#include "Model.h"

using namespace std;
///Gamescene assignment
namespace GAME
{

	//My task was to instantiate a scene of gameobjects from a file. After some experimenting, 
	//I decided to use.XML files for this task.With some consideration and discussion from my 
	//other group members, I downloaded a class called �pugixml� which made it much easier to 
	//read from.Then I created two identically formatted XML files and gave them different values 
	//to read.Pressing the enter key will clear the list of objects, then create a new one, reading 
	//from the other XML file.

	class Scene1 : public Scene
	{
	protected:
		bool addModel(const string tree, const Vec3 pos, const float rot);
	public:
		explicit Scene1(Window& windowRef);
		virtual ~Scene1();
		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Update(const float deltaTime);
		virtual void Render() const;
		virtual void HandleEvents(const SDL_Event &SDLEvent);
		virtual void OnResize(const int, const int);

	private:
		bool LoadFile(int file);
		int fileLoaded;
		Vec3 lightPos;
		std::vector<Model*> models;
		Camera *camera = nullptr;
	};
}
#endif