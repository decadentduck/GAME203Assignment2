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
#include "SceneEnvironment.h"
#include "Bodies.h"
#include "Model1.h"
#include "Model2.h"
#include "Camera.h"

//forest of trees assignment
namespace GAME
{
	/// Forward casting
	class Trackball;

	class Scene3 : public Scene
	{
	protected:
		bool addModel(const char* filename);
	public:
		explicit Scene3(Window& windowRef);
		virtual ~Scene3();
		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Update(const float deltaTime);
		virtual void Render() const;
		virtual void HandleEvents(const SDL_Event &SDLEvent);
		virtual void OnResize(const int, const int);

	private:
		Vec3 eye, at, up;
		std::vector<Model1*> models;
		Camera* camera;
		void CreateForest();
		Vec3 lightPos;
	};
}
#endif