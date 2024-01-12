//using recursion
int fac(int n){
    if(n==1) return 1;
    return n * fac(n-1);
}

//Using DP
long long factorial[10001000];//1e9+1000
void fac(int n) {
    factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorial[i] = (factorial[i - 1] * i);
    }
}