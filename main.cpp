#include <iostream>
#include <string>

using namespace std;

class Player
{
public:
	Player(const string& name = " ");
	string GetName() const;
	Player* GetNext() const;
	void SetNext(Player* next);
	
private:
	string m_Name;
	// 次のプレイヤ
	Player* m_pNext;	
};

Player::Player(const string& name):
	m_Name(name),
	//ヌルポインタ
	m_pNext(0)			
{}

string Player::GetName() const
{
	return m_Name;
}

Player* Player::GetNext() const
{
	return m_pNext;
}

void Player::SetNext(Player* next)
{
	m_pNext = next;
}

class Lobby
{
	friend ostream& operator<<(ostream& os, const Lobby& aLobby);
	
public:
	Lobby();
	~Lobby();
	void AddPlayer();
	void RemovePlayer();
	void Clear();
	
private:
	Player* m_pHead;//プレイヤーリスト
};

Lobby::Lobby():
	//ヌルポインタ
	m_pHead(0)			
{}

Lobby::~Lobby()
{
	Clear();
}

void Lobby::AddPlayer()//プレイヤーの追加
{
	//新しいプレイヤノードを作成
	cout << "Please enter a name of the new player: ";
	string name;
	cin >> name;
	Player* pNewPlayer = new Player(name);
	
	//リストは空っぽの状態だと、新しいプレイヤがリストの最初の項目となる
	// if list is empty, make head of list this new player
	if (m_pHead == 0)
	{
		m_pHead = pNewPlayer;
	}
	//　ではなければリストの最終項目に追加する
	// otherwise find the end of the list and add the player there
	else
	{
		Player* pIter = m_pHead;
		while (pIter->GetNext() != 0)
		{
			pIter = pIter->GetNext();
		}
		pIter->SetNext(pNewPlayer);
	}
}

void Lobby::RemovePlayer()
{
	if (m_pHead == 0)//プレイヤーリストが0だったら
	{
		//ゲームロビーには誰もいません。削除することができません。
		cout << "The game lobby is empty.	No one to remove!\n";
	}
	else
	{
    //リストの一番最初のプレイヤーを削除
		Player* pTemp = m_pHead;
		m_pHead = m_pHead->GetNext();
		delete pTemp;
	}
