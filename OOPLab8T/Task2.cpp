/*Написати функцію-шаблон функцію впорядкування методом «Вставки». 
Написати специфікацію функції-шаблон для типу char*.*/
#include <iostream>
#include <cstring>

using namespace std;

template<typename T>
void InsertionSort(int size, T A[])
{
    T buff = 0;
    int i, j;

    for(i = 1; i < size; i++)
    {
        buff = A[i];
        for(j = i - 1; j >= 0 && A[j] > buff; j--)
            A[j + 1] = A[j]; 
        
        A[j + 1] = buff;
    }
}

template<>
void InsertionSort<const char*>(int size, const char* A[])
{
    const char* buff = 0;
    int i, j;

    for(i = 1; i < size; i++)
    {
        buff = A[i];
        for(j = i - 1; j >= 0 && strcmp(A[j], buff) > -1; j--)
            A[j + 1] = A[j];

        A[j + 1] = buff;
    }
}


int main()
{
    int arr[] = {2, 8, 9, 1, 5};
    int size = 5;
    InsertionSort(size, arr);

    cout << "Sorted(int):" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    double arr1[] = {1.2, 3.4, 3.2, 4.7, 2.6};
    InsertionSort(size, arr1);

    cout << "Sorted(double):" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    const char* arr2[] = {"frog", "bird", "snail", "monkey", "turtle"};
    const int size2 = sizeof(arr2) / sizeof(arr2[0]);
    InsertionSort<const char*>(size2, arr2);

    cout << "Sorted(char):" << endl;
    for (int i = 0; i < size2; i++)
    {
        cout << arr2[i] << " ";
    }

    return 0;
}