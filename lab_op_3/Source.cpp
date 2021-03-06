#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class ListNode
{
public:
	string value;
	string key;
	ListNode* next;
	ListNode(string key, string value);
	ListNode();
};

ListNode::ListNode(string key, string value)
{
	this->key = key;
	this->value = value;
	this->next = nullptr;
}

ListNode::ListNode()
{
	this->key = "";
	this->value = "";
	this->next = nullptr;
}

class HashTable
{
private:
	int size = 1;
	ListNode** ptr;
	int size_for_ch = 0;

	int HashFunc(string key)
	{
		int sum = 0;
		int size = key.size() * 2;
		for (int i = 0; i < key.size(); i++)
		{
			sum += key[i];
		}
		int res = sum + size;
		return res % this->size;
	}

	void Check()
	{
		if (this->size_for_ch > (double)0.8 * this->size)
		{
			size_for_ch = 0;
			Resize();
		}
	}

	void Resize()
	{
		this->size = this->size * 2;
		ListNode** oldptr = ptr;
		ptr = new ListNode * [this->size];
		for (int i = 0; i < this->size; i++)
		{
			ptr[i] = nullptr;
		}
		for (int i = 0; i < this->size / 2; i++)
		{
			while (oldptr[i] != nullptr)
			{
				if (oldptr[i]->next == nullptr)
				{
					Insert(oldptr[i]->key, oldptr[i]->value);
					ListNode* temp = oldptr[i];
					oldptr[i] = nullptr;
					delete temp;
				}
				else
				{
					while (oldptr[i]->next != nullptr)
					{
						Insert(oldptr[i]->key, oldptr[i]->value);
						ListNode* temp = oldptr[i];
						oldptr[i] = oldptr[i]->next;
						delete temp;
					}
				}
			}

		}
		delete[] oldptr;
	}
public:

	HashTable()
	{
		ptr = new ListNode * [this->size];
		for (int i = 0; i < this->size; i++)
		{
			ptr[i] = nullptr;
		}
	}

	void Insert(string key, string value)
	{
		int hash = HashFunc(key);
		ListNode* curr_index = this->ptr[hash];
		ListNode* previosly = nullptr;
		while (curr_index != nullptr)
		{
			previosly = curr_index;
			curr_index = curr_index->next;
		}
		if (curr_index == nullptr)
		{
			curr_index = new ListNode(key, value);
			if (previosly == nullptr)
			{
				this->ptr[hash] = curr_index;
				this->size_for_ch++;
			}
			else
			{
				ListNode* temp1 = this->ptr[hash];
				while (temp1->next != nullptr)
				{
					temp1 = temp1->next;
				}
				temp1->next = curr_index;
			}
		}
		Check();
	}

	void Search(string key)
	{
		bool check = false;
		int hash = HashFunc(key);
		ListNode* curr = this->ptr[hash];
		if (curr != nullptr)
		{
			while (curr != nullptr)
			{
				if (curr->key == key)
				{
					cout << curr->key << ": " << curr->value << endl << endl << endl;
					curr = curr->next;
					check = true;
				}
				else
				{
					curr = curr->next;
				}
			}
			if (!check)
			{
				cout << key << " : Not found" << endl;
			}
		}
	}

	~HashTable()
	{
		delete[] ptr;
	}
};


int main()
{

	HashTable table;
	string path = "C:\\C++\\lab_op_3\\File\\dict_processed.txt";
	ifstream FIn(path);
	if (!FIn.is_open()) cout << "Not op";
	else cout << "Open";
	cout << endl;
	char poin = ';';
	string key, value, s, sen;
	string sum;
	while (!FIn.eof())
	{
		getline(FIn, s);
		for (int i = 0; s[i] != poin; i++) { key += s[i]; }
		value = s.erase(0, key.size() + 2);
		table.Insert(key, value);
		key = "";
		value = "";
	}
	cout << "Your sentence: ";
	getline(cin, sen);
	char end = '\0';
	for (int i = 0; i <= sen.size(); i++)
	{
		if (!isspace(sen[i]) && sen[i] != end)
		{
			sum += sen[i];
		}
		else
		{
			for (int j = 0; j < sum.size(); j++)
			{
				if (sum[j] >= 97)
				{
					sum[j] -= 32;
				}
				else continue;
			}
			table.Search(sum);
			sum = "";
		}
	}
	return 0;
}
