#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
    return EXIT_FAILURE;
  }

  SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 620, 387, SDL_WINDOW_SHOWN);
  if (win == NULL)
  {
    fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
    return EXIT_FAILURE;
  }

  SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (ren == NULL)
  {
    fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
    if (win != NULL)
    {
      SDL_DestroyWindow(win);
    }
    SDL_Quit();
    return EXIT_FAILURE;
  }


  // Good to go
  bool is_running = true;
  while(is_running) {
    SDL_Delay(100);
    SDL_Event event;
    if(SDL_PollEvent(&event)) {
      printf("Got event: %d\n", event.key.keysym.sym);

      if(event.window.event == SDL_WINDOWEVENT_CLOSE) {
        is_running = false;
      }
    }
    
    
  }

  return 0;
}
