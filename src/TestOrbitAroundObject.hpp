#ifndef TESTORBITAROUNDOBJECT_HPP
#define TESTORBITAROUNDOBJECT_HPP

// #include "TestOrbitAroundObject.hpp"

#include "TestActivation.hpp"

#if TEST_MODE == 1
#if TEST_MODE_TEST_ORBIT_AROUND_OBJECT == 1

#include "Tester.hpp"

class TestOrbitAroundObject: public Tester {

    private:

    

    public:

    int runTest() override;

};

#endif
#endif

#endif // TESTORBITAROUNDOBJECT_HPP
