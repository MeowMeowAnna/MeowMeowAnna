#include <iostream> 
#include <string>
#include <clocale>
using namespace std;
///////////////////////////////////////////////////////////////////////
/////////////////////////////ÁÀÇÎÂÛÉ ÊËÀÑÑ/////////////////////////////
///////////////////////////////////////////////////////////////////////
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
/////////////////////////////ÊÎÍÑÒĞÓÊÒÎĞ ÏÎ ÓÌÎË×ÀÍÈŞ/////////////////////////////
Meow1::Meow1()
{
	number = 0;
	volume = 0;
	tempreg = false;
	color = new char[1];
	strcpy(color, "white");
}
/////////////////////////////ÊÎÍÑÒĞÓÊÒÎĞ/////////////////////////////
Meow1::Meow1(int a, int b, char* c, bool d)
{
	number = a;
	volume = b;
	tempreg = d;
	color = new char[strlen(c) + 1];
	strcpy(color, c);
}
/////////////////////////////ÊÎÏÈĞÓŞÙÈÉ ÊÎÍÑÒĞÓÊÒÎĞ/////////////////////////////
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
/////////////////////////////ÄÅÑÒĞÓÊÒÎĞ/////////////////////////////
Meow1 :: ~Meow1()
{
	delete[] color;
}
/////////////////////////////ÏÅĞÅÃĞÓÇÊÀ ÏĞÈÑÂÀÈÂÀÍÈß/////////////////////////////
Meow1 Meow1 :: operator=(const Meow1& a)
{
	if (this == &a)  return *this;
	else
	{
		this->Copy(a);
		return *this;
	}
}
/////////////////////////////ÔÓÍÊÖÈß ÂÛÂÎÄÀ/////////////////////////////
void Meow1::Print() const {
	cout << "Ñåğèéíûé íîìåğ: " << number << endl;
	cout << "Îáú¸ì: " << volume << endl;
	cout << "Ğåãóëÿòîğ òåìïåğàòóğû ";
	if (tempreg)
	{
		cout << "èìååòñÿ";
	}
	else
	{
		cout << "îòñóòñòâóåò";
	}
	cout << endl;
	cout << "Öâåò: " << color << endl;
};
/////////////////////////////ÔÓÍÊÖÈß ÑËÎÆÅÍÈß/////////////////////////////
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
/////////////////////////////ÔÓÍÊÖÈß ÑĞÀÂÍÅÍÈß/////////////////////////////
bool Meow1::Cmp(const Meow1& a) {
	return volume == a.volume && number == a.number && tempreg == a.tempreg && color == a.color;
};
/////////////////////////////ÔÓÍÊÖÈß ÊÎÏÈĞÎÂÀÍÈß/////////////////////////////
void Meow1::Copy(const Meow1& a) {
	number = a.number;
	volume = a.volume;
	color = new char[strlen(a.color) + 1];
	strcpy(color, a.color);
	tempreg = a.tempreg;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////ÏĞÎÈÇÂÎÄÍÛÉ ÊËÀÑÑ///////////////////////////
///////////////////////////////////////////////////////////////////////

class Meow2 : public Meow1
{
protected:
	int size;
public:
	Meow2();
	Meow2(int a, int b, char* c, bool d, int s);
	Meow2(const Meow2& a);
	~Meow2();
	Meow2 operator =(const  Meow2 &a);
	void Print() const;
};
/////////////////////////////ÊÎÍÑÒĞÓÊÒÎĞ ÏÎ ÓÌÎË×ÀÍÈŞ/////////////////////////////
Meow2::Meow2() :Meow1()
{
	size = 0;
}
/////////////////////////////ÊÎÍÑÒĞÓÊÒÎĞ/////////////////////////////
Meow2::Meow2(int a, int b, char* c, bool d, int s) : Meow1(a, b, c, d)
{
	size = s;
}
/////////////////////////////ÊÎÏÈĞÓŞÙÈÉ ÊÎÍÑÒĞÓÊÒÎĞ/////////////////////////////
Meow2::Meow2(const Meow2& a)
{
	if (&a != this) {
		Meow1::Meow1(a);
		size = a.size;
	}
}
/////////////////////////////ÏÅĞÅÃĞÓÇÊÀ ÏĞÈÑÂÀÈÂÀÍÈß/////////////////////////////
Meow2 Meow2 :: operator=(const Meow2& a)
{
	if (this == &a)  return *this;
	else
	{
		this->Copy(a);
		return *this;
	}
}
/////////////////////////////ÄÅÊÑÒĞÓÊÒÎĞ/////////////////////////////
Meow2 :: ~Meow2()
{
	Meow1::~Meow1();
}
/////////////////////////////ÔÓÍÊÖÈß ÂÛÂÎÄÀ/////////////////////////////
void Meow2::Print() const
{
	Meow1::Print();
	cout << "Ğàçìåğ íàãğåâàòåëüíîãî ïğèáîğà: " << size << endl;
}
int main()
{
	setlocale(LC_ALL, "rus");
	Meow1 mur1, mur2(1, 1, (char*)"yellow", true), mur3(2, 2, (char*)"red", false);
	Meow2 mur4, mur5(3, 3, (char*)"black", false, 15), mur6(4, 4, (char*)"white", true, 20);
	cout << "Èíôîğìàöèÿ î íàãğåâàòåëüíûõ ıëåìåíòàõ: " << endl;
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
	Meow1 mur7 = mur6.sum(mur5);
	mur6.Copy(mur7);
	mur6.Print();
	cout << endl;
	system("pause");
	return 0;
}
