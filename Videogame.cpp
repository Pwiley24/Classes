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
void Videogame::print(){
  cout << "Title: " << title << ", Year: " << year << ", Publisher: " << publisher << ", Rating: " << rating << endl;
}


