//
//  BulletController.h
//  LiteEngine2D
//
//  Created by Alex on 14/05/16.
//  Copyright © 2016 University of Bucharest. All rights reserved.
//

#ifndef BulletController_h
#define BulletController_h

#include "Bullet.h"
#include "CharObject.h"
#include <vector>

class BulletController{

    std::vector <Bullet*> _bulletVector;
    CharObject* _hero;
    
public:
    BulletController(CharObject*);
    ~BulletController();
    
    void Update();
    void Display();
    void Clear();
    
    void loadBullet(Bullet *);
    
    std::vector<Bullet*>& getBullets();
};


#endif /* BulletController_h */
