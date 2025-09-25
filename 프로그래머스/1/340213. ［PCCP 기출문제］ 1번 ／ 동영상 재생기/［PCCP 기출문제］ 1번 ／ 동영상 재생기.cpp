#include <string>
#include <vector>
#include <iostream>

using namespace std;

int calc_time (string &str){
    
    int min = ((str[0]-'0')*10+(str[1]-'0'))*60;
    int sec = (str[3]-'0')*10+str[4]-'0';
    
    return min+sec;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> cmd) {
    // 풀이방법
    // video_len의 수를 읽어서 숫자로 변경해서 계산하면 어떨까
    
    int min=0;
    int sec=0;
    
    // min = ((video_len[0]-'0')*10+(video_len[1]-'0'))*60; //3분이면 180초
    // sec = (video_len[3]-'0')*10+video_len[4]-'0'; // 초 계산
    int total_sec = calc_time(video_len);
      
    int pos_sec = calc_time(pos);
    
    int op_start_sec = calc_time(op_start);
    
    int op_end_sec = calc_time(op_end);
    
    int c = cmd.size();
    
    for (int i=0; i<c; i++){
        //오프닝인지 먼저 확인
        if (op_start_sec<=pos_sec && pos_sec<=op_end_sec){
            pos_sec=op_end_sec;
        }
        
        if (cmd[i]=="prev"){
            if (pos_sec<10) pos_sec=0;
            else pos_sec -= 10;
            
        } else if (cmd[i]=="next"){
            if(total_sec-pos_sec<10) pos_sec = total_sec;
            else pos_sec += 10;
        }
        
        //오프닝인지 확인
        if (op_start_sec<=pos_sec && pos_sec<=op_end_sec){
            pos_sec=op_end_sec;
        }
        cout << video_len << " " << pos << " "<< op_start << "~" << op_end << " " << cmd[i] << "\n";
    } //for문 종료
    
    string answer = "mm:ss";
    
    //pos_sec을 다시 분:초로 변환한다 
    min = pos_sec/60;
    sec = pos_sec%60;
    
    answer[0] = min/10 + '0';
    answer[1] = min%10 + '0';
    answer[3] = sec/10 + '0';
    answer[4] = sec%10 + '0';    
    
    
    return answer;
}