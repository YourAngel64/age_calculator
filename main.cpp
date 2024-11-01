#include "main.hpp"
#include "app.hpp"

int main(int argc, char const *argv[]){
    App *app = new App();

    while(app->isRunning())
        app->Run();

    app->Close();
    delete(app);
    return 0;
}
