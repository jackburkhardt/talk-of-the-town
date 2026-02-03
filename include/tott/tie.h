//
// Created by gromme on 1/31/26.
//

#ifndef TOTT_TIE_H
#define TOTT_TIE_H
#include <any>
#include <string>
#include <unordered_map>

namespace tott {
    class tie {
    private:
        //std::unordered_map<std::string, std::any> data;
    public:
        int trust;
        int closeness;

        //std::any& operator[](const std::string &idx) { return data[idx]; }
    };
};
#endif //TOTT_TIE_H