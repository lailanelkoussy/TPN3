#ifndef MAPREDUCE
#define MAPREDUCE


#include <vector>
#include <iostream>
#include "Core.hpp"

template<typename T>
class MapReduce {
private:
    std::vector<T>* values;
    static std::vector<Core<T>*> cores;
    Core<T>* core;

public:
    MapReduce(std::vector<T>*);
    Core<T>* chooseCore();
    MapReduce<T>* map(bool (*func)(T&));
    static void afficherCores();
    Core<T>* getCore();
};




#endif

