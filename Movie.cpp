#include <iostream>
#include <cstring>
#include "Movie.h"

using namespace std;

Movie::Movie(){
  director = new char[30];
}

void Movie::setRating(float rate){
  rating = rate;
}
float Movie::getRating(){
  return rating;
}
void Movie::setDirector(char* name){
  director = new char[30];
  strcpy(director, name);
}
char* Movie::getDirector(){
  return director;
}
void Movie::setDuration(int time){
  duration = time;
}
int Movie::getDuration(){
  return duration;
}
