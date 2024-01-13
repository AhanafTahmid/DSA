int md = 1e9 + 7;
ll inverse(ll i){
    if(i==1) return 1;
    return (md - ((md/i)*inverse(md%i))%md+md)%md;
}