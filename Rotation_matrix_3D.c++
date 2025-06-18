#include <stdio.h>
#include <math.h>
#include <windows.h>

#define PI 3.14159265

typedef struct {
    float x, y, z;
} Vec3;

typedef struct {
    float x, y;
} Vec2;

Vec3 rotateX(Vec3 p, float theta) { // rotation maxtrix 3D
    return (Vec3){
        .x = p.x,
        .y = p.y * cos(theta) - p.z * sin(theta),
        .z = p.y * sin(theta) + p.z * cos(theta)
    };
}

Vec3 rotateY(Vec3 p, float theta) {
    return (Vec3){
        .x = p.x * cos(theta) + p.z * sin(theta),
        .y = p.y,
        .z = -p.x * sin(theta) + p.z * cos(theta)
    };
}

Vec3 rotateZ(Vec3 p, float theta) {
    return (Vec3){
        .x = p.x * cos(theta) - p.y * sin(theta),
        .y = p.x * sin(theta) + p.y * cos(theta),
        .z = p.z
    };
}

Vec2 project(Vec3 p) { // 3차원 좌표를 2차원으로 투영하줌 정사영 방법으로 
    Vec2 r;
    float scale = 10.0f;
    r.x = p.x * scale + 40;
    r.y = p.y * scale + 12;
    return r;
}

void drawLine(char canvas[25][80], int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (1) {
        if (x0 >= 0 && x0 < 80 && y0 >= 0 && y0 < 25)
            canvas[y0][x0] = '*';
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx) { err += dx; y0 += sy; }
    }
}

void clearCanvas(char canvas[25][80]) {
    for (int y = 0; y < 25; y++)
        for (int x = 0; x < 80; x++)
            canvas[y][x] = ' ';
}

void renderCanvas(char canvas[25][80]) {
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 80; x++)
            putchar(canvas[y][x]);
        putchar('\n');
    }
}

int main() {
    Vec3 cube[8] = { // 꼭짓점 좌표 
        {-1, -1, -1}, {1, -1, -1},
        {1,  1, -1}, {-1, 1, -1},
        {-1, -1,  1}, {1, -1, 1},
        {1,  1,  1}, {-1, 1, 1}
    };

    int edges[12][2] = { // 모서리 어떤 어떤선을 이여야 하는지 
        {0,1}, {1,2}, {2,3}, {3,0},  // back face
        {4,5}, {5,6}, {6,7}, {7,4},  // front face
        {0,4}, {1,5}, {2,6}, {3,7}   // sides
    };

    float angle = 0;

    while (1) {
        char canvas[25][80];
        clearCanvas(canvas);

        Vec2 projected[8];
        for (int i = 0; i < 8; i++) {
            Vec3 p = cube[i];
            p = rotateX(p, angle);
            p = rotateY(p, angle);
            p = rotateZ(p, angle);
            projected[i] = project(p);
        }

        for (int i = 0; i < 12; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            drawLine(canvas,
                     (int)projected[a].x, (int)projected[a].y,
                     (int)projected[b].x, (int)projected[b].y);
        }

        system("cls");
	        renderCanvas(canvas);
	
	        angle += 0.05f;
	        Sleep(0.1);
	    }
	
	    return 0;
	}
