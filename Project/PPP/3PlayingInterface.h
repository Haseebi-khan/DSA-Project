#pragma once
#include <iostream>
#include "1UI.h"
void box()
{
    showCursor(true);
    // left line
    for (int i = 4; i < 16; i++)
    {
        textColor(2); // Set text color to Blue (colorIndex 4)
        gotoXY(i, 2);
        cout << "|";
        // Inner left
        if (i >= 5)
        {
            gotoXY(i, 11);
            cout << "|";
        }
    }
    // Upper line
    for (int i = 2; i < 30; i++)
    {
        textColor(2); // Set text color to Blue (colorIndex 4)
        gotoXY(4, i);
        cout << "-";
        // Inner Upper
        if (i >= 3)
        {
            if (i == 11 || i == 20 || i == 29)
            {
                continue;
            }
            else
            {
                gotoXY(8, i);
                cout << "-";
            }
        }
    }
    // Right line
    for (int i = 5; i < 16; i++)
    {
        textColor(2); // Set text color to Blue (colorIndex 4)
        gotoXY(i, 29);
        cout << "|";
        // Inner Right
        if (i >= 5)
        {
            gotoXY(i, 20);
            cout << "|";
        }
    }
    // Lower line
    for (int i = 2; i < 30; i++)
    {
        textColor(2); // Set text color to Blue (colorIndex 4)
        gotoXY(16, i);
        cout << "-";
        // Inner Lower
        if (i >= 3)
        {
            if (i == 11 || i == 20 || i == 29)
            {
                continue;
            }
            else
            {
                gotoXY(12, i);
                cout << "-";
            }
        }
    }
    cout << endl;

    showCursor(false);
    textColor(4, true);

    gotoXY(6, 6);
    cout << "1";
    gotoXY(6, 15);
    cout << "2";
    gotoXY(6, 24);
    cout << "3";

    gotoXY(10, 6);
    cout << "4";
    gotoXY(10, 15);
    cout << "5";
    gotoXY(10, 24);
    cout << "6";

    gotoXY(14, 6);
    cout << "7";
    gotoXY(14, 15);
    cout << "8";
    gotoXY(14, 24);
    cout << "_";
}
