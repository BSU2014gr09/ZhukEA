#include <iostream>
#include <string>
#include <fstream>
#include <list>
using namespace std;
class text
{
	struct node
	{
		string str;
		int count;
		node() : count(1){}
		node(string &s) : count(1), str(s){}
	};
public:
	typedef list<node> type;
	type val;
	friend istream &operator>>(istream &in, text &t);
	friend ostream &operator<<(ostream &out, text &t);
};
istream &operator>>(istream &in, text &t)
{
	string tmp;
	while (in >> tmp)
	{
		text::type::iterator pt;
		for (pt = t.val.begin(); pt != t.val.end() && pt->str != tmp; ++pt);
		if (pt != t.val.end())
			pt->count++;
		else
			t.val.push_back(text::node(tmp));
	}
	return in;
}
ostream & operator<<(ostream &out, text &t)
{
	text::type::iterator pt;
	for (pt = t.val.begin(); pt != t.val.end(); ++pt)
		out << pt->count << " " << pt->str << endl;
	return out;
}
int main()
{
	ifstream file("text.txt");
	if (!file.is_open())
	{
		cout << "Error open file";
		cin.get();
		return 1;
	}
	text txt;
	file >> txt;
	cout << txt;
	return 0;
}