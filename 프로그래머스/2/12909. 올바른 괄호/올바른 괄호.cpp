#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer;
    // how to
    // 문자열을 배열처럼 접근해서 '('이면 1 ')'이면 2로 바꿔보자
    // 그리고 cnt1, cnt2로 각각 요소를 세보자
    // 짝이 맞는지 확인하자 
    // cnt1이 있기 전에 cnt2가 있으면 false를 return
    // cnt1, cnt2가 짝이 맞으면 패스
    // 그리고 배열의 왼쪽과 오른쪽을 같이 보면서 짝 짓고 지어진 애들은 0으로 바꿔보자
    // 모든 배열이 0으로 바뀌었는지 확인하면 true
    
    int n = s.length();

    int cnt1=0;
    int cnt2=0;
    for (int i=0; i<n; i++){
        if (cnt2>cnt1){
            answer = false;
            return answer;
        }
        if (s[i]=='(') {
            
            cnt1++;
        } else if (s[i]==')'){
            
            cnt2++;
        }
    }
    
    if (cnt1==cnt2){
        answer = true;
    } else {
        answer = false;
        return answer;
    }
    
    return answer;
}