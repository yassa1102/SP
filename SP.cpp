#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct car {
	int id;
	string name;
	string color;
	double price;
	int year;
};
void add ()
{
	char choice;
	while (true)
	{
	car c;
		cout << "Enter car id: ";
		cin >> c.id;
		cout << "Enter car name: ";
		cin >> c.name;
		cout << "Enter car color: ";
		cin >> c.color;
		cout << "Enter car price: ";
		cin >> c.price;
		cout << "Enter car year: ";
		cin >> c.year;
		ofstream file("cars.txt");
		if (file.is_open()) {
			file << c.id << endl << c.name << endl << c.color << endl << c.price << endl << c.year << endl;
			file.close();
			cout << "Car added successfully!" << endl;
		}
		else {
			cout << "Unable to open file!" << endl;
		}
		cout << "Do you want to add another car? (y/n): ";
		cin >> choice;
		if (choice == 'n' || choice == 'N')
			break;
	}
	
}
void display()
{
	ifstream file("cars.txt");
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();
	}
	else {
		cout << "Unable to open file!" << endl;
	}
}
void remove()
{
	int id;
	cout << "Enter car id to remove: ";
	cin >> id;
	string target = to_string(id);
	ifstream infile("cars.txt");
	ofstream outfile("temp.txt");
	if (infile.is_open() && outfile.is_open()) {
		string line;
		while (getline(infile, line)) {
			if (line.find(target) == string::npos) {
				outfile << line << endl;
			}
		}
		infile.close();
		outfile.close();
		remove("cars.txt");
		rename("temp.txt", "cars.txt");
		cout << "Car removed successfully!" << endl;
	}
	else {
		cout << "Unable to open file!" << endl;
	}
		
}
int main() {
	int choice;
	do {
		cout << "1. Add car" << endl;
		cout << "2. Display cars" << endl;
		cout << "3. Remove car" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			add();
			break;
		case 2:
			cout << " the saved cars are : " << endl;
			display();
			break;
		case 3:
			remove();
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Invalid choice!" << endl;
		}
	} while (choice != 4);
	return 0;
}