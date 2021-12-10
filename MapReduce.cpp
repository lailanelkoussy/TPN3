#include "MapReduce.hpp"

using namespace std;

template<typename T>
vector<Core<T> *> initializeVector() {
    vector<Core<T> *> myVector;
    for (int i = 0; i < 4; i++) {
        myVector.push_back(new Core<T>());
    }
    return myVector;
}


template<typename T>
vector<Core<T>*> MapReduce<T>::cores{initializeVector<T>()};


template<typename T>
MapReduce<T>::MapReduce(std::vector<T> *val): values(val) {

}

template<typename T>
Core<T> *MapReduce<T>::chooseCore() {
    Core<T> *corePoint = cores[0];
    for (unsigned long i = 1; i < cores.size(); i++) {
        if (cores[i]->getDegradation() < corePoint->getDegradation())
            corePoint = cores[i];
    }
    corePoint->set(values);
    return corePoint;
}

template<typename T>
void MapReduce<T>::afficherCores() {
    cout << "****Coeurs disponibles****" << endl;
    for (unsigned long i = 0; i < cores.size(); i++)
        cout<<"id : "<<cores[i]->getId()<<" |  degradation  "<<cores[i]->getDegradation()<<endl;
}

template<typename T>
Core<T>* MapReduce<T>::getCore() {
    return core;

}

template<typename T>
MapReduce<T> *MapReduce<T>::map(bool (*func)(T &)) {
    core = chooseCore();
    core->set(values);
    core->map(func);
    values = core->getValues();
    return this;
}


