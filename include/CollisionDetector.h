//
//  CollisionDetector.h
//  LiteEngine2D
//
//  Created by Alex on 01/06/16.
//  Copyright © 2016 University of Bucharest. All rights reserved.
//

#ifndef CollisionDetector_h
#define CollisionDetector_h

class CollisionDetector
{
private:
    static CollisionDetector* Col;
public:
    static CollisionDetector* Instance();
    CollisionDetector();
};

#endif /* CollisionDetector_h */
