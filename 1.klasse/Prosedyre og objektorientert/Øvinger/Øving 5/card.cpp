#include <iostream>
#include <vector>
#include "card.h"
using namespace std;

string suitToString(Suit s) {
	switch (s) {
	case CLUBS: return "Clubs"; break;
	case DIAMONDS: return "DIAMONDS"; break;
	case HEARTS: return "HEARTS"; break;
	case SPADES: return "SPADES"; break;
	default: return "You made an illegal choice";
	}
}


string rankToString(Rank r) {
	switch (r){ 
	case TWO: return "Two"; break;
	case THREE: return "Three"; break;
	case FOUR: return "Four"; break;
	case FIVE: return "Five"; break;
	case SIX: return "Six"; break;
	case SEVEN: return "Seven"; break;
	case EIGHT: return "Eight"; break;
	case NINE: return "Nine"; break;
	case TEN: return "Ten"; break;
	case JACK: return "Jack"; break;
	case QUEEN: return "Queen"; break;
	case KING: return "King"; break;
	case ACE: return "Ace"; break;
	default: return "You made an illegal choice";
	}
}


string toString(CardStruct card) {
	string suit = suitToString(card.s);
	string rank = rankToString(card.r);
	return rank + " of " + suit;
}

string toStringShort(CardStruct card) {
	string suit = suitToString(card.s).substr(0, 1);
	string rank = to_string(card.r);
	string kort = suit + rank;
	return  kort;
}

void card::initialize(Suit suit, Rank rank) {
	this->suit = suit;
	this->rank = rank;
	valid = true;
}

string card::getSuit() {
	return suitToString(suit); 
}

Rank card::getRank() {
	return rank;
}

string card::toString() {
	string s = suitToString(suit);
	string r = rankToString(rank);
	if (valid == true) {
		return s + " of " + r;
	}
	else {
		return "Ugylding kort";
	}

}

string card::toStringShort() { 
	string s = (suitToString(suit)).substr(0.1);
	string r = to_string(rank);
	if (valid == true) {
		return s + r;
	}else {
		return "ugylding kort";
	}
}

card::card() {
	valid = false;
}

card::card(Suit suit, Rank rank) {
	this->suit = suit;
	this->rank = rank;
	valid = true;
}


CardDeck::CardDeck() { //Hvordan kjøre funksjonen(teste)? Hvorfor static_cast?
	for (int i = 0; i < 4; i++) {
		for (int j = 2; j < 15; j++) {
			card a (static_cast <Suit>(i),static_cast <Rank>(j));
			cards.push_back(a);
		}
	}
	currentCardIndex = 0;
}

void CardDeck::swap(int a, int b) {
	card temp = cards[a];
	cards[a] = cards[b];
	cards[b] = temp;
}

void CardDeck::print() {
	for (int i = 0; i < cards.size(); i++) {
		//cout << cards[i] << endl; Hvorfor ikke sånn?
		cout << cards[i].toString() << endl;
	}
}

void CardDeck::printShort() {
	for (int i = 0; i < cards.size(); i++) {
		card c = card(cards[i]);
		cout << c.toStringShort() << endl;
	}
}

void CardDeck::shuffle() {
	for (int i = 0; i < 1000; i++) {
		int num1 = rand() % 52;
		int num2 = rand() % 52;
		card temp = cards[num1];
		cards[num1] = cards[num2];
		cards[num2] = temp;
	}
}

card CardDeck::drawCard() {
	currentCardIndex ++;
	return cards[currentCardIndex - 1];
}




bool Blackjack::isAce(card* card) {
	return ((*card).getRank() == ACE); 
}

int Blackjack::getCardValue(card* card) {
	if (isAce(card)) {
		return -1;
	}
	else {
		int rank = (*card).getRank();
		if (rank > 10) return 10;
		else return rank;
	}
}


int Blackjack::getPlayercardValue(card* card) {
	if (isAce(card)) {
		int value = 0;
		while (value != 1 && value != 11) {
			cout << "Hvilken verdi skal esset ha, 1 eller 11? ";
			cin >> value;
		}
		cout << "Esset fikk verdien " << value << endl;
		return value;
	}
	else {
		return getCardValue(card);
	}
}

int Blackjack::getDealerCardValue(card* card, int dealerHand) {
	if (isAce(card)) {
		if (dealerHand + 11 > 21) {
			return 1;
		}else {
			return 11;
		}
	}else {
		return getCardValue(card);
	}
}

bool Blackjack::askPlayerDrawCard() {
	char answer = 0;
	while (answer != 'J' && answer != 'N') {
		std::cout << "Vil du trekke et kort til (j/n)? ";
		std::cin >> answer;
		answer = toupper(answer);
	}
	return (answer == 'J');
}

