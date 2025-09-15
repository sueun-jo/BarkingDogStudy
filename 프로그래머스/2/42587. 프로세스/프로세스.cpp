#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<int> priorities, int location) {
    
    queue<pair<int, int>> q;
    priority_queue <int> pq; 
    //pritorities는 중요도가 순서대로 담겨있다
    //location은 내가 몇번째로 실행될지 궁금해 하는 프로세스의 위치이다 
    int n = priorities.size();
    
    for (int idx=0; idx<n; idx++){
        pq.push(priorities[idx]);
        q.push({priorities[idx], idx});
        // q 요소의 first 값은 우선순위, second는 idx임
    }
    
    int answer = 1;
    while (!q.empty()){ //큐가 빌때까지 반복한다
        
        if (q.front().first == pq.top()){ //pq.top()과 q.front().first가 일치하면
            if (q.front().second == location){ // 그 문서가 내가 찾는 location이면
                return answer;
            }
            q.pop(); //우선순위는 맞는데 location은 아니야 그러면 꺼내
            pq.pop(); //마찬가지 꺼내
            answer++;

            } else { // 우선순위가 달라, 그러면 꺼내서 다시 집어 넣어야됨
                pair <int, int> temp = q.front(); //임시에 담아서
                q.push(temp); // 뒤에 넣고
                q.pop(); // 꺼냄
            }            
        } //while문 끝나는 곳
    
    return answer;
    }
    
