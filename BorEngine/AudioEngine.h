#pragma once

#include <SDL\SDL_mixer.h>
#include <string>
#include <map>

namespace BorEngine {

	class SoundEffect {
	public:
		friend class AudioEngine;
		void play(int loops = 0);
	private:
		Mix_Chunk* p_chunk = nullptr;
	};

	class Music {
	public:
		friend class AudioEngine;
			void play(int loops = -1);
		static	void pause();
		static	void stop();
		static void resume();
	private:
		Mix_Music* p_music = nullptr;
	};

	class AudioEngine
	{
	public:
		AudioEngine();
		~AudioEngine();

		void init();
		void destroy();

		SoundEffect loadSoundEffect(const std::string& filePath);
		Music loadMusic(const std::string& filePath);
	private:
		std::map<std::string, Mix_Chunk*> p_effectMap;
		std::map<std::string, Mix_Music*> p_musicMap;
		bool p_isInitialized = false;
	};

}