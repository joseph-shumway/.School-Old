if(EXISTS "/mnt/c/.School/CSCE_221/PA-1/pa1-p2/planr/build/gtest/destructor[1]_tests.cmake")
  include("/mnt/c/.School/CSCE_221/PA-1/pa1-p2/planr/build/gtest/destructor[1]_tests.cmake")
else()
  add_test(destructor_NOT_BUILT destructor_NOT_BUILT)
endif()