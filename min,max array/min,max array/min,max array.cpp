#include "ext.h"
void arr();

int main()
{
    setlocale(LC_ALL, "ru");
    arr();
    return 0;
}

void arr()
{
    const int N = 10;
    int mass[N], max, min;
    srand(time(0));

    cout << "Элементы: |";
    for (int i = 0; i < N; i++)
    {
        mass[i] = rand() % 99;
        cout << mass[i] << "|";
    }
    cout << endl;
    cout << "Ищем мин. и макс. элемент в массиве..." << endl;
    Sleep(5000);
    cout << endl;

    max = mass[0];
    min = mass[0];

    for (int i = 1; i < N; i++)
    {
        if (max < mass[i]) max = mass[i];
        if (min > mass[i]) min = mass[i];
    }

    cout << "Минимальный элемент: " << min << endl;
    cout << "максимальный элемент: " << max << endl;
}