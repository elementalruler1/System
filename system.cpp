#include <iostream>
#include <string>
//#include <new>
#include <list>

#include <stdio.h>
#include <stdlib.h>

/* disable warning for getenv()*/
#pragma warning(disable : 4996)

std::string get_substr(std::string::iterator beg, std::string::iterator end) {
	std::string retVal;
	return retVal.append(beg, end);
}

int main() {

	/* request DIR from system */
	int i;
	printf("Checking if processor is available...");

	if (system(NULL)) puts("Ok");
	else exit(EXIT_FAILURE);

	printf("Executing command DIR...\n");
	i = system("dir");
	printf("The value returned was %d.\n", i);


	/* create list of paths in PATH */
	char* pPath;
	pPath = getenv("PATH");
	if (pPath != NULL) puts("PATH requested successfully...\n");
	else exit(EXIT_FAILURE);

	std::string cur_path = pPath;
	std::list<std::string> paths;
	std::string::iterator start = cur_path.begin();
	std::string::iterator fin;
	for (std::string::iterator it = cur_path.begin(); it != cur_path.end(); ++it) {

		if (*it == ';') {
			fin = it;
			paths.push_back(get_substr(start, fin));
			start = it + 1;
		}
	}

	std::cout << "PATH ENVIRONMENT VARIABLE:" << std::endl;
	int index = 0;
	for (std::list<std::string>::iterator list_it = paths.begin(); list_it != paths.end(); ++list_it) {
		std::cout << index++ << "\t" << *list_it << std::endl;

	}

	return 0;
}