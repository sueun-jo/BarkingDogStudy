#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int students[6][2] = {0,}; //초기화
    int n, k;
    cin >> n >> k; //참가 명수와 최대 인원 수 per room 입력 받음

    int gender, grade;

    /*성별, 학년 별로 2차원 배열 채우기*/
    for (int i=0; i<n; i++){ 
        cin >> gender >> grade; //성별, 학년 입력 받기
        if (gender==0){ //여학생인 경우
            students[grade-1][0] += 1;
        } else { //남학생인 경우
            students[grade-1][1] += 1;
        }
    }

    int room = 0; //방 갯수
    int x=0; //학생 수
    
    for (int i=0; i<grade; i++){
        for (int j=0; j<2; j++){
            x = students[i][j];
            if (x==0) continue;
            else if (x<=k) room++;
            else room += x/k + 1;
        }
    }

    cout << room;

    return 0;
}