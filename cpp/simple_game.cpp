// Simple Console Game: Snake (simplified) in C++
#include <iostream>
#include <deque>
#include <conio.h> // Windows only; for Linux, use ncurses
#include <windows.h>

using namespace std;

struct Point { int x, y; };

int main() {
    const int width = 20, height = 10;
    deque<Point> snake = {{width/2, height/2}};
    Point food = {3, 3};
    char dir = 'd';
    bool game_over = false;
    while (!game_over) {
        // Draw
        system("cls");
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (x == food.x && y == food.y) cout << 'F';
                else {
                    bool body = false;
                    for (auto& s : snake) if (s.x == x && s.y == y) body = true;
                    cout << (body ? 'O' : '.');
                }
            }
            cout << '\n';
        }
        // Input
        if (_kbhit()) {
            char c = _getch();
            if (c == 'w' || c == 'a' || c == 's' || c == 'd') dir = c;
        }
        // Move
        Point head = snake.front();
        if (dir == 'w') head.y--;
        if (dir == 's') head.y++;
        if (dir == 'a') head.x--;
        if (dir == 'd') head.x++;
        if (head.x < 0 || head.x >= width || head.y < 0 || head.y >= height) { game_over = true; break; }
        for (auto& s : snake) if (s.x == head.x && s.y == head.y) { game_over = true; break; }
        snake.push_front(head);
        if (head.x == food.x && head.y == food.y) {
            food.x = rand() % width; food.y = rand() % height;
        } else {
            snake.pop_back();
        }
        Sleep(100);
    }
    cout << "Game Over! Score: " << snake.size() << endl;
    return 0;
}
