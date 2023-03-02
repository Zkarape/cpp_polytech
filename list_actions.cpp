#include <iostream>

class ListNode
{
        public:
		ListNode(const double);
	private:
		double  _data;
		ListNode *_next;
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

//ListNode::ListNode(const double data)
//: _data = data,
//  _next = nullptr

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
	if (!_firstPtr)
		return (1);
	return (0);
}

void	List::insertAtFront(const double d)
{
	ListNode *cur;

	cur = getNewNode(d);
	if (!isEmpty())
	{
		_firstPtr = cur;
		_lastPtr = cur;
	//	cur->_next = nullptr;
	}
	else
		cur->_next = _firstPtr;
	std::cout << d << " containing node is inserted at front" << std::endl;
}

void	List::insertAtBack(const double d)
{
	ListNode *cur;

	cur = getNewNode(d);
	if (_lastPtr == nullptr)
		_lastPtr = cur;
	else
		_lastPtr->_next = cur;
	cur->_next = nullptr;
	std::cout << d << " containing node is inserted at back" << std::endl;
}

bool	List::RemoveFromFront(double &d)//sending with reference for avoiding redundant copy of d
{
	if (!isEmpty())
	{
		_firstPtr->_next = nullptr;
		delete (_firstPtr);
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
	while (tmp->_next->_next)
		tmp = tmp->_next;
	if (tmp)
	{
		delete tmp->_next;
		tmp->_next = nullptr;
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

void	List::print()
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

//int main()
//{
//	
//}
