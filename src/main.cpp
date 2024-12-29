#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>

using namespace std;

int main() {
  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;
  SDL_Event e;

  // Init SDL
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);

  bool running = true;

  while (running) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT)
        running = false;
    }

    // Set color to clear
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw white pixel
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawPoint(renderer, 640 / 2, 480 / 2);

    // Draw to screen
    SDL_RenderPresent(renderer);
    SDL_Delay(10000);
  }
  // Exit
  return 0;
}
