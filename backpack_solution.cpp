#include <iostream>

#include "hash_table.h"
#include "backpack_solution.h"
#include "dynamic_array.h"
#include "state_of_backpack.h"
#include "item.h"



StateOfBackpack SolveBackpackA(const DynamicArray<Item>& items, int maxVolume)
{
    int itemCount = items.GetLength();
    StateOfBackpack bestState(itemCount);

    HashTable<int, StateOfBackpack> stateTable;

    for (int mask = 0; mask < (1 << itemCount); ++mask)
    {
        StateOfBackpack currentState(itemCount);

        for (int i = 0; i < itemCount; ++i)
        {
            if (mask & (1 << i))
            {
                const Item& item = items[i];
                currentState.totalValue += item.value;
                currentState.totalVolume += item.volume;
                currentState.Set(i, true);
            }
        }

        int stateHash = currentState.totalValue * 1000 + currentState.totalVolume;

        if (stateTable.ContainsKey(stateHash))
        {
            if (currentState.totalValue > stateTable.GetValue(stateHash).value().totalValue)
            {
                stateTable.Add(stateHash, currentState);
            }
        }
        else
        {
            stateTable.Add(stateHash, currentState);
        }

        if (currentState.totalVolume <= maxVolume)
        {
            if (currentState.totalValue > bestState.totalValue)
            {
                bestState = currentState;
            }
        }
    }

    return bestState;
}

StateOfBackpack SolveBackpackB(const DynamicArray<Item>& items, int maxVolume, int maxWeight)
{
    int itemCount = items.GetLength();
    StateOfBackpack bestState(itemCount);

    HashTable<int, StateOfBackpack> stateTable;

    for (int mask = 0; mask < (1 << itemCount); ++mask)
    {
        StateOfBackpack currentState(itemCount);

        for (int i = 0; i < itemCount; ++i)
        {
            if (mask & (1 << i))
            {
                const Item& item = items[i];
                currentState.totalValue += item.value;
                currentState.totalVolume += item.volume;
                currentState.totalWeight += item.weight;
                currentState.Set(i, true);
            }
        }

        int stateHash = currentState.totalValue * 1000 + currentState.totalVolume * 100 + currentState.totalWeight;

        if (stateTable.ContainsKey(stateHash))
        {
            if (currentState.totalValue > stateTable.GetValue(stateHash).value().totalValue)
            {
                stateTable.Add(stateHash, currentState);
            }
        }
        else
        {
            stateTable.Add(stateHash, currentState);
        }

        if (currentState.totalVolume <= maxVolume && currentState.totalWeight <= maxWeight)
        {
            if (currentState.totalValue > bestState.totalValue)
            {
                bestState = currentState;
            }
        }
    }

    return bestState;
}

StateOfBackpack SolveBackpackC(const DynamicArray<Item>& items, int maxWeight)
{
    int itemCount = items.GetLength();
    StateOfBackpack bestState(itemCount);

    HashTable<int, StateOfBackpack> stateTable;

    for (int mask = 0; mask < (1 << itemCount); ++mask)
    {
        StateOfBackpack currentState(itemCount);

        for (int i = 0; i < itemCount; ++i)
        {
            if (mask & (1 << i))
            {
                const Item& item = items[i];
                currentState.totalValue += item.value;
                currentState.totalWeight += item.weight;
                currentState.Set(i, true);
            }
        }

        int stateHash = currentState.totalValue * 1000 + currentState.totalWeight;

        if (stateTable.ContainsKey(stateHash))
        {
            if (currentState.totalValue > stateTable.GetValue(stateHash).value().totalValue)
            {
                stateTable.Add(stateHash, currentState);
            }
        }
        else
        {
            stateTable.Add(stateHash, currentState);
        }

        if (currentState.totalWeight <= maxWeight)
        {
            if (currentState.totalValue > bestState.totalValue)
            {
                bestState = currentState;
            }
        }
    }

    return bestState;
}

StateOfBackpack SolveBackpackD(const DynamicArray<Item>& items, int maxVolume, int maxWeight)
{
    int itemCount = items.GetLength();
    StateOfBackpack bestState(itemCount);

    HashTable<int, StateOfBackpack> stateTable;

    for (int mask = 0; mask < (1 << itemCount); ++mask)
    {
        StateOfBackpack currentState(itemCount);

        for (int i = 0; i < itemCount; ++i)
        {
            if (mask & (1 << i))
            {
                const Item& item = items[i];
                currentState.totalValue += item.value;
                currentState.totalVolume += item.volume;
                currentState.totalWeight += item.weight;
                currentState.Set(i, true);
            }
        }

        int stateHash = currentState.totalValue * 1000 + currentState.totalVolume * 100 + currentState.totalWeight;

        if (stateTable.ContainsKey(stateHash))
        {
            const auto& existingState = stateTable.GetValue(stateHash).value();
            if (currentState.totalValue > existingState.totalValue ||
                (currentState.totalValue == existingState.totalValue && currentState.totalVolume > existingState.totalVolume))
            {
                stateTable.Add(stateHash, currentState);
            }
        }
        else
        {
            stateTable.Add(stateHash, currentState);
        }

        if (currentState.totalVolume <= maxVolume && currentState.totalWeight <= maxWeight)
        {
            if (currentState.totalValue > bestState.totalValue ||
                (currentState.totalValue == bestState.totalValue && currentState.totalVolume > bestState.totalVolume))
            {
                bestState = currentState;
            }
        }
    }

    return bestState;
}

StateOfBackpack SolveBackpackE(const DynamicArray<Item>& items, int maxVolume)
{
    int itemCount = items.GetLength();
    StateOfBackpack bestState(itemCount);

    HashTable<int, StateOfBackpack> stateTable;

    for (int mask = 0; mask < (1 << itemCount); ++mask)
    {
        StateOfBackpack currentState(itemCount);

        for (int i = 0; i < itemCount; ++i)
        {
            if (mask & (1 << i))
            {
                const Item& item = items[i];
                currentState.totalValue += item.value;
                currentState.totalVolume += item.volume;
                currentState.totalWeight += item.weight;
                currentState.Set(i, true);
            }
        }

        int stateHash = currentState.totalValue * 1000 + currentState.totalVolume;

        if (stateTable.ContainsKey(stateHash))
        {
            const auto& existingState = stateTable.GetValue(stateHash).value();
            if (currentState.totalValue > existingState.totalValue ||
                (currentState.totalValue == existingState.totalValue && currentState.totalWeight < existingState.totalWeight))
            {
                stateTable.Add(stateHash, currentState);
            }
        }
        else
        {
            stateTable.Add(stateHash, currentState);
        }

        if (currentState.totalVolume <= maxVolume)
        {
            if (currentState.totalValue > bestState.totalValue ||
                (currentState.totalValue == bestState.totalValue && currentState.totalWeight < bestState.totalWeight))
            {
                bestState = currentState;
            }
        }
    }

    return bestState;
}


void PrintSolution(const StateOfBackpack& solution, const DynamicArray<Item>& items)
{
    std::cout << "Best total value: " << solution.totalValue << "\n";
    std::cout << "Total weight: " << solution.totalWeight << "\n";
    std::cout << "Total volume: " << solution.totalVolume << "\n";
    std::cout << "Selected items: \n";

    for (int i = 0; i < solution.GetLength(); ++i)
    {
        if (solution.Get(i))
        {
            const Item& item = items[i];
            std::cout << "  Item " << i + 1 << ": "
                      << "Value = " << item.value << ", "
                      << "Weight = " << item.weight << ", "
                      << "Volume = " << item.volume << "\n";
        }
    }
}
