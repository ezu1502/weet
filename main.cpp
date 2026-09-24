#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"

#include <cmath>
#include <iostream>
#include <numbers>
#include <string>
#include <stdexcept>

constexpr int sampleRate = 44100;

constexpr double pi = std::numbers::pi;

struct Oscillator {
    float frequency;
    int sampleIndex;
};

void apply_effects(double& sample){
    if (sample > 0.5){
        sample = 0.5;
    }
    if (sample < -0.5){
        sample = -0.5;
    }

    sample*=2;
}

void data_callback(ma_device *device, void *output, const void *input, ma_uint32 frameCount){
    Oscillator *osc = static_cast<Oscillator*>(device->pUserData);
    float *outputBuffer = static_cast<float*>(output);
    
    
    for (ma_uint32 i = 0; i < frameCount; i++){
        double time = static_cast<double>(osc->sampleIndex) / sampleRate;

        double sample = std::sin(2*pi*osc->frequency*time);

        apply_effects(sample);

        outputBuffer[i] = sample;
        osc->sampleIndex++;
    }
}

ma_device create_audio_device(Oscillator *oscillator){
    ma_device_config config = ma_device_config_init(ma_device_type_playback); // inicializa o dispositivo do miniaudio
    config.sampleRate = sampleRate;
    config.playback.format = ma_format_f32; // Configura o dispositivo pra receber amostras float de 32bits
    config.playback.channels = 1; // Configura o miniaudio pra mono
    config.dataCallback = data_callback; // função que o mini audio vai chamar

    config.pUserData = oscillator;

    ma_device device;

    ma_result result = ma_device_init(nullptr, &config, &device);

    if (result != MA_SUCCESS){
        throw std::runtime_error("ma_device couldn't be initialized.");
    }

    result = ma_device_start(&device);

    if (result != MA_SUCCESS){
        throw std::runtime_error("ma_device couldn't be started.");
    }    
    
    return device;
}

int main(int argc, char *argv[]){
    if (argc != 2){
        std::cout << "Usage: ./weet frequency";
        return 1;
    }

    float frequency = std::stof(argv[1]);

    Oscillator oscillator;
    oscillator.frequency = frequency;
    oscillator.sampleIndex = 0;
    ma_device device = create_audio_device(&oscillator);
    while(true){

    }
}