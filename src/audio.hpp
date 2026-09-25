#pragma once

#include <QObject>

#include "device.hpp"
#include "oscillator.hpp"

void data_callback(ma_device *device, void *output, const void *input, ma_uint32 frameCount);

class Audio : public QObject{

Q_OBJECT  
public:
    Audio();
    ~Audio();

    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();

private:
    Oscillator oscillator;
    ma_device device{};
};