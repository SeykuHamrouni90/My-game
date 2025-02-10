#ifndef INPUT_H
#define INPUT_H


#include <SFML/Graphics.hpp>
using namespace sf;

class Input{
    struct Button {bool left, right, up, down, attack, escape;};

    public:
        //Prototype du constructeur
        Input();
        //Prototype du GetKey
        Button GetKey(void) const;
        //Prototype
        void IntputsHandler(Event event, RenderWindow& window);
    private:
        Button button;
};

#endif