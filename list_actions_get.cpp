#include <iostream>

class ListNode
{
	private:
		double  _data;
		ListNode *_next;
        public:
		ListNode(const double);
		double getdata() const
		{
			return (_data);
		}
		ListNode *getnode()
		{
			return (_next);
		}
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
		nxt = cur->getnode();
		nxt = next;
	//	next = _firstPtr;
	//	_firstPtr = cur;
	//	cur->_next = next;
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
		next = _lastPtr->getnode();
		next = cur;
		_lastPtr = cur;
	}
	std::cout << d << " containing node is inserted at back" << std::endl;
}

bool	List::RemoveFromFront(double &d)//sending with reference for avoiding redundant copy of d
{
	ListNode *tmp;

	if (!isEmpty())
	{
		tmp = _firstPtr->getnode();
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
	ListNode *tmpnxt;

	tmp = _firstPtr;
	while (tmp->getnode()->getnode())
		tmp = tmp->getnode();
	if (tmp)
	{
		tmpnxt = tmp->getnode();
		delete tmp->getnode();
		tmpnxt = nullptr;
		_lastPtr = tmp;
		std::cout << d << " containing node is deleted from back" << std::endl;
		return (1);
	}
	else
	{
		std::cout << d << " containing node is not deleted from back" << std::endl;
		return (0);
	}
}

void	List::print() const
{
	ListNode *tmp;

	tmp = _firstPtr;
	while (tmp)
	{
		printf("one timeeeeeeeeeeeeee\n");
		std::cout << "data is " << tmp->getdata() << std::endl;
		tmp = tmp->getnode();
	}
}

List::~List()
{
	ListNode *tmp;

	tmp = _firstPtr;
	while (tmp)
	{
		tmp = _firstPtr->getnode();
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
	int	 x;
	double a = 9;
	double b = 99;
	int	 data;
	List	L;

	//instructions();
//	std::cin >> x;
	/*
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
			L.insertatback(data);
		}
		else if (x == 3)
		{
			L.removefromfront(a);
		}
		else if (x == 4)
		{
			L.removefromback(a);
		}
	}
	*/
	L.insertAtFront(a);
	L.insertAtFront(b);
	L.insertAtFront(a);
//	L.insertAtBack(b);
	L.print();
	L.~List();
}
