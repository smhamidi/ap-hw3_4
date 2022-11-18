#include "message.h"
#include "../include/message.h"

Message::Message(std::string _type, std::string _sender, std::string _receiver)
    : type{_type}, sender{_sender}, receiver{_receiver} {
  std::time_t now = std::time(0);
  std::string _time = std::ctime(&now);
  _time.erase(_time.find_last_not_of(" \n\r\t") + 1);
  time = _time;
}

Message::Message() : Message::Message("", "", "") {}

std::string Message::get_type() { return type; }
std::string Message::get_sender() { return sender; }
std::string Message::get_receiver() { return receiver; }
std::string Message::get_time() { return time; }