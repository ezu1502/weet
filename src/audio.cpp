#include <stdexcept>
#include <vector>
#include <stdexcept>

#include "audio.hpp"

std::vector<Waveform> waves = {Waveform::SINE, Waveform::SQUARE, Waveform::SAW, Waveform::TRIANGLE, Waveform::ARC};

void data_callback(ma_device *device, void *output, const void *input, ma_uint32 frameCount){
    Oscillator *osc = static_cast<Oscillator*>(device->pUserData);
    float *outputBuffer = static_cast<float*>(output);
    
    
    for (ma_uint32 i = 0; i < frameCount; i++){
        double sample = osc->get_sample();

        // apply_effects(sample);

        outputBuffer[i] = sample;
    }
}

void apply_effects(double& sample){
    if (sample > 0.5){
        sample = 0.5;
    }
    if (sample < -0.5){
        sample = -0.5;
    }

    sample*=2;
}


Audio::Audio() : oscillator(440, Waveform::SINE){
    create_audio_device(
        &device,
        &oscillator,
        sampleRate,
        data_callback
    );
}

void Audio::start(){
    ma_result result = ma_device_start(&device);

    if (result != MA_SUCCESS){
        throw std::runtime_error("ma_device couldn't be started.");
    }
}

void Audio::stop(){
    ma_result result = ma_device_stop(&device);

    if (result != MA_SUCCESS){
        throw std::runtime_error("ma_device couldn't be stopped.");
    }
}

void Audio::set_frequency(float value){
    oscillator.set_frequency(value);
}

void Audio::set_gain(float value){
    oscillator.set_amplitude(value);
}

Audio::~Audio(){
    ma_device_uninit(&device);
}

void Audio::set_waveform(int choice){
    
    

    if (choice < 0 || choice >= static_cast<int>(waves.size())){
        throw std::invalid_argument("Invalid index");
    }

    oscillator.set_waveform(waves[choice]);
}