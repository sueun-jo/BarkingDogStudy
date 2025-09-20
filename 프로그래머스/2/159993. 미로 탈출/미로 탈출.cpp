#include <string>
#include <vector>
#include <queue>

#define X first
#define Y second

using namespace std;


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int bfs (vector<string>& board, pair<int, int> start, pair<int, int> target){
    int line = board.size();
    int col = board[0].size();
    
    int dist[100][100] = {0, };
    
    for (int i=0; i<line; i++){
        for (int j=0; j<col; j++){
            if (board[i][j] != 'X')
                dist[i][j] = -1; //갈수있는곳 설정
        }
    }
    
    queue <pair<int, int>> Q; //큐 선언
    
    dist[start.X][start.Y] = 0;
    Q.push(start); //시작지점 큐에 넣기
    
    while (!Q.empty()){
        auto cur = Q.front();
        if (cur == target) return dist[cur.X][cur.Y];
        Q.pop();
        
        for (int dir=0; dir<4; dir++){
            
            int nx = cur.X+dx[dir];
            int ny = cur.Y+dy[dir];
            
            if (nx<0 || nx>=line || ny<0 || ny >= col) continue;
            if (dist[nx][ny]>=0) continue;
            
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
            Q.push({nx, ny});
        }
            
    } //bfs 탐색종료
    
    return -1; //못찾으면 -1

} //bfs함수 종료

int solution(vector<string> maps) {
    int answer = 0;
    pair <int, int> start, lev, exit;
    
    for (int i=0; i<maps.size(); i++){
        for (int j=0; j<maps[0].size(); j++){
            if (maps[i][j] == 'S'){
                start = {i, j}; //start 좌표저장
            }
            if (maps[i][j] == 'L'){
                lev = {i, j}; // lev 좌표 저장
            }
            if (maps[i][j] == 'E'){ 
                exit = {i, j}; // exit 좌표 저장
            }
        }
    } // 좌표값 찾고 dist 저장
    
    int dist1 = bfs(maps, start, lev);
    int dist2 = bfs(maps, lev, exit);
    if (dist1==-1 || dist2 == -1)  {
        answer = -1;
        return answer;
    } else return dist1+dist2;
}