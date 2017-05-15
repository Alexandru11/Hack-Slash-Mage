//
//  Animator.h
//  LiteEngine2D
//
//  Created by Alex on 20/05/16.
//  Copyright © 2016 University of Bucharest. All rights reserved.
//

#ifndef Animator_h
#define Animator_h

#include "Image.h"
#include "Vector2.h"
#include <vector>

class Animator{
    
    static int frame;
    static int gLastTick;
    static int attack_frame;
    static int attack_gLastTick;
    static bool lr;
    static bool mouse_pressed;
    static Vector2 mouse_pos;
    
    std::vector<Image*> _imagesr; //standing right
    std::vector<Image*> _imagesl; //standing left
    std::vector<Image*> _imagesRF; //right front
    std::vector<Image*> _imagesLF; //left front
    std::vector<Image*> _imagesLB; //left back
    std::vector<Image*> _imagesRB; // right back
    std::vector<Image*> _imagesARF; // attack right front
    std::vector<Image*> _imagesALF; // attack left front
    std::vector<Image*> _imagesARB; // attack right back
    std::vector<Image*> _imagesALB; // attack left back
    
public:
    
    Animator();
    ~Animator();
    void displayAnimation(Vector2);
    void displayAttackAnimation(Vector2);
    
    
};



#endif /* Animator_h */
