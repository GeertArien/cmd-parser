#include "../include/Argument.h"


namespace CMD {

Argument::Argument(Type type, const std::string& identifier, const std::string& description, bool value)
		: type_(type), identifier_(identifier), description_(description), bool_value_(value)
{ }

Argument::Argument(Type type, const std::string& identifier, const std::string& description,
				   const std::string& value, bool required)
		: type_(type), identifier_(identifier), description_(description), string_value_(value), required_(required)
{ }

void Argument::SetBoolValue(bool value) {
	bool_value_ = value;
}

void Argument::SetStringValue(const std::string& value) {
	string_value_ = value;
}

}
