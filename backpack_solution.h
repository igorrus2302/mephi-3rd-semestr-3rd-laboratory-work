#pragma once

#include "item.h"
#include "dynamic_array.h"
#include "state_of_backpack.h"


StateOfBackpack SolveBackpackA(const DynamicArray<Item>& items, int maxVolume);
StateOfBackpack SolveBackpackB(const DynamicArray<Item>& items, int maxVolume, int maxWeight);
StateOfBackpack SolveBackpackC(const DynamicArray<Item>& items, int maxWeight);
StateOfBackpack SolveBackpackD(const DynamicArray<Item>& items, int maxVolume, int maxWeight);
StateOfBackpack SolveBackpackE(const DynamicArray<Item>& items, int maxVolume);

void PrintSolution(const StateOfBackpack& solution, const DynamicArray<Item>& items);