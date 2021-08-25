#include "Ex05.01.h"
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 10

int main(void)
{
    dog dogs[ARRAY_SIZE] = { {"Bella", 26.7}, {"Luna",23.6}, {"Spot", 27.3}, {"Lucy", 22.4}, {"Cooper", 29.2}, {"Max", 26.5}, {"Bailey", 27.4}, {"Daisy", 27.1}, {"Sadie", 23.9}, {"Lola", 26.6} };
    printf_s("Dogs:\n");
    PrintDogArray(dogs, ARRAY_SIZE);
    SortDogsByName(dogs, ARRAY_SIZE);
    printf_s("Sorted by Name:\n");
    PrintDogArray(dogs, ARRAY_SIZE);
    SortDogsBySize(dogs, ARRAY_SIZE);
    printf_s("Sorted by Size:\n");
    PrintDogArray(dogs, ARRAY_SIZE);
}

void SwapDogs(dog *dogA, dog *dogB)
{
    dog temp = *dogA;
    *dogA = *dogB;
    *dogB = temp;
}

void PrintDogArray(dog dogArray[], size_t size)
{
    for (size_t i = 0; i < size; ++i, ++dogArray)
    {
        printf_s("{ Name: %s,\tSize: %g kgs }", dogArray->name, dogArray->kg);
        if (i != size - 1)
        {
            printf_s(", \n");
        }
    }
    printf_s("\n\n");
}

void SortDogsByName(dog dogArray[], size_t size)
{
    for (size_t i = 0; i < size - 1; ++i)
    {
        dog *smallest = &dogArray[i];
        for (size_t j = i + 1; j < size; ++j)
        {
            if (strcmp(dogArray[j].name, smallest->name) < 0)    //another dog is has lower alphabetical name than "smallest" dog
            {
                smallest = &dogArray[j];
            }
        }

        SwapDogs(&dogArray[i], smallest);
    }
}

void SortDogsBySize(dog dogArray[], size_t size)
{
    for (size_t i = 0; i < size - 1; ++i)
    {
        dog *smallest = &dogArray[i];
        for (size_t j = i + 1; j < size; ++j)
        {
            if (dogArray[j].kg < smallest->kg)    //another dog is smaller than "smallest" dog
            {
                smallest = &dogArray[j];
            }
        }

        SwapDogs(&dogArray[i], smallest);
    }
}