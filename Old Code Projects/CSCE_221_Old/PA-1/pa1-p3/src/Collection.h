/**
 * There is no Collection.cpp for this assignment.
 * Move all the functions from Collection.cpp to this file
 * Covert the Collection class to a templated form.
 *      Stress_ball should be replaced with typename "Obj".
 *      Stress_ball_colors
 *      Stress_ball_sizes should be replaced with typename "F2"
 */

#ifndef COLLECTION_H
#define COLLECTION_H
#include <exception>
#include <string>
#include <iostream>

using std::cout;
using std::endl;

enum class Sort_choice
{
    bubble_sort = 0,
    insertion_sort = 1,
    selection_sort = 2
};

struct EmptyCollectionException : public std::exception
{
	const char * what () const noexcept
    {
        return "Collection is Empty!";
    }
};


// Begin class declaration ------------------------------------------------------------------------------


template <typename Obj, typename F1, typename F2>
class Collection
{
    private: 
        Obj *array;
        int size;
        int capacity;
        void resize();

    public:
        Collection();
        Collection(const int cap);
        Collection(const Collection &c);
        Collection &operator=(const Collection &c);
        ~Collection();
        Collection(Collection &&c);
        Collection &operator=(Collection &&c);
        void insert_item(const Obj &sb);
        bool contains(const Obj &sb) const;
        Obj remove_any_item();
        void remove_this_item(const Obj &sb);
        void make_empty();
        bool is_empty() const;
        int total_items() const;
        int total_items(const F2 s) const;
        int total_items(const F1 c) const;
        void print_items() const;
        Obj &operator[](const int i);
        const Obj &operator[](const int i) const;

};


template <typename Obj, typename F1, typename F2>
std::istream &operator>>(std::istream &is, Collection<Obj, F1, F2> &c);


template <typename Obj, typename F1, typename F2>
std::ostream &operator<<(std::ostream &os, const Collection<Obj, F1, F2> &c);


template <typename Obj, typename F1, typename F2>
Collection<Obj, F1, F2> make_union(const Collection<Obj, F1, F2> &c1, const Collection<Obj, F1, F2> &c2);


template <typename Obj, typename F1, typename F2>
void swap(Collection<Obj, F1, F2> &c1, Collection<Obj, F1, F2> &c2);


template <typename Obj, typename F1, typename F2>
void sort_by_size(Collection<Obj, F1, F2> &c, const Sort_choice sort);


// End declarations, begin definitions ------------------------------------------------------------------


template <typename Obj, typename F1, typename F2>
Collection<Obj, F1, F2>::Collection() {
    size = 0;
    capacity = 0;
    array = nullptr;
}


template <typename Obj, typename F1, typename F2>
Collection<Obj, F1, F2>::Collection(const int cap) {
    size = 0;
    capacity = cap;
    array = new Obj[cap];
}


template <typename Obj, typename F1, typename F2>
Collection<Obj, F1, F2>::Collection(const Collection &c) {
    size = c.size;
    capacity = c.capacity;
    array = new Obj[capacity];
    for (int i = 0; i < capacity; i++)
    {
        array[i] = c[i];
    }
    
}


template <typename Obj, typename F1, typename F2>
Collection<Obj, F1, F2>& Collection<Obj, F1, F2>::operator=(const Collection &c) {
    if (this == &c) {
        //cout << "SAME" << endl;
        return *this;
    }


    // cout << endl << endl << "Other collection Size: "<< c.size << endl;
    // cout << "This Size: " << this->size << endl;
    // cout << "Other collection Capacity: "<< c.capacity << endl;
    // cout << "This Capacity: " << this->capacity << endl << endl << endl;
    
    this->size = 0;

    // cout << endl << endl << "Other collection Size: "<< c.size << endl;
    // cout << "This Size: " << this->size << endl;
    // cout << "Other collection Capacity: "<< c.capacity << endl;
    // cout << "This Capacity: " << this->capacity << endl << endl << endl;
    
    this->capacity = c.capacity;
    delete[] array;
    array = new Obj[capacity];
    
    
    for (int i = 0; i < c.size; i++)
    {
        array[i] = c[i];
        size++;
        //cout << "Item " << c[i] << " added. array[i]=" << array[i] << endl;
    }

    // cout << endl << endl << "Other collection Size: "<< c.size << endl;
    // cout << "This Size: " << size << endl;
    // cout << "Other collection Capacity: "<< c.capacity << endl;
    // cout << "This Capacity: " << capacity << endl << endl << endl;
    
    return *this;
}


template <typename Obj, typename F1, typename F2>
Collection<Obj, F1, F2>::~Collection() {
    delete[] array;
    array = nullptr;
    capacity = 0;
    size = 0;
}


template <typename Obj, typename F1, typename F2>
Collection<Obj, F1, F2>::Collection(Collection &&c) {
    size = c.size;
    capacity = c.capacity;
    //delete[] array;
    //array = nullptr;
    array = c.array;
    
    c.array = nullptr;
    c.size = 0;
    c.capacity = 0;

}


template <typename Obj, typename F1, typename F2>
Collection<Obj, F1, F2>& Collection<Obj, F1, F2>::operator=(Collection &&c) {
    delete[] array;

    //cout << "USING MOVE" << endl << endl;

    array = c.array;
    c.array = nullptr;
    c.size = 0;
    c.capacity = 0;

    return *this;
}


// Other functions --------------------------------------------------------------------------------------

template <typename Obj, typename F1, typename F2>
void Collection<Obj, F1, F2>::insert_item(const Obj &sb) {
    // first insert
    if (capacity == 0) {
        capacity = 1;

        // create temp array
        Obj *temp_array = new Obj[capacity];
        
        // fill temp array
        temp_array[0] = sb;
        
        // clean up
        delete[] array;
        array = temp_array;
        //delete[] temp_array;
        temp_array = nullptr;
        size = 1;

    } else if (size == capacity) {
        
        capacity *= 2;

        // create temp array
        Obj *temp_array = new Obj[capacity];
        
        // fill temp array with array
        for (int i = 0; i < size; i++)
        {
            temp_array[i] = array[i];
        }


        // insert Obj
        temp_array[size] = sb;
        size++;
        
        // clean up
        delete[] array;
        // assign array with temp array and clean up temp array
        array = temp_array;
        //delete[] temp_array;
        temp_array = nullptr;

    } else {
        // insert stress ball
        array[size] = sb;
        size ++;

    }
}


template <typename Obj, typename F1, typename F2>
bool Collection<Obj, F1, F2>::contains(const Obj &sb) const{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == sb) {
            return true;
        }
    }

    return false;
    
}


template <typename Obj, typename F1, typename F2>
Obj Collection<Obj, F1, F2>::remove_any_item() {
    if (size == 0) {
        throw std::out_of_range("The collection is empty");
    }
    
    int index = rand() % size;
    Obj ball = array[index];

    Obj* temp_array = new Obj[capacity - 1];
    
    for (int i = 0; i < index; i++)
    {
        temp_array[i] = array[i];
    }

    for (int i = index; i < size - 1; i++)
    {
        temp_array[i] = array[i + 1];
    }

    delete[] array;
    array = temp_array;
    temp_array = nullptr;
    size--;

    return ball;
    
}


template <typename Obj, typename F1, typename F2>
void Collection<Obj, F1, F2>::remove_this_item(const Obj &sb) {
    if (size == 0) {
        throw std::out_of_range("The collection is empty");
    }
    
    bool found_item = false;
    int index = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] == sb) {
            found_item = true;
            index = i;
        }
    }

    if (found_item == false) {
        throw std::out_of_range("No equal item exists!");
    }


    Obj* temp_array = new Obj[capacity];

    // fill in array from temp array disregarding removed item
    for (int i = 0; i < index; i++)
    {
        temp_array[i] = array[i];
    }

    for (int i = index; i < size - 1; i++)
    {
        temp_array[i] = array[i + 1];
    }

    delete[] array;
    array = temp_array;
    temp_array = nullptr;
    size--;
}


template <typename Obj, typename F1, typename F2>
void Collection<Obj, F1, F2>::make_empty() {
    delete[] array;
    array = nullptr;

    capacity = 0;
    size = 0;
    
}


template <typename Obj, typename F1, typename F2>
bool Collection<Obj, F1, F2>::is_empty() const{
    if (size == 0) {
        return true;
    }
    return false;
}


template <typename Obj, typename F1, typename F2>
int Collection<Obj, F1, F2>::total_items() const{
    return size;
}


template <typename Obj, typename F1, typename F2>
int Collection<Obj, F1, F2>::total_items(const F2 s) const{
    int total= 0;
    
    for (int i = 0; i < size; i++)
    {
        if (array[i].get_size() == s) {
            total++;
        }
    }
    return total;
}


template <typename Obj, typename F1, typename F2>
int Collection<Obj, F1, F2>::total_items(const F1 c) const{
    int total= 0;
    
    for (int i = 0; i < size; i++)
    {
        if (array[i].get_color() == c) {
            total++;
        }
    }
    return total;
}


template <typename Obj, typename F1, typename F2>
void Collection<Obj, F1, F2>::print_items() const{
    //cout << "Size: " << size << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "(" << array[i].color_list[array[i].get_color()] << "," << array[i].size_list[array[i].get_size()] << ")" << endl;
    }
    
}


template <typename Obj, typename F1, typename F2>
Obj& Collection<Obj, F1, F2>::operator[](const int i) {
    return array[i];
}


template <typename Obj, typename F1, typename F2>
const Obj& Collection<Obj, F1, F2>::operator[](const int i) const{
    return array[i];
}



// Other Functions part 2 -------------------------------------------------------------------------------



template <typename Obj, typename F1, typename F2>
std::istream &operator>>(std::istream &is, Collection<Obj, F1, F2> &c) {
    Obj o;
    while (is >> o) {
        c.insert_item(o);
    }
    return is;

}


template <typename Obj, typename F1, typename F2>
std::ostream &operator<<(std::ostream &os, const Collection<Obj, F1, F2> &c) {
    
    for (int i = 0; i < c.total_items(); i++)
    {   
        //cout << c[i] << endl;
        os << c[i] << endl;
    }
    // for (int i = 0; i < c.size; i++)
    // {
    //     os << "(" << color_list[c.array[i].get_color()] << "," << size_list[c.array[i].get_size()] << ")" << endl;
    // }
    
    
    return os;
}


template <typename Obj, typename F1, typename F2>
Collection<Obj, F1, F2> make_union(const Collection<Obj, F1, F2> &c1, const Collection<Obj, F1, F2> &c2) {
    Collection<Obj, F1, F2> c3;
    for (int i = 0; i < c1.total_items(); i++)
    {
        c3.insert_item(c1[i]);
    }

    for (int i = 0; i < c2.total_items(); i++)
    {
        c3.insert_item(c2[i]);
    }
    
    return c3;
}


template <typename Obj, typename F1, typename F2>
void swap(Collection<Obj, F1, F2> &c1, Collection<Obj, F1, F2> &c2) {
    Collection<Obj, F1, F2> temp;
    temp = c1;
    c1 = c2;
    c2 = temp;
}


template <typename Obj, typename F1, typename F2>
void sort_by_size(Collection<Obj, F1, F2> &c, const Sort_choice sort) {
    //cout << (int) sort;

    switch ((int) sort)
    {
    case 0: {// Bubble Sort

        for (int i = c.total_items(); i > 1; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (c[j+1].get_size() < c[j].get_size())
                {   
                    // swap items
                    Obj temp;
                    temp = c[j+1];
                    c[j+1] = c[j];
                    c[j] = temp;
                }
            }
        }
        break;
    } 

// ---------------------------------------

    case 1: { // Insertion Sort
        
        int i = 1;
        while (i < c.total_items()) {
            int j = i;
            while (j > 0 and c[j-1].get_size() > c[j].get_size()) {
                // swap items
                Obj temp;
                temp = c[j];
                c[j-1] = c[j];
                c[j] = temp;
                j--;
            }
            i++;
        }
        
        break;
    }

// ---------------------------------------

    case 2: { // Selection Sort

        int i = 0;
        int j = 0;

        for (i = 0; i < c.total_items()-1; i++) {
            int min = i;
            for (j = i+1; j < c.total_items(); j++) {
                if (c[j].get_size() < c[min].get_size()) {min = j;}
            }

            if (min != i) {                
                // swap items
                Obj temp;
                temp = c[i];
                c[i] = c[min];
                c[min] = temp;
            }
        }

        break;
    
    }

// ---------------------------------------

    default:
        break;
    }

}



#endif