#pragma once

#include <iomanip>
#include <vector>
#include <string>
#include "Argument.h"


namespace CMD {

	class Parser final {

	public:
		explicit Parser(const std::string& example);

		void SetArguments(const std::vector<Argument*> arguments);
		bool Parse(int argc, const char** argv);

		void PrintErrors(std::ostream& os) const;
		void PrintHelp(std::ostream& os) const;

	private:
		std::vector<Argument*> arguments_;
		std::vector<std::string> errors_;
		std::string example_;

		void ValidateArguments(std::vector<Argument*>& arguments);

	};

}


