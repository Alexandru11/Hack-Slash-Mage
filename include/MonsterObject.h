#ifndef MONSTEROBJECT_H
#define MONSTEROBJECT_H

#include "Image.h"
#include "ColliderInterface.h"
#include "SceneObject.h"
#include "Vector2.h"
#include "CharObject.h"
#include "MonsterAnimator.h"

class MonsterObject : public SceneObject
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
	MonsterObject (CharObject* phero);
	~MonsterObject ();
    
	virtual void Draw ();
	virtual void Update ();
    Vector2 getPosition();
    int getRadius();
    
    
    
    //la Coliziuni
    void OnCollisionEnter(ColliderInterface*);
    int getDamage();
    
    //pt resurse
    
    
};

#endif