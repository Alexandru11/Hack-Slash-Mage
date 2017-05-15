//
//  Bullet.h
//  LiteEngine2D
//
//  Created by Alex on 14/05/16.
//  Copyright © 2016 University of Bucharest. All rights reserved.
//

#ifndef Bullet_h
#define Bullet_h
#include "CharObject.h"
#include "Image.h"
#include "ColliderInterface.h"
#include "SceneObject.h"
#include "Vector2.h"
#include "BulletAnimator.h"

class Bullet : public SceneObject
{
    
private:
    Image* _image;
    Image* _collisionImage;
    float _speed;
    Vector2 _position;
    Vector2 _destination;
    Vector2 _velocity;
    int _radius;
    bool _finaldestination;
    BulletAnimator* _animate;
    
public:
    Bullet (CharObject*, Vector2 destination);
    ~Bullet ();
    
    virtual void Draw ();
    virtual void Update ();
    Vector2 getPosition();
    int getRadius();
    
    int getDamage();
    bool getFinalDestination();
    
    //la Coliziuni
    void OnCollisionEnter(ColliderInterface*);
    
    
};


#endif /* Bullet_h */
