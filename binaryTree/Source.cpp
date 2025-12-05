#include <iostream>
#include <set>
#include <map>
using namespace std;

class Student
{
	string name;
	int age;
public:
	Student()
	{
		age = 0;
	}
	Student(string n, int a)
	{
		name = n;
		age = a;
	}
	void Print()
	{
		cout << "Name: " << name << " Age: " << age << endl;
	}
	void Init()
	{
		cout << "Enter the name:";
		cin >> name;
		cout << "Enter the age:";
		cin >> age;
	}
	string GetName()
	{
		return name;
	}
	int GetAge()
	{
		return age;
	}
	void SetName(string n)
	{
		name = n;
	}
	void SetAge(int a)
	{
		age = a;
	}
	bool operator<(Student obj) const
	{
		if (age < obj.age)
		{
			return true;
		}
		return false;
	}
	bool operator>(Student obj)
	{
		if (age > obj.age)
		{
			return true;
		}
		return false;
	}
};

ostream& operator << (ostream& os, Student obj)
{
	os << "Name: " << obj.GetName() << "\tAge: " << obj.GetAge() << endl;
	return os;
}

typedef pair<Student, Student> mypair;

int main()
{
	map<Student, Student> group;
	string name;
	int age;
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter the name:";
		cin >> name;
		cout << "Enter the age:";
		cin >> age;
		Student obj(name,age);
		group.insert(mypair(obj,obj));
	}
	cout << endl;
	for (auto ptr = group.begin(); ptr != group.end(); ptr++)
	{
		ptr->second.Print();
	}
	cout << endl;
}