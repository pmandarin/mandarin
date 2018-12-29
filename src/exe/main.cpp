/*
 * Copyright © 2018 AperLambda <aperlambda@gmail.com>
 *
 * This file is part of mandarin.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#include <mandarin/mandarin.h>

namespace sys = lambdacommon::system;
namespace term = lambdacommon::terminal;

int main(int argc, char **argv)
{
	term::setup();
	term::set_title("mandarin");

	auto[context, return_code] = mandarin::init();
	if (return_code != mandarin::ReturnCodes::SUCCESS) {
		switch (return_code) {
			case mandarin::ERROR:
				return return_code;
			case mandarin::ERROR_NON_ROOT:
				std::cout << term::LIGHT_RED << "Error 0x" << std::hex << mandarin::ERROR_NON_ROOT << ": please run as root." << term::RESET << std::endl;
				return return_code;
			default:
				break;
		}
	}

	return mandarin::ReturnCodes::SUCCESS;
}