#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    Display *display = XOpenDisplay(NULL);

    if (!display) {
        printf("Cannot open display\n");
        return 1;
    }

    int screen = DefaultScreen(display);

    Window window = XCreateSimpleWindow(
        display,
        RootWindow(display, screen),
        100, 100,        // Position
        400, 300,        // Größe
        1,               // Border width
        BlackPixel(display, screen),
        WhitePixel(display, screen)
    );

    XSelectInput(display, window, ExposureMask | PointerMotionMask);

    XMapWindow(display, window);

    XEvent event;

    while (1) {
        XNextEvent(display, &event);

        if (event.type == Expose) {
            printf("Expose event\n");
        }

        if (event.type == MotionNotify) {
            printf("Mouse: %d %d\n",
                event.xmotion.x,
                event.xmotion.y
            );
        }
    }

    return 0;
}
