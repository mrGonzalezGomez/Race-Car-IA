#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

int play_song(void)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_AUDIO) != 0)
    {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    // Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        fprintf(stderr, "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return 1;
    }

    // Load an MP3 file
    const char *mp3File = "coconut_mall.mp3";
    Mix_Music *music = Mix_LoadMUS(mp3File);
    if (music == NULL)
    {
        fprintf(stderr, "Mix_LoadMUS Error: %s\n", Mix_GetError());
        return 1;
    }

    // Play the music
    Mix_PlayMusic(music, 1);

    // Wait until playback is finished
    while (Mix_PlayingMusic())
    {
        SDL_Delay(100);
    }

    // Cleanup and exit
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}
