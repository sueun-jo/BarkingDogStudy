#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;     // 다리 위 상태 (길이는 항상 bridge_length 유지)
    int time = 0;          // 경과 시간
    int sum = 0;           // 다리 위 트럭 무게 합
    int idx = 0;           // 대기 트럭 인덱스

    // 처음엔 다리 길이만큼 0으로 채워두기
    for (int i = 0; i < bridge_length; i++) {
        bridge.push(0);
    }

    while (!bridge.empty()) {
        time++;

        // 1) 다리 맨 앞칸 제거 (트럭이 있으면 무게에서 빼줌)
        sum -= bridge.front();
        bridge.pop();

        // 2) 아직 대기 트럭이 남아있다면
        if (idx < truck_weights.size()) {
            // 현재 트럭을 올릴 수 있으면
            if (sum + truck_weights[idx] <= weight) {
                bridge.push(truck_weights[idx]);
                sum += truck_weights[idx];
                idx++;
            } else {
                // 못 올리면 빈칸(0)만 올려서 시간 끌기
                bridge.push(0);
            }
        }
    }

    return time;
}
