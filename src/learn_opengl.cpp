// Library includes
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <glad/glad.h>
#include <stdlib.h>

#include "external/glad/glad.c"

// Custom file includes
#include "learn_opengl.h"
#include "my_assert.h"
#include "sdl3_window.h"
#include "sdl3_opengl.h"

#include "my_assert.cpp"
#include "sdl3_window.cpp"
#include "sdl3_opengl.cpp"

void panic_and_abort(const char* title, const char* message) {
    SDL_ShowSimpleMessageBox(
		SDL_MESSAGEBOX_ERROR,
		title,
		message,
		NULL);
    
    // Exit with an error.
    exit(-1);
}

int main(int argc, char* argv[]) {
    initialize_window();
	initialize_opengl();

    // main loop
    while (!should_close_window()) {
		// ...
    }

	destroy_opengl();
    destroy_window();
    return 0;
}
 
