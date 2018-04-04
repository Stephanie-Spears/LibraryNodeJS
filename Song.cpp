//
// Created by Stephanie Spears on 4/3/18.
//

#include "Song.h"
#include <iostream>

using namespace std;

Song::Song() {
	title = new char[strlen("empty title")+1]; //+1 sets last char to a null terminator
	strcpy(title, "empty title"); //strcpy(destination, source)

	artist = new char[strlen("empty artist")+1];
	strcpy(artist, "empty artist");

	duration = new char[strlen("empty duration")+1];
	strcpy(duration, "empty duration");

	album = new char[strlen("empty album")+1];
	strcpy(album, "empty album");
}

Song::Song(const char title[], const char artist[], const char duration[], const char album[]) {
	this->title = new char[strlen(title)+1];
	strcpy(this->title, title);
	this->artist = new char[strlen(artist)+1];
	strcpy(this->artist, artist);
	this->duration = new char[strlen(duration)+1];
	strcpy(this->duration, duration);
	this->album = new char[strlen(album)+1];
	strcpy(this->album, album);
}

Song::~Song() {
	delete[] title;
	delete[] artist;
	delete[] duration;
	delete[] album;
}


void Song::getTitle(char title[]) const {
	strcpy(title, this->title); //strcpy(destination, source), so it's taking the member variable "this->title" and copying it into the passed in parameter "title."
	//since the parameter is passed by value, the new value of "title" is updated in main.
}

void Song::getArtist(char artist[]) const {

	strcpy(artist, this->artist);
}

void Song::getDuration(char duration[]) const {
	strcpy(duration, this->duration);
}

void Song::getAlbum(char album[]) const {
	strcpy(album, this->album);
}

/* If address of instance member variable is not empty-->deallocate
 * strcpy(destination, source)--copies argument into the instance member var (this->title)
 * allocate new memory for char array, copy passed in argument to instance mem var
 * In: user-defined value or inputfile.txt value, validated by InputTools
 * */
void Song::setTitle(const char title[]) {
	this->title = new char[strlen(title)+1];
	strcpy(this->title, title);
}

void Song::setArtist(const char artist[]) {
	this->artist = new char[strlen(artist)+1];
	strcpy(this->artist, artist);
}

void Song::setDuration(const char duration[]) {
	this->duration = new char[strlen(duration)+1];
	strcpy(this->duration, duration);
}

void Song::setAlbum(const char album[]) {
	this->album = new char[strlen(album)+1];
	strcpy(this->album, album);
}



void Song::print() const {
	cout << "Title: " << this->title << endl; //these are the member variables of class Song. They don't need to be passed in because "print()" is a member function, and all member functions have access to one another without needing to specifically pass them in.
	cout << "Artist: " << this->artist << endl;
	cout << "Duration: " << this->duration << endl;
	cout << "Album: " << this->album << endl;
}



/*
NOTE:
the operator "new" has two forms--
1. one to allocate a single variable. (new dataType;)
2. one to allocate an array of variables. (new dataType[intExp];)

the operator "new" allocates memory (a variable) of the designated type and returns a pointer to it--meaning it returns the address of this allocated memory. The allocated memory is uninitialized.
*/

/*
q = new char[16];
 this creates an array of 16 char type components and stores the base address of the array in q.
 because a dynamic variable is unnamed, it cannot be accessed directly. it is accessed indirectly by the pointer returned by new.
 */

/*
str = new string; //allocates memory of type string and stores the address of the memory in str
*str = "Sunny Day"; //stores the string "Sunny Day" in the memory pointed to by str
*/

