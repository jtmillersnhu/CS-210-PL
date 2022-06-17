#include "utils.h"

/**
 * Returns a string of length n, each character a c.
 * For example, nCharString(5, '*') should return "*****"
 *
 * @param n string length, >=0
 * @return string of n c's
 */
std::string nCharString(size_t n, char c) {
    std::string str = "";
    for (auto i = 0; i < n; i++) {
        str.push_back(c);
    }
    return str;
}

/**
 * Prints menu
 *
 * @param *strings[], nonempty array of choices
 * @param width, width of each line, will be comfortably bigger than the longest string
 *
 */
void printMenu(std::string strings[], unsigned int numStrings, unsigned char width) {
    std::string temp = "";
    std::cout << nCharString(width, '*') << std::endl;
    for (auto i = 0; i < numStrings; i++) {
        std::cout << "* " << (i + 1) << " - " << strings[i];
        for (auto j = 0; j < (width - strings[i].size() - 7); j++) {
            std::cout << " ";
        }
        std::cout << "*" << std::endl;
        if (i < numStrings - 1) {
            std::cout << std::endl;
        }
    }
    std::cout << nCharString(width, '*') << std::endl;
}

/**
 * Gets menu choice 1 through maxChoice, inclusive
 *
 * @param maxChoice, maximum choice index
 * @return the first legal choice input, could be 1 through maxChoice, inclusive
 */
unsigned int getMenuChoice(unsigned int maxChoice) {
    bool validChoice = false;
    unsigned int choice;
    while (!validChoice) {
        try {
            std::cin >> choice;
            if ((choice >= 1) && (choice <= maxChoice)) {
                validChoice = true;
            }
        }
        catch (...) {
            validChoice = false;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
        if (!validChoice) {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "ERROR: Please enter a valid menu choice to continue" << std::endl;
        }
    }
    return choice;
}


/**
* Get an integer
*
* @return a valid integer
*/
int getInteger() {
    bool validInput = false;
    int value;
    while (!validInput) {
        try {
            std::cin >> value;
            validInput = true;
        }
        catch (...) {
            validInput = false;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
        if (!validInput) {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "ERROR: Please enter a valid integer " << std::endl;
        }
    }
    return value;
}


/**
* Get a string
*
* @return a valid string
*/
std::string getString() {
	bool validInput = false;
	std::string value;
	while (!validInput) {
		try {
			std::cin >> value;
			validInput = true;
		}
		catch (...) {
			validInput = false;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
		if (!validInput) {
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << "ERROR: Please enter a valid string " << std::endl;
		}
	}
	return value;
}


/*
Description:
	To call this function, pass the name of the Python function you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
void callStringFunc(std::string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"utils");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc)) {
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else {
		PyErr_Print();
	}
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python function you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(std::string proc, int param) {
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"utils");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc)) {
		pValue = Py_BuildValue("(i)", (unsigned long)param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else {
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}


/*
Description:
	To call this function, pass the name of the Python function you wish to call and the string parameter you want to send
Example:
	double x = CallDoubleFunc("doublevalue","ten");
Return:
	20.0 is returned to the C++
*/
double CallDoubleFunc(std::string proc, std::string param) {
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"utils");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc)) {
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else {
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;

	return PyFloat_AsDouble(presult);
}


/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(std::string proc) {
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"utils");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc)) {
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, NULL);
		PyErr_Print();
	}
	else {
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
}


/**
* Description: 
*	This is a utility function to accomplish the display item frequency task.
*/
void DisplayItemFrequency() {
	std::string item;
	std::cout << "Please enter an item for which to search: ";
	item = getString();
	std::cout.precision(2);
	std::cout << item << "'s frequency: " << std::fixed << CallDoubleFunc("full_get_freq", item) << "%" << std::endl;
}


/**
* Description:
*	This is a utility function to accomplish the histogram task.
*/
void DisplayHistogram() {
	const std::string INPUT_FILE = "frequency.dat";
	std::ifstream ifs;
	std::vector<std::string> item;
	std::vector<int> num;
	size_t entries = 0;
	std::string temp_item;
	int temp_num;
	
	// Create the file from Python
	CallProcedure("full_write_counter");

	// Populate two vectors with items and their number of appearances
	ifs.open(INPUT_FILE);
	while (ifs >> temp_item >> temp_num) {
		entries++;
		item.resize(entries);
		num.resize(entries);
		item.at(entries - 1) = temp_item;
		num.at(entries - 1) = temp_num;
	}
	ifs.close();

	// Get the maximum number of chars from the items vector
	int max_chars = 0;
	for (auto i = 0; i < item.size(); i++) {
		max_chars = item.at(i).size() > max_chars ? item.at(i).size() : max_chars;
	}

	// Create a histogram for the items
	std::ios_base::fmtflags f(std::cout.flags());
	for (auto i = 0; i < item.size(); i++) {
		std::cout.width(max_chars);
		std::cout << item.at(i) << " ";
		for (auto j = 0; j < num.at(i); j++) {
			std::cout << "=";
		}
		std::cout << std::endl;		
	}
	std::cout.flags(f);
}