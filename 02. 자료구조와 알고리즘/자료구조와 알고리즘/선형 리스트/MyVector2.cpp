#ifdef SOLUTION_02
#include "MyVector2.h"

void MyVector::reallocate(int newCapacity)
{
    MyObject* newContainer = new MyObject[newCapacity];

    for (size_t i = 0; i < _size; ++i)
    {
        newContainer[i] = _container[i];
    }

    delete[] _container;

    _container = newContainer;
    _capacity = newCapacity;
}

void MyVector::reserve(int newCapacity)
{
    if (_capacity >= newCapacity)
    {
        return;
    }

    reallocate(newCapacity);
}

MyVector::iterator MyVector::begin()
{
    return _container;
}

MyVector::const_iterator MyVector::begin() const
{
    return _container;
}

MyVector::iterator MyVector::end()
{
    return _container + _size;
}

MyVector::const_iterator MyVector::end() const
{
    return _container + _size;
}

MyVector::iterator MyVector::erase(iterator pos)
{
    if (_size == 0)
    {
        return end();
    }

    iterator last = end() - 1;
    for (iterator iter = pos; iter != last; ++iter)
    {
        *iter = *(iter + 1);
    }

    --_size;

    return pos;
}

void MyVector::clear()
{
    delete[] _container;
    _container = nullptr;
    _size = 0;
    _capacity = 0;
}

MyVector::MyVector(int capacity)
    : _container(new MyObject[capacity]), _size(0), _capacity(capacity)
{

}

MyVector::MyVector(const MyVector& other)
    : _container(new MyObject[other._capacity]), _size(other._size), _capacity(other._capacity)
{
    for (size_t i = 0; i < _size; ++i)
    {
        _container[i] = other._container[i];
    }
}

MyVector& MyVector::operator=(const MyVector& other)
{
    if (this == &other)
    {
        return *this;
    }

    MyVector temp(other);
    std::swap(_container, temp._container);
    std::swap(_size, temp._size);
    std::swap(_capacity, temp._capacity);

    return *this;
}

MyVector::~MyVector()
{
    clear();
}

int MyVector::GetCapacity() const
{
    return _capacity;
}

int MyVector::GetSize() const
{
    return _size;
}

void MyVector::Add(int id)
{
    if (_size == _capacity)
    {
        reserve((_capacity == 0) ? 1 : _capacity * 2);
    }

    _container[_size]._id = id;
    ++_size;
}

MyObject* MyVector::FindById(int MyObjectId) const
{
    for (size_t i = 0; i < _size; ++i)
    {
        if (_container[i]._id == MyObjectId)
        {
            return &_container[i];
        }
    }

    return nullptr;
}

void MyVector::TrimToSize()
{
    if (_size == _capacity)
    {
        return;
    }

    reallocate(_size);
}

MyObject& MyVector::operator[](size_t index)
{
    return _container[index];
}

std::string MyVector::ToString() const
{
    // { 1, 2, 3, 4, 5 }
    // [1,2,3,4,5]
    std::stringstream ss;

    ss << "[";
    for (size_t i = 0; i < _size; ++i)
    {
        ss << _container[i]._id << ",";
    }
    ss << "]";

    return ss.str();
}

void MyVector::RemoveAll(int MyObjectId)
{
    iterator iter = begin();

    while (iter != end())
    {
        if (iter->_id == MyObjectId)
        {
            iter = erase(iter);
        }
        else
        {
            ++iter;
        }
    }
}

MyVector* MyVector::GroupById(int* numGroups)
{
    MyVector ids;
    for (size_t i = 0; i < _size; ++i)
    {
        if (nullptr == ids.FindById(_container[i]._id))
        {
            ids.Add(_container[i]._id);
        }
    }

    int count = ids.GetSize();
    MyVector* result = new MyVector[count];

    for (size_t i = 0; i < _size; ++i)
    {
        size_t index = ids.FindById(_container[i]._id) - ids.begin();
        result[index].Add(_container[i]._id);
    }

    *numGroups = count;
    return result;
}
#endif