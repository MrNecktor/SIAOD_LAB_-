#include<cstdlib>
#include<ctime>
#include <iostream>
#include <clocale>

using namespace std;


/// быстр сорт

void qsortRec(int* mas, int size)
{
    int i = 0;
    int j = size - 1;

    int mid = mas[size / 2];

    do
    {
        
        while (mas[i] < mid)
        {
            i++;
        }
        
        while (mas[j] > mid)
        {
            j--;
        }
        
        if (i <= j)
        {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    
    if (j > 0)
    { 
        qsortRec(mas, j + 1);
    }
    if (i < size)
    {
        qsortRec(&mas[i], size - i);
    }
}


//// тировка перамид

void heapif(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

 
    if (l < n && arr[l] > arr[largest])
        largest = l;

    
    if (r < n && arr[r] > arr[largest])
        largest = r;

    
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        
        heapif(arr, n, largest);
    }
}


void heapSort(int arr[], int n)
{
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapif(arr, n, i);

   
    for (int i = n - 1; i >= 0; i--)
    {
        
        swap(arr[0], arr[i]);

        
        heapif(arr, i, 0);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int min = -250;
    int max = 250;
    int siz1 = 50;
    int siz2 = 50;
    int ans = 0;

    srand(static_cast<unsigned int>(time(0)));

    cout << "Введите длинну строки: ";
    cin >> siz1;
    cout << "Введите количество строк: ";
    cin >> siz2;

    int** arr = new int* [siz1];

    for (int i = 0; i < siz1; i++)
    {
        arr[i] = new int[siz2];
    }

    for (int i = 0; i < siz1; i++)
    {
        for (int j = 0; j < siz2; j++)
        {
            arr[i][j] = rand() % (max - min) + min;
        }
    }

    cout << "Оригтнальный массив: " << endl;

    for (int i = 0; i < siz1; i++)
    {
        for (int j = 0; j < siz2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Типы сортировки: " << endl 
        << "1 - Выбором " << endl 
        << "2 - Вставкой " << endl 
        << "3 - Обменом " << endl 
        << "4 - Шелла" << endl 
        << "5 - Быстрая сортировка "
        << endl << "6 - Пирамидальная" 
        << endl << "Выберети сортировку: ";
    cin >> ans;

    switch (ans)
    {
        //// Сортировка 1 типа (выбором)
        case 1:
        {


            int min_sort_1 = 0;
            int buf_sort_1 = 0;

            for (int i = 0; i < siz1; i++)
            {
                for (int j = 0; j < siz2; j++)
                {
                    min_sort_1 = j;
                    for (int k = j + 1; k < siz2; k++)
                    {
                        min_sort_1 = (arr[i][k] < arr[i][min_sort_1]) ? k : min_sort_1;
                    }

                    if (j != min_sort_1)
                    {
                        buf_sort_1 = arr[i][j];
                        arr[i][j] = arr[i][min_sort_1];
                        arr[i][min_sort_1] = buf_sort_1;
                    }
                }
            }

            cout << "Сортированный массив: " << endl;

            for (int i = 0; i < siz1; i++)
            {
                for (int j = 0; j < siz2; j++)
                {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }

        case 2:
        {
            //// сортировка 2 типа (вставкой)

            int buf_sort_2;
            int key_sort_2;
            int temp_sort_2;
            {
                for (int j = 0; j < siz2; j++)
                {
                    for (int i = 0; i < siz1 - 1; i++)
                    {
                        key_sort_2 = i + 1;
                        temp_sort_2 = arr[j][key_sort_2];
                        for (int k = i + 1; k > 0; k--)
                        {
                            if (temp_sort_2 < arr[j][k - 1])
                            {
                                arr[j][k] = arr[j][k - 1];
                                key_sort_2 = k - 1;
                            }
                        }
                        arr[j][key_sort_2] = temp_sort_2;
                    }
                }

                cout << "Сортированный массив: " << endl;

                for (int i = 0; i < siz1; i++)
                {
                    for (int j = 0; j < siz2; j++)
                    {
                        cout << arr[i][j] << " ";
                    }
                    cout << endl;
                }
            }
        }

        case 3:
        {

            //// сортировка 3 типа (обменом)

            int temp_sort_3;

            for (int k = 0; k < siz1; k++)
            {
                for (int i = 0; i < siz2 - 1; i++)
                {
                    for (int j = 0; j < siz2 - i - 1; j++)
                    {
                        if (arr[k][j] > arr[k][j + 1])
                        {
                            temp_sort_3 = arr[k][j];
                            arr[k][j] = arr[k][j + 1];
                            arr[k][j + 1] = temp_sort_3;
                        }
                    }
                }
            }

            cout << "Сортированный массив: " << endl;

            for (int i = 0; i < siz1; i++)
            {
                for (int j = 0; j < siz2; j++)
                {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }

        case 4:
        {
            //// сортировка 4 типа (шелла)

            int buf_sort_3;
            int temp_sort_3;
            for (int k = 0; k < siz1; k++)
            {
                buf_sort_3 = siz2;
                buf_sort_3 = buf_sort_3 / 2;
                while (buf_sort_3 > 0)
                {
                    for (int i = 0; i < siz2 - buf_sort_3; i++)
                    {
                        int j = i;
                        while (j >= 0 && arr[k][j] > arr[k][j + buf_sort_3])
                        {
                            temp_sort_3 = arr[k][j];
                            arr[k][j] = arr[k][j + buf_sort_3];
                            arr[k][j + buf_sort_3] = temp_sort_3;
                            j--;
                        }
                    }
                    buf_sort_3 = buf_sort_3 / 2;
                }     
            }

            cout << "Сортированный массив: " << endl;

            for (int i = 0; i < siz1; i++)
            {
                for (int j = 0; j < siz2; j++)
                {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }

        case 5:
        {

            //// сортировка 5 типа (быстрая сортировка)

            for (int k = 0; k < siz1; k++)
            {
                qsortRec(arr[k], siz2);
            }

            cout << "Сортированный массив: " << endl;

            for (int i = 0; i < siz1; i++)
            {
                for (int j = 0; j < siz2; j++)
                {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }

        
    }
}



