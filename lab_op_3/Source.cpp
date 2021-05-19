#include<iostream>
#include<fstream>

using namespace std;

class ListNode
{
private:
	int value;
	int key;
	ListNode* next;
public:
	ListNode(int key, int value);
};

ListNode::ListNode(int key, int value)
{
	this->key = key;
	this->value = value;
	this->next = nullptr;
}

int main()
{

}