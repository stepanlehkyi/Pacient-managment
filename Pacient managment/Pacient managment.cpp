/*                  DentalClinic
This program is created for easy dental managment.

*/

#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <windows.h>
using namespace std;

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
    Pacient():name(""),surname(""),patername(""),sex(0),birth_date(""),telephone_number(""),adress(""),diagnosis(""),complaints(""),allergic_history(""){}
    Pacient (string name,string surname, string patername, bool sex, string birth_date, string telephone_number, string adress, string diagnosis, string complaints,string allergic_history)
    {
        Init(name, surname, patername, sex, birth_date, telephone_number, adress, diagnosis, complaints, allergic_history);
    }
    void Init(string name, string surname, string patername, bool sex, string birth_date, string telephone_number, string adress, string diagnosis, string complaints,string allergic_history) {
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

class Menu {
public:

    void Start() {
        cout << "��� ��� ���� �������� DentalClinic " << endl;
        cout << "��� 䳿, �� �� ������ ������. ������� ���� � �������: \n";
        cout << "1-������ ������ ��������;\n";
        cout << "2-�������� ��������;\n";
        cout << "3-����������� ������ ��������;\n";
       // cout << "4-�������� ����������;\n";
     //   cout << "4-����������� ����������;\n";
        cout << "4-����� ��������;\n";
        }



};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   // �������� ��'� ���� �������, �������� ������, ���� ������
    Pacient a;
    a.Init("������","������","���������",0,"26.06.1995","+380975410329","�.�����-���������, ���.����������� 30, 12","������� ������ 45 ","���������� ��� � �������� ������� ��� ","������������� ������� �� ���������") ;
    cout << a.GetName() << "\n" << a.GetSurName() << "\n" << a.GetPaterName() << "\n"<<a.GetSex()<<"\n"<<a.GetBirthDate()<<"\n"<< a.GetTelephone_number()<<"\n"<<a.GetAdress()<<"\n"<<a.GetDiagnosis()<<"\n"<<a.GetComplaints()<<"\n"<<a.GetAllergic_history()<<"\n";




    return 0;
}

