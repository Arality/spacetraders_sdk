#include "authentication.hpp"

namespace SpaceTraders::sdk {

Authentication::operator std::string() const { return "Bearer " + token; }

std::ostream &operator<<(std::ostream &os, const Authentication &auth) {
  os << "Bearer " + auth.token;
  return os;
}

} // namespace SpaceTraders::sdk