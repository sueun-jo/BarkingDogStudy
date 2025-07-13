#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; //정수 몇개
    cin >> n;

    int v; //찾으려는 정수
    vector <int> arr;
    int x;
    for (int i=0; i<n; i++){
        cin >> x; //x값 입력받음
        arr.push_back(x); //vector v에 x값 집어넣음  
    }

    cin >> v;

    int cnt=0;
    for (auto k: arr){
        if (k==v) cnt++; 
    }
    

    cout << cnt;
    return 0;
}