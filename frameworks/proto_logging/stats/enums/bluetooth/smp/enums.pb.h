// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: frameworks/proto_logging/stats/enums/bluetooth/smp/enums.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_frameworks_2fproto_5flogging_2fstats_2fenums_2fbluetooth_2fsmp_2fenums_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_frameworks_2fproto_5flogging_2fstats_2fenums_2fbluetooth_2fsmp_2fenums_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_frameworks_2fproto_5flogging_2fstats_2fenums_2fbluetooth_2fsmp_2fenums_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_frameworks_2fproto_5flogging_2fstats_2fenums_2fbluetooth_2fsmp_2fenums_2eproto {
  static const ::uint32_t offsets[];
};
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE
namespace android {
namespace bluetooth {
namespace smp {

enum CommandEnum : int {
  CMD_UNKNOWN = 0,
  CMD_PAIRING_REQUEST = 1,
  CMD_PAIRING_RESPONSE = 2,
  CMD_PAIRING_CONFIRM = 3,
  CMD_PAIRING_RANDOM = 4,
  CMD_PAIRING_FAILED = 5,
  CMD_ENCRYPTION_INFON = 6,
  CMD_MASTER_IDENTIFICATION = 7,
  CMD_IDENTITY_INFO = 8,
  CMD_IDENTITY_ADDR_INFO = 9,
  CMD_SIGNING_INFO = 10,
  CMD_SECURITY_REQUEST = 11,
  CMD_PAIRING_PUBLIC_KEY = 12,
  CMD_PAIRING_DHKEY_CHECK = 13,
  CMD_PAIRING_KEYPRESS_INFO = 14,
  CMD_PAIRING_COMPLETE = 65280,
  CMD_BR_UNKNOWN = 256,
  CMD_BR_PAIRING_REQUEST = 257,
  CMD_BR_PAIRING_RESPONSE = 258,
  CMD_BR_PAIRING_CONFIRM = 259,
  CMD_BR_PAIRING_RANDOM = 260,
  CMD_BR_PAIRING_FAILED = 261,
  CMD_BR_ENCRYPTION_INFON = 262,
  CMD_BR_MASTER_IDENTIFICATION = 263,
  CMD_BR_IDENTITY_INFO = 264,
  CMD_BR_IDENTITY_ADDR_INFO = 265,
  CMD_BR_SIGNING_INFO = 266,
  CMD_BR_SECURITY_REQUEST = 267,
  CMD_BR_PAIRING_PUBLIC_KEY = 268,
  CMD_BR_PAIRING_DHKEY_CHECK = 269,
  CMD_BR_PAIRING_KEYPRESS_INFO = 270,
  CMD_BR_PAIRING_COMPLETE = 65281
};
bool CommandEnum_IsValid(int value);
constexpr CommandEnum CommandEnum_MIN = CMD_UNKNOWN;
constexpr CommandEnum CommandEnum_MAX = CMD_BR_PAIRING_COMPLETE;
constexpr int CommandEnum_ARRAYSIZE = CommandEnum_MAX + 1;

const std::string& CommandEnum_Name(CommandEnum value);
template<typename T>
inline const std::string& CommandEnum_Name(T enum_t_value) {
  static_assert(::std::is_same<T, CommandEnum>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function CommandEnum_Name.");
  return CommandEnum_Name(static_cast<CommandEnum>(enum_t_value));
}
bool CommandEnum_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, CommandEnum* value);
enum PairingFailReasonEnum : int {
  PAIRING_FAIL_REASON_RESERVED = 0,
  PAIRING_FAIL_REASON_PASSKEY_ENTRY = 1,
  PAIRING_FAIL_REASON_OOB = 2,
  PAIRING_FAIL_REASON_AUTH_REQ = 3,
  PAIRING_FAIL_REASON_CONFIRM_VALUE = 4,
  PAIRING_FAIL_REASON_PAIR_NOT_SUPPORT = 5,
  PAIRING_FAIL_REASON_ENC_KEY_SIZE = 6,
  PAIRING_FAIL_REASON_INVALID_CMD = 7,
  PAIRING_FAIL_REASON_UNSPECIFIED = 8,
  PAIRING_FAIL_REASON_REPEATED_ATTEMPTS = 9,
  PAIRING_FAIL_REASON_INVALID_PARAMETERS = 10,
  PAIRING_FAIL_REASON_DHKEY_CHK = 11,
  PAIRING_FAIL_REASON_NUMERIC_COMPARISON = 12,
  PAIRING_FAIL_REASON_CLASSIC_PAIRING_IN_PROGR = 13,
  PAIRING_FAIL_REASON_XTRANS_DERIVE_NOT_ALLOW = 14,
  PAIRING_FAIL_REASON_CANCELLED = 27,
  PAIRING_FAIL_REASON_INTERNAL_ERROR = 271,
  PAIRING_FAIL_REASON_UNKNOWN_IO_CAP = 272,
  PAIRING_FAIL_REASON_BUSY = 275,
  PAIRING_FAIL_REASON_ENCRYPTION_FAIL = 276,
  PAIRING_FAIL_REASON_STARTED = 277,
  PAIRING_FAIL_REASON_RESPONSE_TIMEOUT = 278,
  PAIRING_FAIL_REASON_FAIL = 280,
  PAIRING_FAIL_REASON_CONNECTION_TIMEOUT = 281
};
bool PairingFailReasonEnum_IsValid(int value);
constexpr PairingFailReasonEnum PairingFailReasonEnum_MIN = PAIRING_FAIL_REASON_RESERVED;
constexpr PairingFailReasonEnum PairingFailReasonEnum_MAX = PAIRING_FAIL_REASON_CONNECTION_TIMEOUT;
constexpr int PairingFailReasonEnum_ARRAYSIZE = PairingFailReasonEnum_MAX + 1;

const std::string& PairingFailReasonEnum_Name(PairingFailReasonEnum value);
template<typename T>
inline const std::string& PairingFailReasonEnum_Name(T enum_t_value) {
  static_assert(::std::is_same<T, PairingFailReasonEnum>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function PairingFailReasonEnum_Name.");
  return PairingFailReasonEnum_Name(static_cast<PairingFailReasonEnum>(enum_t_value));
}
bool PairingFailReasonEnum_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, PairingFailReasonEnum* value);
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

}  // namespace smp
}  // namespace bluetooth
}  // namespace android

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::android::bluetooth::smp::CommandEnum> : ::std::true_type {};
template <> struct is_proto_enum< ::android::bluetooth::smp::PairingFailReasonEnum> : ::std::true_type {};

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_frameworks_2fproto_5flogging_2fstats_2fenums_2fbluetooth_2fsmp_2fenums_2eproto