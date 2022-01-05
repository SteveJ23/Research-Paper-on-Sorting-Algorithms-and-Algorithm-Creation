// Inlude header files
#include "sorting.h";
#include "data.h";

// Include libraries
#include <cstdlib>;
#include <ctime>;
#include <fstream>;



int main()
{
	// Declare variables
	int numTrials = 10;
	int numLevels = 9;
	int base = 5;
	int size;
	string option;
	ofstream fout;


	

	// Open output file
	fout.open("results.txt");

	// If the output file opens correctly
	if (fout) { 

		
		// Run the ascending data input on all functions
		option = "best";
		for (int i = 0; i < numLevels; i++) {
			size = (pow(base,i+1)); // Increase size exponentially for each iteration
			fout << "Option: " << option << " | Number of Trials: " << numTrials << " | Size: " << size << "\n\n";
			cout << "Option: " << option << " | Number of Trials: " << numTrials << " | Size: " << size << "\n\n";
			trials(fout, option, size, numTrials);		
			fout << "\n\n\n\n";
			cout << "\n\n\n\n";
		}

		fout << "--------------------------------------------------------------------------------------------------------------------------------------------\n\n\n\n";
		
		// Run the random data input on all functions
		option = "random";
		for (int i = 0; i < numLevels; i++) {
			srand(time(NULL));
			size = (pow(base, i + 1)); // Increase size exponentially for each iteration
			fout << "Option: " << option << " | Number of Trials: " << numTrials << " | Size: " << size << "\n\n";
			cout << "Option: " << option << " | Number of Trials: " << numTrials << " | Size: " << size << "\n\n";
			trials(fout, option, size, numTrials);
			fout << "\n\n\n\n";
			cout << "\n\n\n\n";
		}

		fout << "--------------------------------------------------------------------------------------------------------------------------------------------\n\n\n\n";
		
		// Run the descending data input on all algorithms
		option = "worst";
		for (int i = 0; i < numLevels; i++) {
			size = (pow(base, i + 1)); // Increase size exponentially for each iteration
			fout << "Option: " << option << " | Number of Trials: " << numTrials << " | Size: " << size << "\n\n";
			cout << "Option: " << option << " | Number of Trials: " << numTrials << " | Size: " << size << "\n\n";
			trials(fout, option, size, numTrials);
			fout << "\n\n\n\n";
			cout << "\n\n\n\n";
		}
		
	}
	else {
		cout << "Output file failed to open properly...";
	}

	// Close output file
	fout.close();

	cout << "Successful exit";

	
	// Exit Program
	exit(EXIT_SUCCESS);


}