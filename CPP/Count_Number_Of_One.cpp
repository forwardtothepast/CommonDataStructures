
// Count number one in a given number
using namespace std;
int countOne(int n)
{
	int count = 0;
	while (n != 0)
	{
		count += 1;
		n = n & (n - 1);
	}
	return count;
}
int main()
{
	int n = 16;
	cout << countOne(n);
}