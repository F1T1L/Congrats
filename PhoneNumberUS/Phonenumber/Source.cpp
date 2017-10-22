/*
������� �� �������� ������� ������� 4 ��� �17.13 ���.1030-1031.
>>��������� ���� ��� ����������� ������
����������� ����� ������ �������� �������� ����� �� 0 �� 9. ������ ����� �� 2 �� 9 �����
��������� � ��� ��� �����, ��� �������� � ��������� ������� :
2	ABC
3	DEF
4	GHI
5	JKL
6	MNO
7	PRS
8	TUV
9	XYZ
�������� ��������� �� �, ������� ��� ������� ������������ ����� ����������
� ���� ��� ��������� ����� �� ���� ����, ��������������� ����� ������.
���������� 2187 (��� � ������� �������) ����� ����.��������� ���������� �������
� ������� 0 � 1.


F1T1L: �� �������� �������� ����� � �������� ��� ��������.

*/


#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <windows.h>
#include <iomanip>

using namespace std;

//������ ���� ������ �������
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

// ���������� ����� ������� �� ��� ������
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
		// ��������� ����� �� ������� 0 � 1 ����� ������� �� 10
		if ((number% p == 0) || (number % p == 1)) {
			break;  // ���� ��������� 0 ��� 1 - ��������� ���� � ���������� ����� �����-��.
		}
		number = number / p;
	}
	return number;
}

void main()
{
//��� �������

//////////////////////////////////
	system("COLOR F5");			//
	setlocale(0, "");           //
//////////////////////////////////
	// ����� ������
	fstream Data("Data.txt", ios::trunc | ios::out | ios::in | ios::binary);
	fstream Names1("Names.txt", ios::trunc | ios::out); //������� ������ ��� ������ ����.
	Names1.close();
	if (!Data)
	{
		cerr << "�� ���� ������� ���� Data.txt" << endl;
		system("PAUSE");
		exit(1);
	}
	cout << endl << endl << endl<< "\t ������ ����� � ����, �����..." << endl << endl;
	int n; 
	for (n = 2222222; n < 9999999 + 1; n++) {
	//�������� �� ������� � ������ 0 ��� 1. (������ � ����� ������� ��� �� �����)
	if (!check(n)) {			//���� ��������� �����(�����!=0) �� ���������� 
		Data.write((char*)&n, sizeof(n));
	}
	else {
		continue;
	}
}	
cout << endl << "========================================================================" << endl;
cout << endl << endl << endl << "\tC�������� ����� �� ����� � ���������� �����..." << endl << endl;
fstream Names("Names.txt", ios::out);
if (!Names)
{
	cerr << "�� ���� ������� ���� Names.txt" << endl;
	system("PAUSE");
	exit(1);
}
Data.seekg(0); // ������ �����.
while (!Data.eof())
{							// ��������� ����� �� �����.
	Data.read((char*)&n, sizeof(n));
	//cout << "�������������� �����: " << n<< endl;
	int d = n;
//��� ��������� ��������, ��������� � ��������������� ���������� ���� ��������.
	char *p_a, *p_b, *p_c, *p_d, *p_e, *p_f, *p_i;
	int p_aA = d / 1000000,
		p_bB = (d / 100000) % 10,
		p_cC = (d / 10000) % 10,
		p_dD = (d / 1000) % 10,
		p_eE = (d / 100) % 10,
		p_fF = (d / 10) % 10,
		p_iI = d % 10;

	
//����� �� �������������,��� ������ �������� ������ ������ ���� ��� :)
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
