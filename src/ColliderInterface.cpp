#include "ColliderInterface.h"

//virtual bool OnCollisionEnter(ColliderInterface*);
//virtual int getDamage();
//virtual int getRadius();
//virtual Vector2 getPosition();

void ColliderInterface::OnCollisionEnter(ColliderInterface*)
{

}

int ColliderInterface::getDamage()
{
    return 0;
}

int ColliderInterface::getRadius()
{
    return 0;
}

Vector2 ColliderInterface::getPosition()
{
    return Vector2::Zero;
}