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

    public :
        int painterDirection=0;
        char painterChar[4] = {'>', 'v', '<', '^'};
        painter(int posX = 0, int posY = 0) {
            this->posX = posX;
            this->posY = posY;
        }

        void move(){
            switch(painterDirection){
                case 0 : posX++; break;
                case 1 : posY++; break;
                case 2 : posX--; break;
                case 3 : posY--; break;
            }
        }

        int getX() { return this->posX; }
        int getY() { return this->posY; }

        void turnLeft() { painterDirection = (painterDirection + 3) % 4; }

};
/*
Note :
Now it need to have a method that will paint the world,
it will use '#' for wall and '.' for empty space,
the problem is, if i use the method from painter object,
it will make matters complicated as it need to access theWorld array
*/
void paint(int sizeX, int sizeY, painter p) {
    int x = p.getX();
    int y = p.getY();
    
    char theWorld[sizeY][sizeX];
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            theWorld[i][j] = '.';
        }
    }
    theWorld[y][x] = p.painterChar[p.painterDirection];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << theWorld[i][j]<<' ';
        }
        cout << endl;
    }
}

int main() {
    int sizeX, sizeY;
    //cin >> sizeX >> sizeY;
    sizeX = 10;
    sizeY = 10;
    painter p(0, 0);
    p.move();
    p.turnLeft();
    p.turnLeft();
    p.turnLeft();
    p.move();
    p.move();

    paint(sizeX, sizeY, p);
    return 0;
}