#include <iostream>
using namespace std; 
// Bubble Sort
int main()
{
	int n, a[1000];
	cin >> n;
	// 2 1 10 6 3 8 7 13 20
	for(int i=0 ; i< n ; i++) cin >> a[i];
	for(int i=0 ; i < n ; i++)
	{
		int count=0;
		for(int j=0 ; j< n-1 ; j++)
		{
			if( a[j] > a[j+1])
			{
				int c = a[j+1];
				a[j+1] = a[j];
				a[j] = c;
			}
			else count++;
			if( count == n-1) break; 
		}
	}

	for(int i=0 ; i< n ; i++)
		cout << a[i] << " ";
	return 0;
}
