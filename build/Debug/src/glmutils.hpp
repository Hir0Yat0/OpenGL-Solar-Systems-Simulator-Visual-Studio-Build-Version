#ifndef GLMUTILS_HPP
#define GLMUTILS_HPP

#include <iostream>

#include "glmlib.hpp"

#define DBGEXPRVEC3(vec3) {std::cerr << #vec3 << ": [" << vec3.x <<  ", " << vec3.y << ", " << vec3.z << ", ]\n";}
#define DBGEXPROUTVEC3(vec3) {std::cout << #vec3 << ": [" << vec3.x <<  ", " << vec3.y << ", " << vec3.z << ", ]\n";}

#endif // GLMUTILS_HPP
