#ifndef S21_STACK
#define S21_STACK

#include <iostream>
#include <exception>
#include "list"

namespace s21{

template<typename T, typename Container = s21::list<T>>
class Stack{
    public:
        using value_type = T;
        using pointer = T*;
        using reference = T &;
        using const_reference = const T &;
        using size_type = size_t;

    private:
        Container container_;
        // pointer next_;
        // value_type value;

// -----------------------------------------------------------------------------------------------------------------------------//
// ----------------------------STACK-MEMBER-FUNCTIONS---------------------------------------------------------------------------//
    public:
        stack() : head(nullptr){}

}





}

#endif // S21_STACK
