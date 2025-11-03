#include <stdint.h>

#include "utils.h"

void convolve(const uint8_t input[LAYERS][HEIGHT][WIDTH],
              const int8_t filter[3][3],
              int32_t output[LAYERS][HEIGHT][WIDTH]) {
    // TO BE IMPROVED BY STUDENTS

    // clear output
    int nx, ny;
    for (unsigned c = 0; c < LAYERS; c++) {
        for (unsigned y = 0; y < HEIGHT; y++) {
            for (unsigned x = 0; x < WIDTH; x++) {
                output[c][y][x] = 0;
                for (short j = 0; j < 3; j++) {
                    ny = y+j-1;
                    if (ny >= 0 && ny < HEIGHT) {
                        for (short i = 0; i < 3; i++) {
                            nx = x+i-1;
                            if (nx >= 0 && nx < WIDTH) {
                                output[c][y][x] += ((int32_t)input[c][ny][nx]) * filter[i][j];
                            }
                        } 
                    }
                }
            }
        }
    }

    /*
    // top left pixel
    for (unsigned x = 0; x < WIDTH; x++) {
        for (unsigned y = 0; y < HEIGHT; y++) {
            for (unsigned c = 0; c < LAYERS; c++) {
                if (x != 0 && y != 0)
                    output[c][y][x] += ((int32_t)input[c][y - 1][x - 1]) * filter[0][0];
            }
        }
    }

    // top pixel
    for (unsigned x = 0; x < WIDTH; x++) {
        for (unsigned y = 0; y < HEIGHT; y++) {
            for (unsigned c = 0; c < LAYERS; c++) {
                if (y != 0)
                    output[c][y][x] += ((int32_t)input[c][y - 1][x]) * filter[0][1];
            }
        }
    }

    // top right pixel
    for (unsigned x = 0; x < WIDTH; x++) {
        for (unsigned y = 0; y < HEIGHT; y++) {
            for (unsigned c = 0; c < LAYERS; c++) {
                if (x != WIDTH - 1 && y != 0)
                    output[c][y][x] += ((int32_t)input[c][y - 1][x + 1]) * filter[0][2];
            }
        }
    }

    // left pixel
    for (unsigned x = 0; x < WIDTH; x++) {
        for (unsigned y = 0; y < HEIGHT; y++) {
            for (unsigned c = 0; c < LAYERS; c++) {
                if (x != 0)
                    output[c][y][x] += ((int32_t)input[c][y][x - 1]) * filter[1][0];
            }
        }
    }

    // center pixel
    for (unsigned x = 0; x < WIDTH; x++) {
        for (unsigned y = 0; y < HEIGHT; y++) {
            for (unsigned c = 0; c < LAYERS; c++) {
                output[c][y][x] += ((int32_t)input[c][y][x]) * filter[1][1];
            }
        }
    }

    // right pixel
    for (unsigned x = 0; x < WIDTH; x++) {
        for (unsigned y = 0; y < HEIGHT; y++) {
            for (unsigned c = 0; c < LAYERS; c++) {
                if (x != WIDTH - 1)
                    output[c][y][x] += ((int32_t)input[c][y][x + 1]) * filter[1][2];
            }
        }
    }

    // bottom left pixel
    for (unsigned x = 0; x < WIDTH; x++) {
        for (unsigned y = 0; y < HEIGHT; y++) {
            for (unsigned c = 0; c < LAYERS; c++) {
                if (x != 0 && y != HEIGHT - 1)
                    output[c][y][x] += ((int32_t)input[c][y + 1][x - 1]) * filter[2][0];
            }
        }
    }

    // bottom pixel
    for (unsigned x = 0; x < WIDTH; x++) {
        for (unsigned y = 0; y < HEIGHT; y++) {
            for (unsigned c = 0; c < LAYERS; c++) {
                if (y != HEIGHT - 1)
                    output[c][y][x] += ((int32_t)input[c][y + 1][x]) * filter[2][1];
            }
        }
    }

    // bottom right pixel
    for (unsigned x = 0; x < WIDTH; x++) {
        for (unsigned y = 0; y < HEIGHT; y++) {
            for (unsigned c = 0; c < LAYERS; c++) {
                if (x != WIDTH - 1 && y != HEIGHT - 1)
                    output[c][y][x] += ((int32_t)input[c][y + 1][x + 1]) * filter[2][2];
            }
        }
    }
    */
}
