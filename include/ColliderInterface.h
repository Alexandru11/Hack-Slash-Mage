//
//  ColliderInterface.h
//  LiteEngine2D
//
//  Created by Alex on 05/05/16.
//  Copyright © 2016 University of Bucharest. All rights reserved.
//

#if defined(__linux__) || defined(__APPLE__)
#include <SDL2/SDL.h>
#elif defined(_WIN32)
#include <SDL.h>
#endif

#ifndef ColliderInterface_h
#define ColliderInterface_h
#include "Vector2.h"
class ColliderInterface
{
    
public:
    
    virtual void OnCollisionEnter(ColliderInterface*);
    virtual int getDamage();
    virtual int getRadius();
    virtual Vector2 getPosition();
};















#endif /* Collider_h */
