
#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>

int app_main()
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
  uint32_t ticks_frame_start;
  uint32_t ticks_frame_used;
  uint32_t ticks_pr_frame = 1000 / 60;
  bool is_running = true;
  SDL_Event event;
  while (is_running)
  {
    ticks_frame_start = SDL_GetTicks();
    // Process all events
    while (SDL_PollEvent(&event))
    {
      printf("Got event: %d\n", event.key.keysym.sym);
      // Process events
      if (event.window.event == SDL_WINDOWEVENT_CLOSE || event.type == SDL_QUIT)
      {
        is_running = false;
      }

      // Update state



      // Render




      // Framerate control
      ticks_frame_used = SDL_GetTicks() - ticks_frame_start;
      // printf("Ticks used: %u, Ticks pr frame: %u\n", ticks_frame_used, ticks_pr_frame);
      if (ticks_frame_used < ticks_pr_frame)
      {
        SDL_Delay(ticks_pr_frame - ticks_frame_used);
      }
      else
      {
        printf("Framerate issue\n");
      }
    }
  }

  return 0;
}

int app_dummy()
{
  return 42;
}
