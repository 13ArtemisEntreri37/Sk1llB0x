
#include <iostream>
#include <vector>
#include <cmath>

int input(char coord) {
    std::cout << "Input "<< coord <<" coordinate: ";
       for (int a = -1;;) {
        std::cin >> a;
        if (a >= 0 && a <= 9)return a;
        std::cout << "Wrong input! Try again!" << std::endl;
       }
}

char coordNm(char a) {
    a == 'X' ? a = 'Y' : a = 'X';
    return a;
    }

std::string name(std::string a) {
    a == "Player # 1" ? a = "Player # 2" : a = "Player # 1";
    std::cout << std::endl;
    return a;
    }

bool occupiedSm(bool puddle[][10], int x, int y) {
    if (puddle[x][y] == 1)return false;
    else { puddle[x][y] = 1; 
    // рисуем поле для оценки
    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            std::cout << puddle[x][y] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
     return true; }
}

void singleDeckShip(bool puddle[][10], std::string plName) {
    std::cout << plName << " places single-deck ships!" << std::endl;
    char coordName = 'X';
    for (int i = 0; i < 4; i++) {
        int x1, y1;
        std::cout << "Enter the coordinates of the single-deck ship # " << i + 1 << std::endl;
        x1 = input(coordName);
        coordName = coordNm(coordName);
        y1 = input(coordName);
        if (!occupiedSm(puddle, x1, y1)) {
            i--; std::cout << std::endl << "Already occupied!" << std::endl << std::endl; continue;
        }
        else { coordName = coordNm(coordName); }
        }
}
bool linearity(int x1, int y1, int x2, int y2) {
    if (x1 == x2 || y1 == y2) { return true; }
    else { std::cout << std::endl << "The ship is located  diagonally!!!" << std::endl << std::endl;  return false; }
 }

bool shipLenght(int x1, int y1, int x2, int y2, int lenght) {
    if ((abs(y1 - y2) == lenght) || (abs(x1 - x2) == lenght)) { return true; }
    else { std::cout << std::endl  << "Wrong ship lenght!" << std::endl << std::endl; return false; }
    
}

bool occupiedLR(bool puddle[][10], int x1, int y1, int x2, int y2) {
    if (x2 < x1)std::swap(x1, x2);
    if (y2 < y1)std::swap(y1, y2);
    for (int i = x1; i <= x2; i++) {
        for (int k = y1; k <= y2; k++)
            {
            if (puddle[i][k] == 1){std::cout << std::endl << "Already occupied!" << std::endl << std::endl; return false;}
            }
    }
    return true;
}

void shipPlanting(bool puddle[][10], int x1, int y1, int x2, int y2) {
    if (x2 < x1)std::swap(x1, x2);
    if (y2 < y1)std::swap(y1, y2);
    for (int i = x1; i <= x2; i++) {
        for (int k = y1; k <= y2; k++)
        {
            puddle[i][k] = 1;
        }
    }
    // рисуем поле для оценки
    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            std::cout << puddle[x][y] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void manyDeckShip(bool puddle[][10], std::string plName) {
    std::cout << plName << " places many deck's ships!" << std::endl;
    int x1, y1, x2, y2;
    int counter = 1;
    while (counter < 4)
        for (int i = counter; i < 4; i++) {
            int sh = 1;
            for (int o = counter; o < 4; o++, sh++) {
                bool ok = false;
                while (!ok) {
                    char coordName = 'X';
                    std::cout << "Enter the coordinates of the " << i + 1 << " deck's ship # " << sh << std::endl;
                    x1 = input(coordName);
                    coordName = coordNm(coordName);
                    y1 = input(coordName);
                    coordName = coordNm(coordName);
                    x2 = input(coordName);
                    coordName = coordNm(coordName);
                    y2 = input(coordName);
                    if (!linearity(x1, y1, x2, y2))continue;//корабль прямой =)
                    if (!shipLenght(x1, y1, x2, y2, i))continue; //его длина соответствует
                    if (!occupiedLR(puddle, x1, y1, x2, y2))continue;//проверяем, не занято ли поле под корабль
                    shipPlanting(puddle, x1, y1, x2, y2);//расставляем корабли
                    std::cout << "The ship has been planted =)" << std::endl;
                    ok = true;
                }


            }
            counter++;
        }
}

int shot(bool puddle[][10], std::string plName, int damage) {
    int x, y;

    bool hit = true;
    while (hit) {
        hit = false;
        std::cout << plName << " - your turn!!!" << std::endl;
        char coordName = 'X';
        x = input(coordName);
        coordName = coordNm(coordName);
        y = input(coordName);
        if (puddle[x][y]) {
            std::cout << plName << " you hitting the target!" << std::endl;
            damage++;
            hit = true;
            puddle[x][y] = 0;
        }
        else {std::cout << plName << " you missed!" << std::endl;}
                                
         for (int i = 0; i < 10; i++) {
             for (int k = 0; k < 10; k++)
             {
                 std::cout << puddle[i][k] << " ";
             }
             std::cout << std::endl;
         }
         std::cout << std::endl;
         if (damage == 20)break;
    }
    return damage;
}



int main() {
    bool puddle1[10][10]{0};
    bool puddle2[10][10]{0};
    std::string plName = "Player # 1";

    //Расставляем однопалубные корабли.
    singleDeckShip(puddle1, plName);
    plName = (name(plName));
    singleDeckShip(puddle2, plName);
    plName = (name(plName));
    //Расставляем много-палубные корабли.
    manyDeckShip(puddle1, plName);
    plName = (name(plName));
    manyDeckShip(puddle2, plName);
    plName = (name(plName));
    // *** Начинаем воевать ***
    int damage_1 = 0;
    int damage_2 = 0;

    while (damage_1 != 20 && damage_2 != 20) {
        damage_1 += shot(puddle2, plName, damage_2);
        if (damage_1 == 20)continue;
        plName = (name(plName));
        damage_2 += shot(puddle1, plName, damage_1);
        if (damage_1 == 20)continue;
        plName = (name(plName));
    }
    std::cout << plName << " WIN!!!" << std::endl;


    

    
}

    

   

   
     
   
 


