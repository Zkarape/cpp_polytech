#include <iostream>

class ListNode
{
        public:
                ListNode(double data);
        private:
                double  _data;
                ListNode *_next;
}

ListNode(double data)
{
        _data = data;
        _next = nullptr;
}

class List
{
        public:
                List();
                ~List();

                void    LstAddFront(const double d);
                void    LstAddBack(const double);
                bool    RemoveFromFront(double &);
                bool    RemoveFromBack(double &);

}
