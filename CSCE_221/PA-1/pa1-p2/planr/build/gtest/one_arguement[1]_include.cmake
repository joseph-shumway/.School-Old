if(EXISTS "/mnt/c/.School/CSCE_221/PA-1/pa1-p2/planr/build/gtest/one_arguement[1]_tests.cmake")
  include("/mnt/c/.School/CSCE_221/PA-1/pa1-p2/planr/build/gtest/one_arguement[1]_tests.cmake")
else()
  add_test(one_arguement_NOT_BUILT one_arguement_NOT_BUILT)
endif()