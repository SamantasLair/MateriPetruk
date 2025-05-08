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
    int rows = 0;
    int cols = 0;

    void errorWorld(string errMsg) { //Mengeluarkan world dan pesan errornya
        cerr << "Error : "<< errMsg << endl;
        cerr << "Dunia sebelum error : " << endl;
        (*world)[posY][posX] = painterChar[painterDirection];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cerr << (*world)[i][j] << ' ';
            }
            cerr << endl;
        }
        cerr << endl;

    }

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
        if (world != nullptr) {
            rows = world->size();
            cols = world->at(0).size();
        } else {
            std::cerr << "Error: pointer ke null" << std::endl;
        }
    }

    

    void move() {
        if (world != nullptr)
            if (isFrontClear())
                switch(painterDirection) {
                    case 0: posX++; break;
                    case 1: posY++; break;
                    case 2: posX--; break;
                    case 3: posY--; break;
                }
            else {
                errorWorld("Tidak dapat maju karena terhalang");
                exit(0);
            }
        else cerr << "Tidak ada world yang terbaca" << endl;

    }

    int getX() { return this->posX; }
    int getY() { return this->posY; }

    void turnLeft() { painterDirection = (painterDirection + 3) % 4; }
    void paint() {
        if (world != nullptr) {
            (*world)[posY][posX] = '@';
        }
    }
    void putWall() {
        if (world != nullptr ) {
            if (isFrontClear())
            switch(painterDirection) {
                case 0: (isFrontClear()) ? (*world)[posY][posX + 1] = '#' : (*world)[posY][posX] = '#'; break;
                case 1: (isFrontClear()) ? (*world)[posY + 1][posX] = '#' : (*world)[posY][posX] = '#'; break;
                case 2: (isFrontClear()) ? (*world)[posY][posX - 1] = '#' : (*world)[posY][posX] = '#'; break;
                case 3: (isFrontClear()) ? (*world)[posY - 1][posX] = '#' : (*world)[posY][posX] = '#'; break;
            }
            else cerr << "Front is not clear" << endl;
        }
    }
    bool isFrontClear() {
        switch(painterDirection) {
            case 0: return (posX + 1 < cols && (*world)[posY][posX + 1] != '#');
            case 1: return (posY + 1 < rows && (*world)[posY + 1][posX] != '#');
            case 2: return (posX - 1 >= 0 && (*world)[posY][posX - 1] != '#');
            case 3: return (posY - 1 >= 0 && (*world)[posY - 1][posX] != '#');
        }
        return false;
    }

    void cleanPaint() {
        if (world != nullptr){
            (*world)[posY][posX] = '.';
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
painter codeBlock(painter p) {
    // Kode kamu disini

    
    return p;
}

void setup(vector<vector<char>>& world) {
    for (int i = 0; i < world.size(); i++) {
        for (int j = 0; j < world[i].size(); j++) {
            if (i == 5)
            world[i][j] = '.';
        }
    }
}

void printWorld(vector<vector<char>>& world, painter& p) {
    // for (int i = 0; i < sizeX +2; i++) {
    //     cout << "- ";
    // }
        p.paint();
    p.move();
    p.turnLeft();
    p.turnLeft();
    p.turnLeft();
    p.move();
    p.paint();
    p.move();
    p.paint();
    p.move();
    p.paint();
        p.paint();
    p.move();
    p.turnLeft();
    p.turnLeft();
    p.turnLeft();
    p.move();
    p.paint();
    p.move();
    p.paint();
    p.move();
    p.paint();
        p.paint();
    p.move();
    p.turnLeft();
    p.turnLeft();
    p.turnLeft();
    p.move();
    p.paint();
    p.move();
    p.paint();
    p.move();
    p.paint();
    world[p.getY()][p.getX()] = p.painterChar[p.painterDirection];
    for (int i = 0; i < world.size(); i++) {
        cout << "| ";
        for (int j = 0; j < world[i].size(); j++) {
            cout << world[i][j] << ' ';
        }
        cout << "|";
        cout << endl;
    }
    // for (int i = 0; i < sizeX +2; i++) {
    //     cout << "- ";
    // }
}

void paintWorld(int sizeX, int sizeY, painter& p) {
    vector<vector<char>> world(sizeY, vector<char>(sizeX, '.'));
    setup(world);
    p.setWorld(&world); // Pass the world to class
    cout << "World setup :" << endl;
    printWorld(world, p);
    cout << endl << "World kamu :" << endl;
    printWorld(world, p);
    p = codeBlock(p);

}

int main() {
    int sizeX = 20;
    int sizeY = 10;
    painter p(0, 0);

    paintWorld(sizeX, sizeY, p);
    return 0;
}

// @author : Samanta