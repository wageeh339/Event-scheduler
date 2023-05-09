#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include "Event.h"

using namespace std;
struct user
{
	string name;
	string pass;

};



list<Event> UnDone;
list<Event> Done;
list<user>User;


void readfile() {
	Event e;
	user u;
	ifstream myfile;
	myfile.open("file.txt");
	if (myfile.is_open())
	{
		while (myfile >> e.Name >> e.id >> e.Place >> e.StartDay >> e.StartTime >> e.EndTime)
		{
			UnDone.push_back(e);
		}
		myfile.close();
	}
	else
		cout << "Unable to open file";

	myfile.open("file2.txt");
	if (myfile.is_open())
	{
		while (myfile >> e.Name >> e.id >> e.Place >> e.StartDay >> e.StartTime >> e.EndTime)
		{
			Done.push_back(e);
		}
		myfile.close();
	}
	else
	{
		cout << "Unable to open file";
	}
	myfile.open("user.txt");
	if (myfile.is_open())
	{
		while (myfile >> u.name >> u.pass)
		{
			User.push_back(u);
		}
		myfile.close();
	}

}

void writefile() {
	ofstream out_file;
	out_file.open("file.txt");
	list<Event>::iterator it;

	for (it = UnDone.begin(); it != UnDone.end(); it++)
	{
		out_file << (*it).Name << ' ' << (*it).id << ' ' << (*it).Place << ' ' << (*it).StartDay << ' ' << (*it).StartTime << ' ' << (*it).EndTime << ' ' << endl;
	}
	out_file.close();

	out_file.open("file2.txt");
	for (it = Done.begin(); it != Done.end(); it++)
	{
		out_file << (*it).Name << ' ' << (*it).id << ' ' << (*it).Place << ' ' << (*it).StartDay << ' ' << (*it).StartTime << ' ' << (*it).EndTime << ' ' << endl;
	}
	out_file.close();
	out_file.open("user.txt");
	list<user>::iterator t;
	for (t = User.begin(); t != User.end(); t++)
	{
		out_file << (*t).name << ' ' << (*t).pass << ' ' << endl;
	}
	out_file.close();
}

bool startSort(Event e1, Event e2)
{
	return (e1.StartDay < e2.StartDay);
}

bool remdSort(Event e1, Event e2)
{
	return (e1.RemTime < e2.RemTime);
}


int main()
{
	system("color 71");
	readfile();
	user USER;
	int beg;
	int date;
	cout << "                             ***Welcome To Event Scheduler***" << endl;
	cout << "Press 1 to Login /n Press 2 To register" << endl;
	cin >> beg;
	bool enter = false;
	if (beg == 1)
	{
		bool log = true;
		while (log)
		{
			if (User.size() == 0)
			{
				cout << "There is no Users , You must Regsite First....." << endl;
				user reg;
				cout << "enter The New User Name OF You :";
				cin >> reg.name;
				cout << endl;
				cout << "enter The New Password of you :";
				cin >> reg.pass;

				bool ex = false;
				list<user>::iterator t;
				for (t = User.begin(); t != User.end(); t++)
				{
					if ((*t).name == reg.name)
					{
						ex = true;
					}

				}
				if (ex)
				{
					cout << "The username Is Taken Please Try Any another User name" << endl;
				}
				else
				{
					USER.name = reg.name;
					USER.pass = reg.pass;
					User.push_back(reg);
					enter = true;
				}


				system("CLS");
			    cout << "welcome....." << reg.name << endl;
				break;
				
			}



			else {

				cout << "Enter The UserName :";
				cin >> USER.name;
				cout << endl;
				cout << "Enter The password :";
				cin >> USER.pass;
				list<user>::iterator t;
				for (t = User.begin(); t != User.end(); t++)
				{

					if ((*t).name == USER.name && (*t).pass == USER.pass)
					{
						cout << "Welcome To Our Program" << endl;
						enter = true;
						log = false;
						break;
					}
					else
					{
						log = true;
						cout << "***Wrong Username***" << endl;
					}


				}
			}
		}
	}
	else if (beg == 2)
	
	{
		bool con = true; //boolian for cont. if the User name is exit ...
		while (con)
		{
		user reg;
		cout << "enter The New User Name OF You :";
		cin >> reg.name;
		cout << endl;
		cout << "enter The New Password of you :";
		cin >> reg.pass;

		bool ex = false; // the bool for the name is exist or no 
	
		

			list<user>::iterator t;
			for (t = User.begin(); t != User.end(); t++)
			{
				if ((*t).name == reg.name)
				{
					ex = true;
				}

			}
			if (ex)
			{
				cout << "The username Is Taken Please Try Any another User name" << endl;

			}
			else
			{
				User.push_back(reg);
				USER.name = reg.name;
				enter = true;
				con = false;
			}
		}

	}


	list<Event>::iterator it;

	if (enter)
	{
		system("CLS");
		cout << "                              Welcome To Our Program" << endl;
		cout << "Enter today's date: ";
		cin >> date;

		int i = 0;
		int size = UnDone.size();
		bool loop = true;
		if (size != 0)
		{
			it = UnDone.begin();
			while (loop) {
				if ((*it).StartDay < date)
				{
					Done.push_back((*it));
					UnDone.erase(it);
					break;
				}
				i++;
				if (i < size)
					it++;
				else
					loop = false;
			}
		}


		int choice;
		while (true)
		{

			cout << endl << "                ^_^ Welcome  ::   " << USER.name << "^_^" << endl << endl;
			cout << " Press 1 To Add Event \n Press 2 To Edit Event \n Press 3 To Delete Event \n Press 4 To Search on An Event \n Press 5 To Display Events \n Press 6 to Exit" << endl;
			cin >> choice;

			if (choice == 1) // Function Add Event ;;
			{
				system("CLS");
				int num;

				cout << "***Enter The Number Of The Events That You Want To Enroll***" << endl;
				cin >> num;

				for (int i = 0; i < num; i++)
				{
					Event e;

					cout << "Enter The Name Of The Event " << endl;

					cin >> e.Name;

					cout << "Enter The ID Of The Event " << endl;
					cin >> e.id;

					cout << "Enter The Place" << endl;
					cin >> e.Place;

					cout << "Enter The StarDay" << endl;
					cin >> e.StartDay;

					cout << "Enter The Start Time" << endl;
					cin >> e.StartTime;

					cout << "Enter The Endtime " << endl;
					cin >> e.EndTime;


					bool exist = false;
					list<Event>::iterator it;
					for (it = UnDone.begin(); it != UnDone.end(); it++)
					{
						if ((*it).id == e.id)
							exist = true;
					}
					for (it = UnDone.begin(); it != UnDone.end(); it++)
					{
						if ((*it).Place == e.Place && (*it).StartDay == e.StartDay)
						{
							if ((*it).EndTime > e.StartTime)
								exist = true;
						}

					}
					if (exist)
						cout << "You can't add\n";
					else
					{
						UnDone.push_back(e);
						cout << "Event Has been Added succesfully" << endl;
					}


				}
			}
			else if (choice == 2)              //Edit Function 
			{
				system("CLS");
				int Id;

				cout << "***Enter The ID Of The Event That You Want To Edit***" << endl;
				cin >> Id;
				list<Event>::iterator it;

				for (it = UnDone.begin(); it != UnDone.end(); it++)
				{
					if ((*it).id == Id)
					{
						cout << "Event's data:\nName:" << (*it).Name << "\nPlace: " << (*it).Place << "\nDay of event: " <<
							(*it).StartDay << "\nStart Time Of Event: " << (*it).StartTime << "EndTime OF Event:" << (*it).EndTime;

						cout << "\nPress 1 To Edit The Name, Press 2 to Edit The Palce , Press 3 To Edit The StartDay ,Press 4 To Edit Starttime , Press 5 to Edit EndTime ";
						int choice;
						cin >> choice;
						if (choice == 1)
						{
							cout << "Write new name: ";
							cin >> (*it).Name;
						}
						else if (choice == 2)
						{
							cout << "Write The New Place :";
							cin >> (*it).Place;
						}
						else if (choice == 3)
						{
							cout << "Write The New StartDay";
							cin >> (*it).StartDay;
						}
						else if (choice == 4)
						{
							cout << "Write The New StartTime:";
							cin >> (*it).StartTime;
						}
						else if (choice == 5)
						{
							cout << "Write The New EndTime:";
							cin >> (*it).EndTime;
						}
					}
					else
					{
						cout << "Wrong" << endl;
						continue;
					}
				}

			}
			else if (choice == 3) // function delete
			{
				system("CLS");

				int Id;

				cout << endl << "***Enter The ID Of The Event That You Want To delete***" << endl;
				cin >> Id;
				list<Event>::iterator it;

				for (it = UnDone.begin(); it != UnDone.end(); it++)
				{
					if ((*it).id == Id)
					{
						cout << "Event's data:\nName:" << (*it).Name << "\nPlace: " << (*it).Place << "\nDay of event: " <<
							(*it).StartDay << "\nStart Time Of Event: " << (*it).StartTime << "EndTime OF Event:" << (*it).EndTime << endl;
						cout << "Are You Sure?? 1>>> (YES) | | | | | | | 2>>>> (NO)......" << endl;
						int sure = 0;
						cin >> sure;
						if (sure == 1)
						{
							UnDone.erase(it);
							cout << "                                Event Has been deleted succesfuly                            " << endl;

							break;
						}
						else
							break;

					}
					else
					{
						cout << "                    Event Has not been Found or The ID is Wrong......" << endl;
						continue;
					}
				}

			}
			else if (choice == 4) //function search 
			{
				system("CLS");
				bool found = false;
				string NAME;
				cout << "               ***Enter The Name of The Event That You Want To Search On It***              " << endl;
				cin >> NAME;
				list<Event>::iterator it;

				for (it = UnDone.begin(); it != UnDone.end(); it++)
				{
					if ((*it).Name == NAME)
					{

						cout << "Event's Data Is :: " << endl << "The Name OF The Event is : " << (*it).Name << endl << "the ID OF the Event is : " << (*it).id << endl << "The Place Is : " << (*it).Place << endl << "The Day Of The Event is : " << (*it).StartDay << endl << "The StartTime Of The event is : " << (*it).StartDay << endl;
						found = true;
					}


				}


				for (it = Done.begin(); it != Done.end(); it++)
				{
					if ((*it).Name == NAME)
					{
						cout << "Event's Data is ::" << endl << "The Name OF The Event is :" << (*it).Name << endl << "the ID OF the Event is :" << (*it).id << endl << "The Place Is :" << (*it).Place << endl << "The Day Of The Event is :" << (*it).StartDay << endl << "The StartTime Of The event is:" << (*it).StartDay << endl;
						found = true;
					}


				}
				if (found == false)
				{
					cout << "          Sorry The Event Is not Found" << endl;
					continue;
				}


			}

			else if (choice == 5) //function display;;;
			{
				system("CLS");
				list<Event>::iterator it;

				for (it = UnDone.begin(); it != UnDone.end(); it++)
				{
					(*it).calcRemTime(date);
				}

				for (it = Done.begin(); it != Done.end(); it++)
				{
					(*it).calcRemTime(date);
				}

				cout << "***Press 1 To Sort By Start Time,,Press 2 To Sort By Remaining Time*** " << endl;
				int cc;
				cin >> cc;
				if (cc == 1)
				{

					UnDone.sort(startSort);
					Done.sort(startSort);
				}
				else
				{

					UnDone.sort(remdSort);
					Done.sort(remdSort);
				}
				cout << "UNDONE EVENTS :\n\n";
				for (it = UnDone.begin(); it != UnDone.end(); it++)
				{
					cout << "Event's data:\nName:" << (*it).Name << "\nPlace: " << (*it).Place << "\nDay of event: " <<
						(*it).StartDay << "\nStart Time Of Event: " << (*it).StartTime << "\nEndTime OF Event: " << (*it).EndTime << "\nRemainder time: " << (*it).RemTime << "\nThe ID OF The Event:" << (*it).id << endl << endl << endl;
				}
				cout << "DONE EVENTS :\n\n";
				for (it = Done.begin(); it != Done.end(); it++)
				{
					cout << "Event's data:\nName:" << (*it).Name << "\nPlace: " << (*it).Place << "\nDay of event: " <<
						(*it).StartDay << "\nStart Time Of Event: " << (*it).StartTime << "\nEndTime OF Event: " << (*it).EndTime << "\nThe ID OF The Event:" << (*it).id << endl;
				}


			}
			else if (choice == 6) //exit
			{
				cout << "                 Thank You for Using our Program" << endl;
				writefile();
				break;
			}

			else
				cout << "***Wrong Choice, Try again\n***";

		}
	}

	cout << endl;
	system("pause");
	return 0;

}


