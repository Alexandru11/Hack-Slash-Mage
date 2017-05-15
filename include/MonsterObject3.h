//
//  MonsterObject3.h
//  LiteEngine2D
//
//  Created by Alex on 18/05/16.
//  Copyright © 2016 University of Bucharest. All rights reserved.
//

#ifndef MonsterObject3_h
#define MonsterObject3_h

#include "Image.h"
#include "ColliderInterface.h"
#include "SceneObject.h"
#include "Vector2.h"
#include "CharObject.h"
#include "MonsterAnimator.h"

class MonsterObject3 : public SceneObject
{
private:
    Image* _collisionImage;
    float _speed;
    Vector2 _position;
    Vector2 _destination;
    int _radius;
    int _damage;
    CharObject* _hero;
    MonsterAnimator* _animate;
    
public:
    MonsterObject3 (CharObject* phero);
    ~MonsterObject3 ();
    
    virtual void Draw ();
    virtual void Update ();
    Vector2 getPosition();
    int getRadius();
    
    
    
    //la Coliziuni
    void OnCollisionEnter(ColliderInterface*);
    int getDamage();
    
    
    
};


#endif /* MonsterObject3_h */
