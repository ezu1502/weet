#pragma once

#include <numbers>
#include <cmath>
constexpr int sampleRate = 44100;

constexpr double pi = std::numbers::pi;

enum class Waveform {
    SINE, 
    SQUARE,
    SAW,
    TRIANGLE,
    ARC,
};

class Oscillator {
public:
    Oscillator(float frequency) : frequency(frequency), waveform(Waveform::SINE), sampleIndex(0), amplitude(1){}
    Oscillator(float frequency, Waveform waveform) : frequency(frequency), waveform(waveform), sampleIndex(0), amplitude(1){}
    Oscillator(float frequency, float amplitude, Waveform waveform) : frequency(frequency), amplitude(amplitude), waveform(waveform), sampleIndex(0){}

    float get_sample();
    
    void set_waveform(Waveform wv);

    void set_frequency(float f);
    void set_amplitude(float a);
    
private:
    int sampleIndex;
    Waveform waveform;

    float get_sine();
    float get_square();
    float get_saw();
    float get_triangle();

    float get_arc();

    float frequency;
    float amplitude;
};
