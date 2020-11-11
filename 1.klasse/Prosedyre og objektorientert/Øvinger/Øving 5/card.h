#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES}; 
enum Rank {TWO = 2, THREE = 3, FOUR = 4, FIVE =5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 11, QUEEN = 12, KING = 13, ACE = 14}; //Verdi
string suitToString(Suit s);
string rankToString(Rank r);

struct CardStruct {
	Suit s;
	Rank r;
};

string toString(CardStruct card);
string toStringShort(CardStruct card);

class card {
private:
	Suit suit;
	Rank rank;
	bool valid;
public:
	card();
	card(Suit suit, Rank rank);
	void initialize(Suit suit, Rank rank);
	string getSuit();
	Rank getRank();
	string toString();
	string toStringShort();
};

class CardDeck {
private:
	vector <card> cards;
	int currentCardIndex;
	void swap(int a, int b);
public:
	CardDeck(); //Hvorfor ikke datatype foran?
	void print();
	void printShort();
	void shuffle();
	card drawCard();
};

class Blackjack {
private:
	vector <CardDeck> deck;
	int playerHand, dealerHand, playerCardsDrawn, dealerCardsDrawn;

public:
	bool isAce(card* card);
	int getCardValue(card* card);
	int getPlayercardValue(card* card);
	int getDealerCardValue(card* card, int dealerHand);
	bool askPlayerDrawCard();
};

