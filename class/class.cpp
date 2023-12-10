#include <iostream>
#include <string>
using namespace std;

class Company //класс Компании
{
private:

	string country;
	string NameCompany;
public:

	Company(string name, string country)

		: country(country), NameCompany(name) {}

	Company(string country)

		:country(country) {}

	Company();
		void getNameCompany()//metod
		{
			cout << NameCompany;
		}

		void getCountry()
		{
			cout << country;
		}
};

class Employee : public Company //класс сотрудники
{
private:

	string nameEmployee;

	int ageEmployee;

	string documentsEmployee;

	bool employeeMarried;

public:


	void setNameEmployee(string newNameEmployee) 
	{
		nameEmployee = newNameEmployee;
	}

	void setAgeEmployee(int newAgeEmployee)
	{
		ageEmployee = newAgeEmployee;
	}

	void employeeMarried(bool married)
	{
		employeeMarried = married;
	}

	void setDocumentsEmployee(string documents)
	{
		documentsEmployee = documents;
	}

	void getInfo()
	{
	cout << nameEmployee << "\t" << ageEmployee << "\t" << documentsEmployee << "\t" << employeeMarried <<endl;
	}
};

class Vehicle : public Company //класс транспорт
{
private:

	string NumberOfRegistration;

	int circleCount;

	string material;

	int passengersCount;

public:

	Vehicle(string material, string NameCompany, string country)

		: Company(NameCompany, country), material(material) {}

	Vehicle(string NumberOfRegistration, int circleCount, int passengersCount, string NameCompany, string country)

		: Company(NameCompany, country), NumberOfRegistration(NumberOfRegistration), circleCount(circleCount), passengersCount(passengersCount) {}

	Vehicle(string NumberOfRegistration, int circleCount, int passengersCount)

		: NumberOfRegistration(NumberOfRegistration), circleCount(circleCount), passengersCount(passengersCount) {}

	Vehicle(string NameCompany, string country)

		: Company(NameCompany, country) {}

	Vehicle();


	void setRegistrationNumber(string Number) //metod
	{
		NumberOfRegistration = Number;
	}
	void setCircleCount(int count)
	{
		circleCount = count;
	}
	void setPassengersCount(int pass)
	{
		passengersCount = pass;
	}
	void setMaterial(string getMaterial)
	{
		material = getMaterial;
	}

	int getCircleCount()
	{
		void GetCircleCount();
		{
			cout << circleCount;
		}

	}
	void NumberOfRegistration()
	{
		cout << NumberOfRegistration;
	}

	void getMaterial()
	{
		cout << material;
	}

	void getPassengersCount()
	{
		cout << passengersCount;
	}
};

class Car : public Vehicle //класс машины

{

private:

	int mass;

	int km;

public:

	Car(int mass, int km, string NameCompany, string country)

		: Vehicle(NameCompany, country), mass(mass), km(km) {}

	Car(string NumberOfRegistration, int circleCount, int passengersCount, string NameCompany, string country, int mass, int km)

		: Vehicle(NumberOfRegistration, circleCount, passengersCount, NameCompany, country), mass(mass), km(km) {}

	Car(int mass, int km, string NumberOfRegistration, int circleCount, int passengersCount)

		: Vehicle(NumberOfRegistration, circleCount, passengersCount), mass(mass), km(km) {}

	Car();

	void getProbeg(int newProbeg) // metod
	{
		km = newProbeg;
	}
	void getMass(int newMass)
	{
		mass = newMass;
	}
};

class Track : Vehicle //класс масса
{
private:
	int gruzzCount;

	float height;

public:
	Track(int gruzz,float height, string NameCompany, string country)
		: Vehicle(NameCompany, country), gruzzCount(gruzz), height(height) {}

	Track(int gruzz, float height, string NumberOfRegistration, int circleCount, int passengersCount, string NameCompany, string country)

		:Vehicle(NumberOfRegistration, circleCount, passengersCount, NameCompany, country), gruzzCount(gruzz), height(height) {}

	Track(int gruzz, string NumberOfRegistration, int circleCount, int passengersCount)

		: Vehicle(NumberOfRegistration, circleCount, passengersCount), gruzzCount(gruzz) {}

	void setAxis(int gruzz)
	{
		gruzzCount = gruzz;
	}

	void setHeight(float newHeight) //metod
	{
		height = newHeight;
	}

	void  getAxis()
	{
		cout << gruzzCount;
	}

	void getHeight()
	{
		cout << height;
	}
};