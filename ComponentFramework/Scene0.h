#ifndef Scene0_H
#define Scene0_H

#include "Scene.h"
#include "Model.h"
#include "Camera.h"

namespace GAME {
	class Window; /// Forward declaration

	class Scene0 : public Scene {
	protected:

		bool addModel(const char* filename);

	public:
		explicit Scene0(Window& windowRef);
		virtual ~Scene0();


		/// Delete these possible default constructors and operators  
		Scene0(const Scene0&) = delete;
		Scene0(Scene0 &&) = delete;
		Scene0& operator=(const Scene0 &) = delete;
		Scene0& operator=(Scene0 &&) = delete;

		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Update(const float deltaTime);
		virtual void Render() const;
		virtual void HandleEvents(const SDL_Event &SDLEvent);
		virtual void OnResize(const int, const int);

	private:
		std::vector<Model*> models;
		Camera* camera;
	};
}
#endif