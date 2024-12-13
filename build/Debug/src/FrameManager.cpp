#include "FrameManager.hpp"

// const std::chrono::milliseconds& FrameManager::getDeltaTime(void) {
//     return FrameManager::deltaTime;
// }

// const std::chrono::milliseconds& FrameManager::getCurrentFrameTimestamp(void) {
//     return FrameManager::deltaTimeSinceStart;
// }

// const std::chrono::milliseconds& FrameManager::getPrevFrameTimestamp(void) {
//     return FrameManager::deltaTimeSinceStartPrev;
// }

void FrameManager::updateFrame(void) {
    const auto now = std::chrono::steady_clock::now();
    FrameManager::deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(now - FrameManager::prevFrameTimestamp);
    FrameManager::prevFrameTimestamp = FrameManager::currentFrameTimestamp;
    FrameManager::currentFrameTimestamp = now;
    FrameManager::deltaTimeSinceStart = std::chrono::duration_cast<std::chrono::milliseconds>(FrameManager::currentFrameTimestamp - FrameManager::startTimeTimestamp);
    FrameManager::deltaTimeSinceStartPrev = std::chrono::duration_cast<std::chrono::milliseconds>(FrameManager::prevFrameTimestamp - FrameManager::startTimeTimestamp);
    FrameManager::deltaTimeSeconds = std::chrono::duration<float>(deltaTime).count();
    FrameManager::scaleTimeByGameSpeed();
}

std::chrono::milliseconds FrameManager::scaleDurationByFloat(const std::chrono::milliseconds& duration, float scale) {
    // const auto a = std::chrono::duration<float,std::milli>(FrameManager::deltaTime) * FrameManager::gameSpeed;
    // const auto b = std::chrono::duration_cast<std::chrono::milliseconds>(a);
    // FrameManager::deltaTime = b;
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::duration<float,std::milli>(duration) * scale);
}

void FrameManager::scaleTimeByGameSpeed(void) {
    
    FrameManager::deltaTime = FrameManager::scaleDurationByFloat(FrameManager::deltaTime,FrameManager::gameSpeed);
    // FrameManager::deltaTime = FrameManager::scaleDurationByFloat(FrameManager::deltaTime,FrameManager::gameSpeed);
    FrameManager::deltaTimeSinceStart = FrameManager::scaleDurationByFloat(FrameManager::deltaTimeSinceStart,FrameManager::gameSpeed);
    FrameManager::deltaTimeSinceStartPrev = FrameManager::scaleDurationByFloat(FrameManager::deltaTimeSinceStartPrev,FrameManager::gameSpeed);
    FrameManager::deltaTimeSeconds = FrameManager::deltaTimeSeconds * FrameManager::gameSpeed;
}

void FrameManager::init(void) {
    const auto now = std::chrono::steady_clock::now();
    FrameManager::deltaTime = std::chrono::milliseconds(0);
    FrameManager::deltaTimeSinceStart = std::chrono::milliseconds(0);
    FrameManager::deltaTimeSinceStartPrev = std::chrono::milliseconds(0);
    FrameManager::startTimeTimestamp = now;
    FrameManager::prevFrameTimestamp = now;
    FrameManager::currentFrameTimestamp = now;
    FrameManager::deltaTimeSeconds = std::chrono::duration<float>(deltaTime).count();
    
}

void FrameManager::increaseGameSpeed(void) {
    FrameManager::gameSpeedMultiplier *= 2.0f;
    FrameManager::gameSpeed = FrameManager::gameSpeedMultiplier * FrameManager::gameSpeedBaseMultiplier;
}

void FrameManager::decreaseGameSpeed(void) {
    if (FrameManager::gameSpeedMultiplier <= 1.0f){
        FrameManager::gameSpeedMultiplier = 1.0f;
    }
    else {
        FrameManager::gameSpeedMultiplier /= 2.0f;
    }
    FrameManager::gameSpeed = FrameManager::gameSpeedMultiplier * FrameManager::gameSpeedBaseMultiplier;
}
