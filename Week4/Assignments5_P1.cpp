#include <iostream>
using namespace std;
int a[1000];
int temp[1000] ={};
int n;
void PrintInPreOrder(int x) {

	for( int i=0 ; i< n-1; i++)
	{
		if (temp[a[i]] == x)
		{
			cout << a[i] << " ";
			PrintInPreOrder(x+1);
		  }  
	}
}

void PrintInPostOrder() {
	
}

void PrintInInOrder() {
	
}


int main()
{	// 5 4 1 2 1 3 2 4 2 5
	int m,x,y, height =0;
	int b[1000] = {};
	bool BiTree = true;
	cin >> n >> m;
	for(int i=0 ; i< n-1 ; i++)
	{
		cin >> x >> a[i];
		if( 0 == i ) temp[x] = 0;
		b[x]++;
		if( b[x] > 2) BiTree = false;
		temp[a[i]] = x;
		height = (height > x) ? height : x;
	}
	PrintInPreOrder(1);
//	PrintInPostOrder();
//	PrintInInOrder();
	cout << "The height of the tree is: " << height;
	return 0;
}
