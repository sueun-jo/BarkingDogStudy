#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

/*
    이진변환과정에서 날아간 0의 갯수(deleted) 와, 이진변환의 과정의 횟수(cnt)를
    answer 벡터에 담아서 출력해야됨
    (이진변환과정)
    1. x에서 0의 갯수를 찾아 deleted에 누적합
    2. x에서 1의 갯수를 c라고 하고 "111" 일때 c는 3
    3. c를 2진수로 바꾼 문자열을 문자열 x에 갱신 -> 변환 과정 끝
    4. cnt++
    5. x=="1" 확인하고 맞으면 종료 아니면 계속 반복
*/

vector<int> solution(string s) {
    vector<int> answer;
    
    int deleted = 0; //지워진 0의 갯수
    int cnt = 0; //변환 과정 횟수
    
    // 1. x에서 0의 갯수를 찾아 deleted에 누적합
    // 2. x에서 1의 갯수를 c라고 하고 "111" 일때 c는 3
    // 3. c를 2진수로 바꾼 문자열을 문자열 x에 갱신 -> 변환 과정 끝
    // 4. cnt++
    // 5. x=="1" 확인하고 맞으면 종료 아니면 계속 반복
    
    while (1){
        if (s=="1") break; //탈출
        // 1.
        deleted += count(s.begin(), s.end(),'0'); 
        
        //2.
        int c = count(s.begin(), s.end(), '1'); // 1 갯수만이 0 제거된 x의 길이
        
        //3.
        bitset<32> bi(c); //2진수 변환
        s=""; //s를 초기화해
        s = bi.to_string(); //문자열 변환 (이진변환) -> 원하지 않는 0이 붙을 수 있음 앞부분에
        //여기서 s에 원치않는 0을 제거하는 로직이 들어감
        s.erase(0, s.find('1')); //0을 제거한다
        
        //4. 변환과정 ㄹㅇ 끝
        cnt++; //cnt하나 늘
        

    } //while 종료
    
    answer.push_back (cnt);
    answer.push_back (deleted);
    return answer;
}