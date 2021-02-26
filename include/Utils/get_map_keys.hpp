/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** get_map_keys
*/

#ifndef GET_MAP_KEYS_HPP_
#define GET_MAP_KEYS_HPP_

#include <vector>

template<typename TK, typename TV, template<typename, typename...> typename C, typename... Args>
std::vector<TK> get_map_keys(const C<TK, TV, Args...> &input_map)
{
    std::vector<TK> keys;

    for (const std::pair<const TK, TV> &pair : input_map)
        keys.push_back(pair.first);
    return keys;
}

#endif /* !GET_MAP_KEYS_HPP_ */
