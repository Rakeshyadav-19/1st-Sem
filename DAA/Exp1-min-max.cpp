#include <stdio.h>
#include <limits.h>

typedef struct
{
    int min;
    int max;
} MinMax;

// Function to find min and max using  divide and conquer
MinMax findMaxMinDivideConquer(int arr[], int low, int high)
{
    MinMax result;
    // Base case: Only one element
    if (low == high)
    {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }
    // Base case: Two elements
    if (high == low + 1)
    {
        if (arr[low] > arr[high])
        {
            result.max = arr[low];
            result.min = arr[high];
        }
        else
        {
            result.max = arr[high];
            result.min = arr[low];
        }
        return result;
    }
    // Divide the array into two halves
    int mid = (low + high) / 2;
    MinMax leftResult =
        findMaxMinDivideConquer(arr, low, mid);
    MinMax rightResult =
        findMaxMinDivideConquer(arr, mid + 1, high);
    // Combine the results
    result.min = (leftResult.min < rightResult.min) ? leftResult.min : rightResult.min;
    result.max = (leftResult.max > rightResult.max) ? leftResult.max : rightResult.max;
    return result;
}
int main()
{
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    MinMax result =
        findMaxMinDivideConquer(arr, 0, size - 1);
    printf("Divide & Conquer Method:\n");
    printf("Maximum: %d\n", result.max);
    printf("Minimum: %d\n", result.min);
    return 0;
}