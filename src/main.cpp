#include "device.hpp"
#include "oscillator.hpp"

#include <iostream>
#include <numbers>
#include <string>
#include <stdexcept>

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
        double sample = osc->get_sample();

        // apply_effects(sample);

        outputBuffer[i] = sample;
    }
}

int main(int argc, char *argv[]){
    if (argc != 2){
        std::cout << "Usage: ./weet frequency";
        return 1;
    }

    float frequency = std::stof(argv[1]);

    Oscillator oscillator(frequency, Waveform::SINE);

    ma_device device = create_audio_device(&oscillator, sampleRate, data_callback);
    while(true){
        
    }
}