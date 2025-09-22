#include <iostream>
#include <vector>
#include <queue>

#define X first
#define Y second

int dx[4] = {1,0,-1, 0};
int dy[4] = {0, 1, 0, -1};


using namespace std;
int main() {

    int n, m; 
    cin >> n >> m; //n이 행갯수 m이 열 갯수

    vector <string> board (n);
    vector <vector<int>> dist (n, vector<int> (m, 0));

    //board 내에서 1이 갈 수 있는 칸
    //0은 벽이다
    for (int i=0; i<n; i++){
        cin >> board[i]; 
        for (int j=0; j<m; j++){
            if (board[i][j]=='1') dist[i][j] = -1; //갈수있는곳 dist에서 -1로 표시
        }
    } //board, dist 채우기

    /*BFS 기본 로직
    1. 시작점을 방문했다고 표시하고 큐에 집어 넣는다.
    2. 큐에서 원소를 꺼내 상하좌우 인접칸에 3번을 수행한다
    3. 해당 칸 이전에 방문했으면 넘어가고, 처음 방문했다면 방문했다고 표시 후 큐에 넣는다
    4. 큐가 빌때까지 반복한다
    
    */
    queue <pair <int, int>> Q; //큐 선언
    dist[0][0] = 1; //시작점 dist를 1로 만든다
    Q.push({0,0}); //시작점 0,0 집어넣는다
    
    while (!Q.empty()){
        auto cur = Q.front();
        if (cur.X == n-1 && cur.Y == m-1) {
            cout << dist[cur.X][cur.Y];
            return 0;
        }
        Q.pop();

        for (int dir=0; dir<4; dir++){
            int nx = cur.X+dx[dir];
            int ny = cur.Y+dy[dir];

            if (nx<0 || nx>=n || ny<0 || ny>=m) continue; //경계검사
            if (dist[nx][ny]>=0) continue; //dist에서 -1만 갈수 있는 곳이다

            dist[nx][ny] = dist[cur.X][cur.Y]+1;
            Q.push({nx, ny});
        }
    } //탐색 종료
    
    
    
    
    
    
    
    
    return 0;
}