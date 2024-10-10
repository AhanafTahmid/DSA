// n = 30, values = 2,3,5
void inclusion_exclusion(){
    int val = 30;
    int n = 3;
    int ar[n+1] = {2,3,5};
    int all_subset= (1<<n);
    int ct = 0, prod = 1;
    ll sum = 0;
    for(int i=1;i<all_subset;i++){
        ct = 0, prod = 1;//count, product
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                ct++;
                prod*=ar[j];
                cout<<ar[j]<<" ";
            }
        }
        if(ct%2==1) sum+=(val/prod);
        else sum-=(val/prod);
    }
}

