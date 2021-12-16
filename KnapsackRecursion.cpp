#include <iostream>
#include <vector>
using namespace std;

vector<int> weight;
vector<int> value;

int Knapsack(int n, int m) {
    if(-1 == n) return 0;
    if(weight[n] > m ) return Knapsack(n-1,m);
    else {
        int v1 = weight[n] + Knapsack(n-1,m-weight[n]);
        int v2 = Knapsack(n-1,m);
        return (v1 > v2) ? v1: v2;
    }
}

int main() {
    int n,x,m;
    cin >> n;
    for(int i=0 ; i< n;  i++)
    {
        cin >> x;
        weight.push_back(x);
        cin >> x;
        value.push_back(x);
    }
    cin >> m;
    cout << Knapsack(n,m);
  //  5 12 20 15 30 10 15 2 2 6 20
}

