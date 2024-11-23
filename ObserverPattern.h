// @author Anbu Krishnan - anbu@iastate.edu
#pragma once
#include <vector>
#include <algorithm>

// Observer interface
template <class T>
class Observer
{
public:
    virtual void update(T *observableData) = 0; // virtual function
    virtual ~Observer() = default;              // virtual destructor
};

// Observable base class
template <class T>
class Observable
{
protected:
    std::vector<Observer<T> *> observers; // List of observers

public:
    // Registers an observer to the list of observers if it's not already present
    void registerObserver(Observer<T> *o)
    {
        if (std::find(observers.begin(), observers.end(), o) == observers.end())
        {
            observers.push_back(o);
        }
    }

    // Removes an observer from the list of observers
    void removeObserver(Observer<T> *o)
    {
        observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
    }

    // Notifies all registered observers about a change + passes the observable data (T*) to each observers update method
    void notifyObservers(T *observableData)
    {
        for (auto observer : observers)
        {
            observer->update(observableData);
        }
    }

    virtual ~Observable() = default; // Virtual destructor
};
