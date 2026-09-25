#include <QQmlContext>
#include "window.hpp"


int Window::run(){
    engine.rootContext()->setContextProperty("audio", &audio);
    engine.loadFromModule("Weet", "Main");
    return app.exec();
}   