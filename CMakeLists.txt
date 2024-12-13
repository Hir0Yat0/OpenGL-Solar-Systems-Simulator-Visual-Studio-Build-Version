cmake_minimum_required(VERSION 3.18)

project(SSS VERSION 0.1.0 DESCRIPTION "OpenGL Solar Systems Simulations" LANGUAGES CXX C)

# debug flags

# set(CMAKE_CXX_FLAGS "-O0 -fno-elide-constructors -pedantic-errors -ansi -Wextra -Wall     -Winit-self -Wold-style-cast -Woverloaded-virtual -Wuninitialized -Wmissing-declarations    -Winit-self -std=c++98")

# set(CMAKE_CXX_FLAGS "-O0 -fno-elide-constructors -pedantic-errors -ansi -Wextra -Wall  -Weffc++   -Winit-self -Woverloaded-virtual -Wuninitialized -Wmissing-declarations    -Winit-self")
# set(CMAKE_CXX_FLAGS "-O0 -fno-elide-constructors -pedantic-errors -ansi -Wextra -Wall  -Weffc++   -Winit-self  -Woverloaded-virtual -Wuninitialized -Wmissing-declarations    -Winit-self")

# set (CMAKE_CXX_FLAGS "-Weffc++")

# find_library(LIBGLFW3DLL )

# set(CMAKE_VERBOSE_MAKEFILE ON)


add_executable(sss 
            src/main.cpp 
            src/glad.c
            src/glmlib.hpp
            src/GLDrawWindow.cpp
            src/GLDrawWindow.hpp
            src/Shader.cpp
            src/Shader.hpp
            src/Shape.cpp
            src/Shape.hpp
            # src/ShapeTextured.cpp
            # src/ShapeTextured.hpp
            # src/ShapeNoTexture.cpp
            # src/ShapeNoTexture.hpp
            src/stb_image.h
            src/Texture.cpp
            src/Texture.hpp
            src/TextureLoader.cpp
            src/TextureLoader.hpp
            # src/Vec3D.hpp
            src/Utils.hpp
            src/ShapeFactory.hpp
            # src/ShapeFactory.cpp
            src/SphereFactory.hpp
            src/SphereFactory.cpp
            # src/FrameManager.hpp
            # src/FrameManager.cpp
            # src/IDManager.hpp
            # src/IDManager.cpp
            # src/Object3D.hpp
            # src/Object3D.cpp
            # src/RenderGroup3D.hpp
            # src/RenderGroup3D.cpp
            # src/RenderGroup3DManager.hpp
            # src/RenderGroup3DManager.cpp
            # src/SphereObjectFactory.hpp
            # src/SphereObjectFactory.cpp
            # src/TestRenderGroup.hpp
            # src/TestRenderGroup.cpp
            src/Tester.hpp
            # src/Tester.cpp
            src/ShaderLoader.hpp
            src/ShaderLoader.cpp
            src/TestSphereRender.hpp
            src/TestSphereRender.cpp
            src/FrameManager.hpp
            src/FrameManager.cpp
            src/IDManager.hpp
            src/IDManager.cpp
            src/Object3D.hpp
            src/Object3D.cpp
            src/RenderGroup3D.hpp
            src/RenderGroup3D.cpp
            src/SphereObjectFactory.hpp
            src/SphereObjectFactory.cpp
            src/SphereRenderGroup.hpp
            src/SphereRenderGroup.cpp
            src/SphereRenderGroup.hpp
            src/Object3DFactory.hpp
            src/TestRenderGroup3D.hpp
            src/TestRenderGroup3D.cpp
            src/Tests.hpp
            src/TestRender2Objects.hpp
            src/TestRender2Objects.cpp
            src/Camera.hpp
            src/Camera.cpp
            src/TestCamera.hpp
            src/TestCamera.cpp
            src/TestBackground.hpp
            src/TestBackground.cpp
            src/RenderGroup3DManager.hpp
            src/RenderGroup3DManager.cpp
            src/lib3d.hpp
            src/OrbitalMovement.hpp
            src/OrbitalMovement.cpp
            src/OrbitalObject3D.hpp
            src/OrbitalObject3D.cpp
            src/OrbitalObjectFactory.hpp
            src/OrbitalObjectFactory.cpp
            src/TestOrbitalObjects.hpp
            src/TestOrbitalObjects.cpp
            src/TestOrbitAroundObject.hpp
            src/TestOrbitAroundObject.cpp
            src/RenderGroupID.hpp
            src/TestSkyBoxTracking.hpp
            src/TestSkyBoxTracking.cpp
            src/Object3DTracker.hpp
            src/Object3DTracker.cpp
            src/PlanetsGroupLoader.hpp
            # src/PlanetsGroupLoader.cpp
            src/TestMorePlanets.hpp
            src/TestMorePlanets.cpp
            src/DebugLevel.hpp
            src/Scales.hpp
            src/TestActivation.hpp
            src/TestLightings.hpp
            src/TestLightings.cpp
        

)

# target_compile_options(sss PRIVATE -Werror -Wextra -g -std=c++23)
#target_compile_options(sss PRIVATE -Werror -Wextra -g)
target_compile_features(sss PUBLIC cxx_std_23)

target_include_directories(sss PUBLIC include)
# target_include_directories(sss PUBLIC lib)
target_link_directories(sss PUBLIC lib)
# target_link_libraries(sss PRIVATE glfw3)
# target_link_libraries(sss PUBLIC -lglfw3dll)
# target_link_libraries(sss PUBLIC -Iinclude -Llib)

add_custom_command(
    TARGET sss POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/glfw3.dll
        $<TARGET_FILE_DIR:sss>
)