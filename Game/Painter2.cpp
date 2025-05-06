#include <iostream>
#include <vector>

using namespace std;
/*
NOTE :
I need to make a class that will become a blueprint for the tiny painter,
that will be used in structured programming lesson.
*/
class painter {
private:
    int posX, posY;
    vector<vector<char>>* world; 

public:
    int painterDirection = 0;
    char painterChar[4] = {'>', 'v', '<', '^'};
    
    painter(int posX = 0, int posY = 0, vector<vector<char>>* world = nullptr) {
        this->posX = posX;
        this->posY = posY;
        this->world = world;
    }

    void setWorld(vector<vector<char>>* world) {
        this->world = world;
    }

    void move() {
        switch(painterDirection) {
            case 0: posX++; break;
            case 1: posY++; break;
            case 2: posX--; break;
            case 3: posY--; break;
        }
    }

    int getX() { return this->posX; }
    int getY() { return this->posY; }

    void turnLeft() { painterDirection = (painterDirection + 3) % 4; }
    void turnRight() { painterDirection = (painterDirection + 1) % 4; }
    void paint() {
        if (world != nullptr) {
            (*world)[posY][posX] = '#';
        }
    }
};
/*
Note :
Now it need to have a method that will paint the world,
it will use '#' for wall and '.' for empty space,
the problem is, if i use the method from painter object,
it will make matters complicated as it need to access theWorld array,
fuck it we gonna make it work with pointer
*/
painter codeBlock(painter p, vector<vector<char>>& world) {
    for (int i = 0; i < 5; i++){
        p.paint();
        p.move();
        p.turnRight();
        p.move();
        p.turnLeft();
    }
    return p;
}

void paintWorld(int sizeX, int sizeY, painter& p) {
    vector<vector<char>> world(sizeY, vector<char>(sizeX, '.'));
    p.setWorld(&world); // Pass the world to class
    p = codeBlock(p, world);

    world[p.getY()][p.getX()] = p.painterChar[p.painterDirection];
    
    // Print the world
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            cout << world[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    int sizeX = 10;
    int sizeY = 10;
    painter p(0, 0);

    paintWorld(sizeX, sizeY, p);
    return 0;
}