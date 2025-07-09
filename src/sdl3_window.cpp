#include "sdl3_window.h"

globalvar SDL_Window* window;
globalvar SDL_GLContext gl_context;

void set_gl_attributes(void) {

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

    set_gl_attributes();
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
