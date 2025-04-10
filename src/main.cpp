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

int g_depth = 0; // Depth of recursion

/* ----------------------------------------------------------------------------
Functions
----------------------------------------------------------------------------- */

/**
 * Draw a triangle with a recursive interior triangle. Vertices of the triangle
 * must be in counter-clockwise order.
 * @param a First vertex of the triangle.
 * @param b Second vertex of the triangle.
 * @param c Third vertex of the triangle.
 * @param n Number of recursion levels left to go.
 */
void DrawDemoTriangle(Vector2 a, Vector2 b, Vector2 c, int n)
{
    DrawTriangle(a, b, c, n % 2 ? WHITE : BLUE);

    if (n <= 0)
        return;

    // Find b2
    Vector2 b2 = Vector2Subtract(a, b);
    b2 = Vector2Scale(b2, 1 / 3.0f);
    b2 = Vector2Add(b, b2);

    // Find a2
    Vector2 a2 = Vector2Subtract(c, a);
    a2 = Vector2Scale(a2, 1 / 3.0f);
    a2 = Vector2Add(a, a2);

    // Find c2
    Vector2 c2 = Vector2Subtract(b, c);
    c2 = Vector2Scale(c2, 1 / 3.0f);
    c2 = Vector2Add(c, c2);

    // Recursive call to render interior triangle
    DrawDemoTriangle(a2, b2, c2, n - 1);
}

/**
 * Draws the example triangle recursion.
 */
void DrawDemo()
{
    DrawText("Demo", 10, 10, 14, BLACK);
    DrawText(std::to_string(g_depth).c_str(), 10, 25, 14, BLACK);

    Vector2 a = {WINDOW_WIDTH / 2.0, 0};       // Top
    Vector2 b = {0, WINDOW_HEIGHT};            // Lower left
    Vector2 c = {WINDOW_WIDTH, WINDOW_HEIGHT}; // Lower right

    DrawDemoTriangle(a, b, c, g_depth);
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
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Recursion");

    // Set game to run at 60 frames-per-second
    SetTargetFPS(60);

    /* ------------------------------------------------------------------------
    Main loop
    ------------------------------------------------------------------------- */

    while (!WindowShouldClose()) {

        /* ------------------------------------------------------------------------
        Update frame
        ------------------------------------------------------------------------- */

        if (IsKeyPressed(KEY_LEFT)) {
            g_depth = max(0, g_depth - 1);
        }
        else if (IsKeyPressed(KEY_RIGHT)) {
            g_depth++;
        }

        /* ------------------------------------------------------------------------
        Draw frame
        ------------------------------------------------------------------------- */

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawDemo();

        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();

    return 0;
}
