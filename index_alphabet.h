#pragma once

#include "dynamic_array.h"
#include "hash_table.h"

#include <string>



void BuildAlphabetIndex(HashTable<std::string, DynamicArray<int>>& wordPageHashTable, const std::string& text,
                        int pageSize, bool isByWords);