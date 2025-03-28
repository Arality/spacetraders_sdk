#pragma once
#include <string>

namespace SpaceTraders::sdk {

class Authentication {
public:
  constexpr Authentication(const std::string &token) : token(token) {};

  operator std::string() const { return "Bearer " + token; };

  friend std::ostream &operator<<(std::ostream &os,
                                            const Authentication &auth) {
    os << "Bearer " + auth.token;
    return os;
  }

private:
  const std::string &token;
};
} // namespace SpaceTraders::sdk