#pragma once
#include <iostream>
#include <termios.h> // for struct termios and terminal control
#include <unistd.h>  // for usleep() function
#include <stdio.h>

using namespace std;

void gotoXY(int x, int y)
{
    cout << "\033[" << x << ";" << y << "H";
}

void textColor(int colorIndex, bool bold = false)
{
    // ANSI escape codes for text color
    string colorCode;

    // Handle color selection
    switch (colorIndex)
    {
    case 0: // Black
        colorCode = "\033[30m";
        break;
    case 1: // Red
        colorCode = "\033[31m";
        break;
    case 2: // Green
        colorCode = "\033[32m";
        break;
    case 3: // Yellow
        colorCode = "\033[33m";
        break;
    case 4: // Blue
        colorCode = "\033[34m";
        break;
    case 5: // Magenta
        colorCode = "\033[35m";
        break;
    case 6: // Cyan
        colorCode = "\033[36m";
        break;
    case 7: // White
        colorCode = "\033[37m";
        break;
    default:
        // Default to white if colorIndex is out of range
        colorCode = "\033[37m";
        break;
    }

    // Apply bold effect if required
    if (bold)
    {
        colorCode = "\033[1m" + colorCode; // Add bold before color
    }

    cout << colorCode;
}

void showCursor(bool showFlag)
{
    if (showFlag)
    {
        cout << "\033[?25h"; // Show cursor
    }
    else
    {
        cout << "\033[?25l"; // Hide cursor
    }
}