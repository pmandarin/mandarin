/*
 * Copyright © 2018 AperLambda <aperlambda@gmail.com>
 *
 * This file is part of mandarin.
 *
 * Licensed under the MIT license. For more information,
 * see the LICENSE file.
 */

#ifndef MANDARIN_BASE_H
#define MANDARIN_BASE_H

#include "mandarin_exports.h"
#include <lambdacommon/system/system.h>
#include <fifo_map.hpp>

#ifdef LAMBDA_WINDOWS
#  define MANDARIN_DEFAULT_CONFIG_DIR_LOCATION "C:\\etc\\mandarin\\"
#elif LAMBDA_ANDROID
#  error "Android is not supported yet."
#else
#  define MANDARIN_DEFAULT_CONFIG_DIR_LOCATION "/etc/mandarin/"
#endif

namespace mandarin
{
	template<class K, class V, class dummy_compare, class A>
	using fifo_map_t = nlohmann::fifo_map<K, V, nlohmann::fifo_map_compare<K>, A>;

	enum ReturnCodes
	{
		SUCCESS = 0x00,
		ERROR = 0x01,
		ERROR_NON_ROOT = 0xAA
	};
}

#endif // MANDARIN_BASE_H