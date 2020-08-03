#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int> > pos;
/*void insertionSort(int left, int right)
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
}*/
int compare(int small, int big)
{
    //printf("small %d big %d\n",small,big);
    if (pos[small].second > pos[big].second)
    {
        return 0;
    }
    else if (pos[small].second < pos[big].second)
    {
        return 1;
    }
    else{
        if( pos[small].first < pos[big].first ){
            return 1;
        }
        else{
            return 0;
        }
    }
}
void quickSort(int start, int end)
{

    /*if (end - start < 50)
    {
        insertionSort(start, end);
        return;
    }*/
    if (start < end)
    {
        int i = start;
        int j = end + 1;
        int pivot = start;
        do
        {
            do
            {
                i++;
            } while ((i < end + 1) && compare(i, start));
            do
            {
                j--;
            } while ((j > -1) && compare(start, j));
            if (i < j)
            {
                pos[i].swap(pos[j]);
            }
        } while (i < j);
        pos[start].swap(pos[j]);
        //swap(pos[start], pos[j]);
        quickSort(start, j - 1);
        quickSort(j + 1, end);
    }
}

int main()
{
    scanf("%d", &n);
    int a, b;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        //printf("%d %d\n",a,b);
        pos.push_back(make_pair(a, b));
    }
    quickSort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", pos[i].first, pos[i].second);
    }
}
