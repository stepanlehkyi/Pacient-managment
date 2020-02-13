﻿/*                  DentalClinic
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
				getline(cin, buff);
				fild.SetAns(buff);
			}
			else
				std::cout << "\n";

		}

		std::cout << cl.Footer.GetText();
		if (cl.Footer.Inputable()) {

			std::cout << " ";
			std::string buff;
			getline(cin, buff);
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
	string sex;
	string birth_date;
	string telephone_number;
	string adress;
	string diagnosis;
	string complaints;
	string allergic_history;
public:
	
	Pacient() :name(""), surname(""), patername(""), sex(""), birth_date(""), telephone_number(""), adress(""), diagnosis(""), complaints(""), allergic_history("") {}
	Pacient(string name, string surname, string patername, string sex, string birth_date, string telephone_number, string adress, string diagnosis, string complaints, string allergic_history)
	{
		Init(name, surname, patername, sex, birth_date, telephone_number, adress, diagnosis, complaints, allergic_history);
	}
	void Init(string name, string surname, string patername, string sex, string birth_date, string telephone_number, string adress, string diagnosis, string complaints, string allergic_history) {
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
	bool SetSex(string sex) { this->sex = sex; return 1; }
	bool SetBirthDate(string birth_date) { this->birth_date = birth_date; return 1; }
	bool SetTelephone_number(string telephone_number) { this->telephone_number = telephone_number; return 1; }
	bool SetAdress(string adress) { this->adress = adress; return 1; }
	bool SetDiagnosis(string diagnosis) { this->diagnosis = diagnosis; return 1; }
	bool SetComplaints(string complaints) { this->complaints = complaints; return 1; }
	bool SetAllergic_history(string allergic_history) { this->allergic_history = allergic_history; return 1; }
	string GetName() { return name; }
	string GetSurName() { return surname; }
	string GetPaterName() { return patername; }
	string GetSex() { return sex; }
	string GetBirthDate() { return birth_date; }
	string GetTelephone_number() { return telephone_number; }
	string GetAdress() { return adress; }
	string GetDiagnosis() { return diagnosis; }
	string GetComplaints() { return complaints; }
	string GetAllergic_history() { return allergic_history; }
};

class SaveLoadSearchFiles {


protected:

	//	Pacient pacient;
	string PacientNameSurname;

	static bool FileExist(string name) {
		fstream file;

		file.open("C:\\Users\\admin\\source\\repos\\ConsoleApplication2\\ConsoleApplication2\\Pacient Base\\" + name + ".bin", fstream::in);
		if (!file.is_open())
			return 0;

		file.close();
		return 1;
	}

public:


	/*SaveLoadSearchFiles(Pacient pacient)
	{
		SetPacient(pacient);
		PacientNameSurname = pacient.GetName() + "_" + pacient.GetSurName() + ".bin";
	}
	*/

	static void Save(Pacient* obj) {
		fstream file;
		file.open("C:\\Users\\Stepan.Lehkyi\\source\\repos\\Pacient managment\\Pacient managment\\Pacient Base\\" + obj->GetName() + "_" + obj->GetSurName() + ".bin", ios::out);
		file.write((const char*)&obj, sizeof(obj));
		file.close();
	}

	static void Load(Pacient* obj, string name) {
		ifstream file;
		file.open("C:\\Users\\Stepan.Lehkyi\\source\\repos\\Pacient managment\\Pacient managment\\Pacient Base\\" + name + ".bin", ios::binary);
		if (file.is_open()) {
			cout << "file is open\n";
		}
		file.read((char*)&(*obj), sizeof(Pacient));
		file.close();

	}



};

class Program {
private:

	bool KeyIsEqualToVal(string key, vector<string> values) {
		for (auto val : values) {
			if (key == val)
				return 1;
		}
		return 0;
	}

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
			Fields("4.Sex(male/female):\t",1),
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
			Fields("4.Search by diagnosis\t"),
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
		Pacient buff;
		buff.SetName(page["Add menu"].fields[0].GetAns());
		buff.SetSurName(page["Add menu"].fields[1].GetAns());
		buff.SetPaterName(page["Add menu"].fields[2].GetAns());
		buff.SetSex(page["Add menu"].fields[3].GetAns());
		buff.SetBirthDate(page["Add menu"].fields[4].GetAns());
		buff.SetTelephone_number(page["Add menu"].fields[5].GetAns());
		buff.SetAdress(page["Add menu"].fields[6].GetAns());
		buff.SetDiagnosis(page["Add menu"].fields[7].GetAns());
		buff.SetComplaints(page["Add menu"].fields[8].GetAns());
		buff.SetAllergic_history(page["Add menu"].fields[9].GetAns());
		SaveLoadSearchFiles::Save(&buff);
		
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
			string answer = page["main menu"].Footer.GetAns();
			if (KeyIsEqualToVal(answer, { "1","Add","add","new" })) {
				AddPatient();
			}
			else if (KeyIsEqualToVal(answer, { "2" ,"rm" ,"remove" ,"Remove" })) {
				RemovePatient();

			}
			else if (KeyIsEqualToVal(answer, { "3", "show","Show","All","all" })) {
				ShowAllPatient();

			}
			else if (KeyIsEqualToVal(answer, { "4","search","search patient","Search" })) {
				SearchPatient();
				while (1) {
					if (KeyIsEqualToVal(answer, { "1","Search by name","by name","1.Search by name","name" })) {
						cout << "Search by name" << endl;
						system("pause");
						break;
					}
					else if (KeyIsEqualToVal(answer, { "2","Search by surname","by surname","1.Search by surname","surname" })) {
						cout << "Search by surname" << endl;
						system("pause");
						break;
					}
					else if (KeyIsEqualToVal(answer, { "3","Search by telephone number","by tel num","3.Search","number" })) {
						cout << "Search by telephone number" << endl;
						system("pause");
						break;
					}
					else if (KeyIsEqualToVal(answer, { "4","by diagnosis","4.Search","4.Search by diagnisis","diagnosis" })) {
						cout << "Search by diagnosis" << endl;
						system("pause");
						break;
					}
					else if (KeyIsEqualToVal(answer, { "5","back","5.Back","exit" })) {
						break;
					}
					else {

						cout << "Please, enter a correct value" << endl;
						system("pause");
						SearchPatient();

					}
				}

			}
			else if (KeyIsEqualToVal(answer, { "5","Edit","edit","edit patient" })) {
				EditPatient();
				while (1) {

				}

			}
			else if (KeyIsEqualToVal(answer, { "6","exit","Exit" })) {
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
	
	/*
	Pacient ab("Lehky", "Stepan", "Yosyfovich", 0, "26/06/1995", "+380975410329", "Ivano_Franliwsk", "Acute ", "Pain", "none");
	Pacient a("Lehkyi", "Stepan", "Yosyfovich", 0, "26/06/1995", "+380975410329", "Ivano_Franliwsk", "Acute ", "Pain", "none");
	Pacient h("BAN", "Ivan", "Ivanovich", 0, "13/12/1999", "+380975410329", "Ivano_Frankiw'sk", "Acute pulpitis", "Pain", "Alergic reaction on penicelinum");
	SaveLoadSearchFiles::Load(&h,"KABAN_Ivan");

	cout << h.GetName() << " " << h.GetSurName() << endl;
	*/


	return 0;
}