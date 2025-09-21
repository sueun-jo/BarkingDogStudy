#include <iostream>
#include <vector>
#include <queue>

#define X first
#define Y second

using namespace std;

vector <vector<int>> board (500, vector<int>(500));
bool vis[500][500];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n, m; //세로n 가로m
    cin >> n >> m; //가로 세로 입력받기
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> board[i][j]; //보드채우기
        }
    } //0은 그림 없는 곳, 1은 그림 있는 곳
    
    int mx = 0; //그림 너비 최대값
    int cnt = 0; //그림 갯수
    
    for (int i=0; i<n; i++){ //세로행 n, 가로행 m
        for (int j=0; j<m; j++){ //i,j를 시작점으로 하고싶음
            if (board[i][j] == 0 || vis[i][j]) continue; //그림이 아니거나 방문한 곳이면 넘김
            
            queue <pair<int,int>> Q; //큐 선언
            vis[i][j] = 1; //방문했다고 표시
            Q.push({i,j}); //큐에 넣음
            cnt++; //그림 수 1 증가: 시작점 찾음

            int area = 0; // 그림 넓이
            while (!Q.empty()){
                
                pair <int, int> cur = Q.front(); Q.pop();
                area++; //젤 앞에 값 집어넣고 꺼내고 area 증가시킴

                for (int dir=0; dir<4; dir++){
                    //상하좌우 좌표값
                    int nx  = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 경계검사
                    if (vis[nx][ny] || board[nx][ny]!=1 ) continue; // 방문했거나 방문할 칸이 아니면 넘김
                    
                    vis[nx][ny] = 1; //방문했다고 표시함
                    Q.push ({nx, ny});
                }
            } // i,j에 대한 bfs 탐색 종료
        mx = max (mx, area); //더 큰거           
        }
    } 
    cout << cnt << "\n";
    cout << mx;
    return 0;
}