/*
* Class: CMSC140 CRN 30434
* Instructor: Ahmed Tarek
* Project6
* Description: Create array from numbers in file and use for calculations
* Due Date: 04/24/18
* I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here: Michael Meyers
*/

/* Process – Pseudocode/Algorithm
* 1. Input file name from keyboard
* 2. Attempt to open file
*	2a. If unsuccessful, display error and request name again
* 3. On success, read from file into array
*	3a. Close input file after reading
* 4. Call function to sum numbers in array and return total
* 5. Call function to return lowest number in array
*	5a. Using for statement, step through array comparing numbers
* 6. Call function to return highest number in array
*	6a. Using for statement, step through array comparing numbers
* 7. Call function to calculate average of numbers in array
*	7a. Using the returned total from total() function as parameter,
*		Divided by the total array emlements
* 8. Display returned values from functions in 4-7
*/


#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

int total(int array[], int); //Function to return the total sum of the array
int highest(int array[], int); //Function to determine the highest number in an array
int lowest(int array[], int); //Function to return the lowest number in an array
double averager(int, int); //Function to return the average from the input parameters


int main() {
	string filename;
	const int ARRAY_SIZE = 12;
	int numbers[ARRAY_SIZE];

	//Enter filename and open input stream
	cout << "Please enter the name of the text file ending in .txt: ";
	cin >> filename;
	ifstream inputFile;
	inputFile.open(filename);

	//If file isn't found, try again
	while(!inputFile) {
		cout << endl;
		cout << "No file found. Enter again." << endl;
		cout << "Please enter the name of the text file ending in .txt: ";
		cin >> filename;
	}

	//Read from file and sum numbers
	int i = 0; //Counter for array elements; only reads first 12 to not overrun array
	while(inputFile && i < ARRAY_SIZE) {
		inputFile >> numbers[i];
		i++;
	}

	//Close file after reading
	inputFile.close();

	//Run functions
	int sum = total(numbers, ARRAY_SIZE);
	int lowestNum = lowest(numbers, ARRAY_SIZE);
	int highestNum = highest(numbers, ARRAY_SIZE);
	double average = averager(sum, ARRAY_SIZE);

	cout << "The lowest number in the file is " << lowestNum << endl;
	cout << "The highest number in the file is " << highestNum << endl;
	cout << "The total sum of the numbers is " << sum << endl;
	cout << endl;
	cout << "The average of the numbers is " << showpoint << fixed << setprecision(2) << average << endl;

	system("pause");
	return 0;
}

//Function to return total sum of numbers in array
int total(int array[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += array[i];
	}
	return sum;
}

//Function to return the lowest number found in array
int lowest(int array[], int size) {
	int base = array[0]; //Baseline variable to hold lowest found number
	for (int i = 0; i < size; i++) {
		if (base > array[i]){
			base = array[i];
		}
	}
	return base;
}

//Function to return the highest number found in array
int highest(int array[], int size) {
	int base = array[0]; //Baseline variable to hold highest found number
	for (int i = 0; i < size; i++) {
		if (base < array[i]) {
			base = array[i];
		}
	}
	return base;
}

//Function to return the average of the numbers in array
double averager(int total, int count) {
	double average = ((double)total / (double)count);
	return average;
}