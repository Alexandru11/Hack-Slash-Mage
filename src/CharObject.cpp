#include "CharObject.h"

#include "Resources.h"

#include "Screen.h"
#include "Input.h"
#include "GameTime.h"
#include "GameEngine.h"
#include "Vector2.h"
#include "ResourceManager.h"

#include <cstdlib>

#define CHAR_SPEED 200

CharObject::CharObject () :
_speed (CHAR_SPEED),
_position (20, 20)
{
    _score = 0;
    _life = 3;
    _radius = 15;
    
    _animate = new Animator;
    
    // This need to be deleted too
    _position = Vector2 (rand () % Screen::GetWidth (), rand () % Screen::GetHeight ());
}

CharObject::~CharObject ()
{
    delete _animate;

}

void CharObject::Draw ()
{
    _animate->displayAnimation(_position);
    
    _animate->displayAttackAnimation(_position);
}

Vector2 CharObject::getPosition()
{
    return _position;
}

int CharObject::getScore()
{
    return _score;
}

int CharObject::getRadius()
{
    return _radius;
}

int CharObject::getLife()
{
    return _life;
}

int CharObject::getDamage()
{
    return 0;
}

void CharObject::increaseScore()
{
    _score++;
}


void CharObject::OnCollisionEnter(ColliderInterface* B)
{
        _life -= B->getDamage();
        
        if(_life <= 0)
        {
            std::cout<<"Game Over!"<<std::endl;
            std::cout<<"Your Score is: "<<_score;
            GameEngine::Quit();
            std::cout<<std::endl;
            exit(0);
        }
}


void CharObject::Update ()
{
    //	 Uncomment this to switch the controls of the hero to keyboard
    
    Vector2 velocity = Vector2::Zero;
    
    if (Input::GetKey ('w')) {
        //Screen::Draw (_imageu, _position);
        velocity += Vector2::Up;
    }
    if (Input::GetKey ('d')) {
        //Screen::Draw (_imager, _position);
        velocity += Vector2::Right;
    }
    if (Input::GetKey ('s')) {
       // Screen::Draw (_imaged, _position);
        velocity += Vector2::Down;
    }
    if (Input::GetKey ('a')) {
       // Screen::Draw (_imagel, _position);
        velocity += Vector2::Left;
    }
    
    
    if (velocity == Vector2::Zero) {
        return;
    }
    
    velocity.Normalize ();
   _position += velocity * _speed * GameTime::GetDeltaTime ();
    
//    _destination = Input::GetMousePosition ();
//    _destination.SetY (Screen::GetHeight () - _destination.GetY ());
//    Vector2 velocity = _destination - _position;
//    
    if (velocity.SqrMagnitude () < 0.1f) {
        return;
    }
    
    //velocity.Normalize ();
    //_position += velocity * _speed * GameTime::GetDeltaTime ();
    
    
}
