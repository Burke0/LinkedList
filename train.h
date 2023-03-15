/*
 * train.h
 *
 *  Created on: Oct 8, 2019
 *  Author: J. Alex Burke
 */

#ifndef TRAIN_H_
#define TRAIN_H_
#include<string>

using namespace std;
struct TrainCar
	{
		string id,contents,weight,origin,destination;
		TrainCar *next;
	};
class Train
{
	public:
	TrainCar* pHead;
	Train();
	void addTrainCarAtBeg(ifstream& in);
	void addTrainCarAtEnd(ifstream& in);
	void addTrainCarAscendingWeight(ifstream& in);
	void trainCarSwap(Train& tr2);
	void printTrain();
	float getTrainWeight();
};


#endif /* TRAIN_H_ */
