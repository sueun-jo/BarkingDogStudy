#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    // bool타입의 vector 선언해서
    // 앞에꺼랑 같으면 false, 아니면
    vector<int> answer;

    
    answer.push_back(arr[0]); //첫항은 무조건 중복 아님
    for (int i=1; i<arr.size(); i++){
        
        if (arr[i-1]==arr[i]){
            continue;
        } else answer.push_back(arr[i]);
    }
    
    
    return answer;
}