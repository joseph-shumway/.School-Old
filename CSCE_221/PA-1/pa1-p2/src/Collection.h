#ifndef COLLECTION_H
#define COLLECTION_H
#include <exception>
#include <string>
#include <iostream>
#include "Stress_ball.h"

enum class Sort_choice
{
    bubble_sort,
    insertion_sort,
    selection_sort
};

struct EmptyCollectionException : public std::exception
{
	const char * what () const noexcept
    {
        return "Collection is Empty!";
    }
};

class Collection
{
    Stress_ball *array;
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
    void insert_item(const Stress_ball &sb);
    bool contains(const Stress_ball &sb) const;
    Stress_ball remove_any_item();
    void remove_this_item(const Stress_ball &sb);
    void make_empty();
    bool is_empty() const;
    int total_items() const;
    int total_items(const Stress_ball_sizes s) const;
    int total_items(const Stress_ball_colors c) const;
    void print_items() const;
    Stress_ball &operator[](const int i);
    const Stress_ball &operator[](const int i) const;
};

std::istream &operator>>(std::istream &is, Collection &c);
std::ostream &operator<<(std::ostream &os, const Collection &c);
Collection make_union(const Collection &c1, const Collection &c2);
void swap(Collection &c1, Collection &c2);
void sort_by_size(Collection &c, const Sort_choice sort);
#endif
