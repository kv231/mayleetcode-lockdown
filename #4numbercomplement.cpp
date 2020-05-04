/*find complement of number--> 5-->2*/
class Solution {
public:
    int findComplement(int num) {
        int count=0;
        int res=0;
        int num1=num;
        while(num1){
            if(!(num1&1)){
                res+=pow(2,count);
            }
            count++;
            num1=num1>>1;
        }
        return res;
    }
};
// another solution
#include<bits/stdc++.h>
using namespace std;
int main(){
    int num;
    cin>>num;
    int mask=~0;
    int count=log2(num)+1;
    mask=mask<<count;
    num|=mask;
    num=~num;
    cout<<num;
}
