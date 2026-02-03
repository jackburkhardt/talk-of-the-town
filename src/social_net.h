//
// Created by gromme on 1/31/26.
//

#ifndef TOTT_GRAPH_H
#define TOTT_GRAPH_H
#include <optional>
#include <unordered_set>
#include <vector>

#include "types.h"

namespace tott {
    class social_net {
    private:
        actors_t actors;
        actor_id_to_actor_t actor_map;
        tie_id_to_tie_t tie_map;
        tie_id_to_tie_data_t tie_datas;

    public:
        std::size_t actor_count() const noexcept;
        std::size_t tie_count() const noexcept;

        std::unordered_set<actor_id_t> get_neighbors(std::string vertex_id) const;

        size_t add_actor(const std::string& name);

        std::optional<actor&> get_actor(actor_id_t id);

        const std::optional<actor&> get_actor(actor_id_t id) const;

        void remove_actor(actor_id_t n);

        void add_tie(actor_id_t lhs, actor_id_t rhs, tie edge);

        std::optional<tie_id_t&> get_tie(actor_id_t lhs, actor_id_t rhs);

        const std::optional<tie_id_t&> get_tie(actor_id_t lhs, actor_id_t rhs) const;

        tie_data_t& get_tie_data(tie_id_t id);

        const tie_data_t& get_tie_data(tie_id_t id) const;

        void remove_tie(actor_id_t lhs, actor_id_t rhs);
    };
}


#endif //TOTT_GRAPH_H