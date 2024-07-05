#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <iterator>
#include <new>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>

#include "init_flags.rs.h"

bool get_value_for_flag( std::string flag )
{
    return true;
}

#define INVOKE_FOR_FLAG() return get_value_for_flag(__FUNCTION__)

namespace bluetooth {
namespace common {
namespace init_flags {

void load( ::std::vector<::std::string> flags ) noexcept {
}

void set_all_for_testing() noexcept {
}

::std::vector<::bluetooth::common::init_flags::InitFlagWithValue> dump() noexcept {
  ::std::vector<::bluetooth::common::init_flags::InitFlagWithValue> ret;
  return ret;
}

bool always_send_services_if_gatt_disc_done_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

bool always_use_private_gatt_for_debugging_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

bool bluetooth_power_telemetry_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

bool btm_dm_flush_discovery_queue_on_search_cancel_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

bool classic_discovery_only_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

bool device_iot_config_logging_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

bool dynamic_avrcp_version_enhancement_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

bool gatt_robust_caching_server_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

::std::int32_t get_hci_adapter() noexcept {
    INVOKE_FOR_FLAG();
}

::std::int32_t get_asha_packet_drop_frequency_threshold() noexcept {
    INVOKE_FOR_FLAG();
}

::std::int32_t get_asha_phy_update_retry_limit() noexcept {
    INVOKE_FOR_FLAG();
}

bool hfp_dynamic_version_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

bool irk_rotation_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

bool leaudio_targeted_announcement_reconnection_mode_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

bool pbap_pse_dynamic_version_upgrade_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

bool redact_log_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

bool sco_codec_select_lc3_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

bool sco_codec_timeout_clear_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

bool sdp_serialization_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

bool sdp_skip_rnr_if_known_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

bool bluetooth_quality_report_callback_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

bool set_min_encryption_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

bool subrating_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

bool use_unified_connection_manager_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

bool sdp_return_classic_services_when_le_discovery_fails_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

bool use_rsi_from_cached_inqiry_results_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}

::std::int32_t get_att_mtu_default() noexcept {
    INVOKE_FOR_FLAG();
}

bool encryption_in_busy_state_is_enabled() noexcept {
    INVOKE_FOR_FLAG();
}
} // namespace init_flags
} // namespace common
} // namespace bluetooth

