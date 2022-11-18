#ifndef MESSAGE_H
#define MESSAGE_H
#include <chrono>
#include <ctime>
#include <string>

class Message {
public:
  Message(std::string _type, std::string _sender, std::string _receiver);
  Message();

  std::string get_type();
  std::string get_sender();
  std::string get_receiver();
  std::string get_time();

private:
  std::string type;     // type of the message ("text", "voice", ...)
  std::string sender;   // the username who send this message
  std::string receiver; // the username whom this message is intended for
  std::string time;     // creation time of the message
};

#endif // MESSAGE_H