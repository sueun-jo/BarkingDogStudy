#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n; //n입력받음

    long long answer = 0;
    
    // 1 <= n <= 10억 -> 최대 10자리, 10자리 숫자는 딱 1개임
    
    long long arr[11] = {0, };

    arr[1] = 9; //한자릿수의 갯수
    arr[10] =1;
    
    for (int i=2; i<=10; i++){
        arr[i] = arr[i-1]*10;
    }

    // 1. 숫자 입력 받고
    // 2. 몇자리인지 확인해
    
    int cnt = 0;
    int q=n;
    while (q!=0){
        q /= 10;
        cnt++; //자릿수 늘려요
    }

    //cout << "자릿수 " << cnt << "\n";
    
    for (int i=1; i<=cnt-1; i++){
        answer += (i*arr[i]);
        //cout << i << "자릿수" << arr[i] << "개" <<"\n";
    }
    
    //cnt는 자릿수
    
    long long remain = n - (pow(10, cnt-1)-1);
    //cout << "남은값" << remain << "\n";
    
    answer += cnt*remain;

    cout << answer;

    return 0;
}