#include "raylib.h"
#include "raymath.h"

#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

/* ----------------------------------------------------------------------------
Constants
----------------------------------------------------------------------------- */

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

/* ----------------------------------------------------------------------------
App state
----------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
Functions
----------------------------------------------------------------------------- */

void DrawDemoTriangle(Vector2 a, Vector2 b, Vector2 c)
{
    DrawTriangle(a, b, c, BLUE);
}

void DrawDemo()
{
    Vector2 a = { WINDOW_WIDTH / 2.0, 0 };  // Top
    Vector2 b = { 0, WINDOW_HEIGHT }; // Lower left
    Vector2 c = { WINDOW_WIDTH, WINDOW_HEIGHT }; // Lower right

    DrawDemoTriangle(a, b, c);
}

/**
Program entry point.
*/
int main(void)
{
    /* ------------------------------------------------------------------------
    Initialization
    ------------------------------------------------------------------------- */

    // Scale things for high DPI monitors so we can see it
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);

    // Setup the application window
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Fractals");

    // Set game to run at 60 frames-per-second
    SetTargetFPS(60);

    /* ------------------------------------------------------------------------
    Main loop
    ------------------------------------------------------------------------- */

    while (!WindowShouldClose()) {

        /* ------------------------------------------------------------------------
        Update frame
        ------------------------------------------------------------------------- */

        // TODO : Update stuff here.

        /* ------------------------------------------------------------------------
        Draw frame
        ------------------------------------------------------------------------- */

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // TODO : Draw stuff here.
        DrawDemo();

        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();

    return 0;
}
