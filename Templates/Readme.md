# Templates

1. Write a class template 'triple' that accepts three types, and allows objects of those types to be stored inside. Demonstrate the use of your template class by enabling three values to be returned from a function (i.e. one object is returned, but that object contains three data members).

2. Develop a `manager' class that will manage dynamically allocated objects.

    Manager classes are typically arrays that store pointers to instances of objects created using 'new' - the pointers to these are stored in a vector.

    Manager classes provide member functions to create objects dynamically, delete them, and delete all of the objects upon destruction of the manager — thus preventing memory leaks. Manager classes are often templatised to facilitate storage of different object types.

    Implement your manager class using templates. Provide the following functionality:

    * A mechanism to store pointers to dynamically created objects.
    * Access to the items stored in the manager (through an index/subscript mechanism). Create access methods that return both the pointer and a reference to the item concerned. Consider both const and non-const situations.
    * Deletion of individual objects.
    * Deletion of all objects.
    * Create copies of existing objects (not just copying the pointers, but deep copying the contents of the objects).
