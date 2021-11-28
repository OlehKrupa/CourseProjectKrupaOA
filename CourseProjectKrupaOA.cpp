#include <fstream>
#include <iostream>

using namespace std;

void shortWay(int** a, int size)
{
	for (int k = 0; k < size; k++)
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				if (a[i][j] > a[i][k] + a[k][j])
					a[i][j] = a[i][k] + a[k][j];
}

void show(int** a, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}

void keyboardMatrix(int** a, int& size)
{
	cout << "Количество вершин графа: ";
	while (!(cin >> size) || size < 2 || size > 255)
	{
		cin.clear();
		cin.ignore(100500, '\n');
		cout << "Неправильный размер графа (диапазон 2 - 255), новое значение: ";
	}

	cout << "Сформируйте матрицу смежности" << endl;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			cout << "a[" << i << "][" << j << "]: ";
			while (!(cin >> a[i][j]) || a[i][j] < 0)
			{
				cin.clear();
				cin.ignore(100500, '\n');
				cout << "Неправильный вес ребра, (целое положительное число)" << endl;
				cout << "a[" << i << "][" << j << "]: ";
			}
		}
}

void fileMatrix(int** a, int& size)
{
	fstream file;
	file.open("input.txt", ios::in);
	file >> size;

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			file >> a[i][j];
		}
}

void rndMatrix(int** a, int& size)
{
	cout << "Количество вершин графа: ";
	while (!(cin >> size) || size < 1 || size>255)
	{
		cin.clear();
		cin.ignore(100500, '\n');
		cout << "Неправильный размер графа (диапазон 2 - 255), новое значение: ";
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (a[i][j] == a[j][i])
			{
				a[i][j] = rand() % 10 + 1;
				a[j][i] = a[i][j];
				if (i == j) a[i][j] = 0;
			}
		}
	}
}

void twoPointShortWay(int** a)
{
	int start = 0, finish = 0, way = 0;
	cout << "Введите начальную и конечную точку, между которыми нужно найти кратчайший путь" << endl;

	while (!(cin >> start) || start < 0 || start>255)
	{
		cin.clear();
		cin.ignore(100500, '\n');
		cout << "Неправильная начальная точка (диапазон 0 - 255), новое значение: ";
	}

	while (!(cin >> finish) || finish < 0 || finish>255 || (start == finish))
	{
		cin.clear();
		cin.ignore(100500, '\n');
		if (start == finish)
			cout << "Начальная и конечная точка совпадают, введите новую конечную точку: ";
		else
			cout << "Неправильная конечная точка (диапазон 0 - 255), новое значение: ";
	}

	start--; finish--;
	way = a[start][finish];
	start++; finish++;
	cout << "Кратчайшее расстояние между точками " << start << "&" << finish << ": " << way << endl;
}

void main()
{
	system("color F0");
	setlocale(LC_ALL, "Ru");
	int size = 0; //размер масива
	//Выделение места под граф с максимум 255 вершинами
	int** a = new int* [255];
	for (int i = 0; i < 255; i++)
		a[i] = new int[255];

	bool t = true;
	int sw = 0;

	while (t)
	{
		cout << "1 - Клавиатура, 2 - Файл, 3 - Генерация, 4 - Массив путей, 5 - Расстояние между точками, 0 - Вырубай!" << endl;
		while (!(cin >> sw) || sw < 0 || sw>6)
		{
			cin.clear();
			cin.ignore(100500, '\n');
			cout << "Ошибка! Выберите пункт меню (0 - 5): ";
		}

		switch (sw)
		{
		case 0:
			cout << "Ну пока :(" << endl;
			t = false;
			break;
		case 1:
			keyboardMatrix(a, size);
			shortWay(a, size);
			break;
		case 2:
			fileMatrix(a, size);
			shortWay(a, size);
			break;
		case 3:
			rndMatrix(a, size);
			shortWay(a, size);
			break;
		case 4:
			show(a, size);
			break;
		case 5:
			twoPointShortWay(a);
			break;
		}
	}
	system("pause");
}