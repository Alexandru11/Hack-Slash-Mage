#include "BulletController.h"
#include "Input.h"
#include "Bullet.h"

BulletController::BulletController(CharObject* phero)
{
    _hero = phero;
}

BulletController::~BulletController()
{
    Clear();
}

void BulletController::loadBullet(Bullet* lbullet)
{
    _bulletVector.push_back(lbullet);
}

std::vector<Bullet*>& BulletController::getBullets()
{
    return _bulletVector;
}


void BulletController::Update ()
{
    Vector2 mouse_pos;

    for (int i=1;i<4;i++)
    {
        mouse_pos=Input::GetMousePosition();
        if(Input::GetMouseButtonDown(i))
            {
                _bulletVector.push_back(new Bullet(_hero, mouse_pos));
            }
    }
     for (int j=0;j<_bulletVector.size();j++)
    {
        _bulletVector[j]->Update();

        if(_bulletVector[j]->getFinalDestination()==true)
        {
            delete _bulletVector[j];
            _bulletVector.erase(_bulletVector.begin() + j);
        }
       
    }

}

void BulletController::Display ()
{
    for (auto iterator1 : _bulletVector)
        iterator1->Draw();
}

void BulletController::Clear ()
{
    if (!_bulletVector.empty())
        for(auto iterator1 : _bulletVector)
            delete iterator1;
}