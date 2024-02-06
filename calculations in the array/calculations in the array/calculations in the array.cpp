#include <iostream>
#include <limits>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "ru");
    int N;

    std::cout << "Введите размер массива: ";
    std::cin >> N;

    double* arr = new double[N];

    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < N; i++) 
    {
        cin >> arr[i];
    }

    double sumOfNegatives = 0;
    double productBetweenMinMax = 1;
    double productOfEvenIndex = 1;
    double sumBetweenFirstLastNegatives = 0;
    //------------------------------------------------------
    //предоставляет важную информацию о свойствах различных типов, таких как минимальные и максимальные значения.
    double minElement = numeric_limits<double>::max(); 
    double maxElement = numeric_limits<double>::min();
    //------------------------------------------------------
    int minIndex = -1;
    int maxIndex = -1;
    int firstNegativeIndex = -1;
    int lastNegativeIndex = -1;

    for (int i = 0; i < N; i++) 
    {
        if (arr[i] < 0)
        {
            sumOfNegatives += arr[i];
        }

        if (arr[i] < minElement)
        {
            minElement = arr[i];
            minIndex = i;
        }

        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
            maxIndex = i;
        }

        if (arr[i] < 0 && firstNegativeIndex == -1)
        {
            firstNegativeIndex = i;
        }

        if (arr[i] < 0)
        {
            lastNegativeIndex = i;
        }

        if (i % 2 == 0) 
        {
            productOfEvenIndex *= arr[i];
        }
    }

    if (minIndex < maxIndex) 
    {
        for (int i = minIndex + 1; i < maxIndex; i++) 
        {
            productBetweenMinMax *= arr[i];
        }
    }
    else 
    {
        for (int i = maxIndex + 1; i < minIndex; i++) 
        {
            productBetweenMinMax *= arr[i];
        }
    }

    if (firstNegativeIndex != -1 && lastNegativeIndex != -1) 
    {
        if (firstNegativeIndex < lastNegativeIndex) 
        {
            for (int i = firstNegativeIndex + 1; i < lastNegativeIndex; i++) 
            {
                sumBetweenFirstLastNegatives += arr[i];
            }
        }
        else 
        {
            for (int i = lastNegativeIndex + 1; i < firstNegativeIndex; i++) 
            {
                sumBetweenFirstLastNegatives += arr[i];
            }
        }
    }

    cout << "Сумма отрицательных элементов: " << sumOfNegatives << endl;
    cout << "Произведение элементов, находящихся между min и max элементами: " << productBetweenMinMax << endl;
    cout << "Произведение элементов с четными номерами: " << productOfEvenIndex << endl;
    cout << "Сумма элементов, находящихся между первым и последним отрицательными элементами: " << sumBetweenFirstLastNegatives << std::endl;

    delete[] arr; //освобождаем память

    return 0;
}
