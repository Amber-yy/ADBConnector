#include <iostream>
#include "ADBConnector.h"

int main()
{
	athena::ADBConnector db;
	db.connectTo("localhost", "yy", "root", "", 3306);

	if (!db.isConnected())
	{
		std::cout << "����ʧ��";
	}

	athena::AQuery query = db.query("select * from mark");
	if (query.rowNum() == 0)
	{
		std::cout << "ѡ��ʧ��";
	}
	else
	{
		while (query.next())
		{
			std::cout<<query["score"];
		}
	}

	return 0;
}