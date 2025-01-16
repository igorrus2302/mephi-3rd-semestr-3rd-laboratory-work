#include "file_writer.h"
#include "hash_table.h"
#include "dynamic_array.h"

#include <iostream>
#include <string>
#include <fstream>



void WriteIndexAlphabetToFile(const std::string& fileName, const HashTable<std::string, DynamicArray<int>>& hashTable)
{
    std::ofstream file(fileName);

    if (!file.is_open())
    {
        std::cerr << "Unable to open the file " << fileName << "\n";
        return;
    }

    PrintValue(hashTable, file);

    file.close();
}