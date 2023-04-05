/*Написати функцію-шаблон, що переставляє перший максимальний та перший мінімальний елементи в масиві. 
Написати специфікацію функції-шаблон для типу char*.*/
#include <iostream>
#include <limits>
#include <algorithm>
#include <cstring>
using namespace std;

template <typename T> 
void MaxMin(int size, T A[], T& max, T& min)
{
    if(size == 0)
    {
        max = numeric_limits<T>::max();
        min = numeric_limits<T>::min();
        return;
    }

    max = min = A[0];

    for(int i = 1; i < size; i++)
    {
        if(A[i] > max)
        {
            max = A[i];
        }

        if(A[i] < min)
        {
            min = A[i];
        }
    }
}

template<>
void MaxMin<const char*>(int size, const char* A[], const char*& max, const char*& min)
{
    if(size == 0)
    {
        max = nullptr;
        min = nullptr;
        return;
    }

    max = A[0];
    min = A[0];

    for(int i = 0; i < size; i++)
    {
        if(strcmp(A[i], max) > -1)
        {
            max = A[i];
        }

        if(strcmp(A[i], min) < -1)
        {
            min = A[i];
        }
    }
}

int main()
{
    int arr[] = {6, 1, 1, 5, 8, 2, 8};
    int max, min;
    MaxMin(7, arr, max, min);
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;

    double arr1[] = {6.2, 1.5, 1.5, 5.1, 8.8, 2.9, 8.8};
    double max1, min1;
    MaxMin(7, arr1, max1, min1);
    cout << "Max: " << max1 << endl;
    cout << "Min: " << min1 << endl;

    const char *charArr[] = {"d", "a", "fis", "frog", "prick"};
    const char *max2, *min2;
    MaxMin(5, charArr, max2, min2);
    cout << "Max: " << max2 << endl;
    cout << "Min: " << min2 << endl;

    return 0;
}