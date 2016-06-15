#include "stdafx.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class folder;

class file {
public:
	string name;
	string info;
	folder *parent;
};

class folder {

public:
	string name;
	folder *parent;
	vector<file> files;
	vector<folder> folders;
	bool createfile(string name);
	bool createfolder(string name);
	void list();
	folder();
};

folder::folder()
{

}


bool folder::createfile(string name) {
	file temp;
	temp.parent = this;
	for (int i = 0; i < files.size(); i++)
	{
		if (files[i].name == name) return 0;
	}
	temp.name = name;
	files.push_back(temp);
	return 1; 
}

bool folder::createfolder(string name) {
	folder temp;
	temp.parent = this;
	for (int i = 0; i < folders.size(); i++)
	{
		if (folders[i].name == name) return 0;
	}
	temp.name = name;
	folders.push_back(temp);
	return 1;
}

void folder::list()
{
	cout << endl;
	for (int i = 0; i < folders.size(); i++)
	{
		cout << folders[i].name << endl;
	}
	cout << "_______________________" << endl;
	for (int i = 0; i < files.size(); i++)
	{
		cout << files[i].name << endl;
	}
	cout << endl;
}

folder open(string name, folder& fold)
{
	for (int i = 0; i < fold.folders.size(); i++)
	{
		if (fold.folders[i].name == name)
		{
			return fold.folders[i];
		}
	}
}

folder back(folder& fold)
{
	return *fold.parent;
}

int main()
{
	folder root;
	root.name = "root";

	string temple;
	string command;
	while (temple != "end")
	{
		cin >> temple;

		if (temple == "list") root.list();
		if (temple == "cd")
		{
			cin >> command;
			root = open(command, root);
		}
		if (temple == "mkdir")
		{
			cin >> command;
			root.createfolder(command);
			cout<< root.folders[0].parent->name<<endl;
		}
		if (temple == "touch")
		{
			cin >> command;
			root.createfile(command);
		}
		if (temple == "cd..")
		{
			root = back(root);
		}
	}

	return 0;
}