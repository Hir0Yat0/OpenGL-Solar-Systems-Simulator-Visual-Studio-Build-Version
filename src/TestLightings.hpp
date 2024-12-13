#ifndef TESTLIGHTINGS_HPP
#define TESTLIGHTINGS_HPP

#include "TestActivation.hpp"

#if TEST_MODE == 1
#if TEST_MODE_TEST_LIGHTINGS == 1
// #include "TestLightings.hpp"
#include "Tester.hpp"

class TestLightings: public Tester {

    private:

    

    public:

    virtual ~TestLightings() = default;

    int runTest() override;

};

#endif
#endif

#endif // TESTLIGHTINGS_HPP
