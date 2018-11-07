#include <cassert>
#include "GameSceneManager.h"
#include "Debug.h"
#include "Timer.h"
#include "Scene0.h"
#include <cassert>
#include "Scene1.h"
#include "Scene2.h"
#include "Scene3.h"

using namespace GAME;

/// See the header file reguarding unique_ptr
std::unique_ptr<GameSceneManager> GameSceneManager::instance(nullptr);

GameSceneManager::GameSceneManager() : windowInstance(), currentScene(nullptr),isRunning(false) 
{
	frameRate = 30; /// in frames per second
}

GameSceneManager::~GameSceneManager()
{
	windowInstance.OnDestroy();
	isRunning = false;
}

GameSceneManager* GameSceneManager::getInstance()
{
	if(instance.get() == nullptr){
		/// I originally set the unique_ptr to be null in the constructor - 
		/// reset() sets the new address
		instance.reset(new GameSceneManager());
	}
	return instance.get();
}

void GameSceneManager::Run()
{
	isRunning = Initialize();  /// Initialize the window and setup OpenGL
	Timer timer;
	timer.Start();

	/// This is now the master loop for the program
	while ( isRunning ) 
	{
		timer.UpdateFrameTicks();

		HandleEvents();
		Update(timer.GetDeltaTime());
		Render();

		/// Keeep the event loop running at a sane rate
		SDL_Delay(timer.GetSleepTime(frameRate));
		///std::cout << "main loop running at: " << (1.0f/timer.GetDeltaTime()) << " frames/sec" << std::endl;
		
	}
}

void GameSceneManager::HandleEvents()
{
	SDL_Event SDLEvent;
	
	while (SDL_PollEvent(&SDLEvent)) 
	{
		switch (SDLEvent.type) 
		{
			case SDL_EventType::SDL_QUIT:
				isRunning = false;
				return;
			case SDL_EventType::SDL_MOUSEBUTTONDOWN:
			case SDL_EventType::SDL_MOUSEBUTTONUP:
			case SDL_EventType::SDL_MOUSEMOTION:
				assert(currentScene); 
				currentScene->HandleEvents(SDLEvent);
				break;
			case SDL_WINDOWEVENT:
				if(SDLEvent.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
				{
					currentScene->OnResize(SDLEvent.window.data1,SDLEvent.window.data2 );
				}
				break;
			case SDL_KEYUP:
				switch (SDLEvent.key.keysym.sym)
				{
				case SDLK_0:
					currentScene->OnDestroy(); //delete current scene
					delete currentScene;
					currentScene = nullptr;
					currentScene = new Scene0(windowInstance); //make new scene
					currentScene->OnCreate(); //build scene
					break;
				case SDLK_1: //switch to assignment one when f1 key is pressed / or restart assignment 1
					currentScene->OnDestroy(); //delete current scene
					delete currentScene;
					currentScene = nullptr;
					currentScene = new Scene1(windowInstance); //make new scene
					currentScene->OnCreate(); //build scene
					break;
				case SDLK_2: //switch to assignment two when f2 key is pressed / or restart assignment 2
					currentScene->OnDestroy();//delete current scene
					delete currentScene;
					currentScene = nullptr;
					currentScene = new Scene2(windowInstance); //make new scene
					currentScene->OnCreate();//build scene
					break;
				case SDLK_3: //switch to assignment 3 when f13 key is pressed / or restart assignment 3
					currentScene->OnDestroy(); //delete current scene
					delete currentScene;
					currentScene = nullptr;
					currentScene = new Scene3(windowInstance); //make new scene
					currentScene->OnCreate(); //build scene
					break;
				default:
					currentScene->HandleEvents(SDLEvent);
					break;
				}
			default:  
				break;
		}
	}
}

void GameSceneManager::Update(const float deltaTime) 
{
	assert(currentScene); 
	currentScene->Update(deltaTime);
}

void GameSceneManager::Render() const 
{
	assert(currentScene); 
	currentScene->Render();
} 

bool GameSceneManager::Initialize()
{
	Debug::Log(EMessageType::INFO, "Initializing the window and first scene" ,__FILE__, __LINE__);

	windowInstance.SetWindowSize(1024, 740);
	bool status = windowInstance.OnCreate();
	if( status == false)
	{
		Debug::Log(EMessageType::FATAL_ERROR, "Failed to initialize a Window and/or OpenGL",__FILE__, __LINE__);
		throw std::string("Failed to initialize a Window and/or OpenGL");
	}

	
	currentScene = new Scene0(windowInstance);

	if(currentScene == nullptr)
	{
		Debug::Log(EMessageType::FATAL_ERROR, "Failed to initialize the Scene",__FILE__, __LINE__);
		throw std::string("Failed to initialize the Scene");
	}
	currentScene->OnCreate(); 
	return true;
}