#pragma once

#include "person.h"
#include "room.h"
#include "hash_table.h"
#include "dynamic_array.h"

using RoomAllocation = HashTable<Room, std::set<Person>>;


bool IsValidAllocation(const Room& room, const std::set<Person>& occupants, const Person& newPerson);
void AllocateRooms(DynamicArray<Room>& rooms, DynamicArray<Person>& people, RoomAllocation& currentAllocation,
                   int& solutionCount, int maxSolutions);