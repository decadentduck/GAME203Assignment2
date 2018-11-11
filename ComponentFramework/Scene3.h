#ifndef Scene3_H
#define Scene3_H

#include "Scene.h"
#include "Model.h"
#include "Camera.h"
#include "Randomizer.h"

namespace GAME {
	class Window; /// Forward declaration

	class Scene3 : public Scene {
	protected:
		Randomizer r;
		bool addModel(const char* filename);

	public:
		explicit Scene3(Window& windowRef);
		virtual ~Scene3();

		/// Delete these possible default constructors and operators  
		Scene3(const Scene3&) = delete;
		Scene3(Scene3 &&) = delete;
		Scene3& operator=(const Scene3 &) = delete;
		Scene3& operator=(Scene3 &&) = delete;

		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Update(const float deltaTime);
		virtual void Render() const;
		virtual void HandleEvents(const SDL_Event &SDLEvent);
		virtual void OnResize(const int, const int);

	private:
		std::vector<Model*> models;
		Camera* camera;
		Vec3 eye, at, up;
		bool CreateForest();
	};
}
#endif