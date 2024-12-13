#include "RenderGroup3DManager.hpp"

void RenderGroup3DManager::addNewGroup(int groupid, std::unique_ptr<RenderGroup3D> rendergroup3d) {
    this->rendergroups3d[groupid] = std::move(rendergroup3d);
}

void RenderGroup3DManager::addToGroup(int groupid, std::shared_ptr<Object3D> object3d) {
    (*this->rendergroups3d[groupid]).add(object3d);
}

void RenderGroup3DManager::render(int groupid) {
    (*this->rendergroups3d[groupid]).render();
}

void RenderGroup3DManager::render(int groupid, const glm::mat4& projection, const glm::mat4& view, const glm::vec3& cameraPos) {
    (*this->rendergroups3d[groupid]).render(projection,view,cameraPos);
}

void RenderGroup3DManager::renderAll(const glm::mat4& projection, const glm::mat4& view, const glm::vec3& cameraPos) {
    for (auto & [groupid, renderGroup3D] : this->rendergroups3d){
        (*renderGroup3D).render(projection,view,cameraPos);
    }
}
