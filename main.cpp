
/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/19/19
** Description: Creates a queue list and presents the user with
** several options for interaction
*********************************************************************/
#include <string>
#include <iostream>
#include <fstream>
#include "menuShell.hpp"
#include "Queue.hpp"
#include "QueueNode.hpp"

void printFwd(Queue &list);
void printQueue(Queue &list);
void loadFromFile(Queue &list, std::string fileName);

int main() {
	std::cout << "Welcome to Phillip Wellheuser's Lab 7, Queued list node program." << std::endl;
	std::cout << "**Choose option 5 to load the included .txt file into the list automatically**" << std::endl;
	const int numOptions = 8;
	// define an array of strings to use in the menus
	std::string chooseOptions[numOptions];
	chooseOptions[0] = "\nChoose from the following options";
	chooseOptions[1] = "1. Add a value to the back of queue";
	chooseOptions[2] = "2. Display the front value";
	chooseOptions[3] = "3. Remove the front node";
	chooseOptions[4] = "4. Display the queue\'s contents";
	chooseOptions[5] = "5. Load List from file";
	chooseOptions[6] = "6. Load List from custom .txt file";
	chooseOptions[7] = "7. Exit";

	Queue list;

	int choice = 0;

	//get an integer choice from the user and select the appropriate action
	while (choice != numOptions-1) {
		choice = choiceMenuMulti(chooseOptions, numOptions);
		switch (choice) {
			case 1:
				list.addBack(chooseIntInRange("Enter an integer from 1 to 100000", 1, 100000));
				break;
			case 2:
				std::cout << "The front of the list is: " << list.getFront()->getVal();
				std::cout << "\n";
				break;
			case 3:
				list.removeFront();
				break;
			case 4:
				std::cout << "Your queued list is: ";
				printQueue(list);
				std::cout << "\n";
				break;
			case 5:
				loadFromFile(list, "numberFile.txt");
				printFwd(list);
				break;
			case 6:
				loadFromFile(list, enterTxtFileWithinRange("Please enter your text file name: ", 1, 31));
				printFwd(list);
				break;
			case 7: 
				std::cout << "Exiting program" << std::endl;
				break;
			default:
				std::cout << "Error in choosing options" << std::endl;
				break;
		}
	}
	return 0;
}

/*********************************************************************
** Description: prints the queue front to back
*********************************************************************/
void printFwd(Queue &list) {
	std::cout << "Your queued list is: ";
	printQueue(list);
	std::cout << "\n";
}

/*********************************************************************
** Description: loads a default file into the queue 
*********************************************************************/
void loadFromFile(Queue &list, std::string fileName) {
	int number;
	std::ifstream numberFile(fileName);
	if (!numberFile) {
		std::cout << "Error opening the file of numbers.";
	}

	std::cout << "\nThe contents of the file are: ";
	while (numberFile >> number) {
		std::cout << number << "   ";
		list.addBack(number);
	}
	std::cout << "\n";
	numberFile.close();
}

/*********************************************************************
** Description: displays the current queue from front to back
*********************************************************************/
void printQueue(Queue &list) {
	if (list.getFront() == nullptr) {
		std::cout << "empty"<< std::endl;;
	}
	else {
		QueueNode *nodePtr = list.getFront();
		std::cout << nodePtr->getVal() << "   ";
		nodePtr = nodePtr->getNext();
		while (nodePtr != list.getFront()) {
			std::cout << nodePtr->getVal() << "   ";
			nodePtr = nodePtr->getNext();
		}
	}
}