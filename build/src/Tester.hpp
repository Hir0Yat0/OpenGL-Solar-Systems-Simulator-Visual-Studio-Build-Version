#ifndef TESTER_HPP
#define TESTER_HPP

// #include "Tester.hpp"

class Tester {

    private:

    

    public:

    static constexpr const char * const TEST_TEXTURE_SRC = "assets/sky-and-grass-24.jpg";
    static constexpr const char * const TEST_VERT_SHADER_SRC = "src/shaders/object3d.vert";
    static constexpr const char * const TEST_FRAG_SHADER_SRC = "src/shaders/object3d.frag";

    virtual ~Tester(){};

    virtual int runTest() = 0;

};


#endif // TESTER_HPP
