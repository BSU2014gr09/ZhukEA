struct node
{
	char * word;
	int amt;
	node * next;
	node() : word(nullptr), amt(0), next(nullptr) {}
	~node()
	{
		delete[] word;
	}
};

struct List
{
	node * begin;
	List() : begin(nullptr) {}
	node * add(char *);
	void print(node *);
	~List()
	{
		while (begin)
		{
			node *temp = begin->next;
			delete begin;
			begin = temp;
		}
	}
};

