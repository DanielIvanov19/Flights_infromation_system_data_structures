#include <iostream>
#include<string>
#include<string.h>
#include<cstring>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include <fstream>
#include<time.h>
#include<ctime>
#include<iomanip>
#pragma warning(disable : 4996)
using namespace std;

struct flight
{
	int number;
	string destination;
	string pilot_name;
	double price;
	bool flight_class;
	string date;
	string passenger_name;
	flight* next; // Pointer to next flight in the linked list
}; //*head = NULL

void addFlight(flight*& head)
{
	int number;
	string destination;
	string pilot_name;
	double price;
	bool flight_class;
	string date;
	string passenger_name;

	while (true)
	{
		cout << "Enter flight number: ";
		cin >> number;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (number < 0)
		{
			cout << "Incorrect flight number!" << endl;
			continue;
		}
		else
		{
			break;
		}

	}
	cout << "Enter destination: ";
	cin >> destination;
	cout << "Enter pilot name: ";
	cin >> pilot_name;
	cout << "Enter price(lv.): ";
	cin >> price;
	while (true)
	{
		cout << "Enter flight class(1-first/0-second): ";
		cin >> flight_class;
		if (!cin)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Incorrect input!" << endl;
			continue;
		}
		else
		{
			break;
		}
	}
	cout << "Enter date (dd.mm.yy): ";
	cin >> date;
	cout << "Enter passenger name: ";
	cin >> passenger_name;

	flight* new_flight = new flight;
	new_flight->number = number;
	new_flight->destination = destination;
	new_flight->pilot_name = pilot_name;
	new_flight->price = price;
	new_flight->flight_class = flight_class;
	new_flight->date = date;
	new_flight->passenger_name = passenger_name;
	new_flight->next = NULL;

	if (head == NULL) {
		head = new_flight;
	}
	else {
		flight* curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = new_flight;
	}
	cout << endl;
}

// new function for adding multiple flights

void addFlights(flight*& head)
{
	int num_flights;
	while (true)
	{
		cout << "Enter the number of flights you want to add: ";
		cin >> num_flights;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (num_flights < 0)
		{
			cout << "Incorrect flight number!" << endl;
			continue;
		}
		else
		{
			break;
		}

	}

	for (int i = 0; i < num_flights; i++) {
		int number;
		string destination;
		string pilot_name;
		double price;
		bool flight_class;
		string date;
		string passenger_name;

		while (true)
		{
			cout << "Enter flight number: ";
			cin >> number;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (number < 0)
			{
				cout << "Incorrect flight number!" << endl;
				continue;
			}
			else
			{
				break;
			}

		}
		cout << "Enter destination: ";
		cin >> destination;
		cout << "Enter pilot name: ";
		cin >> pilot_name;
		cout << "Enter price(lv.): ";
		cin >> price;
		while (true)
		{
			cout << "Enter flight class(1-first/0-second): ";
			cin >> flight_class;
			if (!cin)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Incorrect input!" << endl;
				continue;
			}
			else
			{
				break;
			}
		}
		cout << "Enter date (dd.mm.yy): ";
		cin >> date;
		cout << "Enter passenger name: ";
		cin >> passenger_name;

		flight* new_flight = new flight;
		new_flight->number = number;
		new_flight->destination = destination;
		new_flight->pilot_name = pilot_name;
		new_flight->price = price;
		new_flight->flight_class = flight_class;
		new_flight->date = date;
		new_flight->passenger_name = passenger_name;
		new_flight->next = NULL;

		if (head == NULL) {
			head = new_flight;
		}
		else {
			flight* curr = head;
			while (curr->next != NULL) {
				curr = curr->next;
			}
			curr->next = new_flight;
		}
		cout << endl;
	}
}

void delete_flight(flight*& head)
{
	int flight_number;
	cout << "Enter the flight number of the flight you want to delete: ";
	cin >> flight_number;

	if (head == NULL) {
		// If the list is empty do nothing
		return;
	}

	if (head->number == flight_number) {
		// In case the flight to delete is at the head of the list
		flight* temp = head;
		head = head->next;
		delete temp;
		return;
	}

	flight* curr = head;
	flight* prev = NULL;
	while (curr != NULL && curr->number != flight_number) {
		prev = curr;
		curr = curr->next;
	}

	if (curr == NULL) {
		// Flight not found in list
		return;
	}

	// Flight to delete is not at the head of the list
	prev->next = curr->next;
	delete curr;
}
void flightsOutput(flight* head) {
	while (head != NULL) {
		cout << "Flight number: " << head->number << endl;
		cout << "Destination: " << head->destination << endl;
		cout << "Pilot name: " << head->pilot_name << endl;
		cout << "Price: " << head->price <<"lv."<< endl;
		if (head->flight_class == true)
		{
			cout << "Flight Class: First" << endl;
		}
		else
		{
			cout << "Flight Class: Second" << endl;
		}
		cout << "Date: " << head->date << endl;
		cout << "Passenger name: " << head->passenger_name << endl;
		cout << endl;
		head = head->next;
	}
}

void cheapestFlightsBinary(flight* head) {
	if (head == NULL) {
		// If the list is empty do nothing
		return;
	}

	// Find the minimum price in the list
	double min_price = head->price;
	flight* curr = head;
	while (curr != NULL) {
		if (curr->price < min_price) {
			min_price = curr->price;
		}
		curr = curr->next;
	}

	// Output all flights with the minimum price
	curr = head;
	while (curr != NULL) {
		if (curr->price == min_price) {
			std::cout << "Flight Number: " << curr->number << endl;
			std::cout << "Destination: " << curr->destination << endl;
			std::cout << "Pilot Name: " << curr->pilot_name << endl;
			std::cout << "Price: " << curr->price <<"lv." << endl;
			if (curr->flight_class) {
				std::cout << "Flight Class: First" << endl;
			}
			else {
				std::cout << "Flight Class: Second" << endl;
			}
			std::cout << "Date: " << curr->date << endl;
			std::cout << "Passenger Name: " << curr->passenger_name << endl;
			std::cout << endl;
		}
		curr = curr->next;
	}
}

void outputByPilotName(flight* head)
{
	flight* curr = head;
	if (head == NULL)
	{
		cout << "No flights in the database!" << endl;
		return;
	}
	string pilot_name;
	int flightsFound = 0;
	cout << "Enter the pilot you are seeking for" << endl;
	cin >> pilot_name;
	cout << "Flight(s) of " << pilot_name << ":" << endl;
	cout << endl;
	while (curr != NULL)
	{
		if (strcmp(curr->pilot_name.c_str(), pilot_name.c_str()) == 0)
		{
			cout << "Flight number: " << curr->number << endl;
			cout << "Destination: " << curr->destination << endl;
			cout << "Pilot name: " << curr->pilot_name << endl;
			cout.setf(ios::fixed);
			cout << "Price: " << setprecision(2) << curr->price << "lv." << endl;
			if (curr->flight_class == true)
			{
				cout << "Flight Class: First" << endl;
			}
			else
			{
				cout << "Flight Class: Second" << endl;
			}
			cout << "Date: " << curr->date << endl;
			cout << "Passenger name: " << curr->passenger_name << endl;
			cout << endl;
			flightsFound++;
		}
		curr = curr->next;
	}
	if (flightsFound == 0)
	{
		cout << "No such pilot in the database" << endl;
	}
}

void sortAlphabeticallyByDestinationSeparateArray(flight* head)
{
	if (head == NULL)
	{
		cout << "There are no flights in the database!" << endl;
		return;
	}
	else
	{
		flight odd_even_array[10];
		int stoppage_variable = 0;
		//Assigning the first 10 elements of the linked list to separate array
		while (head != NULL)
		{
			flight temp;
			temp.number = head->number;
			temp.destination = head->destination;
			temp.pilot_name = head->pilot_name;
			temp.price = head->price;
			temp.flight_class = head->flight_class;
			temp.date = head->date;
			temp.passenger_name = head->passenger_name;
			odd_even_array[stoppage_variable] = temp;
			stoppage_variable += 1;
			if (stoppage_variable > 9)
			{
				break;
			}
			head = head->next;
		}

		// Odd-even sort of the separate array
		bool isSorted = false;

		while (!isSorted)
		{
			isSorted = true;

			for (int i = 1; i < stoppage_variable; i += 2) {
				if (odd_even_array[i].destination < odd_even_array[i + 1].destination) {
					std::swap(odd_even_array[i], odd_even_array[i + 1]);
					isSorted = false;
				}
			}

			for (int i = 0; i < stoppage_variable; i += 2) {
				if (odd_even_array[i].destination < odd_even_array[i + 1].destination) {
					std::swap(odd_even_array[i], odd_even_array[i + 1]);
					isSorted = false;
				}
			}
		}

		//Output of the sorted array
		for (int i = 0; i < stoppage_variable; i++)
		{
			if (odd_even_array[i].destination == "")
			{
				break;
			}
			cout << "Flight number: " << odd_even_array[i].number << endl;
			cout << "Destination: " << odd_even_array[i].destination << endl;
			cout << "Pilot name: " << odd_even_array[i].pilot_name << endl;
			cout.setf(ios::fixed);
			cout << "Price: " << setprecision(2) << odd_even_array[i].price << "lv." << endl;
			if (odd_even_array[i].flight_class == true)
			{
				cout << "Flight Class: First" << endl;
			}
			else
			{
				cout << "Flight Class: Second" << endl;
			}
			cout << "Date: " << odd_even_array[i].date << endl;
			cout << "Passenger name: " << odd_even_array[i].passenger_name << endl;
			cout << endl;
		}
	}
}


void sortAlphabeticallyByDestinationBubbleSort(flight*& head) {
	if (head == nullptr || head->next == nullptr) {
		return; // nothing to sort
	}
	bool swapped = true;
	while (swapped) {
		swapped = false;
		flight* curr = head;
		flight* prev = nullptr;
		while (curr->next != nullptr) {
			if (curr->destination < curr->next->destination) {
				// swap the current node with the next node
				flight* temp = curr->next;
				curr->next = temp->next;
				temp->next = curr;
				if (curr == head) {
					head = temp;
				}
				else {
					prev->next = temp;
				}
				prev = temp;
				swapped = true;
			}
			else {
				prev = curr;
				curr = curr->next;
			}
		}
	}
}

void searchByDateAndDestination(flight* head) {
	if (head == nullptr) {
		cout << "There are no flights in the database!" << endl;
		return;
	}
	string searchDate, searchDestination;
	cout << "Enter a destination to search for: ";
	cin >> searchDestination;
	cout << "Enter a date to search for: ";
	cin >> searchDate;

	cout << "Flights on " << searchDate << " to " << searchDestination << ":" << endl;
	bool found = false;

	flight* current = head;
	while (current != nullptr) {
		if (current->date == searchDate && current->destination == searchDestination) {
			cout << "Flight number: " << current->number << endl;
			cout << "Destination: " << current->destination << endl;
			cout << "Pilot name: " << current->pilot_name << endl;
			cout << "Price: " << current->price << "lv." << endl;
			cout << "Flight Class: " << (current->flight_class ? "First" : "Second") << endl;
			cout << "Date: " << current->date << endl;
			cout << "Passenger name: " << current->passenger_name << endl;
			cout << endl;
			found = true;
		}

		current = current->next;
	}

	if (!found) {
		cout << "No flights found on " << searchDate << " to " << searchDestination << endl;
	}
}


void sortAscendingByPriceAndDestinationSeparateArraySelectionSort(flight* head) {
	if (head == nullptr) {
		cout << "There are no flights in the database!" << endl;
		return;
	}
	else {
		flight selection_sort_array[10];
		int stoppage_variable = 0;
		// Assigning the first 10 elements of the linked list to separate array
		while (head != nullptr) {
			flight temp;
			temp.number = head->number;
			temp.destination = head->destination;
			temp.pilot_name = head->pilot_name;
			temp.price = head->price;
			temp.flight_class = head->flight_class;
			temp.date = head->date;
			temp.passenger_name = head->passenger_name;
			selection_sort_array[stoppage_variable] = temp;
			stoppage_variable += 1;
			if (stoppage_variable > 9) {
				break;
			}
			head = head->next;
		}

		// Selection sort of the separate array
		for (int i = 0; i < stoppage_variable - 1; ++i) {
			int minIndex = i;

			for (int j = i + 1; j < stoppage_variable; ++j) {
				if (selection_sort_array[j].price < selection_sort_array[minIndex].price ||
					(selection_sort_array[j].price == selection_sort_array[minIndex].price && selection_sort_array[j].flight_class < selection_sort_array[minIndex].flight_class)) {
					minIndex = j;
				}
			}

			if (minIndex != i) {
				flight temp = selection_sort_array[i];
				selection_sort_array[i] = selection_sort_array[minIndex];
				selection_sort_array[minIndex] = temp;
			}
		}

		// Output of the sorted array in ascending order
		for (int i = 0; i < stoppage_variable; i++) {
			if (selection_sort_array[i].destination == "") {
				break;
			}
			cout << "Flight number: " << selection_sort_array[i].number << endl;
			cout << "Destination: " << selection_sort_array[i].destination << endl;
			cout << "Pilot name: " << selection_sort_array[i].pilot_name << endl;
			cout.setf(ios::fixed);
			cout << "Price: " << setprecision(2) << selection_sort_array[i].price << "lv." << endl;
			if (selection_sort_array[i].flight_class == true) {
				cout << "Flight Class: First" << endl;
			}
			else {
				cout << "Flight Class: Second" << endl;
			}
			cout << "Date: " << selection_sort_array[i].date << endl;
			cout << "Passenger name: " << selection_sort_array[i].passenger_name << endl;
			cout << endl;
		}
	}
}

void sortDescendingByPriceAndDestinationSeparateArrayInsertionSort(flight* head) {
	if (head == nullptr) {
		cout << "There are no flights in the database!" << endl;
		return;
	}
	else {
		flight insertion_sort_array[10];
		int stoppage_variable = 0;

		// Assigning the first 10 elements of the linked list to the separate array
		while (head != nullptr) {
			flight temp;
			temp.number = head->number;
			temp.destination = head->destination;
			temp.pilot_name = head->pilot_name;
			temp.price = head->price;
			temp.flight_class = head->flight_class;
			temp.date = head->date;
			temp.passenger_name = head->passenger_name;
			insertion_sort_array[stoppage_variable] = temp;
			stoppage_variable += 1;
			if (stoppage_variable > 9) {
				break;
			}
			head = head->next;
		}

		// Insertion sort of the separate array in descending order
		for (int i = 1; i < stoppage_variable; ++i) {
			flight key = insertion_sort_array[i];
			int j = i - 1;

			while (j >= 0 && (insertion_sort_array[j].price < key.price ||
				(insertion_sort_array[j].price == key.price && insertion_sort_array[j].flight_class < key.flight_class))) {
				insertion_sort_array[j + 1] = insertion_sort_array[j];
				j = j - 1;
			}

			insertion_sort_array[j + 1] = key;
		}

		// Output the sorted array in descending order
		for (int i = 0; i < stoppage_variable; i++) {
			if (insertion_sort_array[i].destination == "") {
				break;
			}
			cout << "Flight number: " << insertion_sort_array[i].number << endl;
			cout << "Destination: " << insertion_sort_array[i].destination << endl;
			cout << "Pilot name: " << insertion_sort_array[i].pilot_name << endl;
			cout.setf(ios::fixed);
			cout << "Price: " << setprecision(2) << insertion_sort_array[i].price << "lv." << endl;
			if (insertion_sort_array[i].flight_class == true) {
				cout << "Flight Class: First" << endl;
			}
			else {
				cout << "Flight Class: Second" << endl;
			}
			cout << "Date: " << insertion_sort_array[i].date << endl;
			cout << "Passenger name: " << insertion_sort_array[i].passenger_name << endl;
			cout << endl;
		}
	}
}


int main()
{
	/*const int length = 50;
	flight arr_flights[length];
	int current = 0; // counter of the initialized elements*/
	int command = 0;

	flight* head = NULL;

	while (true)
	{
		cout << "1. Add a flight" << endl;
		cout << "2. Add n flights" << endl;
		cout << "3. Delete flight" << endl;
		cout << "4. Flights output" << endl;
		cout << "5. Cheapest flights" << endl;
		cout << "6. Flights of certain pilot" << endl;
		cout << "7. Arrange the flights in alphabetical order(Odd-even/Bubble Sort)" << endl;
		cout << "8. More options" << endl;
		cout << "9. Exit" << endl;

		while (true)
		{
			cout << "Enter a command between 1 and 9: ";
			cin >> command;
			if (!cin)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "You didn't input a number" << endl;
				continue;
			}

			if (command <= 0 || command > 13)
			{
				cout << "Incorrect command input!" << endl;
				continue;
			}
			else
			{
				break;
			}

		}
		switch (command)
		{
		case 1:
			cout << endl;
			addFlight(head);
			break;
		case 2:
			cout << endl;
			addFlights(head);
			break;
		case 3:
			cout << endl;
			delete_flight(head);
		case 4:
			cout << endl;
			flightsOutput(head);
			break;
		case 5:
			cout << endl;
			cheapestFlightsBinary(head);
			break;
		case 6:
			cout << endl;
			outputByPilotName(head);
			break;
		case 7:
			cout << endl;
			sortAlphabeticallyByDestinationSeparateArray(head);
			sortAlphabeticallyByDestinationBubbleSort(head);
			break;

		case 8:
		{
			cout << endl;
			int smallCommand = 0;

			while (true)
			{
				cout << "1. Ascending order by price and flight class(Selection Sort)" << endl;
				cout << "2. Descending order by price and flight class(Insertion Sort)" << endl;
				cout << "3. Search by date and destination" << endl;
				cout << "4. Back to main menu" << endl;
				cin >> smallCommand;
				if (!cin)
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "You didn't input a number" << endl;
					continue;
				}
				switch (smallCommand)
				{
				case 1:
					sortAscendingByPriceAndDestinationSeparateArraySelectionSort(head);
					break;
				case 2:
					sortDescendingByPriceAndDestinationSeparateArrayInsertionSort(head);
					break;
				case 3:
					searchByDateAndDestination(head);
				case 4:
					break;
				default:
					break;
				}
				if (smallCommand == 4)
				{
					break;
				}

			}
			break;
		}
		case 9:
			cout << "You exited the program" << endl;
			break;
		default:
			break;
		}
		if (command == 9)
		{
			break;
		}
	}
	return 0;
}
