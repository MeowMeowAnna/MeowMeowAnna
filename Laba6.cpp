#include <iostream> 
#include <string>
#include <clocale>
using namespace std;
////////////////////////////////////////////////////////////////////////
//////////////////////////������ ������� �����//////////////////////////
////////////////////////////////////////////////////////////////////////
class Meow1
{
protected:
	int number;
	int volume;
	char* color;
	bool tempreg;
public:
	Meow1();
	Meow1(int a, int b, char* c, bool d);
	Meow1(const Meow1& a);
	~Meow1();
	Meow1 operator =(const  Meow1 &a);
	void Print() const;
	Meow1 sum(const Meow1& a);
	bool Cmp(const Meow1& a);
	void Copy(const Meow1& a);
};
/////////////////////////////����������� �� ���������/////////////////////////////
Meow1::Meow1()
{
	number = 0;
	volume = 0;
	tempreg = false;
	color = new char[1];
	strcpy(color, "white");
}
/////////////////////////////�����������/////////////////////////////
Meow1::Meow1(int a, int b, char* c, bool d)
{
	number = a;
	volume = b;
	tempreg = d;
	color = new char[strlen(c) + 1];
	strcpy(color, c);
}
/////////////////////////////���������� �����������/////////////////////////////
Meow1::Meow1(const Meow1& a)
{
	if (&a != this)
	{
		number = a.number;
		volume = a.volume;
		color = new char[strlen(a.color) + 1];
		strcpy(color, a.color);
		tempreg = a.tempreg;
	}
}
/////////////////////////////����������/////////////////////////////
Meow1 :: ~Meow1()
{
	delete[] color;
}
/////////////////////////////���������� ������������/////////////////////////////
Meow1 Meow1 :: operator=(const Meow1& a)
{
	if (this == &a)  return *this;
	else
	{
		this->Copy(a);
		return *this;
	}
}
/////////////////////////////������� ������/////////////////////////////
void Meow1::Print() const {
	cout << "�������� �����: " << number << endl;
	cout << "�����: " << volume << endl;
	cout << "��������� ����������� ";
	if (tempreg)
	{
		cout << "�������";
	}
	else
	{
		cout << "�����������";
	}
	cout << endl;
	cout << "����: " << color << endl;
};
/////////////////////////////������� ��������/////////////////////////////
Meow1 Meow1::sum(const Meow1& a) {
	Meow1 f;
	char* tmp = new char[strlen(color) + 1];
	strcpy(tmp, color);
	f.number = number + a.number;
	f.volume = volume + a.volume;
	f.tempreg = false;
	strcat(tmp, "-");
	strcat(tmp, a.color);
	f.color = new char[strlen(tmp) + 1];
	strcpy(f.color, tmp);
	return f;
};
/////////////////////////////������� ���������/////////////////////////////
bool Meow1::Cmp(const Meow1& a) {
	return volume == a.volume && number == a.number && tempreg == a.tempreg && color == a.color;
};
/////////////////////////////������� �����������/////////////////////////////
void Meow1::Copy(const Meow1& a) {
	number = a.number;
	volume = a.volume;
	color = new char[strlen(a.color) + 1];
	strcpy(color, a.color);
	tempreg = a.tempreg;
}

////////////////////////////////////////////////////////////////////////
//////////////////////////������ ������� �����//////////////////////////
////////////////////////////////////////////////////////////////////////
class Meow3
{
protected:
	int temper;
	double length;
public:
	Meow3();
	Meow3(int a, double b);
	Meow3(const Meow3& a);
	Meow3 operator =(const  Meow3 &a);
	void Print() const;
	void Switch();
};
/////////////////////////////����������� �� ���������/////////////////////////////
Meow3::Meow3()
{
	temper = 0;
	length = 15;
}
/////////////////////////////�����������/////////////////////////////
Meow3::Meow3(int a, double b)
{
	temper = a;
	length = b;
}
/////////////////////////////���������� �����������/////////////////////////////
Meow3::Meow3(const Meow3& a)
{
	if (&a != this)
	{
		temper = a.temper;
		length = a.length;
	}
}
/////////////////////////////���������� ������������/////////////////////////////
Meow3 Meow3 :: operator=(const Meow3& a)
{
	temper = a.temper;
	length = a.length;
	return *this;
}
/////////////////////////////������� ������/////////////////////////////
void Meow3::Print() const {
	cout << "�����������: " << temper << endl;
	cout << "����� �������: " << length << endl;
};
/////////////////////////////������� ����������/////////////////////////////
void Meow3::Switch() {
	temper = 0;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////����������� �����///////////////////////////
///////////////////////////////////////////////////////////////////////

class Meow2 : public Meow1, public Meow3
{
protected:
	int size;
public:
	Meow2();
	Meow2(int a, int b, char* c, bool d, int s, int t, double l);
	Meow2(const Meow2& a);
	~Meow2();
	Meow2 operator =(const  Meow2 &a);
	void Print() const;
};
/////////////////////////////����������� �� ���������/////////////////////////////
Meow2::Meow2() :Meow1(), Meow3()
{
	size = 0;
	temper = 0;
	length = 0;
}
/////////////////////////////�����������/////////////////////////////
Meow2::Meow2(int a, int b, char* c, bool d, int s, int t, double l) :Meow1(a, b, c, d), Meow3(t, l)
{
	size = s;
	temper = t;
	length = l;
}
/////////////////////////////���������� �����������/////////////////////////////
Meow2::Meow2(const Meow2& a)
{
	if (&a != this) {
		Meow1::Meow1(a);
		Meow3::Meow3(a);
		size = a.size;
		temper = a.temper;
		length = a.length;
	}
}
/////////////////////////////���������� ������������/////////////////////////////
Meow2 Meow2 :: operator=(const Meow2& a)
{
	number = a.number;
	volume = a.volume;
	color = new char[strlen(a.color) + 1];
	strcpy(color, a.color);
	tempreg = a.tempreg;
	size = a.size;
	temper = a.temper;
	length = a.length;
	return *this;
}
/////////////////////////////�����������/////////////////////////////
Meow2 :: ~Meow2()
{
	Meow1::~Meow1();
}
/////////////////////////////������� ������/////////////////////////////
void Meow2::Print() const
{
	Meow1::Print();
	Meow3::Print();
	cout << "������ ��������������� �������: " << size << endl;
}
int main()
{
	setlocale(LC_ALL, "rus");
	Meow1 mur1, mur2(1, 1, (char*)"yellow", true), mur3(2, 2, (char*)"red", false);
	Meow3 mur7, mur8(40, 40);
	Meow2 mur4, mur5(3, 3, (char*)"black", false, 15, 40, 50), mur6(4, 4, (char*)"white", true, 20, 30, 20);
	Meow2 mur9;
	cout << "���������� � �������������� ���������: " << endl;
	cout << "/////////////////////////////////mur1/////////////////////////////////" << endl;
	mur1.Print();
	cout << "/////////////////////////////////mur2/////////////////////////////////" << endl;
	mur2.Print();
	cout << "/////////////////////////////////mur3/////////////////////////////////" << endl;
	mur3.Print();
	cout << "/////////////////////////////////mur4/////////////////////////////////" << endl;
	mur4.Copy(mur3);
	mur4.Print();
	cout << "/////////////////////////////////mur5/////////////////////////////////" << endl;
	mur5.Print();
	cout << "/////////////////////////////////mur6/////////////////////////////////" << endl;
	Meow1 mur6_1 = mur6.sum(mur5);
	mur6.Copy(mur6_1);
	mur6.Print();
	cout << "/////////////////////////////////mur7/////////////////////////////////" << endl;
	mur7.Print();
	cout << "//////////////////////////mur8 �� ����������//////////////////////////" << endl;
	mur8.Print();
	mur8.Switch();
	cout << "////////////////////////mur8 ����� ����������/////////////////////////" << endl;
	mur8.Print();
	cout << "/////////////////////////////////mur9/////////////////////////////////" << endl;
	mur9.Print();
	cout << endl;
	system("pause");
	return 0;
}
