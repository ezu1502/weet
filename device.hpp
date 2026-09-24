#pragma once
#include "miniaudio.h"

using AudioCallback = void (*)(ma_device*, void*, const void*, ma_uint32);
class Oscillator;

ma_device create_audio_device(Oscillator *oscillator, int sampleRate, AudioCallback callback);