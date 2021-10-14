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
#include "Post.h"
#include <sstream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

Post::Post(unsigned int postId, string userName, string postText)
  : postId(postId), userName(userName), postText(postText) {
  if (postId == 0 || userName == "" || postText == "") {
    throw std::invalid_argument("post constructor: invalid parameter values");
  }
}

unsigned int Post::getPostId() {
  return postId;
}

string Post::getPostUser() {
  return userName;
}

string Post::getPostText() {
  return postText;
}

vector<string> Post::findTags() {
  // TODO(student): extracts candidate tags based on occurrences of # in the post
  string text = this -> postText;
  std::stringstream ss;

  string current = "";
  vector<string> result;

  ss.str(text);

  while (ss >> current) {
    //cout << current << endl;
    if (current.at(0) == '#') {
      //current.erase(0,1);

      for (int i = 0; i < current.size(); i++) {
        switch (current.at(i)) {
          case 'A': current.at(i) = 'a'; break;
          case 'B': current.at(i) = 'b'; break;
          case 'C': current.at(i) = 'c'; break;
          case 'D': current.at(i) = 'd'; break;
          case 'E': current.at(i) = 'e'; break;
          case 'F': current.at(i) = 'f'; break;
          case 'G': current.at(i) = 'g'; break;
          case 'H': current.at(i) = 'h'; break;
          case 'I': current.at(i) = 'i'; break;
          case 'J': current.at(i) = 'j'; break;
          case 'K': current.at(i) = 'k'; break;
          case 'L': current.at(i) = 'l'; break;
          case 'M': current.at(i) = 'm'; break;
          case 'N': current.at(i) = 'n'; break;
          case 'O': current.at(i) = 'o'; break;
          case 'P': current.at(i) = 'p'; break;
          case 'Q': current.at(i) = 'q'; break;
          case 'R': current.at(i) = 'r'; break;
          case 'S': current.at(i) = 's'; break;
          case 'T': current.at(i) = 't'; break;
          case 'U': current.at(i) = 'u'; break;
          case 'V': current.at(i) = 'v'; break;
          case 'W': current.at(i) = 'w'; break;
          case 'X': current.at(i) = 'x'; break;
          case 'Y': current.at(i) = 'y'; break;
          case 'Z': current.at(i) = 'z'; break;

          case '!': current.erase(i,1); i--; break;
          case ',': current.erase(i,1); i--; break;
          case '.': current.erase(i,1); i--; break;
          case '?': current.erase(i,1); i--; break;

          default: break;

          
        }
      }

      //cout << "Revised: " << current << endl;
      result.push_back(current);

    }
  }

  

  return result;

}
