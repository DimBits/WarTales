#include "Game.h"
#include "wt-client.h"

int main(int argc, char** argv) {
    Game WarTales;
    WarTales.setTitle("Hello");
    WarTales.setRenderDrawColor({0, 255, 0, 255});
    WarTales.exec();
    return 0;
}

