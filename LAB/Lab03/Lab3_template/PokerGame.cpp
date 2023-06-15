#include "PokerGame.h"

void PokerGame::Distribute(bool usedCards[52])
{	
	//TO_DO: Random generate five cards to player
	//Hint: Use usedCards to record which card have been distributed
	srand(time(NULL));
	while (playerCards.size() < 5)
	{
		int flag = -1;
		while (flag == -1) 
		{
			int x = rand() % 52;
			if (usedCards[x] == false)
			{
				usedCards[x] = true;
				playerCards.push_back(x);
				flag = 1;
			}
		}
	}
}

void PokerGame::set(vector<int> cards)
{
	for (int i = 0; i < 5; i++)
		playerCards.push_back(cards[i]);
}

void PokerGame::printCards()
{
	char shape[5] = { 'C','D','H','S' };
	cout << "Player cards:";
	
	for (int i = 0; i < 5; i++)
	{
		//TO_DO: Print the player's cards.
		// For example: "C1" "S2" "H3" ...
		cout << shape[(playerCards[i] / 13)] << playerCards[i] % 13+1 << " ";
	}
	cout << endl;
	
}

void PokerGame::sortCards()
{
	//TO_DO: Sort the cards accroding to thier number
	for (int i = 4; i >0; i--)
	{
		for (int j = 0; j <= i - 1; j++)
		{
			if (playerCards[j] % 13 > playerCards[j + 1] % 13)
			{
				int tmp = playerCards[j];
				playerCards[j] = playerCards[j + 1];
				playerCards[j + 1] = tmp;
			}
		}
	}

}

void PokerGame::evaluate()
{
	sortCards();
	if (this->isStraight() && this->isFlush())
	{
		Type = StraightFlush;
	}
	else if (this->isFourOfaKind())
	{
		Type = FourOfaKind;
	}
	else if (this->isFullHouse())
	{
		Type = FullHouse;
	}
	else if (this->isFlush())
	{
		Type = Flush;
	}
	else if (this->isStraight())
	{
		Type = Straight;
	}
	else if (this->isThreeOfaKind())
	{
		Type = ThreeOfaKind;
	}
	else if (this->isTwoPairs())
	{
		Type = TwoPairs;
	}
	else if (this->isOnePair())
	{
		Type = OnePair;
	}
	else
	{
		Type = Highcard;
	}
}

int PokerGame::getType()
{
	return Type;
}

void PokerGame::compare(int type)
{
	//TO_DO: Compare the type and output who is winner
	if (Type > type)	cout << "Player1 win" << endl;
	else if (Type < type)	cout << "Player2 win" << endl;
	else    cout << "Draw" << endl;
}

bool PokerGame::isStraight()
{
	//TO_DO: Check whether the hand of cards is Straight or not
	if ((playerCards[1] % 13 == playerCards[0] % 13 + 1) && (playerCards[2] % 13 == playerCards[0] % 13 + 2) && (playerCards[3] % 13 == playerCards[0] % 13 + 3) && (playerCards[4] % 13 == playerCards[0] % 13 + 4))
		return true;	
	return false;
}

bool PokerGame::isFlush()
{
	//TO_DO: Check whether the hand of cards is Flush or not
	if ((playerCards[0] / 13 == playerCards[1] / 13) && (playerCards[0] / 13 == playerCards[2] / 13) && (playerCards[0] / 13 == playerCards[3] / 13) && (playerCards[0] / 13 == playerCards[4] / 13))
		return true;
	return false;
}

bool PokerGame::isFourOfaKind()
{
	//TO_DO: Check whether the hand of cards is FourOfaKind or not
	int num[13] = { 0 }, times[5] = { 0 };
	for (int i = 0; i < 5; i++)
		num[playerCards[i] % 13]++;
	for (int i = 0; i < 13; i++)
		times[num[i]]++;
	if (times[4] == 1)
		return true;
	return false;
}

bool PokerGame::isFullHouse()
{
	//TO_DO: Check whether the hand of cards is FullHouse or not
	int num[13] = { 0 }, times[5] = { 0 };
	for (int i = 0; i < 5; i++)
		num[playerCards[i] % 13]++;
	for (int i = 0; i < 13; i++)
		times[num[i]]++;
	if (times[2] == 1&&times[3]==1)
		return true;
	return false;
}

bool PokerGame::isThreeOfaKind()
{
	//TO_DO: Check whether the hand of cards is ThreeOfaKind or not
	int num[13] = { 0 }, times[5] = { 0 };
	for (int i = 0; i < 5; i++)
		num[playerCards[i] % 13]++;
	for (int i = 0; i < 13; i++)
		times[num[i]]++;
	if (times[3] == 1 && times[1] == 2)
		return true;
	return false;
}

bool PokerGame::isTwoPairs()
{
	//TO_DO: Check whether the hand of cards is TwoPairs or not
	int num[13] = { 0 }, times[5] = { 0 };
	for (int i = 0; i < 5; i++)
		num[playerCards[i] % 13]++;
	for (int i = 0; i < 13; i++)
		times[num[i]]++;
	if (times[2] == 2 && times[1] == 1)
		return true;
	return false;
}

bool PokerGame::isOnePair()
{
	//TO_DO: Check whether the hand of cards is OnePair or not
	int num[13] = { 0 }, times[5] = { 0 };
	for (int i = 0; i < 5; i++)
		num[playerCards[i] % 13]++;
	for (int i = 0; i < 13; i++)
		times[num[i]]++;
	if (times[2] == 1 && times[1] == 3)
		return true;
	return false;
}



