//
// Created by gromme on 1/30/26.
//

#ifndef TOTT_actor_H
#define TOTT_actor_H
#include <string>

namespace tott {
    class actor {
        public:
            const std::string& tag;
            const size_t id;
            bool active = true;
            std::unordered_set<std::string> known_gossip;

            explicit actor(const size_t& id, const std::string& tag) : tag(tag), id(id) {}
    };
}


#endif //TOTT_actor_H
