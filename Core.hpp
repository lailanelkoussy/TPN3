#ifndef CORE
#define CORE


#include <vector>
#include <iostream>



template <typename T>
class MapReduce;

template <typename T>
class Core {

private:
    //TODO: faire attention au pb count/id avec les deletes possibles
    Core();
    static int count;
    const int id{count};
    //TODO: what is degradation?
    int degradation;
    std::vector<T>* values;
    std::vector<T>* getValues();
    template<typename R> friend std::ostream& operator<<(std::ostream&, const Core<R>*);
    template<typename R> friend std::vector<Core<R>*> initializeVector();
    friend MapReduce<T> *MapReduce<T>::map(bool (*func)(T &));

public:
    void set(std::vector<T>*);
    static int getCount();
    int getId() const;
    int getDegradation() const;
    Core<T> & map(bool (*func)(T&));
    template<class U> U reduce(U (*func)(U, T), U);
};


#endif




