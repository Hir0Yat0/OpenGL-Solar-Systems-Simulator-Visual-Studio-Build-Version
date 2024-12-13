#ifndef TESTORBITALOBJECTS_HPP
#define TESTORBITALOBJECTS_HPP

// #include "TestOrbitalObjects.hpp"

#include "TestActivation.hpp"

#if TEST_MODE == 1
#if TEST_MODE_TEST_ORBITAL_OBJECTS == 1

#include "Tester.hpp"

class TestOrbitalObjects: Tester {

    private:

    

    public:

    int runTest() override;

};

#endif
#endif

#endif // TESTORBITALOBJECTS_HPP
