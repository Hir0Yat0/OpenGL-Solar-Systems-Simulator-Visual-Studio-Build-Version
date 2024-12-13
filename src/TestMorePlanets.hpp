#ifndef TESTMOREPLANETS_HPP
#define TESTMOREPLANETS_HPP


// #include "TestMorePlanets.hpp"
#include "TestActivation.hpp"
#if TEST_MODE == 1
#if TEST_MODE_TEST_MORE_PLANETS == 1

#include "Tester.hpp"



class TestMorePlanets: public Tester {

    private:

    

    public:

    int runTest() override;

};

#endif
#endif

#endif // TESTMOREPLANETS_HPP
