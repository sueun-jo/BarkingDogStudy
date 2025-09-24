#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a;
    char op;
    string b;
    cin >> a >> op >> b;

    if (op=='*'){ //곱하기면
        int a_zero = a.size()-1; //a의 0의 갯수
        int b_zero = b.size()-1; //b의 0의 갯수

        int zero_num = a_zero+b_zero;

        string a="1"; //a초기화

        for (int i=0; i<zero_num; i++){
            a += "0";
        }
        
        cout << a;
        return 0;
        
    } else if (op=='+'){
        //길이가 차이날때 idx차이를 생각해요

        int d = a.size()-b.size(); //a와 b의 길이 차이
        // cout << "d: " << d <<"\n";
        if (d>0){ //a>b
            for (int i=0; i<b.size(); i++){
                if (b[i]=='1'){
                    a[i+d] = '1';
                    break;
                }
            }
            cout << a;
        } else if (d<0){ // a<b
            d *= -1;
            for (int i=0; i<a.size(); i++){
                if (a[i]=='1'){
                    b[i+d] = '1';
                    break;
                }
            }
            cout << b;
        } else if (d==0) { //길이 차이가 없음
            a[0]='2';
            cout << a;
        }
        
    }
    return 0;
}