#include <iostream>
#include <vector>
#include <cmath>
int main() {
    int snake[5][5];
    int num = 0;
    int config = 1;
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            snake[x][y] = num;
            std::cout << num << " ";
            num += config;
        }
        std::cout << std::endl;
        num += 5 - config;
        config *= -1;
    }  
}
