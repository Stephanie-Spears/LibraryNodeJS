//
// Created by Stephanie Spears on 4/3/18.
//

#ifndef LIBRARYNODEJS_SONGLIST_H
#define LIBRARYNODEJS_SONGLIST_H

#include "Song.h"

class SongList {
public:
	//Constructors
	SongList();
	explicit SongList(const char fileName[]);

	//Destructors
	~SongList();

	//Accessor Functions
	bool get(int index, Song &deleteSong, Song& aSong) const;
	bool searchArtist(const char artist[], Song& match) const;
	bool searchAlbum(const char album[], Song& match) const;
	int getSize() const;
	void printAll() const;
	void saveSongs(const char fileName[]) const;

	//Mutator Functions
	void addSong(const Song& aSong);
	void addSortedSong(const Song& aSong);
	void removeSong(int index, Song& deleteSong, Song& aSong);
	void loadSongs(const char fileName[]);

private:
	struct Node {
		Song data;
		Node * next;
		Node * back;
		Node(const Song& aData) {
			char title[MAX_CHAR];
			char artist[MAX_CHAR];
			char duration[MAX_CHAR];
			char album[MAX_CHAR];

			aData.getTitle(title);
			aData.getArtist(artist);
			aData.getDuration(duration);
			aData.getAlbum(album);


			data.setTitle(title);
			data.setArtist(artist);
			data.setDuration(duration);
			data.setAlbum(album);
		}
	};
	Node * first;
	Node * last;
	int count;
};


#endif //LIBRARYNODEJS_SONGLIST_H



/*NOTES
A linked list is a collection of components called NODES. Every node EXCEPT the LAST one contains the address of the NEXT node.
		Thus, every node in a linked list has two components: one to store data, and one to store the address (called the LINK) of the NEXT node in the list.
		The address of the FIRST node in the list is stored in a separate location called HEAD or FIRST.

		head->info .. the arrow indicates that the address of the node to which it is pointing is stored in that node.
		if head's address is "2000" and the info stored is "17", then the statement head->info will equal "17"--because head's address (2000) is pointing to the data stored there ("17").

		Because each node of a linked list has two components (info/data and the link which points to the address of that info/data),
		we need to declare each node as a CLASS or STRUCT.
		*/