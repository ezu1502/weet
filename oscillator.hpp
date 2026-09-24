#pragma once

#include <numbers>
#include <cmath>
constexpr int sampleRate = 44100;

constexpr double pi = std::numbers::pi;

enum class Waveform {
    SINE, 
    SQUARE,
    SAW,
    TRIANGLE
};

class Oscillator {
public:
    Oscillator(float frequency) : frequency(frequency), waveform(Waveform::SINE), sampleIndex(0){}
    Oscillator(float frequency, Waveform waveform) : frequency(frequency), waveform(waveform), sampleIndex(0){}

    float get_sample();
    void set_waveform(Waveform wv);
private:
    int sampleIndex;
    float frequency;
    Waveform waveform;

    float get_sine();
    float get_square();
    float get_saw();
};
