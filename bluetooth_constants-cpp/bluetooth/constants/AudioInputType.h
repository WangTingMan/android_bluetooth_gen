/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Using: out/host/linux-x86/bin/aidl --lang=cpp -Weverything -Wno-missing-permission-annotation -t --min_sdk_version 36 --ninja -d out/soong/.intermediates/packages/modules/Bluetooth/common/bluetooth_constants-cpp-source/gen/staging/bluetooth/constants/AudioInputType.cpp.d -h out/soong/.intermediates/packages/modules/Bluetooth/common/bluetooth_constants-cpp-source/gen/include/staging -o out/soong/.intermediates/packages/modules/Bluetooth/common/bluetooth_constants-cpp-source/gen/staging -Npackages/modules/Bluetooth/common packages/modules/Bluetooth/common/bluetooth/constants/AudioInputType.aidl
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
enum class AudioInputType : int32_t {
  UNSPECIFIED = 0,
  BLUETOOTH = 1,
  MICROPHONE = 2,
  ANALOG = 3,
  DIGITAL = 4,
  RADIO = 5,
  STREAMING = 6,
  AMBIENT = 7,
};
}  // namespace constants
}  // namespace bluetooth
namespace bluetooth {
namespace constants {
[[nodiscard]] static inline std::string toString(AudioInputType val) {
  switch(val) {
  case AudioInputType::UNSPECIFIED:
    return "UNSPECIFIED";
  case AudioInputType::BLUETOOTH:
    return "BLUETOOTH";
  case AudioInputType::MICROPHONE:
    return "MICROPHONE";
  case AudioInputType::ANALOG:
    return "ANALOG";
  case AudioInputType::DIGITAL:
    return "DIGITAL";
  case AudioInputType::RADIO:
    return "RADIO";
  case AudioInputType::STREAMING:
    return "STREAMING";
  case AudioInputType::AMBIENT:
    return "AMBIENT";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}
}  // namespace constants
}  // namespace bluetooth
namespace android {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::bluetooth::constants::AudioInputType, 8> enum_values<::bluetooth::constants::AudioInputType> = {
  ::bluetooth::constants::AudioInputType::UNSPECIFIED,
  ::bluetooth::constants::AudioInputType::BLUETOOTH,
  ::bluetooth::constants::AudioInputType::MICROPHONE,
  ::bluetooth::constants::AudioInputType::ANALOG,
  ::bluetooth::constants::AudioInputType::DIGITAL,
  ::bluetooth::constants::AudioInputType::RADIO,
  ::bluetooth::constants::AudioInputType::STREAMING,
  ::bluetooth::constants::AudioInputType::AMBIENT,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
