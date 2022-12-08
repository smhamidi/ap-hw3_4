#include "server.h"
#include <stdexcept>
#include <string>
#include <utility>

User Server::create_user(std::string username) {
  bool user_exist = false;
  for (auto const &[key, val] : public_keys) {
    if (val == username) {
      user_exist = true;
    }
  }
  if (user_exist) {
    throw std::logic_error("username already exists");
  }
  std::string user_public_key{}, user_private_key{};
  crypto::generate_key(user_public_key, user_private_key);

  User user{username, user_private_key, this};
  users.push_back(user);
  public_keys.insert(
      std::pair<std::string, std::string>(user_public_key, username));

  return user;
}
