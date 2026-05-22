/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=cpp -Weverything -Wno-missing-permission-annotation -t --min_sdk_version 36 --ninja -d out/soong/.intermediates/packages/modules/Bluetooth/common/bluetooth_constants-cpp-source/gen/staging/bluetooth/constants/aics/Mute.cpp.d -h out/soong/.intermediates/packages/modules/Bluetooth/common/bluetooth_constants-cpp-source/gen/include/staging -o out/soong/.intermediates/packages/modules/Bluetooth/common/bluetooth_constants-cpp-source/gen/staging -Npackages/modules/Bluetooth/common packages/modules/Bluetooth/common/bluetooth/constants/aics/Mute.aidl
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
enum class Mute : int8_t {
  NOT_MUTED = 0,
  MUTED = 1,
  DISABLED = 2,
};
}  // namespace aics
}  // namespace constants
}  // namespace bluetooth
namespace bluetooth {
namespace constants {
namespace aics {
[[nodiscard]] static inline std::string toString(Mute val) {
  switch(val) {
  case Mute::NOT_MUTED:
    return "NOT_MUTED";
  case Mute::MUTED:
    return "MUTED";
  case Mute::DISABLED:
    return "DISABLED";
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
constexpr inline std::array<::bluetooth::constants::aics::Mute, 3> enum_values<::bluetooth::constants::aics::Mute> = {
  ::bluetooth::constants::aics::Mute::NOT_MUTED,
  ::bluetooth::constants::aics::Mute::MUTED,
  ::bluetooth::constants::aics::Mute::DISABLED,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
