#ifndef IDMANAGER_HPP
#define IDMANAGER_HPP

// #include "IDManager.hpp"
#include<unordered_set>
#include<random>

class IDManager {

    private:

    public:

    std::unordered_set<size_t> ids;

    IDManager();
    size_t getNewID();
    int removeID(size_t id);

};


#endif // IDMANAGER_HPP