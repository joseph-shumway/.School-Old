/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "Network.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

void printMenu() {
  cout << "Welcome to CPPeers" << endl;
  cout << "The options are: " << endl;
  cout << "1. load data file and add information" << endl;
  cout << "2. show posts by user" << endl;
  cout << "3. show posts with hashtag" << endl;
  cout << "4. show most popular hashtag" << endl;
  cout << "9. quit" << endl;
  cout << "--------> Enter your option: ";
}

void processLoad(Network& cppeers) {
  string fileName = "";
  cout << "Enter filename: ";
  cin >> fileName;
  cppeers.loadFromFile(fileName);
}

void processPostsByUser(Network& cppeers) {
  // TODO(student): implement

  cout << "Enter username: ";
  string userName = "";
  cin >> userName;

  vector<Post*> result = cppeers.getPostsByUser(userName);
  string text = "";

  for (auto each : result) {
    text = each->getPostText();
    cout << text << endl;
  }
}

void processPostsWithHashtags(Network& cppeers) {
  cout << "Enter tagname: ";
  string tagName = "";
  cin >> tagName;

  vector<Post*> result = cppeers.getPostsWithTag(tagName);
  string text = "";

  for (auto each : result) {
      text = each->getPostText();
      cout << text << endl;
  }
}

void processMostPopularHashtag(Network& cppeers) {
  // TODO(student): implement
  for (auto each : cppeers.getMostPopularHashtag()) {
      cout << each;
  }
  cout << endl;
}

int main() {

  try {
    Network cppeers;

    int choice = 0;

    // present menu
    do {
      printMenu();
      cin >> choice;
      switch(choice) {
        case 1: {
          processLoad(cppeers);
          break;
        }
        case 2: {
          processPostsByUser(cppeers);
          break;
        }
        case 3: {
          processPostsWithHashtags(cppeers);
          break;
        }
        case 4: {
          processMostPopularHashtag(cppeers);
          break;
        }
      }
    } while (choice != 9);
  } catch (std::exception& exc) {
    std::cout << exc.what() << endl;
  }

  return 0;
}
