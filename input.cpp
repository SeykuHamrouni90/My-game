#include "input.hpp"



//Constructeur
Input::Input(){
    button.left = button.right = button.up = button.down = button.attack = button.exit = false;
}

//Fonction qui accède à button (structure) et donne l'info private
Input::Button Input::GetKey(void) const 
{
    return button;
}

void Input::IntputsHandler(Event event, RenderWindow& window){
     //Fermer la fenêtre si clic sur croix
    if(event.type == Event::Closed){
        window.close();
    }

    if (event.type == Event::KeyPressed){
        
        switch(event.key.code)
        {
            case Keyboard::Left:
                button.left = true;
                break;
            case Keyboard::Right:
                button.right = true;
                break;
            case Keyboard::Up:
                button.up = true;
                break;
            case Keyboard::Down:
                button.down = true;
                break;
            case Keyboard::Escape:
                button.exit = true;
                break;
            default:
                break;
        }
    }
    if (event.type == Event::KeyReleased){
        
        switch(event.key.code)
        {
            case Keyboard::Left:
                button.left = false;
                break;
            case Keyboard::Right:
                button.right = false;
                break;
            case Keyboard::Up:
                button.up = false;
                break;
            case Keyboard::Down:
                button.down = false;
                break;
            case Keyboard::Escape:
                button.exit = false;
                break;
            default:
                break;
        }
    }
    //Détection de la souris
    if (event.type == Event::MouseButtonPressed){
        if (event.mouseButton.button == Mouse::Left){
            button.attack = true;
        }
    }
    if (event.type == Event::MouseButtonReleased){
        if (event.mouseButton.button == Mouse::Left){
            button.attack = false;
        }
    }
}
