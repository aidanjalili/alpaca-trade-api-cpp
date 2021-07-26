#include "alpaca/bars.h"

#include "alpaca/json.h"
#include "glog/logging.h"
#include "rapidjson/document.h"

namespace alpaca {

Status Bar::fromJSON(const std::string& json) {
  rapidjson::Document d;
  if (d.Parse(json.c_str()).HasParseError()) {
    return Status(1, "Received parse error when deserializing bar JSON");
  }

  if (!d.IsObject()) {
    return Status(1, "Deserialized valid JSON but it wasn't a bars object");
  }

  PARSE_STRING(time, "t")
  PARSE_DOUBLE(open_price, "o")
  PARSE_DOUBLE(high_price, "h")
  PARSE_DOUBLE(low_price, "l")
  PARSE_DOUBLE(close_price, "c")
  PARSE_UINT(volume, "v")

  return Status();
}
} // namespace alpaca
