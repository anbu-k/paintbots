// @author Anbu Krishnan - anbu@iastate.edu
#ifndef ITEST_H
#define ITEST_H

class ITest
{
public:
    // virtual method that will be overridden by subclasses
    virtual bool doTests() const = 0;

    // virtual destructor
    virtual ~ITest() {}
};

#endif