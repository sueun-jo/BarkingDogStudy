#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    //small a = 97 (아스키코드값) 
    //small z = 122 (아스키코드값)
    //대문자랑 소문자 차이가 32만큼 난다 소문자-32 = 대문자
    
    if ('a' <= s[0] && s[0] <= 'z' ) {
        s[0] -= 32;
    }
    
    for (int i=1; i<s.size(); ++i){
        if (s[i] !=' ' && s[i-1]==' '){ //내 앞이 공백이고 난 공백 아니면
            if ('a' <= s[i] && s[i] <= 'z'){ // 변경
                s[i] -= 32; 
            }    
        } else { //나머지 
            if (s[i]!=' ' && 'A' <= s[i] && s[i] <= 'Z' ){
                //중에서도 공백 아닌 일반의 경우
                s[i] += 32;
            }
        }
        // 공백문자가 여러개 나올 수 있다고 했으니
        // 나는 공백문자가 아니면서 내 앞은 공백인지 확인하고 변경
    }
    return s;
}