#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[1000];
	int b[1000];
	int j=0;
	int sum,min=0,max=0;
	for(int i=0 ; i < n; i++)
		{
			cin >> a[i]; 
			min = (a[i] < min) ? a[i] : min; // find min
			max = (a[i] > max ) ? a[i] : max; // find max
			if(a[i] % 2 ==0)
			{
				b[j]=a[i];
				j++;
			}
		}
	//done
	return 0;
}
