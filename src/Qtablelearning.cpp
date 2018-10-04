#include "Qtablelearning.h"

Qtablelearning::Qtablelearning(const unsigned int states, const unsigned int actions){
	this->states = states;
	this->actions = actions;

	this->Qtable = new double*[states];
	for(int i = 0; i<actions; ++i){
		this->Qtable[i] = new double[actions];
	}

	for (int i = 0; i < states; ++i)
	{
		for (int j = 0; j < actions; ++j)
		{
			this->Qtable[i][j] = 0;
		}
	}
}

std::pair<double,int> Qtablelearning::getMaxAction(const unsigned int curState){
	double max = 0;
	int index = 0;
	for (int i = 0; i < this->actions; ++i)
	{
		if(this->Qtable[curState][i]>max){
			max = this->Qtable[curState][i]; 
			index = i;
		}	
	}
	return std::make_pair(max, index);
}

double Qtablelearning::reward(){
	//TODO
}

void Qtablelearning::updateQtable(){
	//TODO
}

void Qtablelearning::saveTable(std::string tableName){
	std::ofstream f(tableName);
	for (int i = 0; i < this->states; i++){
		for (int j = 0; j < this->actions; j++){
	    	f << this->Qtable[i][j]<<" ";
	  	}
	}
	f.close();
}

void Qtablelearning::saveTable(std::string tableName, std::string pathToSave){
	std::ofstream f(pathToSave+"/"+tableName);
	for (int i = 0; i < this->states; i++){
		for (int j = 0; j < this->actions; j++){
	    	f << this->Qtable[i][j]<<" ";
	  	}
	}
	f.close();
}

void Qtablelearning::getTableFromFile(std::string tableName){
	std::ifstream f(tableName);
	for (int i = 0; i < this->states; i++){
		for (int j = 0; j < this->actions; j++)
		  f >> this->Qtable[i][j];
	}
	f.close();
}

void Qtablelearning::getTableFromFile(std::string tableName, std::string pathToGet){
	std::ifstream f(pathToGet+"/"+tableName);
	for (int i = 0; i < this->states; i++){
		for (int j = 0; j < this->actions; j++)
		  f >> this->Qtable[i][j];
	}
	f.close();
}