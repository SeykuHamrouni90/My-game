//Bien penser à tout inclure les fichiers .cpp
#include "main.hpp"
#include "input.cpp"

//Variables
//Fenêtre du Jeu
RenderWindow window;
//Gestion des inputs
Input input;
//Création de la Font
Font font;
//Création du Texte
Text txt;


int main(){

    window.create(VideoMode(WIN_WIDTH,WIN_HEIGHT,32), "Mon jeu");
    //Activation du Vsync
    window.setVerticalSyncEnabled(true);

    //Chargement font (police)
     LoadFont();

    SetText(txt, "Coucou");

    //boucle qui tourne tant que la fenêtre est ouverte
    while (window.isOpen()){

        Event event; // Variable pour gérer l'événement
        //On boucle sur les événements
        while(window.pollEvent(event)){
            input.IntputsHandler(event, window);
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

//Chargement de la police d'écriture
void LoadFont(){
    //On vérifie que la police d'écriture est bien chargée
    if(!font.loadFromFile("res/Poppins-MediumItalic.ttf")){
        //Si erreur
        cout << "Erreur Chargement de la police\n";
    }
}

//Mise en place du texte
void SetText (Text &txt, String str){
     txt.setFont(font);
     txt.setString(str);
     txt.setCharacterSize(26);
     txt.setFillColor(Color::Cyan);
}

 /*Gestion inputs (Clavier Souris)
    //Cette méthode est pour les event plus ponctuels
    if (event.key.code == Keyboard::Escape){
        window.close();
    }*/