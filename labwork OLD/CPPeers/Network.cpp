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
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Network.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

Network::Network() {
  // empty containers of vectors already created
  // no implementation is needed here
}

void Network::loadFromFile(string fileName) {
  std::ifstream ifs(fileName);
  std::stringstream ss;
  std::string line = "";
  std::string type = "";

  string t_username = "";
  unsigned int t_postID = 0;
  string t_postText = "";

  if (!ifs.is_open()) {
    throw std::invalid_argument("Error: can't open file");
  }

  //cout << "TRANSCRIPT: " << endl;

  //while (getline(ifs, line)) {
  //  cout << line << endl;
  //}

  ifs.clear();
  ifs.seekg(std::ios::beg);


  while (getline(ifs, line)) {
    ss.clear();
    ss.str(line);

    ss >> type;

    try {
      if (type == "User") {
        t_username = "";
        ss >> t_username;
        //cout << "User found: " << t_username << endl;
        addUser(t_username);
        
      } else if (type == "Post") {
        //cout << "Post found!" << endl;
        ss >> t_postID;
        ss >> t_username;
        string textLine = "";
        getline(ss, textLine);
        t_postText = textLine;

        addPost(t_postID, t_username, t_postText);

      } else {
        throw std::runtime_error("Line does not start with Post or User");
      }
    } catch (std::invalid_argument e) {
      cout << e.what() << endl;
      throw std::runtime_error("Error: invalid format in file");
    }
    
  }

  


}

void Network::addUser(string userName) {

  for (int i = 0; i < userName.size(); i++) {
    switch (userName.at(i)) {
      case 'A': userName.at(i) = 'a'; break;
      case 'B': userName.at(i) = 'b'; break;
      case 'C': userName.at(i) = 'c'; break;
      case 'D': userName.at(i) = 'd'; break;
      case 'E': userName.at(i) = 'e'; break;
      case 'F': userName.at(i) = 'f'; break;
      case 'G': userName.at(i) = 'g'; break;
      case 'H': userName.at(i) = 'h'; break;
      case 'I': userName.at(i) = 'i'; break;
      case 'J': userName.at(i) = 'j'; break;
      case 'K': userName.at(i) = 'k'; break;
      case 'L': userName.at(i) = 'l'; break;
      case 'M': userName.at(i) = 'm'; break;
      case 'N': userName.at(i) = 'n'; break;
      case 'O': userName.at(i) = 'o'; break;
      case 'P': userName.at(i) = 'p'; break;
      case 'Q': userName.at(i) = 'q'; break;
      case 'R': userName.at(i) = 'r'; break;
      case 'S': userName.at(i) = 's'; break;
      case 'T': userName.at(i) = 't'; break;
      case 'U': userName.at(i) = 'u'; break;
      case 'V': userName.at(i) = 'v'; break;
      case 'W': userName.at(i) = 'w'; break;
      case 'X': userName.at(i) = 'x'; break;
      case 'Y': userName.at(i) = 'y'; break;
      case 'Z': userName.at(i) = 'z'; break;
      default: break;
    }
  }

  for (auto each : users) {
    if (each->getUserName() == userName) {
      string output = "Error: username " + userName + "already exists";
      throw std::invalid_argument(output);
    }
  }

  User* user = new User(userName);

  users.push_back(user);

  cout << "Added User " << userName << endl;
}

void Network::addPost(unsigned int postId, string userName, string postText) {
  // TODO(student): create post and add it to network
  
  //cout << endl << "Post Text: " << postText << endl;

  bool valid = false;

  for (int i = 0; i < posts.size(); i++) {
      if (posts.size() > 0) {
        if (posts.at(i)->getPostId() == postId) {
          throw std::invalid_argument("Error: duplicate postID");
        }
      }

      
  }


  for (int i = 0; i < users.size(); i++) {
    if (users.at(i)->getUserName() == userName) {valid = true;}
  }

  if (!valid) {
      throw std::invalid_argument("Error: no username exists matching input username");
  }

  Post* post = new Post(postId, userName, postText);
  posts.push_back(post);
  
  for (auto each : users) {
      if (each->getUserName() == userName) {
        each->addUserPost(post);
      }
  }

  vector<string> postTags = post->findTags();

  bool hasTag = false;
  //cout << "Post name: " << postId << endl;
  //cout << "Number of post tags: " << postTags.size() << endl;
  // for all tags in the post
  for (auto currentPostTag : postTags) {
    // for all tags in the global tag list
      for (auto currentGlobalTag : tags) {
          //check if the current tagname matches the global name in the loop
          if (currentGlobalTag->getTagName() == currentPostTag) {
            //add post to current tag
            currentGlobalTag->addTagPost(post);
            currentGlobalTag->numberOfPosts++;
            hasTag = true;
          }
      }

      //create new tag and add post to the tag if tag doesnt exist
      if (!hasTag) {
        try {
          Tag* tempTag = new Tag(currentPostTag);
          tempTag->addTagPost(post);
          tempTag->numberOfPosts++;
          tags.push_back(tempTag);
          //delete tempTag;
          

        } catch (std::invalid_argument e) {
          cout << e.what() << endl;
        }
      }
      hasTag = false;
  }

  
  cout << "Added Post " << post->getPostId() << " by " << post->getPostUser() << endl;

}

vector<Post*> Network::getPostsByUser(string userName) {
  // TODO(student): return posts created by the given user
  if (userName.size() == 0) {
    throw std::invalid_argument("Error: username invalid");
  }

  for (auto each : users) {
    if (each->getUserName() == userName) {
      return each->getUserPosts();
    }
  }
}

vector<Post*> Network::getPostsWithTag(string tagName) {
  // TODO(student): return posts containing the given tag
  if (tagName.size() == 0) {
    throw std::invalid_argument("Error: tag invalid");
  }

  //cout << endl << "TagName: " << tagName << endl;

  for (auto each : tags) {
    if (each->getTagName() == tagName) {
      //cout << "TAG: " << each->getTagName() << endl;

      //cout << "POSTS: " << endl;
      for (auto each2 : each->getTagPosts()) {
          //cout << "Post Text: " << each2->getPostText() << endl;
      }

      //cout << endl;
      
      return each->getTagPosts();
    } 
  }

  //cout << endl << endl;
}

vector<string> Network::getMostPopularHashtag() {
  // TODO(student): return the tag occurring in most posts
  int max = 0;
  vector<string> result;

  for (auto each : tags) {
    if (each->getTagPosts().size() > max) {
      max = each->getTagPosts().size();
      //cout << "new max: " << max << endl;
      result.clear();
      result.push_back(each->getTagName());
    } else if (each->getTagPosts().size() == max) {
      result.push_back(each->getTagName());
    }
  }

  return result;

}

/**
  * Destructor
  * Do not change; already implemented.
  */
Network::~Network() {
  for (unsigned int i = 0; i < users.size(); ++i) {
    delete users.at(i);
  }
  for (unsigned int i = 0; i < tags.size(); ++i) {
    delete tags.at(i);
  }
  for (unsigned int i = 0; i < posts.size(); ++i) {
    delete posts.at(i);
  }
}
