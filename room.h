#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <limits>

struct Room {

    int capacity;  // Вместимость
    int cost;      // Стоимость
    std::string type;   // Тип номера: Single, Double, Triple


    bool operator<(const Room& other) const
    {
        return std::tie(capacity, cost, type) < std::tie(other.capacity, other.cost, other.type);
    }

    bool operator==(const Room& other) const
    {
        return std::tie(capacity, cost, type) == std::tie(other.capacity, other.cost, other.type);
    }
};

namespace std {
    template <>
    struct hash<Room> {
        std::size_t operator()(const Room& room) const {
            // Комбинируем хеши для типа, вместимости и стоимости номера
            return hash<std::string>()(room.type) ^ hash<int>()(room.capacity) ^ hash<int>()(room.cost);
        }
    };
}
