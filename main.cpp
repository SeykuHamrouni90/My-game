#include "main.hpp"
using namespace sf;
using namespace std;

//Prototypes des fonctions
void IntputsHandler(Event event, RenderWindow& window);
void LoadFont();
void SetText (Text &txt, String str);

//Variables
Font font;


int main(){

    RenderWindow window(VideoMode(WIN_WIDTH,WIN_HEIGHT,32), "Mon jeu");
    //Activation du Vsync
    window.setVerticalSyncEnabled(true);

    //Chargement font (police)
     LoadFont();

     //création d'un texte
     Text txt;
    SetText(txt, "Mon Jeu");

    //boucle qui tourne tant que la fenêtre est ouverte
    while (window.isOpen()){

        Event event; // Variable pour gérer l'événement
        //On boucle sur les événements
        while(window.pollEvent(event)){
            IntputsHandler(event, window);
        }
        //Couleur de la fenêtre en noir
        window.clear(Color::Black);

        //On dessine entre le window.clear et le window.display
        window.draw(txt);
        
        
        //Afficher à l'écran
        window.display();

    }

    return 0;
}


//Gestion des events et inputs
void IntputsHandler(Event event, RenderWindow& window){
    //Fermer la fenêtre si clic sur croix
            if(event.type == Event::Closed){
                
                window.close();
                }
}



//Chargement de la police d'écriture
void LoadFont(){
    //On vérifie que la police d'écriture est bien chargée
    if(!font.loadFromFile("res/Poppins-MediumItalic.ttf")){
        //Si erreur
        cout << "Erreur Chargement de la police\n";
    }
}

void SetText (Text &txt, String str){
     txt.setFont(font);
     txt.setString(str);
     txt.setCharacterSize(26);
     txt.setFillColor(Color::Cyan);
}