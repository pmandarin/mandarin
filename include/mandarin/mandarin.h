/*
 * Copyright © 2018 AperLambda <aperlambda@gmail.com>
 *
 * This file is part of mandarin.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#ifndef MANDARIN_LIBRARY_H
#define MANDARIN_LIBRARY_H

#include "config.h"

#define MANDARIN_VERSION_MAJOR 0
#define MANDARIN_VERSION_MINOR 1
#define MANDARIN_VERSION_PATCH 0
#define MANDARIN_VERSION_TYPE "indev"

namespace mandarin
{
	class MandarinContext
	{

	};

	/*!
	 * Initializes the mandarin library.
	 * @return A pointer to a mandarin context if succeed, else null.
	 */
	std::pair<std::shared_ptr<MandarinContext>, uint32_t> init();

	/*!
	 * Gets the runtime version of mandarin as a string.
	 * @return The runtime version of mandarin.
	 */
	extern std::string MANDARIN_API get_version();	
}

#endif //MANDARIN_LIBRARY_H