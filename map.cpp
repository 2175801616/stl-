#include<iostream>
#include<map>
using namespace std;

class Student {
public:
	int get_id() {
		return id;
	}
	string get_name()
	{
		return name;
	}
	void change_id(int i)
	{
		id = i;
	}
	Student() { name = "NULL"; }
	Student(int i,string n)
	{
		id = i;
		name = n;
	}

private:
	int id;
	string name;
};

std::ostream& operator<<(std::ostream& out, map<int, string>& src)
{
	auto iter= src.begin();
	for (; iter != src.end(); iter++)
	{
		pair<int, string> data = *iter;
		out << data.first << " " << data.second << endl;
	}
	out << endl;
	return out;
}

std::ostream& operator<<(std::ostream& out, map<int, Student>& src)
{
	auto iter = src.begin();
	for (; iter != src.end(); iter++)
	{
		pair<int, Student> data = *iter;
		out << data.second.get_id() << " " << data.second.get_name() << endl;
	}
	out << endl;
	return out;
}

void map_Student()
{
	map<int, string> mapStudent;
	mapStudent.insert(pair<int,string>(3, "С��"));
	mapStudent.insert(map<int, string>::value_type(1, "С��"));
	mapStudent[2] = "С��";

	int key = 5;
	string name = "С��";
	pair<int,string> pairST(key, name);
	mapStudent.insert(pairST);

	key = 6;
	name = "С��";
	map<int, string>::value_type valueTP(key, name);
	mapStudent.insert(valueTP);
	cout << mapStudent;

	Student S(1, "С��");
	map<int, Student> mapStu;
	mapStu[1] = S;
	mapStu.insert(pair<int, Student>(2, Student(2, "С��")));
	mapStu.insert(map<int, Student>::value_type(3, Student(3, "С��")));

	cout << mapStu;

}

void map_insert()
{
	map<int, string> mapStudent;
	mapStudent.insert(pair<int, string>(3, "С��"));
	mapStudent.insert(map<int, string>::value_type(1, "С��"));
	mapStudent[2] = "С��";
	cout << mapStudent;
	mapStudent.insert(pair<int, string>(1, "С��"));
	cout << mapStudent;
	mapStudent.insert(map<int, string>::value_type(1, "С��"));
	cout << mapStudent;
	mapStudent[1] = "С��";
	cout << mapStudent;
}

void map_auto_create()
{
	map<int, string> mapStudent;
	mapStudent.insert(pair<int, string>(3, "С��"));
	string name = mapStudent[1];
	cout <<"auto:"<< name<<endl;
}

template<typename T1,typename T2>
void map_find(map<T1,T2> &src)
{
	map<int, string> mapStudent;
	mapStudent.insert(pair<int, string>(3, "С��"));
	mapStudent.insert(map<int, string>::value_type(1, "С��"));
	mapStudent[2] = "С��";

	string name;
	name = mapStudent[1];
	cout << "id 1 name: " << name << endl;

	auto iter = mapStudent.find(2);
	if (iter != mapStudent.end()) {
		name = (*iter).second;
		cout << "id 2 name: " << name << endl;
	}
	else cout << "can not find"<<endl;

	name = mapStudent.at(3);
	cout << "id 3 name: " << name << endl;
}
int main()
{
	map_Student();

	Student S1(1, "xiao");
	Student S2 = S1;
	cout << S1.get_id() << " " << S2.get_id()<<endl;
	S1.change_id(2);
	cout << S1.get_id() << " " << S2.get_id() << endl;

	map_insert();

	map_auto_create();

	map<int, string> mapStudent;
	map_find(mapStudent);
	return 0;
}