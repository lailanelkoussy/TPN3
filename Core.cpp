#include "Core.hpp"

using namespace std;

template<typename T>
int Core<T>::count = 0;

template<typename T>
Core<T> &Core<T>::map(bool (*func)(T &)) {
    degradation++;
    vector<T>* newValues = new vector<T>;
    for (unsigned long i = 0; i < values->size(); i++) {
        if(func(values->at(i))){
            newValues->push_back(values->at(i));
        }
    }
    values = newValues;
    return *this;
}

template<typename T>
Core<T>::Core() {
    values = nullptr;
    count++;
    degradation = 0;
}

template<typename T>
int Core<T>::getCount() {
    return count;
}

template<typename R>
ostream &operator<<(ostream &out, const Core<R> *core) {
    out << "Core id: " << core->id << endl;
    out << "Core degradation: " << core->degradation << endl;
    if (core->values == nullptr || core->degradation == 0)
        return out;

    out << "List of elements in core: " << endl;

    for (unsigned long i = 0; i < core->values->size(); i++) {
        out << core->values->at(i) << endl;
    }
    return out;
}

template<typename T>
void Core<T>::set(vector<T> *collection) {
 values = collection;
}

template<typename T>
template<class U>
U Core<T>::reduce(U (*func)(U, T), U u) {
    degradation++;
    U result = func(u, values->at(0));
    for(int i = 1; i<values->size(); i++){
         result = func(result, values->at(i));
    }
    return result;


}

template<typename T>
int Core<T>::getDegradation() const {
    return degradation;
}

template<typename T>
int Core<T>::getId() const {
    return id;
}

template<typename T>
vector<T> *Core<T>::getValues() {
    return values;
}






