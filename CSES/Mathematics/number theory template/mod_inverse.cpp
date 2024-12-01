//Main Inverse template, for divisional power
int md = 1e9 + 7;
int power(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%m;
        a = (a * a) %m;
        b >>= 1;
    }
    return res;
}


int inverse(int i){
    return power(i, md-2, md);//binexpo(tt,M-2,M); = a^(M-2)%M
}



///############################################




int md = 1e9 + 7;
int inverse(int i){
    if(i==1) return 1;
    return (md - ((md/i)*inverse(md%i))%md+md)%md;
}

