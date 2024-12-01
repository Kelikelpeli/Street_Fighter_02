#pragma once

#include "raylib.h"

enum class SoundType
{
	IntroTheme = 0,
	GameOver,
	KenTheme,
	Victory,
};

class AudioManager
{
public:
	AudioManager();

	void InitAudioFiles();
	void UnloadAudioFiles();

	void PlaySoundEffect(SoundType sound);
	static AudioManager& GetAudioManager();


private:
	static AudioManager* AudioMngr;

	Sound IntroSound;
	Sound GameOverSound;
	Sound KenThemeSound;
	Sound VictorySound;
};
