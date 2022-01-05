// CSCI 115 Term project part 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <iostream>
using namespace std;

double timer(clock_t start, clock_t end) {



    double timer = end - start;
    timer = timer / (CLOCKS_PER_SEC / 1000); // ms
    return timer;


}

void bruteForceSum(vector<int>& a, int sum) {
    

    for (int i = 0; i < a.size()-1; ++i) {
        for (int j = i + 1; j < a.size(); ++j) {
            if (a[i] + a[j] == sum) {
                cout << "Pair (" << a[i] << ", " << a[j] << ")" << endl;
                return;
            }



        }



    }


    cout << "Pair that equals X not found" << endl;
}

//Worst Case time complexity O(N^2).


struct Entry{
        int num = 0;
        int frequency = 0;


};


int hashFunction(int& input, int size) { //creates hash key.
    
    if (input < 0) {
        int key = (input * (-1)) % size;
        return key;
    }
    int key = input % size;
    return key;


}

void updateHash(vector<Entry>& hashTable, int& num) {
    
    int key = hashFunction(num, hashTable.size());

    if (hashTable[key].frequency == 0) {
        hashTable[key].frequency++;
        hashTable[key].num = num;
    }
    else if (hashTable[key].num == num) {
        hashTable[key].frequency++;
    }
    else {
       // int i = 1;
        while (hashTable[key].frequency != 0 && hashTable[key].num != num) { //linear probing. increment key until we find the element or the next empty slot.
           
            ++key;

        }

        if (hashTable[key].num == num) {
            hashTable[key].frequency++;
        }
        else {
            hashTable[key].num = num;
            hashTable[key].frequency++;
        }

    }


}




bool searchHashTable(vector<Entry>& hashTable, int& num, int dupe, int size) {

    
    
    int key = hashFunction(num, size); // size is hash table size.
    
    

    if (hashTable[key].frequency == 0) {

        return false; // this means the element does not exist so return. 

    }
    else if (hashTable[key].num == num) {

        if (dupe == 0) {
            return true; //the number we are searching for exist, we can return.
        }
        else {
            if (hashTable[key].frequency > 1) { // A == B so we need to see if there is at least more than 1 that can make A + B = X
                return true;
            } 
        }

    }
    else {
       // int i = 1;
        while (hashTable[key].frequency != 0 && hashTable[key].num != num) {
            
           
            ++key;
        }



        if (hashTable[key].num == num && hashTable[key].frequency != 0) {


            if (dupe == 0) {
                return true; //we found the element using linear probing, return true.
            }
            else {
                if (hashTable[key].frequency > 1) { //check if frequency is higher than 1 if dupe.
                    return true;
               }
            }
        }
        else {
            return false; //using linear probing we found the next empty space meaning the element we are searching for does not exist.


        }



    }
  
  



}





void findPair(vector<int> a, int x, int size) {

    
   
    vector<Entry> hashTable(size + 300); // hashtable size is initial vector size + 200 for linear probing.
    clock_t start2 = clock();
    for (int i = 0; i < size; ++i) {

        updateHash(hashTable, a[i]);

    }

    bool ex = false;
    clock_t end2 = clock();
    cout << "Time for insertion is " << timer(start2, end2) << " ms" << endl;
    clock_t start3 = clock();
    for (int i = 0; i < size; ++i) {

        int A = a[i];
        int B = x - A; // we are looking for 2 numbers in the array that add to x. To do this we will subtract a[i] from x and search for the answer in the hashTable;
        
        bool exist;
        if (A != B) {
           exist = searchHashTable(hashTable, B, 0, size + 300); //+300 for linear probing, that is the size of hash table.
        }
        else {
            exist = searchHashTable(hashTable, B, 1, size + 300); // dupe. Check if frequency is > 1
        }
        
        
        
        


        
   
        if (exist == true) {
          cout << "Pair that sums up to " << x << " is (" << A << ", " << B << ")" << endl;
          ex = true;
           break;
        }
        
    }
    clock_t end3 = clock();

    cout << "Time for look up is is " << timer(start3, end3) << " ms" << endl;
    if (ex == false) {
        cout << "No pair was found that adds up to: " << x << endl;
    }
}




int main()
{
    int size = 10000;
    int x = 348;
    
    vector<int> setofInts(size);
    srand(time(NULL));

    for (int i = 0; i < setofInts.size(); ++i) { 

        setofInts[i] = (rand() % 10000);      //testing with elements under 1000.



    }


    
    cout << "HashTable implementation algorithm: " << endl;

    clock_t start2 = clock();
    findPair(setofInts, x, size);
    clock_t end2 = clock();

    cout << "Total Time is: " << timer(start2, end2) << endl;
    cout << endl;

    

    



    cout << "Brute Force searching for " << x << ":" <<  endl;
    clock_t start3 = clock();
    bruteForceSum(setofInts, x);
    clock_t end3 = clock();
    cout << "Time is: " << timer(start3, end3) << " ms" << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
