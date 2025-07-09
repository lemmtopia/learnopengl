#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <glad/glad.h>

#include "external/glad/glad.c"

#include "learn_opengl.h"
#include "my_assert.h"

#include "my_assert.cpp"

globalvar SDL_Window* window;

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    MY_ASSERT(0 == 1);
    return 0;
}
