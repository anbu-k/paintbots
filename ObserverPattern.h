// @author Anbu Krishnan - anbu@iastate.edu
#pragma once
#include <vector>
#include <algorithm>

// Observer interface
template <class T>
class Observer {
public:
    virtual void update(T* observableData) = 0; // Pure virtual function
    virtual ~Observer() = default;             // Virtual destructor
};

// Observable base class
template <class T>
class Observable {
protected:
    std::vector<Observer<T>*> observers; // List of observers

public:
    void registerObserver(Observer<T>* o) {
        if (std::find(observers.begin(), observers.end(), o) == observers.end()) {
            observers.push_back(o);
        }
    }

    void removeObserver(Observer<T>* o) {
        observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
    }

    void notifyObservers(T* observableData) {
        for (auto observer : observers) {
            observer->update(observableData);
        }
    }

    virtual ~Observable() = default; // Virtual destructor
};
