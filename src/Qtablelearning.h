#ifndef QTABLELEARNING_H
#define QTABLELEARNING_H

#include <string>
#include <iostream>

class Qtablelearning
{
private:

public:
	Qtablelearning();
	~Qtablelearning();
	
	//Save the q-learning table in a .txt
	void saveTable(std::string tableName);
	void saveTable(std::string tableName, std::string pathToSave);
};

#endif