#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector <int> publish;
    vector <int> answer;
    
    int n = progresses.size();
    for (int i=0; i<n; i++){
        int remain = 100 - progresses[i];
        //나머지 있냐? 잇으면 +1 없으면 -1
        int x = (remain%speeds[i])==0 ? remain/speeds[i] : remain/speeds[i]+1;
        publish.push_back(x);
    }
    
    int start = 0;
    while (start < n){
        int day = publish[start]; //day에 시작 기준점
        int cnt = 1;
        
        int idx = start+1;
        
        while ( idx < n && day >= publish[idx]){
            idx++;
            cnt++;
        }
        
        answer.push_back(cnt);
        start = idx;
    }
    
    return answer;
}