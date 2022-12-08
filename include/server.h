#ifndef SERVER_H
#define SERVER_H

class User;

#include "crypto.h"
#include "message.h"
#include "user.h"
#include <map>
#include <vector>

class Server {
public:
  Server() = default;

  std::vector<User> get_users() { return users; }
  std::map<std::string, std::string> get_public_keys() { return public_keys; }
  std::vector<Message *> get_messages() { return messages; }

  bool create_message(Message *msg, std::string signature);
  User create_user(std::string username);

private:
  std::vector<User> users; // to store our users
  std::map<std::string, std::string>
      public_keys;                 // map usernames to their publickeys
  std::vector<Message *> messages; // to store all the messages sent by users
};

#endif // SERVER_H