#pragma once

#include "hash_table.h"
#include "dynamic_array.h"

#include <iostream>
#include <string>


void WriteIndexAlphabetToFile(const std::string& fileName, const HashTable<std::string, DynamicArray<int>>& hashTable);

template <typename T>
void PrintValue(const T& value, std::ostream& os)
{
    os << value;
}

template <typename T>
void PrintValue(const DynamicArray<T>& value, std::ostream& os)
{
    os << "[";

    for (int i = 0; i < value.GetLength(); i++)
    {
        PrintValue(value[i], os);

        if (i < value.GetLength() - 1)
        {
            os << ", ";
        }
    }

    os << "]";
}

template <typename TKey, typename TValue, typename Hash = std::hash<TKey>>
void PrintValue(const HashTable<TKey, TValue, Hash>& value, std::ostream& os)
{
    for (int i = 0; i < value.GetCapacity(); i++)
    {
        if (value.ContainsIndex(i))
        {
            PrintValue(value.GetKeyByIndex(i), os);
            os << " : ";

            PrintValue(value.GetValueByIndex(i), os);
            os << "\n";
        }
    }
}