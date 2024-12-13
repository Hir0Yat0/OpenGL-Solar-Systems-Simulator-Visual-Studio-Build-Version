#include "TestCamera.hpp"

#include "Object3D.hpp"
#include "RenderGroup3D.hpp"
#include "GLDrawWindow.hpp"
#include "SphereObjectFactory.hpp"
#include "SphereRenderGroup.hpp"

int TestCamera::runTest() {

    auto window = GLDrawWindow();

    if (!window.initSuccess){
        std::cerr << "GLFW Window Initialization Errors" << "\n";
        return -1;
    }

    auto sphereObjectFactory = SphereObjectFactory();

    auto sphere1 = sphereObjectFactory.getSharedObject3D();
    auto sphere2 = sphereObjectFactory.getSharedObject3D();
    // (*sphere1).angularVelocity[0] = 0.5f;
    // (*sphere1).orientation[0] = 3.14;
    // (*sphere1).angularVelocity[1] = 0.5f;
    // (*sphere1).angularVelocity[2] = 0.5f;
    (*sphere1).setAxis(0,1);
    (*sphere1).angularVelocity = 1;

    (*sphere1).scale[0] = 0.3f;
    (*sphere1).scale[1] = 0.3f;
    (*sphere1).scale[2] = 0.3f;
    (*sphere2).scale[0] = 0.3f;
    (*sphere2).scale[1] = 0.3f;
    (*sphere2).scale[2] = 0.3f; 

    (*sphere1).velocity[0] = -0.5f;
    (*sphere2).position[0] = 1.5f;

    auto sphereRenderGroup = SphereRenderGroup().getRenderGroup3D();

    if (!(*sphereRenderGroup).initSuccess){
        std::cerr << "Sphere Render Group Initialization Errors!" << "\n";
        return -1;
    }

    (*sphereRenderGroup).add(sphere1);
    (*sphereRenderGroup).add(sphere2);

    int exitcode = window.drawWindow(std::move(sphereRenderGroup));

    return exitcode;

    // return 0;
}