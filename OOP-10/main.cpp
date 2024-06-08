#include <iostream>
#include "File_work.h"
#include "Pair.h"
using namespace std;

int main() {
	Pair pair, pair1, pair2;
	int k, choice, num;
	double tmp;
	char file_name[30];
	do {
		cout << endl << "1. Make file" << endl << "2. Print file" << endl << "3. Delete record from file" << endl << "4. Add record to file" << endl << "5. Change record in file" << endl << "6. Complete task" << endl << "0. Exit" << endl;
		cin >> choice;
		switch (choice) {
		case 1: cout << "Enter file name: ";
			cin >> file_name;
			k = make_file(file_name);
			if (k < 0) cout << "couldn't make file!";
			break;
		case 2: cout << "Enter file name: ";
			cin >> file_name;
			k = print_file(file_name);
			if (k == 0) cout << "Empty file!" << endl;
			if (k < 0) cout << "Couldn't read file!" << endl;
			break;

		case 3: cout << "Enter file name: ";
			cin >> file_name;
			cout << "Enter number: ";
			cin >> num;
			k = del_by_position(file_name, num);
			if (k < 0) cout << "Couldn't read file!" << endl;
			break;
		case 4: cout << "Enter file name: ";
			cin >> file_name;
			cout << "Enter number: ";
			cin >> num;
			cout << "New pair: ";
			cin >> pair1;
			k = add_file(file_name, num, pair1);
			if (k < 0) cout << endl << "Couldn't read file!" << endl;
			if (k == 0) cout << endl << "No such record!" << endl;
			break;

		case 5: cout << "Enter file name: ";
			cin >> file_name;
			cout << "Enter number: ";
			cin >> num;
			cout << "New pair: ";
			cin >> pair2;
			k = change_file(file_name, num, pair2);
			if(k<0) cout << endl << "Couldn't read file!" << endl;	
			if (k == 0) cout << endl << "No such record!" << endl;
			break;
		case 6: cout << "Enter file name: ";
			cin >> file_name;
			cout << "Enter number to erase lesser numbers: ";
			cin >> num;
			k = delete_lt(file_name, num);
			if (k < 0) cout << endl << "Couldn't read file!" << endl;
			if (k == 0) cout << endl << "No such record!" << endl;
			cout << "Enter L number to inclease existing pairs: " << endl << "1 - int, 2 - float: ";
			cin >> choice;
			cout << "Enter L: ";
			switch (choice) {
			case 1:
				cin >> num;
				k = increase_l(file_name, num);
				break;
			case 2:
				cin >> tmp;
				k = increase_l(file_name, tmp);
				break;
			}
			if (k < 0) cout << endl << "Couldn't read file!" << endl;
			if (k == 0) cout << endl << "No such record!" << endl;
			cout << "Enter >k to enter new pairs after >n'th element: ";
			cin >> k >> num;
			k = add_afterK(file_name, num, k);
			if (k < 0) cout << endl << "Couldn't read file!" << endl;
			if (k == 0) cout << endl << "No such record!" << endl;
		}
	} while (choice != 0);
	return 0;
}
