#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "SceneObject.h"
#include "BulletController.h"
#include "Background.h"

class Scene
{
private:
	std::vector<SceneObject*> _heroes;
    std::vector<SceneObject*> _monsters;
    BulletController* _bulletController;
    Background* _background;

public:
	Scene ();
	~Scene ();

	void Update ();
	void Display ();
    void Collision ();
    
	void Clear ();
    
    void LoadMonsters();
    
    BulletController* getBPointer();
    std::vector<SceneObject*>& getHeroes();
    std::vector<SceneObject*>& getMonsters();
};

#endif