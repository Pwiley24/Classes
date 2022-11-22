#include <iostream>
#include <cstring>
#include "Videogame.h"

using namespace std;

Videogame::Videogame(){
  publisher = new char[30];
}

void Videogame::setRating(float rate){
  rating = rate;
}
float Videogame::getRating(){
  return rating;
}
char* Videogame::getPublisher(){
  return publisher;
}
void Videogame::setPublisher(char* pub){
  publisher = new char[30];
  strcpy(publisher, pub);
}
void virtual Videogame::print(char* title, int date, char* pub, float rate){
  cout << "Title: " << title << ", Year: " << date << ", Publisher: " << pub << ", Rating: " << rate << endl;
}


