#include <string>
#include <vector>

using namespace std;

void dfs (int x, int &target, vector<int> &numbers, int &answer, int idx, int sum){
    sum += x;
    if (idx == numbers.size()-1){
        if (sum == target) answer++;
        
        return;
    }
    idx++;
    dfs(numbers[idx], target, numbers, answer, idx, sum);
    dfs(-1*numbers[idx], target, numbers, answer, idx, sum);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers[0], target, numbers, answer, 0, 0);
    dfs(-1*numbers[0], target, numbers, answer, 0 ,0);
    
    return answer;
}