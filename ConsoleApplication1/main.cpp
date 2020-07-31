/*Kenya Foster
File: main.cpp
CS 101
Reads from file and prints number of times a word appears, cleans words of punc. etc.
*/

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

int numTimes(string token, string *wordList, int size);
string cleanWord(string token);
int size = 0; //size of wordList
int unum = 0; //number of unique words


int numTimes(string token, string *wordList, int size) //searches in wordlist for number of times a word is encountered
{
	int num = 0; //number of times a word appears
	for (int i = 0; i < size; i++)
	{
		if ((wordList[i]).compare(token) == 0)
			num++;
	}
	return num;
}

string cleanWord(string token) //returns a cleaned word
{
	for (size_t i = 0; i < token.length(); i++)
	{
		if (ispunct(token[i]))
		{
			token.erase(i--, 1); //erases 1 item at that slot
		}
	}

	if (token.compare("") != 0)
	{
		string word = "";

		for (size_t i = 0; i < token.length(); i++)
		{
			word += tolower(token[i]);
		}

		return word;
	}
	else
		return "";
}


int main(int argc, char *argv[])
{
	ifstream infile(argv[1]);
	string token;
	string *wordList = new string[30000];
	int size = 0;

	while (infile >> token)
	{
		string word = cleanWord(token);

		if (word.compare("") != 0)
		{
			wordList[size] = word;
			size++;

			int numm = numTimes(word, wordList, size);
			if (numm > 1)
				unum++;
		}
	}

	int total = size - unum;

	cout << "The number of words found in the file was " << size << endl;
	cout << "The number of unique words found in the file was " << total << endl;

	string user = "";

	cout << "Please enter a word: ";

	while (cin >> user)
	{
		int n = numTimes(user, wordList, size);
		cout << "The word " << user << " appears " << n << " times in the document" << endl;
		cout << "Please enter a word: ";
	}

	return 0;
}

