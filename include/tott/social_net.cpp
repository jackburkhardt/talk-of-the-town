//
// Created by gromme on 1/31/26.
//

#include "social_net.h"

#include <format>

namespace detail {
    // inline tott::tie_id_t make_ordered_pair(tott::actor_id_t lhs, tott::actor_id_t rhs) {
    //     if (lhs < rhs) return {lhs, rhs};
    //     else return {rhs, lhs};
    // }

    inline std::size_t hash_combine(std::size_t a, std::size_t b)
    {
        if (b > a) { // ensure a and b are sorted for consistent hashing
            const size_t tmp = a;
            a = b;
            b = tmp;
        }
        return a ^ (b + 0x9e3779b9 + (a << 6) + (a >> 2));
    }
}

namespace tott {
    std::size_t social_net::actor_count() const noexcept {
        return actor_map.size();
    }

    std::size_t social_net::tie_count() const noexcept {
        return tie_map.size();
    }

    const actors_t& social_net::get_neighbors(actor_id_t actor_id) const {
        return adjacency.at(actor_id);
    }

    actors_t& social_net::get_neighbors(actor_id_t actor_id) {
        return adjacency.at(actor_id);
    }

    size_t social_net::add_actor(const std::string &name) {
        while (has_actor(vertex_id_tracker)) {
            ++vertex_id_tracker;
        }
        actor_map.try_emplace(vertex_id_tracker, actor{name});

        return vertex_id_tracker;
    }

    bool social_net::has_actor(const actor_id_t& id) const {
        return actor_map.contains(id);
    }

    actor* social_net::get_actor(actor_id_t id) {
        if (has_actor(id)) return &actor_map.at(id);
        return nullptr;
    }

    const actor* social_net::get_actor(actor_id_t id) const {
        if (has_actor(id)) return &actor_map.at(id);
        return nullptr;
    }

    void social_net::remove_actor(actor_id_t n) {
        if (has_actor(n)) {
            actor_map.erase(n);
        }
    }

    void social_net::add_tie(actor_id_t lhs, actor_id_t rhs, tie edge) {
        if (!has_actor(lhs) || !has_actor(rhs)) {
            throw std::invalid_argument(std::format("add_tie: Actors with ids [{}] and [{}] were not found in the network.", lhs, rhs));
        }
        adjacency[lhs].insert(rhs);
        adjacency[rhs].insert(lhs);
        tie_map.emplace(detail::hash_combine(lhs, rhs), edge);
    }

    tie* social_net::get_tie(actor_id_t lhs, actor_id_t rhs) {
        tie_id_t id = detail::hash_combine(lhs, rhs);
        if (tie_map.contains(id)) {
            return &tie_map.at(id);
        }
        return nullptr;
    }

    const tie *social_net::get_tie(actor_id_t lhs, actor_id_t rhs) const {
        tie_id_t id = detail::hash_combine(lhs, rhs);
        if (tie_map.contains(id)) {
            return &tie_map.at(id);
        }
        return nullptr;
    }

    tie_data_t *social_net::get_tie_data(tie_id_t id) {
        if (tie_datas.contains(id)) return &tie_datas.at(id);
        else return nullptr;
    }

    const tie_data_t *social_net::get_tie_data(tie_id_t id) const {
        if (tie_datas.contains(id)) return &tie_datas.at(id);
        else return nullptr;
    }

    void social_net::remove_tie(actor_id_t lhs, actor_id_t rhs) {
        tie_id_t id = detail::hash_combine(lhs, rhs);
        if (tie_map.contains(id)) {
            tie_map.erase(id);
        }
    }
}
