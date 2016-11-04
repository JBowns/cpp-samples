# STL

Write a test application that uses basic containers provided by the STL (i.e. vector, deque, list, set, multiset, map, multimap) to store, modify and display some simple data. Use appropriate function members defined on these containers and appropriate iterators to access and manipulate that data.

1. Create a vector of integers, put 6 values into it `<0, -12, 23, -34, 45, -56>`, double these values and display the number of items it contains and its new contents with a space between each value.

2.	Create a deque of integers, fill it in so that it contains the values `<1, 2, 3, 4, 5, 5, 4, 3, 2, 1>`, replace the even values by 0 then display the new contents of that deque, one value per line.

3.	Create a list of integers, copy the content of the vector from question 2.a into it, display its content, remove all negative items it contains, display its new contents and display it again in reverse order.

4.	Create a set of integers, fill it in with the values `<1, -5, 0, 3, -4, 3, 0>`, display its contents (to check the order in which they appear and that there are no duplicates in it), then copy the contents of that set into a vector of integers.

5.	Create a multiset of integers, fill it in with the same values as in question 2d. Display its content WITHOUT showing the duplicates.

6.	Create a multimap, where the key is an integer and the value a string, fill it in with the following pairs

    - `<3, "vector">`
    - `<1, "list">`
    - `<2, "deque">`
    - `<4, "map">`
    - `<2, "set">`

    display its contents in the following format:

    - key: 1	value: list
    - key: 2	value: deque
    - key: 2	value: set
    - key: 3	value: vector
    - key: 4	value: map

    The order of the two values associated with key 2 is undefined so may differ from this.

7. Create a map, where the key is a string (representing a ‘lecturer’) and the value a number (representing a ‘module number’), fill it in with the following pairs:

    - `<"Jacob", 4004>`
    - `<"Monica", 6309>`
    - `<"Monica", 5300>`
    - `<"Jacob", 6309>`
    - `<"Monica", 5305>`

    and display the number of the modules taught by each of the lecturers.
