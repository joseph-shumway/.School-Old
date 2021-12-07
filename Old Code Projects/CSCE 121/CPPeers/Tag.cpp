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
#include "Tag.h"
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

Tag::Tag(string tagName) /* TODO(student): initialize */ {
  
  numberOfPosts = 0;
  //cout << "TAG: " << tagName << endl;

  if (tagName.size() < 2) {
    throw std::invalid_argument("Error: tagName is less than 2 characters");
  }

  if (tagName.at(0) != '#') {
    throw std::invalid_argument("Error: tagName must begin with a #");
  }

  switch (tagName.at(1)) {
    case 'a': break;
    case 'b': break;
    case 'c': break;
    case 'd': break;
    case 'e': break;
    case 'f': break;
    case 'g': break;
    case 'h': break;
    case 'i': break;
    case 'j': break;
    case 'k': break;
    case 'l': break;
    case 'm': break;
    case 'n': break;
    case 'o': break;
    case 'p': break;
    case 'q': break;
    case 'r': break;
    case 's': break;
    case 't': break;
    case 'u': break;
    case 'v': break;
    case 'w': break;
    case 'x': break;
    case 'y': break;
    case 'z': break;

    default: throw std::invalid_argument("Error: First letter of tagName is not a lowercase letter");
  }

  for (int i = 1; i < tagName.size(); i++) {
    switch (tagName.at(i)) {
      case 'A': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'B': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'C': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'D': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'E': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'F': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'G': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'H': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'I': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'J': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'K': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'L': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'M': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'N': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'O': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'P': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'Q': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'R': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'S': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'T': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'U': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'V': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'W': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'X': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'Y': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");
      case 'Z': throw std::invalid_argument("Error: At least one character in tag is not a lowercase letter");

      default: continue;
    }

    switch (tagName.at(tagName.size() - 2)) {
      case '!': 
        switch (tagName.at(tagName.size() - 1)) {
          case '!': throw std::invalid_argument("Error: more than one ending punctiation");
          case ',': throw std::invalid_argument("Error: more than one ending punctiation");
          case '?': throw std::invalid_argument("Error: more than one ending punctiation");
          case '.': throw std::invalid_argument("Error: more than one ending punctiation");
        }
      case ',': 
        switch (tagName.at(tagName.size() - 1)) {
          case '!': throw std::invalid_argument("Error: more than one ending punctiation");
          case ',': throw std::invalid_argument("Error: more than one ending punctiation");
          case '?': throw std::invalid_argument("Error: more than one ending punctiation");
          case '.': throw std::invalid_argument("Error: more than one ending punctiation");
        }
      case '?': 
        switch (tagName.at(tagName.size() - 1)) {
          case '!': throw std::invalid_argument("Error: more than one ending punctiation");
          case ',': throw std::invalid_argument("Error: more than one ending punctiation");
          case '?': throw std::invalid_argument("Error: more than one ending punctiation");
          case '.': throw std::invalid_argument("Error: more than one ending punctiation");
        }
      case '.': 
        switch (tagName.at(tagName.size() - 1)) {
          case '!': throw std::invalid_argument("Error: more than one ending punctiation");
          case ',': throw std::invalid_argument("Error: more than one ending punctiation");
          case '?': throw std::invalid_argument("Error: more than one ending punctiation");
          case '.': throw std::invalid_argument("Error: more than one ending punctiation");
        }

      default: break;
    }

  }

  this -> tagName = tagName;
}

string Tag::getTagName() {
  return tagName;
}

vector<Post*>& Tag::getTagPosts() {
  return tagPosts;
}

void Tag::addTagPost(Post* post) {

  if (post == nullptr) {
    throw std::invalid_argument("Error: post is invalid");
  }

  tagPosts.push_back(post);
}
