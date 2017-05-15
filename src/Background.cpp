#include "Background.h"
#include "Resources.h"
#include "Screen.h"


Background::Background()
{
    _image = Resources::LoadImage("background.png");
    
}

Background::~Background()
{
    delete _image;
}


void Background::Draw()
{
    Screen::Draw (_image, Vector2(0,720));
}