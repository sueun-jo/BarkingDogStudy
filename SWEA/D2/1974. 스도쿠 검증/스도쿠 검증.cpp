#include <iostream>
#include <map>

using namespace std; 

// 가로, 세로, 3*3 배열 체크 필요함
bool garo (int (&sudoku)[9][9]){
    

    for (int r=0; r<9; r++){
        int check[10] = {0,}; //check용 배열 초기화
        for (int c=0; c<9; c++){
            
            for (int i=1; i<=9; i++){
                if (sudoku[r][c] == i){ // 동일하면
                    check[i] += 1;
                    if (check[i]>1) return false;
                }
            }
        }
    }

    return true;
}

bool sero (int (&sudoku) [9][9]){

    for (int c=0; c<9; c++){
        int check[10] = {0,}; //check용 배열 초기화
        for (int r=0; r<9; r++){

            for (int i=1; i<=9; i++){
                if (sudoku[r][c] == i){
                    check[i] += 1;
                    if (check[i]>1) return false;
                }
            }
        }
    }
    return true;
}

bool box (int (&sudoku) [9][9]){
    
    // 3*3 배열을 옮겨가면서 체크할 수 있을까?

    for (int r=0; r<9; r+=3){
        for (int c=0; c<9; c+=3){

            //박스 체크 시작
            int check [10] = {0, }; //중복체크용
            for (int i=r; i<r+3; i++){
                for (int j=c; j<c+3; j++){
                    for (int k=1; k<=9; k++){
                        if (sudoku[i][j] == k){
                            check[k]++; //증가
                            if (check[k]>1) return false;
                            
                        }
                    }
                }
            }
        }
    }

    return true;
}

int main (){ 

    int t;
     
    cin >> t;

    for (int test=1; test<=t; test++){
        
        int sudoku [9][9] = {0, }; // 스도쿠 배열 초기화

        //스도쿠 채우기
        for (int row=0; row<9; row++){
            for (int col=0; col<9; col++){
                 cin >> sudoku[row][col];
            }
        }
        
        if (garo (sudoku) && sero(sudoku) && box(sudoku)){
            cout << "#" << test << " 1\n";
        } else {
            cout << "#" << test << " 0\n";
        }
    
    } // test case 종료문


    return 0;
}