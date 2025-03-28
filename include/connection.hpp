#pragma once

#include "authentication.hpp"
#include "restclient-cpp/connection.h"
#include <map>
#include <memory>
#include <nlohmann/json.hpp>
#include <string>

typedef std::map<std::string, std::string> Header;

namespace SpaceTraders::sdk {

class Client {
public:
  constexpr static Client &getInstance() {
    static Client instance;
    return instance;
  }
  constexpr ~Client() { RestClient::disable(); }

private:
  constexpr Client() { RestClient::init(); }

public:
  Client(Client const &) = delete;
  void operator=(Client const &) = delete;
};

class Connection {
public:
  constexpr Connection(const Authentication &auth)
      : auth(auth), client(Client::getInstance()) {};


  /**
   * @brief Perform a get request to the server
   * 
   * @param endpoint the enpoint to make the request to
   * @param header any additional headers to include
   * @return constexpr nlohmann::basic_json<> 
   */
  constexpr nlohmann::basic_json<> get(const std::string endpoint,
                                       const Header &header = {}) {
    auto conn = get_connection(header);



    const auto response = conn->get(endpoint);
    switch (response.code) {
    case 200: {
      const auto data = nlohmann::json::parse(response.body);
      return data["data"];
    }
    default: {
      assert(false); // TODO Fix
    }
    }
  };

  // nlohmann::basic_json<> put(const std::string endpoint,
  //                            const Header &header = {});
  // nlohmann::basic_json<> post(const std::string endpoint,
  //                             const Header &header = {});
  // nlohmann::basic_json<> patch(const std::string endpoint,
  //                              const Header &header = {});

private:
  const Authentication &auth;
  const Client &client;
  inline static const std::string baseUrl = "https://api.spacetraders.io/v2";
  constexpr std::unique_ptr<RestClient::Connection>
  get_connection(Header header) {

    auto conn = std::unique_ptr<RestClient::Connection>(
        new RestClient::Connection(baseUrl));

    header["Content-Type"] = "application/json";
    header["Authorization"] = auth;
    for (const auto &[key, value] : header)
      conn->AppendHeader(key, value);

    return conn;
  }



  // Cache cache;
};

} // namespace SpaceTraders::sdk