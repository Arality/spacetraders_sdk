#pragma once
#include <string>

namespace SpaceTraders::sdk {

class Authentication {
public:
  constexpr Authentication(std::string &token) : token(token) {};

  operator std::string() const;

  friend std::ostream &operator<<(std::ostream &os, const Authentication &auth);

private:
  const std::string &token;
};
} // namespace SpaceTraders::sdk