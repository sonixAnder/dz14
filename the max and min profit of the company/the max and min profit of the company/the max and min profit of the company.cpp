#include "ext.h"

int main()
{
    setlocale(LC_ALL, "ru");
    vector<int> profit(12);

    for (int i = 0; i < 12; i++) 
    {
        cout << "Введите прибыль за " << i + 1 << "-й месяц: ";
        cin >> profit[i];
    }

    int start, end;
    cout << "Введите номер начального месяца диапазона: ";
    cin >> start;
    cout << "Введите номер конечного месяца диапазона: ";
    cin >> end;

    int maxProfit = profit[start - 1];
    int minProfit = profit[start - 1];
    int maxMonth = start;
    int minMonth = start;

    for (int i = start; i <= end; i++) 
    {
        if (profit[i - 1] > maxProfit) 
        {
            maxProfit = profit[i - 1];
            maxMonth = i;
        }
        if (profit[i - 1] < minProfit) 
        {
            minProfit = profit[i - 1];
            minMonth = i;
        }
    }

    cout << "Месяц с максимальной прибылью: " << maxMonth << endl;
    cout << "Месяц с минимальной прибылью: " << minMonth << endl;

    return 0;
}