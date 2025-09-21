#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <climits>


using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> val;
    //str을 한땀한땀 보는데, 공백이면 cotinue아니면 vector에 집어넣어 
    //그리고 atoi를 사용한다
    stringstream ss(s);
    
    int num;
    int max = INT_MIN;
    int min = INT_MAX;
    
    while(ss>>num){
        if (num<min) min = num; 
        if (num>max) max = num;
    }
    
    return to_string(min) + " " + to_string(max);
}