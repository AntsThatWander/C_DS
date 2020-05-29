#include <stdio.h>


int fibo(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    else{
        return fibo(n-1) + fibo(n-2);
    }
}

int fiboT(int n, int next, int before){
    if(n==1) return next;
    else 
        return fiboT(n-1, next+before, next);

}

int fiboL(int n){
    int before = 0, next = 1;
    for(int i=1; i<n; i++){
        int cur = before + next;
        before = next;
        next = cur;
    }
    return next;
}


