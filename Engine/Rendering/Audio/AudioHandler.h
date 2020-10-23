#ifndef AUDIOHANDLER_H
#define AUDIOHANDLER_H
#include <string>
#include <map>
#include <memory>
#include <fmod.hpp>
#include <glm/glm.hpp>
#include "../../Core/Debug.h"
#include "AudioSource.h"

class AudioHandler
{
public:
	AudioHandler(const AudioHandler&) = delete;
	AudioHandler(AudioHandler&&) = delete;

	AudioHandler& operator = (const AudioHandler&) = delete;
	AudioHandler& operator = (const AudioHandler&&) = delete;

	static AudioHandler* GetInstance();

	bool OnCreate(glm::vec3 position_, glm::vec3 velocity_, glm::vec3 forwardDirection_, glm::vec3 upDirection_);
	void OnDestroy();

private:
	AudioHandler();
	~AudioHandler();

	FMOD::System* FMODSystem;
	static std::map<std::string, FMOD::Sound*> soundMap;
	static std::map<int, FMOD::Channel*> channelMap;
	int channelCount;

	FMOD_VECTOR glmToFmod(glm::vec3 vector_);
	FMOD::Sound* GetSound(std::string name_);

	static std::unique_ptr<AudioHandler> audioInstnace;
	friend std::default_delete<AudioHandler>;

	void LoadSound(std::string soundName_, bool loopSound_, bool is3d_, bool howPlay_);
	bool isPlaying(int channelID_);
	int playSound(std::string soundName_, glm::vec3 pos_, glm::vec3 vel_, float volume);
	void Update(int channelID_, glm::vec3 pos_, glm::vec3 vel_);

};

#endif