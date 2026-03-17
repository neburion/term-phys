#pragma once
#include "core/Object.hpp"
#include <string>
#include <vector>
#include <unordered_map>

class Scene{
public:
    void   addObject(Object &&toAdd);
    void   removeObject(Object &toRemove);
    int    getObejectsNumber();
    Object &getObjectByName(std::string toGet);
    Object &getObjectByIndex(int index);
private:
    std::vector<std::unique_ptr<Object>> objects;
    std::unordered_map<std::string, int> indexMap;
};
