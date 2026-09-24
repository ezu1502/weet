#pragma once

class Window {
public:
    Window(int argc, char *argv[]);
    
    int run();

private:
    int argc;
    char *argv[];
};