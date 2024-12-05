#include <iostream>
using namespace std;

int main() {
    
    string s = "asdasd";
    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i] << " ";
    }
    
    
    
    cout << endl;
    return 0;
}
// #include <iostream>
// #include <X11/Xlib.h>
// #include <GL/gl.h>
// #include <GL/glx.h>
// #include <X11/Xutil.h>
// #include <cstdio>

// int main()
// {
//     Display *display = XOpenDisplay(NULL);
//     if (display == NULL)
//     {
//         fprintf(stderr, "Unable to open display\n");
//         return 1;
//     }

//     Window root = DefaultRootWindow(display);
//     int screen = DefaultScreen(display);

//     // Obtain an appropriate visual
//     GLint att[] = {GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None};
//     XVisualInfo *vi = glXChooseVisual(display, 0, att);
//     if (vi == NULL)
//     {
//         fprintf(stderr, "No appropriate visual found\n");
//         return 1;
//     }

//     // Create a colormap
//     Colormap cmap = XCreateColormap(display, root, vi->visual, AllocNone);

//     XSetWindowAttributes swa;
//     swa.colormap = cmap;
//     swa.event_mask = ExposureMask | KeyPressMask;

//     Window win = XCreateWindow(display, root, 100, 100, 800, 600, 0, vi->depth, InputOutput, vi->visual, CWColormap | CWEventMask, &swa);

//     XMapWindow(display, win);
//     XStoreName(display, win, "Learn GDI");

//     Atom wm_delete_window = XInternAtom(display, "WM_DELETE_WINDOW", False);
//     XSetWMProtocols(display, win, &wm_delete_window, 1);

//     GLXContext glc = glXCreateContext(display, vi, NULL, GL_TRUE);
//     glXMakeCurrent(display, win, glc);

//     // Set up OpenGL
//     glClearColor(0.0, 0.0, 0.0, 1.0); // Black background

//     XEvent event;
//     while (1)
//     {
//         XNextEvent(display, &event);

//         if (event.type == Expose)
//         {
//             glClear(GL_COLOR_BUFFER_BIT);

//             // Draw a red rectangle
//             glColor3f(1.0, 0.0, 0.0);
//             glBegin(GL_QUADS);
//             glVertex2f(-0.5, -0.5);
//             glVertex2f(0.5, -0.5);
//             glVertex2f(0.5, 0.5);
//             glVertex2f(-0.5, 0.5);
//             glEnd();

//             glXSwapBuffers(display, win);
//         }
//         else if (event.type == ClientMessage)
//         {
//             if ((Atom)event.xclient.data.l[0] == wm_delete_window)
//             {
//                 // Exit the loop when the window close event is detected
//                 break;
//             }
//         }
//     }

//     glXDestroyContext(display, glc);
//     XDestroyWindow(display, win);
//     XCloseDisplay(display);

//     return 0;
// }

// // #include <GL/gl.h>
// // #include <GL/glx.h>
// // #include <X11/Xlib.h>
// // #include <iostream>

// // int main() {
// //     Display* display = XOpenDisplay(NULL);
// //     if (!display) {
// //         std::cerr << "Unable to open X display.\n";
// //         return 1;
// //     }
// //     std::cout << "X display opened successfully.\n";
// //     XCloseDisplay(display);
// //     return 0;
// // }