#ifndef Scene3_H
#define Scene3_H
#define NUM_TREES 20
#include <GL/glew.h>
#include <SDL.h>
#include "Scene.h"
#include "Window.h"
#include <iostream>
#include "MMath.h"
#include "QuadSphere.h"
#include "Trackball.h"
#include "Bodies.h"

//forest of trees assignment
namespace GAME
{
	/// Forward casting
	class Trackball;
	class Model0;

	class Scene3 : public Scene
	{
	protected:

	public:
		explicit Scene3(Window& windowRef);
		virtual ~Scene3();
		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Update(const float deltaTime);
		virtual void Render() const;
		virtual void HandleEvents(const SDL_Event &SDLEvent);
		virtual void OnResize(const int, const int);

		Vec3 eye, at, up;
	private:
		void CreateForest();
		Vec3 lightPos;
		Bodies* bodies[NUM_TREES];
		Trackball *trackball;
	};
}
#endif