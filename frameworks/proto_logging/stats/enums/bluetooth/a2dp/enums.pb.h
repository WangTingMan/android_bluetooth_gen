// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: frameworks/proto_logging/stats/enums/bluetooth/a2dp/enums.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_frameworks_2fproto_5flogging_2fstats_2fenums_2fbluetooth_2fa2dp_2fenums_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_frameworks_2fproto_5flogging_2fstats_2fenums_2fbluetooth_2fa2dp_2fenums_2eproto

#include <cstdint>
#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_util.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_frameworks_2fproto_5flogging_2fstats_2fenums_2fbluetooth_2fa2dp_2fenums_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_frameworks_2fproto_5flogging_2fstats_2fenums_2fbluetooth_2fa2dp_2fenums_2eproto {
  static const ::uint32_t offsets[];
};
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE
namespace android {
namespace bluetooth {
namespace a2dp {

enum PlaybackStateEnum : int {
  PLAYBACK_STATE_UNKNOWN = 0,
  PLAYBACK_STATE_PLAYING = 10,
  PLAYBACK_STATE_NOT_PLAYING = 11
};
bool PlaybackStateEnum_IsValid(int value);
constexpr PlaybackStateEnum PlaybackStateEnum_MIN = PLAYBACK_STATE_UNKNOWN;
constexpr PlaybackStateEnum PlaybackStateEnum_MAX = PLAYBACK_STATE_NOT_PLAYING;
constexpr int PlaybackStateEnum_ARRAYSIZE = PlaybackStateEnum_MAX + 1;

const std::string& PlaybackStateEnum_Name(PlaybackStateEnum value);
template<typename T>
inline const std::string& PlaybackStateEnum_Name(T enum_t_value) {
  static_assert(::std::is_same<T, PlaybackStateEnum>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function PlaybackStateEnum_Name.");
  return PlaybackStateEnum_Name(static_cast<PlaybackStateEnum>(enum_t_value));
}
bool PlaybackStateEnum_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, PlaybackStateEnum* value);
enum AudioCodingModeEnum : int {
  AUDIO_CODING_MODE_UNKNOWN = 0,
  AUDIO_CODING_MODE_HARDWARE = 1,
  AUDIO_CODING_MODE_SOFTWARE = 2
};
bool AudioCodingModeEnum_IsValid(int value);
constexpr AudioCodingModeEnum AudioCodingModeEnum_MIN = AUDIO_CODING_MODE_UNKNOWN;
constexpr AudioCodingModeEnum AudioCodingModeEnum_MAX = AUDIO_CODING_MODE_SOFTWARE;
constexpr int AudioCodingModeEnum_ARRAYSIZE = AudioCodingModeEnum_MAX + 1;

const std::string& AudioCodingModeEnum_Name(AudioCodingModeEnum value);
template<typename T>
inline const std::string& AudioCodingModeEnum_Name(T enum_t_value) {
  static_assert(::std::is_same<T, AudioCodingModeEnum>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function AudioCodingModeEnum_Name.");
  return AudioCodingModeEnum_Name(static_cast<AudioCodingModeEnum>(enum_t_value));
}
bool AudioCodingModeEnum_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, AudioCodingModeEnum* value);
// ===================================================================


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace a2dp
}  // namespace bluetooth
}  // namespace android

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::android::bluetooth::a2dp::PlaybackStateEnum> : ::std::true_type {};
template <> struct is_proto_enum< ::android::bluetooth::a2dp::AudioCodingModeEnum> : ::std::true_type {};

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_frameworks_2fproto_5flogging_2fstats_2fenums_2fbluetooth_2fa2dp_2fenums_2eproto