#include "TestLightings.hpp"

#include "TestActivation.hpp"

#if TEST_MODE == 1
#if TEST_MODE_TEST_LIGHTINGS == 1

#include "lib3d.hpp"
#include "PlanetsGroupLoader.hpp"

int TestLightings::runTest() {

    auto window = GLDrawWindow();

    if (!window.initSuccess){
        std::cerr << "GLFW Window Initialization Errors" << "\n";
        return -1;
    }

    auto renderGroup3DManager = RenderGroup3DManager::makeNew();

    auto planets = PlanetsGroupLoader().getPlanets(window);

    for (auto &[groupid,planetgroup] : (*planets)){
        (*renderGroup3DManager).addNewGroup(groupid,std::move(planetgroup));
    }

    constexpr float camPosOffset = Scales::starSunDiameterScaledKM + 100.0f;

    window.camera.Position = glm::vec3(camPosOffset);

    return window.drawWindow(std::move( renderGroup3DManager));
    // return 0;
}

#endif
#endif
