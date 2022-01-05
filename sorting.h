#ifndef SORTING_H
#define SORTING_H

// Include libraries
#include <vector>

// Name space
using namespace std;

// Insertion Sort
void insertionSort(vector<int>& a);

// Selection Sort
void selectionSort(vector<int>& a);

// Bubble Sort
void bubbleSort(vector<int>& a);

// Merge Sort
void mergeSort(vector<int>& arr, int p, int r);
void merge(vector<int>& arr, int p, int q, int r);

// Quick Sort First
int partition(vector<int>& a, int lo, int hi);
void quickSort(vector<int>& a, int p, int r);

// Quick Sort Median
int partitianMedian(vector<int>& a, int p, int r);
void quickSortMedian(vector<int>& a, int p, int r);

// Quick Sort Random
int partition2(vector<int>& a, int p, int r);
int RandomPivotPartition(vector<int>& a, int low, int high);
void randomQuickSort(vector<int>& a, int p, int r);

// Heap Sort
void buildMaxHeap(vector<int>& a);
void max_heapify(vector<int>& a, int i, int n);
void ascendingHeapSort(vector<int>& a);

// Counting Sort
int getMax(vector<int>& a);
void countingSort(vector<int>& a, vector<int>& b);

// Radix Sort
void countingSort2(vector<int>& a, int n, int d);
void radixSort(vector<int>& a, int d);


#endif // SORTING_H