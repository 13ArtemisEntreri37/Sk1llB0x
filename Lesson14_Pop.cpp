#include <iostream>
#include <vector>
#include <cmath>
int pop = 144;
void fromChina(bool chpok[][12]) {
    for (int a = 0; a < 12; a++) {
        for (int b = 0; b < 12; b++) {
            chpok[a][b] = true;
        }
    }
};
void chpokShow(bool chpok[][12]) {
    for (int a = 0; a < 12; a++) {
        for (int b = 0; b < 12; b++) {
            (chpok[a][b]) ? std::cout << "O" : std::cout << "X";
            std::cout << " ";
        }
        std::cout << std::endl;
    }
};
int input(int c) {
    while (1) {
        std::cin >> c;
        if (c < 0 || c > 11) {
            std::cout << "Wrong input! Try again!" << std::endl; continue;
        }
        return c;
    }
}
void chpoking(bool chpok[][12], int a, int b, int c, int d) {
    for (int x = a; x <= c; x++) {
        for (int y = b; y <= d; y++) {
            if (chpok[x][y]) {
                pop -= 1;
                std::cout << "Pop!" << std::endl;
                chpok[x][y] = false;
            }
        }
    }

}
int main() {
    
    bool chpok[12][12];
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
     fromChina(chpok); // Надуваем пупырки
     while (pop > 0) {
         chpokShow(chpok); // Выводим на экран
         std::cout << "Input Start pos: " << std::endl;
         x1 = input(x1);
         y1 = input(y1);
         std::cout << "Input End pos: " << std::endl;
         x2 = input(x2);
         y2 = input(y2);
         chpoking(chpok, x1, y1, x2, y2);
         std::cout << std::endl;
         
         
     }
  

   

   
}