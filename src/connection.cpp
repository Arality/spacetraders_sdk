#include "connection.hpp"

namespace SpaceTraders::sdk {

nlohmann::basic_json<> Connection::get(const std::string endpoint,
                                       const Header &header) const {
  auto conn = get_connection(header);
  auto response = conn->get(endpoint);
  switch (response.code) {
  case 200: {
    auto data = nlohmann::json::parse(response.body);
    return data["data"];
  }
  default: {
    assert(false); // TODO Fix
  }
  }
}

// nlohmann::basic_json<> Connection::put(const std::string endpoint,
//                                        const Header &header) {}

// nlohmann::basic_json<> Connection::post(const std::string endpoint,
//                                         const Header &header) {}

// nlohmann::basic_json<> Connection::patch(const std::string endpoint,
//                                          const Header &header) {}

std::unique_ptr<RestClient::Connection>
Connection::get_connection(Header header) const {

  auto conn = std::unique_ptr<RestClient::Connection>(
      new RestClient::Connection(base_url));

  header["Content-Type"] = "application/json";
  header["Authorization"] = auth;
  for (const auto &[key, value] : header)
    conn->AppendHeader(key, value);

  return std::move(conn);
}
} // namespace SpaceTraders::sdk