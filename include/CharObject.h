#ifndef CHAROBJECT_H
#define CHAROBJECT_H

#include "Image.h"
#include "ColliderInterface.h"
#include "SceneObject.h"
#include "Vector2.h"
#include "Animator.h"


class CharObject : public SceneObject
{
private:
    Image* _imageu;
    Image* _imagel;
    Image* _imager;
    Image* _imaged;
    
    Animator* _animate;
    
    float _speed;
    Vector2 _position;
    Vector2 _destination;
    int _radius;
    int _life;
    int _score;
    
public:
    CharObject ();
    ~CharObject ();
    
    virtual void Draw ();
    virtual void Update ();
    Vector2 getPosition();
    int getRadius();
    int getLife();
    int getScore();
    
    
    //La coliziune
    void OnCollisionEnter(ColliderInterface*);
    int getDamage();
    void increaseScore();
};



#endif