#ifndef QTABLELEARNING_H
#define QTABLELEARNING_H

#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>

class Qtablelearning
{
private:
	//States and actions to the fomulate Qtable
	unsigned int states;
	unsigned int actions;

	//Qtable - matrix of double [states][actions]
	double **Qtable;

	//Const of Bellman equactions
	double learningRate = 0.8;
	double Gamma = 0.95;

	//Last state
	unsigned int lastState = 0;

public:
	Qtablelearning(const unsigned int states, const unsigned int actions);
	Qtablelearning(const unsigned int states, const unsigned int actions, double lr, double g);
	
	//Get max action in table with the state determined
	std::pair<double,int> getMaxAction(const unsigned int curState);

	//Get the reward of the environment
	double reward();

	//Function to update the Qtable (Q-learning table algorithm)
	void updateQtable(const int curState, const int curAction, double r);

	//Get random action to act in the environment
	int getRandomAction();

	//Save the q-learning table in a file
	void saveTable(std::string tableName);
	void saveTable(std::string tableName, std::string pathToSave);

	//Get table from file
	void getTableFromFile(std::string tableName);
	void getTableFromFile(std::string tableName, std::string pathToGet);

	//Setting and configuring learning rate or gamma
	void setLearningRate(double lr){ this->learningRate = lr; };
	void setGamma(double g){ this->Gamma = g;};
	
	//Print the QTable
	void printQtable();

	//Get Qtable
	double** getQtable(){ return this->Qtable; }

	//Set last state
	void setLastState(unsigned int ls){ this->lastState = ls; }
};

#endif