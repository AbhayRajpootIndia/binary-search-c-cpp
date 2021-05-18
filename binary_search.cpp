#include <stdio.h>

int binary_search(int array[], int value, int start, int stop) {

// start- first index of array -> initially: 0
// stop- last index of array   -> initially: (length of array -1)
// value- the element to search for
// array[] - the parent array

    int mid;

    if (start == stop) {                       // stop recurssion
        if (array[start] == value) {
            return start;
        }
        else {
            return -1;                         // value not found in array
        };
    }
    else if (stop % 2 == 0) {                  // value of mid for next iteration
        mid = (start + stop + 1) / 2;
    }
    else {
        mid = (start + stop) / 2;
    };

    if (value == array[mid]) {
        return mid;                                             // value found at index mid (search completed)
    }
    else if (value < array[mid]) {
        return binary_search(array, value, start, mid - 1);     // value in left part of array
    }
    else if (array[mid] < value) {
        return binary_search(array, value, mid + 1, stop);      // value in right part of array
    }

};

int main() {
    int array [] = {1,2,3,4,5,6,7,8,9};
    int value{0}, start{0}, stop = sizeof(array) / sizeof(int) -1;   // values to initialise binary search

    printf("Enter the value to find: ");
    scanf("%d", &value);

    int index = binary_search(array, value, start, stop);

    if (index > -1) {
        printf("The value was found at index: %d", index);
        printf("\n");
        }
    else {
        printf("The value doesn't exist in array.\n");
    };
