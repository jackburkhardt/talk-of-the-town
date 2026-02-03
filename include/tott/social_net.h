//
// Created by gromme on 1/31/26.
//

#ifndef TOTT_GRAPH_H
#define TOTT_GRAPH_H
#include <optional>
#include <unordered_set>

#include "types.h"

namespace tott {
    class social_net {
    private:
        actor_id_to_actor_t actor_map;
        tie_id_to_tie_t tie_map;
        tie_id_to_tie_data_t tie_datas;
        std::unordered_map<actor_id_t, actors_t> adjacency;
        size_t vertex_id_tracker = 0;

    public:
        std::size_t actor_count() const noexcept;
        std::size_t tie_count() const noexcept;

        const actors_t& get_neighbors(actor_id_t actor_id) const;

        actors_t& get_neighbors(actor_id_t actor_id);

        size_t add_actor(const std::string& name);

        bool has_actor(const actor_id_t &id) const;

        actor* get_actor(actor_id_t id);

        const actor* get_actor(actor_id_t id) const;

        void remove_actor(actor_id_t n);

        void add_tie(actor_id_t lhs, actor_id_t rhs, tie edge);

        tie* get_tie(actor_id_t lhs, actor_id_t rhs);

        const tie* get_tie(actor_id_t lhs, actor_id_t rhs) const;

        tie_data_t* get_tie_data(tie_id_t id);

        const tie_data_t* get_tie_data(tie_id_t id) const;

        void remove_tie(actor_id_t lhs, actor_id_t rhs);
    };
}


#endif //TOTT_GRAPH_H