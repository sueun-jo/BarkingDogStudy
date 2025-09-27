#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

int dx[6] = {1, 0,-1, 0, 0, 0}; 
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1}; //상하좌우위아래

int board[100][100][100];
int dist[100][100][100];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, n, h; //m가로 n세로 h높이
    cin >> m >> n >> h;

    queue <tuple<int,int,int>> Q;

    int cnt = 0;
    for (int k=0; k<h; k++) //높이
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++){
                cin >> board[k][i][j];
                if (board[k][i][j]==0) {dist[k][i][j]= -1; cnt++;}//안익은 토마토
                if (board[k][i][j]==1) Q.push({k,i,j}); //시작점 넣어
            }

    if (cnt==0){ cout << 0; return 0;} //안익은 토마토 없으면 0출력하고 종료
    
    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();

        for (int dir=0; dir<6; dir++){
            //tuple {높이, 행, 열}
            int nx = get<1>(cur)+dx[dir];
            int ny = get<2>(cur)+dy[dir];
            int nz = get<0>(cur)+dz[dir];

            if (nx<0||nx>=n||ny<0||ny>=m||nz<0||nz>=h) continue; //경계검사
            if (dist[nz][nx][ny]!=-1) continue; //넘어가
            dist[nz][nx][ny]=dist[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
            Q.push({nz, nx, ny});
        }
                
    } //bfs 종료

    int answer = 0;
    for (int k=0; k<h; k++)
        for(int i=0; i<n; i++)
            for (int j=0; j<m; j++){
                if (dist[k][i][j]==-1){ cout << -1; return 0;} //안익은 토마토 있으면 -1 출력
                answer = max(answer, dist[k][i][j]); 
            }

    cout << answer;
    return 0;
}