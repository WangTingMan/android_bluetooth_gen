/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=cpp -Weverything -Wno-missing-permission-annotation -t --min_sdk_version 36 --ninja -d out/soong/.intermediates/packages/modules/Bluetooth/common/bluetooth_constants-cpp-source/gen/staging/bluetooth/constants/aics/GainMode.cpp.d -h out/soong/.intermediates/packages/modules/Bluetooth/common/bluetooth_constants-cpp-source/gen/include/staging -o out/soong/.intermediates/packages/modules/Bluetooth/common/bluetooth_constants-cpp-source/gen/staging -Npackages/modules/Bluetooth/common packages/modules/Bluetooth/common/bluetooth/constants/aics/GainMode.aidl
 *
 * DO NOT CHECK THIS FILE INTO A CODE TREE (e.g. git, etc..).
 * ALWAYS GENERATE THIS FILE FROM UPDATED AIDL COMPILER
 * AS A BUILD INTERMEDIATE ONLY. THIS IS NOT SOURCE CODE.
 */
#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace bluetooth {
namespace constants {
namespace aics {
enum class GainMode : int8_t {
  MANUAL_ONLY = 0,
  AUTOMATIC_ONLY = 1,
  MANUAL = 2,
  AUTOMATIC = 3,
};
}  // namespace aics
}  // namespace constants
}  // namespace bluetooth
namespace bluetooth {
namespace constants {
namespace aics {
[[nodiscard]] static inline std::string toString(GainMode val) {
  switch(val) {
  case GainMode::MANUAL_ONLY:
    return "MANUAL_ONLY";
  case GainMode::AUTOMATIC_ONLY:
    return "AUTOMATIC_ONLY";
  case GainMode::MANUAL:
    return "MANUAL";
  case GainMode::AUTOMATIC:
    return "AUTOMATIC";
  default:
    return std::to_string(static_cast<int8_t>(val));
  }
}
}  // namespace aics
}  // namespace constants
}  // namespace bluetooth
namespace android {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::bluetooth::constants::aics::GainMode, 4> enum_values<::bluetooth::constants::aics::GainMode> = {
  ::bluetooth::constants::aics::GainMode::MANUAL_ONLY,
  ::bluetooth::constants::aics::GainMode::AUTOMATIC_ONLY,
  ::bluetooth::constants::aics::GainMode::MANUAL,
  ::bluetooth::constants::aics::GainMode::AUTOMATIC,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
