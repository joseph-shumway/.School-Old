if(EXISTS "/mnt/c/.School/CSCE_221/PA-1/pa1-p3/planr/build/gtest/destructors[1]_tests.cmake")
  include("/mnt/c/.School/CSCE_221/PA-1/pa1-p3/planr/build/gtest/destructors[1]_tests.cmake")
else()
  add_test(destructors_NOT_BUILT destructors_NOT_BUILT)
endif()