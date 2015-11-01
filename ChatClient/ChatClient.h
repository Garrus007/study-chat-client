#pragma once

/*
�������� �� ����� ������� � ��������
*/

#include <Windows.h>
#include "Packets.h"
#include <string>

class ChatClinet
{
public:

	bool ConnectToServer(const TCHAR* pipe_name);
	bool Login(std::string name, std::string password);
	bool Register(std::string name, std::string password);
	bool SendChatMessage(std::string message);
	bool LoadChat(Chat& chat);
	bool GetUsers(QList<User>& users);
	void Disconnect();

	~ChatClinet();

private:
	HANDLE pipe;
	User me;

	//���������� ������ � ������ ������
	bool send(char* buffer, int size, HANDLE pipe);

	//��������� ������
	int receive(char*& buffer, HANDLE pipe);

	//���������� ��� ���������
	PacketTypes get_type(char* buffer);
};