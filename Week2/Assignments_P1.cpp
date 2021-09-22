#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int *a = new int[10000];
	int count=0;
	for(int i=0 ; i < n ; i++)
		cin >> a[i];
	for(int i=0 ; i< n; i++)
		{
			for(int j=i+1 ; j < n; j++)
			{
				if( a[i] == a[j] ) count++;
			}
		}
	cout << "the number of pairs (i,j) that A[i] = A[j] is " << count << endl;
	return 0;
}
