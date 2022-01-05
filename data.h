#ifndef DATA_H
#define DATA_H

// Include libraries
#include <ctime>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Timer Function
double timer(clock_t start, clock_t end);

// Input vector constructor
vector<int> vect(char order, int size);

// Insertion Trials runner
void insertionTrials(ofstream& outFile, string option, int size);

// Selection Trials runner
void selectionTrials(ofstream& outFile, string option, int size);

// Bubble Trials Runner
void bubbleTrials(ofstream& outFile, string option, int size);

// Merge Trials Runner
void mergeTrials(ofstream& outFile, string option, int size);

// First Quick Trials Runner
void firstQuickTrials(ofstream& outFile, string option, int size);

// Median Quick Trials Runner
void medianQuickTrials(ofstream& outFile, string option, int size);

// Random Quick Trials Runner
void randomQuickTrials(ofstream& outFile, string option, int size);

// Heap Trials Runner
void heapTrials(ofstream& outFile, string option, int size);

// Counting Trials Runner
void countingTrials(ofstream& outFile, string option, int size);

// Radix Trials Runner
void radixTrials(ofstream& outFile, string option, int size);

// Master Trials Runner
void trials(ofstream& outFile, string option, int size, int numTrials);

#endif // DATA_H