/*
Задание из учебника Дейтела издание 4 под №17.13 стр.1030-1031.
>>Генератор слов для телефонного номера
Стандартный набор кнопок телефона содержит цифры от 0 до 9. Каждая цифра от 2 до 9 имеет
связанные с ней три буквы, что отражено в следующей таблице :
2	ABC
3	DEF
4	GHI
5	JKL
6	MNO
7	PRS
8	TUV
9	XYZ
Напишите программу на С, которая для данного семизначного числа записывает
в файл все возможные слова из семи букв, соответствующие этому номеру.
Существует 2187 (три в седьмой степени) таких слов.Избегайте телефонных номеров
с цифрами 0 и 1.


F1T1L: По хорошему выводить нужно в бинарник для скорости.

*/


#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <windows.h>
#include <iomanip>

using namespace std;

//массив букв каждой клавиши
char	two[3]		= { 'A','B','C' },
		tree[3]		= { 'D','E','F' },
		four[3]		= { 'G','H','I' },
		five[3]		= { 'J','K','L' },
		six[3]		= { 'M','N','O' },
		seven[3]	= { 'P','R','S' },
		eight[3]	= { 'T','U','V' },
		nine[3]		= { 'X','Y','Z' };

int check();
char* convert();

// возвращаем адрес массива по его номеру
char* convert(int c) {
	switch (c) {
	case 2: return two;			break;
	case 3: return tree;		break;
	case 4: return four;		break;
	case 5: return five;		break;
	case 6: return six;			break;
	case 7: return seven;		break;
	case 8: return eight;		break;
	case 9: return nine;		break;
	}
}

int check(int number) {
	int p = 10;
	for (int j = 0; j < 7; j++) {
		// Проверяем число на наличие 0 и 1 путем деления на 10
		if ((number% p == 0) || (number % p == 1)) {
			break;  // Если встречает 0 или 1 - прерывает цикл и возвращает число какое-то.
		}
		number = number / p;
	}
	return number;
}

void main()
{
//Для красоты

//////////////////////////////////
	system("COLOR F5");			//
	setlocale(0, "");           //
//////////////////////////////////
	// Новый файлик
	fstream Data("Data.txt", ios::trunc | ios::out | ios::in | ios::binary);
	fstream Names1("Names.txt", ios::trunc | ios::out); //Создаем файлик для набора букв.
	Names1.close();
	if (!Data)
	{
		cerr << "Не могу создать файл Data.txt" << endl;
		system("PAUSE");
		exit(1);
	}
	cout << endl << endl << endl<< "\t Запись чисел в файл, ждите..." << endl << endl;
	int n; 
	for (n = 2222222; n < 9999999 + 1; n++) {
	//проверка на наличие в номере 0 или 1. (номера с этими цифрами нам не нужны)
	if (!check(n)) {			//если возращает число(любое!=0) то пропускаем 
		Data.write((char*)&n, sizeof(n));
	}
	else {
		continue;
	}
}	
cout << endl << "========================================================================" << endl;
cout << endl << endl << endl << "\tCчитываем номер из файла и генерируем буквы..." << endl << endl;
fstream Names("Names.txt", ios::out);
if (!Names)
{
	cerr << "Не могу создать файл Names.txt" << endl;
	system("PAUSE");
	exit(1);
}
Data.seekg(0); // Начало файла.
while (!Data.eof())
{							// Извлекаем число из файла.
	Data.read((char*)&n, sizeof(n));
	//cout << "Обрабатываемое число: " << n<< endl;
	int d = n;
//Для ускорения процесса, указатели и предварительные вычисления идут отдельно.
	char *p_a, *p_b, *p_c, *p_d, *p_e, *p_f, *p_i;
	int p_aA = d / 1000000,
		p_bB = (d / 100000) % 10,
		p_cC = (d / 10000) % 10,
		p_dD = (d / 1000) % 10,
		p_eE = (d / 100) % 10,
		p_fF = (d / 10) % 10,
		p_iI = d % 10;

	
//Бежим за огнетушителем,ибо Адская карусель циклов сожжет комп ваш :)
	for (int a = 0; a < 3; a++) { //1
		p_a = convert(p_aA);
		for (int b = 0; b < 3; b++) { //2
			p_b = convert(p_bB);
			for (int c = 0; c < 3; c++) { //3
				p_c = convert(p_cC);
				for (int d = 0; d < 3; d++) { //4
					p_d = convert(p_dD);
					for (int e = 0; e < 3; e++) { //5
						p_e = convert(p_eE);
						for (int f = 0; f < 3; f++) { //6
							p_f = convert(p_fF);
							for (int i = 0; i < 3; i++) {//7
								p_i = convert(p_iI);
Names << p_a[a] << p_b[b] << p_c[c] << p_d[d] << p_e[e] << p_f[f] << p_i[i] << "\t";
							}

							
						}
						

					}

					
				}
				

			}
			

		}

		
	}
	
	
}

system("PAUSE");
}
