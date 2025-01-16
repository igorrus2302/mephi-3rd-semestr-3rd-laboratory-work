#include "file_generator.h"
#include "person.h"

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>



void GenerateItemsFile(const std::string& fileName, int numberOfItems, int maxWeight, int maxVolume, int maxValue)
{
    std::ofstream file(fileName);

    if (!file)
    {
        std::cerr << "Error opening the file\n\n";
        return;
    }

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (int i = 0; i < numberOfItems; i++)
    {
        int weight = std::rand() % maxWeight + 1;
        int volume = std::rand() % maxVolume + 1;
        int value = std::rand() % maxValue + 1;

        file << weight << " " << volume << " " << value << "\n";
    }

    file.close();

    std::cout << "File was successfully created!\n\n";
}

void GenerateRoomsFile(const std::string& fileName, int numberOfRooms)
{
    std::ofstream file(fileName);

    if (!file)
    {
        std::cerr << "Error opening the file\n\n";
        return;
    }

    for (int i = 0; i < numberOfRooms; ++i)
    {
        int capacity = 1 + std::rand() % 3;
        int cost = 50 + std::rand() % 201;
        std::string type;

        switch (capacity)
        {
            case 1:
                type = "Single";
                break;
            case 2:
                type = "Double";
                break;
            case 3:
                type = "Triple";
                break;
            default:
                type = "Unknown";
                break;
        }

        file << capacity << " " << cost << " " << type << "\n";
    }

    file.close();

    std::cout << "File was successfully created!\n\n";
}

void GeneratePeopleFile(const std::string& fileName, int numberOfPeople)
{
    std::ofstream file(fileName);

    if (!file)
    {
        std::cerr << "Error opening the file\n\n";
        return;
    }

    for (int i = 0; i < numberOfPeople; ++i)
    {
        bool isMale = getRandomNumber(0, 1) == 0;
        Person person = generateRandomPerson(isMale);

        file << person.firstName << ","
             << person.lastName << ","
             << person.patronymic << ",";

        if (person.spouse.empty())
        {
            file << "Empty";
        }
        else
        {
            file << person.spouse;
        }

        file << ", Friends: ";

        if (person.friends.empty())
        {
            file << "Empty";
        }
        else
        {
            for (const auto& friendName : person.friends)
            {
                file << friendName << ";";
            }
        }

        file << ", Enemies: ";

        if (person.enemies.empty())
        {
            file << "Empty";
        }
        else
        {
            for (const auto& enemyName : person.enemies)
            {
                file << enemyName << ";";
            }
        }

        file << "\n";
    }

    file.close();

    std::cout << "File was successfully created!\n\n";
}