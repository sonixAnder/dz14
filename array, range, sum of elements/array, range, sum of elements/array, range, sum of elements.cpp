#include "ext.h"

int main() 
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    int* arr = new int[size];

    int rangeStart, rangeEnd;
    cout << "Введите диапазон значений (пример: 1 10): ";
    cin >> rangeStart >> rangeEnd;

    for (int i = 0; i < size; i++) 
    {
        arr[i] = rand() % (rangeEnd - rangeStart + 1) + rangeStart;
    }

    int threshold;
    cout << "Введите пороговое значение: ";
    cin >> threshold;

    int sum = 0;

    for (int i = 0; i < size; i++) 
    {
        if (arr[i] < threshold) 
        {
            sum += arr[i];
        }
    }

    cout << "Сумма элементов, меньших " << threshold << ": " << sum << endl;

    delete[] arr; //освобождение памяти

    return 0;
}