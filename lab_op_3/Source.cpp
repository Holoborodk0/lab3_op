#include<iostream>
#include<fstream>
#include<string>;

using namespace std;

class ListNode
{
private:
	string value;
	string key;
public:
	ListNode* next;
	ListNode(string key, string value);
};

ListNode::ListNode(string key, string value)
{
	this->key = key;
	this->value = value;
	this->next = nullptr;
}

class HashTable
{
private:
	int size = 100;
	ListNode** ptr;

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
public:

	HashTable()
	{
		ptr = new ListNode * [size];
		for (int i = 0; i < size; i++)
		{
			ptr[i] = nullptr;
		}
	}

	//void Check()
	//{
	//	int count;
	//	for (int i = 0; i < this->size; i++)
	//	{
	//		if (ptr[i] != nullptr) count++;
	//		if (count > (int)0.8 * this->size) Resize();
	//		else continue;
	//	}
	//	count = 0;
	//}

	//void Resize()
	//{
	//	this->size = this->size*2;
	//	ListNode** Newptr;
	//	Newptr = new ListNode * [this->size];
	//	for (int i = 0; i < size; i++)
	//	{
	//		Newptr[i] = nullptr;
	//	}

	//}

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
			int b;
		}

	}
};


int main()
{
	HashTable table;
	table.Insert("A", "ff");
	table.Insert("Bd", "fxa");
	table.Insert("A", "sgrgc");
	table.Insert("A", "segkgkx");
	table.Insert("A", "segffdffgfgrfgekgkx");
}