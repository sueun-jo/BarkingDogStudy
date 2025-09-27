#include <iostream>
#include <vector>
#include <queue>

#define X first
#define Y second

using namespace std;

int dx[4] = {1,0,-1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; // 세로 가로

    cin >> n >> m;
    vector <vector<int>> board  (n, vector<int> (m, 0));
    vector <vector<int>> vis (n, vector<int> (m,0));

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> board[i][j];
            if (board[i][j]==1) vis[i][j]=-1; //갈수있는 곳 표시
        }
    } 

    queue <pair <int, int>> Q; // 큐 선언

    int cnt = 0; // 그림 갯수
    int mx = 0; //넓이 최대

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (board[i][j]==1 && vis[i][j]==-1){ //그림칸 도착
                vis[i][j]=1; //방문했다고 표시
                Q.push({i,j}); //시작점 넣기
                cnt++; //그림 갯수 증가
                
            }
            int area = 0;
            while (!Q.empty()){
                auto cur = Q.front();
                Q.pop(); area++; //넓이 값 늘리기

                //네 방향 확인
                for (int dir=0; dir<4; dir++){

                    int nx = cur.X+dx[dir];
                    int ny = cur.Y+dy[dir];

                    if (nx<0 || nx >=n || ny < 0 || ny >=m ) continue; // 경계
                    if (vis[nx][ny]>=0) continue;

                    vis[nx][ny]=1; //방문했다고 표시
                    Q.push({nx,ny}); //집어넣음 
                }
            } //bfs 탐색 종료

            if (area>=mx) mx = area;
        }
    }

    cout << cnt << "\n" << mx;
    

    return 0;
}