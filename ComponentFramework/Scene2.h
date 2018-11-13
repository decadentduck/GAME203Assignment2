#ifndef Scene2_H
#define Scene2_H

#include "Scene.h"
#include "Model2.h"
#include "Camera.h"
///deorating objects assignment
/*
The task was to create multiple meshes that will render off an original object. Decorations should move with the object.
So the solution wasn’t as direct as it needed to be I noticed this as the camera for brief 3 was being done. Because one would have had to be able to differentiate the different types of movements that could happen in the system. There is the camera, and the models and either of them could move, and it would look like the same thing was going on.  So I needed a way to differentiate between the two in my code to show that I’m not moving just the camera.
To solve this I have a model attached to the Viewmatrix’s  “at” position so if the camera moves you can see that model move. But you can move the other models separately to show that models do move together as one object. For simplicity sakes I just used 3 trees to act as one body.  I separated the movements into different keyboard input sets. Wasd is for the camera, and ijkl is for the models.
Translating the models was easy. All you had to do was apply the same translation to each model to make them move in uniform. The hardest part was trying to figure out how to rotate the models off a parent model being the pivot point. In theory you would have to translate the set of models to origin with the parent sitting on 0,0,0 then rotate the models then retranslate it back to where it first started with it’s new rotation. But alas, I could not get it to work or at least I did not have enough time to figure it out.
I noticed that the assignments we chose had the same principle being applied to it, just on seperate variables. So we ended up doing a lot of redundant work without realizing it.

*/
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
		void RotateCamera(const char* direction);
		VMath calc;

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
		//Camera Variables
		Vec3 lightPos;
		//Vec3 positiveRefPosition, negativeRefPosition;
		Trackball *trackball;
		Vec3 eye, at, up;
		Camera *camera = nullptr;
		std::vector<Model2*> models;
		Vec3 originTranslation;
		Vec3 ViewDirection;

	public:
		//Model Variables
		Vec3 modelPosition;
		Vec3 modelOrientation;
		Vec3 tempPosition;

	};
}
#endif