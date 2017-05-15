#include "ResourceManager.h"

#include <iostream>


ResourceManager::ResourceManager()
{
    
}

ResourceManager::~ResourceManager()
{
    delete s;
}

ResourceManager* ResourceManager::s(new ResourceManager);

ResourceManager* ResourceManager::Instance()
{
    return s;
}

void ResourceManager::addResource(std::string a, Object *b)
{
    resourcesMap[a]=b;
}

Object* ResourceManager::getResource(std::string a)
{
    return resourcesMap[a];
}