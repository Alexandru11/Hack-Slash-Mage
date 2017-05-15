#include "CollisionDetector.h"

CollisionDetector* CollisionDetector::Instance()
{
    return Col;
}

CollisionDetector* CollisionDetector :: Col(new CollisionDetector);

CollisionDetector::CollisionDetector()
{
    
}

