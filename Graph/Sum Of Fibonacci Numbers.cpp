int Solution::fibsum(int A) {
    
    stack<int> fib;
    
    int p1 = 1,p=0;
    int p2 = 1;
    fib.push(1);
    int cnt =0;
    while(p <= A){
         p = p1 + p2;
        fib.push(p);
        p1 = p2;
        p2 = p;
    }
    
    while(A>0){
        while(fib.top() > A)
            fib.pop();
            
        A = A - fib.top();
        fib.pop();
        cnt++;
    }
    return cnt;
}
