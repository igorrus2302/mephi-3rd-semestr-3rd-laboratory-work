#include "functional_tests.h"
#include "hash_table.h"
#include "dynamic_array.h"

#include <iostream>
#include <cassert>


void HashTableTests()
{
    HashTable<int, std::string> table;
    assert(table.IsEmpty());
    assert(table.GetCount() == 0);
    assert(table.GetCapacity() >= 20);

    table.Add(1, "One");
    table.Add(2, "Two");
    table.Add(3, "Three");

    assert(!table.IsEmpty());
    assert(table.GetCount() == 3);
    assert(table.ContainsKey(1));
    assert(table.ContainsKey(2));
    assert(table.ContainsKey(3));
    assert(!table.ContainsKey(4));

    assert(table.GetValue(1).value_or("") == "One");
    assert(table.GetValue(2).value_or("") == "Two");
    assert(table.GetValue(3).value_or("") == "Three");
    assert(!table.GetValue(4).has_value());

    table.Add(1, "Updated");
    assert(table.GetValue(1).value_or("") == "Updated");

    table.Remove(2);
    assert(!table.ContainsKey(2));
    assert(table.GetCount() == 2);

    table.Remove(3);
    assert(!table.ContainsKey(3));
    assert(table.GetCount() == 1);

    table.Remove(1);
    assert(table.IsEmpty());
    assert(table.GetCount() == 0);

    for (int i = 0; i < 100; i++)
    {
        table.Add(i, "Value" + std::to_string(i));
    }
    assert(table.GetCount() == 100);
    for (int i = 0; i < 100; i++)
    {
        assert(table.GetValue(i).value_or("") == "Value" + std::to_string(i));
    }

    for (int i = 0; i < 100; i++)
    {
        table.Remove(i);
    }
    assert(table.IsEmpty());
    assert(table.GetCount() == 0);

    HashTable<int, std::string> conflictTable(5);
    conflictTable.Add(1, "One");
    conflictTable.Add(6, "Six");

    assert(conflictTable.GetValue(1).value_or("") == "One");
    assert(conflictTable.GetValue(6).value_or("") == "Six");

    conflictTable.Remove(1);
    assert(!conflictTable.ContainsKey(1));
    assert(conflictTable.GetValue(6).value_or("") == "Six");

    std::cout << "All hash table tests passed successfully!" << std::endl;
}