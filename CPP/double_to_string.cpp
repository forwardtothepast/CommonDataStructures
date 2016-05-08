#include<iostream>
#include<ostream>
using namespace std;
char* getStr(double n, int precision)
{
	long intP = trunc(n);
	int count = 0;
	while (intP > 0)
	{
		intP = intP / 10;
		count++;
	}
	char* ret = new char[count + 2 + precision];
	intP = trunc(n);
	int c = count;
	while (intP > 0)
	{
		ret[c - 1] = '0' + (intP % 10);
		intP = intP / 10;
		c--;
	}
	ret[count] = '.';
	long p = trunc(n);
	long t = trunc(n * pow(10, precision)) - (p*pow(10, precision));
	c = precision  + count;
	int counter = precision;
	while (precision > 0)
	{
		ret[c ] = '0' + (t % 10);
		t = t / 10;
		c--;
		precision--;
	}
	ret[counter + count + 1] = '\0';
	return ret;

}
int main()
{
	double d = 25887658.8658658;
	cout << d << endl;
	cout << getStr(d,4);

}


/*output:

2.58877e+007
25887658.8658Press any key to continue . . .


*/