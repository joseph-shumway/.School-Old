#include "gtest/gtest.h"
#include "Collection.h"
#include "Jeans.h"
#include "Stress_ball.h"

#include "data_files.h"

#include <sstream>
#include <vector>
#include <string.h>

using namespace std;

using CollectionSB = Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes>;
using CollectionJN = Collection<Jeans, Jeans_colors, Jeans_sizes>;


template <class T>
vector<T> buildMatchingVector(stringstream& ss){
    vector<T> v;
    T obj;

    while(ss >> obj){
        v.push_back(obj);
    }
    return v;
}


template <class StoredType, class CollectionType>
void checkOneTestCase(const char * const input, const char * const expected_output){
    std::stringstream ss_input;
    ss_input << input;

    CollectionType col;
    ss_input >> col;

    // reset the stream
    ss_input.clear();
    ss_input.seekg(0, ios::beg);

    auto vec = buildMatchingVector<StoredType>(ss_input);

    if(static_cast<int>(vec.size()) != col.total_items()){
        std::cout << "Error: mismatch between expected size (" << vec.size() << ") and your size: " << col.total_items() << std::endl;
        ASSERT_TRUE(false);
    }

    std::cout << "Checking element-wise comparison of objects" << std::endl;
    for(int i = 0; i < col.total_items(); i++){
        ASSERT_TRUE(col[i] == vec[i]);
    }

    std::cout << "Passed element wise check, checking operator<<" << std::endl;

    std::stringstream ss_output;
    ss_output << col;

    int r = strcmp(ss_output.str().c_str(), expected_output);

    if(r != 0){
        std::cout << "!!! Mismatch between your output and expected output !!!" << std::endl;
        std::cout << "=== Your output is: ===" << std::endl;
        std::cout << ss_output.str() << std::endl;
        std::cout << "=== Expected output is: ===" << std::endl;
        std::cout << expected_output << std::endl;
        std::cout << "=== EOF ===" << std::endl;
    }

    ASSERT_TRUE(r == 0);
}

TEST(COLLECTION, STREAM_OPERATORS)
{
    checkOneTestCase<Jeans, CollectionJN>(jeans1, jeans1_out);
    checkOneTestCase<Jeans, CollectionJN>(jeans2, jeans2_out);
    checkOneTestCase<Stress_ball, CollectionSB>(Stress_ball1, Stress_ball1_out);
    checkOneTestCase<Stress_ball, CollectionSB>(Stress_ball2, Stress_ball2_out);
}
