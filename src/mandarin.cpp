/*
 * Copyright © 2018 AperLambda <aperlambda@gmail.com>
 *
 * This file is part of mandarin.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#include <mandarin/mandarin.h>

#include "../include/mandarin/mandarin.h"

namespace mandarin
{
	std::pair<std::shared_ptr<MandarinContext>, uint32_t> init()
	{
		if (!lambdacommon::system::is_root())
			return {nullptr, ReturnCodes::ERROR_NON_ROOT};
		return {std::make_shared<MandarinContext>(), ReturnCodes::SUCCESS};
	}

	std::string MANDARIN_API get_version()
	{
		std::string type{MANDARIN_VERSION_TYPE};
		auto result = std::to_string(MANDARIN_VERSION_MAJOR) + '.' + std::to_string(MANDARIN_VERSION_MINOR) + '.' + std::to_string(MANDARIN_VERSION_PATCH);
		if (type != "Release")
			result = type + result;
		return result;
	}
}