#include <iostream>
#include <SFML/Graphics.hpp>
#include "input.hpp"

//exécuter le code : g++ main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system

//constantes définissant la taille de l'écran
const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;

using namespace sf;
using namespace std;

void LoadFont();
void SetText (Text &txt, String str);
void CheckBtn();



