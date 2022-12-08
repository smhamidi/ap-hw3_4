#ifndef USER_H
#define USER_H

class Server;

#include "message.h"
#include "server.h"

class User {
public:
  User(std::string _username, std::string _private_key, Server *_server);
  std::string get_username() { return username; }
  bool send_text_message(std::string text, std::string receiver);
  bool send_voice_message(std::string receiver);

private:
  std::string username;    // username of the user
  std::string private_key; // private key of the user
  Server *const server;    // a pointer to the server for communications
};

#endif // USER_H