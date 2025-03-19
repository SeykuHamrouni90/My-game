//Bien penser à tout inclure les fichiers .cpp
#include "main.hpp"
#include "input.cpp"

//Variables
RenderWindow window;
Input input;
Font font;
Text txt;
Texture texture;
Sprite perso;
IntRect rect(0,0,32,32);
float posX = 0;
float posY = 350;


//Conversion du chiffre en string
char temp [256];

RectangleShape rectangle(Vector2f(800, 100));


int main(){

    //Options de la fenêtre
    ContextSettings options;
    options.antialiasingLevel = 4;
    window.create(VideoMode(WIN_WIDTH,WIN_HEIGHT,32), "Mon jeu", Style::Default, options);
    
    //Activation du Vsync
    window.setVerticalSyncEnabled(true);

    //Chargement font (police)
    LoadTexture();
    LoadFont();
    SetText(txt, "Coucou");
    
    //Setup des diverses formes
    PrimitivePreparer();

    //boucle qui tourne tant que la fenêtre est ouverte
    while (window.isOpen()){

        Event event; // Variable pour gérer l'événement
        
        //On boucle sur les événements
        while(window.pollEvent(event)){
            input.IntputsHandler(event, window);
            CheckBtn();
            perso.setPosition(posX, posY);
        }
        //Couleur de la fenêtre en noir
        window.clear(Color::Black);

        //On dessine entre le window.clear et le window.display
        Draw();

        //Afficher à l'écran
        window.display();

    }
    return 0;
}

void LoadTexture(){
    texture.loadFromFile("res/textures/Idle_Sprite.png");
    if(!texture.loadFromFile("res/textures/Idle_Sprite.png")){
        //Si erreur
        cout << "Erreur Chargement de l'image\n";
    }
    perso.setTexture(texture);
    perso.setTextureRect(rect);
    perso.scale(5.0f, 5.0f);
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
     txt.setPosition(360,10);
}

//Check du bouton appuyé et éxécution de l'instruction correspondante
void CheckBtn(){
    if (input.GetKey().left == true){
        posX -= 10;
    }
    if (input.GetKey().right == true ){
        posX += 10;
    }
    if (input.GetKey().down == true){
        posY += 10;
    }
    if (input.GetKey().up == true){
        posY -= 10;
    }
    if (input.GetKey().attack == true){
    
    }
    if(input.GetKey().exit == true){
        window.close();
    }
}

void Draw(){
    window.draw(txt);
    window.draw(perso);
    window.draw(rectangle);
    }

void PrimitivePreparer(){
        //Préparation des primitive (on fera ici les plateformes et divers décors)
    rectangle.setFillColor(Color::White);
    rectangle.setPosition(0,500);
}

 /*Gestion inputs (Clavier Souris)

    //Cette méthode est pour les event plus ponctuels
    if (event.key.code == Keyboard::Escape){
        window.close();
    }
    Pour écrire une valeur numérique : sprintf(temp, "%d", nom_de_la_variable);
    mettre un %f pour les floats*/