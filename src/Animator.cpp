#include "Animator.h"
#include "Resources.h"
#include "Screen.h"
#include "Input.h"

int Animator::frame = 0;
int Animator::gLastTick = 0;

int Animator::attack_frame = 0;
int Animator::attack_gLastTick = 0;


bool Animator:: lr = false;
bool Animator:: mouse_pressed = false;
Vector2 Animator:: mouse_pos = Vector2::Zero;

Animator::~Animator()
{
    for (auto iterator1: _imagesl)
        delete iterator1;
    for (auto iterator1: _imagesr)
        delete iterator1;
    for (auto iterator1: _imagesRF)
        delete iterator1;
    for (auto iterator1: _imagesRB)
        delete iterator1;
    for (auto iterator1: _imagesLF)
        delete iterator1;
    for (auto iterator1: _imagesLB)
        delete iterator1;
    for (auto iterator1: _imagesALF)
        delete iterator1;
    for (auto iterator1: _imagesARF)
        delete iterator1;
    for (auto iterator1: _imagesALB)
        delete iterator1;
    for (auto iterator1: _imagesARB)
        delete iterator1;
    
}

void Animator::displayAttackAnimation(Vector2 position)
{
    
    int tick = SDL_GetTicks();
    
    if((tick - attack_gLastTick)>10)//
    {
        attack_gLastTick = tick;
        attack_frame++;
    }
    
    if (Input::GetMouseButtonDown(1))
    {
        mouse_pressed = true;
        mouse_pos = Input::GetMousePosition();
        mouse_pos.SetY (Screen::GetHeight () - mouse_pos.GetY ());
    }
    
    if (mouse_pressed==true)
    {
        if(position.GetY()<=mouse_pos.GetY() && position.GetX()<=mouse_pos.GetX())
        {
            if( (attack_frame / (_imagesARB.size()-1)) >= (_imagesARB.size()))
            {
                attack_frame = 0;
                mouse_pressed = false;
            }
            if (mouse_pressed == true)
                Screen::Draw(_imagesARB[attack_frame/(_imagesARB.size()-1)], position);
        }
        
        if(position.GetY()<=mouse_pos.GetY() && position.GetX()>=mouse_pos.GetX())
        {
            if( (attack_frame / (_imagesALB.size()-1)) >= (_imagesALB.size()))
            {
                attack_frame = 0;
                mouse_pressed = false;
            }
            if (mouse_pressed == true)
                Screen::Draw(_imagesALB[attack_frame/(_imagesALB.size()-1)], position);
            
        }
        
        
        if(position.GetY()>=mouse_pos.GetY() && position.GetX()<=mouse_pos.GetX())
        {
            if( (attack_frame / (_imagesARF.size()-1)) >= (_imagesARF.size()))
            {
                attack_frame = 0;
                mouse_pressed = false;
            }
            if (mouse_pressed == true)
                Screen::Draw(_imagesARF[attack_frame/(_imagesARF.size()-1)], position);
        }
        
        if(position.GetY()>=mouse_pos.GetY() && position.GetX()>=mouse_pos.GetX())
        {
            if( (attack_frame / (_imagesALF.size()-1)) >= (_imagesALF.size()))
            {
                attack_frame = 0;
                mouse_pressed = false;
            }
            if (mouse_pressed == true)
                Screen::Draw(_imagesALF[attack_frame/(_imagesALF.size()-1)], position);
        }
    }
    else
        attack_frame = 0;
}

void Animator::displayAnimation(Vector2 position)
{
    int tick = SDL_GetTicks();
    
    if((tick - gLastTick)>11)//
    {
        gLastTick = tick;
        frame++;
    }
    
    if (mouse_pressed == false)
    {
    /////////////////////////////Up&Right//////////////////////////////////
    
    
    if (Input::GetKey ('w') && Input::GetKey ('d')) {
        lr = true;
        if( (frame / (_imagesRB.size()-1)) >= (_imagesRB.size()))
            frame = 0;
        Screen::Draw(_imagesRB[frame/(_imagesRB.size()-1)], position);
    }
    
    /////////////////////////////Up&Left//////////////////////////////////
     else if (Input::GetKey ('w') && Input::GetKey ('a')) {
         lr=false;
         if( (frame / (_imagesLB.size()-1)) >= (_imagesLB.size()))
             frame = 0;
         Screen::Draw(_imagesLB[frame/(_imagesLB.size()-1)], position);
     }
    
    /////////////////////////////Up//////////////////////////////////
    else if (Input::GetKey ('w')){
        if(lr==true)
        {
            if( (frame / (_imagesRB.size()-1)) >= (_imagesRB.size()))
                frame = 0;
            Screen::Draw(_imagesRB[frame/(_imagesRB.size()-1)], position);
        }
        else
        {
            if( (frame / (_imagesLB.size()-1)) >= (_imagesLB.size()))
                frame = 0;
            Screen::Draw(_imagesLB[frame/(_imagesLB.size()-1)], position);
            
        }
    }
    
    /////////////////////////////Right//////////////////////////////////
    else if (Input::GetKey ('d')) {
        lr=true;
        if( (frame / (_imagesRF.size()-1)) >= (_imagesRF.size()))
            frame = 0;
        Screen::Draw(_imagesRF[frame/(_imagesRF.size()-1)], position);
    }
    
    /////////////////////////////Left//////////////////////////////////
    else if (Input::GetKey ('a')) {
        lr=false;
        if( (frame / (_imagesLF.size()-1)) >= (_imagesLF.size()))
            frame = 0;
        Screen::Draw(_imagesLF[frame/(_imagesLF.size()-1)], position);
    }
    
    /////////////////////////////Down&Right//////////////////////////////////
    else if (Input::GetKey ('s') && Input::GetKey ('a')) {
        lr=false;
        if( (frame / (_imagesLF.size()-1)) >= (_imagesLF.size()))
            frame = 0;
        Screen::Draw(_imagesLF[frame/(_imagesLF.size()-1)], position);
    }
    
    /////////////////////////////Down&Left//////////////////////////////////
    else if (Input::GetKey ('s') && Input::GetKey ('d')) {
        lr=true;
        if( (frame / (_imagesRF.size()-1)) >= (_imagesRF.size()))
            frame = 0;
        Screen::Draw(_imagesRF[frame/(_imagesRF.size()-1)], position);
    }
    
    /////////////////////////////Down//////////////////////////////////
    else if (Input::GetKey ('s')){
        if(lr==true)
        {
            if( (frame / (_imagesRF.size()-1)) >= (_imagesRF.size()))
                frame = 0;
            Screen::Draw(_imagesRF[frame/(_imagesRF.size()-1)], position);
        }
        else
        {
            if( (frame / (_imagesLF.size()-1)) >= (_imagesLF.size()))
                frame = 0;
            Screen::Draw(_imagesLF[frame/(_imagesLF.size()-1)], position);
            
        }
    }
    
    /////////////////////////////Stand//////////////////////////////////
    else{
        if (lr==true)
        {
            if( (frame / (_imagesr.size()-1)) >= (_imagesr.size()))
                frame = 0;
            Screen::Draw(_imagesr[frame/(_imagesr.size()-1)], position);
        }
        else
        {
            if( (frame / (_imagesl.size()-1)) >= (_imagesl.size()))
                frame = 0;
            Screen::Draw(_imagesl[frame/(_imagesl.size()-1)], position);
        }
    }
    }
   
}

Animator::Animator()
{
    _imagesl.push_back(Resources::LoadImage("Hero/Standl/1.png"));
    _imagesl.push_back(Resources::LoadImage("Hero/Standl/2.png"));
    _imagesl.push_back(Resources::LoadImage("Hero/Standl/3.png"));
    _imagesl.push_back(Resources::LoadImage("Hero/Standl/4.png"));
    _imagesl.push_back(Resources::LoadImage("Hero/Standl/5.png"));
    _imagesl.push_back(Resources::LoadImage("Hero/Standl/6.png"));
    
    _imagesr.push_back(Resources::LoadImage("Hero/Standr/1.png"));
    _imagesr.push_back(Resources::LoadImage("Hero/Standr/2.png"));
    _imagesr.push_back(Resources::LoadImage("Hero/Standr/3.png"));
    _imagesr.push_back(Resources::LoadImage("Hero/Standr/4.png"));
    _imagesr.push_back(Resources::LoadImage("Hero/Standr/5.png"));
    _imagesr.push_back(Resources::LoadImage("Hero/Standr/6.png"));
    
    _imagesRF.push_back(Resources::LoadImage("Hero/WalkRightFront/1.png"));
    _imagesRF.push_back(Resources::LoadImage("Hero/WalkRightFront/2.png"));
    _imagesRF.push_back(Resources::LoadImage("Hero/WalkRightFront/3.png"));
    _imagesRF.push_back(Resources::LoadImage("Hero/WalkRightFront/4.png"));
    _imagesRF.push_back(Resources::LoadImage("Hero/WalkRightFront/5.png"));
    _imagesRF.push_back(Resources::LoadImage("Hero/WalkRightFront/6.png"));
    _imagesRF.push_back(Resources::LoadImage("Hero/WalkRightFront/7.png"));
    _imagesRF.push_back(Resources::LoadImage("Hero/WalkRightFront/8.png"));
    
    _imagesLF.push_back(Resources::LoadImage("Hero/WalkLeftFront/1.png"));
    _imagesLF.push_back(Resources::LoadImage("Hero/WalkLeftFront/2.png"));
    _imagesLF.push_back(Resources::LoadImage("Hero/WalkLeftFront/3.png"));
    _imagesLF.push_back(Resources::LoadImage("Hero/WalkLeftFront/4.png"));
    _imagesLF.push_back(Resources::LoadImage("Hero/WalkLeftFront/5.png"));
    _imagesLF.push_back(Resources::LoadImage("Hero/WalkLeftFront/6.png"));
    _imagesLF.push_back(Resources::LoadImage("Hero/WalkLeftFront/7.png"));
    _imagesLF.push_back(Resources::LoadImage("Hero/WalkLeftFront/8.png"));
  
    _imagesLB.push_back(Resources::LoadImage("Hero/WalkLeftBack/1.png"));
    _imagesLB.push_back(Resources::LoadImage("Hero/WalkLeftBack/2.png"));
    _imagesLB.push_back(Resources::LoadImage("Hero/WalkLeftBack/3.png"));
    _imagesLB.push_back(Resources::LoadImage("Hero/WalkLeftBack/4.png"));
    _imagesLB.push_back(Resources::LoadImage("Hero/WalkLeftBack/5.png"));
    _imagesLB.push_back(Resources::LoadImage("Hero/WalkLeftBack/6.png"));
    _imagesLB.push_back(Resources::LoadImage("Hero/WalkLeftBack/7.png"));
    _imagesLB.push_back(Resources::LoadImage("Hero/WalkLeftBack/8.png"));
    
    _imagesRB.push_back(Resources::LoadImage("Hero/WalkRightBack/1.png"));
    _imagesRB.push_back(Resources::LoadImage("Hero/WalkRightBack/2.png"));
    _imagesRB.push_back(Resources::LoadImage("Hero/WalkRightBack/3.png"));
    _imagesRB.push_back(Resources::LoadImage("Hero/WalkRightBack/4.png"));
    _imagesRB.push_back(Resources::LoadImage("Hero/WalkRightBack/5.png"));
    _imagesRB.push_back(Resources::LoadImage("Hero/WalkRightBack/6.png"));
    _imagesRB.push_back(Resources::LoadImage("Hero/WalkRightBack/7.png"));
    _imagesRB.push_back(Resources::LoadImage("Hero/WalkRightBack/8.png"));
    
    _imagesALB.push_back(Resources::LoadImage("Hero/AttackLeftBack/1.png"));
    _imagesALB.push_back(Resources::LoadImage("Hero/AttackLeftBack/2.png"));
    _imagesALB.push_back(Resources::LoadImage("Hero/AttackLeftBack/3.png"));
    _imagesALB.push_back(Resources::LoadImage("Hero/AttackLeftBack/4.png"));
    _imagesALB.push_back(Resources::LoadImage("Hero/AttackLeftBack/5.png"));
    _imagesALB.push_back(Resources::LoadImage("Hero/AttackLeftBack/6.png"));
    _imagesALB.push_back(Resources::LoadImage("Hero/AttackLeftBack/7.png"));
    
    _imagesARB.push_back(Resources::LoadImage("Hero/AttackRightBack/1.png"));
    _imagesARB.push_back(Resources::LoadImage("Hero/AttackRightBack/2.png"));
    _imagesARB.push_back(Resources::LoadImage("Hero/AttackRightBack/3.png"));
    _imagesARB.push_back(Resources::LoadImage("Hero/AttackRightBack/4.png"));
    _imagesARB.push_back(Resources::LoadImage("Hero/AttackRightBack/5.png"));
    _imagesARB.push_back(Resources::LoadImage("Hero/AttackRightBack/6.png"));
    _imagesARB.push_back(Resources::LoadImage("Hero/AttackRightBack/7.png"));
    
    _imagesALF.push_back(Resources::LoadImage("Hero/AttackLeftFront/1.png"));
    _imagesALF.push_back(Resources::LoadImage("Hero/AttackLeftFront/2.png"));
    _imagesALF.push_back(Resources::LoadImage("Hero/AttackLeftFront/3.png"));
    _imagesALF.push_back(Resources::LoadImage("Hero/AttackLeftFront/4.png"));
    _imagesALF.push_back(Resources::LoadImage("Hero/AttackLeftFront/5.png"));
    _imagesALF.push_back(Resources::LoadImage("Hero/AttackLeftFront/6.png"));
    _imagesALF.push_back(Resources::LoadImage("Hero/AttackLeftFront/7.png"));
    
    _imagesARF.push_back(Resources::LoadImage("Hero/AttackRightFront/1.png"));
    _imagesARF.push_back(Resources::LoadImage("Hero/AttackRightFront/2.png"));
    _imagesARF.push_back(Resources::LoadImage("Hero/AttackRightFront/3.png"));
    _imagesARF.push_back(Resources::LoadImage("Hero/AttackRightFront/4.png"));
    _imagesARF.push_back(Resources::LoadImage("Hero/AttackRightFront/5.png"));
    _imagesARF.push_back(Resources::LoadImage("Hero/AttackRightFront/6.png"));
    _imagesARF.push_back(Resources::LoadImage("Hero/AttackRightFront/7.png"));
    
}