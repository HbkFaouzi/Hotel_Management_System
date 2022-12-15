/*
	Tittle		: Hotel Management System
	Author		: Faouzi Brice Ouedraogo
	Language	: C++

*/

#include<fstream> //redefines a set or operations for handling files related to input and output
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<dos.h>
#include<iostream>



// Interface function 
using namespace std;

void intro()
{
		cout<<"\n\n\t            ";
		cout << "     Hotel Management System";
		cout << "\n\n\t\t\t\t     MADE BY ";
		cout << "\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
		cout << "\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
		cout << "||\t\t\t\t\t\t\t\t\t      ||";
		cout << "||\t\t\t\t\t\t\t\t\t      ||";
		cout << "||\t\t\t\tFAOUZI BRICE OUEDRAOGO\t\t\t      ||";
		cout << "||\t\t\t\t\t\t\t\t\t      ||";
		cout << "||\t\t\t\t\t  \t\t\t\t      ||";
		cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
		cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
}

void head()
{
	cout << "\n";
	cout << "******************************************\n";
	cout << " ***************************************\n";
	cout << " |\t\t\t\t       |\n";
	cout << " |\tPacific Group of Hotels\t       |\n";
	cout << " |\t\t\t\t       |\n";
	cout << " **************************************";
	cout << "\n*****************************************";
}

void time()
{
	int i = 0;
	long long int j;
	cout << "\n\n\n Connectin to server\n Syncing Data";
	while (i < 10)
	{
		for (j=5;j>=4;j++) 
		{
			if (j == 99999)	
			{
				cout << ".";
				break;
			}
		}
		++i;
	}
}

// Hotel class

class hotel {
private:
	int room_no;
	char name[30];
	char address[50];
	char phone[15];
	int days;
	float fare;
public:
	void main_menu();			// To display the main menu
	void add();					// To book a room
	void display();				// To display the customer record
	void rooms();				// To display allotted rooms
	void edit();				// To edit the customer record
	int check(int);				// To check room status
	void modify(int);			// To modify the record
	void delete_rec(int);		// To delete the record
};

void hotel::main_menu()
{
	int choice = 0;
	while (choice != 5)
	{
		system("cls");
		head();
		cout << "\n\t    *************";
		cout << "\n\t    * MAIN MENU *";
		cout << "\n\t    *************";
		cout << "\n\n\n\t1.Book A Room";
		cout << "\n\t2.Customer Record";
		cout << "\n\t3.Rooms Allotted";
		cout << "\n\t4.Edit Record";
		cout << "\n\t5.Exit";
		cout << "\n\n\tEnter Your Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1: add();
			break;
		case 2: display();
			break;
		case 3: rooms();
			break;
		case 4: edit();
			break;
		case 5: break;
		default:
		{
			cout << "\n\n\t\tWrong choice..!!";
			cout << "\n\t\t\tPress any key to continue..!!";
			//getch();
		}
		}

	}
}

void hotel::add()
{
	ifstream fin;
	system("cls");
	head();
	int r, flag;
	ofstream fout("Record.dat", ios::app);
	cout << "\n Enter customer details";
	cout << "\n ------------------------";
	cout << "\n\n Room no: ";
	cin >> r;
	flag = check(r);
	if (flag)
		cout << "\n Sorry !!!Room is already booked";
	else {
		room_no = r;
		cout << "\n";
		cout << " Name: ";
		cin.getline(name, sizeof name);
		cout << " Address: ";
		cin.getline(address, sizeof address);
		cout << " Phone No: ";
		cin.getline(phone, sizeof phone);
		cout << " No of days to checkout: ";
		cin >> days;
		fare = days * 900;				// 900 is currently set as the default price per day
		fout.write((char*)this, sizeof(hotel));
		cout << "\n Room is booked !!!";
	}
	cout << "\n Press any key to continue ...!!";
	fin.close();
}

void hotel::display() {
	system("cls");
	head();
	ifstream fin("Record.dat", ios::in);
	int r, flag=-1;
	cout << "\n Enter room no: ";
	cin >> r;
	while (!fin.eof()) {
		fin.read((char*)this, sizeof(hotel));
		if (room_no == r) {
			system("cls");
			head();
			cout << "\n Customer Details";
			cout << "\n ----------------";
			cout << "\n\n Room no: " << room_no;
			cout << "\n Name: " << name;
			cout << "\n Address: " << address;
			cout << "\n Phone no: " << phone;
			cout << "\n Days: " << days;
			cout << "\n Total Fare: " << fare;
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "\n Sorry Room no. not found or vacant....!!";
	cout << "\n\n Press any key to continue....!!";
	//;
	fin.close();
}

void hotel::rooms() {
	system("cls");
	head();
	ifstream fin("Record.dat", ios::in);
	cout << "\n\t\t\t    List Of rooms allotted";
	cout << "\n\t\t\t    ----------------------";
	while (!fin.eof()) {
		fin.read((char*)this, sizeof(hotel));
		cout << "\n Room no: " << room_no << "\n Name: " << name;
		cout << "\n Address: " << address << "\n Phone: " << phone;
		cout << "\n Days: " << days << "\n Total: " << fare;
		cout << "\n**********************************";
	}
	cout << "\n\n\n\t\t\tPress any key to continue.....!!";
	fin.close();
}

void hotel::edit()
{
	system("cls");
	head();
	int choice, r;
	cout << "\n EDIT MENU";
	cout << "\n ---------";
	cout << "\n\n 1.Modify customer record";
	cout << "\n 2.Delete customer record";
	cout << "\n Enter your choice: ";
	cin >> choice;
	system("cls");
	head();
	cout << "\n Enter room no: ";
	cin >> r;
	switch (choice)
	{
	case 1:	modify(r);
		break;
	case 2:	delete_rec(r);
		break;
	default: cout << "\n Wrong Choice.....!!";
	}
	cout << "\n Press any key to continue....!!!";
	
}

int hotel::check(int r)
{
	int flag = 0;
	ifstream fin("Record.dat", ios::in);
	while (!fin.eof())
	{
		fin.read((char*)this, sizeof(hotel));
		if (room_no == r)
		{
			flag = 1;
			break;
		}
	}
	fin.close();
	return(flag);
}

void hotel::modify(int r)
{
	system("cls");
	head();
	long pos, flag = 0;
	fstream file("Record.dat", ios::in | ios::out | ios::binary);
	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char*)this, sizeof(hotel));
		if (room_no == r)
		{
			cout << "\n Enter New Details";
			cout << "\n -----------------";
			cout << "\n Name: ";
			cin.getline(name, sizeof name);
			cout << " Address: ";
			cin.getline(address, sizeof address);
			cout << " Phone no: ";
			cin.getline(phone, sizeof phone);
			cout << " Days: ";
			cin >> days;
			fare = days*900;
			file.seekg(pos);
			file.write((char*)this, sizeof(hotel));
			cout << "\n Record is modified....!!";
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		cout << "\n Sorry Room no. not found or vacant...!!";
	file.close();
}

void hotel::delete_rec(int r)
{
	system("cls");
	head();
	int flag = 0;
	char ch;
	ifstream fin("Record.dat", ios::in);
	ofstream fout("temp.dat", ios::out);
	while (!fin.eof())
	{
		fin.read((char*)this, sizeof(hotel));
		if (room_no == r)
		{
			cout << "\n Name: " << name;
			cout << "\n Address: " << address;
			cout << "\n Phone No: " << phone;
			cout << "\n Days: " << days;
			cout << "\n Total Fare: " << fare;
			cout << "\n\n Do you want to delete this record(y/n): ";
			cin >> ch;
			if (ch == 'n')
				fout.write((char*)this, sizeof(hotel));
			flag = 1;
			break;
		}
		else
			fout.write((char*)this, sizeof(hotel));
	}
	fin.close();
	fout.close();
	if (flag == 0)
		cout << "\n Sorry room no. not found or vacant...!!";
	else
	{
		remove("Record.dat");
		rename("temp.dat", "Record.dat");
	}
}

// main function

int main()
{
	system("color 0A");
	hotel h;
	system("cls");
	cout << "\n\n\n";
	intro();
	time();
	cout << "\n\n\n\t\t\tPress any key to continue...!!!";
	//sleep(200);

	
	system("cls");
	head();
	char id[5], pass[7];
	cout << "\n\n\tUsername => ";
	cin >> id;
	cout << "\n\tPassword => ";
	cin >> pass;
	cout << "\n\n\t";
	time();
	cout << "\t";
	if (strcmp(id, "admin") == 0 && strcmp(pass, "****") == 0)
		cout << "\n\n\t\t\t !!! Login successfull!!!";
	else
	{
		cout << "\n\n\t\t\t!!!Wrong id or password!!!";
		exit(-1);
	}
	system("cls");
	h.main_menu();
	
	return 0;
}