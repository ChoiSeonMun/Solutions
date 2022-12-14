#ifdef SOLUTION_02
#pragma once

#include <string>
#include <sstream>

//-------------------------------------------------------------------------------------------------
// MyVector 가 관리하는 오브젝트
//-------------------------------------------------------------------------------------------------
struct MyObject
{
    int _id;
};

//-------------------------------------------------------------------------------------------------
// MyVector 클래스.
//-------------------------------------------------------------------------------------------------
class MyVector
{
    using iterator          = MyObject*;
    using const_iterator    = const MyObject*;

private:
    int         _size       = 0;
    int         _capacity   = 0;
    MyObject*   _container  = nullptr;

private:
    void        reallocate(int newCapacity);
    void        reserve(int newCapacity);

    iterator        begin();
    const_iterator  begin() const;
    iterator        end();
    const_iterator  end() const;

    iterator erase(iterator pos);

    void clear();

public: // 생성자, 복사생성자, 할당연산자, 소멸자를 .cpp 파일에 구현합니다.
    MyVector() = default;

    // Constructor.
    MyVector(int capacity);

    // Copy constructor.
    MyVector(const MyVector& other);
       
    // Assignment operator.
    MyVector& operator=(const MyVector& other);

    // Destructor.
    ~MyVector();

public: // 아래 기능 함수들을 .cpp 파일에 구현합니다.
    // Returns current capacity of this vector.
    int GetCapacity() const;

    // Returns current size of this vector.
    int GetSize() const;

    // Creates a new MyObject instance with the given ID, and appends it to the end of this vector.
    void Add(int id);

    // Returns the first occurrence of MyObject instance with the given ID.
    // Returns nullptr if not found.
    MyObject* FindById(int MyObjectId) const;
    
    // Trims the capacity of this vector to current size.
    void TrimToSize();
   
    // Returns the MyObject instance at the specified index.
    MyObject& operator[](size_t index);

    // Returns string representation of the vector.
    std::string ToString() const;
    
    // Remove all MyObject instances with the given ID in this vector.
    void RemoveAll(int MyObjectId);
    
    // Returns a newly allocated array of MyVector objects,
    // each of whose elements have the same "_id" value of the MyObject struct.
    // The 'numGroups' is an out parameter, and its value should be set to
    // the size of the MyVector array to be returned.
    MyVector* GroupById(int* numGroups);
};

#endif