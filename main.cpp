//
// Created by Stephanie Spears on 4/3/18.
//

#include <iostream>

#include "UserInterface.h"
#include "InputTools.h"
#include "Song.h"
#include "SongList.h"

using namespace std;
//TODO: clean up unused imports, separate headers and implementations more cleanly


//RENAME MAIN TO CALLABLE FUNCTION
int main() {


	char command;
	char fileName[] = "/Users/wolfmac/CLionProjects/MusicLibrary/songs.txt";
	SongList list(fileName);
	Song aSong;

	displayMenu();
	command = readInCommand();

	while (command != '6') {
		processCommand(command, list);
		displayMenu();
		command = readInCommand();
	}

	list.saveSongs(fileName);

	return 0;
}