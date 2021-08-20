#include<iostream>
#include<string.h>
#include<fstream>
#include<iostream>
#include<string.h>
#include<fstream>
#include<bits/stdc++.h>
#include<ctime>
#include <cstring>
#include<vector>
#include<ctype.h>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class RE{
	int id;
	char name[20];
	float price;
	public:
	RE()
	{
		id=0;
		strcpy(name,"No Property");
		price=0;
	}
	void setdata();
	void showdata();
	int storedata();
	void viewalldata();
	void searchdata(char*);
	void deletedata(char*);
	void updatedata(char*);
};
void RE::setdata()
{
	cout<<"Enter the ID , Property and Price:"<<endl;
	cin>>id;
	cin.ignore();
	cin.getline(name,19);
	cin>>price;
	
}
void RE::showdata() 
{
	cout<<"ID : "<<id<<endl<<"Property : "<<name<<endl<<"Price : "<<price<<endl;
	 
}
int RE::storedata()
{
	if(id==0&&price==0)
	{
		cout<<"\nData not initailized"<<endl;
		return 0;
		
	}
	else
	{
		ofstream fout;
		fout.open("REs.txt",ios::app);
		fout.write((char*)this,sizeof(*this));
		fout.close();
	}
	
}
void RE::viewalldata()
{
	ifstream fin;
	fin.open("REs.txt",ios::in);
	if(!fin)
	{
		cout<<"\nFile not found"<<endl;
		
	}
	else
	{
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			showdata();
			cout<<endl;
			fin.read((char*)this,sizeof(*this));
			
		}
		fin.close();
	}
}
void RE::searchdata(char* t)
{
	int count=0;
	ifstream fin;
	fin.open("REs.txt",ios::in);
	if(!fin)
	{
		cout<<"\n File not found"<<endl;
		
	}
	else
	{
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			if(!strcmp(t,this->name))
			{
				showdata();
				count++;
				
			}
			fin.read((char*)this,sizeof(*this));
			
		}
		if(count==0)
		{
			cout<<"Data not found"<<endl;
			
		}
		fin.close();
	}
}
void RE::deletedata(char* t)
{
	int flag=0;
	ifstream fin;
	ofstream fout;
	fin.open("REs.txt",ios::in);
	if(!fin)
	{
		cout<<"\nFile not exist"<<endl;
		
	}
	else
	{
		fout.open("Tempo.txt",ios::out);
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			if(strcmp(name,t))
			{
				fout.write((char*)this,sizeof(*this));
				
			}
			else
			{
				cout<<"\n\nPropery Deleted...."<<endl;
				flag=1;
			}
			fin.read((char*)this,sizeof(*this));
		}
		if(flag==0)
		{
			cout<<"\n\nProperty doesnt exist"<<endl;
		}
		fin.close();
		fout.close();
		remove("REs.txt");
		rename("Tempo.txt","REs.txt");
	}
}
void RE::updatedata(char* t)
{
	int found=0;
	fstream file;
	file.open("REs.txt",ios::in|ios::out|ios::ate);
	file.seekg(0);
	file.read((char*)this,sizeof(*this));
	while(!file.eof())
	{
		if(!strcmp(t,name))
		{
			setdata();
			file.seekp(file.tellp()-sizeof(*this));
			file.write((char*)this,sizeof(*this));
			found=1;
			
		}
		file.read((char*)this,sizeof(*this));
		
	}
	file.close();
	if(found==0)
	{
		cout<<"\n\nProperty not founf"<<endl;
	}
	else
	{
		cout<<"\n\nProperty updated"<<endl;
	}
	
}
int menu()
{
	int choice;
	time_t now = time(0);
    char* dt = ctime(&now);
	cout << "     Date  |    Time \n " << dt << endl;
	cout<<"\t\t---------------------------------";
	cout<<"\n\t\t     Real Estate Management"<<endl;
	cout<<"\t\t---------------------------------"<<endl;
	cout<<"\n\t==============================================";
	cout<<"\n\n\t\t 1. Add Property";
	cout<<"\n\n\t\t 2. View all Property";
	cout<<"\n\n\t\t 3. Search Property";
	cout<<"\n\n\t\t 4. Delete Property";
	cout<<"\n\n\t\t 5. Update Property";
	cout<<"\n\n\t\t 6. Exit";
	cout<<"\n\n\t\t Enter your choice : ";
	cout<<"\n\t==============================================\n";
	cin>>choice;
	return choice;
	
}
main()
{
	RE r1;
	char namee[20];
	while(1)
	{
		system("cls");
		switch(menu())
		{
			case 1:
				r1.setdata();
				r1.storedata();
				cout<<"Stored Property..."<<endl;
				break;
			case 2:
				r1.viewalldata();
				break;
			case 3:
				cout<<"Enter the property to search"<<endl;
				cin.ignore();
				cin.getline(namee,19);
				r1.searchdata(namee);
				break;
			case 4:
				cout<<"Enter the property to delete"<<endl;
				cin.ignore();
				cin.getline(namee,19);
				r1.deletedata(namee);
				break;
			case 5:
				cout<<"Enter the property for update"<<endl;
				cin.ignore();
				cin.getline(namee,19);
				r1.updatedata(namee);
				break;
			case 6:
				cout<<"\n Thank You :)"<<endl;
				system("cls");
				exit(0);
				break;
				default:
					cout<<"Invalid input"<<endl;
					
		}
		system("pause");
		
	}
	
}
