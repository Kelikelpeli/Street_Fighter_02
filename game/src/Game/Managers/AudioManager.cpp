#include "AudioManager.h"


AudioManager* AudioManager::AudioMngr = nullptr;

AudioManager::AudioManager()
{
    InitAudioFiles();
}
AudioManager& AudioManager::GetAudioManager()
{
    if (!AudioMngr)
        AudioMngr = new AudioManager();

    return *AudioMngr;
}

void AudioManager::InitAudioFiles()
{
    InitAudioDevice();

    //Music
    IntroSound = LoadSound("resources/Sound/Title_Theme.mp3");	// Load Intro theme music
    GameOverSound = LoadSound("resources/Sound/Game_Over.mp3");
    KenThemeSound = LoadSound("resources/Sound/Ken_Theme.mp3");
    VictorySound = LoadSound("resources/Sound/Victory_Screen.mp3");

    SetSoundVolume(IntroSound, 0.5f);
}


void AudioManager::PlaySoundEffect(SoundType sound)
{

    switch (sound)
    {
    case SoundType::IntroTheme:
        PlaySound(IntroSound);
        StopSound(GameOverSound);
        StopSound(KenThemeSound);
        StopSound(VictorySound);
        SetSoundVolume(IntroSound, 0.5f);
        break;
    case SoundType::GameOver:
        PlaySound(GameOverSound);
        StopSound(IntroSound);
        StopSound(KenThemeSound);
        StopSound(VictorySound);
        SetSoundVolume(GameOverSound, 0.5f);
        break;
    case SoundType::KenTheme:
        PlaySound(KenThemeSound);
        StopSound(IntroSound);
        StopSound(GameOverSound);
        StopSound(VictorySound);
        SetSoundVolume(KenThemeSound, 0.5f);
        break;
    case SoundType::Victory:
        PlaySound(VictorySound);        
        StopSound(IntroSound);
        StopSound(GameOverSound);
        StopSound(KenThemeSound);
        SetSoundVolume(VictorySound, 0.5f);
        break;
    default:
        break;
    }
}

void AudioManager::UnloadAudioFiles()
{
    UnloadSound(KenThemeSound);
    UnloadSound(IntroSound);
    UnloadSound(VictorySound);
    UnloadSound(GameOverSound);
   

    //CloseAudio
    CloseAudioDevice();

}


