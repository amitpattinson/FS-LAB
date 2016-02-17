//============================================================================
// Name        : lab2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<sstream>
#include<stdlib.h>
#include<string>
using namespace std;

class student{
	public:string usn;
	string name;
	int sem;
	string branch;
	public:string buffer;
	public:fstream f1;

	public:void pack()
	{
		string temp,sem1;
		stringstream out;
		out<<sem;
		sem1=out.str();
		temp.erase();
		temp=usn+'|'+name+'|'+sem1+'|'+branch;
		if(temp.length()<100)
		{
			for(int i=temp.length()+1;i<=100;i++)
			{
				temp+="$";
			}
		}
		buffer+=temp;
	}

	public:void datain()
		{
			cout<<"Enter USN: ";
			cin>>usn;
			cout<<"Enter Name: ";
			cin>>name;
			cout<<"Enter Semester: ";
			cin>>sem;
			cout<<"Enter Branch: ";
			cin>>branch;
		}

	void write()
		{
			f1.open("file.txt",ios::out|ios::app);
			f1<<buffer;
			f1.close();
		}

	int unpack();
	void modify();
	void del();

	int search(string key)
	{
		int p[4];
		int flag=0,pos;
		f1.open("file.txt",ios::in);
		while(!f1.eof())
		{
		  f1.getline(buffer,100);
		  pos=file.tellp();
		  p=unpack();
		  if(key==usn)
		  {
			  flag=1;
			  return p[0];
		  }
		  if(key==name)
		  {
			  flag=1;
			  return p[1];
		  }
		  if(key==sem)//convert sem to string
		  {
			  flag=1;
			  return p[2];
		  }
		  if(key==branch)
		  {
			  flag=1;
			  return p[3];
		  }

		}
		return pos;
	}

	int unpack()
	{
		int i=0,p[4];
		while(buffer[i]!='|')
		{
			usn=buffer[i];
			i++;
			p[0]=file.tellp();
		}
		while(buffer[i]!='|')
		{
			name=buffer[i];
			i++;
			p[1]=file.tellp();
		}
		while(buffer[i]!='|')
		{
			sem=buffer[i];
			i++;
			p[2]=file.tellp();
		}
		while(buffer[i]!='$')
		{
			branch=buffer[i];
			i++;
			p[3]=file.tellp();
		}
		return p;
	}

};

int main() {
	int choice;
	sting key;
	student s;
	while(1)
	{
		cout<<"Enter 1.Insert 2.search 3.modify 4.Delete 5.Exit";
		cin>>choice;
		switch(choice)
		{
		case 1:s.datain();
			   s.pack();
			   s.write();
			   break;

		case 2:cout<<"\nEnter key to be searched for: ";
				cin>>key.
				int flag=s.search(key);
				break;

		/*case 3:s.modify();
			   break;

		case 4:s.del();
			   break; */

		case 5:exit(0);
				break;

		default:cout<<"\nWrong input!";
		}
	}
	return 0;
}


