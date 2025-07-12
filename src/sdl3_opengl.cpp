#include "sdl3_opengl.h"

globalvar SDL_GLContext gl_context;

void set_gl_attributes(void) {
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(
		SDL_GL_CONTEXT_PROFILE_MASK,
		SDL_GL_CONTEXT_PROFILE_CORE);

	#ifdef _DEBUG
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);
	#endif
}

void initialize_opengl(void) {
    set_gl_attributes();

	gl_context = SDL_GL_CreateContext(window);

	if (!gl_context) {
		panic_and_abort("SDL_GL_CreateContext failed!", SDL_GetError());
		exit(-1);
	}

	SDL_GL_MakeCurrent(window, gl_context);

	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
		panic_and_abort("gladLoadGLLoader failed!", "Failed to initialize GLAD!");
		exit(-1);
	}
}

void destroy_opengl(void) {
	SDL_GL_DestroyContext(gl_context);
}
