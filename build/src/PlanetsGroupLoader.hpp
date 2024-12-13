#ifndef PLANETSGROUPLOADER_HPP
#define PLANETSGROUPLOADER_HPP

// #include "PlanetsGroupLoader.hpp"
#include <memory>
#include <vector>
#include <unordered_map>

#include "RenderGroup3D.hpp"
#include "Object3D.hpp"
#include "SphereRenderGroup.hpp"
#include "OrbitalObjectFactory.hpp"
#include "OrbitalObject3D.hpp"
#include "RenderGroupID.hpp"
#include "Object3DTracker.hpp"
#include "GLDrawWindow.hpp"

#include "Scales.hpp"   

class PlanetsGroupLoader {

    private:

    inline std::unique_ptr<RenderGroup3D> getPlanetMercury(std::weak_ptr<Object3D> centralObject) const{

        // get planets
        auto orbitalObjectFactory = OrbitalObjectFactory();
        auto planetMercury = orbitalObjectFactory.getSharedOrbitalObject3D();
        // configure planets
        (*planetMercury).setUniformScale(Scales::planetMercuryDiameterScaledKM);
        (*planetMercury).setAxisY();
        (*planetMercury).angularVelocity = 1.0f;
        (*planetMercury).position[0] = Scales::planetDistanceLinearOffsetKM + Scales::planetDistanceLinearKM * 1.0f;
        (*planetMercury).velocity[2] = -10.0f * 7.0f * 1.0f;//2.0f;   
        (*planetMercury).gravityToCentralObject = Scales::planetMercuryDiameterKM * Scales::gravityScale * 1.5f;
        (*planetMercury).centralObject = centralObject;

        // add planets
        auto planetMercuryRenderGroup = SphereRenderGroup().getRenderGroup3D("assets/2k_mercury.jpg");
        (*planetMercuryRenderGroup).add(planetMercury);


        return planetMercuryRenderGroup;


    };

    inline std::unique_ptr<RenderGroup3D> getPlanetVenus(std::weak_ptr<Object3D> centralObject) const{

        // get planets
        auto orbitalObjectFactory = OrbitalObjectFactory();
        auto planetVenus = orbitalObjectFactory.getSharedOrbitalObject3D();
        // configure planets
        (*planetVenus).setUniformScale(Scales::planetVenusDiameterScaledKM);
        (*planetVenus).setAxisY();
        (*planetVenus).angularVelocity = -1.0f;
        (*planetVenus).position[0] = Scales::planetDistanceLinearOffsetKM + Scales::planetDistanceLinearKM * 2.0f;
        (*planetVenus).velocity[2] = -80.0f;   
        (*planetVenus).gravityToCentralObject = Scales::planetVenusDiameterKM * Scales::gravityScale;
        (*planetVenus).centralObject = centralObject;

        // add planets
        auto planetVenusRenderGroup = SphereRenderGroup().getRenderGroup3D("assets/2k_venus_surface.jpg");
        (*planetVenusRenderGroup).add(planetVenus);


        return planetVenusRenderGroup;


    };

    inline std::unique_ptr<RenderGroup3D> getPlanetEarth(std::weak_ptr<Object3D> centralObject) const{

        // get planets
        auto orbitalObjectFactory = OrbitalObjectFactory();
        auto planetEarth = orbitalObjectFactory.getSharedOrbitalObject3D();
        // configure planets
        (*planetEarth).setUniformScale(Scales::planetEarthDiameterScaledKM);
        (*planetEarth).setAxisY();
        (*planetEarth).angularVelocity = 1.0f;
        (*planetEarth).position[0] = Scales::planetDistanceLinearOffsetKM + Scales::planetDistanceLinearKM * 3.0f;
        (*planetEarth).velocity[2] = -80.0f;   
        (*planetEarth).gravityToCentralObject = Scales::planetEarthDiameterKM * Scales::gravityScale;
        (*planetEarth).centralObject = centralObject;

        // add planets
        auto planetEarthRenderGroup = SphereRenderGroup().getRenderGroup3D("assets/2k_earth_daymap.jpg");
        (*planetEarthRenderGroup).add(planetEarth);


        return planetEarthRenderGroup;


    };

    inline std::unique_ptr<RenderGroup3D> getPlanetMars(std::weak_ptr<Object3D> centralObject) const{

        // get planets
        auto orbitalObjectFactory = OrbitalObjectFactory();
        auto planetMars = orbitalObjectFactory.getSharedOrbitalObject3D();
        // configure planets
        (*planetMars).setUniformScale(Scales::planetMarsDiameterScaledKM);
        (*planetMars).setAxisY();
        (*planetMars).angularVelocity = 1.0f;
        (*planetMars).position[0] = Scales::planetDistanceLinearOffsetKM + Scales::planetDistanceLinearKM * 4.0f;
        (*planetMars).velocity[2] = -20.0f * 1.0f * 1.0f * 2.5f ;   
        // (*planetMars).gravityToCentralObject = Scales::planetMarsDistanceFromSunKM ;
        // (*planetMars).gravityToCentralObject = Scales::planetMarsDistanceFromSunScaledKM ;
        (*planetMars).gravityToCentralObject = Scales::planetMarsDiameterKM * Scales::gravityScale;
        (*planetMars).centralObject = centralObject;

        // add planets
        auto planetMarsRenderGroup = SphereRenderGroup().getRenderGroup3D("assets/2k_mars.jpg");
        (*planetMarsRenderGroup).add(planetMars);


        return planetMarsRenderGroup;


    };

    inline std::unique_ptr<RenderGroup3D> getPlanetJupiter(std::weak_ptr<Object3D> centralObject) const{

        // get planets
        auto orbitalObjectFactory = OrbitalObjectFactory();
        auto planetJupiter = orbitalObjectFactory.getSharedOrbitalObject3D();
        // configure planets
        (*planetJupiter).setUniformScale(Scales::planetJupiterDiameterScaledKM);
        (*planetJupiter).setAxisY();
        (*planetJupiter).angularVelocity = 1.0f;
        (*planetJupiter).position[0] = Scales::planetDistanceLinearOffsetKM + Scales::planetDistanceLinearKM * 5.0f;
        (*planetJupiter).velocity[2] = -10.0f * 10.0f * 2.0f * 1.0f;   
        (*planetJupiter).gravityToCentralObject = Scales::planetJupiterDiameterKM  * Scales::gravityScale;
        (*planetJupiter).centralObject = centralObject;

        // add planets
        auto planetJupiterRenderGroup = SphereRenderGroup().getRenderGroup3D("assets/2k_jupiter.jpg");
        (*planetJupiterRenderGroup).add(planetJupiter);


        return planetJupiterRenderGroup;


    };

    inline std::unique_ptr<RenderGroup3D> getPlanetSaturn(std::weak_ptr<Object3D> centralObject) const{

        // get planets
        auto orbitalObjectFactory = OrbitalObjectFactory();
        auto planetSaturn = orbitalObjectFactory.getSharedOrbitalObject3D();
        // configure planets
        (*planetSaturn).setUniformScale(Scales::planetSaturnDiameterScaledKM);
        (*planetSaturn).setAxisY();
        (*planetSaturn).angularVelocity = 1.0f;
        (*planetSaturn).position[0] = Scales::planetDistanceLinearOffsetKM + Scales::planetDistanceLinearKM * 6.0f;
        (*planetSaturn).velocity[2] = -200.0f;   
        (*planetSaturn).gravityToCentralObject = Scales::planetSaturnDiameterKM * Scales::gravityScale;
        (*planetSaturn).centralObject = centralObject;

        // add planets
        auto planetSaturnRenderGroup = SphereRenderGroup().getRenderGroup3D("assets/2k_saturn.jpg");
        (*planetSaturnRenderGroup).add(planetSaturn);


        return planetSaturnRenderGroup;


    };

    inline std::unique_ptr<RenderGroup3D> getPlanetUranus(std::weak_ptr<Object3D> centralObject) const{

        // get planets
        auto orbitalObjectFactory = OrbitalObjectFactory();
        auto planetUranus = orbitalObjectFactory.getSharedOrbitalObject3D();
        // configure planets
        (*planetUranus).setUniformScale(Scales::planetUranusDiameterScaledKM);
        (*planetUranus).setAxisY();
        (*planetUranus).angularVelocity = 1.0f;
        (*planetUranus).position[0] = Scales::planetDistanceLinearOffsetKM + Scales::planetDistanceLinearKM * 7.0f;
        (*planetUranus).velocity[2] = -120.0f ;   
        (*planetUranus).gravityToCentralObject = Scales::planetUranusDiameterKM * Scales::gravityScale;
        (*planetUranus).centralObject = centralObject;

        // add planets
        auto planetUranusRenderGroup = SphereRenderGroup().getRenderGroup3D("assets/2k_uranus.jpg");
        (*planetUranusRenderGroup).add(planetUranus);


        return planetUranusRenderGroup;


    };

    inline std::unique_ptr<RenderGroup3D> getPlanetNeptune(std::weak_ptr<Object3D> centralObject) const{

        // get planets
        auto orbitalObjectFactory = OrbitalObjectFactory();
        auto planetNeptune = orbitalObjectFactory.getSharedOrbitalObject3D();
        // configure planets
        (*planetNeptune).setUniformScale(Scales::planetNeptuneDiameterScaledKM);
        (*planetNeptune).setAxisY();
        (*planetNeptune).angularVelocity = 1.0f;
        (*planetNeptune).position[0] = Scales::planetDistanceLinearOffsetKM + Scales::planetDistanceLinearKM * 8.0f;
        (*planetNeptune).velocity[2] = -120.0f ;   
        (*planetNeptune).gravityToCentralObject = Scales::planetNeptuneDiameterKM * Scales::gravityScale;
        (*planetNeptune).centralObject = centralObject;

        // add planets
        auto planetNeptuneRenderGroup = SphereRenderGroup().getRenderGroup3D("assets/2k_neptune.jpg");
        (*planetNeptuneRenderGroup).add(planetNeptune);


        return planetNeptuneRenderGroup;


    };

    inline std::unique_ptr<RenderGroup3D> getPlanetPluto(std::weak_ptr<Object3D> centralObject) const{

        // get planets
        auto orbitalObjectFactory = OrbitalObjectFactory();
        auto planetPluto = orbitalObjectFactory.getSharedOrbitalObject3D();
        // configure planets
        (*planetPluto).setUniformScale(Scales::planetPlutoDiameterScaledKM);
        (*planetPluto).setAxisY();
        (*planetPluto).angularVelocity = 1.0f;
        (*planetPluto).position[0] = Scales::planetDistanceLinearOffsetKM + Scales::planetDistanceLinearKM * 9.0f;
        (*planetPluto).velocity[2] = -20.0f;   
        (*planetPluto).gravityToCentralObject = Scales::planetPlutoDiameterKM * Scales::gravityScale;
        (*planetPluto).centralObject = centralObject;

        // add planets
        auto planetPlutoRenderGroup = SphereRenderGroup().getRenderGroup3D("assets/pluto_map.png");
        (*planetPlutoRenderGroup).add(planetPluto);


        return planetPlutoRenderGroup;


    };

    inline std::shared_ptr<Object3D> getPlanetSunObject3D() const{

        // get planets
        // auto orbitalObjectFactory = OrbitalObjectFactory();
        // auto planetSun = orbitalObjectFactory.getSharedOrbitalObject3D();
        auto sphereObjectFactory = SphereObjectFactory();
        auto planetSun = sphereObjectFactory.getSharedObject3D();
        // configure planets
        (*planetSun).setUniformScale(Scales::planetSunDiameterScaledKM);
        (*planetSun).setAxisY();
        (*planetSun).angularVelocity = 0.1f;
        (*planetSun).position[0] = Scales::planetSunDistanceFromSunScaledKM;
        // (*planetSun).velocity[0] = 10.0f;   
        // (*planetSun).gravityToCentralObject = 1000.0f * 1.0e+3 ;
        // (*planetSun).centralObject = centralObject;


        return planetSun;


    };

    inline std::unique_ptr<RenderGroup3D> getPlanetSun(std::shared_ptr<Object3D> planetSun) const{

        // add planets
        auto planetSunRenderGroup = SphereRenderGroup().getRenderGroup3D("assets/2k_sun.jpg","src/shaders/lightsourceobject3d.vert","src/shaders/lightsourceobject3d.frag",true);
        (*planetSunRenderGroup).add(planetSun);


        return planetSunRenderGroup;


    };

    inline std::unique_ptr<RenderGroup3D> getSkyBox(const GLDrawWindow &window) const{

        auto background = std::make_shared<Object3DTracker>();
        (*background).setUniformScale(10000.0f);
        (*background).angularVelocity = 0.001f;
        (*background).trackedObject3D = window.camera.object3D;
        auto backgroundRenderGroup = SphereRenderGroup().getRenderGroup3D("assets/galaxy-6972265_1920.jpg","src/shaders/lightsourceobject3d.vert","src/shaders/lightsourceobject3d.frag",true);
        (*backgroundRenderGroup).add(background);

        return backgroundRenderGroup;

    };
    

    public:

    inline std::unique_ptr<std::unordered_map< int,std::unique_ptr<RenderGroup3D> >> getPlanets(const GLDrawWindow &window) const{

        auto planets = std::make_unique<std::unordered_map< int,std::unique_ptr<RenderGroup3D> >>();

        std::shared_ptr<Object3D> planetSun = this->getPlanetSunObject3D();

        (*planets)[RenderGroupID::PLANET_SUN] = this->getPlanetSun(planetSun); 
        (*planets)[RenderGroupID::PLANET_MERCURY] = this->getPlanetMercury(planetSun);
        (*planets)[RenderGroupID::PLANET_VENUS] = this->getPlanetVenus(planetSun);
        (*planets)[RenderGroupID::PLANET_EARTH] = this->getPlanetEarth(planetSun);
        (*planets)[RenderGroupID::PLANET_MARS] = this->getPlanetMars(planetSun);
        (*planets)[RenderGroupID::PLANET_JUPYTER] = this->getPlanetJupiter(planetSun);
        (*planets)[RenderGroupID::PLANET_SATURN] = this->getPlanetSaturn(planetSun);
        (*planets)[RenderGroupID::PLANET_URANUS] = this->getPlanetUranus(planetSun);
        (*planets)[RenderGroupID::PLANET_NEPTUNE] = this->getPlanetNeptune(planetSun);    
        (*planets)[RenderGroupID::PLANET_PLUTO] = this->getPlanetPluto(planetSun);  
        (*planets)[RenderGroupID::BACKGROUND] = this->getSkyBox(window);

        return planets;
    };

};


#endif // PLANETSGROUPLOADER_HPP
