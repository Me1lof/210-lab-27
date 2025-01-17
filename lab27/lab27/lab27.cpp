//Melissa OChoa
//COMSC 210
// Village Map

#include <iostream>
#include <map>
#include <tuple>
#include <string>
using namespace std;

map<string, tuple<int, string, string>> villagers;

void displayVillagers() {
	cout << "\nVillagers and their details:" << endl;
	for (auto& pair : villagers) {
		cout << pair.first << " - Friendship Level: " << get<0>(pair.second)
			<< ", Species: " << get<1>(pair.second)
			<< ", Catchphrase: " << get<2>(pair.second) << endl;
	}
}

void addVilager() {
	string name, species, catchphrase;
	int friendshipLevel;

	cout << "\nEnter villager name: ";
	cin >> name;
	cout << "Enter friendship level: ";
	cin >> friendshipLevel;
	cout << "Enter species: ";
	cin >> species;
	cout << "Enter catchphrase: ";
	cin.ignore();
	getline(cin, catchphrase);

	villagers[name] = make_tuple(friendshipLevel, species, catchphrase);
	cout << name << " added.\n";
}

void deleteVillager() {
	string name;
	cout << "\n Enter the name of the villager being deleted: ";
	cin >> name;

		if (villagers.erase(name)) {
			cout << name << " deleted.\n";
		}
}

void searchVillager() {
	string name;
	cout << "\nEnter villager name to search: ";
	cin >> name;

	auto it = villagers.find(name);
	if (it != villagers.end()) {
		cout << name << " found - Friendship Level: " << get<0>(it->second)
			<< ", Species: " << get<1>(it->second)
			<< ", Catchphrase: " << get<2>(it->second) << endl;
	}
}

void modifyFriendshipLevel(bool increase) {
	string name;
	cout << "\nEnter villager name to " << (increase ? "increase" : "decrease") << "friendship level: ";
	cin >> name;

	auto it = villagers.find(name);
	if (it != villagers.end()) {
		int& level = get<0>(it->second);
		if (increase) {
			if (level < 10) ++level;
		}
		else {
			if (level > 0) --level;
		}
		cout << "friendship level updated for" << name << ".\n";
	}
}

int main() {
	int choice;

	do {
		cout << "\nMenu:\n"
			<< "1. Add Villager\n"
			<< "2. Display All Villagers\n"
			<< "3. Delete Villager\n"
			<< "4. Search for Villager\n"
			<< "5. Increase Friendship Level\n"
			<< "6. Decrease Friendship Level\n"
			<< "7. Exit\n"
			<< "Enter your choice: ";
		cin >> choice;


		switch (choice) {
		case 1: addVilager(); break;
		case 2: displayVillagers(); break;
		case 3: deleteVillager(); break;
		case 4: searchVillager(); break;
		case 5: modifyFriendshipLevel(true); break;
		case 6: modifyFriendshipLevel(false); break;
		case 7: cout << "Existing program.\n"; break;
		default: cout << "Invaild choice! Please try again.\n";
		}
	} while (choice != 7);

	return 0;
}
