#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <conio.h>

using namespace std;
int i = 0;

bool compare(const pair<int, double> x, const pair<int, double> y)
{
  return x.second > y.second;
}

class Employee
{
public:
    int id; // identyfikator pracownika
    string name;
    string surname;
    string departmentid; //identyfikator działu w którym pracuje dane osoba
    string position;     //stanowisko na którym pracuje dana osoba

    void print()
    {
        cout << "ID pracownika: " << id << "\n Imie i nazwisko:" << name << " " << surname << "\n Departament i pozycja: " << departmentid << " - " << position << "\n";
    }
};

class HRMS
{
private:
    map<int, Employee> pracownik;
    map<string, vector<int>> pracownik_depid;
    map<int, double> pracownik_salary;

public:
    void add(Employee employee, string departmentid, double salary) //ampersant przed employee moze byc potrzebny
    {
        employee.departmentid = departmentid;
        employee.id = i;
        i++;
        pracownik[employee.id] = employee;

        pracownik_depid[departmentid].push_back(employee.id);

        pracownik_salary[employee.id] = salary;
    }

    void changeSalary(int pracownik_id, double salary)
    {
        pracownik_salary[pracownik_id] = salary;
    }

    void printDepartment(string departmentid)
    {
        cout << "\nPosortowano po departmentid: " << departmentid << endl;
        vector<int> vect = pracownik_depid[departmentid];
        for (int id : vect)
        {
            pracownik[id].print();
        }
    }

    void printSalaries()
    {
        for (map<int, Employee>::iterator it = pracownik.begin(); it != pracownik.end(); ++it)
        {
            it->second.print();
            cout << " Wynagrodzenie: " << pracownik_salary[it->first] << "zl" << endl;
        }
    }

    void printSalariesSorted()
    {
        list<pair<int, double>> sortuj;

        for (map<int, double>::iterator it = pracownik_salary.begin(); it != pracownik_salary.end(); ++it)
        {
            sortuj.push_back(make_pair(it->first, it->second));
        }
        sortuj.sort(compare);

        cout << "\nPosortowano po wynagrodzeniu: " << endl;
        for (list<pair<int, double>>::iterator it = sortuj.begin(); it != sortuj.end(); ++it)
        {
            pracownik[it->first].print();
            cout << " Wynagrodzenie: " << pracownik_salary[it->first] << "zl" << endl;
        }
    }
};

main()
{
    HRMS dane;
    Employee osoba;

    osoba.name = "Piotr";
    osoba.surname = "Kawka";
    osoba.position = "Szef";
    dane.add(osoba, "Kuchnia", 5000.00);

    osoba.name = "Pawel";
    osoba.surname = "Kot";
    osoba.position = "Kucharz";
    dane.add(osoba, "Kuchnia", 2800.00);

    osoba.name = "Piotr";
    osoba.surname = "Opoka";
    osoba.position = "Pomoc kuchenna";
    dane.add(osoba, "Kuchnia", 2000.50);

    osoba.name = "Jakub";
    osoba.surname = "Nowak";
    osoba.position = "Serwisant";
    dane.add(osoba, "Serwis", 3000.00);

    osoba.name = "Joanna";
    osoba.surname = "Kulig";
    osoba.position = "Pomoc kuchenna";
    dane.add(osoba, "Kuchnia", 2100.60);

    osoba.name = "Krzysztof";
    osoba.surname = "Kulig";
    osoba.position = "Sprzedawca";
    dane.add(osoba, "Obsluga", 15000.03);

    osoba.name = "Jacek";
    osoba.surname = "Ogórek";
    osoba.position = "Serwisant";
    dane.add(osoba, "Serwis", 3000.05);

    osoba.name = "Wiktoria";
    osoba.surname = "Broniszewska";
    osoba.position = "Kucharz";
    dane.add(osoba, "Kuchnia", 8000.60);

    osoba.name = "Jakub";
    osoba.surname = "Lach";
    osoba.position = "Kelner";
    dane.add(osoba, "Obsluga", 5000.00);

    osoba.name = "Marcin";
    osoba.surname = "Lach";
    osoba.position = "Serwisant";
    dane.add(osoba, "Serwis", 4000.45);

    dane.printDepartment("Kuchnia");
    dane.printDepartment("Serwis");
    dane.printDepartment("Obsluga");

    cout << "\n";
    dane.printSalaries();
    dane.printSalariesSorted();
    getch();
    return 0;
}