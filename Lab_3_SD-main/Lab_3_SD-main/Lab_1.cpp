#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>

void printArrayForTask1(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != 0)
		{
			printf("%d%c",arr[i],' ');
		}
		else
		{
			continue;
		}
	}
	printf("\n");
}

int processArray(int arr[], int *freqelem, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = 1 + rand() % 10; //генерируем случайное число, остаток от деления на n будет число <n, включая 0 => 1+rand дает сдвиг диапозона
	}

	printArrayForTask1(arr, size);

	for (int i = 0; i < size - 1; i++) //сортировка выбором
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		int buf = arr[min];
		arr[min] = arr[i];
		arr[i] = buf;
	}

	int mod = 0;

	for (int i = 0; i < size; i++) //эл-ты, встречающиеся более 2 раз
	{
		int count = 0;

		for (int j = 0; j < size; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
		}
		if (mod < count)
		{
			mod = count;
		}
		if (i != 0 && i != size - 1) //проверка на выход за рамки массива
		{
			if (arr[i - 1] != arr[i] && arr[i] == arr[i + 1])
			{
				freqelem[i] = arr[i];
			}
		}
	}

	for (int i = 0; i < size; i++) //мода ряда
	{
		int count = 0;
		for (int j = 0; j < size; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;

				if (count == mod)
				{
					return arr[i];
				}
			}
		}
	}
}

void initializeArray(double** arr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			*(*(arr + i) + j) = sin(i - j) + cos(i + j);
		}
	}
}

double* arrayTwoToOne(double** arr, int n, int m)
{
	int size = n * m;
	double* arr1D = new double [size];
	int count = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < m; j++)
		{
			*(arr1D + count) = *(*(arr + i) + j); 
			count++;
		}
	}
	return arr1D;
}

void deleteArray(double** arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void printArray2D(double** arr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << std::setw(14)<< *(*(arr + i) + j);
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void printArray1D(double* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << *(arr + i) << " " << std::setw(14);
	}
	std::cout << "\n";
}

char* concatWithParam(char* dest, const char* src, int maxlen) //Функция приписывает maxlen символов строки src к строке dest
{
	for (int i = strlen(dest), k = 0; k < maxlen; i++, k++)
	{
		dest[i] = src[k];
	}
	return dest;
}

int main()
{
	/* Вариант 4
	Объявить массив из n=20 целых чисел, проинициализировать нулями. Функция
	process_array() должна заполнить массив случайными числами от 1 до 10, вычислить
	и вернуть наиболее часто встречающееся значение в массиве (если таких несколько,
	вернуть наименьшее) и сформировать выходной массив из всех элементов, которые
	встречаются как минимум 2 раза во входном массиве. Вывести на экран массивы. */
	printf("For Lav_3 SD\n");
	printf("Task_1\n");											
	int num[20] = {};
	int freqelem[20] = {};
	const int size = sizeof(num) / sizeof(num[0]);
	int x = processArray(num, freqelem, size);
	printf("FrequentElements: ");
	printArrayForTask1(freqelem, size);
	printf("MostFrequentElement: %d\n", x);

	/* Преобразование: 2D → 1D. Двумерный массив 5х3 вещественных чисел необходимо
	выложить в один ряд по элементам слева направо и снизу вверх.
	Инициализация: заполнить массив числами x[i][j] = sin(i–j) + cos(i+j).
	Вывод на экран: на каждый элемент массива отвести 14 позиций. */

	std::cout << "Task_2" << std::endl;
	const int n = 5;
	const int m = 3;
	const int length = 15;
	double** array = new double* [5]; //динамический 2д массив (массив указателей на массивы)
	for (int i = 0; i < 5; i++)
	{
		*(array + i) = new double[3];
	}
	initializeArray(array, n, m);
	printArray2D(array, n, m);
	double* exitarray = arrayTwoToOne(array, n, m);
	deleteArray(array, n);
	printArray1D(exitarray, length);
	delete[] exitarray;

	/* Функция strncat.
	Формат char* strncat(char* dest, const char* src, size_t maxlen).
	Функция приписывает maxlen символов строки src к строке dest. */

	printf("Task_3\n");
	char secondstring[] = " and i add more ";
	char firststring[255] = "This is first string";
	int len = 10;
	printf("1: %s\n", firststring);
	printf("2: %s\n", secondstring);
	printf("Number of characters: %d\n", len);
	char* standardresult = strncat(firststring, secondstring, len);
	printf("Standard: %s\n", standardresult);
	char mysecondstring[] = " and i add more ";
	char myfirststring[255] = "This is first string";
	char* myresult = concatWithParam(myfirststring, mysecondstring, len);
	printf("My version: %s\n", myresult);
	return 0;
	/*Здесь распологаются изменения для лабораторной работы №3 по ТРПО*/
}

