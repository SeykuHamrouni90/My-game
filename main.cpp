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
//Exemple de valeur position axe X
int posX = 0;
//Conversion du chiffre en string
char temp [256];


int main(){

    window.create(VideoMode(WIN_WIDTH,WIN_HEIGHT,32), "Mon jeu");
    
    //Activation du Vsync
    window.setVerticalSyncEnabled(true);

    //Chargement font (police)
     LoadFont();

    SetText(txt, "Coucou");

    //Préparation des primitives
    CircleShape circle_shape(75) ;
    circle_shape.setFillColor(Color(200,200,0));
    circle_shape.setOutlineColor(Color::Red);
    circle_shape.setOutlineThickness(5);
    RectangleShape rectangle_shape(Vector2f(120.f,50.f));
    rectangle_shape.setFillColor(Color(200,0,100,100));
    rectangle_shape.setSize(Vector2f(200.f,100.f));
    rectangle_shape.setPosition(200,300);
    

    //boucle qui tourne tant que la fenêtre est ouverte
    while (window.isOpen()){

        Event event; // Variable pour gérer l'événement
        
        //On boucle sur les événements
        while(window.pollEvent(event)){
            input.IntputsHandler(event, window);
            CheckBtn();
            circle_shape.setPosition(posX,80);
        }
        //Couleur de la fenêtre en noir
        window.clear(Color::Black);

        //On dessine entre le window.clear et le window.display
        window.draw(txt);
        window.draw(circle_shape);
        window.draw(rectangle_shape);
        
        
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
     txt.setFillColor(Color::White);
}

//Check du bouton appuyé et éxécution de l'instruction correspondante
void CheckBtn(){
    if (input.GetKey().left == true){
        SetText(txt, temp);
        posX -= 20;
        sprintf(temp, "%d", posX);
    }
    if (input.GetKey().right == true){
        SetText(txt, temp);
        posX += 20;
        sprintf(temp, "%d", posX);
    }
    if (input.GetKey().down == true){
        SetText(txt, "Down");
    }
    if (input.GetKey().up == true){
        SetText(txt, "Up");
    }
    if (input.GetKey().attack == true){
        SetText(txt, "Attack");
    }
    if(input.GetKey().exit == true){
        window.close();
    }
}



 /*Gestion inputs (Clavier Souris)

    //Cette méthode est pour les event plus ponctuels
    if (event.key.code == Keyboard::Escape){
        window.close();
    }*/