#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;

int checking(int i, int *parent);

void swap(int **a, int **b, int *temp)
{
    temp = *b;
    *b = *a;
    *a = temp;
}

void quickSort(int **d, int start, int end)
{
    int i, j;
    int *temp;
    int pivot;
    if (start < end)
    {
        i = start;
        j = end + 1;
        pivot = d[start][2];
        do
        {
            do
            {
                i++;
            } while ((d[i][2] < pivot) && i < end); //왜 여기서 seg fault가 날까...
            do
            {
                j--;
            } while ((d[j][2] > pivot) && j > start);
            if (i < j)
                swap(&d[i], &d[j], temp);
        } while (i < j);
        swap(&d[start], &d[j], temp);

        quickSort(d, start, j - 1);
        quickSort(d, j + 1, end);
    }
}

int main(int argc, char **argv)
{
    int n, m, count = 0;
    
    scanf("%d %d", &n, &m);

    int *parent = new int[n+1];
    int *childheight = new int[n];
    int *check = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        childheight[i] = 0;
        check[i] = 0;
    }
    parent[n]=n;//시발 문제 잘 읽자 ^^
    int **weight = new int *[m];
    for (int i = 0; i < m; i++)
    {
        weight[i] = new int[3];
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &weight[i][0], &weight[i][1], &weight[i][2]);
    }

    quickSort(weight, 0, m - 1);
    
    int first, second;
    for (int i = 0; i < m; i++)
    {
        first = checking(weight[i][0], parent);
        second = checking(weight[i][1], parent);
        if (first != second)
        {
            check[first] = 1;
            check[second] = 1;

            int height1 = childheight[first];
            int height2 = childheight[second];
            if (height1 > height2)
            {
                parent[second] = first;
            }
            else if (height1 < height2)
            {
                parent[first] = second;
            }
            else
            {
                parent[second] = first;
                childheight[first]++;
            }
            count += weight[i][2];
        }
    }
    
    printf("%d\n",count);
}

int checking(int i, int *parent)
{
    while (parent[i] != i)
    {
        i = parent[i];
    }
    return i;
}
