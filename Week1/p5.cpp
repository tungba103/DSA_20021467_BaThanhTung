#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main(){
	int n;
	cin >> n;
	// Khoi tao 2 bien min, max va gan gia tri ban dau
	int min=n,max=n;
	for(int i=0 ; i< n; i++)
		{
			cin >> n;
			min = ( n < min) ? n : min;
			max = (n > max) ? n : max;
		}
	cout << min + max;
	return 0;
}
