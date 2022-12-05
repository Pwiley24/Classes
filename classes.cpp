/*
 * This project creates a database to store media types wit different values.
 * Author: Paige Wiley
 * Date: 12-5-2022
 */

#include <iostream>
#include <vector>
#include "digitalMedia.h"
#include "Videogame.h"
#include "Music.h"
#include "Movie.h"


using namespace std;

void add(vector<digitalMedia*> &mediaList);
void search(vector<digitalMedia*> &mediaList);
void printSearch(vector<digitalMedia*> &list);
void deleteMedia(vector<digitalMedia*> &mediaList);
bool checkDelete(vector<digitalMedia*> &deleteList);

int main(){
  bool running = true;
  vector<digitalMedia*> mediaList;

  while(running){
    char input[10];
    cout << "Enter a command (ADD, SEARCH, DELETE, QUIT)" << endl;
    cin.get(input, 10);
    cin.ignore(10, '\n');

    if(strcmp(input, "ADD") == 0){ //user wants to add media
      add(mediaList);
      
    
    }else if(strcmp(input, "QUIT") == 0){ //user wants to quit program
      running = false;
    }else if(strcmp(input, "SEARCH") == 0){ //user wants to search database
      search(mediaList);
    }else if(strcmp(input, "DELETE") == 0){ //user wants to delete database item
      deleteMedia(mediaList);
    }

    
  }

  
  return 0;
}

/*
 * This function will allow user to type information in.
 * Program will then iterate through each of its values
 * to see if it matches. Print the information if it matches.
 */
void search(vector <digitalMedia*> &mediaList){
  vector <digitalMedia*> searchList;
  char input[30];
  cout << "Search by TITLE or YEAR?" << endl;
  cin.get(input, 30);
  cin.ignore(30, '\n');
  

  vector <digitalMedia*>::iterator ptr;
 
  if(strcmp(input, "TITLE") == 0){  
    cout << "What is the title?" << endl;
    cin.get(input, 30);
    cin.ignore(30, '\n');
    
    for(ptr = mediaList.begin(); ptr < mediaList.end(); ptr++){ //goes through each value in vector
      if(strcmp(input, (*ptr)->getTitle()) == 0){ //title matches media
	searchList.push_back(*ptr);
      }
    }
    
  }else if(strcmp(input, "YEAR") == 0){ //search year; convert char to int
    cout << "What is the year?" << endl;
    cin.get(input, 10);
    cin.ignore(10, '\n');
    int year = stoi(input);
    
    for(ptr = mediaList.begin(); ptr < mediaList.end(); ptr++){
      if(year == (*ptr)->getYear()){ //year matches media
	searchList.push_back(*ptr);
      }
    }
  }
  
  

  printSearch(searchList);
 
}

void printSearch(vector <digitalMedia*> &list){
  vector <digitalMedia*>::iterator ptr;

  for(ptr = list.begin(); ptr< list.end(); ptr++){
    (*ptr)->print();
  }
  list.clear();
}



void deleteMedia(vector <digitalMedia*> &mediaList){
  vector <digitalMedia*> deleteList;
  char input[30];
  int deletes = 0;
  cout << "Delete by TITLE or YEAR?" << endl;
  cin.get(input, 30);
  cin.ignore(30, '\n');

  vector <digitalMedia*>::iterator ptr;

  if(strcmp(input, "TITLE") == 0){ //find by title
    cout << "What is the title?" << endl;
    cin.get(input, 30);
    cin.ignore(30, '\n');
    
    for(ptr = mediaList.begin(); ptr < mediaList.end(); ptr++){
      if(strcmp(input, (*ptr)->getTitle()) == 0){ //title matches media
	deleteList.push_back(*ptr);
      }
    }
    
    deletes = deleteList.size();
    
    //remove deleted list from media list
    if(checkDelete(deleteList)){
      while(deletes >= 1){
	for(ptr = mediaList.begin(); ptr < mediaList.end(); ptr++){
	  if(strcmp(input, (*ptr)->getTitle()) == 0){
	    ptr = mediaList.erase(ptr);
	  }else{
	    ++ptr;
	  }
	}
	deletes--;
      }
    }
  }else if(strcmp(input, "YEAR") == 0){//find by year
    cout << "What is the year?" << endl;
    cin.get(input, 10);
    cin.ignore(10, '\n');
    int year = stoi(input);

    for(ptr = mediaList.begin(); ptr < mediaList.end(); ptr++){
      if(year == (*ptr)->getYear()){//year matches media
	deleteList.push_back(*ptr);
      }
    }
    
    deletes = deleteList.size();
    
    //Remove deleted items from media list
    if(checkDelete(deleteList)){
      while(deletes >= 1){ //while items still need to be deleted
	for(ptr = mediaList.begin(); ptr < mediaList.end(); ptr++){
	  if(year == (*ptr)->getYear()){
	    ptr = mediaList.erase(ptr);   
	  }else{
	    ++ptr;
	  }
	}
	deletes--;
      }
    }
  }
}


bool checkDelete(vector <digitalMedia*> &deleteList){
  char input;
  printSearch(deleteList);
  cout << "Are you sure you want to delete these items? (y or n)" << endl;
  cin >> input;
  cin.ignore(5, '\n');
  if(input == 'y'){

    vector <digitalMedia*>::iterator ptr;
    
    for(ptr = deleteList.begin(); ptr < deleteList.end(); ptr++){
      delete (*ptr);
    }
    deleteList.clear();
    
    return true;
  }
  return false;
}

void add(vector <digitalMedia*> &mediaList){
  char input[30];
  cout << "What type of media? (VIDEOGAME, MUSIC, MOVIE)" << endl;
  cin.get(input, 10);
  cin.ignore(10, '\n');
  
  if(strcmp(input,"VIDEOGAME") == 0){ //if videogame ask publisher, rating
    Videogame* newVideo = new Videogame();
    
    //assign the title and year:
    cout << "What year was it made?" << endl;
    cin.get(input, 10);
    cin.ignore(10, '\n');
    int videoYr = stoi(input);
    newVideo->setYear(videoYr);

    cout << "What is the title?" << endl;
    cin.get(input, 30);
    cin.ignore(30, '\n');
    newVideo->setTitle(input);

    //assign the publisher:
    cout << "Who is the publisher?" << endl;
    cin.get(input, 20);
    cin.ignore(20, '\n');
    newVideo->setPublisher(input);

    //assign the rating:
    cout << "What is the rating?" << endl;
    cin.get(input, 10);
    cin.ignore(10, '\n');
    float videoRate = atof(input);
    newVideo->setRating(videoRate);

    //push into vector:
    mediaList.push_back(newVideo);

  }else if (strcmp(input, "MUSIC") == 0){ //if music ask artist, duration, publisher
    Music* newMusic = new Music();
    
    //assign the title and year:
    cout << "What year was it made?" << endl;
    cin.get(input, 10);
    cin.ignore(10, '\n');
    int musicYr = stoi(input);
    newMusic->setYear(musicYr);

    cout << "What is the title?" << endl;
    cin.get(input, 30);
    cin.ignore(30, '\n');
    newMusic->setTitle(input);

    //assign the artists:
    cout << "Who is the artist?" << endl;
    cin.get(input, 30);
    cin.ignore(30, '\n');
    newMusic->setArtist(input);

    //assign the publisher:
    cout << "Who is the publisher?" << endl;
    cin.get(input, 30);
    cin.ignore(30, '\n');
    newMusic->setPublisher(input);

    //assign the duration
    cout << "What is the duration? (in seconds)" << endl;
    cin.get(input, 10);
    cin.ignore(10, '\n');
    int musicDur = stoi(input);
    newMusic->setDuration(musicDur);

    //push to vector
    mediaList.push_back(newMusic);
    
  }else if (strcmp(input, "MOVIE") == 0){ //if movie ask rating, director, duration
    Movie* newMovie = new Movie();

    //assign the title and year:
    cout << "What year was it made?" << endl;
    cin.get(input, 10);
    cin.ignore(10, '\n');
    int movieYr = stoi(input);
    newMovie->setYear(movieYr);

    cout << "What is the title?" << endl;
    cin.get(input, 30);
    cin.ignore(30, '\n');
    newMovie->setTitle(input);

    //assign rating:
    cout << "What is the rating?" << endl;
    cin.get(input, 10);
    cin.ignore(10, '\n');
    float movieRate = atof(input);
    newMovie->setRating(movieRate);

    //assign director:
    cout << "Who is the director?" << endl;
    cin.get(input, 30);
    cin.ignore(30, '\n');
    newMovie->setDirector(input);

    //assign duration:
    cout << "What is the duration? (in minutes)" << endl;
    cin.get(input, 10);
    cin.ignore(10, '\n');
    int movieDur = stoi(input);
    newMovie->setDuration(movieDur);

    //push to vector
    mediaList.push_back(newMovie);
  }
  
 
}


/*video game child
 - rating
 - publisher
 
  Music child
 - artist
 - publisher

  Movies child
 - director
 - duration
 - rating

  Digital media parent
 - title
 - year

vector to store all the medias
when you create a vector ask for media type
create a new media type and ask for corresponding things

 */
