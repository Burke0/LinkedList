/*
 * train.cpp
 *
 *  Created on: Oct 8, 2019
 *  Author: J. Alex Burke
 */
#include "train.h"
#include <string>
#include <iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>

Train::Train()//initialize a train
{
	pHead=new TrainCar();
	pHead=NULL;
}
/*
 * addTrainCarAtBeg adds a trainCar(node) to the beginning of a train(linked list).
 * It uses the input file stream as a parameter so that it can read a line
 * from the text file containing the information on each train car.
 * The information is stored in a bunch of strings which are data members of the trainCar structure.
 * 1)new trainCar created and filled with data
 * 2)It's next pointer is set to point to the head of the train, and the head
 * 		is assigned to point to the new TrainCar making this new node the head of the train.
 * 3)the new trainCar is set to be a null pointer beacuse it is no longer needed.
 */
void Train::addTrainCarAtBeg( ifstream& in)
{
	TrainCar* pNew= new TrainCar();
	in>>pNew->id>>pNew->contents>>pNew->weight>>pNew->origin>>pNew->destination;
	pNew->next=pHead;
	pHead=pNew;
	pNew=NULL;
}
/***************************************************************************************************************
 * addTrainCarAtEnd adds a trainCar(node) to the end of a train(linked list).                                  *
 * It uses the input file stream as a parameter so that it can read a line                                     *
 * from the text file containing the information on each train car.                                            *
 * The information is stored in a bunch of strings which are data members of the trainCar structure.           *
 * If there are no nodes in the train, it makes the trainCar the first node.                                   *
 * Otherwise it walks through the train until if finds a trainCar with data member next being a null pointer.  *
 * This is where the end of the train is.                                                                      *
 * Then it makes a new trainCar and adds it to this location.                                           *                                                                        *
 ***************************************************************************************************************/
void Train::addTrainCarAtEnd(ifstream& in)
{

	if(pHead==NULL)
	{
		TrainCar* pNew=new TrainCar();
			in>>pNew->id>>pNew->contents>>pNew->weight>>pNew->origin>>pNew->destination;
			pNew->next=NULL;
		pHead=pNew;
	}
	else
	{
		TrainCar* pNew;
		pNew=pHead;
		while(pNew->next!=NULL)
		{
			pNew=pNew->next;
		}
		pNew->next=new TrainCar();
		in>>pNew->next->id>>pNew->next->contents>>pNew->next->weight>>pNew->next->origin>>pNew->next->destination;
		pNew->next->next=NULL;
		pNew=NULL;
	}
}
/*addTrainCarAscending weight adds a trainCar(node) the the train(linked list) in order of ascending weight.
 * Three trainCars are created
 * one that points to the current node(pCurrent), one to the previous node(pPrevious),
 * and one that the data is stored in(pNew).
 * current node pointer is set equal to head pointer
 * If the data member weight stored in pNEW is less than the first node in the train,
 * the new trainCar is placed at the beginning.
 * Otherwise, it walks through the train comparing weights until it finds where the new TrainCar should go.
 * Then, the next pointer of the previous node is set to point at the new trainCar, and the trainCar's
 * next pointer is set to the current node.
 * All three are then set to null because they are no longer needed.
 */
void Train::addTrainCarAscendingWeight(ifstream& in)
{
	TrainCar* pNew = new TrainCar();
	TrainCar* pCurrent= new TrainCar();
	TrainCar* pPrevious= new TrainCar();

	pCurrent=pHead;
	in>>pNew->id>>pNew->contents>>pNew->weight>>pNew->origin>>pNew->destination;

	if(pHead==NULL||atof((pCurrent->weight).c_str())>atof((pNew->weight).c_str()))//if the new node is less than the train's first node place at start
	{
		pNew->next=pHead;
		pHead=pNew;
		pNew=NULL;
	}
	else
	{
		while(pCurrent!=NULL && atof((pCurrent->weight).c_str())<atof((pNew->weight).c_str()))//keep advancing through linked list until
		{
			pPrevious=pCurrent;
			pCurrent=pCurrent->next;
		}
		pPrevious->next=pNew;
		pNew->next=pCurrent;
		pNew=NULL;
	}
	pPrevious=NULL;
	pCurrent=NULL;

}
/**********************************************************************************************
 * trainCarSwap swaps a train car from the beginning of one train to the end of another.      *
 * A New trainCar is created(pNew). All data is from source trainCar is copied over.                *
 * Then, the new trainCar is added to the second train. The memory from the source train car  *
 * is temporarily pointed at by pTemp while the head pointer is moved forward one.                     *
 * Then, the memory is cleared and both pNew and pTemp is set to be null pointers             *
 * because they are no longer needed.                                                         *
 **********************************************************************************************/
void Train::trainCarSwap(Train& tr2)
{
	TrainCar* pNew= new TrainCar();
	pNew->id=pHead->id;
	pNew->contents=pHead->contents;
	pNew->weight=pHead->weight;
	pNew->origin=pHead->origin;
	pNew->destination=pHead->destination;
	pNew->next=tr2.pHead;
	tr2.pHead=pNew;
	pNew=NULL;
	TrainCar* pTemp=pHead;
	if(pHead->next!=NULL)
		pHead=pHead->next;
	else
		pHead=NULL;
	free(pTemp);
	pTemp=NULL;
}
/*************************************************************************************************************
 * printTrain prints the train by walking through it and printing each node's id data member followed by a ->*
 *************************************************************************************************************/
void Train::printTrain()
{
	TrainCar* pWalker;
	pWalker=pHead;
	while(pWalker!=NULL)
	{
		if(pWalker->next!=NULL)
			cout<<pWalker->id<<"->";
		else
			cout<<pWalker->id;//<<" "<<pWalker->contents<<" "<<pWalker->weight<<" "<<pWalker->origin<<" "<<pWalker->destination<<" "<<endl;
		pWalker=pWalker->next;
	}
	pWalker=NULL;
}
/************************************************************************************************************
 * getTrainWeight walks through the train and adds the weight data member(converted from string to a float) *
 * of each trainCar(node) to a float named weight and returns this value                                    *
 ************************************************************************************************************/
float Train::getTrainWeight()
{
	float weight=0;
	TrainCar* pWalker;
		pWalker=pHead;
	while(pWalker!=NULL){
			weight=weight+atof((pWalker->weight).c_str());
			pWalker=pWalker->next;
	}
	return weight;

}

