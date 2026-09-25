#pragma once

#include "audio.hpp"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

class Window {
public:
    Window(int argc, char *argv[], Audio& audio) : argc(argc), argv(argv), app(argc, argv), engine(), audio(audio){}    
    int run();

private:
    int argc;
    char **argv;

    QGuiApplication app;
    QQmlApplicationEngine engine;

    Audio& audio;
};