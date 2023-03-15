#include <iostream>

class ListNode
{
	friend class List;
	private:
		double  _data;
		ListNode *_next;
        public:
		ListNode(const double);
};

class List	
{
        public:
                List();
                ~List();

                void    insertAtFront(const double d);
                void    insertAtBack(const double);
                bool    RemoveFromFront(double &);
                bool    RemoveFromBack(double &);
                bool    isEmpty() const;
                void    print() const;
        private:
                ListNode* getNewNode(const double) const;
        private:
                ListNode* _firstPtr;
                ListNode* _lastPtr;
};

ListNode::ListNode(const double data)
{
        _data = data;
        _next = nullptr;
}

List::List()
{
	_firstPtr = nullptr;
	_lastPtr = nullptr;
}

ListNode *List::getNewNode(const double d) const
{
	ListNode *newNode = new ListNode(d);
	return (newNode);
}

bool	List::isEmpty() const
{
	return (_firstPtr == nullptr);
}

void	List::insertAtFront(const double d)
{
	ListNode *cur;
	ListNode *next;
	ListNode *nxt;

	cur = getNewNode(d);
	if (isEmpty())
	{
		_firstPtr = cur;
		_lastPtr = cur;
	}
	else
	{
		next = _firstPtr;
		_firstPtr = cur;
		cur->_next = next;
	}
	std::cout << d << " containing node is inserted at front" << std::endl;
}

void	List::insertAtBack(const double d)
{
	ListNode *cur;
	ListNode *next;

	cur = getNewNode(d);
	if (isEmpty())
	{
		_firstPtr = cur;
		_lastPtr = cur;
	}
	else
	{
		_lastPtr->_next = cur;
		_lastPtr = cur;
	}
	std::cout << d << " containing node is inserted at back" << std::endl;
}

bool	List::RemoveFromFront(double &d)//sending with reference for avoiding redundant copy of d
{
	ListNode *tmp;

	if (!isEmpty())
	{
		tmp = _firstPtr->_next;
		delete (_firstPtr);
		_firstPtr = tmp;
		std::cout << d << " containing node is deleted from front" << std::endl;
		return (1);
	}
	else
	{
		std::cout << d << " containing node is not deleted from front" << std::endl;
		return (0);
	}
}

bool	List::RemoveFromBack(double &d)
{
	ListNode *tmp;

	tmp = _firstPtr;
	if (isEmpty())
	{
		std::cout << " list is empty" << std::endl;
		return (0);
	}
	while (tmp->_next && tmp->_next->_next)
		tmp = tmp->_next;
	delete tmp->_next;
	tmp->_next = nullptr;
	_lastPtr = tmp;
	std::cout << d << " containing node is deleted from back" << std::endl;
	return (1);
}

void	List::print() const
{
	ListNode *tmp;

	tmp = _firstPtr;
	while (tmp)
	{
		std::cout << "data is " << tmp->_data << std::endl;
		tmp = tmp->_next;
	}
}

List::~List()
{
	ListNode *tmp;

	tmp = _firstPtr;
	while (tmp)
	{
		tmp = _firstPtr->_next;
		delete _firstPtr;
		_firstPtr = tmp;
	}
}

void	instructions()
{
	std::cout << "Enter one of the following\n"
		<< "1 to insert at beginning of list\n"
		<< "2 to insert at end of the list\n"
		<< "3 to delete from beginning of list\n"
		<< "4 to delete from end of list\n"
		<< "5 to end list processing\n";
}

int main()
{
	int	 x = 1;
	double a = 9;
	double b = 99;
	int	 data;
	List	L;

	instructions();
//	std::cin >> x;
	while (x != 5)
	{
		std::cin >> x;
		if (x == 1)
		{
			std::cout << "Enter double data: ";
			std::cin >> data;
			L.insertAtFront(data);
		}
		else if (x == 2)
		{
			std::cout << "enter double data: ";
			std::cin >> data;
			L.insertAtBack(data);
		}
		else if (x == 3)
		{
			L.RemoveFromFront(a);
		}
		else if (x == 4)
		{
			L.RemoveFromBack(a);
		}
	}
	//L.insertAtFront(a);
//	L.insertAtFront(b);
//	L.insertAtBack(b);
//	L.RemoveFromBack(b);
//	L.RemoveFromBack(b);
	L.print();
	L.~List();
}
