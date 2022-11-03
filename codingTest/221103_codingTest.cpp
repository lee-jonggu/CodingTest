#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, AnswerN;         // 테스트 케이스의 수
    int temp, temp2;               // cost 합을 담을 변수
        // 전체 테스트 케이스
        cin >> t; 
        int test_case[t]; 
        

    for (int i=0;i<t;i++) {
        int n,m;                // 게임판의 크기, 이동 카드의 수


        // 게임판의 크기, 이동 카드의 수
        cin >> n >> m; 
        int gameSize = (n-1)*4;
        int countCard[7] = {0,m,m,m,m,m,m};

        // 통행료 배열
        int cost[gameSize];
        for (int i=1;i<gameSize+1;i++)
            cin >> cost[i];

        // 통행료 배열 확인
        for (int i=1;i<gameSize+1;i++)
            cout << cost[i] << " ";
        cout << endl; 

        // 카드가 1로 시작하면
        for (int i=1;i<m+1;i++) {
            AnswerN += cost[i+1];
            countCard[1] = m-1;
            for (int c=2;c<7;c++) {
                if (c==2) {
                    AnswerN += cost[i+1+2];
                    countCard[c] = m-1;
                    for (int c=3;c<7;c++) {
                        if (c==3) {
                            AnswerN += cost[i+1+2+3];
                            countCard[c] = m-1;
                            for (int c=4;c<7;c++) {
                                if (c==4) {
                                    AnswerN += cost[i+1+2+3+4];
                                    countCard[c] = m-1;
                                    for (int c=5;c<7;c++)
                                    if (c==5) {
                                        AnswerN += cost[i+1+2+3+4+5];
                                        countCard[c] = m-1;
                                        for (int c=2;c<7;c++) {
                                            if (countCard[c] != 0) {
                                                if (i+1+2+3+4+5+6 > gameSize) {
                                                    AnswerN = 0;
                                                    AnswerN += cost[(i+1+2+3+4+5+6) - gameSize];
                                                    temp = AnswerN;
                                                } else { AnswerN = 0 ;AnswerN += cost[i+1+2+3+4+5+6]; temp = AnswerN;}
                                            }
                                        }
                                    }
                                    else if (c==6) {
                                        AnswerN += cost[i+1+2+3+4+6];
                                        countCard[c] = m-1;
                                        for (int c=2;c<7;c++) {
                                            if (countCard[c] != 0) {
                                                if (i+1+2+3+4+5+6 > gameSize) {
                                                    AnswerN = 0;
                                                    AnswerN += cost[(i+1+2+3+4+5+6) - gameSize];
                                                } else { AnswerN = 0; AnswerN += cost[i+1+2+3+4+5+6];}
                                            }
                                        }
                                    }
                                    if (temp < AnswerN) {
                                    AnswerN = temp;
                                }
                                }
                                else if (c==5) {
                                    AnswerN += cost[i+1+2+3+5];
                                    countCard[c] = m-1;
                                    if (c==4) {
                                        AnswerN += cost[i+1+2+3+4+5];
                                        countCard[c] = m-1;
                                        if (countCard[6] != 0) {
                                            if ((i+1+2+3+4+5+6) > gameSize) {
                                                AnswerN += cost[(i+1+2+3+4+5+6) - gameSize];
                                                temp2 = AnswerN;
                                            } else { AnswerN += cost[i+1+2+3+4+5+6]; temp2=AnswerN; }
                                        }
                                    }
                                    else if (c==6) {
                                        AnswerN += cost[i+1+2+3+5+6];
                                        countCard[c] = m-1;
                                        if (countCard[4] != 0) {
                                            if ((i+1+2+3+4+5+6) > gameSize) {
                                                AnswerN = 0;
                                                AnswerN += cost[(i+1+2+3+4+5+6) - gameSize];
                                            } else { AnswerN = 0;AnswerN += cost[i+1+2+3+4+5+6];}
                                        }
                                    }
                                    if (temp2 < AnswerN) {
                                        if ( temp2 < temp )
                                        AnswerN = temp2;
                                    }
                                } 
                            }
                        }
                    }
                }
            }
        }
        // if (temp < AnswerN) {
        //     AnswerN = temp;
        // }
        cout << AnswerN;
    }

    // for (int i=0;i<t;i++)
    //     test_case[i] = AnswerN;

    // for (int i=0;i<t;i++)
    //     cout << test_case[i]; 

    return 0;
}

// 1
// 6 1 
// 0 400 300 200 100 500 700 900 500 500 400 300 700 400 800 900 200 300 300 400