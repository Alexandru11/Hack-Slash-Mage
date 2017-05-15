#include "BulletAnimator.h"
#include "Resources.h"
#include "Screen.h"

int BulletAnimator::frame = 0;
int BulletAnimator::gLastTick = 0;

BulletAnimator::~BulletAnimator()
{
    for (auto iterator1: _imagesa)
        delete iterator1;
}

void BulletAnimator::displayAttackAnimation(Vector2 bullet_pos)
{
    int tick = SDL_GetTicks();
    
    if((tick - gLastTick)>90)//
    {
        gLastTick = tick;
        frame++;
    }
    
    if( (frame / (_imagesa.size()-1)) >= (_imagesa.size()))
        frame = 0;
    Screen::Draw(_imagesa[frame/(_imagesa.size()-1)], bullet_pos);
    
    
}

BulletAnimator::BulletAnimator()
{
    _imagesa.push_back(Resources::LoadImage("Bullet/Attack/1.png"));
    _imagesa.push_back(Resources::LoadImage("Bullet/Attack/2.png"));
    _imagesa.push_back(Resources::LoadImage("Bullet/Attack/3.png"));
    _imagesa.push_back(Resources::LoadImage("Bullet/Attack/4.png"));
    _imagesa.push_back(Resources::LoadImage("Bullet/Attack/5.png"));
    _imagesa.push_back(Resources::LoadImage("Bullet/Attack/6.png"));
    
}