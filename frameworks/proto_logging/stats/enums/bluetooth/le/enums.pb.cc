// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: frameworks/proto_logging/stats/enums/bluetooth/le/enums.proto

#include "frameworks/proto_logging/stats/enums/bluetooth/le/enums.pb.h"

#include <algorithm>
#include <cstdint>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace android {
namespace bluetooth {
namespace le {
}  // namespace le
}  // namespace bluetooth
}  // namespace android
namespace android {
namespace bluetooth {
namespace le {
bool LeAclConnectionState_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> LeAclConnectionState_strings[4] = {};

static const char LeAclConnectionState_names[] =
  "LE_ACL_ALREADY_PRESENT"
  "LE_ACL_FAILED"
  "LE_ACL_SUCCESS"
  "LE_ACL_UNSPECIFIED";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry LeAclConnectionState_entries[] = {
  { {LeAclConnectionState_names + 0, 22}, 3 },
  { {LeAclConnectionState_names + 22, 13}, 2 },
  { {LeAclConnectionState_names + 35, 14}, 1 },
  { {LeAclConnectionState_names + 49, 18}, 0 },
};

static const int LeAclConnectionState_entries_by_number[] = {
  3, // 0 -> LE_ACL_UNSPECIFIED
  2, // 1 -> LE_ACL_SUCCESS
  1, // 2 -> LE_ACL_FAILED
  0, // 3 -> LE_ACL_ALREADY_PRESENT
};

const std::string& LeAclConnectionState_Name(
    LeAclConnectionState value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          LeAclConnectionState_entries,
          LeAclConnectionState_entries_by_number,
          4, LeAclConnectionState_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      LeAclConnectionState_entries,
      LeAclConnectionState_entries_by_number,
      4, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     LeAclConnectionState_strings[idx].get();
}
bool LeAclConnectionState_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, LeAclConnectionState* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      LeAclConnectionState_entries, 4, name, &int_value);
  if (success) {
    *value = static_cast<LeAclConnectionState>(int_value);
  }
  return success;
}
bool LeConnectionOriginType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> LeConnectionOriginType_strings[3] = {};

static const char LeConnectionOriginType_names[] =
  "ORIGIN_JAVA"
  "ORIGIN_NATIVE"
  "ORIGIN_UNSPECIFIED";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry LeConnectionOriginType_entries[] = {
  { {LeConnectionOriginType_names + 0, 11}, 2 },
  { {LeConnectionOriginType_names + 11, 13}, 1 },
  { {LeConnectionOriginType_names + 24, 18}, 0 },
};

static const int LeConnectionOriginType_entries_by_number[] = {
  2, // 0 -> ORIGIN_UNSPECIFIED
  1, // 1 -> ORIGIN_NATIVE
  0, // 2 -> ORIGIN_JAVA
};

const std::string& LeConnectionOriginType_Name(
    LeConnectionOriginType value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          LeConnectionOriginType_entries,
          LeConnectionOriginType_entries_by_number,
          3, LeConnectionOriginType_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      LeConnectionOriginType_entries,
      LeConnectionOriginType_entries_by_number,
      3, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     LeConnectionOriginType_strings[idx].get();
}
bool LeConnectionOriginType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, LeConnectionOriginType* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      LeConnectionOriginType_entries, 3, name, &int_value);
  if (success) {
    *value = static_cast<LeConnectionOriginType>(int_value);
  }
  return success;
}
bool LeConnectionType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> LeConnectionType_strings[8] = {};

static const char LeConnectionType_names[] =
  "CONNECTION_TYPE_GATT"
  "CONNECTION_TYPE_L2CAP_FIXED_CHNL_AMP"
  "CONNECTION_TYPE_L2CAP_FIXED_CHNL_ATT"
  "CONNECTION_TYPE_L2CAP_FIXED_CHNL_LE_SIGNALLING"
  "CONNECTION_TYPE_L2CAP_FIXED_CHNL_SMP"
  "CONNECTION_TYPE_L2CAP_FIXED_CHNL_SMP_BR_EDR"
  "CONNECTION_TYPE_LE_ACL"
  "CONNECTION_TYPE_UNSPECIFIED";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry LeConnectionType_entries[] = {
  { {LeConnectionType_names + 0, 20}, 2 },
  { {LeConnectionType_names + 20, 36}, 6 },
  { {LeConnectionType_names + 56, 36}, 4 },
  { {LeConnectionType_names + 92, 46}, 5 },
  { {LeConnectionType_names + 138, 36}, 3 },
  { {LeConnectionType_names + 174, 43}, 7 },
  { {LeConnectionType_names + 217, 22}, 1 },
  { {LeConnectionType_names + 239, 27}, 0 },
};

static const int LeConnectionType_entries_by_number[] = {
  7, // 0 -> CONNECTION_TYPE_UNSPECIFIED
  6, // 1 -> CONNECTION_TYPE_LE_ACL
  0, // 2 -> CONNECTION_TYPE_GATT
  4, // 3 -> CONNECTION_TYPE_L2CAP_FIXED_CHNL_SMP
  2, // 4 -> CONNECTION_TYPE_L2CAP_FIXED_CHNL_ATT
  3, // 5 -> CONNECTION_TYPE_L2CAP_FIXED_CHNL_LE_SIGNALLING
  1, // 6 -> CONNECTION_TYPE_L2CAP_FIXED_CHNL_AMP
  5, // 7 -> CONNECTION_TYPE_L2CAP_FIXED_CHNL_SMP_BR_EDR
};

const std::string& LeConnectionType_Name(
    LeConnectionType value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          LeConnectionType_entries,
          LeConnectionType_entries_by_number,
          8, LeConnectionType_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      LeConnectionType_entries,
      LeConnectionType_entries_by_number,
      8, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     LeConnectionType_strings[idx].get();
}
bool LeConnectionType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, LeConnectionType* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      LeConnectionType_entries, 8, name, &int_value);
  if (success) {
    *value = static_cast<LeConnectionType>(int_value);
  }
  return success;
}
bool LeConnectionState_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> LeConnectionState_strings[15] = {};

static const char LeConnectionState_names[] =
  "STATE_GATT_APP_CREATE_LE_ACL"
  "STATE_GATT_APP_USE_LINK_FLAG"
  "STATE_GATT_CONNECT_NATIVE"
  "STATE_GATT_CONN_STATE_CHANGE_CLIENT"
  "STATE_GATT_CONN_STATE_CHANGE_SERVER"
  "STATE_GATT_CREATE_DIRECT_CONN"
  "STATE_GATT_HOLD_LINK_EMPTY"
  "STATE_L2CAP_FIXED_CHNL_LE_ACL_FINISH"
  "STATE_L2CAP_FIXED_CHNL_START_CREATE_CONN"
  "STATE_L2CAP_FIXED_CHNL_START_LE_ACL"
  "STATE_LE_ACL_CANCEL"
  "STATE_LE_ACL_END"
  "STATE_LE_ACL_START"
  "STATE_LE_ACL_TIMEOUT"
  "STATE_UNSPECIFIED";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry LeConnectionState_entries[] = {
  { {LeConnectionState_names + 0, 28}, 9 },
  { {LeConnectionState_names + 28, 28}, 5 },
  { {LeConnectionState_names + 56, 25}, 8 },
  { {LeConnectionState_names + 81, 35}, 10 },
  { {LeConnectionState_names + 116, 35}, 11 },
  { {LeConnectionState_names + 151, 29}, 6 },
  { {LeConnectionState_names + 180, 26}, 7 },
  { {LeConnectionState_names + 206, 36}, 14 },
  { {LeConnectionState_names + 242, 40}, 12 },
  { {LeConnectionState_names + 282, 35}, 13 },
  { {LeConnectionState_names + 317, 19}, 3 },
  { {LeConnectionState_names + 336, 16}, 2 },
  { {LeConnectionState_names + 352, 18}, 1 },
  { {LeConnectionState_names + 370, 20}, 4 },
  { {LeConnectionState_names + 390, 17}, 0 },
};

static const int LeConnectionState_entries_by_number[] = {
  14, // 0 -> STATE_UNSPECIFIED
  12, // 1 -> STATE_LE_ACL_START
  11, // 2 -> STATE_LE_ACL_END
  10, // 3 -> STATE_LE_ACL_CANCEL
  13, // 4 -> STATE_LE_ACL_TIMEOUT
  1, // 5 -> STATE_GATT_APP_USE_LINK_FLAG
  5, // 6 -> STATE_GATT_CREATE_DIRECT_CONN
  6, // 7 -> STATE_GATT_HOLD_LINK_EMPTY
  2, // 8 -> STATE_GATT_CONNECT_NATIVE
  0, // 9 -> STATE_GATT_APP_CREATE_LE_ACL
  3, // 10 -> STATE_GATT_CONN_STATE_CHANGE_CLIENT
  4, // 11 -> STATE_GATT_CONN_STATE_CHANGE_SERVER
  8, // 12 -> STATE_L2CAP_FIXED_CHNL_START_CREATE_CONN
  9, // 13 -> STATE_L2CAP_FIXED_CHNL_START_LE_ACL
  7, // 14 -> STATE_L2CAP_FIXED_CHNL_LE_ACL_FINISH
};

const std::string& LeConnectionState_Name(
    LeConnectionState value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          LeConnectionState_entries,
          LeConnectionState_entries_by_number,
          15, LeConnectionState_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      LeConnectionState_entries,
      LeConnectionState_entries_by_number,
      15, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     LeConnectionState_strings[idx].get();
}
bool LeConnectionState_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, LeConnectionState* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      LeConnectionState_entries, 15, name, &int_value);
  if (success) {
    *value = static_cast<LeConnectionState>(int_value);
  }
  return success;
}
bool LeScanCallbackType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 8:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> LeScanCallbackType_strings[5] = {};

static const char LeScanCallbackType_names[] =
  "TYPE_ALL_MATCHES"
  "TYPE_ALL_MATCHES_AUTO_BATCH"
  "TYPE_FIRST_MATCH"
  "TYPE_MATCH_LOST"
  "TYPE_UNKNOWN";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry LeScanCallbackType_entries[] = {
  { {LeScanCallbackType_names + 0, 16}, 1 },
  { {LeScanCallbackType_names + 16, 27}, 8 },
  { {LeScanCallbackType_names + 43, 16}, 2 },
  { {LeScanCallbackType_names + 59, 15}, 4 },
  { {LeScanCallbackType_names + 74, 12}, 0 },
};

static const int LeScanCallbackType_entries_by_number[] = {
  4, // 0 -> TYPE_UNKNOWN
  0, // 1 -> TYPE_ALL_MATCHES
  2, // 2 -> TYPE_FIRST_MATCH
  3, // 4 -> TYPE_MATCH_LOST
  1, // 8 -> TYPE_ALL_MATCHES_AUTO_BATCH
};

const std::string& LeScanCallbackType_Name(
    LeScanCallbackType value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          LeScanCallbackType_entries,
          LeScanCallbackType_entries_by_number,
          5, LeScanCallbackType_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      LeScanCallbackType_entries,
      LeScanCallbackType_entries_by_number,
      5, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     LeScanCallbackType_strings[idx].get();
}
bool LeScanCallbackType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, LeScanCallbackType* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      LeScanCallbackType_entries, 5, name, &int_value);
  if (success) {
    *value = static_cast<LeScanCallbackType>(int_value);
  }
  return success;
}
bool LeScanType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> LeScanType_strings[4] = {};

static const char LeScanType_names[] =
  "SCAN_TYPE_AUTO_BATCH"
  "SCAN_TYPE_BATCH"
  "SCAN_TYPE_REGULAR"
  "SCAN_TYPE_UNKNOWN";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry LeScanType_entries[] = {
  { {LeScanType_names + 0, 20}, 3 },
  { {LeScanType_names + 20, 15}, 2 },
  { {LeScanType_names + 35, 17}, 1 },
  { {LeScanType_names + 52, 17}, 0 },
};

static const int LeScanType_entries_by_number[] = {
  3, // 0 -> SCAN_TYPE_UNKNOWN
  2, // 1 -> SCAN_TYPE_REGULAR
  1, // 2 -> SCAN_TYPE_BATCH
  0, // 3 -> SCAN_TYPE_AUTO_BATCH
};

const std::string& LeScanType_Name(
    LeScanType value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          LeScanType_entries,
          LeScanType_entries_by_number,
          4, LeScanType_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      LeScanType_entries,
      LeScanType_entries_by_number,
      4, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     LeScanType_strings[idx].get();
}
bool LeScanType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, LeScanType* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      LeScanType_entries, 4, name, &int_value);
  if (success) {
    *value = static_cast<LeScanType>(int_value);
  }
  return success;
}
bool LeScanMode_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 20:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> LeScanMode_strings[9] = {};

static const char LeScanMode_names[] =
  "SCAN_MODE_AMBIENT_DISCOVERY"
  "SCAN_MODE_BALANCED"
  "SCAN_MODE_CUSTOM"
  "SCAN_MODE_LOW_LATENCY"
  "SCAN_MODE_LOW_POWER"
  "SCAN_MODE_OPPORTUNISTIC"
  "SCAN_MODE_SCREEN_OFF"
  "SCAN_MODE_SCREEN_OFF_BALANCED"
  "SCAN_MODE_UNKNOWN";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry LeScanMode_entries[] = {
  { {LeScanMode_names + 0, 27}, 5 },
  { {LeScanMode_names + 27, 18}, 3 },
  { {LeScanMode_names + 45, 16}, 20 },
  { {LeScanMode_names + 61, 21}, 4 },
  { {LeScanMode_names + 82, 19}, 2 },
  { {LeScanMode_names + 101, 23}, 1 },
  { {LeScanMode_names + 124, 20}, 6 },
  { {LeScanMode_names + 144, 29}, 7 },
  { {LeScanMode_names + 173, 17}, 0 },
};

static const int LeScanMode_entries_by_number[] = {
  8, // 0 -> SCAN_MODE_UNKNOWN
  5, // 1 -> SCAN_MODE_OPPORTUNISTIC
  4, // 2 -> SCAN_MODE_LOW_POWER
  1, // 3 -> SCAN_MODE_BALANCED
  3, // 4 -> SCAN_MODE_LOW_LATENCY
  0, // 5 -> SCAN_MODE_AMBIENT_DISCOVERY
  6, // 6 -> SCAN_MODE_SCREEN_OFF
  7, // 7 -> SCAN_MODE_SCREEN_OFF_BALANCED
  2, // 20 -> SCAN_MODE_CUSTOM
};

const std::string& LeScanMode_Name(
    LeScanMode value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          LeScanMode_entries,
          LeScanMode_entries_by_number,
          9, LeScanMode_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      LeScanMode_entries,
      LeScanMode_entries_by_number,
      9, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     LeScanMode_strings[idx].get();
}
bool LeScanMode_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, LeScanMode* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      LeScanMode_entries, 9, name, &int_value);
  if (success) {
    *value = static_cast<LeScanMode>(int_value);
  }
  return success;
}
bool LeScanAbuseReason_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> LeScanAbuseReason_strings[4] = {};

static const char LeScanAbuseReason_names[] =
  "REASON_HW_FILTER_NA"
  "REASON_SCAN_TIMEOUT"
  "REASON_TRACKING_HW_FILTER_NA"
  "REASON_UNKNOWN";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry LeScanAbuseReason_entries[] = {
  { {LeScanAbuseReason_names + 0, 19}, 2 },
  { {LeScanAbuseReason_names + 19, 19}, 1 },
  { {LeScanAbuseReason_names + 38, 28}, 3 },
  { {LeScanAbuseReason_names + 66, 14}, 0 },
};

static const int LeScanAbuseReason_entries_by_number[] = {
  3, // 0 -> REASON_UNKNOWN
  1, // 1 -> REASON_SCAN_TIMEOUT
  0, // 2 -> REASON_HW_FILTER_NA
  2, // 3 -> REASON_TRACKING_HW_FILTER_NA
};

const std::string& LeScanAbuseReason_Name(
    LeScanAbuseReason value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          LeScanAbuseReason_entries,
          LeScanAbuseReason_entries_by_number,
          4, LeScanAbuseReason_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      LeScanAbuseReason_entries,
      LeScanAbuseReason_entries_by_number,
      4, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     LeScanAbuseReason_strings[idx].get();
}
bool LeScanAbuseReason_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, LeScanAbuseReason* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      LeScanAbuseReason_entries, 4, name, &int_value);
  if (success) {
    *value = static_cast<LeScanAbuseReason>(int_value);
  }
  return success;
}
bool LeAdvInterval_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> LeAdvInterval_strings[4] = {};

static const char LeAdvInterval_names[] =
  "INTERVAL_HIGH"
  "INTERVAL_LOW"
  "INTERVAL_MEDIUM"
  "INTERVAL_UNKNOWN";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry LeAdvInterval_entries[] = {
  { {LeAdvInterval_names + 0, 13}, 1 },
  { {LeAdvInterval_names + 13, 12}, 3 },
  { {LeAdvInterval_names + 25, 15}, 2 },
  { {LeAdvInterval_names + 40, 16}, 0 },
};

static const int LeAdvInterval_entries_by_number[] = {
  3, // 0 -> INTERVAL_UNKNOWN
  0, // 1 -> INTERVAL_HIGH
  2, // 2 -> INTERVAL_MEDIUM
  1, // 3 -> INTERVAL_LOW
};

const std::string& LeAdvInterval_Name(
    LeAdvInterval value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          LeAdvInterval_entries,
          LeAdvInterval_entries_by_number,
          4, LeAdvInterval_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      LeAdvInterval_entries,
      LeAdvInterval_entries_by_number,
      4, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     LeAdvInterval_strings[idx].get();
}
bool LeAdvInterval_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, LeAdvInterval* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      LeAdvInterval_entries, 4, name, &int_value);
  if (success) {
    *value = static_cast<LeAdvInterval>(int_value);
  }
  return success;
}
bool LeAdvTxPower_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> LeAdvTxPower_strings[5] = {};

static const char LeAdvTxPower_names[] =
  "TX_POWER_HIGH"
  "TX_POWER_LOW"
  "TX_POWER_MEDIUM"
  "TX_POWER_ULTRA_LOW"
  "TX_POWER_UNKNOWN";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry LeAdvTxPower_entries[] = {
  { {LeAdvTxPower_names + 0, 13}, 4 },
  { {LeAdvTxPower_names + 13, 12}, 2 },
  { {LeAdvTxPower_names + 25, 15}, 3 },
  { {LeAdvTxPower_names + 40, 18}, 1 },
  { {LeAdvTxPower_names + 58, 16}, 0 },
};

static const int LeAdvTxPower_entries_by_number[] = {
  4, // 0 -> TX_POWER_UNKNOWN
  3, // 1 -> TX_POWER_ULTRA_LOW
  1, // 2 -> TX_POWER_LOW
  2, // 3 -> TX_POWER_MEDIUM
  0, // 4 -> TX_POWER_HIGH
};

const std::string& LeAdvTxPower_Name(
    LeAdvTxPower value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          LeAdvTxPower_entries,
          LeAdvTxPower_entries_by_number,
          5, LeAdvTxPower_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      LeAdvTxPower_entries,
      LeAdvTxPower_entries_by_number,
      5, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     LeAdvTxPower_strings[idx].get();
}
bool LeAdvTxPower_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, LeAdvTxPower* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      LeAdvTxPower_entries, 5, name, &int_value);
  if (success) {
    *value = static_cast<LeAdvTxPower>(int_value);
  }
  return success;
}
bool LeAdvOpCode_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> LeAdvOpCode_strings[2] = {};

static const char LeAdvOpCode_names[] =
  "ERROR_CODE_ON_START"
  "ERROR_CODE_UNKNOWN";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry LeAdvOpCode_entries[] = {
  { {LeAdvOpCode_names + 0, 19}, 1 },
  { {LeAdvOpCode_names + 19, 18}, 0 },
};

static const int LeAdvOpCode_entries_by_number[] = {
  1, // 0 -> ERROR_CODE_UNKNOWN
  0, // 1 -> ERROR_CODE_ON_START
};

const std::string& LeAdvOpCode_Name(
    LeAdvOpCode value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          LeAdvOpCode_entries,
          LeAdvOpCode_entries_by_number,
          2, LeAdvOpCode_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      LeAdvOpCode_entries,
      LeAdvOpCode_entries_by_number,
      2, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     LeAdvOpCode_strings[idx].get();
}
bool LeAdvOpCode_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, LeAdvOpCode* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      LeAdvOpCode_entries, 2, name, &int_value);
  if (success) {
    *value = static_cast<LeAdvOpCode>(int_value);
  }
  return success;
}
bool LeAdvStatusCode_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> LeAdvStatusCode_strings[7] = {};

static const char LeAdvStatusCode_names[] =
  "ADV_STATUS_FAILED_ALREADY_STARTED"
  "ADV_STATUS_FAILED_DATA_TOO_LARGE"
  "ADV_STATUS_FAILED_FEATURE_UNSUPPORTED"
  "ADV_STATUS_FAILED_INTERNAL_ERROR"
  "ADV_STATUS_FAILED_TOO_MANY_ADVERTISERS"
  "ADV_STATUS_SUCCESS"
  "ADV_STATUS_UNKNOWN";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry LeAdvStatusCode_entries[] = {
  { {LeAdvStatusCode_names + 0, 33}, 4 },
  { {LeAdvStatusCode_names + 33, 32}, 2 },
  { {LeAdvStatusCode_names + 65, 37}, 6 },
  { {LeAdvStatusCode_names + 102, 32}, 5 },
  { {LeAdvStatusCode_names + 134, 38}, 3 },
  { {LeAdvStatusCode_names + 172, 18}, 1 },
  { {LeAdvStatusCode_names + 190, 18}, 0 },
};

static const int LeAdvStatusCode_entries_by_number[] = {
  6, // 0 -> ADV_STATUS_UNKNOWN
  5, // 1 -> ADV_STATUS_SUCCESS
  1, // 2 -> ADV_STATUS_FAILED_DATA_TOO_LARGE
  4, // 3 -> ADV_STATUS_FAILED_TOO_MANY_ADVERTISERS
  0, // 4 -> ADV_STATUS_FAILED_ALREADY_STARTED
  3, // 5 -> ADV_STATUS_FAILED_INTERNAL_ERROR
  2, // 6 -> ADV_STATUS_FAILED_FEATURE_UNSUPPORTED
};

const std::string& LeAdvStatusCode_Name(
    LeAdvStatusCode value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          LeAdvStatusCode_entries,
          LeAdvStatusCode_entries_by_number,
          7, LeAdvStatusCode_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      LeAdvStatusCode_entries,
      LeAdvStatusCode_entries_by_number,
      7, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     LeAdvStatusCode_strings[idx].get();
}
bool LeAdvStatusCode_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, LeAdvStatusCode* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      LeAdvStatusCode_entries, 7, name, &int_value);
  if (success) {
    *value = static_cast<LeAdvStatusCode>(int_value);
  }
  return success;
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace le
}  // namespace bluetooth
}  // namespace android
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>