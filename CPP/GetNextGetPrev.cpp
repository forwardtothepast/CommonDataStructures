/*

Given a positive integer, print the next smallest and 
the next largest number that have the same number of 7 
bits in their binary representation*/


#include<iostream>
using namespace std;
int getNext(int n)
{
	if (n == 0)
		return 0;	
	int c0=0, c1=0, p=INT_MIN;
	for (int i = 0; i < sizeof(int)* 8; i++)
	{
		if (n & 1 << i)
		{
			c1 += 1;
			p = i;
		}
		else
		{
			if (p != INT_MIN)
			{
				p = i;
				break;
			}
			c0 += 1;
		}
	}
	n |= 1 << p;
	n &= (~0) << p;
	n |= ~((~0) << (c1 - 1));
	return n;
}
int getPrev(int n)
{
	if (n == 0)
		return 0;
	int c0 = 0, c1 = 0, p = INT_MIN;
	for (int i = 0; i < sizeof(int)* 8; i++)
	{
		if (!(n & 1 << i))
		{
			c0 += 1;
			p = i;
		}
		else
		{
			if (p != INT_MIN)
			{
				p = i;
				break;
			}
			c1 += 1;
		}
	}
	n &= ~(1 << p);
	n &= (~0) << p;
	n |=( ~((~0) << (c1 + 1)))<< (c0 - 1) ;
	return n;
}
int main()
{
	int n = 5;
	cout << getNext(n)<<endl;
	cout << getPrev(n)<<endl;

}

/*output:

6
3
Press any key to continue . . .


*/