//
//  MonsterAnimator.h
//  LiteEngine2D
//
//  Created by Alex on 21/05/16.
//  Copyright © 2016 University of Bucharest. All rights reserved.
//

#ifndef MonsterAnimator_h
#define MonsterAnimator_h

#include "Image.h"
#include "Vector2.h"
#include <vector>

class MonsterAnimator{
    
    static int frame;
    static int gLastTick;
    
    std::vector<Image*> _imagesl;
    std::vector<Image*> _imagesr;
    
public:
    MonsterAnimator(std::string);
    ~MonsterAnimator();
    void displayAnimation(Vector2, Vector2);
    
};

#endif /* MonsterAnimator_h */
