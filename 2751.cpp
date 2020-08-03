#include <iostream>
#include <algorithm>
using namespace std;
int n;
int *arr;
void insertionSort(int left, int right)
{
    for (int i = left; i < right; i++)
    {
        int key = arr[i + 1];
        int j;
        for (j = i; j >= left; j--)
        {
            if (arr[j] > key)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = key;
    }
}
int *Median(int *a, int *b, int *c)
{
    if (*a < *b)
    {
        if (*b < *c)
            return b;
        else if (*a < *c)
            return c;
        else
            return a;
    }
    else
    {
        if (*a < *c)
            return a;
        else if (*b < *c)
            return c;
        else
            return b;
    }
}

void quickSort(int start, int end)
{

    if (end - start < 50)
    {
        insertionSort(start, end);
        return;
    }
    if (start < end)
    {
        int i = start;
        int j = end + 1;
        swap(arr[start], *Median(&arr[start], &arr[end], &arr[(end - start) / 2]));
        int pivot = arr[start];
        do
        {
            do
            {
                i++;
            } while (arr[i] < pivot);
            do
            {
                j--;
            } while (arr[j] > pivot);
            if (i < j)
                swap(arr[i], arr[j]);
        } while (i < j);
        swap(arr[start], arr[j]);
        quickSort(start, j - 1);
        quickSort(j + 1, end);
    }
}

int main()
{
    scanf("%d", &n);
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    quickSort(0, n - 1);
    //sort(arr,arr+n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}
