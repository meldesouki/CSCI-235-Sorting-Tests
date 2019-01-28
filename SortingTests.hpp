
#ifndef SortingTests_hpp
#define SortingTests_hpp

#include <iostream>
#include <chrono>
using namespace std::chrono;

/*****************************************************************/
/********************* SORTING FUNCTIONS *************************/
/*****************************************************************/
/**
 @post Sorts an array in ascending order using the selection sort algorithm.
 @param a the array to sort
 @param size the number of elements in a
 */
void selectionSort(int a[], size_t size);

/**
 @post Sorts an array in ascending order using insertion sort.
 @param a the array to sort
 @param size of the array
 */
void insertionSort(int a[], size_t size);

/**
@post Sorts the elements in a range of a array.
@param a the array with the elements to sort
@param from the first position in the range to sort
@param to the last position in the range to sort (included)
 */
void mergeSort(int a[], int from, int to);

/*********************************************************************/
/****************** ARRAY POPULATING FUNCTIONS ***********************/
/*********************************************************************/


/**
 @post Populates values with randomly generated numbers in range size
 @param values the array to populate
 @param size of the array to be populated
 */
void generateRandomArray(int values[], size_t size);

/**
 @post Populates values with integers in ascending order
 @param values the array to populate
 @param size of the array to be populated
 */
void generateAscendingArray(int values[], size_t size);

/**
 @post Populates values with integers in descending order
 @param values the array to populate
 @param size of the array to be populated
 */
void generateDescendingArray(int values[], size_t size);

/**
 @post Populates values with integers in ascending order except for the last 10 that are randomly generated
 @param values the array to populate
 @param size of the array to be populated
 */
void generateLastTenRandomArray(int values[], size_t size);

/**
 @post Populates values with integers in randomly generated in range size/10
 @param values the array to populate
 @param size of the array to be populated
 */
void generateFewRandomArray(int values[], size_t size);

#endif /* SortingTests_hpp */
