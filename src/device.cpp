#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include <iostream>

#include <stdexcept>

using AudioCallback = void (*)(ma_device*, void*, const void*, ma_uint32);
class Oscillator;

void create_audio_device(ma_device *device, Oscillator *oscillator, int sampleRate, AudioCallback callback){
    ma_device_config config = ma_device_config_init(ma_device_type_playback); // inicializa o dispositivo do miniaudio
    config.sampleRate = sampleRate;
    config.playback.format = ma_format_f32; // Configura o dispositivo pra receber amostras float de 32bits
    config.playback.channels = 1; // Configura o miniaudio pra mono
    config.dataCallback = callback; // função que o mini audio vai chamar

    config.pUserData = oscillator;

    ma_result result = ma_device_init(nullptr, &config, device);

    if (result != MA_SUCCESS){
        throw std::runtime_error("ma_device couldn't be initialized.");
    }

}