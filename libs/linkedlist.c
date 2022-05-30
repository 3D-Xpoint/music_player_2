#include <linkedlist.h>
#include <string.h>
static Node* _head = NULL;

static Node* _tail = NULL;

static Node* _cur_node = NULL;

static bool isInit = false;
static size_t nSize = 0;

void init()
{
	isInit = true;
	_head = (Node *)malloc(sizeof(Node));
	_tail = (Node *)malloc(sizeof(Node));
	_cur_node = _head;
	
	_head->next = _tail;
	_tail->prev = _head;
}

bool empty()
{
	return size() == 0;
}

size_t size()
{
	return nSize;
}

void print()
{
	printf("LinkedList [ ");
	Node* now = first_node();
	for(int i = 0; i<size();i++)
	{
		printf(now->data);
		printf(" ");
		now = now->next;
	}
	printf("]\n");
}

void print_file(FILE* stream)
{	
	Node* now = last_node();
	char s1[10];
	sprintf(s1,"%d\n",size());
	fputs(s1,stream);
	for(int i = 0; i<size();i++)
	{
		fputs(now->data,stream);
		fputs("\n",stream);
		now = now->prev;
	}
}

void clear()
{
	Node* now = first_node();
	for(int i = 0; i<size();i++)
	{	
		now = now->next;
		delete_node(now->prev);
	}
}

Node* append_left(size_t n,char new_data[n])
{
	Node* newn = (Node *)malloc(sizeof(Node));
	newn->data = new_data;
	insert_after(_head,newn);
}


Node* insert_after(Node* cur_node,Node* new_node)
{	
	if(cur_node == _tail)
		return new_node;
	
	nSize++;
	new_node->next = cur_node->next;
	new_node->prev = cur_node;
	cur_node->next = new_node;
	new_node->next->prev = new_node;

	return new_node;
}

Node* append(size_t n,char new_data[n])
{
	if(!isInit)
		init();
	Node* newn = (Node *)malloc(sizeof(Node));
	newn->data=new_data;
	insert_after(_tail->prev,newn);
}

Node* delete_node(Node* cur_node)
{
	if(cur_node == _head || cur_node == _tail)
		return _tail;
	
	Node* result = cur_node->next;
	cur_node->prev->next = cur_node->next;
	cur_node->next->prev = cur_node->prev;
	free(cur_node);
	nSize--;
	return result;
}

Node* delete(char* data)
{
	Node* now = first_node();
	for(int i = 0;i<size();i++)
	{
		if(strcmp(now->data,data))
			return delete_node(now);
		now = now->next;
	}
	return _tail;
}

Node* get_node(size_t index)
{
	if(index == -1)
	return _cur_node;

	if(index >= size())
		return _tail;
	Node* now = first_node();	
	for(int i = 0;i<index;i++)
	{
		now = now->next;
	}
	return now;
}

Node* first_node()
{
	if(size() > 0)
		return _head->next;
	else
		return _tail;
}

Node* last_node()
{
	if(size() > 0)
		return _tail->prev;
	else
		return _tail;

}

Node* next()
{
	Node* result = _cur_node->next;
	if(_cur_node == _tail)
		result = _tail->prev;
	_cur_node = result;
	return result;
}

Node* prev()
{
	Node* result = _cur_node->prev;
	if(_cur_node == _head)
		result = _head->prev;
	_cur_node = result;
	return result;
} 
