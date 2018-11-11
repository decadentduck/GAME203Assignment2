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

using namespace std;
///Gamescene assignment
namespace GAME
{
	/// Forward casting
	class Trackball;
	class Model;

	class Scene1 : public Scene
	{
	protected:

	public:
		explicit Scene1(Window& windowRef);
		virtual ~Scene1();
		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Update(const float deltaTime);
		virtual void Render() const;
		virtual void HandleEvents(const SDL_Event &SDLEvent);
		virtual void OnResize(const int, const int);
		class Object* Objects[NUM_OBJECTS];
		
		ifstream fileInput;
		std::string next, name, filename;
		int pX, pY, pZ, rX, rY, rZ, loc_end, loc_name, loc_pX, loc_pY, loc_pZ, loc_rX, loc_rY, loc_rZ;

	private:
		Vec3 lightPos;
		Model *model;
		Trackball *trackball;
		int activeScene, loadedScene;
		Camera *camera = nullptr;
	};
}
#endif