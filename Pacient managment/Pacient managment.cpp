/*                  DentalClinic
This program is created for easy dental managment.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include <windows.h>
#include <map>
using namespace std;

class Fields {
protected:
	bool inputable;
	std::string text;
	std::string ans;
public:
	Fields() :inputable(1), text("no text"), ans("no ans") {}
	Fields(const std::string& text, bool Inputable = 0) : inputable(Inputable), text(text), ans("no ans") {}
	bool Inputable() { return inputable; }
	bool SetAns(std::string Ans) {
		// add functional part
		ans = Ans;
		return 1;
	}
	std::string GetText() { return text; }
	std::string GetAns() { return ans; }

};

struct CheckList {
	std::string Header = "NOP";
	std::vector<Fields> fields;
	Fields Footer;
};

class View
{
public:

	static void NewPage(CheckList& cl) { 
		system("cls");

		std::cout << "\t" << cl.Header << "\t\n";
		for (Fields& fild : cl.fields)
			
		{
			std::cout << " " << fild.GetText();

			if (fild.Inputable()) {
				std::cout << " ";
				std::string buff;
				getline(cin,buff);
				fild.SetAns(buff);
			}
			else
				std::cout << "\n";

		}

		std::cout << cl.Footer.GetText();
		if (cl.Footer.Inputable()) {

			std::cout << " ";
			std::string buff;
			getline(cin,buff);
			cl.Footer.SetAns(buff);

		}
		else
			system("pause");

	}



};

class Pacient {
protected:
	string name;
	string surname;
	string patername;
	bool sex;
	string birth_date;
	string telephone_number;
	string adress;
	string diagnosis;
	string complaints;
	string allergic_history;
public:
	Pacient() :name(""), surname(""), patername(""), sex(0), birth_date(""), telephone_number(""), adress(""), diagnosis(""), complaints(""), allergic_history("") {}
	Pacient(string name, string surname, string patername, bool sex, string birth_date, string telephone_number, string adress, string diagnosis, string complaints, string allergic_history)
	{
		Init(name, surname, patername, sex, birth_date, telephone_number, adress, diagnosis, complaints, allergic_history);
	}
	void Init(string name, string surname, string patername, bool sex, string birth_date, string telephone_number, string adress, string diagnosis, string complaints, string allergic_history) {
		SetName(name);
		SetSurName(surname);
		SetPaterName(patername);
		SetSex(sex);
		SetBirthDate(birth_date);
		SetTelephone_number(telephone_number);
		SetAdress(adress);
		SetDiagnosis(diagnosis);
		SetComplaints(complaints);
		SetAllergic_history(allergic_history);
	}
	bool SetName(string name) { this->name = name; return 1; }
	bool SetSurName(string surname) { this->surname = surname; return 1; }
	bool SetPaterName(string patername) { this->patername = patername; return 1; }
	bool SetSex(bool sex) { this->sex = sex; return 1; }
	bool SetBirthDate(string birth_date) { this->birth_date = birth_date; return 1; }
	bool SetTelephone_number(string telephone_number) { this->telephone_number = telephone_number; return 1; }
	bool SetAdress(string adress) { this->adress = adress; return 1; }
	bool SetDiagnosis(string diagnosis) { this->diagnosis = diagnosis; return 1; }
	bool SetComplaints(string complaints) { this->complaints = complaints; return 1; }
	bool SetAllergic_history(string allergic_history) { this->allergic_history = allergic_history; return 1; }
	string GetName() { return name; }
	string GetSurName() { return surname; }
	string GetPaterName() { return patername; }
	bool GetSex() { return sex; }
	string GetBirthDate() { return birth_date; }
	string GetTelephone_number() { return telephone_number; }
	string GetAdress() { return adress; }
	string GetDiagnosis() { return diagnosis; }
	string GetComplaints() { return complaints; }
	string GetAllergic_history() { return allergic_history; }
};

class Program {
protected:
	map<string, CheckList> page;
public:

	void Init() {
		page["main menu"] = CheckList{
		  "Here is menu of DentalClinic.\n\tWhat do you want to do?: \n",
		{
		Fields("1-Add new pacient;\n"),
		Fields("2-Remove pacient;\n"),
		Fields("3-Show all pacients;\n"),
		Fields("4-Search pacient;\n"),
		Fields("5-Edit information about patient; \n"),
		Fields("6-Exit\n")
		},
			Fields("->", 1)
		};
		page["Add menu"] = CheckList{
			"Here is menu for add new pacient. Enter information: \n",
		{
			Fields("1.Name:\t",1),
			Fields("2.Surname:\t",1),
			Fields("3.Patername:\t",1),
			Fields("4.Sex:\t",1),
			Fields("5.Birth date:\t",1),
			Fields("6.Telephone number:\t",1),
			Fields("7.Adress:\t",1),
			Fields("8.Diagnosis:\t",1),
			Fields("9.Complaints:\t",1),
			Fields("10.Allergic history:\t",1)
		},
			Fields("\n Is everything entered correctly:(y/n)->", 1)
		};
		page["Remove menu"] = CheckList{
			"Here is menu for remove pacient. Choose by what you want to delete: \n",
		{
			Fields("1.By name\t"),
			Fields("2.By surname\t"),
			Fields("3.Back to main menu\t")
		},
			Fields("\n->", 1)
		};
		page["Search menu"] = CheckList{
			"Here is menu for pacient search. Choose a value, you want to search by:\n",
		{
			Fields("1.Search by name\t"),
			Fields("2.Search by surname\t"),
			Fields("3.Search by telephone number\t"),
			Fields("4.Search by diagnosis\t"),
			Fields("5.Back to main menu\t")
		},
			Fields("\nEnter by what value you want to search->", 1)
		};
		page["Edit menu"] = CheckList{
			"Here is menu for pacient edit. Firstly you should search a patient. Choose by what value, you want to search a pacient: \n",
		{
			Fields("1.Search by name\t"),
			Fields("2.Search by surname\t"),
			Fields("3.Search by telephone number\t"),
			Fields("4.Seearch by diagnosis\t"),
			Fields("5.Back to main menu\t")
		},
			Fields("\n->", 1)
		};
		page["Exit page"] = CheckList{
			"",
		{},
			Fields("Are you sure You want to exit?\t->(y/n)", 1)
		};

	}


	void AddPatient() {//adds a new Patient
		View::NewPage(page["Add menu"]);

	}

	void RemovePatient() { //creates a new page
		View::NewPage(page["Remove menu"]);

	}
	void ShowAllPatient() {
		//Load from file
	}
	void SearchPatient() { 
		View::NewPage(page["Search menu"]);
	
	}
	void EditPatient() {
		View::NewPage(page["Edit menu"]);

	}
	void ExitPage() {
		View::NewPage(page["Exit page"]);
		
			

	}

	void Start() {
		while (1) {
			auto& thisPage = page["main menu"];
			View::NewPage(thisPage);
			
			if (page["main menu"].Footer.GetAns() == "1"|| page["main menu"].Footer.GetAns() == "Add"|| page["main menu"].Footer.GetAns() == "add"|| page["main menu"].Footer.GetAns() == "new") {
				AddPatient();
				
			}
			else if (page["main menu"].Footer.GetAns() == "2"|| page["main menu"].Footer.GetAns() == "rm"|| page["main menu"].Footer.GetAns() == "remove"||page["main menu"].Footer.GetAns() == "Remove") {
				RemovePatient();
				
			}
			else if (page["main menu"].Footer.GetAns() == "3"|| page["main menu"].Footer.GetAns() == "show"|| page["main menu"].Footer.GetAns() == "Show"|| page["main menu"].Footer.GetAns() == "All"|| page["main menu"].Footer.GetAns() == "all") {
				ShowAllPatient();
				
			}
			else if (page["main menu"].Footer.GetAns() == "4"|| page["main menu"].Footer.GetAns() == "search"|| page["main menu"].Footer.GetAns() == "search patient"|| page["main menu"].Footer.GetAns() == "Search") {
				SearchPatient();
				while (1) {
					if (page["Search menu"].Footer.GetAns() == "1" || page["Search menu"].Footer.GetAns() == "Search by name" || page["Search menu"].Footer.GetAns() == "by name" || page["Search menu"].Footer.GetAns() == "1.Search by name" || page["Search menu"].Footer.GetAns() == "name") {
						cout << "Search by name" << endl;
						system("pause");
						break;
					}
					else if (page["Search menu"].Footer.GetAns() == "2" || page["Search menu"].Footer.GetAns() == "Search by surname" || page["Search menu"].Footer.GetAns() == "by surname" || page["Search menu"].Footer.GetAns() == "1.Search by surname" || page["Search menu"].Footer.GetAns() == "surname") {
						cout << "Search by surname" << endl;
						system("pause");
						break;
					}
					else if (page["Search menu"].Footer.GetAns() == "3" || page["Search menu"].Footer.GetAns() == "Search by telephone number" || page["Search menu"].Footer.GetAns() == "by tel num" || page["Search menu"].Footer.GetAns() == "3.Search" || page["Search menu"].Footer.GetAns() == "number") {
						cout << "Search by telephone number" << endl;
						system("pause");
						break;
					}
					else if (page["Search menu"].Footer.GetAns() == "4" || page["Search menu"].Footer.GetAns() == "by diagnosis" || page["Search menu"].Footer.GetAns() == "4.Search" || page["Search menu"].Footer.GetAns() == "4.Search by diagnisis" || page["Search menu"].Footer.GetAns() == "diagnosis") {
						cout << "Search by diagnosis" << endl;
						system("pause");
						break;
					}
					else if (page["Search menu"].Footer.GetAns() == "5" || page["Search menu"].Footer.GetAns() == "back" || page["Search menu"].Footer.GetAns() == "5.Back" || page["Search menu"].Footer.GetAns() == "exit") {
						break;
					}
					else {
						
						cout << "Please, enter a correct value" << endl;
						system("pause");
						SearchPatient();
						
						
					}
				}
				
			}
			else if (page["main menu"].Footer.GetAns() == "5"|| page["main menu"].Footer.GetAns() == "Edit"|| page["main menu"].Footer.GetAns() == "edit"|| page["main menu"].Footer.GetAns() == "edit patient") {
				EditPatient();
				while (1) {

				}
				
			}
			else if (page["main menu"].Footer.GetAns() == "6"|| page["main menu"].Footer.GetAns() == "exit"|| page["main menu"].Footer.GetAns() == "Exit") {
				ExitPage();
				if (page["Exit page"].Footer.GetAns() == "y")
				break;
			}
			else {
				cout << "Choose a correct value\n";
				system("pause");
				
			}
		}


	}


};



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Program menu;
	menu.Init();
	menu.Start();
	


	return 0;
}