#pragma once

#include "authentication.hpp"
#include "restclient-cpp/connection.h"
#include <map>
#include <memory>
#include <nlohmann/json.hpp>
#include <string>

typedef std::map<std::string, std::string> Header;

namespace SpaceTraders::sdk {

class Connection {
public:
  constexpr Connection(const Authentication &auth) : auth(auth) {};
  nlohmann::basic_json<> get(const std::string endpoint,
                             const Header &header = {}) const;
  // nlohmann::basic_json<> put(const std::string endpoint,
  //                            const Header &header = {});
  // nlohmann::basic_json<> post(const std::string endpoint,
  //                             const Header &header = {});
  // nlohmann::basic_json<> patch(const std::string endpoint,
  //                              const Header &header = {});

private:
  const Authentication &auth;
  inline static const std::string base_url = "https://api.spacetraders.io/v2";
  std::unique_ptr<RestClient::Connection> get_connection(Header header) const;

  // Cache cache;
};

} // namespace SpaceTraders::sdk