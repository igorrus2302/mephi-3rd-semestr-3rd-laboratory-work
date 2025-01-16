#pragma once

#include "names.h"
#include "dynamic_array.h"

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <random>
#include <string>
#include <limits>

struct Person {

    std::string firstName;   // Имя
    std::string lastName;    // Фамилия
    std::string patronymic;  // Отчество
    std::set<std::string> friends;  // Друзья
    std::set<std::string> enemies;  // Враги
    std::string spouse;        // Супруг

    bool operator<(const Person& other) const
    {
        return tie(lastName, firstName, patronymic) < tie(other.lastName, other.firstName, other.patronymic);
    }
};

int getRandomNumber(int min, int max);
Person generateRandomPerson(bool isMale);

template <typename T>
void generatePeople(int maleCount, int femaleCount, DynamicArray<Person>& peopleArray)
{
    std::set<Person> peopleSet;  // Используется для уникальных людей

    // Генерация мужчин
    for (int i = 0; i < maleCount; ++i)
    {
        Person person = generateRandomPerson(true);
        peopleSet.insert(person);
    }

    // Генерация женщин
    for (int i = 0; i < femaleCount; ++i)
    {
        Person person = generateRandomPerson(false);
        peopleSet.insert(person);
    }

    // Добавление людей в DynamicArray
    for (const auto& person : peopleSet)
    {
        peopleArray.Append(person);
    }

    // Генерация случайных друзей, врагов и супругов
    int totalPeople = peopleArray.GetLength();

    for (int i = 0; i < totalPeople; ++i)
    {
        Person& current = peopleArray[i];

        // Случайное количество друзей и врагов
        int friendsCount = getRandomNumber(0, 3);
        int enemiesCount = getRandomNumber(0, 3);

        for (int j = 0; j < friendsCount; ++j)
        {
            int friendIndex = getRandomNumber(0, totalPeople - 1);
            if (friendIndex != i)
                current.friends.insert(peopleArray[friendIndex].lastName);
        }

        for (int j = 0; j < enemiesCount; ++j)
        {
            int enemyIndex = getRandomNumber(0, totalPeople - 1);
            if (enemyIndex != i)
                current.enemies.insert(peopleArray[enemyIndex].lastName);
        }

        // 50%-й шанс на наличие супруга
        if (getRandomNumber(0, 1))
        {
            int spouseIndex = getRandomNumber(0, totalPeople - 1);
            if (spouseIndex != i)
                current.spouse = peopleArray[spouseIndex].firstName + " " + peopleArray[spouseIndex].lastName;
        }
    }
}


