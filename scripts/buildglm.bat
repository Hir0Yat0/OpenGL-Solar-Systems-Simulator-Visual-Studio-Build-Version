cd include\glm
cmake -DGLM_BUILD_TESTS=OFF -DBUILD_SHARED_LIBS=ON -B build . -G "MinGW Makefiles"
cmake --build build -- all
cmake --build build -- install
