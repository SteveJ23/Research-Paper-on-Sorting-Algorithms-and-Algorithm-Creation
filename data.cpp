// Include header files
#include "data.h";
#include "sorting.h";

// Include libraries
#include <fstream>;



// Timer function
double timer(clock_t start, clock_t end) {

    double timer = end - start;
    timer = timer / (CLOCKS_PER_SEC / 1000); // ms
    return timer;

}

// Vector data input builder
vector<int> vect(char order, int size) {  
    vector<int> input;
    
    if (order == 'a') { // create ascending order vecor        
        for (int i = 0; i < size; i++) {

            input.push_back(i);

        }
    }
    else if (order == 'd') { // create descending order vector        
        for (int i = (size-1); i >= 0; i--) {

            input.push_back(i);
        }
    }
    else { // create randomly ordered vector
        for (int i = 0; i < size; i++) { // random from 0 to size vector
            input.push_back(rand() % size); //random elements from 0 to testing2.size().
        }

    }

    // Return vector and exit function
    return input;

}

void insertionTrials(ofstream& outFile, string option, int size) {
    vector<int> input;
    
    // Best - run with ascending input
    if (option == "best") {    
    input = vect('a', size);

    clock_t start = clock();
    insertionSort(input);
    clock_t end = clock();

    outFile <<  timer(start, end) << ", ";
    cout << timer(start, end) << ", ";
    }

    // Worst - run with descending input
    else if (option == "worst") {
        if (size <= 400000) {
            input = vect('d', size);

            clock_t start = clock();
            insertionSort(input);
            clock_t end = clock();

            outFile << timer(start, end) << ", ";
            cout << timer(start, end) << ", ";
        }
    }

    // Average - run with random input
    else {
        if (size <= 100000)
            input = vect('r', size);

            clock_t start = clock();
            insertionSort(input);
            clock_t end = clock();

            outFile << timer(start, end) << ", ";
            cout << timer(start, end) << ", ";
    }
    
}

void selectionTrials(ofstream& outFile, string option, int size) {
    
    vector<int> input;
    
    // Best - ascending input
    if (option == "best") {
        input = vect('a', size);

        clock_t start = clock();
        selectionSort(input);
        clock_t end = clock();

        outFile << timer(start, end) << ", ";
        cout << timer(start, end) << ", ";
    }

    // Worst - descending input
    else if (option == "worst") {
        input = vect('d', size);

        clock_t start = clock();
        selectionSort(input);
        clock_t end = clock();

        outFile << timer(start, end) << ", ";
        cout << timer(start, end) << ", ";
    }

    // Average - randon input
    else {
        input = vect('r', size);

        clock_t start = clock();
        selectionSort(input);
        clock_t end = clock();

        outFile << timer(start, end) << ", ";
        cout << timer(start, end) << ", ";
    }
    
}

void bubbleTrials(ofstream& outFile, string option, int size) {
    
    vector<int> input;
    
    // Best - ascending input
    if (option == "best") {
        input = vect('a', size);

        clock_t start = clock();
        bubbleSort(input);
        clock_t end = clock();

        outFile << timer(start, end) << ", ";
        cout << timer(start, end) << ", ";
    }

    // Worst - descending input
    else if (option == "worst") {
        input = vect('d', size);

        clock_t start = clock();
        bubbleSort(input);
        clock_t end = clock();

        outFile << timer(start, end) << ", ";
        cout << timer(start, end) << ", ";
    }

    // Average - random input
    else {
        input = vect('r', size);

        clock_t start = clock();
        bubbleSort(input);
        clock_t end = clock();

        outFile << timer(start, end) << ", ";
        cout << timer(start, end) << ", ";
    }
    
}

void mergeTrials(ofstream& outFile, string option, int size) {
    
    vector<int> input;
    
    // Best - ascending input
    if (option == "best") {
        input = vect('a', size);

        clock_t start = clock();
        mergeSort(input, 0, size-1);
        clock_t end = clock();

        outFile << timer(start, end) << ", ";
        cout << timer(start, end) << ", ";
    }

    // Worst - descending input
    else if (option == "worst") {
        input = vect('d', size);

        clock_t start = clock();
        mergeSort(input, 0, size - 1);
        clock_t end = clock();

        outFile << timer(start, end) << ", ";
        cout << timer(start, end) << ", ";
    }

    // Average - random input
    else {
        input = vect('r', size);

        clock_t start = clock();
        mergeSort(input, 0, size - 1);
        clock_t end = clock();

        outFile << timer(start, end) << ", ";
        cout << timer(start, end) << ", ";
    }
    
}


void firstQuickTrials(ofstream& outFile, string option, int size) {

    vector<int> input;

    // Ascending input
    if (option == "best") {
        if (size <= 4000) {
            input = vect('a', size);

            clock_t start = clock();
            quickSort(input, 0, size - 1);
            clock_t end = clock();

            outFile << timer(start, end) << ", ";
            cout << timer(start, end) << ", ";
        }
    }

    // Descending input
    else if (option == "worst") {
        if (size <= 4000) {
            input = vect('d', size);

            clock_t start = clock();
            quickSort(input, 0, size - 1);
            clock_t end = clock();

            outFile << timer(start, end) << ", ";
            cout << timer(start, end) << ", ";
        }
    }

    // Random input
    else {
        //if (size <= 390000) {
            input = vect('r', size);

            clock_t start = clock();
            quickSort(input, 0, size - 1);
            clock_t end = clock();

            outFile << timer(start, end) << ", ";
            cout << timer(start, end) << ", ";
        //}
    }

}

void medianQuickTrials(ofstream& outFile, string option, int size) {

    vector<int> input;

    // Ascending input
    if (option == "best") {
        if (size <= 4000) {
            input = vect('a', size);

            clock_t start = clock();
            quickSortMedian(input, 0, size - 1);
            clock_t end = clock();

            outFile << timer(start, end) << ", ";
            cout << timer(start, end) << ", ";
        }
    }

    // Descending input
    else if (option == "worst") {
        if (size <= 4000) {
            input = vect('d', size);

            clock_t start = clock();
            quickSortMedian(input, 0, size - 1);
            clock_t end = clock();

            outFile << timer(start, end) << ", ";
            cout << timer(start, end) << ", ";
        }
    }

    // Random input
    else {
        //if (size <= 390000) {
            input = vect('r', size);

            clock_t start = clock();
            quickSortMedian(input, 0, size - 1);
            clock_t end = clock();

            outFile << timer(start, end) << ", ";
            cout << timer(start, end) << ", ";
        //}
    }

}


void randomQuickTrials(ofstream& outFile, string option, int size) {

    vector<int> input;

    // Ascending input

    if (option == "best") {
        if (size <= 4000) {
            input = vect('a', size);

            clock_t start = clock();
            randomQuickSort(input, 0, size - 1);
            clock_t end = clock();

            outFile << timer(start, end) << ", ";
            cout << timer(start, end) << ", ";
        }
    }

    // Descending input
    else if (option == "worst") {
        if (size <= 4000) {
            input = vect('d', size);

            clock_t start = clock();
            randomQuickSort(input, 0, size - 1);
            clock_t end = clock();

            outFile << timer(start, end) << ", ";
            cout << timer(start, end) << ", ";
        }
    }

    // Random input
    else {
        //if (size <= 390000) {
            input = vect('r', size);

            clock_t start = clock();
            randomQuickSort(input, 0, size - 1);
            clock_t end = clock();

            outFile << timer(start, end) << ", ";
            cout << timer(start, end) << ", ";
        //}
    }

}



void heapTrials(ofstream& outFile, string option, int size) {

    vector<int> input;

    // Ascending input
    if (option == "best") {
        input = vect('a', size);

        clock_t start = clock();
        ascendingHeapSort(input);
        clock_t end = clock();

        outFile << timer(start, end) << ", ";
        cout << timer(start, end) << ", ";
    }

    // Descending input
    else if (option == "worst") {
        input = vect('d', size);

        clock_t start = clock();
        ascendingHeapSort(input);
        clock_t end = clock();

        outFile << timer(start, end) << ", ";
        cout << timer(start, end) << ", ";
    }

    // Random input
    else {
        input = vect('r', size);

        clock_t start = clock();
        ascendingHeapSort(input);
        clock_t end = clock();

        outFile << timer(start, end) << ", ";
        cout << timer(start, end) << ", ";
    }

}


void countingTrials(ofstream& outFile, string option, int size) {

    vector<int> input;
    vector<int> b(size);

    // ascending
    if (option == "best") { // max is already less than n
        input = vect('a', size);

        clock_t start = clock();
        countingSort(input, b);
        clock_t end = clock();

        outFile << timer(start, end) << ", ";
        cout << timer(start, end) << ", ";
    }

    // descending
    else if (option == "worst") {
        input = vect('d', size);

        clock_t start = clock();
        countingSort(input, b);
        clock_t end = clock();

        outFile << timer(start, end) << ", ";
        cout << timer(start, end) << ", ";
    }

    // random
    else {
        input = vect('r', size);

        clock_t start = clock();
        countingSort(input, b);
        clock_t end = clock();

        outFile << timer(start, end) << ", ";
        cout << timer(start, end) << ", ";
    }

}

void radixTrials(ofstream& outFile, string option, int size) {

    vector<int> input;
    

    // ascending
    if (option == "best") { // max is already less than n
        input = vect('a', size);
        int digit = getMax(input);
        digit = int(log10(digit) + 1);

        clock_t start = clock();
        radixSort(input, digit);
        clock_t end = clock();

        outFile << timer(start, end) << ", ";
        cout << timer(start, end) << ", ";
    }

    // descending
    else if (option == "worst") {
        input = vect('d', size);
        int digit = getMax(input);
        digit = int(log10(digit) + 1);

        clock_t start = clock();
        radixSort(input, digit);
        clock_t end = clock();

        outFile << timer(start, end) << ", ";
        cout << timer(start, end) << ", ";
    }

    // random
    else {
        input = vect('r', size);
        int digit = getMax(input);
        digit = int(log10(digit) + 1);

        clock_t start = clock();
        radixSort(input, digit);
        clock_t end = clock();

        outFile << timer(start, end) << ", ";
        cout << timer(start, end) << ", ";
    }

}



void trials(ofstream& outFile, string option, int size, int numTrials) {
    
    // Insertion Trials runner
    outFile << "Insertion: ";
    cout << "Insertion: ";
    for (int i = 0; i < numTrials; i++) {
        insertionTrials(outFile, option, size);
    }
    outFile << "\n\n";
    cout << "\n\n";
    
    
    
    // Selection Trials runner
    if (size <= 100000) { // 
        outFile << "Selection: ";
        cout << "Selection: ";
        for (int i = 0; i < numTrials; i++) {
            selectionTrials(outFile, option, size);
        }
        outFile << "\n\n";
        cout << "\n\n";
    }

    // Merge Trials runner
    outFile << "Merge: ";
    cout << "Merge: ";
    for (int i = 0; i < numTrials; i++) {
        mergeTrials(outFile, option, size);
    }
    outFile << "\n\n";
    cout << "\n\n";

    

    // First Quick Trials runner
    outFile << "First Quick: ";
    cout << "First Quick: ";
    for (int i = 0; i < numTrials; i++) {
        firstQuickTrials(outFile, option, size);
    }
    outFile << "\n\n";
    cout << "\n\n";
    
    // Median Quick Trials runner
    outFile << "Median Quick: ";
    cout << "Median Quick: ";
    for (int i = 0; i < numTrials; i++) {
        medianQuickTrials(outFile, option, size);
    }
    outFile << "\n\n";
    cout << "\n\n";

    // Random Quick Trials runner
    outFile << "Random Quick: ";
    cout << "Random Quick: ";
    for (int i = 0; i < numTrials; i++) {
        randomQuickTrials(outFile, option, size);
    }
    outFile << "\n\n";
    cout << "\n\n";

    

    // Heap Trials runner
    outFile << "Heap: ";
    cout<< "Heap: ";
    for (int i = 0; i < numTrials; i++) {
        heapTrials(outFile, option, size);
    }
    outFile << "\n\n";
    cout << "\n\n";

    // Counting Trials runner
    outFile << "Counting: ";
    cout << "Counting: ";
    for (int i = 0; i < numTrials; i++) {
        countingTrials(outFile, option, size);
    }
    outFile << "\n\n";
    cout << "\n\n";

    // Radix Trials runner
    outFile << "Radix: ";
    cout << "Radix: ";
    for (int i = 0; i < numTrials; i++) {
        radixTrials(outFile, option, size);
    }
    outFile << "\n\n";
    cout << "\n\n";

    // Bubble Trials runner
    if (size <= 100000) {
        outFile << "Bubble: ";
        cout << "Bubble: ";
        for (int i = 0; i < numTrials; i++) {
            bubbleTrials(outFile, option, size);
        }
    }
          
}