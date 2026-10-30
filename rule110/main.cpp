#include <iostream>
#include <vector>
#include <raylib.h>

const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;

int next_gen(int a, int b, int c) {
    if(a==0 && b==0 && c==0) return 0;
    if(a==0 && b==0 && c==1) return 1;
    if(a==0 && b==1 && c==0) return 1;
    if(a==0 && b==1 && c==1) return 1;
    if(a==1 && b==0 && c==0) return 0;
    if(a==1 && b==0 && c==1) return 1;
    if(a==1 && b==1 && c==0) return 1;
    return 0;
}

int main() {
    InitWindow(WIN_WIDTH, WIN_HEIGHT, "rule110ByRegie");
    int n = WIN_WIDTH;
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        std::vector<int> cells(n, 0);
        cells[n-1] = 1;
        for(int y{0}; y<WIN_HEIGHT; y++) {
            if(y>0) {
                std::vector<int> new_cells(n, 0);
                for(int i{0}; i<n; i++) {
                    new_cells[i] = next_gen(cells[(i-1+n)%n], cells[i], cells[(i+1)%n]);
                }
                cells = new_cells;
            }
            for(int x{0}; x<WIN_WIDTH; x++) {
                if(cells[x] == 1) DrawPixel(x, y, BLACK);
            }
        }
        EndDrawing();
    }

    // std::cout << "Hello\n" << std::endl;
    CloseWindow();
}
