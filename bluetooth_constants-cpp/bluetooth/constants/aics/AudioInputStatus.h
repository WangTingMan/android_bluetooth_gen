/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=cpp -Weverything -Wno-missing-permission-annotation -t --min_sdk_version 36 --ninja -d out/soong/.intermediates/packages/modules/Bluetooth/common/bluetooth_constants-cpp-source/gen/staging/bluetooth/constants/aics/AudioInputStatus.cpp.d -h out/soong/.intermediates/packages/modules/Bluetooth/common/bluetooth_constants-cpp-source/gen/include/staging -o out/soong/.intermediates/packages/modules/Bluetooth/common/bluetooth_constants-cpp-source/gen/staging -Npackages/modules/Bluetooth/common packages/modules/Bluetooth/common/bluetooth/constants/aics/AudioInputStatus.aidl
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
enum class AudioInputStatus : int8_t {
  INACTIVE = 0,
  ACTIVE = 1,
};
}  // namespace aics
}  // namespace constants
}  // namespace bluetooth
namespace bluetooth {
namespace constants {
namespace aics {
[[nodiscard]] static inline std::string toString(AudioInputStatus val) {
  switch(val) {
  case AudioInputStatus::INACTIVE:
    return "INACTIVE";
  case AudioInputStatus::ACTIVE:
    return "ACTIVE";
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
constexpr inline std::array<::bluetooth::constants::aics::AudioInputStatus, 2> enum_values<::bluetooth::constants::aics::AudioInputStatus> = {
  ::bluetooth::constants::aics::AudioInputStatus::INACTIVE,
  ::bluetooth::constants::aics::AudioInputStatus::ACTIVE,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
