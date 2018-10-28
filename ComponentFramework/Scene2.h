#ifndef Scene2_H
#define Scene2_H
#include <GL/glew.h>
#include <SDL.h>
#include "Scene.h"
#include "Window.h"
#include <iostream>
#include "MMath.h"
#include "QuadSphere.h"
#include "Primitive.h"
#include "Trackball.h"

namespace GAME
{
	/// Forward casting
	class Trackball;
	class Model;

	class Scene2 : public Scene
	{
	protected:

	public:
		explicit Scene2(Window& windowRef);
		virtual ~Scene3();
		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Update(const float deltaTime);
		virtual void Render() const;
		virtual void HandleEvents(const SDL_Event &SDLEvent);
		virtual void OnResize(const int, const int);
	private:
		Vec3 lightPos;
		Model *model;
		Trackball *trackball;
	};
}
#endif