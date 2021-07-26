#include "alpaca/trade.h"

#include "alpaca/json.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

namespace alpaca {
Status Trade::fromJSON(const std::string& json) {
  rapidjson::Document d;
  if (d.Parse(json.c_str()).HasParseError()) {
    return Status(1, "Received parse error when deserializing trade JSON");
  }

  if (!d.IsObject()) {
    return Status(1, "Deserialized valid JSON but it wasn't a trade object");
  }

  PARSE_DOUBLE(price, "p")
  PARSE_INT(size, "s")
  PARSE_INT(exchange, "x")
  PARSE_UINT64(timestamp, "t")

  return Status();
}
} // namespace alpaca
