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
    IntroMusic = LoadMusicStream("resources/Sound/Title_Theme.mp3");	// Load Intro theme music
    GameOverMusic = LoadMusicStream("resources/Audio/Music/GameOverTheme.mp3");


    //Sounds
    DeathSound = LoadSound("resources/Audio/Sounds/Death.mp3");;
    EatingCherrySound = LoadSound("resources/Audio/Sounds/EatingCherry.mp3");;
    EatingGhostSound = LoadSound("resources/Audio/Sounds/EatingGhost.mp3");;
    EatingPowerPillSound = LoadSound("resources/Audio/Sounds/EatingPowerPill.mp3");;
    GameStartSound = LoadSound("resources/Audio/Sounds/GameStart.mp3");;
    SirenSound = LoadSound("resources/Audio/Sounds/Siren.mp3");;
    VictorySound = LoadSound("resources/Audio/Sounds/Victory.mp3");;
    WakaWakaSound = LoadSound("resources/Audio/Sounds/WakaWaka.mp3");;

    SetMusicVolume(IntroMusic, 1.0f);
}

void AudioManager::PlayIntroMusic(bool activate)
{
    if (activate) {
        PlayMusicStream(IntroMusic);
        TraceLog(LOG_INFO, "Intro music started playing.");
    }
    else {
        StopMusicStream(IntroMusic);
        TraceLog(LOG_INFO, "Intro music finish playing.");
    }
}

void AudioManager::UpdateIntroMusic()
{
    UpdateMusicStream(IntroMusic);
}

void AudioManager::PlayGameOverMusic(bool activate)
{
    if (activate)
        PlayMusicStream(GameOverMusic);
    else
        StopMusicStream(GameOverMusic);
}

void AudioManager::UpdateGameOverMusic()
{
    UpdateMusicStream(GameOverMusic);
}

void AudioManager::PlaySoundEffect(SoundType sound)
{
    switch (sound)
    {
    case SoundType::Death:
        PlaySound(DeathSound);
        break;
    case SoundType::EatingCherry:
        PlaySound(EatingCherrySound);
        break;
    case SoundType::EatingGhost:
        PlaySound(EatingGhostSound);
        break;
    case SoundType::EatingPowerPill:
        PlaySound(EatingPowerPillSound);
        break;
    case SoundType::GameStart:
        PlaySound(GameStartSound);
        break;
    case SoundType::Siren:
        PlaySound(SirenSound);
        break;
    case SoundType::Victory:
        PlaySound(VictorySound);
        break;
    case SoundType::WakaWaka:
        PlaySound(WakaWakaSound);
        break;
    default:
        break;
    }
}

void AudioManager::UnloadAudioFiles()
{
    UnloadSound(DeathSound);
    UnloadSound(EatingCherrySound);
    UnloadSound(EatingGhostSound);
    UnloadSound(EatingPowerPillSound);
    UnloadSound(GameStartSound);
    UnloadSound(SirenSound);
    UnloadSound(VictorySound);
    UnloadSound(WakaWakaSound);

    //CloseAudio
    CloseAudioDevice();

}


