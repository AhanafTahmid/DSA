
Template - Take not take approach for all subsequence 

void f(vector<int>arr, int index,int n,vector<int> &subarr, vector<vector<int>>&ans){
    if (index == n){
        ans.insert(subarr);
        return;
    }
    //pick
    subarr.push_back(arr[index]);
    f(arr, index+1,n,subarr, ans);
    subarr.pop_back();
    //not_pick
    f(arr, index + 1,n,subarr, ans);
}


void f(vector<int>arr, int index,int n, int s, vector<int>&ans){
    if (index == n){
        ans.push_back(s);
        return;
    }
    //take
    f(arr, index+1,n,s + arr[index],ans);
    //not take
    f(arr, index+1,n,s,ans);
}

//backtracking template

bool possible(){

}
bool f(){
    //traverse and check if possible
    //do backtrack here
}
