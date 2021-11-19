	#include <iostream>
using namespace std;
int arr[1000];

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int split (int low, int high)
{
    int pivot = arr[low]; 
    int left = low+1;
    int right = high;
    while(true){
        while(arr[left] <= pivot && left <= right) left++;
        while(arr[right] >= pivot && left <= right) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[low], arr[right]);
    return right;
}

void quickSort( int low, int high)
{
    if (low < high)
    {
        int pi = split(low, high);
        quickSort(low, pi-1);
        quickSort(pi + 1, high);
    }
}

int main()
{
	int n;
	cin >> n;
	for( int i=0 ; i < n ; i++) cin >> arr[i];
	quickSort(0,n-1);
	for(int i=0 ; i< n ; i++)
		cout << arr[i] << " ";
	return 0;
}
