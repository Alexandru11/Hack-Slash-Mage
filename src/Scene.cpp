#include "Scene.h"
#include "CollisionSystem.h"

#include "MonsterObject.h"
#include "MonsterObject2.h"
#include "MonsterObject3.h"

#include "CharObject.h"

Scene::Scene ()
{
    
	// Hardcoded construction of a new BallObject in the scene constructor
	// TODO: This need to be deleted (even as an example)
    
    _background = new Background();
    CharObject* Hero1 = new CharObject();
    _bulletController = new BulletController(Hero1);
    _heroes.push_back (Hero1);
    
    LoadMonsters();
    
}

void Scene::LoadMonsters()
{
    while (_monsters.size()<=5)
    {
            if (rand()%3 == 0)
                _monsters.push_back (new MonsterObject (dynamic_cast<CharObject*>(_heroes[0])));
            else if (rand()%3 == 1)
                _monsters.push_back (new MonsterObject2 (dynamic_cast<CharObject*>(_heroes[0])));
            else if (rand()%3 == 2)
                _monsters.push_back (new MonsterObject3 (dynamic_cast<CharObject*>(_heroes[0])));
    }
}

std::vector<SceneObject*>& Scene::getHeroes()
{
    return _heroes;
}

std::vector<SceneObject*>& Scene::getMonsters()
{
    return _monsters;
}

BulletController* Scene::getBPointer()
{
    return _bulletController;
}

Scene::~Scene ()
{
	Clear ();
}

void Scene::Update ()
{
	for (auto iterator1 : _heroes) { // Obiecte de tip SceneObjects
		iterator1->Update (); // Se apeleaza prin virtualizare
	}
    
    _bulletController->Update();
    
    LoadMonsters();
    
    for (auto iterator2 : _monsters) { // Obiecte de tip SceneObjects
        iterator2->Update (); // Se apeleaza prin virtualizare
    }
}

void Scene::Display ()
{
    _background->Draw();
    
    for (auto iterator1 : _heroes) { // Obiecte de tip SceneObjects
        iterator1->Draw(); // Se apeleaza prin virtualizare
    }
    for (auto iterator2 : _monsters) { // Obiecte de tip SceneObjects
        iterator2->Draw(); // Se apeleaza prin virtualizare
    }
    
    _bulletController->Display();
    
    
    
}

void Scene::Clear ()
{
	for (auto iterator1 : _heroes) {
		delete iterator1;
	}
    for (auto iterator2 : _monsters) {
        delete iterator2;
    }
    delete _bulletController;
    
    delete _background;
}


void Scene::Collision()
{
    int i,j;
    for ( i=0; i<_heroes.size(); i++)
        for ( j=0; j<_monsters.size(); j++)
        {
            if (CollisionSystem::Instance()->verifyCollisions(_heroes[i], _monsters[j])==true)
            {
//                _heroes[i]->OnCollisionEnter(_monsters[j]);
//                _monsters[j]->OnCollisionEnter(_heroes[i]);
                delete _monsters[j];
                _monsters.erase(_monsters.begin()+j);
            }
        }
    
    for ( i=0; i<_monsters.size(); i++)
        for (j=0; j<_bulletController->getBullets().size(); j++)
        {
            if(CollisionSystem::Instance()->verifyCollisions(_monsters[i], _bulletController->getBullets()[j])==true)
            {
//                _monsters[i]-> OnCollisionEnter(_bulletController-> getBullets()[j]);
//                _bulletController-> getBullets()[j]-> OnCollisionEnter(_monsters[i]);
                delete _monsters[i];
                delete _bulletController-> getBullets()[j];
                _monsters.erase(_monsters.begin()+i);
                _bulletController-> getBullets().erase(_bulletController-> getBullets().begin()+j);
            }
        }
    
    
}