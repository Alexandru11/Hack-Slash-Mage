#include "MonsterAnimator.h"
#include "Resources.h"
#include "Screen.h"



MonsterAnimator::~MonsterAnimator()
{
    for (auto iterator1: _imagesl)
        delete iterator1;
    for (auto iterator1: _imagesr)
        delete iterator1;
}

int MonsterAnimator::frame = 0;
int MonsterAnimator::gLastTick = 0;

void MonsterAnimator::displayAnimation(Vector2 monster_pos, Vector2 hero_pos)
{
    int tick = SDL_GetTicks();
    
    if((tick - gLastTick)>90) //
    {
        gLastTick = tick;
        frame++;
    }
    
    if (monster_pos.GetX() <= hero_pos.GetX())
        {
            if( (frame / (_imagesr.size()-1)) >= (_imagesr.size()))
                frame = 0;
            Screen::Draw(_imagesr[frame/(_imagesr.size()-1)], monster_pos);
    
        }
    else if (monster_pos.GetX() >= hero_pos.GetX())
        {
            if( (frame / (_imagesl.size()-1)) >= (_imagesl.size()))
                frame = 0;
            Screen::Draw(_imagesl[frame/(_imagesl.size()-1)], monster_pos);
        }
    
}

MonsterAnimator::MonsterAnimator(std::string s)
{
    if (s=="Monster1")
    {
        _imagesl.push_back(Resources::LoadImage("Monsters/Monster1/Left/1.png"));
        _imagesl.push_back(Resources::LoadImage("Monsters/Monster1/Left/2.png"));
        _imagesl.push_back(Resources::LoadImage("Monsters/Monster1/Left/3.png"));
        _imagesl.push_back(Resources::LoadImage("Monsters/Monster1/Left/4.png"));
        _imagesl.push_back(Resources::LoadImage("Monsters/Monster1/Left/5.png"));
        
        _imagesr.push_back(Resources::LoadImage("Monsters/Monster1/Right/1.png"));
        _imagesr.push_back(Resources::LoadImage("Monsters/Monster1/Right/2.png"));
        _imagesr.push_back(Resources::LoadImage("Monsters/Monster1/Right/3.png"));
        _imagesr.push_back(Resources::LoadImage("Monsters/Monster1/Right/4.png"));
        _imagesr.push_back(Resources::LoadImage("Monsters/Monster1/Right/5.png"));
    }
    
    else if (s=="Monster2")
    {
        _imagesl.push_back(Resources::LoadImage("Monsters/Monster2/Left/1.png"));
        _imagesl.push_back(Resources::LoadImage("Monsters/Monster2/Left/2.png"));
        _imagesl.push_back(Resources::LoadImage("Monsters/Monster2/Left/3.png"));
        
        _imagesr.push_back(Resources::LoadImage("Monsters/Monster2/Right/1.png"));
        _imagesr.push_back(Resources::LoadImage("Monsters/Monster2/Right/2.png"));
        _imagesr.push_back(Resources::LoadImage("Monsters/Monster2/Right/3.png"));
    }
    
    else if (s=="Monster3")
    {
        _imagesl.push_back(Resources::LoadImage("Monsters/Monster3/Left/1.png"));
        _imagesl.push_back(Resources::LoadImage("Monsters/Monster3/Left/2.png"));
        _imagesl.push_back(Resources::LoadImage("Monsters/Monster3/Left/3.png"));
        _imagesl.push_back(Resources::LoadImage("Monsters/Monster3/Left/4.png"));
        _imagesl.push_back(Resources::LoadImage("Monsters/Monster3/Left/5.png"));
        _imagesl.push_back(Resources::LoadImage("Monsters/Monster3/Left/6.png"));
        
        _imagesr.push_back(Resources::LoadImage("Monsters/Monster3/Right/1.png"));
        _imagesr.push_back(Resources::LoadImage("Monsters/Monster3/Right/2.png"));
        _imagesr.push_back(Resources::LoadImage("Monsters/Monster3/Right/3.png"));
        _imagesr.push_back(Resources::LoadImage("Monsters/Monster3/Right/4.png"));
        _imagesr.push_back(Resources::LoadImage("Monsters/Monster3/Right/5.png"));
        _imagesr.push_back(Resources::LoadImage("Monsters/Monster3/Right/6.png"));
    }
}