# Table of Contents
* [Templates](#templates)
    - [Programming with Templates](#pwt)
- [Function Templates](#functemp)
- [Class Templates](#classtemp)
- [STL vector class](#vector)

# Templates <a name="templates"></a>
* main principles of object-oriented design:
    - data abstraction
        - separation of abstract *properties* and concrete *implementation*
    - code reuse
        - reuse existing code (libraries)
        - make classes reusable
- important mechanisms for code reuse
    - use existing libraries
    - generic programming (templates)

#### Programming with Templates <a name="pwt"></a>
Goal
* code once, reuse many times
* write code that works with any object

Approach
* use data type as **parameter** to template
    - templates can be functions **OR** classes
- template code can be used with any data type

# Function Templates <a name="functemp"></a>
* goal: create function that works with any data type
* any function can be *templated* (global or member function)
* if member function templated, its class must be too
* write function using *variable* in place of data type
* call function using any data type
- compiler creates **specialization** of template for each type you use
    - real function placed in your code with data type hard-coded
    - new function compiled with rest of code
- templated functions can be overloaded
    - same name, different parameters
    - **this is not specialization**
    - non-templated function chosen over templated one

# Class Templates <a name="classtemp"></a>
* goal: create class that works with any data type
    - known as a ***parameterized*** type
- any member function can be templated
- often used for collection classes
- write class using *variable* instead of data type
- create instance of the class using any data type
- compiler creates **specialization** of template for each type you use
    - real class placed in your code with data type hard-coded
    - all members of the class that are templated are specialization for that type
    - new class compiled with rest of code
- Special cases
    - non-type parameter
    - default types
- each specialization gets own copy of static members

# STL **vector** class <a name="vector"></a>
* problem with C-style arrays:
    - no bounds checking
    - don't support many operators (eg. assignment, relational, etc.)
* one alternative: **vector** class template
* can store any data type
* supports many operators
* provides useful member functions
    - **size, at, etc.**
