#include <iostream>
using namespace std;
int UCLN(int x, int y)
{	
	// tru dan 2 so den khi bang nhau
	while(x != y)
	{
		if( x > y) x -= y;
		else y -= x;
	}
	return x;
	
//	int min = (x < y) ? x : y;
//	int i;
//	for(i = min/2 ; i > 0 ; i--){
//		if( x%i == 0 && y%i == 0) break; 
//	} 
//	return i;
	
}
int main()
{
	int x,y;
	cin >> x >> y;
	cout << UCLN(x,y);
	return 0;
}

