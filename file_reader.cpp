#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "file_reader.h"
#include "dynamic_array.h"
#include "item.h"
#include "room.h"
#include "person.h"


DynamicArray<Item> ReadItemsFromFile(const std::string& fileName)
{
    std::ifstream file(fileName);

    DynamicArray<Item> items;

    if (!file)
    {
        std::cerr << "Error opening file: " << fileName << "\n\n";
        return items;
    }

    int weight;
    int volume;
    int value;

    while (file >> weight >> volume >> value)
    {
        if (weight < 0 || volume < 0 || value < 0)
        {
            std::cerr << "Error: Negative values are not allowed. Skipping entry.\n";
            continue;
        }
        items.Append({weight, volume, value});
    }

    if (file.fail() && !file.eof())
    {
        std::cerr << "Error reading file. Ensure the format is correct.\n";
    }

    file.close();

    if (items.GetLength() > 0)
    {
        std::cout << "The data has been successfully read. Items count: " << items.GetLength() << "\n\n";
    }
    else
    {
        std::cerr << "No valid data found in file.\n";
    }

    return items;
}


DynamicArray<Room> ReadRoomsFromFile(const std::string& fileName)
{
    std::ifstream file(fileName);

    DynamicArray<Room> rooms;

    if (!file)
    {
        std::cerr << "Error opening file\n\n";
        return rooms;
    }

    int capacity;
    int cost;
    std::string type;

    while (file >> capacity >> cost >> type)
    {
        rooms.Append({capacity, cost, type});
    }

    file.close();

    std::cout << "The data has been successfully read\n\n";

    return rooms;
}

DynamicArray<Person> ReadPeopleFromFile(const std::string& fileName)
{
    std::ifstream file(fileName);

    DynamicArray<Person> people;

    if (!file)
    {
        std::cerr << "Error opening file\n\n";
        return people;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream stream(line);
        Person person;

        std::string friendsPart, enemiesPart;

        std::getline(stream, person.firstName, ',');
        std::getline(stream, person.lastName, ',');
        std::getline(stream, person.patronymic, ',');

        std::string spouse;
        std::getline(stream, spouse, ',');

        if (spouse != "empty")
        {
            person.spouse = spouse;
        }

        std::getline(stream, friendsPart, ',');
        if (friendsPart.find("Friends:") == 0)
        {
            friendsPart = friendsPart.substr(8);
            if (friendsPart != "empty")
            {
                std::istringstream friendsStream(friendsPart);
                std::string friendName;
                while (std::getline(friendsStream, friendName, ';'))
                {
                    if (!friendName.empty())
                    {
                        person.friends.insert(friendName);
                    }
                }
            }
        }

        std::getline(stream, enemiesPart);
        if (enemiesPart.find("Enemies:") == 0)
        {
            enemiesPart = enemiesPart.substr(9);
            if (enemiesPart != "empty")
            {
                std::istringstream enemiesStream(enemiesPart);
                std::string enemyName;
                while (std::getline(enemiesStream, enemyName, ';'))
                {
                    if (!enemyName.empty())
                    {
                        person.enemies.insert(enemyName);
                    }
                }
            }
        }

        people.Append(person);
    }

    file.close();

    std::cout << "The data has been successfully read\n\n";

    return people;
}

DynamicArray<std::string> SplitTextIntoWords(const std::string& text)
{
    std::istringstream stream(text);

    DynamicArray<std::string> words;

    std::string word;

    while (stream >> word)
    {
        words.Append(word);
    }

    return words;
}

std::string ReadTextFormFile(const std::string& fileName)
{
    std::ifstream file(fileName);

    if (!file.is_open())
    {
        std::cerr << "Unable to open the file " << fileName << "\n\n";
        return "";
    }

    std::string line;
    std::string text;

    while (std::getline(file, line))
    {
        text += line + "\n";
    }

    file.close();

    return text;
}