#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main (){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 문서 너비는 10 고정이다

    // 테스트 케이스 갯수 t
    // 숫자 n개 (Ci, Ki) 갯수
    // 다음줄부터 n+1줄까지 Ci(알파벳 종류)와 Ki(1~20 사이 정수)가 주어짐 

    // 문제 풀이 방식
    // t, n, c, k를 입력받는다

    // 문제풀이 방식
    // c, k를 입력 받는다 
    
    int test, t;
    int n;
    
    cin >> t;

    char c;
    int k;

    for (int test=1; test<=t; test++){
        cin >> n;
        cout << "#" << test;    
        int flag = 0;
        for (int i=1; i<=n; i++){
            cin >> c >> k; // 문자, 숫자 입력받음

            for (int j=1; j<=k; j++){
                if (flag%10==0) cout << "\n";
                cout << c;
                flag++;
            }
        }
        cout << "\n";
    }

    return 0;
}