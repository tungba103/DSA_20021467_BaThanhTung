#include <iostream>
#include <set>
using namespace std;
// 11 -5 -4 -3 -2 -1 0 1 2 3 4 5
void PrintSetsOfThreeN2LogN(int n, int a[])
{
	set<int> s;
	for(int i=0 ; i < n ; i++)
		s.insert(a[i]);
	for(int i=0 ; i< n-2 ; i++)
		{
			for(int j= i+1 ; j< n-1 ; j++)
			{
				if( s.find(-a[i]-a[j]) != s.end() ) cout << a[i] << " " << a[j] << " " << -a[i]-a[j] << endl;
			}
		}
	return;
}

int main()
{
	int n, a[100];
	cin >> n;
	for( int i=0 ; i< n ; i++) cin >> a[i];
	PrintSetsOfThreeN2LogN(n,a);
	return 0;
}

