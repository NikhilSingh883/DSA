string Solution::multiple(int A) {
    queue<long long> Q;
    long long num;
    Q.push(1);
    
    while(!Q.empty()){
        num = Q.front();
        Q.pop();
        if(num%A==0) break;
        
        Q.push(num*10);
        Q.push(num*10+1);
    }
    
    string str;
    while(num){
        int d = num%10;
        num/=10;
        str.push_back(d+'0');
    }
    
    reverse(str.begin(),str.end());
    
    return str;
}
