#include "my_assert.h"

#include <SDL3/SDL_messagebox.h>
#include <stdio.h>

void ReportAssertionFailure(const char* expr, const char* file, int line) {
    char message[MESSAGE_SIZE];

    sprintf_s(
	message,
	MESSAGE_SIZE,
	"File: (%s)\nLine: (%d)\nExpression: (%s)",
	file, line, expr);

    SDL_ShowSimpleMessageBox(
	SDL_MESSAGEBOX_ERROR,
	"Assertion failed!",
	(const char*)message,
	NULL);
}
