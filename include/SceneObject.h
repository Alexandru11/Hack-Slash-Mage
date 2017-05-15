#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "Object.h"
#include "Vector2.h"
#include "ColliderInterface.h"

class SceneObject : public Object, public ColliderInterface
{
public:
	SceneObject ();
	virtual ~SceneObject ();

	virtual void Update ();
	virtual void Draw ();
    //virtual Vector2 getPosition() = 0; nu e nevoie
};

#endif