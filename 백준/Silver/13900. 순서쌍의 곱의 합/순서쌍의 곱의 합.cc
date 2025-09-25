#include <iostream>

using namespace std;

long long num[100001]; //초기화
long long pnum[100001]; //
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    
    cin >> n; //숫자 n개

    //누적합 알고리즘
    int sum=0;
    for (int i=0; i<n; i++){
        cin >> num[i];
    }

    for (int i=n-1; i>=0; i--){
        pnum[i-1] = pnum[i] + num[i];
        // cout << pnum[i-1] << "\n";
    }

    long long answer = 0;
    for (int i=0; i<=n-2; i++){
        answer += num[i]*pnum[i];
    }

    cout << answer;

    return 0;
}