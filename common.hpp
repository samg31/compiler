#ifndef COMMON_HPP
#define COMMON_HPP

#include <memory>
#include <string>
#include "token.hpp"

using token_ptr = std::unique_ptr<token>;
using symbol = const std::string;

#endif
