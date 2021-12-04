#include <iostream>
#include <vector>
using namespace std;

void snapsack(int n, vector<int> weight, vector<int> value, int V)
{
    vector<double> res;
    for(int i=0  ;i<  n; i++)
        res.push_back((double)value[i]/weight[i]);
    for(int i=0 ; i < n ; i++)
    {
        int count=0;
        for( int j=0 ; j< n-1 ; j++)
        {
            if(res[j] < res[j+1]) {
                count++;
                swap(res[j],res[j+1]);
                swap(weight[j],weight[j+1]);
                swap(value[j],value[j+1]);
            }
        }
        if(count==0) break;
    }
    for( int i=0  ;i< n ; i++) {
        if(V >= weight[i]) {
            cout << weight[i] << " ";
            V -= weight[i];
        }
    }
}
int main() {
    int n,x,V;
    vector<int> weight;
    vector<int> value;
    cin >> n;
    for(int i=0 ; i< n;  i++)
    {
        cin >> x;
        weight.push_back(x);
        cin >> x;
        value.push_back(x);
    }
    cin >> V;
    snapsack(n,weight,value,V);
  //  5 12 50 15 30 10 15 2 2 6 8
}

