//
//  CollisionSystem.h
//  LiteEngine2D
//
//  Created by Alex on 06/05/16.
//  Copyright © 2016 University of Bucharest. All rights reserved.
//

#ifndef CollisionSystem_h
#define CollisionSystem_h


#include "ColliderInterface.h"
#include "Scene.h"

class CollisionSystem
{
private:
    static CollisionSystem* Col;
public:
    static CollisionSystem* Instance();
    CollisionSystem();
    bool verifyCollisions(ColliderInterface*, ColliderInterface*);
};


#endif /* CollisionSystem_h */
