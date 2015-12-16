//Jay Rosen
//This program opens, reads, and writes to a file the lowercase string of original contents

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>	
using namespace std;

// Grammar class declaration
class Grammar
{
private:
	static const int SIZE = 500;
	char fileName1[SIZE];
	char fileName2[SIZE];
	char ch;

public:

	ifstream inFile;
	fstream outFile;
	void getInFile(string);
	void getOutFile(string);
	void closeFile();
	void lowerCase();
};

// Program that uses Grammar class

/**************************************************************
*						Grammar::getInFile                    *
* Open txt file that user input the name of and validate.      *
**************************************************************/
void Grammar::getInFile(string fileName1)
{
	inFile.open(fileName1);

	if (!inFile)
	{
		cout << "\n\t\tERROR: could not be read file\n\n\t\t";
		exit(0);
	}

}

/**************************************************************
*						Grammar::getOutFile                           *
* Create txt file that user input the name of and pass to lowerCase() *
**************************************************************/
void Grammar::getOutFile(string fileName2)
{
	outFile.open(fileName2, ios::out);

	lowerCase();
}

/**************************************************************
*						Grammar::lowercase                     *
* Transform strings from text file to all lowercase            *
**************************************************************/
void Grammar::lowerCase()
{

	inFile.get(ch);
	while (!inFile.eof())
	{
		outFile.put(tolower(ch));
		inFile.get(ch);
	}

	closeFile();
}

/**************************************************************
*						Grammar::closeFile                    *
* Open txt file that user input the name of and validate.      *
**************************************************************/
void Grammar::closeFile()
{

	inFile.close();
	outFile.close();

	cout << "\n\t\tGrammar editor has edited the file.\n\t\tCheck txt file for results.\n\n\t\t";
}

//Driver programs
int main()
{
	Grammar editor;
	string file1 = "";
	string file2 = "";

	cout << "\n\n\n\t\tWhat txt file do you want to edit?  ";
	cin >> file1;

	editor.getInFile(file1);

	cout << "\t\tWhere should " << file1 << " edits be saved to?  ";
	cin >> file2;

	editor.getOutFile(file2);


	system("pause");

	return 0;
}