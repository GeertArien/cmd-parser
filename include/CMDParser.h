#pragma once

#include <iomanip>
#include <vector>
#include <string>
#include "CMDArgument.h"


namespace RegexFA {

	class CMDParser final {

	public:
		explicit CMDParser(const std::string& example);

		void SetArguments(const std::vector<CMDArgument*> arguments);
		bool Parse(int argc, const char** argv);

		void PrintErrors(std::ostream& os) const;
		void PrintHelp(std::ostream& os) const;

	private:
		std::vector<CMDArgument*> arguments_;
		std::vector<std::string> errors_;
		std::string example_;

		void ValidateArguments(std::vector<CMDArgument*>& arguments);

	};

}


