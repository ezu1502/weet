#include "oscillator.hpp"
#include <cmath>

void Oscillator::set_frequency(float f){
    frequency = f;
}

void Oscillator::set_amplitude(float a){
    amplitude = a;
}

float Oscillator::get_sample(){

    float result = 0.0f;
    switch (waveform){
        case Waveform::SINE:
            result = get_sine();
            break;
        case Waveform::SQUARE:
            result = get_square();
            break;
        case Waveform::SAW:
            result = get_saw();
            break;
        case Waveform::TRIANGLE:
            result = get_triangle();
            break; 
        case Waveform::ARC:
            result = get_arc();
            break;
    }

    sampleIndex++;

    return amplitude * result;
}
void Oscillator::set_waveform(Waveform wv){
    waveform = wv;
}

float Oscillator::get_sine(){
    double time = static_cast<double>(sampleIndex) / sampleRate;
    return std::sin(2*pi*frequency*time);
}

float Oscillator::get_square(){
    double time = static_cast<double>(sampleIndex) / sampleRate;

    double cycles = time * frequency;

    if (std::fmod(cycles, 1) > 0.5){
        return 1.0f;
    }
    else {
        return -1.0f;
    }
}

float Oscillator::get_saw(){
    double time = static_cast<double>(sampleIndex) / sampleRate;

    double cycles = time * frequency;

    return -2 * (std::fmod(cycles, 1) - 0.5);
}

float Oscillator::get_triangle(){
    double time = static_cast<double>(sampleIndex) / sampleRate;

    double cycles = time * frequency;

    return 2 *(std::abs(std::fmod(cycles, 1)) - 0.5);
}

float Oscillator::get_arc(){
    double time = static_cast<double>(sampleIndex) / sampleRate;

    double phase = std::fmod(time * frequency, 1);

    double x = (phase - 0.5);
    double y = std::sqrt(0.25 - x*x);

    return phase < 0.5 ? 2*y : -2*y;
}   