int findmin(int &a, int &b, int &c)
{
    if( a < b)
    {
        if( a < c) return a;
        else return c; 
    }
    else {
        if( b > c) return c;
        else return b;
    }
}

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    // sum1, sum2, sum3
    stack<int> s1,s2,s3;
    int sum1=0, sum2=0, sum3=0;
    for(int i= (int)h1.size() -1 ; i>=0  ; i--)
        {
            s1.push(h1[i]);
            sum1+= h1[i];
        }
    for(int i= (int)h2.size() -1 ; i>=0  ; i--)
        {
            s2.push(h2[i]);
            sum2+= h2[i];
        }
    for(int i= (int)h3.size() -1 ; i>=0  ; i--)
        {
            s3.push(h3[i]);
            sum3+= h3[i];
        }
    
    cout << sum1 << sum2 << sum3 << endl; // 1 1 1 2 1 4 3 2 3
    int min=sum1;
    while( sum1 != sum2 || sum1 != sum3 || sum2 != sum3)
    {
        min = findmin(sum1,sum2,sum3);
        while( sum1 > min){
            sum1 -= s1.top();
            s1.pop();
        } 
        while( sum2 > min){
            sum2 -= s2.top();
             s2.pop();
        }
        while( sum3 > min){
            sum3 -= s3.top();
            s3.pop();
        } 
    }
    return min;
}