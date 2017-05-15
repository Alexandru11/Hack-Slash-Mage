//
//  BulletAnimator.h
//  LiteEngine2D
//
//  Created by Alex on 21/05/16.
//  Copyright © 2016 University of Bucharest. All rights reserved.
//

#ifndef BulletAnimator_h
#define BulletAnimator_h

#include "Image.h"
#include "Vector2.h"
#include <vector>

class BulletAnimator{
    
    static int frame;
    static int gLastTick;
    
    std::vector<Image*> _imagesa; //attack
    
public:
    BulletAnimator();
    ~BulletAnimator();
    void displayAttackAnimation(Vector2);
    
};



#endif /* BulletAnimator_h */
