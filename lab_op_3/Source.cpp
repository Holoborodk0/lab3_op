#include<iostream>
#include<fstream>

using namespace std;

struct ListNode
{
	int value;
	int key;
	ListNode* next = nullptr;
};

class HashTable
{
private:
	int size = 100;
	ListNode** ptr;
public:

	HashTable()//конструктор
	{
		ptr = new ListNode * [size];
		for (int i = 0; i < size; i++)
		{
			ptr[i] = nullptr;
		}
	}

	void Check()
	{
		int count;
		for (int i = 0; i < this->size; i++)
		{
			if (ptr[i] != nullptr) count++;
			if (count > (int)0.8 * this->size) Resize();
			else continue;
		}
		count = 0;
	}

	void Resize()
	{
		this->size = this->size * 2;
		ListNode** Newptr;
		Newptr = new ListNode * [this->size];
		for (int i = 0; i < size; i++)
		{
			Newptr[i] = nullptr;
		}

	}

	int HashFunc(string key)
	{
		int sum = 0;
		int size = key.size() * 2;
		for (int i = 0; i < key.size(); i++)
		{
			key[i] += sum;
		}
		int res = sum + size;
		return res % this->size;
	}

	void Insert(string key, string value)
	{
		int hash = HashFunc(key);
		ListNode* curr_index = this->ptr[hash];
		ListNode* prev = nullptr;
		while (curr_index != nullptr)
		{
			prev = curr_index;
			curr_index = curr_index->next;
		}

	}
};


int main()
{

}