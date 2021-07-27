#pragma once

#include <string>

#include "alpaca/status.h"

namespace alpaca {

/**
 * @brief A type representing a trade.
 */
class Trade {
 public:
  /**
   * @brief A method for deserializing JSON into the current object state.
   *
   * @param json The JSON string
   *
   * @return a Status indicating the success or faliure of the operation.
   */
  Status fromJSON(const std::string& json);

 public:
  double price;
  int size;
  int exchange;
  //left out conditions cuz im lazy and dont use them/need them rn
  // int cond1;
  // int cond2;
  // int cond3;
  // int cond4;
  std::string timestamp;
  //Note you could even have more objects -- see the alpaca apiv2 docs for more, but i rly only care abt price,
  //and exchance/timestamp were j easy since they were already there.
};

/**
 * @brief A type representing the last trade for a certain symbol.
 */
class LastTrade {
 public:
  /**
   * @brief A method for deserializing JSON into the current object state.
   *
   * @param json The JSON string
   *
   * @return a Status indicating the success or faliure of the operation.
   */
  Status fromJSON(const std::string& json);

 public:
  //std::string status;
  std::string symbol;
  Trade trade;
};
} // namespace alpaca
