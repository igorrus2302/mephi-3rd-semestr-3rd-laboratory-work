#include <random>

#include "person.h"



int getRandomNumber(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

Person generateRandomPerson(bool isMale)
{
    Person person;

    if (isMale)
    {
        person.firstName = maleFirstNames[getRandomNumber(0, countFirstNames - 1)];
        person.lastName = maleLastNames[getRandomNumber(0, countLastNames - 1)];
        person.patronymic = malePatronymics[getRandomNumber(0, countPatronymics - 1)];
    }
    else
    {
        person.firstName = femaleFirstNames[getRandomNumber(0, countFirstNames - 1)];
        person.lastName = femaleLastNames[getRandomNumber(0, countLastNames - 1)];
        person.patronymic = femalePatronymics[getRandomNumber(0, countPatronymics - 1)];
    }

    return person;
}