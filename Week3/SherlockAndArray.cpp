// Complexity: O(n)
string balancedSums(vector<int> arr) {
    int left=0, right =0;
    int l=0, r= (int)arr.size()-1, count = r;
    while(count > 0)
    {
        while(arr[l] == 0)
        {
            l++;
            count--;
        }
        while(arr[r] == 0)
        {
            r--;
            count--;
        }
        if( count == 0) break;
        if( left >= right)
        {
            right += arr[r];
            r--;
        }
        else
        {
            left += arr[l];
            l++;
        }
        count--;
    }
    if( left == right ) return "YES";
    return "NO";
}
