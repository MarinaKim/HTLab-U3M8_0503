#include<stdio.h>
#include <locale.h>
#include<iostream>
#include <math.h>
#include <time.h>
#include <stdint.h>
#include <string.h>

using namespace std;

 int * createDunamic(int len) // function return ukazatel
{
	return (int *)malloc(len * sizeof(int));
}

 char * createDunamicChar(int len) // function return ukazatel
{
	return (char *)malloc(len * sizeof(char));
}

char * reallocDunamicChar(char * str, int len) // function return ukazatel
{
	return (char*)realloc(str, len * sizeof(char));
}

void replacestr(char *str, char * old, char * tonew)
{
	int count = 0;
	int lenOld = strlen(old);
	int strLen = strlen(str);

	for (int i = 0;i < strlen(str);i++)
	{
		if (str[i] == *old)
		{
			count++;
			old++;
		}
		else
		{
			old = old - count;
			count = 0;
		}

		if (count == lenOld)
		{
			int different = strlen(tonew) - lenOld;
			if (different > 0)
			{
				str = reallocDunamicChar(str, (strLen + different + 1));
				if (str == NULL) break;
				//Доделать 
				/*for (int j = strlen(str) + 1;j > i;j--)
				{
					*(str + j) = *(str + j - 1);
				}

				tonew = tonew - strlen(tonew);

				for (int j = i - strlen(old);j <= i;j++)
				{
					*(str + j) = *(tonew);
					tonew++;
				}*/
			}
			else if (different == 0)
				for (int j = 0;j < lenOld;j++)
					*(str + j) = *(tonew + j);
		}
	}

}

void five(char*a, int r)
{
	for (int i = 0; i < r / 2; i++)
	{
		if (a[i] == ':')
			a[i] = '.';
	}

	for (int i = r / 2; i < r; i++)
	{
		if (a[i] == '!')
			a[i] = '.';
	}

	printf("%s\n", a);
}
int BinToTen(int *a, int r)
{
	int k;
	for (int i = 0;i < r;i++)
	{
		int j = r - 1;
		while (j >= 0)
		{
			k += a[i] * pow(2, j);
			j--;
		}
	}
	return k;
}
void binary(int *a, int r)
{
	for (int i = 0; i < r; i++)
		if (a[i] == 0 || a[i] == 1)
		{
			int l = BinToTen(a, r);
			printf("%d\n", l);
		}
}

void DifSimbols(char *a, int r)
{
	for (int i = 0;i < r; i++)
	{
		if ((a[i] >= -64 && a[i] < -1) || (a[i] >= 65 && a[i] <= 90) || (a[i] > 97 && a[i] < 122))
		{

		}
	}
}

void StartSameEnd(char *str, int r)
{
	unsigned char *word = (unsigned char*)calloc(50, sizeof(unsigned char));
	int n = 0, kon = 0, ws = 0;

	while (kon < r)
	{
		while (str[kon] != ' '&&str[kon] != ',')
		{
			if (kon != r)
				kon++;
			else break;
		}
		for (int i = n;i < kon;i++)
		{
			word[ws] = str[i];
			ws++;
		}
		word[ws] = '\0';

		if (kon - n != 1)
		{
			if (isupper(word[0]))
			{
				if (tolower(word[0]) == word[ws - 1])
					cout << word << endl;
			}
			else
			{
				if (word[0] == word[ws - 1])
					cout << word << endl;
			}
		}
		n = kon + 1;
		if (str[kon] != ' ' || str[kon] != ',')
			kon++;
		ws = 0;
	}
}

//8
void ThreeSymb(char*str, int r)
{
char *word = (char*)calloc(50, sizeof(char));
	int n = 0, kon = 0, ws = 0;

	while (kon < r)
	{
		while (str[kon] != ' '&&str[kon] != ',')
		{
			if (kon != r)
				kon++;
			else break;
		}
		for (int i = n;i < kon;i++)
		{
			word[ws] = str[i];
			ws++;
		}
		word[ws] = '\0';
		
		if (strlen(word) == 3)
			printf("%s\n", word);

		n = kon + 1;
		if (str[kon] != ' ' || str[kon] != ',')
			kon++;
		ws = 0;
	}
}

void Findk(char *str, int r)
{
	char *word = (char*)calloc(50, sizeof(char));
	int n = 0, kon = 0, ws = 0;

	while (kon < r)
	{
		
		while (str[kon] != ' '&&str[kon] != ',')
		{
			if (kon != r)
				kon++;
			else break;
		}
		for (int i = n;i < kon;i++)
		{
			word[ws] = str[i];
			ws++;
		}
		word[ws] = '\0';

		for (int i = 0; i < strlen(word); i++)
		{
			if (word[i] == 'k')
			{
				printf("%s\n", word);
				break;
			}
	}
		n = kon + 1;
		if (str[kon] != ' ' || str[kon] != ',')
			kon++;
		ws = 0;
	}
}


int cSymb(char*str, char symb)
{
	int count = 0;
	for (int i = 0;i < strlen(str);i++)
		if (*(str + i) == symb)
			count++;
	return count;
}

void repl7(char*str)
{
	int c = cSymb(str, ' ');
	str = (char*)realloc(str, sizeof(char)*(strlen(str) + c));
	int n = 0, kon = 0, ws = 0;
		while (kon < strlen(str))
	{
		while (str[kon] != ' ')
		{
			if (kon != strlen(str))
				kon++;
			else break;
		}
		for (int i = strlen(str)+1; i > kon;i--)
		{
			*(str + i) = *(str + i-1);
		}
		*(str + kon) = ',';
		kon=kon+2;

	}
	printf("\n\n%s\n", str);

}