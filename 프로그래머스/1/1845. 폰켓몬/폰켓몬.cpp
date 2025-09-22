#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    //nums는 포켓몬 번호 종류가 담겨있음
    //포켓몬 마릿수는 nums.size();
    //내가 골라야 하는 포켓몬 갯수는 nums.size()/2;  (내림)
    
    //nums배열을 기준으로 map을 만든다
    //map의 key로는 포켓몬 번호를, value는 마릿수를 담는다
    
    unordered_map <int, int> um;
    int n = nums.size();
    for (int i=0; i<n; i++){
        um[nums[i]]++; //um값 채우기
    }
    
    int choice = n/2; //데려갈 수 있는 마릿수
    
    if (um.size()>=choice) answer=choice; //종류가 많으면 최대로 다양하게
    else answer = um.size();
    
    return answer;
}