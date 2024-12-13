#ifndef OBJECT3D_HPP
#define OBJECT3D_HPP

// #include "Object3D.hpp"
#include<array>
#include<chrono>
#include<unordered_map>
#include<random>
#include<functional>

#include"FrameManager.hpp"
#include"IDManager.hpp"
#include"glmlib.hpp"

class Object3D {

    private:

    static inline std::unordered_map<size_t,Object3D *> objs{};
    static inline IDManager idManager{};
    glm::vec3 axis;
    bool isZeroVector(const glm::vec3 &vec3) const;

    public:

    const size_t id;
    std::array<float,3> position;
    std::array<float,3> velocity;
    std::array<float,3> acceleration;
    float angle;
    float angularVelocity;
    //  std::array<float,3> angularVelocity;
    float angularAcceleration;
    std::array<float,3> scale;
    std::array<float,3> scaleVelocity;
    std::array<float,3> scaleAcceleration;

    Object3D(const std::array<float,3> &position=std::array<float,3>{0.0f,0.0f,0.0f}, float angle = 0.0f,const std::array<float,3> &axis=std::array<float,3>{1.0f,0.0f,0.0f}, const std::array<float,3> &scale=std::array<float,3>{1.0f,1.0f,1.0f});
    virtual ~Object3D();
    virtual void update(const std::chrono::milliseconds &deltaTime);
    virtual void update(const float &deltaTimeSeconds);
    static void updateAllObjects(void);
    virtual void printObjectInfo(void) const;
    virtual void setAxis(int axis,float val);
    virtual void setAxis(const std::array<float,3> &val);
    virtual void setAxisX(void);
    virtual void setAxisY(void);
    virtual void setAxisZ(void);
    [[nodiscard]]
    virtual float getAxis(int axis);
    [[nodiscard]]
    virtual glm::vec3 getAxis(void);
    virtual void setUniformScale(float val);

};


#endif // OBJECT3D_HPP
