//
// Created by jack on 2/3/2026.
//

#include <iostream>

#include "tott/social_net.h"

int main() {
    std::cout << "it works!";
    tott::social_net net;
    auto new_id = net.add_actor("test actor");
    auto actor = net.get_actor(new_id);
    if (actor) {
        actor->known_gossip.insert("Barney should not be put in charge of the facility security");
        std::cout << actor->known_gossip.size();
    }



    return 0;
}
