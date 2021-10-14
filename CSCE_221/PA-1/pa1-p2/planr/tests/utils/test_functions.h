#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTIONS_H
#include "Collection.h"
#include "Stress_ball.h"

/*
    This is some major cruft from last year lol
    - Alex
*/

bool assert_sorted(Collection& c){
    bool greater = false, less = false;
    if(c.total_items() < 2) return true;
    if(c[0].get_size() < c[1].get_size()) less = true;
    else if(c[0].get_size() > c[1].get_size()) greater = true;
    if(!greater && !less){
        int i = 0;
        for(i = 1; i < c.total_items()-1; i++){
            if(c[i].get_size() < c[i+1].get_size()){
                less = true;
                break;
            }
            else if(c[i].get_size() > c[i+1].get_size()){
                greater = true;
                break;
            }
        }
        if(!greater && !less) return true;
        else{
            if(less){
                for(; i < c.total_items()-1; i++){
                    if(c[i].get_size() > c[i+1].get_size()) return false;
                }
                return true;
            }
            else{
                for(; i < c.total_items()-1; i++){
                    if(c[i].get_size() < c[i+1].get_size()) return false;
                }
                return true;
            }
        }
    }
    else if(less){
        for(int i = 0; i < c.total_items()-1; i++){
            if(c[i].get_size() > c[i+1].get_size()) return false;
        }
        return true;
    }
    else{
        for(int i = 0; i < c.total_items()-1; i++){
            if(c[i].get_size() < c[i+1].get_size()) return false;
        }
        return true;
    }
}

template<class T>
bool assert_equal(T a, T b){
    return a == b;
}

bool assert_true(bool test){return test;}
bool assert_false(bool test){return !test;}

#endif