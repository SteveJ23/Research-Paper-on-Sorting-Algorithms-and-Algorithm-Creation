// Include header files
#include "sorting.h";


void insertionSort(vector<int>& a) {

    for (int i = 1; i < a.size(); ++i) {

        int key = a[i];

        int j = i - 1;

        while (j >= 0 && a[j] > key) {

            a[j + 1] = a[j];


            --j;
        }

        a[j + 1] = key;

    }


}

// -----------------------------------------------------------------//

void selectionSort(vector<int>& a) {

    int min;

    for (int i = 0; i < a.size(); ++i) {

        min = i;
        for (int j = i + 1; j < a.size(); ++j) {


            if (a[j] < a[min]) {
                min = j;
            }

        }

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;

    }

}

// -----------------------------------------------------------------//

void bubbleSort(vector<int>& a)
{
    // Bubble largest number toward the right
    for (int i = a.size() - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (a[j] > a[j + 1])
            {
                // Swap the numbers
                double temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
    // Exit the function
    return;
}

// -----------------------------------------------------------------//

void mergeSort(vector<int>& arr, int p, int r) {

    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);

    }

}

void merge(vector<int>& arr, int p, int q, int r) {

    int n1 = (q - p) + 1;

    int n2 = (r - q) + 1;

    vector<int> leftArr(n1 + 1);
    vector<int> rightArr(n2);


    int l = 0;

    for (int i = p; i <= q; ++i) {


        leftArr[l] = arr[i];
        ++l;

    }

    int z = 0;
    for (int i = q + 1; i <= r; ++i) {

        rightArr[z] = arr[i];
        ++z;

    }

    leftArr[leftArr.size() - 1] = numeric_limits<int>::max();
    rightArr[rightArr.size() - 1] = numeric_limits<int>::max();

    int i = 0;
    int j = 0;


    for (int k = p; k <= r; ++k) {

        if (leftArr[i] < rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;

        }
        else {
            arr[k] = rightArr[j];
            ++j;
        }

    }

}

// -----------------------------------------------------------------//

int partition(vector<int>& a, int lo, int hi) { //first element 

    int i = lo;
    int j = hi + 1;


    while (true) {

        while (a[lo] >= a[++i]) { //pivot is lo so we can start off at lo + 1

            if (i >= hi) {
                break;
            }

        }



        while (a[lo] <= a[--j]) {

            if (j <= lo) {
                break;
            }

        }

        if (i >= j) {
            break;
        }


        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;

    }

    int temp = a[j]; //swap pivot with j
    a[j] = a[lo];
    a[lo] = temp;


    return(j);

}


void quickSort(vector<int>& a, int p, int r) {

    if (p < r) {

        int q = partition(a, p, r);

        quickSort(a, p, q - 1); //pivot is already sorted so do from q-1.
        quickSort(a, q + 1, r);

    }

}

//median

int partitianMedian(vector<int>& a, int p, int r) {

    int mid = (p + r) / 2;
    int x = (a[p] + a[mid] + a[r]) / 3;
    int i = p - 1;
    int j = r + 1;

    while (true) {

        while (x < a[--j]) {
            if (j < p) {
                break;
            }

        }

        while (x > a[++i]) {

            if (i > r) {
                break;
            }

        }

        if (i < j) {
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;

        }
        else {
            return j;
        }

    }

}


void quickSortMedian(vector<int>& a, int p, int r) {

    if (p < r) {

        int q = partitianMedian(a, p, r);
        quickSortMedian(a, p, q);
        quickSortMedian(a, q + 1, r);

    }

}

// Random

void swap(int &m, int &n) {
    int temp;
    temp = m;
    m = n;
    n = temp;
}

int partition2(vector<int>& a, int p, int r) {

    int x = a[p];

    int i = p - 1;
    int j = r + 1;

    while (true) {

        while (x < a[--j]) {

            if (j < p) {
                break;
            }

        }

        while (x > a[++i]) {

            if (i > r) {
                break;
            }

        }

        if (i < j) {
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;

        }
        else {
            return j;
        }

    }

}

int RandomPivotPartition(vector<int>& a, int low, int high) {
    int pvt, n;
    n = rand();
    // Randomizing the pivot value in the given subpart of array.
    pvt = low + n % (high - low + 1);

    int temp = a[pvt];
    a[pvt] = a[low];
    a[low] = temp;
    //swap(a[high], a[pvt]);

    return partition2(a, low, high);
}

void randomQuickSort(vector<int>& a, int p, int r) {

    if (p < r) {
        int q = RandomPivotPartition(a, p, r);

        randomQuickSort(a, p, q);
        randomQuickSort(a, q + 1, r);

    }

}
// -----------------------------------------------------------------//

void buildMaxHeap(vector<int>& a) {

    int n = a.size();

    for (int i = ((n - 1) / 2); i > 0; --i) {

        max_heapify(a, i, n);
    }

}


void max_heapify(vector<int>& a, int i, int n) {

    int l = (2 * i);
    int r = (2 * i) + 1;


    int largest;

    if (l < n && a[l] > a[i]) {

        largest = l;

    }
    else {
        largest = i;
    }


    if (r < n && a[r] > a[largest]) {

        largest = r;

    }

    if (largest != i) {

        int temp = a[largest];
        a[largest] = a[i];
        a[i] = temp;

        max_heapify(a, largest, n);
    }


}


void ascendingHeapSort(vector<int>& a) {
    buildMaxHeap(a);

    for (int i = a.size() - 1; i > 1; --i) {
        int temp = a[i];
        a[i] = a[1];
        a[1] = temp;

        max_heapify(a, 1, i);

    }

}

// -----------------------------------------------------------------//

int getMax(vector<int>& a) {
    int max = a[0];
    for (int i = 1; i < a.size(); i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    return(max);
}

void countingSort(vector<int>& a, vector<int>& b) {

    int max = getMax(a);
    vector<int> c;

    for (int i = 0; i < max + 1; ++i) {
        c.push_back(0); //make an vector with pure 
    }

    for (int j = 1; j < a.size(); ++j) {
        c[a[j]] = c[a[j]] + 1;
    }

    for (int i = 1; i < c.size(); ++i) {
        c[i] = c[i] + c[i - 1];
    }

    for (int j = a.size() - 1; j >= 1; --j) {
        b[c[a[j]]] = a[j];
        c[a[j]] = c[a[j]] - 1;
    }

}

// -----------------------------------------------------------------//

void countingSort2(vector<int>& a, int n, int d) { // this will be used for radix sort. It is the same as radixSort but we will be using it to do 

    vector<int> aux(10); // aux size 10
    vector<int> result(n + 1); //output size n+1;

    for (int i = 0; i < 10; ++i) {

        aux[i] = 0;
    }

    for (int j = 0; j <= n; ++j) { // frequency

        aux[(a[j] / d) % 10] = aux[(a[j] / d) % 10] + 1;

    }

    for (int i = 1; i < 10; ++i) {

        aux[i] = aux[i] + aux[i - 1];

    }

    for (int j = n; j >= 0; --j) {

        result[aux[(a[j] / d) % 10] - 1] = a[j];
        aux[(a[j] / d) % 10] = aux[(a[j] / d) % 10] - 1;

    }

    for (int i = 0; i <= n; ++i) {

        a[i] = result[i];

    }

}

void radixSort(vector<int>& a, int d) {

    int j = 1;
    int n = a.size() - 1;


    for (int i = 1; i <= d; ++i) { //loop from 1 to d(max number of digits)

        if (i > 1) {
            j = 10 * j; //the first digit is at 10^0 which is 1. second digit is it 10^1, third is at 10^2 and so on. So if I is greater than 1 we take the power of it.
        }

        countingSort2(a, n, j);

    }

}