#pragma once

#include <iostream>
#include <string>


void GenerateItemsFile(const std::string& fileName, int numberOfItems, int maxWeight, int maxVolume, int maxValue);
void GenerateRoomsFile(const std::string& fileName, int numberOfRooms);
void GeneratePeopleFile(const std::string& fileName, int numberOfPeople);