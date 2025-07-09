#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <glad/glad.h>

#include <stdlib.h>

#include "external/glad/glad.c"

#include "learn_opengl.h"
#include "my_assert.h"

#include "my_assert.cpp"

globalvar SDL_Window* window;

void panic_and_abort(const char* title, const char* message) {
    SDL_ShowSimpleMessageBox(
	SDL_MESSAGEBOX_ERROR,
	title,
	message,
	NULL);
    
    // Exit with an error.
    exit(-1);
}

void initialize_window(void) {
    // Maybe add more init flags?
    uint32 init_flags = SDL_INIT_VIDEO | SDL_INIT_EVENTS;
    if (!SDL_Init(init_flags)) {
	panic_and_abort("SDL_Init failed!", SDL_GetError());
    }

    // Create the window
    uint64 window_flags = SDL_WINDOW_OPENGL;
    window = SDL_CreateWindow(TITLE, WIDTH, HEIGHT, window_flags);
    if (!window) {
	panic_and_abort("SDL_CreateWindow failed!", SDL_GetError());
    }
}

void destroy_window(void) {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool32 should_close_window(void) {
    SDL_Event ev;
    while (SDL_PollEvent(&ev)) {
	if (ev.type == SDL_EVENT_QUIT) return TRUE;
    }

    return FALSE;
}

int main(int argc, char* argv[]) {
    initialize_window();

    // main loop
    while (!should_close_window()) {
	// ...
    }

    destroy_window();
    return 0;
}
