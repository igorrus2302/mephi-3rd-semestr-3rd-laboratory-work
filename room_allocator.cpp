#include "person.h"
#include "room.h"
#include "hash_table.h"

#include <iostream>
#include <set>
#include <string>

using RoomAllocation = HashTable<Room, std::set<Person>>;


bool IsValidAllocation(const Room& room, const std::set<Person>& occupants, const Person& newPerson)
{
    // Проверка вместимости
    if (occupants.size() >= room.capacity) return false;

    // Проверка на врагов
    for (const auto& occupant : occupants)
    {
        if (newPerson.enemies.count(occupant.firstName + occupant.lastName) ||
            occupant.enemies.count(newPerson.firstName + newPerson.lastName))
            return false;
    }

    return true;
}


void AllocateRooms(DynamicArray<Room>& rooms, DynamicArray<Person>& people, RoomAllocation& currentAllocation,
                   int& solutionCount, int maxSolutions)
{
    if (solutionCount >= maxSolutions) return;

    // Все туристы расселены
    if (people.GetLength() == 0)
    {
        ++solutionCount;
        std::cout << "Solution " << solutionCount << ":\n";

        for (int i = 0; i < currentAllocation.GetCapacity(); ++i)
        {
            if (currentAllocation.ContainsIndex(i))
            {
                const Room& room = currentAllocation.GetKeyByIndex(i);
                const auto& occupants = currentAllocation.GetValueByIndex(i);

                std::cout << "Room (" << room.type << ", Capacity: " << room.capacity
                          << ", Cost: " << room.cost << "):\n";

                for (const auto& person : occupants)
                {
                    std::cout << "  " << person.lastName << " " << person.firstName
                              << " " << person.patronymic << "\n";
                }
            }
        }
        std::cout << "----------------\n";

        return;
    }

    // Извлекаем последнего туриста
    Person currentPerson = people.GetLastElement();
    people.Resize(people.GetLength() - 1);

    // Заселение в существующие комнаты
    for (int i = 0; i < currentAllocation.GetCapacity(); ++i)
    {
        if (currentAllocation.ContainsIndex(i))
        {
            Room& room = currentAllocation.GetKeyByIndex(i);
            auto& occupants = currentAllocation.GetValueByIndex(i);

            if (IsValidAllocation(room, occupants, currentPerson))
            {
                occupants.insert(currentPerson);
                AllocateRooms(rooms, people, currentAllocation, solutionCount, maxSolutions);
                occupants.erase(currentPerson); // Откат
            }
        }
    }

    // Заселение в новую комнату
    for (int i = 0; i < rooms.GetLength(); ++i)
    {
        const Room& room = rooms[i];

        if (!currentAllocation.ContainsKey(room))
        {
            std::set<Person> newOccupants = { currentPerson };
            currentAllocation.Add(room, newOccupants);
            AllocateRooms(rooms, people, currentAllocation, solutionCount, maxSolutions);
            currentAllocation.Remove(room);

            break;
        }
    }

    // Возвращаем туриста обратно
    people.Append(currentPerson);
}


void PrintAllocation(const RoomAllocation& allocation, int solutionNumber)
{
    std::cout << "Solution " << solutionNumber << ":\n";
    for (int i = 0; i < allocation.GetCapacity(); ++i)
    {
        if (allocation.ContainsIndex(i))
        {
            const Room& room = allocation.GetKeyByIndex(i);
            const auto& occupants = allocation.GetValueByIndex(i);

            std::cout << "Room (" << room.type << ", Capacity: " << room.capacity
                      << ", Cost: " << room.cost << "):\n";

            for (const auto& person : occupants)
            {
                std::cout << "  " << person.lastName << " " << person.firstName
                          << " " << person.patronymic << "\n";
            }
        }
    }
    std::cout << "----------------\n";
}
