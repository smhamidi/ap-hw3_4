#ifndef MESSAGE_H
#define MESSAGE_H
#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

class Message {
public:
  Message(std::string _type, std::string _sender, std::string _receiver);
  Message();

  std::string get_type() const;
  std::string get_sender() const;
  std::string get_receiver() const;
  std::string get_time() const;

  virtual void print(std::ostream &os) const;
  friend std::ostream &operator<<(std::ostream &os, const Message &c) {
    c.print(os);
    return os;
  };

private:
  std::string type;     // type of the message ("text", "voice", ...)
  std::string sender;   // the username who send this message
  std::string receiver; // the username whom this message is intended for
  std::string time;     // creation time of the message
};

class TextMessage : public Message {
public:
  TextMessage(std::string text, std::string sender, std::string receiver);
  void print(std::ostream &os) const;
  std::string get_text() const { return text; }

private:
  std::string text;
};

class VoiceMessage : public Message {
public:
  VoiceMessage(std::string sender, std::string receiver);
  void print(std::ostream &os) const;
  std::vector<unsigned char> get_voice() const { return voice; }

private:
  std::vector<unsigned char> voice;
};
#endif // MESSAGE_H