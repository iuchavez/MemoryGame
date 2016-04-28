#include "Card.h"



Card::Card(bool, bool)
{
}


Card::~Card()
{
}

// Precondition: None
// Postconition: The name of the card type as overloaded by the sub classes
// Purpose: To gain access to the encapsulated data members, providing a way to compare two Card objects
string Card::getCardTypeName()
{
	return cardTypeName;
}

// Precondition: None
// Postcondition: The status of the bool variable matched, false if not matched yet and true if already matched
// Purpose: Allows for us to test which cards have been matched
bool Card::isMatched()
{
	return matched;
}

// Precondition: None
// Postcondition: Changes the status of a card from unmatched to matched
// Purpose: Making the object status matched
void Card::setToMatch()
{
	matched = true;
}

// Precondition: None
// Postcondition: The status of the card with respect to the faceUp data member is set to true
// Purpose: To have an objective way of making a Card become face up
void Card::showFace()
{
	faceUp = true;
}

// Precondition: None
// Postcondition: The status of the card with respect to the faceUp data member is set to false
// Purpose: To have an objective way of making a Card become face down
void Card::hideFace()
{
	faceUp = false;
}

// Precondition: None
// Postcondition: Returns true if the card is face up
// Purpose: To check if the card is face up, allowing us to overlook cards that have already been won
bool Card::isFaceUp()
{
	return faceUp;
}

// Precondition: None
// Postcondition: The status of the card with respect to the faceUp data member is inverted
// Purpose: Provides a relative means to change the status of a Card to face up
void Card::flipCard()
{
	// An alias is created for faceUp to make more readable
	bool cardStatus = &faceUp;
	// This means that the current status of the card is changed
	cardStatus = !cardStatus;
}

// Precondition: None
// Postcondition: The status of the card with respect to the faceUp data member is inverted
// Purpose: Provides a relative means to change the status of a Card to face up
bool Card::operator!() const
{
	// An alias is created for faceUp to make more readable
	bool cardStatus = &faceUp;
	// This means that the current status of the card is changed
	cardStatus = !cardStatus;
	return cardStatus;
}

// Precondition: The card that calls this function (implied) and a Card that the user wishes to compare with
// Postcondition: Returns true if the both Card objects have the same cardTypeName
// Purpose: Needed to form a conditional that is the precondition the the match(Card) function
bool Card::equals(Card rhs)
{
	// Comparison with respect to cardTypeName
	if (cardTypeName == rhs.cardTypeName) {
		return true;
	}
	else {
		return false;
	}
}

// Precondition: The card that calls this function (implied) and a Card that the user wishes to compare with
// Postcondition: Returns true if the both Card objects have the same cardTypeName
// Purpose: Overloaded operator makes code more readable. Needed to form a conditional that is the precondition 
//          the the match(Card) function
bool Card::operator==(Card rhs)
{
	// Comparison is by the cardTypeName;
	if (cardTypeName == rhs.getCardTypeName()) {
		return true;
	}
	else {
		return false;
	}
}

// Predondition: The implicit and explicit objects associated with this method must first have been compared
//				 with each other and returned a value of true. Then, either Card object can call this method
//				 and pass the other Card object as a parameter
// Postcondition: Both the implicit and explicit Card objects will have have a value of true for their matched data member
// Purpose: To advance the memory game by keeping track of the Cards that have already been won/guessed
void Card::match(Card & match)
{
	// This object set match to true
	setToMatch();
	// Explicit parameter likewise set match to true;
	match.setToMatch();
}
