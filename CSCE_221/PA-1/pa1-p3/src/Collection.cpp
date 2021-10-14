

// #include "Collection.h"
// #include "Stress_ball.h"


// using std::cout;
// using std::endl;
// // Constructors


// Collection::Collection() {
//     size = 0;
//     capacity = 0;
//     array = nullptr;
// }

// Collection::Collection(const int cap) {
//     size = 0;
//     capacity = cap;
//     array = new Stress_ball[cap];
// }

// Collection::Collection(const Collection &c) {
//     size = c.size;
//     capacity = c.capacity;
//     array = new Stress_ball[capacity];
//     for (int i = 0; i < capacity; i++)
//     {
//         array[i] = c[i];
//     }
    
// }

// Collection& Collection::operator=(const Collection &c) {
//     if (this == &c) {
//         //cout << "SAME" << endl;
//         return *this;
//     }


//     // cout << endl << endl << "Other collection Size: "<< c.size << endl;
//     // cout << "This Size: " << this->size << endl;
//     // cout << "Other collection Capacity: "<< c.capacity << endl;
//     // cout << "This Capacity: " << this->capacity << endl << endl << endl;
    
//     this->size = 0;

//     // cout << endl << endl << "Other collection Size: "<< c.size << endl;
//     // cout << "This Size: " << this->size << endl;
//     // cout << "Other collection Capacity: "<< c.capacity << endl;
//     // cout << "This Capacity: " << this->capacity << endl << endl << endl;
    
//     this->capacity = c.capacity;
//     delete[] array;
//     array = new Stress_ball[capacity];
    
    
//     for (int i = 0; i < c.size; i++)
//     {
//         array[i] = c[i];
//         size++;
//         //cout << "Item " << c[i] << " added. array[i]=" << array[i] << endl;
//     }

//     // cout << endl << endl << "Other collection Size: "<< c.size << endl;
//     // cout << "This Size: " << size << endl;
//     // cout << "Other collection Capacity: "<< c.capacity << endl;
//     // cout << "This Capacity: " << capacity << endl << endl << endl;
    
//     return *this;
// }

// Collection::~Collection() {
//     delete[] array;
//     array = nullptr;
//     capacity = 0;
//     size = 0;
// }

// Collection::Collection(Collection &&c) {
//     size = c.size;
//     capacity = c.capacity;
//     //delete[] array;
//     //array = nullptr;
//     array = c.array;
    
//     c.array = nullptr;
//     c.size = 0;
//     c.capacity = 0;

// }

// Collection& Collection::operator=(Collection &&c) {
//     delete[] array;

//     //cout << "USING MOVE" << endl << endl;

//     array = c.array;
//     c.array = nullptr;
//     c.size = 0;
//     c.capacity = 0;

//     return *this;
// }


// // Other functions


// void Collection::insert_item(const Stress_ball &sb) {
//     // first insert
//     if (capacity == 0) {
//         capacity = 1;

//         // create temp array
//         Stress_ball *temp_array = new Stress_ball[capacity];
        
//         // fill temp array
//         temp_array[0] = sb;
        
//         // clean up
//         delete[] array;
//         array = temp_array;
//         //delete[] temp_array;
//         temp_array = nullptr;
//         size = 1;

//     } else if (size == capacity) {
        
//         capacity *= 2;

//         // create temp array
//         Stress_ball *temp_array = new Stress_ball[capacity];
        
//         // fill temp array with array
//         for (int i = 0; i < size; i++)
//         {
//             temp_array[i] = array[i];
//         }


//         // insert stress_ball
//         temp_array[size] = sb;
//         size++;
        
//         // clean up
//         delete[] array;
//         // assign array with temp array and clean up temp array
//         array = temp_array;
//         //delete[] temp_array;
//         temp_array = nullptr;

//     } else {
//         // insert stress ball
//         array[size] = sb;
//         size ++;

//     }
// }

// bool Collection::contains(const Stress_ball &sb) const{
//     for (int i = 0; i < size; i++)
//     {
//         if (array[i] == sb) {
//             return true;
//         }
//     }

//     return false;
    
// }

// Stress_ball Collection::remove_any_item() {
//     if (size == 0) {
//         throw std::out_of_range("The collection is empty");
//     }
    
//     int index = rand() % size;
//     Stress_ball ball = array[index];

//     Stress_ball* temp_array = new Stress_ball[capacity - 1];
    
//     for (int i = 0; i < index; i++)
//     {
//         temp_array[i] = array[i];
//     }

//     for (int i = index; i < size - 1; i++)
//     {
//         temp_array[i] = array[i + 1];
//     }

//     delete[] array;
//     array = temp_array;
//     temp_array = nullptr;
//     size--;

//     return ball;
    
// }

// void Collection::remove_this_item(const Stress_ball &sb) {
//     if (size == 0) {
//         throw std::out_of_range("The collection is empty");
//     }
    
//     bool found_item = false;
//     int index = 0;

//     for (int i = 0; i < size; i++)
//     {
//         if (array[i] == sb) {
//             found_item = true;
//             index = i;
//         }
//     }

//     if (found_item == false) {
//         throw std::out_of_range("No equal item exists!");
//     }


//     Stress_ball* temp_array = new Stress_ball[capacity];

//     // fill in array from temp array disregarding removed item
//     for (int i = 0; i < index; i++)
//     {
//         temp_array[i] = array[i];
//     }

//     for (int i = index; i < size - 1; i++)
//     {
//         temp_array[i] = array[i + 1];
//     }

//     delete[] array;
//     array = temp_array;
//     temp_array = nullptr;
//     size--;
    
// }

// void Collection::make_empty() {
//     delete[] array;
//     array = nullptr;

//     capacity = 0;
//     size = 0;
    
// }

// bool Collection::is_empty() const{
//     if (size == 0) {
//         return true;
//     }
//     return false;
// }

// int Collection::total_items() const{
//     return size;
// }

// int Collection::total_items(const Stress_ball_sizes s) const{
//     int total= 0;
    
//     for (int i = 0; i < size; i++)
//     {
//         if (array[i].get_size() == s) {
//             total++;
//         }
//     }
//     return total;
// }

// int Collection::total_items(const Stress_ball_colors c) const{
//     int total= 0;
    
//     for (int i = 0; i < size; i++)
//     {
//         if (array[i].get_color() == c) {
//             total++;
//         }
//     }
//     return total;
// }

// void Collection::print_items() const{
//     //cout << "Size: " << size << endl;
//     for (int i = 0; i < size; i++)
//     {
//         cout << "(" << color_list[array[i].get_color()] << "," << size_list[array[i].get_size()] << ")" << endl;
//     }
    
// }

// Stress_ball& Collection::operator[](const int i) {
//     return array[i];
// }

// const Stress_ball& Collection::operator[](const int i) const{
//     return array[i];
// }

// //
// //
// // Other Functions
// //
// //

// std::istream &operator>>(std::istream &is, Collection &c) {
//     string color_t = "";
//     string size_temp = "";
//     while (is >> color_t >> size_temp){

//         if (color_t.empty() || size_temp.empty()) {
//             return is;
//         }
//         //cout << "Color: " << color_t << endl;
//         //cout << "Size: " << size_t << endl;
//         Stress_ball_sizes s1;
//         Stress_ball_colors c1;

//         for (unsigned int i = 0; i < 4; i++) {
//             //cout << "Color: " << color_t << endl;
//             if (color_t == color_list[i]) {
//                 c1 = Stress_ball_colors(i);
//                 //cout << "COLOR MATCH! Color=" << color_list[Stress_ball_colors(c1)] << endl;
//             }
//         }

        
//         for (unsigned int i = 0; i < size_list->size(); i++) {
//             if (size_temp == size_list[i]) {
//                 s1 = Stress_ball_sizes(i);
//             }
//         }

//         Stress_ball sb = Stress_ball(c1, s1);

//         c.insert_item(sb);
//     }
//     return is;

// }

// std::ostream &operator<<(std::ostream &os, const Collection &c) {
    
//     for (int i = 0; i < c.total_items(); i++)
//     {   
//         //cout << c[i] << endl;
//         os << c[i] << endl;
//     }
//     // for (int i = 0; i < c.size; i++)
//     // {
//     //     os << "(" << color_list[c.array[i].get_color()] << "," << size_list[c.array[i].get_size()] << ")" << endl;
//     // }
    
    
//     return os;
// }

// Collection make_union(const Collection &c1, const Collection &c2) {
//     Collection c3;
//     for (int i = 0; i < c1.total_items(); i++)
//     {
//         c3.insert_item(c1[i]);
//     }

//     for (int i = 0; i < c2.total_items(); i++)
//     {
//         c3.insert_item(c2[i]);
//     }
    
//     return c3;
// }

// void swap(Collection &c1, Collection &c2) {
//     Collection temp;
//     temp = c1;
//     c1 = c2;
//     c2 = temp;
// }

// void sort_by_size(Collection &c, const Sort_choice sort) {
    //cout << (int) sort;
    // switch (sort)
    // {
    // case 0:
    //     break;
    // case 1:
    //     break;
    // case 2:
    //     break;
    
    // default:
    //     break;
    // }


    //cout << (sort == a) << endl;
    //bool d = c.is_empty();
    //cout << d;
//}