#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  // For usleep()

#define WIDTH 80
#define HEIGHT 24

typedef struct {
    int x;
    int y;
} Point;

typedef enum { NONE, BALL, PADDLE } ObjectType;

struct Object {
    ObjectType type;
    Point position;
};

// Function prototypes
void initializeObjects(struct Object *objects);
void drawObjects(struct Object *objects);
void updateObjects(struct Object *objects);
int checkCollision(struct Object *objects);

int main() {
    srand(time(NULL));

    struct Object objects[5];
    initializeObjects(objects);

    while (1) {
        system("clear");  // Use "clear" to clear the terminal in Unix/Linux
        drawObjects(objects);
        updateObjects(objects);
        if (checkCollision(objects)) break;
        usleep(100000);  // Delay for 100 milliseconds (100,000 microseconds)
    }

    printf("Game Over!\n");
    return 0;
}

void initializeObjects(struct Object *objects) {
    objects[0].type = BALL;
    objects[0].position.x = WIDTH / 2;
    objects[0].position.y = HEIGHT - 3;

    objects[1].type = PADDLE;
    objects[1].position.x = WIDTH / 4;
    objects[1].position.y = HEIGHT - 10;

    objects[2].type = PADDLE;
    objects[2].position.x = WIDTH * 3 / 4;
    objects[2].position.y = HEIGHT - 10;

    objects[3].type = NONE;
    objects[3].position.x = rand() % WIDTH;
    objects[3].position.y = rand() % (HEIGHT - 5);

    objects[4].type = NONE;
    objects[4].position.x = rand() % WIDTH;
    objects[4].position.y = rand() % (HEIGHT - 5);
}

void drawObjects(struct Object *objects) {
    for (int i = 0; i < 5; i++) {
        printf("\033[%d;%dH", objects[i].position.y, objects[i].position.x); // Move cursor
        switch (objects[i].type) {
            case BALL:
                printf("O");
                break;
            case PADDLE:
                printf("-");
                break;
            default:
                printf(".");
        }
    }

    // Draw background
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf(" ");
        }
        printf("\n");
    }
}

void updateObjects(struct Object *objects) {
    // Update ball position
    objects[0].position.x += rand() % 3 - 1;
    objects[0].position.y -= 1;

    // Check paddle collision
    if (checkCollision(objects)) return;

    // Bounce ball off edges
    if (objects[0].position.x <= 0 || objects[0].position.x >= WIDTH - 1) {
        objects[0].position.x *= -1;
    }
    if (objects[0].position.y <= 0) {
        objects[0].position.y = HEIGHT - 3;
    }
}

int checkCollision(struct Object *objects) {
    // Check ball collision with paddles
    for (int i = 0; i < 2; i++) {
        if (abs(objects[0].position.x - objects[i + 1].position.x) <= 1 &&
            abs(objects[0].position.y - objects[i + 1].position.y) <= 1) {
            objects[0].position.y = HEIGHT - 3;
            return 1;
        }
    }

    // Check ball collision with other objects
    for (int i = 2; i < 5; i++) {
        if (abs(objects[0].position.x - objects[i].position.x) <= 1 &&
            abs(objects[0].position.y - objects[i].position.y) <= 1) {
            objects[0].position.y = HEIGHT - 3;
            return 1;
        }
    }

    return 0;
}

