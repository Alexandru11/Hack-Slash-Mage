#include "MonsterObject2.h"

#include "Resources.h"

#include "Screen.h"
#include "Input.h"
#include "GameTime.h"
#include "Vector2.h"
#include "ResourceManager.h"


#include <cstdlib>

#define MONSTER_SPEED 50

MonsterObject2::MonsterObject2 (CharObject* phero) :
_speed (MONSTER_SPEED),
_position (20, 20)
{
    //_collisionImage = Resources::LoadImage("rectangle.png") ;

    // This need to be deleted too
    
    if (rand()%2 == 1)
    {if (rand()%2 == 1)
        _position.SetX(Screen::GetWidth());
    else _position.SetX(0);
        _position.SetY(rand() % Screen::GetHeight());}
    else
    {if (rand()%2 == 1)
        _position.SetY(Screen::GetHeight());
    else _position.SetY(0);
        _position.SetX(rand() % Screen::GetWidth());
    }
    
    _radius = 20;
    _hero = phero;
    _damage = 2;
    
    _animate = new MonsterAnimator("Monster2");
    
    _speed += _hero->getScore();
    
    
}

MonsterObject2::~MonsterObject2()
{
    delete _animate;
}

void MonsterObject2::Draw ()
{
    _animate->displayAnimation(_position, _hero->getPosition());
    // Screen::Draw(_collisionImage, _position);
}

Vector2 MonsterObject2::getPosition()
{
    return _position;
}

int MonsterObject2::getRadius()
{
    return _radius;
}

void MonsterObject2::OnCollisionEnter(ColliderInterface* B)
{
        _hero->increaseScore();
}

int MonsterObject2::getDamage()
{
    return _damage;
}

void MonsterObject2::Update ()
{
    //	 Uncomment this to switch the controls of the ball to keyboard
    
    //	 Vector2 velocity = Vector2::Zero;
    //
    //	 if (Input::GetKey ('w')) {
    //	 	velocity += Vector2::Up;
    //	 }
    //	 if (Input::GetKey ('d')) {
    //	 	velocity += Vector2::Right;
    //	 }
    //	 if (Input::GetKey ('s')) {
    //	 	velocity += Vector2::Down;
    //	 }
    //	 if (Input::GetKey ('a')) {
    //	 	velocity += Vector2::Left;
    //	 }
    //
    //	 if (velocity == Vector2::Zero) {
    //	 	return;
    //	 }
    //
    //	 velocity.Normalize ();
    
    // _position += velocity * _speed * GameTime::GetDeltaTime ();
    
    _destination = _hero->getPosition();
    //_destination.SetY (Screen::GetHeight () - _destination.GetY ());
    Vector2 velocity = _destination - _position;
    
    if (velocity.Magnitude () < 0.1f) {
        return;
    }
    
    velocity.Normalize ();
    
    _position += velocity * _speed * GameTime::GetDeltaTime ();
}
