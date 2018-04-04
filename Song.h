//
// Created by Stephanie Spears on 4/3/18.
//

#ifndef LIBRARYNODEJS_SONG_H
#define LIBRARYNODEJS_SONG_H

const int MAX_CHAR = 50;


class Song {
public:
//	Constructors
	Song();
	Song(const char title[], const char artist[], const char duration[], const char album[]);/*declaring const formal param prevents function from changing value of arguments, even when var are passed by reference */

	// 	Destructor
	virtual ~Song();

	// Accessor Functions
	void getTitle(char title[]) const;
	void getArtist(char artist[]) const;
	void getDuration(char duration[]) const;
	void getAlbum(char album[]) const;
	void print() const;
/*	When a function is declared as const, it can be called on any type of object. Non-const functions can only be called by non-const objects.*/

	// Mutator Functions
	void setTitle(const char title[]);
	void setArtist(const char artist[]);
	void setDuration(const char duration[]);
	void setAlbum(const char album[]);


private:
	char *title; //pointer var->var content=mem address
	char *artist;
	char *duration;
	char *album;


};


#endif //LIBRARYNODEJS_SONG_H

/*
 * "*" is a pointer variable, whose content is a memory address
 "&" is the address operator, it returns the address of its operand
 (ex: int x; int *p; ...  p = &x;) <- this sets p = to the address of x. So now x and p both refer to the same memory location.
*/

//Song aSong; //this is an object of type Song
//Song *aSongPointer; //this is a pointer variable of type Song
//
//aSongPointer = &aSong; //this stores the address of aSong into aSongPointer.
//
//aSongPointer->artist = "artist name";//this stores "artist name" in the artist[] component of the object aSong.
