#include "Core.hpp"

using namespace std;

template<typename T>
int Core<T>::count = 0;

template<typename T>
Core<int> &Core<T>::map(bool (*func)(T &)) {
    for (unsigned long i = 0; i < values->size(); i++) {
        func(values->at(i));
    }
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
    if (core->values == nullptr)
        return out;

    out << "List of elements in core: " << endl;

    for (unsigned long i = 0; i < core->values->size(); i++) {
        out << core->values->at(i) << endl;
    }
    return out;
}

template<typename T>
void Core<T>::set(const vector<T> &collection) {
    values->clear();
    for (unsigned long i = 0; i < collection.size(); i++)
        values->push_back(collection[i]);
}

template<typename T>
template<class U>
U Core<T>::reduce(U (*func)(U, T), U u) {
    return reduceRecc(func, u, 0);
}

template<typename T>
template<class U>
U Core<T>::reduceRecc(U (*func)(U, T), U u, int i) {

    if (i == values->size() - 1)
        return func(u, values->at(i));
    else
        return reduceRecc(func, func(u, values->at(i)), i++);


}

template<typename T>
int Core<T>::getDegradation() const {
    return degradation;
}

template<typename T>
int Core<T>::getId() const {
    return id;
}






