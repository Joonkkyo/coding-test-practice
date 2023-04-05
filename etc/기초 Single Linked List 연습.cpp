#define MAX_NODE 10000

using namespace std;
struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	head = nullptr;
	nodeCnt = 0;
}

void addNode2Head(int data)
{
	Node* newNode = getNode(data);
	newNode->next = head;
	head = newNode;
}

void addNode2Tail(int data)
{
	Node* newNode = getNode(data);
	Node* lastNode = head;

	if (head == nullptr)
	{
		head = newNode;
		return;
	}

	while (lastNode->next != nullptr)
		lastNode = lastNode->next;

	lastNode->next = newNode;
}

void addNode2Num(int data, int num)
{
	Node* newNode = getNode(data);

	if (num == 1)
	{
		newNode->next = head;
		head = newNode;
		return;
	}

	Node* preNode = head;
	for (int i = 1; i < num - 1 && preNode->next != nullptr; i++)
		preNode = preNode->next;

	if (preNode->next == nullptr)
		preNode->next = newNode;

	else
	{
		newNode->next = preNode->next;
		preNode->next = newNode;
	}
}

void removeNode(int data)
{
	if (head == nullptr)
		return;
	
	if (head->data == data)
	{
		head = head->next;
		return;
	}

	Node* preNode = head;

	while (preNode->next != nullptr && preNode->next->data != data)
		preNode = preNode->next;

	if (preNode->next == nullptr)
		return;

	Node* delNode = preNode->next;
	preNode->next = delNode->next;
}

int getList(int output[MAX_NODE])
{
	int idx = 0;
	Node* cur = head;
	while (cur != nullptr)
	{
		output[idx++] = cur->data;
		cur = cur->next;
	}

	return idx;
}
