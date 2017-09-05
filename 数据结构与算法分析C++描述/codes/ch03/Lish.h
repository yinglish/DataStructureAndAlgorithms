template <typename Object>
class List
{
private:
    struct Node 
    {

    };
public:
    class const_iterator
    {

    };
    
    class iterator : public const_iterator
    {

    };

public:
    List()
    {

    }
    List(const List &rhs)
    {

    }
    ~List()
    {

    }
    const List & operator= (const List & rhs)
    {

    }

    iterator begin()
    {
        return iterator(head->next);
    }
    const_iterator begin() const
    {
        return const_iterator(head->next);
    }
    iterator end()
    {
        return iterator(tail);
    }
    const_iterator end() const 
    {
        return const_iterator(tail);
    }

    int size() const
    {
        return theSize;
    }
    bool empty() const
    {
        return size() == 0;
    }

    void clear()
    {
        while (!empty())
        {
            pop_front();
        }
    }

    Object & front()
    {
        return *begin();
    }
    const Object & front() const
    {
        return *begin();
    }
    Object & back()
    {
        return *--end();
    }
    cosnt Object & back() const
    {
        return *--end();
    }
    void push_front(const Object &x)
    {
        insert(begin(), x);
    }
}