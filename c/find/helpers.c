/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */


bool search(int value, int values[], int n){
    //binary search
    int low = 0;
    int high = n - 1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (values[mid] > value){
            high = mid - 1;
        } else if (values[mid] < value){
            low = mid + 1;
        } else {
            return 1;
        }
    }
    return 0;
}

/**
 * Sorts array of n values.
 */

const int max = 65536;
int counting_arr[max];

void sort(int values[], int n){
    //counting sort

    //create counting sort's array
    for (int i = 0; i < max; ++i){
        for (int j = 0; j < n; ++j){
            if (values[j] == i){
                counting_arr[i]++;
            }
        }
    }

    //sort based on created array
    int j = 0;
    while (j < n){
        for (int i = 0; i < max; ++i){
            int k = counting_arr[i];
            int m = 0;
            while (m < k){
                values[j] = i;
                m++;
                j++;
            }
        }
    }

    for (int i = 0; i < n; ++i){
        printf("%i: %i\n", i, values[i]);
    }
}
