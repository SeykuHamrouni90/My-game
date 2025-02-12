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
float posX = 0;
int RecX = 600;
int rayon = 75;
int Largeur = 75;
int CircleHitbox, RectangleHitbox;

//Conversion du chiffre en string
char temp [256];
CircleShape circle_shape(rayon);
RectangleShape rectangle(Vector2f(Largeur, 160));


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
            circle_shape.setPosition(posX,60);
        }
        //Couleur de la fenêtre en noir
        window.clear(Color::Black);

        //On dessine entre le window.clear et le window.display
            Draw();

        //Afficher à l'écran
        window.display();

        CircleHitbox = posX + rayon;
        RectangleHitbox= RecX - Largeur;
        
        if(CircleHitbox >RectangleHitbox){
            posX = (RecX - Largeur - rayon); 
        }

    }
    return 0;
}

void LoadTexture(){
    texture.loadFromFile("res/textures/sans.png");
    if(!texture.loadFromFile("res/textures/sans.png")){
        //Si erreur
        cout << "Erreur Chargement de l'image\n";
    }
    perso.setTexture(texture);
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
    if (input.GetKey().right == true && CircleHitbox < RectangleHitbox ){
        posX += 10;
    }
    if (input.GetKey().down == true){
        
    }
    if (input.GetKey().up == true){
        
    }
    if (input.GetKey().attack == true){
    
    }
    if(input.GetKey().exit == true){
        window.close();
    }
}

void Draw(){
    window.draw(txt);
    window.draw(circle_shape);
    window.draw(rectangle);
    window.draw(perso);
    }

void PrimitivePreparer(){
        //Préparation des primitives
    circle_shape.setFillColor(Color::Magenta);
    rectangle.setFillColor(Color::Green);
    rectangle.setPosition(RecX,50);
    
}

 /*Gestion inputs (Clavier Souris)

    //Cette méthode est pour les event plus ponctuels
    if (event.key.code == Keyboard::Escape){
        window.close();
    }
    Pour écrire une valeur numérique : sprintf(temp, "%d", nom_de_la_variable);
    mettre un %f pour les floats*/