

#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstring>

// Задание 1
void initializationmass(double* mass, int num)
{
	for (int i = 0; i < num; ++i)
	{
		mass[i] = (double)(rand() % 6);
	}
}
double processArray(double mass[], int num)
{
	double min[6] = { 0.0 };
	for (int i = 0; i < num; ++i)
	{
		if (mass[i] == 0) { min[0] = min[0] + 1; }
		if (mass[i] == 1) { min[1] = min[1] + 1; }
		if (mass[i] == 2) { min[2] = min[2] + 1; }
		if (mass[i] == 3) { min[3] = min[3] + 1; }
		if (mass[i] == 4) { min[4] = min[4] + 1; }
		if (mass[i] == 5) { min[5] = min[5] + 1; }
	}
	double lo = 0;
	for (int i = 0; i < 6; ++i)
	{
		if (min[i] < min[i + 1])
		{
			lo = min[i];
		}
	}
	double lo1 = 100;
	for (int i = 0; i < 6; ++i)
	{
		if (min[i] == lo && i < lo1)
		{
			lo1 = i;
		}
	}

	double tmp = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = (num - 1); j >= (i + 1); j--)
		{
			if (mass[j] < mass[j - 1])
			{
				tmp = mass[j];
				mass[j] = mass[j - 1];
				mass[j - 1] = tmp;
			}
		}
	}
	return lo1;
}

void printArray(double mass[], int num)
{
	std::cout << std::endl;
	for ( int i = 0; i < num; ++i)
	{
		std::cout << mass[i] << " ";
	}
}

// Задание 2
void initializeArray(double** mass1, int str, int stob)
{
	for (int count_row = 0; count_row < str; count_row++)
		for (int count_column = 0; count_column < stob; count_column++)
			mass1[count_row][count_column] = sin(count_row - count_column) + cos(count_row + count_column);
}

void printArray2D(double** mass1, int str, int stob)
{
	for (int count_row = 0; count_row < str; count_row++)
	{
		for (int count_column = 0; count_column < stob; count_column++)
			std::cout << std::setw(10) << std::setprecision(10) << mass1[count_row][count_column] << "     ";
		std::cout << std::endl;
	}
}

double* makeArray1D(double** mass, double* rez, int stob, int str)
{
	int longg = 0;
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stob; j++)
		{
			rez[longg] = mass[i][j];
			longg = ++longg;
		}
	}
	return rez;
}

void printArray1D(double* mass, int stob)
{
	for ( int i = 0; i < stob; i++)
	{
		std::cout << i[mass] << " ";
	}
	std::cout << std::endl;
}
// Задание 3

char* standard_result (char* rez)
{
	char str[50] = "Первая часть ";
	char str2[50] = "Вторая часть";
	strcat_s(rez, sizeof str, "Начало ");
	strcat_s(rez, sizeof str, str);
	strcat_s(rez, sizeof str, str2);
	return rez;
}

char* reverseChar(char* s1, char* s2)
{
	int N = 0;
	char* q = s1, * w = s2;
	for (; *q; q++) N++; q = s1;
	for (; *w; w++) N++; w = s2;
	char* dest = (char*)malloc(N + 1);
	char *iter = dest;

	// Копируем s1 и s2
	for (; *q; q++, iter++) *iter = *q;
	for (; *w; w++, iter++) *iter = *w;

	*iter = '\0';
	return dest;
}



int main()
{
	setlocale(LC_CTYPE, "rus");
	metka1:
	std::cout << "Введите номер задания, или 4 выход" << std::endl ;
	int z;
	std::cin >> z;
	if (z==1)
	{ 
		const int num = 20;
		double mass[num] = { 0.0 };
		srand(0);

		initializationmass(mass,num);
		printArray(mass, num);

		double result = processArray(mass, num);
		printArray(mass, num);
		printf("min: %g\n\n", result);
		goto metka1;
	}
	if (z == 2)
	{
		const int longg = 15;
		const int str = 5;
		const int stolb = 3;
		double** mass1 = new double* [str];
		for (int count = 0; count < str; count++)
			mass1[count] = new double[stolb];
		initializeArray(mass1, str, stolb);
		printArray2D(mass1, str, stolb);
		double* rez = new double[longg];
		rez = makeArray1D(mass1, rez, stolb, str);
		printArray1D(rez, longg);
		goto metka1;;
	}
	if (z == 3)
	{
		char str1[15] = "(Первая часть)";
		char str2[15] = "(Вторая часть)";
		char rez[100] = "";
		char* standard = standard_result(rez);
		std::cout << standard << std::endl;
		char rez1[100] = "(Новое начало) ";
		char* my_result = reverseChar(rez1, str1);
		std::cout << "Мое " << my_result;
		goto metka1;
	}
	system("pause");
	return 0;
}