/*
bool GameOver = false;
    char XO[3][3];
    char gamer_nick = 'X';
    int x;
    int y;
    int cnt = 0;

    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            XO[a][b] = ' ';
        }
    }
    std::cout << "Use the coordinates of 2 digits!" << std::endl;
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            std::cout << a << b << ' ';
        }
        std::cout << std::endl;
    }

    while (!GameOver) {
        std::cout << "Please insert X : " << std::endl;
        std::cin >> x;
        if(std::cin.good() == false) {
            std::cout << "Wrong input! Try again!" << std::endl; continue;
        }
        std::cout << "Please insert Y : " << std::endl;
        std::cin >> y;
            if (x > 2 || x < 0 || y > 2 || y < 0) {
            std::cout << "Wrong input! Try again!" << std::endl; continue;
        }
        if (XO[x][y] != ' ') {
            std::cout << "Wrong input! Try again!" << std::endl; continue;
        }
        else {
            XO[x][y] = gamer_nick;
            cnt++;
        }
        for (int i = 0; i < 3; i++) {
            if ((XO[i][0] == XO[i][1] && XO[i][1] == XO[i][2]) && XO[i][0] != ' ' ||
                (XO[0][i] == XO[1][i] && XO[1][i] == XO[2][i]) && XO[0][i] != ' ') {
                std::cout << "Player >>" << gamer_nick << "<< WIN!";
                GameOver = true;
                break;
            }

        }
        if (!GameOver && cnt == 9) {
            std::cout << "Draw game!"; GameOver = true;
        }

        if (!GameOver) {
            gamer_nick == 'X' ? gamer_nick = 'O' : gamer_nick = 'X';

            std::cout << std::endl;
            std::cout << "Turn: " << cnt << std::endl;
            for (int a = 0; a < 3; a++) {
                for (int b = 0; b < 3; b++) {
                    std::cout << XO[a][b];
                }
                std::cout << std::endl;
            }
        }

    }




*/
/*
{
    int cnt = 5;
    int matrix1[4][4] = {{ 1,2,3,4 },
                         { 4,1,2,3 },
                         { 3,4,1,2 },
                         { 2,3,4,1 }
};
    int matrix2[4][4] = {{ 1,2,3,4 },
                         { 4,1,2,3 },
                         { 3,4,1,2 },
                         { 2,3,4,1 }
    };

    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            if (matrix1[a][b] == matrix2[a][b]){
                if (cnt % 5 != 0) matrix1[a][b] = 0;
                cnt++;
            }
            else
            {
                std::cout << "A difference has been detected!";
                return 0;
            }
        }
    }
    std::cout <<"The matrices are equal!" << std::endl;
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            std::cout << matrix1[a][b];
        }
        std::cout << std::endl;
    }

*/
/*
{
        int cnt = 5;
        int matrix1[4][4] = { { 1,2,3,4 },
                             { 4,1,2,3 },
                             { 3,4,1,2 },
                             { 2,3,4,1 }
        };
        int matrix2[4][4] = { { 1,2,3,4 },
                             { 4,1,2,3 },
                             { 3,4,1,2 },
                             { 2,3,4,1 }
        };

        for (int a = 0; a < 4; a++) {
            for (int b = 0; b < 4; b++) {
                if (matrix1[a][b] == matrix2[a][b]) {
                    if (cnt % 5 != 0) matrix1[a][b] = 0;
                    cnt++;
                }
                else
                {
                    std::cout << "A difference has been detected!";
                    return 0;
                }
            }
        }
        std::cout << "The matrices are equal!" << std::endl;
        for (int a = 0; a < 4; a++) {
            for (int b = 0; b < 4; b++) {
                std::cout << matrix1[a][b];
            }
            std::cout << std::endl;
        }
        */

#include <iostream>
#include <vector>
#include <cmath>

int main(){
     float matrixA[4][4] = { { 1.f, 2.f, 3.f, 4.f},
                            { 5.f, 6.f, 7.f, 8.f},
                            { 9.f,10.f,11.f,12.f},
                            {13.f,14.f,15.f,16.f}
    };
    float VecB[4] = {1.f,2.f,3.f,4.f };
    float VecC[4]{0.f };
    for (int i = 0; i < 4; i++) {
        for (int o = 0; o < 4; o++) {
            VecC[i] += (matrixA[i][o] * VecB[o]);
        }
    }
        for (int a = 0; a < 4; a++) {
            std::cout << VecC[a] << ' ';
        }

    }
