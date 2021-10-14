#include <iostream>
#include <cmath>
#include "./nth_root.h"

int main()
{
    { // MINIMUM REQUIREMENT (for this lab)
        // just call the function with various values of n and x

        try
        {
            nth_root(0, 2);
            nth_root(2, -2);
            nth_root(-2, 0);
            nth_root(1, 2);
            nth_root(-6, 2);
            nth_root(-1, 2);
            nth_root(-2, 2);
            nth_root(10, 2);
            nth_root(1, 0);
            nth_root(1, -2);
            nth_root(5, 5);
            nth_root(2, 2.35);
            nth_root(-2, -2.35);
            nth_root(-2.5, 2);
            nth_root(2.5, 2.5);
            nth_root(2, 1);
            nth_root(-2.5, -2.50);
        }
        catch (std::domain_error)
        {
        }
    }

    { // TRY HARD
        // report the value
        try
        {
            double actual = nth_root(2, 1.0);
            std::cout << "nth_root(2, 1) = " << actual << std::endl;

            double actual1 = nth_root(-2, 1.0);
            std::cout << "nth_root(2, 1) = " << actual1 << std::endl;

            double actual2 = nth_root(5, 1.5);
            std::cout << "nth_root(2, 1) = " << actual2 << std::endl;

            double actual3 = nth_root(2, 1.0);
            std::cout << "nth_root(2, 1) = " << actual3 << std::endl;

            double actual4 = nth_root(20, 17.7);
            std::cout << "nth_root(2, 1) = " << actual << std::endl;

            double actual5 = nth_root(-20, -111.0);
            std::cout << "nth_root(2, 1) = " << actual5 << std::endl;
        }
        catch (std::domain_error)
        {
        }
    }

    { // TRY HARDER
        // compare the actual value to the expected value
        double actual = nth_root(2, 1.0);
        double expected = 1;
        if (std::fabs(actual - expected) > 0.00005)
        {
            std::cout << "[FAIL] (n=2, x=1)" << std::endl;
            std::cout << "  expected nth_root(2, 1) to be " << expected << std::endl;
            std::cout << "  got " << actual << std::endl;
        }
        else
        {
            std::cout << "[PASS] (n=2, x=1)" << std::endl;
        }

        double actual1 = nth_root(12, 1.4);
        double expected1 = 1;
        if (std::fabs(actual1 - expected1) > 0.00005)
        {
            std::cout << "[FAIL] (n=2, x=1)" << std::endl;
            std::cout << "  expected nth_root(2, 1) to be " << expected1 << std::endl;
            std::cout << "  got " << actual1 << std::endl;
        }
        else
        {
            std::cout << "[PASS] (n=2, x=1)" << std::endl;
        }

        double actual2 = nth_root(22, 1.15);
        double expected2 = 1;
        if (std::fabs(actual2 - expected2) > 0.00005)
        {
            std::cout << "[FAIL] (n=2, x=1)" << std::endl;
            std::cout << "  expected nth_root(2, 1) to be " << expected2 << std::endl;
            std::cout << "  got " << actual2 << std::endl;
        }
        else
        {
            std::cout << "[PASS] (n=2, x=1)" << std::endl;
        }
    }
}
