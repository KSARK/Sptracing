#include "SDL.h"
#include "Detile/Sphere.hpp"
#include "Detile/Camera_F.hpp"

#include <algorithm>

const int height = 800;
const int width = 800;

SDL_Window* win = nullptr;
SDL_Surface* surface = nullptr;

int init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
        return 1;

    win = SDL_CreateWindow("Sptracing", 100, 100, width, height, SDL_WINDOW_SHOWN);

    if (win == nullptr)
        return 1;

    surface = SDL_GetWindowSurface(win);

    if (surface == nullptr)
        return 2;

    return 0;
}

void Destroy()
{
    SDL_FreeSurface(surface);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

void render_test(Sphere scene, Camera_F camera, int max_depth)
{
    SDL_LockSurface(surface);
    auto pixels = (unsigned char*)surface->pixels;

    camera.initialize();

    float dD=255.0f / max_depth;

    for (int y = 0; y < height; y++)
    {
        float sy = 1 - y * 1.0f / height;
        for (int x = 0; x < width; ++x) {
            float sx = 1 - x * 1.0f / width;
            Ray3 ray = camera.generate_ray(sx, sy);
            Intersect_result result = scene.intersect(ray);
            if (result.geometry)
            {
                auto depth = (unsigned char)( 255 - std::min(result.distance * dD, 255.0f) );
                pixels[4 * (y * surface->w + x) + 0] = depth;
                pixels[4 * (y * surface->w + x) + 1] = depth;
                pixels[4 * (y * surface->w + x) + 2] = depth;
                pixels[4 * (y * surface->w + x) + 3] = 255;
            }
        }
    }

    SDL_UnlockSurface(surface);
    SDL_UpdateWindowSurface(win);
}

int main(int argc, char *argv[])
{

    if (init() != 0)
        return -1;


    render_test(Sphere(Vector3(0, 10, -10), 10),
                Camera_F(Vector3(0, 10, 10), Vector3(0, 0, -1), Vector3(0, 1, 0), 90), 20);

    SDL_Delay(10000);
    Destroy();
    return 0;
}