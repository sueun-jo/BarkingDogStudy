#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    string str;
    cin >> str;
    
    list<char> editor; // list

    for (char c: str){
        editor.push_back(c);
    }

    int m;
    cin >> m; //명령어 갯수 입력 받음

    auto cursor = editor.end(); //list editor의 끝자리 반환
    
    string cmd;
    while (m){
        m--; //m 하나 줄임
        cin >> cmd; //명령 입력 
        /*디버깅용
        for (char c: editor) cout << c ;
        cout << "\n";
        cout << cmd << " | ";
        if (cursor != editor.end()) {
        cout << "cursor points to: " << *cursor << '\n';
        } else {
            cout << "cursor is at end()\n";
        }
        */
    
        if (cmd == "L"){
            if (cursor == editor.begin()) continue; 
            cursor--; //하나 왼쪽으로 이동함
        } else if (cmd == "D"){
            if (cursor == editor.end() ) continue;
            cursor++; //커서 오른쪽으로 이동
        } else if (cmd == "B"){ //하나 지우기
            if (cursor == editor.begin()) continue; //시작부분에 있으면
            auto erasePos = cursor;
            --erasePos;
            editor.erase(erasePos); //cursor 앞부분에 있는 원소 삭제
        } else if (cmd == "P") {
            char a;
            cin >> a;
            editor.insert(cursor, a);
        }
    }

    for (char c : editor)
        cout << c;
        
    return 0;
}