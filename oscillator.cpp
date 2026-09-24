#include "oscillator.hpp"

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
    }

    sampleIndex++;

    return result;
}
void Oscillator::set_waveform(Waveform wv){
    waveform = wv;
}

float Oscillator::get_sine(){
    double time = static_cast<double>(sampleIndex) / sampleRate;
    return std::sin(2*pi*frequency*time);
}

float Oscillator::get_square(){
    return 0.0f;
}

float Oscillator::get_saw(){
    return 0.0f;
}