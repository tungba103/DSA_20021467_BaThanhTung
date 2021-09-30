int pairs(int k, vector<int> arr) {
    sort(arr.begin(),arr.end());
    int count=0;
    for(int i=0 ; i< (int)arr.size()-1 ; i++)
        for(int j=i+1 ; j <(int)arr.size(); j++)
            if( arr[j] - arr[i] == k) count++;
    return count;
}
