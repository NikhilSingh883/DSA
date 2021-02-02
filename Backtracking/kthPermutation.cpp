int findFirstNumIndex(int& k, int n)
{
 
    if (n == 1)
        return 0;
    n--;
 
    int first_num_index;
    // n_actual_fact = n!
    int n_partial_fact = n;
 
    while (k >= n_partial_fact
           && n > 1) {
        n_partial_fact
            = n_partial_fact
              * (n - 1);
        n--;
    }
 
    // First position of the
    // kth sequence will be
    // occupied by the number present
    // at index = k / (n-1)!
    first_num_index = k / n_partial_fact;
 
    k = k % n_partial_fact;
 
    return first_num_index;
}


string getPermutation(int n, int k) {
    string ans = "";
 
    vector<int> s;
 
    // Insert all natural number
    // upto n in set
    for (int i = 1; i <= n; i++)
        s.push_back(i);
 
 
    // subtract 1 to get 0 based indexing
    k = k - 1;
 
    for (int i = 0; i < n; i++) {
 
        int index
            = findFirstNumIndex(k, n - i);
 
        // itr now points to the
        // number at index in set s
        ans += (to_string(s[index]));
 
        // remove current number from the set
        s.erase(s.begin() + index);
 
    }
    return ans;
}