#include <bits/stdc++.h>
using namespace std;


bool checkRotation(string s1, string s2){
    if(s1.length() != s2.length()){
        return false;
    }
    string temp = s1+s1;
    if(temp.find(s2) != string::npos){
        return true;
    }else{
        return false;
    }
}


int main(){

    
    return 0;
}