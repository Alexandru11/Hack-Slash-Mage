#include "Game.h"
//REMEMBER this is the game loop
#if defined(__linux__) || defined(__APPLE__)
	#include <SDL2/SDL.h>
#elif defined(_WIN32)
	#include <SDL.h>
#endif

#include "GameTime.h"
#include "Input.h"
#include "Screen.h"
#include "CollisionSystem.h"
#include "CollisionDetector.h"
#include "ResourceManager.h"
#include "Resources.h"

#define FRAMES_PER_SECOND 1000
#define TIME_PER_FRAME (1000 / FRAMES_PER_SECOND)
#define TICKS_PER_FRAME (1.0 / FRAMES_PER_SECOND)

Game::Game ()
{
       
	_currentScene = new Scene (); // creaza scena/ jocul/ cu toate obiectele

	GameTime::Init();
}

Game::~Game ()
{

}

Game& Game::Instance ()
{
	static Game instance;

	return instance;
}

void Game::Start ()
{
	bool running=true;

    CollisionSystem::Instance();
    
	while(running)
	{
		Screen::Clear ();
		GameTime::UpdateFrame ();
		Input::UpdateState (); // SDL_POLLEVENT

        if (Input::GetQuit () || Input::GetKeyDown (27)) {
        	running = false;
        	continue;
        }

        // if (Input::GetResizeEvent () != Vector2::Zero) {
		// 	OnWindowResize (Input::GetResizeEvent ());
		// }

		_currentScene->Update (); //executam actiunile din tastatura
        _currentScene->Collision(); //verificam si executam coliziunile
        _currentScene->Display (); //renders all actions wanted

		Screen::Render ();

		if(TICKS_PER_FRAME > GameTime::GetElapsedTimeMS () - GameTime::GetTimeMS ()) {
			SDL_Delay(TICKS_PER_FRAME - (GameTime::GetElapsedTimeMS () - GameTime::GetTimeMS ()));
		}
	}
    
    delete CollisionSystem::Instance();
}
