#include "CollisionSystem.h"
#include "ColliderInterface.h"
#include "Vector2.h"
#include "CharObject.h"
#include "GameEngine.h"
#include "Input.h"
#include "Screen.h"


CollisionSystem* CollisionSystem::Instance()
{
    return Col;
}

CollisionSystem* CollisionSystem :: Col(new CollisionSystem);

CollisionSystem::CollisionSystem()
{

}

bool CollisionSystem::verifyCollisions(ColliderInterface* A, ColliderInterface* B)
{
    if (Vector2::Distance(A->getPosition(), B->getPosition()) <= (A->getRadius() + B->getRadius()))
    {
        A->OnCollisionEnter(B);
        B->OnCollisionEnter(A);
        return true;
    }
    return false;
}
