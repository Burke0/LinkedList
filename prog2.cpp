/*
 * prog2.cpp
 * Created on: Oct 8, 2019
 * Author:J. Alex Burke
 * This program simulates a railway-switching yard using linked lists. Each TrainCar acts as a node for a train.
 */
#include "train.h"
#include <string>
#include <iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>

using namespace std;
/**********************************************************************************************************
 *                                                                                                        *
 * The main function in this program loads data from from a text file.                                    *
 * Then it calls functions of Train class to create and fill the nodes(train car's)                       *
 * of a source train with the appropriate data. It also outputs the weight of the train to the console.   *
 *                                                                                                        *
 * Next, it uses The trainCarSwap function to move nodes from the source train to three other trains      *
 * which depends on the "destination" data member of each trainCar.                                       *
 * It outputs each track every time a trainCar is switched.                                               *
 * When there are no more nodes(TrainCar's) on the source train, it outputs each of the new three trains  *
 * and their weights to the console.                                                                      *
 *                                                                                                        *
 * There is a line of code for Sample Execution I and II in a while loop. To see each one,                *
 * simply comment the other out.                                                                          *
 **********************************************************************************************************/
int main()
{

	Train train1, train2Roanoke, train3Portsmouth, train4Other;
	ifstream in;
	in.open("arrivingtrain.txt");
	while(!in)
	{
		cerr<<"no file open"<<endl;
		string fileName;
		cout<<"please enter file name: "<<endl;
		cin>>fileName;
		in.open(fileName);
	}
	while(!in.eof())
	{
		train1.addTrainCarAtEnd(in);//SAMPLE EXECUTION I
		//train1.addTrainCarAscendingWeight(in);//SAMPLE EXECUTION II
		//train1.addTrainCarAtBeg(in);//MISC
	}
	cout<<"Track 0: ";
	train1.printTrain();
	cout<<endl<<"Total weight: "<<train1.getTrainWeight()<<endl<<endl;
	cout<<"Switching starts..."<<endl<<endl;
	while(train1.pHead!=NULL)
	{
		if(train1.pHead->destination=="Roanoke")
			train1.trainCarSwap(train2Roanoke);
		else if(train1.pHead->destination=="Portsmouth")
			train1.trainCarSwap(train3Portsmouth);
		else
			train1.trainCarSwap(train4Other);
		cout<<"Track 0: ";
		train1.printTrain();
		cout<<"\nTrack 1: ";
		train2Roanoke.printTrain();
		cout<<"\nTrack 2: ";
		train3Portsmouth.printTrain();
		cout<<"\nTrack 3: ";
		train4Other.printTrain();
		cout<<endl<<endl;
		}
	cout<<"Final: "<<endl<<endl<<"Track 1: ";
	train2Roanoke.printTrain();
	cout<<"\nTotal weight: "<<train2Roanoke.getTrainWeight()<<endl;
	cout<<"Track 2: ";
	train3Portsmouth.printTrain();
	cout<<"\nTotal weight: "<<train3Portsmouth.getTrainWeight()<<endl;
	cout<<"Track 3: ";
	train4Other.printTrain();
	cout<<"\nTotal weight: "<<train4Other.getTrainWeight()<<endl;
	in.close();
	return 0;
}



