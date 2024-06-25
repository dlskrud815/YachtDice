#pragma once

#include "NetworkManager.h"

class GameManager 
{
public:
	GameManager(int m_radio)	//持失切
	{
		NetworkManager networkmanager;
		switch (m_radio)
		{
		case 0:
			break;
		case 1:
			this->networkmanager = networkmanager;
			break;
		case 2:
			break;
		}
	}

	~GameManager()	//社瑚切
	{
	
	}

	void SetUsername(CString m_username) { this->m_username = m_username; }
	void SetRadio(int m_radio) { this->m_radio = m_radio; }

	CString GetUsername() { return this->m_username; }
	int GetRadio() { return this->m_radio; }

private:
	CString m_username;
	int m_radio;
	NetworkManager networkmanager;
};