#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "CircArray.h"

int isEven(int value) { return value % 2; }

int main(void)
{
	CircArray cb;

	bool exit = false;
	char key;

	printf("�������������������������������ͻ\n");
	printf("�esc�Exit			�\n");
	printf("�1  �Print Ring			�\n");
	printf("�2  �Add element		�\n");
	printf("�3  �Get element		�\n");
	printf("�4  �Create Circle		�\n");
	printf("�������������������������������ͼ\n");

	while (!exit)
	{

		key = _getch();
		switch (key)
		{
		case 27:
			printf("Exit.\n");
			exit = true;
			break;

	    case '1':
			cb.print();
			break;

		case '2':
		{
			int n = rand() % 100;
			printf("Adding %i\n", n);
			cb.put(n);
			break;
		}

		case '3':
		{
			int *n = cb.get();
			
			if(n != NULL)	printf("Get %i\n", *n);
			else printf("There is no element to take!\n");
			delete(n);
			break;
		}

		case '4':
		{
			int n;
			printf("Input number of ring: ");
			scanf("%i", &n);
			cb = CircArray(n);
			break;
		}

		default:
			printf("Wrong symbol\n");
			break;
		}
	}
	return 0;
}