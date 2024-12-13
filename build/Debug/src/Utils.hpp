#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <iostream>

namespace Utils {

    #define DBGEXPR(EXPR) {std::cerr << #EXPR << ": " << EXPR << "\n";}
    #define DBGEXPROUT(EXPR) {std::cout << #EXPR << ": " << EXPR << "\n";}

    template<class T>
    inline void printVector(const std::vector<T> & vec){
        std::cout << "[";
        for (const auto &data : vec){
            std::cout << data << ", ";
        }
        std::cout << "]\n";
    }
    template<class T>
    inline void printVectorErr(const std::vector<T> & vec){
        std::cerr << "[";
        for (const auto &data : vec){
            std::cerr << data << ", ";
        }
        std::cerr << "]\n";
    }

    #define printArray(arr) {\
        std::cout << "["; \
        for (const auto &data : arr){ \
            std::cout << data << ", "; \
        } \
        std::cout << "]\n"; \
    }

    #define printArrayErr(arr){ \
        std::cerr << "["; \
        for (const auto &data : arr){ \
            std::cerr << data << ", "; \
        } \
        std::cerr << "]\n"; \
    }

    #define DBGEXPRARRAY(EXPRARRAY) { \
        std::cerr << #EXPRARRAY << ": "; \
        printArrayErr(EXPRARRAY); \
    }

    #define DBGEXPRARRAYOUT(EXPRARRAY) { \
        std::cerr << #EXPRARRAY << ": "; \
        printArray(EXPRARRAY); \
    }

} // namespace Utils

#endif // UTILS_HPP
