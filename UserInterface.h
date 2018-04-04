//
// Created by Stephanie Spears on 4/3/18.
//

#ifndef LIBRARYNODEJS_USERINTERFACE_H
#define LIBRARYNODEJS_USERINTERFACE_H

#include "Song.h"
#include "SongList.h"
#include "InputTools.h"

void displayMenu();
char readInCommand();
void processCommand(char command, SongList& list);
void readInSong(Song& aSong);
int readIndex(); //should i make this void?
void readSearchArtist(char artist[]);
void readSearchAlbum(char album[]);

#endif //LIBRARYNODEJS_USERINTERFACE_H
