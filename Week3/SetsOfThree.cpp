#include <iostream>
using namespace std;
// 11 -5 -4 -3 -2 -1 0 1 2 3 4 5

// Complexity: O(n^3)
// Using 3 loops for check sum of three
void PrintSetsOfThreeN3(int n, int a[])
{
	for(int i=0 ; i< n-2 ; i++)
		{
			for(int j= i+1 ; j< n-1 ; j++)
			{
				for( int k= j+1; k< n ; k++)
				{
					if( a[i] + a[j] + a[k] == 0 ) cout << a[i] << " " << a[j] << " " << a[k] << endl;
				}
			}
		}
	return;
}

// Complexity: O(n^2logn)
//Using 2 loops and BinarySearch to check sum of three
int BinarySearch(int a[], int n, int k)
{
	int l=0, r = n-1;
	while( l < r)
	{
		int mid = (l+r)/2;
		if( k > a[mid])	l = mid+1;
		else r = mid;
	}
	if( a[l] == k) return l;
	return -1;
}

void PrintSetsOfThreeN2LogN(int n, int a[])
{
	for(int i=0 ; i < n; i++)
		for(int j=i+1 ; j< n ; j++)
			if( a[i] > a[j])
			{
				a[i] += a[j];
				a[j] = a[i] -a[j];
				a[i] -= a[j];
			}

	
	for(int i=0 ; i< n-2 ; i++)
		{
			for(int j= i+1 ; j< n-1 ; j++)
			{
				if(BinarySearch(a,n,-a[i]-a[j]) > j) cout << a[i] << " " << a[j] << " " << -a[i]-a[j] << endl;
			}
		}
	return;
}


// Complexity: O(n^2)
// Using iterator
void PrintSetsOfThreeO2(int n, int a[])
{
	for(int i=0 ; i < n; i++)
		for(int j=i+1 ; j< n ; j++)
			if( a[i] > a[j])
			{
				a[i] += a[j];
				a[j] = a[i] - a[j];
				a[i] -= a[j];
			}
	for( int mid = 1 ; mid< n-1 ; mid++)
	{
		int l= mid-1;
		int r= mid+1;
		while( l >= 0 && r <= n-1)
		{
			// -5 -4 -3 -2 -1 0 1 2 3 4 5
			if( (a[l] + a[mid] + a[r]) > 0 ) l--;
			else if( (a[l] + a[mid] + a[r]) < 0) r++;
			else
			{
				cout << a[l] << " " << a[mid] << " " << a[r] << endl;
				r++;
			}
		}
	}
	
}

int main()
{
	int n;
	int a[1000];
	cin >> n;
	for(int i=0 ; i < n ; i++)
		cin >> a[i];
	PrintSetsOfThreeO2(n,a);
	return 0;
}
