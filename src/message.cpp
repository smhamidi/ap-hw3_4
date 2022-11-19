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

std::string Message::get_type() const { return type; }
std::string Message::get_sender() const { return sender; }
std::string Message::get_receiver() const { return receiver; }
std::string Message::get_time() const { return time; }

void Message::print(std::ostream &os) const {
  std::string stars(30, '*');
  os << stars << std::endl;
  os << sender << " -> " << receiver << std::endl;
  os << "message type: " << type << std::endl;
  os << "message time: " << time << std::endl;
  os << stars << std::endl;
}

TextMessage::TextMessage(std::string _text, std::string _sender,
                         std::string _receiver)
    : Message("text", _sender, _receiver), text{_text} {}

void TextMessage::print(std::ostream &os) const {
  std::string stars(30, '*');
  os << stars << std::endl;
  os << get_sender() << " -> " << get_receiver() << std::endl;
  os << "message type: " << get_type() << std::endl;
  os << "message time: " << get_time() << std::endl;
  os << "text: " << get_text() << std::endl;
  os << stars << std::endl;
}

VoiceMessage::VoiceMessage(std::string _sender, std::string _receiver)
    : Message("voice", _sender, _receiver) {
  for (size_t i = 0; i < 5; i++) {
    voice.push_back(i);
  }
}
void VoiceMessage::print(std::ostream &os) const {
  std::string stars(30, '*');
  os << stars << std::endl;
  os << get_sender() << " -> " << get_receiver() << std::endl;
  os << "message type: " << get_type() << std::endl;
  os << "message time: " << get_time() << std::endl;
  os << "voice: ";
  for (auto i : get_voice()) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  os << stars << std::endl;
}