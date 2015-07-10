/*
 Rob Fitzgerald
 template darray class
*/

/*
 darray class
 
 dynamic array ADT class, mostly implemented.

 edited from CSCI 2312 in-class example.

 ****************************************************************************
 darray<T>()

 post-condition: instantiate a darray, capacity of 1, used = 0;

 ****************************************************************************
 darray<T>(const darray& d)

 post-condition: copy of parameter darray has been used to instantiate this
                    instance of a darray

 ****************************************************************************
 explicit darray<T>(unsigned newCap)

 post-condition: new darray insantiated with capacity of unsigned parameter.

 ****************************************************************************
 ~darray<T>()

 post-condition: freestore memory associated with this instance of darray has
                    been deleted before finishing with object destruction.

 ****************************************************************************
 unsigned size() const { return used; }
 
 post-condition: returns the current value of used (size of used portion of
                    darray)

 ****************************************************************************
 unsigned capacity() const { return cap; }

 post-condition: returns the current value of cap (capacity of darray)

 ****************************************************************************
 const T& operator [ ] (unsigned) const;
 T& operator [ ] (unsigned);

 pre-condition:  parameter (subscript) is a valid element in the array, 
            otherwise assert will end the program.
 post-condition: address of data at requested array element is returned

 ****************************************************************************
 const T* find(const T&) const;
 T* find(const T&);
 
 post-condition: returns a pointer to the first match for the parameter found
                    in the array.  If not found, returns a null pointer.

 ****************************************************************************
 void pop_back();

 post-condition: Reduces array capacity by one and disgards the final element,
                    unless capacity is zero, in which case nothing happens.

 ****************************************************************************
 void push_back(const T&);

 post-condition: adds the parameter to the array, increasing used by 1.  If
                    the capacity needs to be extended, it will resize by 1.

 ****************************************************************************
 void resize(unsigned);

 post-condition: darray has been resized, truncated if resized smaller than
                    the amount used.

 ****************************************************************************
 darray& operator = (const darray&);

 post-condition: copies darray in parameter (or right hand side of assignment
                    operation) into the calling (left hand side) object.

 ****************************************************************************
 void operator += (const darray&);
 
 post-condition: appends the right hand side darray to the end (after-used 
                    section) of the left hand side darray.  Will extend capacity
                    if needed.
 */


#ifndef _darray
#define _darray

#include <iostream>
#include <exception>

template <typename T>
class darray
{
public:
    // Constructors
    
    darray<T>() { arr = new T[1]; used = 0; cap = 1; }
    darray<T>(const darray& d);
    explicit darray<T>(unsigned newCap)
        { arr = new T[newCap]; used = 0; cap = newCap; }
    ~darray<T>() { delete [] arr; }
    
    // Constant members
    unsigned size() const { return used; }
    unsigned capacity() const { return cap; }
    const T* find(const T&) const;
    T front() const;
    T back() const;
    
    // Modification members
    T& back();
    void pop_back();
    void push_back(const T&);
    T& front();
    void pop_front();
    void push_front(const T&);  // added 2015/07/08 for queue FIFO ops
    T* find(const T&);
    void resize(unsigned);
    void moveToBack(int);
    void moveToFront(int);
    
    // Operators
    const T& operator [ ] (unsigned) const;
    T& operator [ ] (unsigned);
    darray& operator = (const darray&);
    void operator += (const darray&);
    
private:
    T* arr;
    unsigned used, cap;

    class badBracket
    {
    public:
        badBracket(unsigned index)
        {
            std::cout << "\n**out of bounds, target = " << index << "**" << std::endl;
        }
    };

};


#include "darray.tem"
#endif





