#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    /* 내가 생각한 풀이 방법
    unordered_multiset으로 중복을 허용하게 해서 participant를 만든다
    completion 벡터를 key로 해서 지운다
    남은 multiset을 return한다
    */
    
    unordered_multiset <string> U; //multiset 참가자 명단
    for (int i=0; i<participant.size(); i++){
        U.insert(participant[i]);
    } // U set 완성
    
    for (int i=0; i<completion.size(); i++){
        U.erase(U.find(completion[i])); //찾아서 지움
    }
    
    for (auto remain : U){
        answer += remain;
    }
    return answer;
}