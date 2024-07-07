//binary search in divide and conquer

#include <stdio.h>


int binarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        
        if (arr[mid] == target)
            return mid;

       
        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);

       
        return binarySearch(arr, mid + 1, right, target);
    }

   
    return -1;
}


int main() {
    int n, target;

    
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

  
    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    
    printf("Enter the target element to search: ");
    scanf("%d", &target);

    
    int index = binarySearch(arr, 0, n - 1, target);

 
    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");

    return 0;
}

