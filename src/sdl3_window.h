#ifndef SDL3_WINDOW_H
#define SDL3_WINDOW_H

#include "learn_opengl.h"

#include <SDL3/SDL.h>

void initialize_window(void);
void destroy_window(void);

bool32 should_close_window(void);

#endif
