#include <iostream>
#include "ADBConnector.h"

int main()
{
	athena::ADBConnector db;
	db.connectTo("localhost", "yy", "root", "", 3306);

	if (!db.isConnected())
	{
		std::cout << "Á¬½ÓÊ§°Ü";
	}

	athena::AQuery query = db.query("select * from mark");
	if (query.rowNum() == 0)
	{
		std::cout << "Ñ¡ÔñÊ§°Ü";
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