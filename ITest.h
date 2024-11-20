// @author Anbu Krishnan - anbu@iastate.edu
#ifndef ITEST_H
#define ITEST_H

class ITest {
public:
    // Pure virtual method that must be overridden by subclasses
    virtual bool doTests() const = 0;

    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~ITest() {}
};

#endif // ITEST_H
