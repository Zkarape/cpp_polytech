#include <iostream>

class ListNode
{
	friend class List;
	private:
		double		_data;
		ListNode	*_next;
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
		bool	insertAtIndex(size_t idx, const double value);
		bool	removeAtIndex(size_t idx, const double value);
		size_t	getElementCount() const;
                bool    isEmpty() const;
                void    print() const;
        private:
                ListNode* getNewNode(const double) const;
        private:
                ListNode* _firstPtr;
                ListNode* _lastPtr;
		size_t	  _count;
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
	_count = 0;
}

size_t	List::getElementCount() const
{
	return (_count);
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

bool	List::insertAtIndex(size_t idx, const double value)
{
	ListNode *tmp;
	ListNode *next;
	ListNode *newone;

	newone = getNewNode(value);
	tmp = _firstPtr;
	if (isEmpty())
	{
		std::cout << " list is empty" << std::endl;
		return (0);
	}
	if (idx < 1 || idx > _count + 1)
	{
		std::cout << "Invalid index" << std::endl;
		return (0);
	}
	while (--idx >= 1)//until idx - 1 th node
		tmp = tmp->_next;
	next = tmp->_next;
	tmp->_next = newone;
	newone->_next = next;
	_count++;
	std::cout << value << " containing node is inserted at idx" << std::endl;
	return (1);
}

//bool	List::removeAtIndex(size_t idx, const double value)
//{
//	
//}

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
	_count++;
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
	_count++;
	std::cout << d << " containing node is inserted at back" << std::endl;
}

bool	List::RemoveFromFront(double &d)//sending with reference for avoiding redundant copy of d
{
	ListNode *tmp;

	if (!isEmpty())
	{
		d = _firstPtr->_data;
		tmp = _firstPtr->_next;
		delete (_firstPtr);
		_firstPtr = tmp;
		_count--;
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
	d = tmp->_data;
	delete tmp->_next;
	tmp->_next = nullptr;
	_lastPtr = tmp;
	_count--;
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
		<< "5 to insert at index idx\n"
		<< "6 to report the number of elemens\n"
		<< "7 to end list processing\n";

}

int main()
{
	int	x = 2;
	int	idx = 0;
	double	a = 9;
	double	b = 99;
	double	aa = 88;
	double	bb = 77;
	int	data;
	List	L;

	
	instructions();
	while (x != 7)
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
		else if (x == 5)
		{	
			std::cout << "enter index: ";
			std::cin >> idx;
			std::cout << "enter double data: ";
			std::cin >> data;
			L.insertAtIndex(idx, data);
		}
		else if (x == 6)
		{
			std::cout << "_count is: " << L.getElementCount();
		}
	}
	L.print();
	L.~List();
}
