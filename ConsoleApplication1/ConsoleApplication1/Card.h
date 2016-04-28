#pragma once
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Card
{
private:
	string cardTypeName;
	bool faceUp;
	bool matched;
	char symbol;

public:
	Card(bool, bool);
	~Card();
	string getCardTypeName();
	bool isMatched();
	void setToMatch();
	void showFace();
	void hideFace();
	bool isFaceUp();
	void flipCard();
	bool operator!() const;
	bool equals(Card);
	bool operator==(Card);
	void match(Card &);

};
