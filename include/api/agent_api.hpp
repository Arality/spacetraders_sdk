#pragma once
#include "agent_model.hpp"
#include "authentication.hpp"
#include "connection.hpp"
#include "foreign_agent_model.hpp"
#include <nlohmann/json.hpp>

namespace SpaceTraders::sdk::api {

class AgentAPI {
public:
  constexpr AgentAPI(const Authentication &auth) : auth(auth) {};

  /**
   * @brief Get's your agent
   *
   * @return SpaceTraders::sdk::model::AgentModel
   */
  constexpr SpaceTraders::sdk::model::Agent get_my_agent() {
    static const std::string endpoint = "/my/agent";
    auto conn = Connection(auth);
    auto results = conn.get(endpoint);
    auto agent = results.template get<SpaceTraders::sdk::model::Agent>();
    return agent;
  };

  /**
   * @brief Get's a foreign agent
   *
   * @param name agents name
   * @return SpaceTraders::sdk::model::ForeignAgentModel
   */
  constexpr SpaceTraders::sdk::model::ForeignAgentModel
  get_agent(const std::string name) {
    const std::string endpoint = "/agents/" + name;
    auto conn = Connection(auth);
    auto results = conn.get(endpoint);
    auto agent =
        results.template get<SpaceTraders::sdk::model::ForeignAgentModel>();
    return agent;
  };

  /**
   * @brief Get all agents
   *
   * @param page What entry offset to request
   * @param limit How many entries to return per page. Max 20
   * @return std::vector<SpaceTraders::sdk::model::ForeignAgentModel>
   */
  constexpr std::vector<SpaceTraders::sdk::model::ForeignAgentModel>
  get_all_agents(const uint page = 1, const uint limit = 10) {
    const std::string endpoint = "/agents";
    auto vec = std::vector<SpaceTraders::sdk::model::ForeignAgentModel>();
    Header header = Header();
    auto conn = Connection(auth);

    header["page"] = std::to_string(page);
    header["limit"] = std::to_string(limit);

    auto results = conn.get(endpoint, header);

    for (auto &agent : results) {
      vec.push_back(
          agent.template get<SpaceTraders::sdk::model::ForeignAgentModel>());
    }

    return vec;
  };

private:
  const Authentication &auth;
};

} // namespace SpaceTraders::sdk::api