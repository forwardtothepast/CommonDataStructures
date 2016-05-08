/* Yo u are given two 32-bit numbers, N andM, and two bit positions, i and j . 
Write a method to insert M into Nsuch that M starts at bit j and 
ends at bit i. You can assume that the bits j through i have enough space to fit all ofM. 
That is, ifM= 10011, you can assume that there are at least 5 bits between j and i. 
You would not, for example, have j-3 and i=2, 
because M could not fully fit between bit 3 and bit 2. 
EXAMPLE: Input: N = 16000000000, M = 10011, i = 2, j = 6 Output: N = 10001001100*/


#include<iostream>
using namespace std;
void print(int n)
{
	cout << endl;
	int i = (sizeof(int)* 8) -1;
	for (; i >= 0; i--)
	{
		if ((1 << i) & n)
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
}

int getAndSet(int n, int m, int i, int j)
{
	int toset = j - i + 1;
	int helper = ~0 << toset;
	int get = (~helper & m) << i;
	return ((~(~helper<<i) & n) | get);
}
void main(int argc , char * agrv[])
{
	if (argc < 5)
		return;

	int n = atoi(agrv[1]);
	cout << endl<<n << endl;
	print(n);
	int m = atoi(agrv[2]);
	cout << endl<<m << endl;
	print(m);
	int i = atoi(agrv[3]);
	cout << endl<< i << endl;
	print(i);
	int j = atoi(agrv[4]);
	cout << endl<< j << endl;
	print(j);
	cout << endl << "result";
	print(getAndSet(n,m,i,j));
	
}

/*output:
C:\Users\pusonw\Documents\Visual Studio 2013\Projects\Project10\Debug>Project10.exe -1024 1 3 7

-1024

11111111111111111111110000000000
1

00000000000000000000000000000001
3

00000000000000000000000000000011
7

00000000000000000000000000000111
result
11111111111111111111110000001000
C:\Users\pusonw\Documents\Visual Studio 2013\Projects\Project10\Debug>
*/