#include <iostream>
using namespace std; 
// Selection sort
int main()
{
	int n, a[1000];
	cin >> n;
	// 2 1 10 6 3 8 7 13 20
	for(int i=0 ; i< n ; i++) cin >> a[i];
	for(int i=0 ; i < n ; i++)
	{
		for( int j = i+1 ; j < n; j++)
		{
			if( a[i] > a[j])
			{
				int c = a[i];
				a[i] = a[j];
				a[j] = c;
			}
		}

	}
	for(int i=0 ; i< n ; i++)
		cout << a[i] << " ";
	return 0;
}
