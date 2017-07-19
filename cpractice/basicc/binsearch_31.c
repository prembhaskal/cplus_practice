#include <stdio.h>

int binsearch(int key, int v[], int n);

int main() {
    int v[] = {2, 4, 5, 7, 8, 8, 10, 19};
    int key;

    key = 2;
    printf("is number %d present in array: %s\n", key, (binsearch(key,v,7) >= 0) ? "found" : "not found");
    key = 3;
    printf("is number %d present in array: %s\n", key, binsearch(key,v,7) >= 0 ? "found" : "not found");


    return 0;
}

/*
    binary_search with 1 if condition inside loop.
    find x in v[0] <= v[1]...v[n-1]
*/
int binsearch(int key, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;

    while (low < high) {
        mid = (low + high) / 2;
        printf("low: %d, high: %d, mid: %d", low, high, mid);
        getchar(); // added to debug through the output, since code block debugger is somehow not working
        if (key <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }

    if (v[mid] == key)
        return mid; /*match*/
    else
        return -1; /*no match*/
}
