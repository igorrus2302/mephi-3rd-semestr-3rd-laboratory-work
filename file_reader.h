#pragma once

#include <iostream>
#include <string>

#include "dynamic_array.h"
#include "item.h"
#include "room.h"
#include "person.h"



DynamicArray<Item> ReadItemsFromFile(const std::string& fileName);
DynamicArray<Room> ReadRoomsFromFile(const std::string& fileName);
DynamicArray<Person> ReadPeopleFromFile(const std::string& fileName);
DynamicArray<std::string> SplitTextIntoWords(const std::string& text);
std::string ReadTextFormFile(const std::string& fileName);
