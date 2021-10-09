#ifndef __TA_TEST_UTILS_
#define __TA_TEST_UTILS_ 

#include <string>

std::string copy_remove_all(std::string input, std::string remove_set) {
  std::string out;
  out.reserve(input.length());

  bool shouldRemove;
  for(auto i = input.cbegin(); i != input.cend(); i++) {

    shouldRemove = false;
    for(auto r = remove_set.cbegin(); r != remove_set.cend(); r++) {
      if(*i == *r) {
        shouldRemove = true;
        break;
      }
    }

    if(shouldRemove) {
      continue;
    }

    out.push_back(*i);    
  }

  return out;
}


#endif /* ifndef __TEST_UTILS_ */
