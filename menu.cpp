#include <iostream>

#include "menu.h"
#include "file_generator.h"
#include "file_reader.h"
#include "file_writer.h"
#include "backpack_solution.h"
#include "hash_table.h"
#include "room_allocator.h"
#include "index_alphabet.h"
#include "functional_tests.h"


using RoomAllocation = HashTable<Room, std::set<Person>>;


int Functions()
{
    std::cout << "      Menu:   \n\n";
    std::cout << "0. Exit\n";
    std::cout << "1. Generate data\n";
    std::cout << "2. Backpack task\n";
    std::cout << "3. Resettlement task\n";
    std::cout << "4. Build alphabet index\n";
    std::cout << "5. Run functional tests\n";

    std::cout << "\n";
    std::cout << "Insert number of function:\n";

    int function;

    std::cin >> function;

    return function;
}

int ChooseGenerator()
{
    std::cout << "Choose for what create data:\n\n";
    std::cout << "1. Items generator for backpack task\n";
    std::cout << "2. Room generator for resettlement task\n";
    std::cout << "3. People generator for resettlement task\n";

    std::cout << "\n";
    std::cout << "Insert number:\n";

    int generatorNumber;

    std::cin >> generatorNumber;

    return generatorNumber;
}

int ChooseBackpackTask()
{
    std::cout << "List of available tasks:\n\n";
    std::cout << "1. Task A. Max value of items and limited volume\n";
    std::cout << "2. Task B. Max value of items and limited volume and weight\n";
    std::cout << "3. Task C. Max value of items and limited weight\n";
    std::cout << "4. Task D. Max value of items, max volume is busy and limited weight\n";
    std::cout << "5. Task E. Max value of items and min weight\n";

    std::cout << "\n";
    std::cout << "Insert number of task\n";

    int numberOfTask;

    std::cin >> numberOfTask;

    return numberOfTask;
}

void Menu()
{
    bool isOpen = true;

    while (isOpen)
    {
        int function = Functions();

        switch (function)
        {
            default:
                std::cout << "Wrong number of function input\n\n";
                continue;

            case (0):
            {
                exit(0);
            }

            case(1):
            {
                int generatorNumber = ChooseGenerator();

                if (generatorNumber == 1) {
                    std::string fileName;

                    int numberOfItems;
                    int maxWeight;
                    int maxVolume;
                    int maxValue;

                    std::cout << "Write file name you want to create:\n";
                    std::cin >> fileName;
                    std::cout << "Write total count of items to create:\n";
                    std::cin >> numberOfItems;
                    std::cout << "Write max weight of one item:\n";
                    std::cin >> maxWeight;
                    std::cout << "Write max volume of one item:\n";
                    std::cin >> maxVolume;
                    std::cout << "Write max value of one item:\n";
                    std::cin >> maxValue;

                    GenerateItemsFile(fileName, numberOfItems, maxWeight, maxVolume, maxValue);
                }
                else if (generatorNumber == 2)
                {
                    std::string fileName;

                    int numberOfRooms;

                    std::cout << "Write file name you want to create:\n";
                    std::cin >> fileName;
                    std::cout << "Write total count of rooms to create:\n";
                    std::cin >> numberOfRooms;

                    GenerateRoomsFile(fileName, numberOfRooms);
                }
                else if (generatorNumber == 3)
                {
                    std::string fileName;

                    int numberOfPeople;

                    std::cout << "Write file name you want to create:\n";
                    std::cin >> fileName;
                    std::cout << "Write total count of people to create:\n";
                    std::cin >> numberOfPeople;

                    GeneratePeopleFile(fileName, numberOfPeople);
                }
                else
                {
                    std::cout << "Wrong generator number input\n\n";
                    break;
                }

                std::cout << "\n\n";
                break;
            }

            case (2):
            {
                int numberOfTask = ChooseBackpackTask();

                std::string fileName;

                std::cout << "Write file name with data:\n";
                std::cin >> fileName;

                DynamicArray<Item> items = ReadItemsFromFile(fileName);

                if (items.GetLength() == 0)
                {
                    std::cerr << "Memory allocation failed\n";
                }

                if (numberOfTask == 1)
                {
                    int maxVolume;

                    std::cout << "Write volume limit in backpack:\n";
                    std::cin >> maxVolume;

                    StateOfBackpack solutionA = SolveBackpackA(items, maxVolume);

                    PrintSolution(solutionA, items);
                }
                else if (numberOfTask == 2)
                {
                    int maxVolume;
                    int maxWeight;

                    std::cout << "Write volume and weight limit in backpack:\n";
                    std::cin >> maxVolume >> maxWeight;

                    StateOfBackpack solutionB = SolveBackpackB(items, maxVolume, maxWeight);

                    PrintSolution(solutionB, items);
                }
                else if (numberOfTask == 3)
                {
                    int maxWeight;

                    std::cout << "Write weight limit in backpack:\n";
                    std::cin >> maxWeight;

                    StateOfBackpack solutionC = SolveBackpackC(items, maxWeight);

                    PrintSolution(solutionC, items);
                }
                else if (numberOfTask == 4)
                {
                    int maxVolume;
                    int maxWeight;

                    std::cout << "Write volume and weight limit in backpack:\n";
                    std::cin >> maxVolume >> maxWeight;

                    StateOfBackpack solutionD = SolveBackpackD(items, maxVolume, maxWeight);

                    PrintSolution(solutionD, items);
                }
                else if (numberOfTask == 5)
                {
                    int maxVolume;

                    std::cout << "Write volume and weight limit in backpack:\n";
                    std::cin >> maxVolume;

                    StateOfBackpack solutionE = SolveBackpackE(items, maxVolume);

                    PrintSolution(solutionE, items);
                }
                else
                {
                    std::cout << "Wrong number of task input\n\n";
                    break;
                }

                std::cout << "\n\n";
                break;
            }
            case (3): {
                std::string roomsFileName;

                int minCountSolutions = 0;
                int maxCountSolutions = 3;

                std::cout << "Write rooms file name:\n";
                std::cin >> roomsFileName;

                std::string peopleFileName;

                std::cout << "Write people file name:\n";
                std::cin >> peopleFileName;

                DynamicArray<Room> rooms = ReadRoomsFromFile(roomsFileName);
                DynamicArray<Person> people = ReadPeopleFromFile(peopleFileName);

                RoomAllocation allocation;

                AllocateRooms(rooms, people, allocation, minCountSolutions, maxCountSolutions);

                std::cout << "\n\n";
                break;
            }
            case (4):
            {
                std::string inputFileName;
                std::string outputFileName;

                int pageSize;
                bool byWords;


                std::cout << "Write text file name to read:\n";
                std::cin >> inputFileName;

                std::string text = ReadTextFormFile(inputFileName);

                std::cout << "Write text file name to write the result:\n";
                std::cin >> outputFileName;

                std::cout << "Enter page size: \n";
                std::cin >> pageSize;

                std::cout << "Use word count - 1 or chars count - 0 for page size?\n";
                std::cin >> byWords;

                if (text.empty()) {
                    std::cerr << "The text is empty\n";
                    break;
                }

                HashTable<std::string, DynamicArray<int>> indexAlphabet;

                BuildAlphabetIndex(indexAlphabet, text, pageSize, byWords);

                WriteIndexAlphabetToFile(outputFileName, indexAlphabet);

                std::cout << "\n\n";

                break;
            }
            case (5):
            {
                HashTableTests();

                std::cout << "\n\n";
            }
        }
    }
}