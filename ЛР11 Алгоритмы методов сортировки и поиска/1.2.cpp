#include <iostream>                           
#include <string.h>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "1.1.h"
#define path "dataBase.txt"
using namespace std;
using namespace std::chrono;

struct student
{
	char fam[20], im[20], otch[20];
	char inc[7];
	int bith;
	int ya;
	int marks[3];
};

static student* mas, t;
static int* a; 
static int* a1;

//�������� ������ ��������� �� �����
extern int loadFromFile()
{
	int k;
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "���� ��� ��������� �� ���������� ��� �� ����� ���� ������!\n";
		cout << "__________________________________" << endl << endl << endl;
			return 0;
	}
	else
	{
		fin >> k;

		//��������� ������
		if (!(mas = (student*)malloc(k * sizeof(student))))
		{
			cout << "������������ ������!";
			fin.close();
			return -1;
		}

		//���������� ������
		for (register int i = 0; i < k; i++)
		{
			fin >> mas[i].fam >> mas[i].im >> mas[i].otch >> mas[i].inc
				>> mas[i].bith >> mas[i].ya
				>> mas[i].marks[0] >> mas[i].marks[1] >> mas[i].marks[2];
		}
		fin.close();
		cout << "������ ��� ��������� ������� ��������� �� �����.\n";
		cout << "__________________________________" << endl << endl << endl;
		return k;
	}
}


//���������� ������ ��������� � ����
extern void saveToFile(int sch)
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "������ ���������� ������ ��������� � ����!" << endl;
		return;
	}
	else
	{
		fout << sch << "\n";
		for (register int i = 0; i < sch; i++)
		{
			fout << mas[i].fam << " " << mas[i].im << " " << mas[i].otch << " " << mas[i].inc << " "
				<< mas[i].bith << " " << mas[i].ya << " "
				<< mas[i].marks[0] << " " << mas[i].marks[1] << " " << mas[i].marks[2] << "\n";
		}
	}
	fout.close();
	cout << "\n������ ��������� ������� ��������� � ����!\n";
	cout << "__________________________________" << endl;
	free(mas);
}


//���������� �������
extern void saveToFileMas(int count)
{
	ofstream fout;
	fout.open("mas.txt");
	if (!fout.is_open())
	{
		cout << "������ ���������� ������ ������� � ����!" << endl;
		return;
	}
	else
	{
		fout << count << "\n";
		for (register int i = 0; i < count; i++)
		{
			fout << *(a1 + i) << " ";
		}
	}
	fout.close();
	cout << "\n������ ������� ������� ��������� � ����!\n";
	cout << "�����...\n";
	cout << "__________________________________" << endl;
	delete[] a;
	delete[] a1;
}


//��������� �������
extern int generate_array()
{
	register int n;
	cout << "������� ������ ������������� ������� (����� ���� ������ 10): ";
	cin >> n;
	while (n<=10 || cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "������ �����: ������ ������������� ������� ������ ���� ����� ������������� ������ ������ 10. ��������� ����: ";
		cin >> n;
	}

	a = new int[n];
	a1 = new int[n];
	srand(time(NULL));
	for (register int i = 0; i < n; i++)
		*(a+i) = rand();
	cout << "__________________________________" << endl << endl << endl;

	return n;
}


//����������� �������
extern int regenerate_array()
{
	register int n;
	cout << "\n������� ������ ��������������� ������� (����� ���� ������ 10): ";
	cin >> n;
	while (n <= 10 || cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "������ �����: ������ ��������������� ������� ������ ���� ����� ������������� ������ ������ 10. ��������� ����: ";
		cin >> n;
	}
	delete[] a;
	delete[] a1;
	a = new int[n];
	a1 = new int[n];
	srand(time(NULL));
	for (register int i = 0; i < n; i++)
		*(a + i) = rand();
	cout << "__________________________________" << endl << endl << endl;

	return n;
}


//������������
 extern void swap(int *x, int *y)
{
	int t;
	t = *x;    	*x = *y;     *y = t;
}


 //����������� ������� 
 extern void cop(int count)
 {
	 for (register int i = 0; i < count; i++)
		 *(a1 + i) = *(a + i);
 }


//����� ������ 10 ���������
 extern void out()
 {
	 for (register int i = 0; i < 10; i++)
		 cout << *(a1 + i) << " ";
	 cout << endl;
	 cout << "__________________________________" << endl << endl << endl;
 }


 //���������� ���������
 extern void bubble_sort(int count)
 {
	 register int i, j;
	 cop(count);
	 auto start = high_resolution_clock::now();

	 for (i = 0; i < count; i++)
		 for (j = count - 1; j > i; j--)
			 if (*(a1 + j - 1) > *(a1 + j))
				 swap((a1 + j - 1), (a1 + j));

	 auto end = high_resolution_clock::now();
	 duration<double> interval = end - start;
	 cout << "\n����� ����������� �� ���������� ������� ��������: " << fixed << setprecision(2) << interval.count() << " ������" << endl;
	 cout << "������ 10 ��������� ���������������� �������:" << endl;
	 out();
 }


 //���������� �������
 extern void min_sort(int count)
 {
	 register int k, i, j;
	 cop(count);
	 auto start = high_resolution_clock::now();

	 for (i = 0; i < count - 1; i++)
	 {
		 k = i;
		 for (j = i + 1; j < count; j++)   
			 if (*(a1 + j) < *(a1 + k))
			 {                 
				 k = j; 			 
			 }
		 swap((a1 + i), (a1 + k));
	 }

	 auto end = high_resolution_clock::now();
	 duration<double> interval = end - start;
	 cout << "\n����� ����������� �� ���������� ������� ������: " << fixed << setprecision(2) << interval.count() << " ������" << endl;
	 cout << "������ 10 ��������� ���������������� �������:" << endl;
	 out();
 }


 // //���������� ��������
 extern void insert_sort(int count)
 {
	 register int i, j;
	 cop(count);
	 auto start = high_resolution_clock::now();

	 for (i = 1; i <= count - 1; i++)
	 {
		 j = i;
		 while (*(a1 + j) < *(a1 + j - 1) && j >= 1)
		 {
			 swap((a1 + j), (a1 + j - 1));
			 j--;
		 }
	 }

	 auto end = high_resolution_clock::now();
	 duration<double> interval = end - start;
	 cout << "\n����� ����������� �� ���������� ������� �������: " << fixed << setprecision(2) << interval.count() << " ������" << endl;
	 cout << "������ 10 ��������� ���������������� �������:" << endl;
	 out();
 }


 //���������� �����
 extern void shell_sort(int count)
 {
	 register int i, j, gap, sorted;
	 cop(count);
	 auto start = high_resolution_clock::now();

	 for (gap = count / 2; gap > 0; gap /= 2)
		 do {
			 sorted = 0;
			 for (i = 0, j = gap; j < count; i++, j++)
				 if (*(a1 + i) > *(a1 + j))
				 {
					 swap((a1 + i), (a1 + j));
					 sorted = 1;
				 }
		 } while (sorted);

	 auto end = high_resolution_clock::now();
	 duration<double> interval = end - start;
	 cout << "\n����� ����������� �� ���������� ������� �����: " << fixed << setprecision(2) << interval.count() << " ������" << endl;
	 cout << "������ 10 ��������� ���������������� �������:" << endl;
	 out();
 }
 

 //������ �����
 extern void hoare_sort_t(int count, int l, int r)
 {
	 cop(count);
	 auto start = high_resolution_clock::now();
	 hoare_sort(l, r);
	 auto end = high_resolution_clock::now();
	 duration<double> interval = end - start;
	 cout << "\n����� ����������� �� ���������� ������� �����: " << fixed << setprecision(2) << interval.count() << " ������" << endl;
	 cout << "������ 10 ��������� ���������������� �������:" << endl;
	 out();
 }


 //���������� �����
 extern void hoare_sort(int l, int r)
 {
	 register int i, j, sr;

	 sr = *(a1 + (l + r) / 2);
	 i = l;
	 j = r;
	 do
	 {
		 while (*(a1 + i) < sr) i++;
		 while (*(a1 + j) > sr) j--;
		 if (i <= j)
		 {
			 swap((a1 + i), (a1 + j));
			 i++;     j--;
		 }
	 } while (i <= j);
	 if (i < r)
		 hoare_sort(i, r);
	 if (j > l)
		 hoare_sort(l, j);
 }


 //�������� ����������
 extern void bogosort(int count)
 {
	 register int i, j;
	 cop(count);
	 auto start = high_resolution_clock::now();
	 srand(time(0)); 

	 while (true)
	 {
		 
		 bool sorted = true;
		 for (i = 1; i < count; i++) {
			 if (a1[i - 1] > a1[i]) {
				 sorted = false;
				 break;
			 }
		 }

		 if (sorted) {
			 break;
		 }

		 for (i = 0; i < count; i++)
		 {
			 j = rand() % count;
			 swap((a1+i), (a1+j));
		 }
	 }

	 auto end = high_resolution_clock::now();
	 duration<double> interval = end - start;
	 cout << "\n����� ����������� �� �������� ����������: " << fixed << setprecision(2) << interval.count() << " ������" << endl;
	 cout << "������ 10 ��������� ���������������� �������:" << endl;
	 out();
 }


 //�����
 extern void find(int count)
 {
	 int i, target;
	 cout << "\n������� ������� ��� ������: ";
	 cin >> target;
	 auto start = high_resolution_clock::now();

	 for (i = 0; i < count; i++)
	 {
		 if (a1[i] == target)
		 {
			 cout << "������� ������! ��� ������: " << i << endl;

			 auto end = high_resolution_clock::now();
			 duration<double> interval = end - start;
			 cout << "����� ����������� �� �������� �����: " << fixed << setprecision(2) << interval.count() << " ������" << endl;
			 cout << "__________________________________" << endl << endl << endl;
			 return;
		 }
	 }
	 auto end = high_resolution_clock::now();
	 cout << "������� �� ������ � �������" << endl;
	 cout << "__________________________________" << endl << endl << endl;
 }


 //�������� ����� 
 extern void find_b(int count)
 {
	 int i, target, left = 0, right = count - 1, middle;
	 cout << "\n������� ������� ��� ������: ";
	 cin >> target;
	 auto start = high_resolution_clock::now();

	 while (left <= right)
	 {
		 middle = left + (right - left) / 2;
		 if (a1[middle] == target)
		 {
			 cout << "������� ������! ��� ������: " << middle << endl;

			 auto end = high_resolution_clock::now();
			 duration<double> interval = end - start;
			 cout << "����� ����������� �� �������� �����: " << fixed << setprecision(2) << interval.count() << " ������" << endl;
			 cout << "__________________________________" << endl << endl << endl;
			 return;
		 }
		 if (a1[middle] < target)
		 {
			 left = middle + 1;
		 }
		 else
		 {
			 right = middle - 1;
		 }
	 }

	 auto end = high_resolution_clock::now();
	 cout << "������� �� ������ � �������" << endl;
	 cout << "__________________________________" << endl << endl << endl;
 }


 //C���������
 extern void sort(int sch)
 {
	 if (sch == 0)
	 {
		 cout << "\n\n��� ����c��!\n";
	 }
	 else
	 {
		 register int sw;
		 cout << "\n\n������� �� ������ ���� ������������ ����������:\n";
		 cout << "1- �� ������� � ���������� �������\n";
		 cout << "2- �� ���� �������� � ������������ �������\n";
		 cout << "3- �� ���� ����������� � ����� � ������������ �������\n";
		 cin >> sw;
		 while (sw <= 0 || sw > 3 || cin.fail() || cin.peek() != '\n')
		 {
			 cin.clear();
			 cin.ignore(1000, '\n');
			 cout << "������ �����: ����� �������� ������ ���� ������������� ����� ������ �� 1 �� 3. ��������� ����: ";
			 cin >> sw;
		 }
		 switch (sw)
		 {
		 case 1: sort_fio(sch); break;
		 case 2: sort_bith(sch); break;
		 case 3: sort_ya(sch); break;
		 }
	 }
	 cout << "__________________________________" << endl << endl << endl;
 }


 //C��������� �� �������
 extern void sort_fio(int sch)
 {
	 register int i, j;
	 for (i = 0; i < sch; i++)
		 for (j = sch - 1; j > i; j--)
			 if (strcmp(mas[j - 1].fam, mas[j].fam) > 0)
			 {
				 t = mas[j - 1];
				 mas[j - 1] = mas[j];
				 mas[j] = t;
			 }
	 cout << "\n\n��������� (����� ��������):\n";
	 for (i = 0; i < sch; i++)
	 {
		 cout << "\n";
		 cout << i + 1 << ". " << mas[i].fam << endl;
	 }
 }


 //���������� �� ���� ��������
 extern void sort_bith(int sch)
 {
	 register int i, j;
	 for (i = 1; i <= sch - 1; i++)
	 {
		 j = i;
		 while (mas[j].bith < mas[j - 1].bith && j >= 1)
		 {
			 t = mas[j - 1];
			 mas[j - 1] = mas[j];
			 mas[j] = t;
			 j--;
		 }
	 }
	 cout << "\n\n��������� (����� �������):\n";
	 for (i = 0; i < sch; i++)
	 {
		 cout << "\n";
		 cout << i + 1 << ". " << mas[i].fam << "- " << mas[i].bith << endl;
	 }
 }


 //���������� �� ���� ����������� � �����
 extern void sort_ya(int sch)
 {
	 register int i, j, gap, sorted;
	 for (gap = sch / 2; gap > 0; gap /= 2)
		 do {
			 sorted = 0;
			 for (i = 0, j = gap; j < sch; i++, j++)
				 if (mas[i].ya > mas[j].ya)
				 {
					 t = mas[i];
					 mas[i] = mas[j];
					 mas[j] = t;
					 sorted = 1;
				 }
		 } while (sorted);

	 cout << "\n\n��������� (����� �����):\n";
	 for (i = 0; i < sch; i++)
	 {
		 cout << "\n";
		 cout << i + 1 << ". " << mas[i].fam << "- " << mas[i].ya << endl;
	 }
 }
