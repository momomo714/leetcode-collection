#include <iostream>
#include<stack>
#include<string>
using namespace std;
bool match_true(char left,char right){
return(left=='('&&right==')')||(left=='['&&right==']')||(left=='{'&&right=='}');}
int main(){
    stack<char>str;
    char a;
    bool error=false;
    while(cin.get(a)){
        if(a=='('||a=='['||a=='{'){str.push(a);}
    else if(a==')'||a==']'||a=='}'){
    if(str.empty()){error=true;break;}    
    char top=str.top();
    str.pop();
    if(!match_true(top,a)){
        error=true;
        break;}}}
if(!error&&!str.empty()){error=true;}
if(!error){cout<<"正确"<<endl;}else{cout<<"错误"<<endl;}
return 0;    }