/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <string>
#include <stdexcept>
#include "User.h"

using std::string;
using std::vector;

User::User(string userName) /* TODO(student): initialize */ {
  if (userName.size() < 1) {
    throw std::invalid_argument("Error: Username is empty");
  }

  for (int i = 0; i < userName.size(); i++) {
    switch (userName.at(i)) {
      case 'a': continue;
      case 'b': continue;
      case 'c': continue;
      case 'd': continue;
      case 'e': continue;
      case 'f': continue;
      case 'g': continue;
      case 'h': continue;
      case 'i': continue;
      case 'j': continue;
      case 'k': continue;
      case 'l': continue;
      case 'm': continue;
      case 'n': continue;
      case 'o': continue;
      case 'p': continue;
      case 'q': continue;
      case 'r': continue;
      case 's': continue;
      case 't': continue;
      case 'u': continue;
      case 'v': continue;
      case 'w': continue;
      case 'x': continue;
      case 'y': continue;
      case 'z': continue;

      default: throw std::invalid_argument("Error: First letter of Username is not a lowercase letter");
    }

  }

  this -> userName = userName;

}

string User::getUserName() {
  // TODO(student): implement getter
  return userName;
}

vector<Post*>& User::getUserPosts() {
  // TODO(student): implement getter
  return userPosts;
}

void User::addUserPost(Post* post) {
  // TODO(student): add post to user posts
  if (post == nullptr) {
    throw std::invalid_argument("Error: post is invalid");
  }

  userPosts.push_back(post);
}
