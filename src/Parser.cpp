#include "../include/Parser.h"


namespace CMD {

Parser::Parser(const std::string& example) : example_(example)
{ }

void Parser::SetArguments(const std::vector<Argument*> arguments) {
	arguments_ = arguments;
}

bool Parser::Parse(int argc, const char** argv) {
	errors_.clear();

	for (size_t i = 1; i < argc; ++i) {
		const std::string current_identifier = argv[i];
		bool found_argument = false;

		for (auto& argument : arguments_) {
			if (argument->GetIdentifier() == current_identifier) {
				found_argument = true;

				if (argument->GetType() == Argument::Type::String) {
					if (++i < argc) {
						argument->SetStringValue(argv[i]);
						break;
					}
					else {
						errors_.push_back("Expected value for argument '" + argument->GetIdentifier() + "'");
					}
				}
				else {
					argument->SetBoolValue(true);
					break;
				}
			}
		}

		if (!found_argument) {
			errors_.push_back("Invalid argument '" + current_identifier + "'");
		}
	}

	ValidateArguments(arguments_);
	return errors_.empty();
}

void Parser::ValidateArguments(std::vector<Argument*>& arguments) {
	for (const auto& argument : arguments) {
		if (argument->IsRequired() && argument->GetStringValue().empty()) {
			errors_.push_back("'" + argument->GetIdentifier() + "' is a required argument");
		}
	}
}

void Parser::PrintErrors(std::ostream& os) const {
	os << "Errors:" << std::endl;

	for (const auto& error : errors_) {
		os << "- " << error << std::endl;
	}
}

void Parser::PrintHelp(std::ostream& os) const {
	os << "Arguments:\n";

	for (const auto& argument : arguments_) {
		os << std::left << std::setw(13) << argument->GetIdentifier() << std::setw(45) << argument->GetDescription();
		if (argument->IsRequired()) {
			os << "required";
		}
		os << '\n';
	}

	os << '\n' << "Example:" << '\n' << example_ << std::endl;
}

}