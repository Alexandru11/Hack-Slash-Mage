//
//  ResourceManager.h
//  LiteEngine2D
//
//  Created by Alex on 19/05/16.
//  Copyright © 2016 University of Bucharest. All rights reserved.
//

#ifndef ResourceManager_h
#define ResourceManager_h

#include <map>
#include "Object.h"

class ResourceManager {
    std::map <std::string, Object*> resourcesMap;
    ResourceManager();
    static ResourceManager *s;
public:
    static ResourceManager* Instance();
    ~ResourceManager();

    void addResource(std::string, Object*);
    Object* getResource(std::string);
    
    
    
    
    
    
    
};















#endif /* ResourceManager_h */
