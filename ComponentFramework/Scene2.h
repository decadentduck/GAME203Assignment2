#ifndef Scene2_H
#define Scene2_H

#include "Scene.h"
#include "Model2.h"
#include "Camera.h"
///deorating objects assignment
namespace GAME
{
	/// Forward casting
	class Trackball;
	
	class Scene2 : public Scene
	{
	protected:
		bool addModel(const char* filename);
		bool addReferenceModel(const char* filename, Vec3 at_);
		unsigned int refNumber;
		
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
		Vec3 positiveRefPosition, negativeRefPosition;
		Trackball *trackball;
		Vec3 eye, at, up;
		Camera *camera = nullptr;
		std::vector<Model2*> models;

		
	};
}
#endif