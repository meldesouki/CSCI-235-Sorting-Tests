/*************
Name: Merna Eldesouki
Assignment: CSCI 235, Fall 2018, Project 5
Date: December 11,2018
Description: This file implements different sorting algorithms and tests them.
***********/
#include "SortingTests.hpp"
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <vector>
using namespace std:: chrono;

/*****************************************************************/
/********************* SORTING FUNCTIONS *************************/
/*****************************************************************/
void selectionSort (int a[], size_t size){

	//by the time the counter is at the last element everything would be sorted
	for (int i = 0; i < size-1; i++){ 

		int curr_min = i; // set the first element in the unsorted half as the min

		for (int j = i+1; j < size; j++){

			if (a[curr_min] > a[j])
				curr_min = j;
		}

		//swapping
		int to_swap = a[curr_min];
		a[curr_min] = a[i];
		a[i] = to_swap;
	}
} //end selectionSort

void insertionSort(int a[], size_t size){

	//move marker after the first element because there are no comparisons to make yet
	for (int i = 1; i < size; i++){ 

		int marker = a[i];
		int j = i-1;

		//shift elements one position to the right to make space for insertion
		while ((j >= 0) && (a[j] > marker)){

			a[j+1] = a[j];
			j--;
		}

		a[j+1] = marker; //where the insertion happens
	}
} //end insertionSort

void mergeSort(int a[], int from, int to){
	
	if (from < to){

		int * merged_arr;
		merged_arr = new int[from + to];

		//Find midpoint to split data into halves
		int midpoint = (from + to)/2;

		mergeSort(a, from, midpoint);
		mergeSort(a, midpoint+1, to); //+1 so you don't sort the same thing twice

		const int size_of_first_half = midpoint - from + 1;
		const int size_of_second_half = to - midpoint;
		int i,j,k;
		//temp arrays dividing the data
		int * low, * high;
		low = new int[size_of_first_half]; 
		high = new int[size_of_second_half];

		for (i = 0; i < size_of_first_half; i++)
			low[i] = a[from + i];
			
		for (j = 0; j < size_of_second_half; j++)
			high[j] = a[midpoint + 1 + j];

		i = 0;
		j = 0;
		k = from;

		while ((i < size_of_first_half) && (j < size_of_second_half)){

			if (low[i] <= high[j]){

				a[k] = low[i];
				i++;
			}

			else{

				a[k] = high[j];
				j++;
			}

			k++;
		}

		while (i < size_of_first_half){

			a[k] = low[i];
			i++;
			k++;
		}

		while (j < size_of_second_half){

			a[k] = high[j];
			j++;
			k++;
		}
	
		delete[] merged_arr;
		delete[] low;
		delete[] high;
	}
} //end mergeSort

/*********************************************************************/
/****************** ARRAY POPULATING FUNCTIONS ***********************/
/*********************************************************************/

void generateRandomArray(int values[], size_t size){

	srand((time(NULL)));
	for (int i = 0; i < size; i++) {
		int rand_val = rand() % size; 
		values[i] = rand_val;
	}
} //end generateRandomArray


void generateAscendingArray(int values[], size_t size){

  generateRandomArray(values, size);
  //sorting in descending order
	for (int i = 0; i < size; i++){
		for(int j = i+1; j < size; j++){

			if (values[i] > values[j]){
				int temp = values[i];
				values[i] = values[j];
				values[j] = temp;
			}
		}
	}
  
} //end generateAscendingArray

void generateDescendingArray(int values[], size_t size){

	generateRandomArray(values, size);

	//sorting in descending order
	for (int i = 0; i < size; i++){
		for(int j = i+1; j < size; j++){

			if (values[i] < values[j]){
				int temp = values[i];
				values[i] = values[j];
				values[j] = temp;
			}
		}
	}

} //end generateDescendingArray

void generateLastTenRandomArray(int values[], size_t size){

	generateAscendingArray(values, size-10);

	for (int i = size-10; i < size; i++) {
		int rand_val = rand() % size; 
		values[i] = rand_val;
	}
} //end generateLastTenRandomArray

void generateFewRandomArray(int values[], size_t size){

	srand((time(NULL)));
	for (int i = 0; i < size; i++) {
		int rand_val = rand() % (size/10); 
		values[i] = rand_val;
	}

} //end generateFewRandomArray

/*****************************************************************/
/****************** RUNTIME TEST FUNCTIONS ***********************/
/*****************************************************************/


double sortTest(void (*sortingFunction)(int a[], size_t size), int values[], size_t size){

	double run_time_sum = 0;
	int count = 0;

	const int size_of_array = size;
	int * arr_copy;
	arr_copy = new int [size_of_array];
	/*while (count < 10){
		
		int arr_copy[size_of_array];
		for (int i = 0; i < size; i++){

			arr_copy[i] = values[i];
		}
		auto start_time =  high_resolution_clock().now();
		sortingFunction(arr_copy, size);
		auto end_time = high_resolution_clock().now();
		duration <double, std::micro> run_time = duration_cast<microseconds>(end_time - start_time);
		run_time_sum += run_time.count();*/

	while (count < 10){
		
		for (int i = 0; i < size; i++){

			arr_copy[i] = values[i];
		}
		
		auto start_time =  high_resolution_clock().now();
		sortingFunction(arr_copy, size);
		auto end_time =  high_resolution_clock().now();
		duration <double, std::micro> run_time = duration_cast<microseconds>(end_time - start_time);
		run_time_sum += (run_time.count());
		count++;
	}

	return run_time_sum/10;
}

double mergeSortTest(int values[], size_t size){

	int count = 0;
	const int size_of_array = size;
	double run_time_sum = 0;
	int * arr_copy;
	arr_copy = new int [size_of_array];
	while (count < 10){
		
		for (int i = 0; i < size; i++){

			arr_copy[i] = values[i];
		}
		auto start_time =  high_resolution_clock().now();
		mergeSort(arr_copy, 0, size-1);
		auto end_time = high_resolution_clock().now();
		duration <double, std::micro> run_time = duration_cast<microseconds>(end_time - start_time);
		run_time_sum += run_time.count();

		count++;
	}

	delete[] arr_copy;
	return run_time_sum/10;
}