#include "TestOrbitalObjects.hpp"

#include "lib3d.hpp"

#include "OrbitalObjectFactory.hpp"
#include "OrbitalObject3D.hpp"

#include "TestActivation.hpp"

#if TEST_MODE == 1
#if TEST_MODE_TEST_ORBITAL_OBJECTS == 1

int TestOrbitalObjects::runTest() {

    auto window = GLDrawWindow();

    if (!window.initSuccess){
        std::cerr << "GLFW Window Initialization Errors" << "\n";
        return -1;
    }

    auto sphereObjectFactory = SphereObjectFactory();
    auto orbitalObjectFactory = OrbitalObjectFactory();

    auto background = sphereObjectFactory.getSharedObject3D();

    (*background).setUniformScale(5000.0f);
    (*background).angularVelocity = 0.001f;
    FrameManager::gameSpeed = 1.0f;

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
    
    (*sphere1).velocity[1] = -0.5f;
    (*sphere2).position[0] = 1.5f;


    auto sphere3 = orbitalObjectFactory.getSharedOrbitalObject3D();
    (*sphere3).velocity[1] = 1.5f;
    (*sphere3).velocity[0] = 1.5f;
    (*sphere3).position[0] = 100.0f;
    (*sphere3).position[1] = 100.0f;
    (*sphere3).setUniformScale(10.0f);
    (*sphere3).gravityToCentralObject = 1000.0f;

    (*sphere3).setAxisZ();
    (*sphere3).angularVelocity = 1.0f / (2.0f * 3.14f);

    auto sphereRenderGroup = SphereRenderGroup().getRenderGroup3D();
    auto backgroundRenderGroup = SphereRenderGroup().getRenderGroup3D("assets/galaxy-6972265_1920.jpg");

    if (!(*sphereRenderGroup).initSuccess){
        std::cerr << "Sphere Render Group Initialization Errors!" << "\n";
        return -1;
    }

    (*backgroundRenderGroup).add(background);

    (*sphereRenderGroup).add(sphere1);
    (*sphereRenderGroup).add(sphere2);
    (*sphereRenderGroup).add(sphere3);

    auto sphereRenderGroupManager = RenderGroup3DManager::makeNew();

    constexpr int backgroundGroupID = 0;
    constexpr int sphereGroupID = 1;

    (*sphereRenderGroupManager).addNewGroup(backgroundGroupID,std::move( backgroundRenderGroup));
    (*sphereRenderGroupManager).addNewGroup(sphereGroupID,std::move( sphereRenderGroup));

    int exitcode = window.drawWindow(std::move(sphereRenderGroupManager));

    return exitcode;

    // return 0;
}

#endif
#endif
