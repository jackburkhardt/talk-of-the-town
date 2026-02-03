//
// Created by gromme on 1/31/26.
//

#ifndef TOTT_TYPES_H
#define TOTT_TYPES_H
#include <any>
#include <unordered_map>
#include <unordered_set>
#include <utility>

#include "actor.h"
#include "tie.h"

namespace tott {
    using actor_id_t = std::size_t;
    using tie_id_t = std::pair<actor_id_t, actor_id_t>;
    using actor_id_to_actor_t = std::unordered_map<actor_id_t, actor>;
    using tie_id_to_tie_t = std::unordered_map<tie_id_t, tie>;
    using actors_t = std::unordered_set<actor_id_t>;
    using tie_data_t = std::unordered_map<std::string, std::any>;
    using tie_id_to_tie_data_t = std::unordered_map<tie_id_t, tie_data_t>;


}

#endif //TOTT_TYPES_H