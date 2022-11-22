#include <iostream>
#include <cstring>
#include "Music.h"

using namespace std;

Music::Music(){
  artist = new char[30];
}

char* Music::getArtist(){
  return artist;
}
void Music::setArtist(char* name){
  artist = new char[30];
  strcpy(artist, name);
}
int Music::getDuration(){
  return duration;
}
void Music::setDuration(int time){
  duration = time;
}
char* Music::getPublisher(){
  return publisher;
}
void Music::setPublisher(char* name){
  publisher = new char[30];
  strcpy(publisher, name);
}
virtual void Music::print(char* title, int date, char* pub, char* name, int time){
  cout << "Title: " << title << ", Year: " << date << ", Publisher: " << pub << ", Artist: " << name << ", Duration: " << time << endl;
}
