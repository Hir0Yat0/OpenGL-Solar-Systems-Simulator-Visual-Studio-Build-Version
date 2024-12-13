#ifndef TESTSKYBOXTRACKING_HPP
#define TESTSKYBOXTRACKING_HPP

// #include "TestSkyBoxTracking.hpp"

#include "TestActivation.hpp"

#if TEST_MODE == 1
#if TEST_MODE_TEST_SKYBOX_TRACKING == 1

#include "Tester.hpp"

class TestSkyBoxTracking: public Tester {

    private:

    

    public:

    int runTest() override;

};

#endif
#endif

#endif // TESTSKYBOXTRACKING_HPP
