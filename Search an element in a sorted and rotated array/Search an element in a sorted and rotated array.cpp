// Search an element in a sorted and rotated array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int search(int arr[], int l, int h, int key) {
	if (l > h) return -1;

	int mid = (l + h) / 2;
	if (arr[mid] == key) return mid;

    if (arr[l] <= arr[mid])
    {
        /* As this subarray is sorted, we can quickly
        check if key lies in half or other half */
        if (key >= arr[l] && key <= arr[mid])
        return search(arr, l, mid-1, key);
 
        return search(arr, mid+1, h, key);
    }

	if (key >= arr[mid] && key <= arr[h])
		return search(arr, mid + 1, h, key);

	return search(arr, l, mid - 1, key);

}

int main()
{
	int arr[] = { 4, 5, 6, 7,8 , 9, 1 ,2, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 8;
	int i = search(arr, 0, n - 1, key);

	if (i != -1)
		cout << "Index: " << i << endl;
	else
		cout << "Key not found ";

    return 0;
}

