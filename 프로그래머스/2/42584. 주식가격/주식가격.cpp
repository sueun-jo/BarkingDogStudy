#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int n = prices.size();
    
    for (int idx=0; idx<n; ++idx){
        int time = 0;
        for (int i=idx+1; i<n; ++i){
            time++;
            if (prices[idx]>prices[i])
                break;
        }
        answer.push_back(time);
    }
    return answer;
}
