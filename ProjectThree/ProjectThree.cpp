#include "utils.h"


int main()
{
	std::string strings[] = { 
		"Display list of items",
		"Display an item's frequency",
		"Display histogram for items",
		"Exit" 
	};
	unsigned int numStrings = 4;
	unsigned int width = 40;
	unsigned int menuChoice = 0;
	unsigned int inputValue;

	do {
		std::cout << std::endl;
		printMenu(strings, numStrings, width);
		menuChoice = getMenuChoice(numStrings);
		switch (menuChoice) {
		case 1:
			CallProcedure("full_print_list");
			break;
		case 2:
			DisplayItemFrequency();
			break;
		case 3:
			DisplayHistogram();
			break;
		}
	} while (menuChoice != numStrings);

    return 0;
}
