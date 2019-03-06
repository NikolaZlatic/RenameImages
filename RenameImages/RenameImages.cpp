// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include <Windows.h>

using namespace std;

int main()
{

	vector<string> temp;
	ifstream infile;
	infile.open("ListOfFiles.txt");

	if (infile.fail()) {
		cout << "Could not open ListOfFiles.txt file." << "\n";
		return 1;
	}

	string data;
	while (infile >> data) {
		temp.push_back(data);
	}

	for (int i = 0; i < temp.size(); i++) {
		//cout << temp[i].substr(0, temp[i].size() - 4) << endl;
		temp[i] = temp[i].substr(0, temp[i].size() - 4);
	}


	struct file {
		string oldName;
		string newName;
		string height;
		string width;
	};

	vector<file> list;

	ifstream infile2;
	infile2.open("images.txt");

	if (infile2.fail())
	{
		cout << "Could not open images.txt file." << "\n";
		return 1;
	}

	while (infile2 >> data) {
		file tempf;
		tempf.oldName = data;
		infile2 >> data;
		tempf.newName = data;
		infile2 >> data;
		tempf.height = data;
		infile2 >> data;
		tempf.width = data;
		list.push_back(tempf);
	}

	vector<string> AssetsIDs;
	//MORAM DA NADJEM NACIN DA IZ OVOG FOLDERA IZVUCEM UNIQUE IDs I DA ONDA SAMO SA NJIMA RADIM
	for (int i = 0; i < list.size(); i++) {
		if (AssetsIDs.size() == 0 ) AssetsIDs.push_back((list[i].oldName)); else 
		if (AssetsIDs[AssetsIDs.size() - 1 ] != list[i].oldName)AssetsIDs.push_back((list[i].oldName));
	}

	for (int i = 0; i < AssetsIDs.size(); i++) {
		cout << AssetsIDs[i] << endl;
	}
	
	/*
	cout << "ListOfImages:" << endl;
	for (int i = 0; i < list.size(); i++) {
		cout << list[i].oldName << " " << list[i].newName << " " << list[i].height << " " << list[i].width << endl;
	}
	cout << "ListOfFiles:" << endl;
	for (int i = 0; i < temp.size(); i++) {
		cout << temp[i] << endl;
	}
	*/
	/*
	string oName;
	string imagesExtensions[8] = { "_box_cover", "_image1" , "_image2" , "_image3" , "_image4", "_image5" , "_image6" , "_poster" };
	string listOfHeights[8] = { "480" , "120" , "160" , "170" , "300" , "375" , "375" , "1280" };
	string listOfWidths[8] = { "720" , "150" , "149" , "160" , "300" , "200" , "384" , "720" };

	for (int i = 0; i < temp.size(); i++) {
		for (int j = 0; j < list.size(); j++) {
			bool bo = false;
			for (int k = 0; k < 8; k++) {
				if (temp[i].substr(list[j].oldName.size(), temp[0].size()) == imagesExtensions[k] &&
					list[j].height == listOfHeights[k] && list[j].width == listOfWidths[k])  bo = true;
			}
			//cout << temp[i].substr(list[j].oldName.size(), temp[0].size()) << endl;
			//cout << list[j].height << " "  << list[j].width << endl;
			if (temp[i].substr(0, list[j].oldName.size()) == list[j].oldName && bo) {
				string oldName = "Images\\";
				//cout << "Substring" << endl;
				//cout << temp[i].substr(0, list[j].oldName.size()) << endl;
				string newName = "Images\\";
				newName.append(list[j].newName);
				newName.append(".jpg");
				oldName.append(temp[i]);
				oldName.append(".jpg");
				//cout << "newName: " << newName << " oldName: " << oldName << endl;
				char *New = new char[newName.length() + 1];
				strcpy(New, newName.c_str());
				char *Old = new char[oldName.length() + 1];
				strcpy(Old, oldName.c_str());
				//cout << i <<  ". Old: " << Old << " New:" << New << endl;
				rename(Old, New);
				delete[] New;
				delete[] Old;
			}
		}
	}
	*/
	
	stringstream ss;
	string test = "UTABL010112380452172";
	ss << "robocopy \\\\DG-FS-03\\cablelabs1.1-1\\" + test + " C:\\Users\\Zlatic\\Desktop\\Test2 UTABL010112380452172_box_cover.jpg";

	string commandLine = ss.str();

	//examine the commandline!
	cout << commandLine << "\n";

	STARTUPINFOA si;
	PROCESS_INFORMATION pi;
	memset(&si, 0, sizeof(si));
	si.cb = sizeof(si);
	memset(&pi, 0, sizeof(pi));

	char *buf = _strdup(commandLine.c_str());
	CreateProcessA(0, buf, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	free(buf);

	return 0;
}


int foo()
{
	stringstream ss;
	string test = "UTABL010112380452172";
	ss << "robocopy \\\\DG-FS-03\\cablelabs1.1-1\\" + test + " C:\\Users\\Zlatic\\Desktop\\Test2 UTABL010112380452172_box_cover.jpg";

	string commandLine = ss.str();

	//examine the commandline!
	cout << commandLine << "\n";

	STARTUPINFOA si;
	PROCESS_INFORMATION pi;
	memset(&si, 0, sizeof(si));
	si.cb = sizeof(si);
	memset(&pi, 0, sizeof(pi));

	char *buf = _strdup(commandLine.c_str());
	CreateProcessA(0, buf, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	free(buf);

	return 1;
}


