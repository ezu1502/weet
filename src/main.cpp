#include <iostream>
#include <string>

#include "window.hpp"
#include "audio.hpp"

int main(int argc, char *argv[]){
    Audio audio{};

    Window window(argc, argv, audio);
    return window.run();
}
