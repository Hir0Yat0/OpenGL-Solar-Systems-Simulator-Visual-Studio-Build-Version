#include<iostream>
#include<stdlib.h>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Utils.hpp"

#include "Tester.hpp"
#include "Tests.hpp"

#include"glmlib.hpp"

int main(){
    
    std::cout << "Hello Worlds!" << "\n";
    
    auto tester = TestLightings();

    int exitcode = tester.runTest();

    DBGEXPR(exitcode);

    return exitcode;
}
