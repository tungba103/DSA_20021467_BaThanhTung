// Complexity: O(n^2)
vector<int> closestNumbers(vector<int> arr) {
    sort(arr.begin(),arr.end());
    int min=arr[1]-arr[0];
    for(int i=1 ; i< (int)arr.size()-1 ; i++)
        min = ( min < (arr[i+1]-arr[i])) ? min : (arr[i+1]-arr[i]);
    vector<int> res;
    for(int i=0 ; i< (int)arr.size()-1 ; i++)
    {
        if( arr[i+1] - arr[i] == min)
        {
            res.push_back(arr[i]);
            res.push_back(arr[i+1]);
        }
    }
    return res;
}
