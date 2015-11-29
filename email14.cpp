// Lab 14
// Programmer: Dhanush Patel
// Editor(s) used: Eclipse
// Compiler(s) used: Eclipse

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

bool isValidEmailCharacter(char c){
	if((c >='A' && c <= 'Z') || (c >='a' && c <='z') || (c >='0' && c <='9') || c=='.' || c=='-' || c=='+'){
		return true;
	}
	return false;
}

int main(){

    ifstream fin;
	cout << "Programmer: Dhanush Patel" << endl;
	cout << "Description: This program prompts for input and output filenames and prints out all valid non-duplicate emails in the input file." << endl;
	cout << endl;

	string defaultInputFile = "fileContainingEmails.txt";
	string inputFile;
	string defaultOutputFile = "copyPasteMyEmails.txt";
	string outputFile;

	cout << "Enter input filename [default: " << defaultInputFile << "]: ";
	getline(cin,inputFile);
	if(inputFile==""){
		inputFile = defaultInputFile;
	}
	cout << "Enter output filename [default: " << defaultOutputFile << "]: ";
	getline(cin,outputFile);
	if(outputFile==""){
			outputFile = defaultOutputFile;
	}

	const int MAX_EMAILS = 1000;
	int nEmails = 0;
	string name[MAX_EMAILS];

	fin.open(inputFile.c_str());
    while(fin.good()){
    string line;
    getline(fin, line);
	for (int i = 0; i < line.length(); i++){
		if(line[i]=='@'){

			int s = i - 1;
			int e = i + 1;
			bool hasDot = false;

			while(true){
				 if(s < 0){
					 break;
				 }
				 if(!isValidEmailCharacter(line[s])){
					 break;
				 }
				 s--;
			}
			   s++;
			while(true){
				 if(e >= line.length()){
					 break;
				 }
				 if(!isValidEmailCharacter(line[e])){
					 break;
				 }
				 if(line[e]=='.'){
					 hasDot = true;
				 }
				 e++;
			}

			if(nEmails < MAX_EMAILS){
				bool duplicate = false;
				for(int i = 0; i < nEmails; i++){
					if(line.compare(name[i]) == 0){
						duplicate = true;
					}
				}
				if(!duplicate){
					name[nEmails++] = line.substr(s,e-s);
				}
			}
		}
	}
   }
    for(int z = 0; z < nEmails; z++){
    					cout << name[z] << endl;
    				}
    fin.close();


}

