#ifndef EX05_01
#define EX05_01
#include <stdio.h>

/// @file Ex05.01.h

typedef struct dog 
{
    char *name;
    float kg;
} dog;

/**
 * @brief Swap function for "dog" type
 * @param dogA 
 * @param dogB 
*/
void SwapDogs(dog *dogA, dog *dogB);

/**
 * @brief Prints out array of dogs to console
 * @param dogArray 
 * @param size 
*/
void PrintDogArray(dog dogArray[], size_t size);

/**
 * @brief Sorts a list of dogs by their name (Selection Sort)
 * @param dogArray 
 * @param size 
*/
void SortDogsByName(dog dogArray[], size_t size);

/**
 * @brief Sorts a list of dogs by their size (Selection Sort)
 * @param dogArray 
 * @param size 
*/
void SortDogsBySize(dog dogArray[], size_t size);

#endif