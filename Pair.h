// @author Anbu Krishnan - anbu@iastate.edu
#ifndef PAIR_H
#define PAIR_H

// template class to store and mange two pointers of the same type
template <typename T>
class Pair
{
private:
    T *first;
    T *second;

public:
    // constructor
    Pair(T *first, T *second) : first(first), second(second) {}

    T *getFirst() const { return first; }   // * to the first object
    T *getSecond() const { return second; } // * to the 2nd object

    // overloaded [] operator to acces objects by index
    T *operator[](int index) const
    {
        if (index == 1)
            return first;
        if (index == 2)
            return second;
        return nullptr;
    }
};

#endif
