
This read me file is for the algorithm creation code.

This program has 2 algorithms implemented. Given a list of numbers and another number X, these algorithms can find whether or not there is a pair in the list that adds up to X. One of them is by brute force meaning it checks all possible combinations, while the second one is a more effective and time managable algorithm which uses hashtable implementation.

How to execute the code:
To execute the code, head over to the main function. The first few lines you will see 2 integers, x and size. Look at the "int size" first and after the "=", write the size of the array you would like to test. This array will have randomly generated numbers from 0 to size-1. Now choose what value you would like x to be, which is the number that is going to be used to find a pair that adds up to that x. Now Press F5 to run and see the result. 


The result will print out a few things. The first bit is the hashtable algorithm and the second bit is the brute force algorithm. For the hashtable implementation, it prints out the pair as well as the time for insertion in ms and the time for look up in ms. The second bit which is the brute force algorithm, prints out the time in ms as well as the pair.



Functions in the code:

There are several functions in the code. 1 function is for the first algorithm while 4 functions and a struct are for the second algorithm.

First algorithm functions:
bruteForceSum


HashTable Algorithm Functions:
hashFunction
updateHash
searchHashTable
findPair
struct Entry


The function timer is to calculate the time it takes for the function to complete.
