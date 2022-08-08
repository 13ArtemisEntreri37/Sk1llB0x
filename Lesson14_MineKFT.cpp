#include <iostream>
#include <vector>
#include <cmath>
void build(int mineSlhak[][5][10], int x, int y, int bl) {
    for (int i = 0; i < 10; i++) {
        (i < bl) ? mineSlhak[x][y][i] = 1 : mineSlhak[x][y][i] = 0;
    }
}
void apokalipsys(int mineShlak[][5][10]) {
    for (int a = 0; a < 5; a++) {
        for (int b = 0; b < 5; b++) {
            for (int c = 0; c < 10; c++) {
                mineShlak[a][b][c] = 0;
            }
        }
    }
}
void level(int mineSlhak[][5][10], int x) {
    x = 0;
    for (int a = 0; a < 5; a++) {
        for (int b = 0; b < 5; b++) {
            (mineSlhak[a][b][x + 1]) ? std::cout << "1" : std::cout << "0";
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}
int main() {
    int Heigh = 0;
    int count = 0;
    int mineSlhak[5][5][10];
    apokalipsys(mineSlhak);
    while (count < 25) {
        for (int a = 0; a < 5; a++) {
            for (int b = 0; b < 5; b++) {
                std::cout << "Input Heigh for sector # " << a << "," << b << std::endl;
                std::cin >> Heigh;
                if (Heigh > 10 || Heigh < 0) continue;
                build(mineSlhak, a, b, Heigh);
                count++;
            }            
        }
    }
    count = 0;
    for (int a = 0; a < 5; a++) {
        for (int b = 0; b < 5; b++) {
            for (int c = 0; c < 10; c++) {
                if (mineSlhak[a][b][c] != 0)count++;
            }
            std::cout << count << " ";
            count = 0;            
        }
        std::cout << std::endl;
    }
    count = 0;
    std::cout << std::endl;
    std::cout << "Input Level: ";
    std::cout << std::endl;
    std::cin >> count;
    level(mineSlhak, count);
}