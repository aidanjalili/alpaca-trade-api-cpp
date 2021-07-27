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

Status LastTrade::fromJSON(const std::string& json) {
  rapidjson::Document d;
  if (d.Parse(json.c_str()).HasParseError()) {
    return Status(1, "Received parse error when deserializing last trade JSON");
  }

  if (!d.IsObject()) {
    return Status(1, "Deserialized valid JSON but it wasn't a last trade object");
  }

  PARSE_STRING(symbol, "symbol")

  if (d.HasMember("trade") && d["trade"].IsObject()) {
    rapidjson::StringBuffer s;
    s.Clear();
    rapidjson::Writer<rapidjson::StringBuffer> writer(s);
    d["trade"].Accept(writer);
    if (auto status = trade.fromJSON(s.GetString()); !status.ok()) {
      return status;
    }
  }

  return Status();
}
} // namespace alpaca
