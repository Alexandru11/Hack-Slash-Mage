

#ifndef Background_h
#define Background_h

#include "SceneObject.h"
#include "Image.h"
#include "Vector2.h"

class Background: public SceneObject
{
    
    Image* _image;

public:
    Background();
    ~Background();
    void Draw();
    
};

#endif
