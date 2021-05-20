#include <iostream>
#include<vector>

using namespace std;

void quickSort(vector < int > &, int , int );
int partition(vector < int > &, int , int );
void printElems(vector < int > );
vector<int> generateRandomList( int );


int main() {
    // Initializing the variables we will use to add and enumerate our list of inputs from user as well as a vector to store all of these inputs.
    int listItem, 
        listLength,
        genRand;

    vector < int > list;

    // Taking user inputs to populate our list with values to be sorted.
    cout << "\n\nEnter the length of the list you would like to sort: ";
    cin >> listLength;
    cout << "\n\n";

    // Since I rather automate as much as possible we can prompt the user to choose to either generate a random list of values between 0 and 100 in
    //  in the length they provided, if they opt not to we will then populate our list using user input values
    cout << "\n\nWould you like to generate a random list between 0 and 100? (1 for yes, 0 for no) : ";
    cin >> genRand;

    // Here we will use the user input response as a flag as a condition to our logic of how our list is populated.
    //  if True we will generate a random list using our generateRandomList function to be saved as the list to be sorted, otherwise we will prompt the user
    //  for more input.
    if(genRand){
        list = generateRandomList(listLength);
    } else {
        cout << "In that case please enter the values you would like sorted.\n";
        // Here we will iterate as many times as perscribed by the listLength input by the user while taking inputes to populate our unsorted list.
        for (int index = 0; index < listLength; index++) {
            cout << "Enter item number  " << index + 1 << " :  ";
            cin >> listItem;
            list.push_back(listItem);
    }
    };

    cout << "\n\n";


    // printing the inputed list to the console prior to sorting
    cout << "\n\nPrior to sorting the list reads: ";
    printElems(list);

    // Calling the quick sort funtion to sort the list prior to reprinting to console
    quickSort(list, 0, listLength - 1);

    // Printing the freshly sorted list to the console.
    cout << "\n\nThe list after sorting reads: ";
    printElems(list);

    cout << "\n\n\n";

    return 0;
}

// I will end up needing to print out my list in a nice single line space separated format, so this sub-function will serve nicely 
void printElems(vector < int > list) {
    int i;
    int len = list.size();
    for (i = 0; i < len; i++)
        cout << list[i] << "  ";

}

vector<int> generateRandomList(int listLength){
    vector < int > list;

    for (int index = 0; index < listLength; index++) {
        list.push_back(rand()%100);
    }  
    return list;
}


// This will effectively partition our array into 2 subarrays returning the new index of our pivot element after it has been sorted
int partition(vector < int > & list, int start, int end) {
    int pivotIndex = start, 
        pivot = list[start], 
        index;

    //We can now test each of the elements against our pivot element swapping as needed when our pivot is greater than our current element
    for (index = start + 1; index <= end; index++) {
        if (pivot > list[index]) {
            list[pivotIndex] = list[index];
            list[index] = list[pivotIndex + 1];
            list[pivotIndex + 1] = pivot;

            pivotIndex++;
        }
    }
    // We will return the new index of our pivot as it is considered to be sorted so that it may be used in our recursive call on the
    // left and right sub-arrays as either a starting or ending point.
    return pivotIndex; 
}

// Recursive implementation designed to partion and sort sub-partitions until the end of the call stack each iteration modifying the 
//  array in memory into a sorted format. Since we are modifying the array in memory there is no need to return anything, we can simply 
//  recall the newly sorted array as needed
void quickSort(vector < int > & list, int leftPointer, int rightPointer) {
    if (leftPointer < rightPointer) {
        // pivotIndex will store the location of our newly sorted partition as returned from partitioning our list argument
        int pivotIndex= partition(list, leftPointer, rightPointer);

        //Applying Quicksort on the elements on Left and the right of the pivot element respectively
        quickSort(list, leftPointer, pivotIndex- 1);
        quickSort(list, pivotIndex+ 1, rightPointer);
    }
}
