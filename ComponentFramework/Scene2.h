#ifndef Scene2_H
#define Scene2_H
#include <GL/glew.h>
#include <SDL.h>
#include "Scene.h"
#include "Window.h"
#include <iostream>
#include "MMath.h"
#include "QuadSphere.h"
#include "Trackball.h"
#include "Bodies.h"
#include "Model.h"
#include "Camera.h"
///deorating objects assignment
namespace GAME
{
	/// Forward casting
	class Trackball;
	class Model;

	class Scene2 : public Scene
	{
	protected:
		Vec3 eye, at, up;
		Camera currentCamera();
	public:
		explicit Scene2(Window& windowRef);
		virtual ~Scene2();
		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Update(const float deltaTime);
		virtual void Render() const;
		virtual void HandleEvents(const SDL_Event &SDLEvent);
		virtual void OnResize(const int, const int);
	private:
		Vec3 lightPos;
		Bodies *body;
		Trackball *trackball;
	};
}
#endif