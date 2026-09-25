#pragma once
#include "miniaudio.h"

using AudioCallback = void (*)(ma_device*, void*, const void*, ma_uint32);
class Oscillator;

void create_audio_device(
    ma_device *device,
    Oscillator *oscillator,
    int sampleRate,
    AudioCallback callback
);