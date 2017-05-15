#include "Bullet.h"

#include "Resources.h"

#include "Window.h"
#include "Screen.h"
#include "Input.h"
#include "GameTime.h"
#include "Vector2.h"


#include <cstdlib>

#define BULLET_SPEED 500

Bullet::Bullet (CharObject* phero, Vector2 destination) :
_speed (BULLET_SPEED),
_position (0, 0)
{
    //_collisionImage = Resources::LoadImage("rectangle.png") ;
    
    _finaldestination = false;
    _radius = 20;
    _position = phero->getPosition();
    _destination = destination;
    _destination.SetY(Screen::GetHeight() - _destination.GetY());
    _velocity = _destination - _position;
    
    _animate = new BulletAnimator();
}

Bullet::~Bullet()
{
    delete _animate;
}

void Bullet::Draw ()
{
    _animate->displayAttackAnimation(_position);
    // Screen::Draw(_collisionImage, _position);
}

Vector2 Bullet::getPosition()
{
    return _position;
}

int Bullet::getRadius()
{
    return _radius;
}


void Bullet::OnCollisionEnter(ColliderInterface* B)
{

}

bool Bullet::getFinalDestination()
{
    return _finaldestination;
}


int Bullet::getDamage()
{
    return 0;
}

void Bullet::Update ()
{
    
    if (_position.GetX() <= -10 || _position.GetX() >= Screen::GetWidth() || _position.GetY()<=-10 || _position.GetY()>=Screen::GetHeight()) {
        _finaldestination = true;
        return;
    }
    
    _velocity.Normalize ();
    
    _position += (_velocity) * _speed * GameTime::GetDeltaTime ();
}
