#include <QQmlContext>
#include <QWindow>
#include <QIcon>

#include "window.hpp"


int Window::run(){
    engine.rootContext()->setContextProperty("audio", &audio);
    engine.loadFromModule("Weet", "Main");

    auto roots = engine.rootObjects();

    if (!roots.isEmpty()){
        auto window = qobject_cast<QWindow*>(roots.first());

        if (window){
            window->setIcon(QIcon(":/qt/qml/Weet/logo/weet_logo.png"));
        }
    }
    return app.exec();
}   