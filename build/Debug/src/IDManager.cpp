#include "IDManager.hpp"

IDManager::IDManager() 
: ids{std::unordered_set<size_t>{}}
{

}

size_t IDManager::getNewID() {
    while (true){
        const size_t id = std::rand();
        if (this->ids.count(id)){
            // loops until a new id is found
            continue;
        }
        this->ids.emplace(id);
        return id;
    }
}

int IDManager::removeID(size_t id) {
    return this->ids.erase(id);
}
