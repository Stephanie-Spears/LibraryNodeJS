//
// Created by Stephanie Spears on 4/3/18.
//

#include "SongList.h"
#include "SongList.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


SongList::SongList() {
	first = nullptr;
	last = nullptr;
	count = 0; //no elements in list
}

SongList::SongList(const char fileName[]) {
	first = nullptr;
	last = nullptr;
	count = 0;
	loadSongs(fileName); //access member function w/ file path parameter
}

SongList::~SongList() {
	Node * current = first;
	while (first != nullptr) {
		current = first->next;
		delete first; //delete the node pointed to by head. The destructor for Song is invoked automatically
		first = current;
	}
}

/*DESTRUCTOR NOTES:

The destructor deallocates the memory occupied by the nodes of a list
when the class object goes out of scope. Because memory is allocated
dynamically, resetting the pointers first and last does not deallocate
the memory occupied by the noes in the list. We must traverse the list,
starting at the first node, and delete each node in the list. The list
can be destroyed by calling the function destroyList. Therefore, the
definition of the destructor is:

template <class Type>
linkedListType<Type>::~linkedListType()
{
destroyList();
}
*/

/* Reads the entries from the file and adds them to the list.
in: fileName*/
void SongList::loadSongs(const char fileName[]) {
	ifstream in;
	char title[MAX_CHAR];
	char artist[MAX_CHAR];
	char duration[MAX_CHAR];
	char album[MAX_CHAR];
	int index = 0;
	Song aSong;

	in.open(fileName);
	if (!in) {
		in.clear();
		cerr << endl << "Failed to open filename '" << fileName << "' for input!" << endl << endl;
		aSong.~Song();
		in.close();
		exit(1);
	}

	in.getline(title, MAX_CHAR, ';');
	aSong.setTitle(title);
	while (!in.eof()) {
		in.getline(artist, MAX_CHAR, ';');
		aSong.setArtist(artist);
		in.getline(duration, MAX_CHAR, ';');
		aSong.setDuration(duration);
		in.getline(album, MAX_CHAR, '\n');
		aSong.setAlbum(album);
		index++;
		addSong(aSong);
		/*SongList::addSong(const Song &aSong) -- it passes our local variable 'aSong' as a reference.
		Normally passing by reference (&) means it's treated as if it were passing the variable itself (whereas passing by value copies the contents and can be time-consuming)
		but by using "const Song &aSong" the function can't change the value.
		SongList function ::addSong does the following:
		-Takes the passed in const parameter "aSong" and runs the Song::getTitle(title) function, where "title" is a local variable inside addSong.
		-this sets the local variable "title" to the value stored in the member function "this->title"
		-Next, it takes SongList member pointer (of type Song) "list" and runs: list[size].setTitle(title);
		-this takes list and runs the function setTitle(title).
		FINALLY addSong(aSong) increments "size". size++.*/
		in.getline(title, MAX_CHAR, ';');
		aSong.setTitle(title);
	}
	in.close();
}

/*This function returns the size of the list.
return: size*/
int SongList::getSize() const {
	return count;
}

/* Searches the list for an entry with passed in artist.
in: artist
out: match
return: true if a match is found and match will be returned through parameter.
false if a match can not be found.*/
bool SongList::searchArtist(const char artist[], Song &match) const {
	Node * current;
	char currentTitle[MAX_CHAR];
	char currentArtist[MAX_CHAR];
	char currentDuration[MAX_CHAR];
	char currentAlbum[MAX_CHAR];

	for (current = first; current != nullptr; current = current->next){ //our current pointer is set to the beginning ("first"), while the pointer isn't empty (NULL), iterate through the list by setting current to the address of the "next" node.
		current->data.getTitle(currentTitle);//makes the pointer "current" point to the address for "data." Data is then accessing it's Song member function (getTitle), and passing is storing the function's local variable "this->title" inside of our current function's "currentTitle" variable.
		current->data.getArtist(currentArtist);
		current->data.getDuration(currentDuration);
		current->data.getAlbum(currentAlbum);
		if (strcmp(artist, currentArtist) == 0) {
			match.setTitle(currentTitle);
			match.setArtist(currentArtist);
			match.setDuration(currentDuration);
			match.setAlbum(currentAlbum);
			cout << endl << currentTitle << endl << currentArtist << endl << currentDuration << endl << currentAlbum << endl << endl;
		}
	}
	if (!current) {
		return false;
	}
	else{
		return true;
	}
}



/* This function searches the list for an entry with passed in album.
in: album
out: match
return: true if a match is found and match will be returned through parameter.
false if a match can not be found and match contains garbage.*/
bool SongList::searchAlbum(const char album[], Song &match) const {
	Node * current;
	char currentTitle[MAX_CHAR];
	char currentArtist[MAX_CHAR];
	char currentDuration[MAX_CHAR];
	char currentAlbum[MAX_CHAR];

	for (current = first; current != nullptr; current = current->next) {
		current->data.getTitle(currentTitle);
		current->data.getArtist(currentArtist);
		current->data.getDuration(currentDuration);
		current->data.getAlbum(currentAlbum);
		if (strcmp(album, currentAlbum) == 0) {
			match.setTitle(currentTitle);
			match.setArtist(currentArtist);
			match.setDuration(currentDuration);
			match.setAlbum(currentAlbum);
			cout << endl << currentTitle << endl << currentArtist << endl << currentDuration << endl << currentAlbum << endl << endl;
		}
	}
	if (!current) {

		return false;
	}
	else{
		return true;
	}
}

/*Prints all the entries to the standard output.*/
void SongList::printAll() const {
	Node * current;

	int index = 0;

	char title[MAX_CHAR];
	char artist[MAX_CHAR];
	char duration[MAX_CHAR];
	char album[MAX_CHAR];

	for (current = first; current; current = current->next) {

		current->data.getTitle(title);
		current->data.getArtist(artist);
		current->data.getDuration(duration);
		current->data.getAlbum(album);

		cout << "Index: " << index << endl;

		index++;
		cout << "Title: " << title << endl << "Artist: " << artist << endl << "Duration: " << duration << endl << "Album: " << album << endl << endl;
	}
}

/* Saves the list to the external file.
in: fileName*/
void SongList::saveSongs(const char fileName[]) const {
	ofstream out;
	Node * current;
	char title[MAX_CHAR];
	char artist[MAX_CHAR];
	char duration[MAX_CHAR];
	char album[MAX_CHAR];

	out.open(fileName);
	if (!out) {
		out.clear();
		cerr << endl << "Failed to open filename '" << fileName << "' for output." << endl << endl;
		exit(1);
	}

	for (current = first; current; current = current->next) {
		current->data.getTitle(title);
		current->data.getArtist(artist);
		current->data.getDuration(duration);
		current->data.getAlbum(album);

		out << title << ';' << artist << ';' << duration << ';' << album << endl;
	}
	out.close();
}

/* This function adds a song entry ordered by title.
in: aSong*/
void SongList::addSortedSong(const Song &aSong) {

	char title[MAX_CHAR];
	char currentTitle[MAX_CHAR];


	aSong.getTitle(title);
//here auto replaced Node * as a suggestion
	auto newNode = new Node(aSong);

	Node * back = nullptr;
	Node * current = first;

	while (current) {
		current->data.getTitle(currentTitle);
		if (strcmp(title, currentTitle) < 0) {
			break;
		}
		back = current;
		current = current->next;

	}

	newNode->next = current;

	if (!back) {
		first = newNode;
	}
	else {
		back->next = newNode;
	}
	count++;
}

/* This function adds a song to the beginning of the list.
in: aSong*/
void SongList::addSong(const Song &aSong) {
	addSortedSong(aSong);

}

/* This function returns the Song object at the specified position through parameter
in: index
out: aSong
return: true if the entry exists, false if illegal index is passed in*/
bool SongList::get(int index, Song &deleteSong, Song& aSong) const {
	char title[MAX_CHAR];

	if (index < 0 || index >= count) {
		cout << "Index not found. " << endl;
		return false;
	}

	Node * current = first;

	if (first == nullptr) {
		cout << "List is empty." << endl;
		return false;
	}
	else {

		for (int i = 0; i < index; i++){ //stops at index to delete
			current = current->next;
		}
		current->data.getTitle(title);
		current->data.setTitle(title);

		Node * currentNode;
		char currentTitle[MAX_CHAR];

		for (currentNode = first; currentNode != nullptr; currentNode = currentNode->next) {

			currentNode->data.getTitle(currentTitle); //going through the currentNode and assigning it data
			if (strcmp(currentTitle, title) == 0) {
				//?	delete currentNode;
				//?	delete current;
				return true;
			}
		}

		return false;
	}
}

/* This function removes a passed in song from the list.
in: aSong*/
void SongList::removeSong(int index, Song& deleteSong, Song& aSong) {
	Song song;
	Node * current;
	Node * trailCurrent;
	bool found;
	int currentIndex = 0;


	current = first;
	found = false;


	if (get(index, deleteSong, song) == true) {
		while (current != nullptr && !found){
			if  (currentIndex == index)	{//if the currentIndex is delete
				found = true;
			}
			else {//this only executes if the item we want to delete isn't in the first node. so we know there is more than one node, so we can update the traversers
				trailCurrent = current; //set the prev node to the current node
				current = current->next; //set the current node to point to the next node
				currentIndex++;
			}
		}

		if (current == nullptr) { //if current is empty
			cout << "List has been initialized empty. Cannot delete from an empty list." << endl;
		}
		else {
			if (currentIndex == index) { //if the item to be deleted is found at our current traversing address (currentIndex, or current->data == deleteItem)
				if (first == current){ //if the item to be deleted is in the first node
					cout << "Item to be deleted is the first in the list." << endl;
					first = first->next; //set the new "first" node to the address of the next node. (ie. remove the first node)
					if (first == nullptr) { //if the updated first now points to an empty node
						last = nullptr; //update the last pointer to empty.
					}
					delete current; //delete our traverser
				}
				else { //if item to be deleted isn't in the first node
					cout << "Item to be deleted isn't the first item in the list" << endl;
					trailCurrent->next = current->next; //copies current's next into trailCurrent's next
					//	if (current == last)
					if (index == (count-1)) { //if the item we want to delete is in the last node ? why doesn't the book's example if(current==last) work?
						cout << "Item to be deleted is the last in the list." << endl;
						last = trailCurrent; //set the last address to the "one before last" node?
					}
					delete current;
				}
				count--;
			}
			else { //if the list isn't empty, but the item to be deleted isn't in it.
				cout << "List is not empty, but item to be deleted was not found." << endl;
			}
		}
	}

}