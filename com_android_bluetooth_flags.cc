#include "com_android_bluetooth_flags.h"

#if __has_include(<unistd.h>)
#include <unistd.h>
#endif
#include "aconfig_storage/aconfig_storage_read_api.hpp"
#include <android/log.h>
#define LOG_TAG "aconfig_cpp_codegen"
#define ALOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#include <atomic>
#include <vector>

namespace com::android::bluetooth::flags {

class flag_provider : public flag_provider_interface {
    public:

        flag_provider()
            : cache_(305)
            , boolean_start_index_()
            , flag_value_file_(nullptr)
            , package_exists_in_storage_(true)
            , fingerprint_matches_(true) {
            for (size_t i = 0 ; i < 305; i++) {
                cache_[i] = -1;
            }

// Storage files are only available on Android, not on host.
#ifndef __ANDROID__
            package_exists_in_storage_ = false;
            return;
#endif
            auto package_map_file_ret = aconfig_storage::get_mapped_file(
                 "com.android.bt",
                 aconfig_storage::StorageFileType::package_map);
            if (!package_map_file_ret.ok()) {
                ALOGE("error: failed to get package map file: %s", package_map_file_ret.error().c_str());
                package_exists_in_storage_ = false;
                return;
            }
            std::unique_ptr<aconfig_storage::MappedStorageFile> package_map_file(*package_map_file_ret);
            auto context = aconfig_storage::get_package_read_context(
                *package_map_file, "com.android.bluetooth.flags");
            if (!context.ok()) {
                ALOGE("error: failed to get package read context: %s", context.error().c_str());
                package_exists_in_storage_ = false;
                return;
            }

            if (!(context->package_exists)) {
                package_exists_in_storage_ = false;
                return;
            }
            if (context->fingerprint != 10916040903694006921ULL) {
                    ALOGE("Fingerprint mismatch for package com.android.bluetooth.flags.");
                    fingerprint_matches_ = false;
                    return;
                }

            // cache package boolean flag start index
            boolean_start_index_ = context->boolean_start_index;

            auto flag_value_file = aconfig_storage::get_mapped_file(
                "com.android.bt",
                aconfig_storage::StorageFileType::flag_val);
            if (!flag_value_file.ok()) {
                ALOGE("error: failed to get flag value file: %s", flag_value_file.error().c_str());
                package_exists_in_storage_ = false;
                return;
            }

            // cache flag value file
            flag_value_file_ = std::unique_ptr<aconfig_storage::MappedStorageFile>(
                *flag_value_file);

        }
        virtual bool a2dp_adjust_sbc_bitpool() override {
            if (cache_[0].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 0);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[0].store(*value, std::memory_order_relaxed);
            }
            return cache_[0].load(std::memory_order_relaxed);
        }
        virtual bool a2dp_cancel_acceptor_alarm_for_avdt_init() override {
            if (cache_[1].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 1);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[1].store(*value, std::memory_order_relaxed);
            }
            return cache_[1].load(std::memory_order_relaxed);
        }
        virtual bool a2dp_delay_disconnect() override {
            if (cache_[2].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 2);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[2].store(*value, std::memory_order_relaxed);
            }
            return cache_[2].load(std::memory_order_relaxed);
        }
        virtual bool a2dp_delay_report_in_dumpsys() override {
            if (cache_[3].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 3);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[3].store(*value, std::memory_order_relaxed);
            }
            return cache_[3].load(std::memory_order_relaxed);
        }
        virtual bool a2dp_disconnect_reason_api() override {
            if (cache_[4].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 4);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[4].store(*value, std::memory_order_relaxed);
            }
            return cache_[4].load(std::memory_order_relaxed);
        }
        virtual bool a2dp_fmq_read_exact() override {
            if (cache_[5].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 5);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[5].store(*value, std::memory_order_relaxed);
            }
            return cache_[5].load(std::memory_order_relaxed);
        }
        virtual bool a2dp_lhdc_api() override {
            if (cache_[6].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 6);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[6].store(*value, std::memory_order_relaxed);
            }
            return cache_[6].load(std::memory_order_relaxed);
        }
        virtual bool a2dp_pm_app_id() override {
            if (cache_[7].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 7);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[7].store(*value, std::memory_order_relaxed);
            }
            return cache_[7].load(std::memory_order_relaxed);
        }
        virtual bool a2dp_reject_sho_request() override {
            if (cache_[8].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 8);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[8].store(*value, std::memory_order_relaxed);
            }
            return cache_[8].load(std::memory_order_relaxed);
        }
        virtual bool a2dp_sbc_underflow_recovery() override {
            if (cache_[9].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 9);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[9].store(*value, std::memory_order_relaxed);
            }
            return cache_[9].load(std::memory_order_relaxed);
        }
        virtual bool a2dp_set_configuration_during_discovery() override {
            if (cache_[10].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 10);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[10].store(*value, std::memory_order_relaxed);
            }
            return cache_[10].load(std::memory_order_relaxed);
        }
        virtual bool a2dp_source_null_fixed_queue() override {
            if (cache_[11].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 11);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[11].store(*value, std::memory_order_relaxed);
            }
            return cache_[11].load(std::memory_order_relaxed);
        }
        virtual bool abs_volume_sdp_conflict() override {
            if (cache_[12].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 12);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[12].store(*value, std::memory_order_relaxed);
            }
            return cache_[12].load(std::memory_order_relaxed);
        }
        virtual bool acl_fix_in_and_out_connection_reqs() override {
            if (cache_[13].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 13);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[13].store(*value, std::memory_order_relaxed);
            }
            return cache_[13].load(std::memory_order_relaxed);
        }
        virtual bool adapter_suspend_advertisement() override {
            if (cache_[14].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 14);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[14].store(*value, std::memory_order_relaxed);
            }
            return cache_[14].load(std::memory_order_relaxed);
        }
        virtual bool adapter_suspend_discoverability() override {
            if (cache_[15].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 15);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[15].store(*value, std::memory_order_relaxed);
            }
            return cache_[15].load(std::memory_order_relaxed);
        }
        virtual bool adapter_suspend_mgmt() override {
            if (cache_[16].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 16);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[16].store(*value, std::memory_order_relaxed);
            }
            return cache_[16].load(std::memory_order_relaxed);
        }
        virtual bool add_bond_loss_reason() override {
            if (cache_[17].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 17);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[17].store(*value, std::memory_order_relaxed);
            }
            return cache_[17].load(std::memory_order_relaxed);
        }
        virtual bool add_hop_to_event_callback() override {
            if (cache_[18].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 18);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[18].store(*value, std::memory_order_relaxed);
            }
            return cache_[18].load(std::memory_order_relaxed);
        }
        virtual bool add_profile_as_intent_extra() override {
            if (cache_[19].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 19);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[19].store(*value, std::memory_order_relaxed);
            }
            return cache_[19].load(std::memory_order_relaxed);
        }
        virtual bool adm_centralize_active_device_handling() override {
            if (cache_[20].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 20);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[20].store(*value, std::memory_order_relaxed);
            }
            return cache_[20].load(std::memory_order_relaxed);
        }
        virtual bool adm_remove_handling_wired() override {
            if (cache_[21].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 21);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[21].store(*value, std::memory_order_relaxed);
            }
            return cache_[21].load(std::memory_order_relaxed);
        }
        virtual bool adm_unset_others_on_hfp_changed() override {
            if (cache_[22].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 22);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[22].store(*value, std::memory_order_relaxed);
            }
            return cache_[22].load(std::memory_order_relaxed);
        }
        virtual bool aics_api() override {
            if (cache_[23].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 23);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[23].store(*value, std::memory_order_relaxed);
            }
            return cache_[23].load(std::memory_order_relaxed);
        }
        virtual bool allow_rearm_if_suspend_scan_params_used() override {
            if (cache_[24].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 24);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[24].store(*value, std::memory_order_relaxed);
            }
            return cache_[24].load(std::memory_order_relaxed);
        }
        virtual bool allow_switching_hid_and_hogp() override {
            if (cache_[25].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 25);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[25].store(*value, std::memory_order_relaxed);
            }
            return cache_[25].load(std::memory_order_relaxed);
        }
        virtual bool always_set_identity_addr() override {
            if (cache_[26].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 26);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[26].store(*value, std::memory_order_relaxed);
            }
            return cache_[26].load(std::memory_order_relaxed);
        }
        virtual bool asha_omit_gatt_after_svc_changed() override {
            if (cache_[27].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 27);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[27].store(*value, std::memory_order_relaxed);
            }
            return cache_[27].load(std::memory_order_relaxed);
        }
        virtual bool avdt_close_on_start_failure_bad_state() override {
            if (cache_[28].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 28);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[28].store(*value, std::memory_order_relaxed);
            }
            return cache_[28].load(std::memory_order_relaxed);
        }
        virtual bool avdt_wait_for_initial_delay_report_as_initiator() override {
            if (cache_[29].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 29);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[29].store(*value, std::memory_order_relaxed);
            }
            return cache_[29].load(std::memory_order_relaxed);
        }
        virtual bool avoid_ctkd_for_temp_pairing() override {
            if (cache_[30].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 30);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[30].store(*value, std::memory_order_relaxed);
            }
            return cache_[30].load(std::memory_order_relaxed);
        }
        virtual bool avoid_l2c_processing_while_stack_shutdown() override {
            if (cache_[31].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 31);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[31].store(*value, std::memory_order_relaxed);
            }
            return cache_[31].load(std::memory_order_relaxed);
        }
        virtual bool avrcp_16_default() override {
            if (cache_[32].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 32);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[32].store(*value, std::memory_order_relaxed);
            }
            return cache_[32].load(std::memory_order_relaxed);
        }
        virtual bool batch_scan_support_check() override {
            if (cache_[33].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 33);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[33].store(*value, std::memory_order_relaxed);
            }
            return cache_[33].load(std::memory_order_relaxed);
        }
        virtual bool ble_rnr_when_connected() override {
            if (cache_[34].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 34);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[34].store(*value, std::memory_order_relaxed);
            }
            return cache_[34].load(std::memory_order_relaxed);
        }
        virtual bool bluetooth_power_telemetry() override {
            if (cache_[35].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 35);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[35].store(*value, std::memory_order_relaxed);
            }
            return cache_[35].load(std::memory_order_relaxed);
        }
        virtual bool bond_loss_transport_check() override {
            if (cache_[36].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 36);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[36].store(*value, std::memory_order_relaxed);
            }
            return cache_[36].load(std::memory_order_relaxed);
        }
        virtual bool bond_state_machine_looper() override {
            if (cache_[37].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 37);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[37].store(*value, std::memory_order_relaxed);
            }
            return cache_[37].load(std::memory_order_relaxed);
        }
        virtual bool bonding_initiator_state_reset() override {
            if (cache_[38].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 38);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[38].store(*value, std::memory_order_relaxed);
            }
            return cache_[38].load(std::memory_order_relaxed);
        }
        virtual bool bqr_common_part_unified_length() override {
            if (cache_[39].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 39);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[39].store(*value, std::memory_order_relaxed);
            }
            return cache_[39].load(std::memory_order_relaxed);
        }
        virtual bool br_edr_discover_gatt_services_over_gatt() override {
            if (cache_[40].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 40);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[40].store(*value, std::memory_order_relaxed);
            }
            return cache_[40].load(std::memory_order_relaxed);
        }
        virtual bool broadcast_transport_type_on_reset() override {
            if (cache_[41].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 41);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[41].store(*value, std::memory_order_relaxed);
            }
            return cache_[41].load(std::memory_order_relaxed);
        }
        virtual bool bt_offload_socket_api() override {
            if (cache_[42].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 42);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[42].store(*value, std::memory_order_relaxed);
            }
            return cache_[42].load(std::memory_order_relaxed);
        }
        virtual bool bt_socket_api_l2cap_cid() override {
            if (cache_[43].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 43);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[43].store(*value, std::memory_order_relaxed);
            }
            return cache_[43].load(std::memory_order_relaxed);
        }
        virtual bool btsec_check_controller_sc_support() override {
            if (cache_[44].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 44);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[44].store(*value, std::memory_order_relaxed);
            }
            return cache_[44].load(std::memory_order_relaxed);
        }
        virtual bool btsec_cycle_irks() override {
            if (cache_[45].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 45);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[45].store(*value, std::memory_order_relaxed);
            }
            return cache_[45].load(std::memory_order_relaxed);
        }
        virtual bool call_sdp_free_in_main_thread() override {
            if (cache_[46].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 46);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[46].store(*value, std::memory_order_relaxed);
            }
            return cache_[46].load(std::memory_order_relaxed);
        }
        virtual bool channel_sounding() override {
            if (cache_[47].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 47);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[47].store(*value, std::memory_order_relaxed);
            }
            return cache_[47].load(std::memory_order_relaxed);
        }
        virtual bool channel_sounding_25q2_apis() override {
            if (cache_[48].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 48);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[48].store(*value, std::memory_order_relaxed);
            }
            return cache_[48].load(std::memory_order_relaxed);
        }
        virtual bool channel_sounding_offload() override {
            if (cache_[49].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 49);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[49].store(*value, std::memory_order_relaxed);
            }
            return cache_[49].load(std::memory_order_relaxed);
        }
        virtual bool check_call_state_atd() override {
            if (cache_[50].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 50);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[50].store(*value, std::memory_order_relaxed);
            }
            return cache_[50].load(std::memory_order_relaxed);
        }
        virtual bool check_l2c_conn_status_before_param_validation() override {
            if (cache_[51].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 51);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[51].store(*value, std::memory_order_relaxed);
            }
            return cache_[51].load(std::memory_order_relaxed);
        }
        virtual bool check_peer_hf_indicator() override {
            if (cache_[52].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 52);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[52].store(*value, std::memory_order_relaxed);
            }
            return cache_[52].load(std::memory_order_relaxed);
        }
        virtual bool clear_pairing_state_when_no_devrec() override {
            if (cache_[53].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 53);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[53].store(*value, std::memory_order_relaxed);
            }
            return cache_[53].load(std::memory_order_relaxed);
        }
        virtual bool complete_disc_if_no_rnr() override {
            if (cache_[54].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 54);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[54].store(*value, std::memory_order_relaxed);
            }
            return cache_[54].load(std::memory_order_relaxed);
        }
        virtual bool conclude_le_pairing_immediately() override {
            if (cache_[55].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 55);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[55].store(*value, std::memory_order_relaxed);
            }
            return cache_[55].load(std::memory_order_relaxed);
        }
        virtual bool concurrent_incoming_outgoing_pairing() override {
            if (cache_[56].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 56);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[56].store(*value, std::memory_order_relaxed);
            }
            return cache_[56].load(std::memory_order_relaxed);
        }
        virtual bool consider_l2c_header_bytes_for_mps_selection() override {
            if (cache_[57].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 57);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[57].store(*value, std::memory_order_relaxed);
            }
            return cache_[57].load(std::memory_order_relaxed);
        }
        virtual bool consistent_battery_level() override {
            if (cache_[58].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 58);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[58].store(*value, std::memory_order_relaxed);
            }
            return cache_[58].load(std::memory_order_relaxed);
        }
        virtual bool continue_queued_command_after_discovery() override {
            if (cache_[59].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 59);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[59].store(*value, std::memory_order_relaxed);
            }
            return cache_[59].load(std::memory_order_relaxed);
        }
        virtual bool delay_jv_pm_idle() override {
            if (cache_[60].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 60);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[60].store(*value, std::memory_order_relaxed);
            }
            return cache_[60].load(std::memory_order_relaxed);
        }
        virtual bool delay_offload_le_coc_connection_ind() override {
            if (cache_[61].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 61);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[61].store(*value, std::memory_order_relaxed);
            }
            return cache_[61].load(std::memory_order_relaxed);
        }
        virtual bool delay_sniff_subrating() override {
            if (cache_[62].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 62);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[62].store(*value, std::memory_order_relaxed);
            }
            return cache_[62].load(std::memory_order_relaxed);
        }
        virtual bool directed_advertising_api() override {
            if (cache_[63].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 63);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[63].store(*value, std::memory_order_relaxed);
            }
            return cache_[63].load(std::memory_order_relaxed);
        }
        virtual bool disconnect_acl_on_gatt_timeout() override {
            if (cache_[64].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 64);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[64].store(*value, std::memory_order_relaxed);
            }
            return cache_[64].load(std::memory_order_relaxed);
        }
        virtual bool disconnect_acls_by_bredr_disabled() override {
            if (cache_[65].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 65);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[65].store(*value, std::memory_order_relaxed);
            }
            return cache_[65].load(std::memory_order_relaxed);
        }
        virtual bool distance_measurement_thread() override {
            if (cache_[66].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 66);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[66].store(*value, std::memory_order_relaxed);
            }
            return cache_[66].load(std::memory_order_relaxed);
        }
        virtual bool do_not_dump_devices_from_adapter_properties() override {
            if (cache_[67].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 67);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[67].store(*value, std::memory_order_relaxed);
            }
            return cache_[67].load(std::memory_order_relaxed);
        }
        virtual bool do_not_hardcode_tmap_role_mask() override {
            if (cache_[68].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 68);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[68].store(*value, std::memory_order_relaxed);
            }
            return cache_[68].load(std::memory_order_relaxed);
        }
        virtual bool donot_collide_with_closed_port() override {
            if (cache_[69].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 69);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[69].store(*value, std::memory_order_relaxed);
            }
            return cache_[69].load(std::memory_order_relaxed);
        }
        virtual bool donot_mandate_auth_along_with_encryption() override {
            if (cache_[70].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 70);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[70].store(*value, std::memory_order_relaxed);
            }
            return cache_[70].load(std::memory_order_relaxed);
        }
        virtual bool donot_pm_classic_on_le_traffic() override {
            if (cache_[71].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 71);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[71].store(*value, std::memory_order_relaxed);
            }
            return cache_[71].load(std::memory_order_relaxed);
        }
        virtual bool dont_send_hci_disconnect_repeatedly() override {
            if (cache_[72].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 72);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[72].store(*value, std::memory_order_relaxed);
            }
            return cache_[72].load(std::memory_order_relaxed);
        }
        virtual bool downgrade_to_basic_mode_on_no_info_resp() override {
            if (cache_[73].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 73);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[73].store(*value, std::memory_order_relaxed);
            }
            return cache_[73].load(std::memory_order_relaxed);
        }
        virtual bool dsa_use_codec_extensibility() override {
            if (cache_[74].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 74);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[74].store(*value, std::memory_order_relaxed);
            }
            return cache_[74].load(std::memory_order_relaxed);
        }
        virtual bool dump_without_promise_timeout() override {
            if (cache_[75].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 75);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[75].store(*value, std::memory_order_relaxed);
            }
            return cache_[75].load(std::memory_order_relaxed);
        }
        virtual bool early_incoming_hid_connection() override {
            if (cache_[76].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 76);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[76].store(*value, std::memory_order_relaxed);
            }
            return cache_[76].load(std::memory_order_relaxed);
        }
        virtual bool enable_battery_level_update_only_through_hf_indicator() override {
            if (cache_[77].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 77);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[77].store(*value, std::memory_order_relaxed);
            }
            return cache_[77].load(std::memory_order_relaxed);
        }
        virtual bool encryption_change_broadcast() override {
            if (cache_[78].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 78);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[78].store(*value, std::memory_order_relaxed);
            }
            return cache_[78].load(std::memory_order_relaxed);
        }
        virtual bool end_outgoing_call_on_chld() override {
            if (cache_[79].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 79);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[79].store(*value, std::memory_order_relaxed);
            }
            return cache_[79].load(std::memory_order_relaxed);
        }
        virtual bool ensure_acl_connection_is_removed_from_pending_list() override {
            if (cache_[80].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 80);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[80].store(*value, std::memory_order_relaxed);
            }
            return cache_[80].load(std::memory_order_relaxed);
        }
        virtual bool extend_and_randomize_role_switch_delay() override {
            if (cache_[81].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 81);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[81].store(*value, std::memory_order_relaxed);
            }
            return cache_[81].load(std::memory_order_relaxed);
        }
        virtual bool fix_buf_len_check_for_first_k_frame() override {
            if (cache_[82].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 82);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[82].store(*value, std::memory_order_relaxed);
            }
            return cache_[82].load(std::memory_order_relaxed);
        }
        virtual bool fix_event_handler_reg_and_dereg() override {
            if (cache_[83].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 83);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[83].store(*value, std::memory_order_relaxed);
            }
            return cache_[83].load(std::memory_order_relaxed);
        }
        virtual bool fix_hfp_qual_1_9() override {
            if (cache_[84].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 84);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[84].store(*value, std::memory_order_relaxed);
            }
            return cache_[84].load(std::memory_order_relaxed);
        }
        virtual bool fix_hfp_rfcomm_collision_state_machine_error() override {
            if (cache_[85].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 85);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[85].store(*value, std::memory_order_relaxed);
            }
            return cache_[85].load(std::memory_order_relaxed);
        }
        virtual bool fix_lecoc_socket_available() override {
            if (cache_[86].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 86);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[86].store(*value, std::memory_order_relaxed);
            }
            return cache_[86].load(std::memory_order_relaxed);
        }
        virtual bool fix_ongoing_rnr_while_bonding() override {
            if (cache_[87].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 87);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[87].store(*value, std::memory_order_relaxed);
            }
            return cache_[87].load(std::memory_order_relaxed);
        }
        virtual bool fix_private_gatt_advertisement() override {
            if (cache_[88].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 88);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[88].store(*value, std::memory_order_relaxed);
            }
            return cache_[88].load(std::memory_order_relaxed);
        }
        virtual bool fix_race_in_orphaned_acls() override {
            if (cache_[89].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 89);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[89].store(*value, std::memory_order_relaxed);
            }
            return cache_[89].load(std::memory_order_relaxed);
        }
        virtual bool fix_socket_connection_failed_no_callback() override {
            if (cache_[90].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 90);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[90].store(*value, std::memory_order_relaxed);
            }
            return cache_[90].load(std::memory_order_relaxed);
        }
        virtual bool fix_started_module_race() override {
            if (cache_[91].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 91);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[91].store(*value, std::memory_order_relaxed);
            }
            return cache_[91].load(std::memory_order_relaxed);
        }
        virtual bool fix_unhandled_bqr_subevent() override {
            if (cache_[92].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 92);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[92].store(*value, std::memory_order_relaxed);
            }
            return cache_[92].load(std::memory_order_relaxed);
        }
        virtual bool fix_use_after_object_destroyed() override {
            if (cache_[93].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 93);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[93].store(*value, std::memory_order_relaxed);
            }
            return cache_[93].load(std::memory_order_relaxed);
        }
        virtual bool flag_handle_hci_error_controller_busy() override {
            if (cache_[94].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 94);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[94].store(*value, std::memory_order_relaxed);
            }
            return cache_[94].load(std::memory_order_relaxed);
        }
        virtual bool floss_separate_host_privacy_and_llprivacy() override {
            if (cache_[95].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 95);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[95].store(*value, std::memory_order_relaxed);
            }
            return cache_[95].load(std::memory_order_relaxed);
        }
        virtual bool gatt_clear_cache_on_factory_reset() override {
            if (cache_[96].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 96);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[96].store(*value, std::memory_order_relaxed);
            }
            return cache_[96].load(std::memory_order_relaxed);
        }
        virtual bool gatt_discovery_is_non_opportunistic_client() override {
            if (cache_[97].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 97);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[97].store(*value, std::memory_order_relaxed);
            }
            return cache_[97].load(std::memory_order_relaxed);
        }
        virtual bool gatt_failure_callback_on_cancel() override {
            if (cache_[98].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 98);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[98].store(*value, std::memory_order_relaxed);
            }
            return cache_[98].load(std::memory_order_relaxed);
        }
        virtual bool gatt_messaging_permissions() override {
            if (cache_[99].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 99);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[99].store(*value, std::memory_order_relaxed);
            }
            return cache_[99].load(std::memory_order_relaxed);
        }
        virtual bool gatt_multi_bearer_connections() override {
            if (cache_[100].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 100);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[100].store(*value, std::memory_order_relaxed);
            }
            return cache_[100].load(std::memory_order_relaxed);
        }
        virtual bool gatt_multi_bearer_transactions() override {
            if (cache_[101].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 101);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[101].store(*value, std::memory_order_relaxed);
            }
            return cache_[101].load(std::memory_order_relaxed);
        }
        virtual bool gatt_offload_api() override {
            if (cache_[102].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 102);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[102].store(*value, std::memory_order_relaxed);
            }
            return cache_[102].load(std::memory_order_relaxed);
        }
        virtual bool gen_key_missing_evt_only_from_iocapreq() override {
            if (cache_[103].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 103);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[103].store(*value, std::memory_order_relaxed);
            }
            return cache_[103].load(std::memory_order_relaxed);
        }
        virtual bool get_all_element_attributes_empty() override {
            if (cache_[104].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 104);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[104].store(*value, std::memory_order_relaxed);
            }
            return cache_[104].load(std::memory_order_relaxed);
        }
        virtual bool get_profile_oneway() override {
            if (cache_[105].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 105);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[105].store(*value, std::memory_order_relaxed);
            }
            return cache_[105].load(std::memory_order_relaxed);
        }
        virtual bool get_svc_uuids_bugfix() override {
            if (cache_[106].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 106);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[106].store(*value, std::memory_order_relaxed);
            }
            return cache_[106].load(std::memory_order_relaxed);
        }
        virtual bool get_svc_uuids_from_ble_adv_data() override {
            if (cache_[107].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 107);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[107].store(*value, std::memory_order_relaxed);
            }
            return cache_[107].load(std::memory_order_relaxed);
        }
        virtual bool graceful_disable_without_message() override {
            if (cache_[108].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 108);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[108].store(*value, std::memory_order_relaxed);
            }
            return cache_[108].load(std::memory_order_relaxed);
        }
        virtual bool handle_delivery_sending_failure_events() override {
            if (cache_[109].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 109);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[109].store(*value, std::memory_order_relaxed);
            }
            return cache_[109].load(std::memory_order_relaxed);
        }
        virtual bool handle_encryption_fail_before_sdp_when_paring() override {
            if (cache_[110].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 110);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[110].store(*value, std::memory_order_relaxed);
            }
            return cache_[110].load(std::memory_order_relaxed);
        }
        virtual bool hap_on_main_looper() override {
            if (cache_[111].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 111);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[111].store(*value, std::memory_order_relaxed);
            }
            return cache_[111].load(std::memory_order_relaxed);
        }
        virtual bool hap_safely_erase_pending_operation_timeout() override {
            if (cache_[112].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 112);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[112].store(*value, std::memory_order_relaxed);
            }
            return cache_[112].load(std::memory_order_relaxed);
        }
        virtual bool hci_instance_name_use_injected() override {
            if (cache_[113].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 113);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[113].store(*value, std::memory_order_relaxed);
            }
            return cache_[113].load(std::memory_order_relaxed);
        }
        virtual bool hci_vendor_specific_extension() override {
            if (cache_[114].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 114);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[114].store(*value, std::memory_order_relaxed);
            }
            return cache_[114].load(std::memory_order_relaxed);
        }
        virtual bool hfp_client_disconnecting_state() override {
            if (cache_[115].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 115);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[115].store(*value, std::memory_order_relaxed);
            }
            return cache_[115].load(std::memory_order_relaxed);
        }
        virtual bool hfp_sco_state_reset_when_profile_restart() override {
            if (cache_[116].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 116);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[116].store(*value, std::memory_order_relaxed);
            }
            return cache_[116].load(std::memory_order_relaxed);
        }
        virtual bool hh_state_update_race_fix() override {
            if (cache_[117].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 117);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[117].store(*value, std::memory_order_relaxed);
            }
            return cache_[117].load(std::memory_order_relaxed);
        }
        virtual bool hid_connection_timeout_in_jni_thread() override {
            if (cache_[118].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 118);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[118].store(*value, std::memory_order_relaxed);
            }
            return cache_[118].load(std::memory_order_relaxed);
        }
        virtual bool hidd_handle_set_protocol_before_interrupt_connected() override {
            if (cache_[119].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 119);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[119].store(*value, std::memory_order_relaxed);
            }
            return cache_[119].load(std::memory_order_relaxed);
        }
        virtual bool hidh_close_in_jni_thread() override {
            if (cache_[120].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 120);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[120].store(*value, std::memory_order_relaxed);
            }
            return cache_[120].load(std::memory_order_relaxed);
        }
        virtual bool hogp_direct_connection_upgrade() override {
            if (cache_[121].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 121);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[121].store(*value, std::memory_order_relaxed);
            }
            return cache_[121].load(std::memory_order_relaxed);
        }
        virtual bool hogp_encryption_collision() override {
            if (cache_[122].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 122);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[122].store(*value, std::memory_order_relaxed);
            }
            return cache_[122].load(std::memory_order_relaxed);
        }
        virtual bool hold_conference_call_from_remote() override {
            if (cache_[123].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 123);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[123].store(*value, std::memory_order_relaxed);
            }
            return cache_[123].load(std::memory_order_relaxed);
        }
        virtual bool idempotent_direct_connect_add() override {
            if (cache_[124].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 124);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[124].store(*value, std::memory_order_relaxed);
            }
            return cache_[124].load(std::memory_order_relaxed);
        }
        virtual bool identity_address_type_api() override {
            if (cache_[125].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 125);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[125].store(*value, std::memory_order_relaxed);
            }
            return cache_[125].load(std::memory_order_relaxed);
        }
        virtual bool identity_to_pseudo_addr() override {
            if (cache_[126].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 126);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[126].store(*value, std::memory_order_relaxed);
            }
            return cache_[126].load(std::memory_order_relaxed);
        }
        virtual bool ignore_auth_req_when_collision_timer_active() override {
            if (cache_[127].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 127);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[127].store(*value, std::memory_order_relaxed);
            }
            return cache_[127].load(std::memory_order_relaxed);
        }
        virtual bool ignore_le_smp_conn_when_sm_over_br_progress() override {
            if (cache_[128].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 128);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[128].store(*value, std::memory_order_relaxed);
            }
            return cache_[128].load(std::memory_order_relaxed);
        }
        virtual bool ignore_message_sms_disallowed() override {
            if (cache_[129].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 129);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[129].store(*value, std::memory_order_relaxed);
            }
            return cache_[129].load(std::memory_order_relaxed);
        }
        virtual bool ignore_multiple_connect_request_in_bt_services() override {
            if (cache_[130].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 130);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[130].store(*value, std::memory_order_relaxed);
            }
            return cache_[130].load(std::memory_order_relaxed);
        }
        virtual bool ignore_unrelated_cancel_bond() override {
            if (cache_[131].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 131);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[131].store(*value, std::memory_order_relaxed);
            }
            return cache_[131].load(std::memory_order_relaxed);
        }
        virtual bool immediate_encryption_after_pairing() override {
            if (cache_[132].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 132);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[132].store(*value, std::memory_order_relaxed);
            }
            return cache_[132].load(std::memory_order_relaxed);
        }
        virtual bool implement_get_image_from_descriptor_for_cover_art() override {
            if (cache_[133].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 133);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[133].store(*value, std::memory_order_relaxed);
            }
            return cache_[133].load(std::memory_order_relaxed);
        }
        virtual bool increase_contact_image_resolution() override {
            if (cache_[134].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 134);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[134].store(*value, std::memory_order_relaxed);
            }
            return cache_[134].load(std::memory_order_relaxed);
        }
        virtual bool indicate_rfcomm_connection_complete_after_msc() override {
            if (cache_[135].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 135);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[135].store(*value, std::memory_order_relaxed);
            }
            return cache_[135].load(std::memory_order_relaxed);
        }
        virtual bool initial_conn_params_p1() override {
            if (cache_[136].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 136);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[136].store(*value, std::memory_order_relaxed);
            }
            return cache_[136].load(std::memory_order_relaxed);
        }
        virtual bool invalidate_hci_handle_on_acl_removal() override {
            if (cache_[137].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 137);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[137].store(*value, std::memory_order_relaxed);
            }
            return cache_[137].load(std::memory_order_relaxed);
        }
        virtual bool irk_scan_bond_check_update() override {
            if (cache_[138].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 138);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[138].store(*value, std::memory_order_relaxed);
            }
            return cache_[138].load(std::memory_order_relaxed);
        }
        virtual bool key_missing_count_api() override {
            if (cache_[139].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 139);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[139].store(*value, std::memory_order_relaxed);
            }
            return cache_[139].load(std::memory_order_relaxed);
        }
        virtual bool key_missing_public() override {
            if (cache_[140].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 140);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[140].store(*value, std::memory_order_relaxed);
            }
            return cache_[140].load(std::memory_order_relaxed);
        }
        virtual bool l2c_not_cancel_timeout() override {
            if (cache_[141].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 141);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[141].store(*value, std::memory_order_relaxed);
            }
            return cache_[141].load(std::memory_order_relaxed);
        }
        virtual bool l2cap_improve_segmented_sdu() override {
            if (cache_[142].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 142);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[142].store(*value, std::memory_order_relaxed);
            }
            return cache_[142].load(std::memory_order_relaxed);
        }
        virtual bool ldac_rate_control() override {
            if (cache_[143].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 143);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[143].store(*value, std::memory_order_relaxed);
            }
            return cache_[143].load(std::memory_order_relaxed);
        }
        virtual bool le_address_map_update() override {
            if (cache_[144].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 144);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[144].store(*value, std::memory_order_relaxed);
            }
            return cache_[144].load(std::memory_order_relaxed);
        }
        virtual bool le_ase_read_multiple_variable() override {
            if (cache_[145].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 145);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[145].store(*value, std::memory_order_relaxed);
            }
            return cache_[145].load(std::memory_order_relaxed);
        }
        virtual bool le_audio_update_config_preference_to_hal() override {
            if (cache_[146].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 146);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[146].store(*value, std::memory_order_relaxed);
            }
            return cache_[146].load(std::memory_order_relaxed);
        }
        virtual bool le_scan_msft_support() override {
            if (cache_[147].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 147);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[147].store(*value, std::memory_order_relaxed);
            }
            return cache_[147].load(std::memory_order_relaxed);
        }
        virtual bool le_subrate_api() override {
            if (cache_[148].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 148);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[148].store(*value, std::memory_order_relaxed);
            }
            return cache_[148].load(std::memory_order_relaxed);
        }
        virtual bool le_subrate_manager() override {
            if (cache_[149].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 149);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[149].store(*value, std::memory_order_relaxed);
            }
            return cache_[149].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_add_opus_codec_type() override {
            if (cache_[150].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 150);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[150].store(*value, std::memory_order_relaxed);
            }
            return cache_[150].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_add_opus_hi_res_codec_type() override {
            if (cache_[151].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 151);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[151].store(*value, std::memory_order_relaxed);
            }
            return cache_[151].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_add_opus_hi_res_codec_type_api() override {
            if (cache_[152].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 152);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[152].store(*value, std::memory_order_relaxed);
            }
            return cache_[152].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_bis_sync_control() override {
            if (cache_[153].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 153);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[153].store(*value, std::memory_order_relaxed);
            }
            return cache_[153].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_broadcast_allow_monitoring_on_resume() override {
            if (cache_[154].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 154);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[154].store(*value, std::memory_order_relaxed);
            }
            return cache_[154].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_broadcast_api_get_local_metadata() override {
            if (cache_[155].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 155);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[155].store(*value, std::memory_order_relaxed);
            }
            return cache_[155].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_broadcast_api_manage_primary_group() override {
            if (cache_[156].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 156);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[156].store(*value, std::memory_order_relaxed);
            }
            return cache_[156].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_broadcast_config_data_path_before_set_iso_data_path() override {
            if (cache_[157].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 157);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[157].store(*value, std::memory_order_relaxed);
            }
            return cache_[157].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_broadcast_fix_autonomous_source_adding() override {
            if (cache_[158].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 158);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[158].store(*value, std::memory_order_relaxed);
            }
            return cache_[158].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_broadcast_monitor_source_sync_status() override {
            if (cache_[159].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 159);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[159].store(*value, std::memory_order_relaxed);
            }
            return cache_[159].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_broadcast_remove_sink_metadata_on_switch_to_local() override {
            if (cache_[160].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 160);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[160].store(*value, std::memory_order_relaxed);
            }
            return cache_[160].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_broadcast_simplify_set_bcast_code() override {
            if (cache_[161].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 161);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[161].store(*value, std::memory_order_relaxed);
            }
            return cache_[161].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_broadcast_source_channel_map_classification() override {
            if (cache_[162].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 162);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[162].store(*value, std::memory_order_relaxed);
            }
            return cache_[162].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_broadcast_volume_control_for_connected_devices() override {
            if (cache_[163].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 163);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[163].store(*value, std::memory_order_relaxed);
            }
            return cache_[163].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_check_ecosystem_base_interval_support() override {
            if (cache_[164].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 164);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[164].store(*value, std::memory_order_relaxed);
            }
            return cache_[164].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_config_profile_enabling() override {
            if (cache_[165].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 165);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[165].store(*value, std::memory_order_relaxed);
            }
            return cache_[165].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_connection_subrating() override {
            if (cache_[166].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 166);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[166].store(*value, std::memory_order_relaxed);
            }
            return cache_[166].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_dev_options_respect_profile_sysprops() override {
            if (cache_[167].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 167);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[167].store(*value, std::memory_order_relaxed);
            }
            return cache_[167].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_disable_broadcast_for_hap_device() override {
            if (cache_[168].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 168);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[168].store(*value, std::memory_order_relaxed);
            }
            return cache_[168].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_do_not_set_autoconnecting_on_connected_device() override {
            if (cache_[169].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 169);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[169].store(*value, std::memory_order_relaxed);
            }
            return cache_[169].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_dynamic_data_path_change() override {
            if (cache_[170].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 170);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[170].store(*value, std::memory_order_relaxed);
            }
            return cache_[170].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_dynamic_direction_opening() override {
            if (cache_[171].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 171);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[171].store(*value, std::memory_order_relaxed);
            }
            return cache_[171].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_fix_stop_reconfiguration_timeout() override {
            if (cache_[172].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 172);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[172].store(*value, std::memory_order_relaxed);
            }
            return cache_[172].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_improve_switching_le_audio_devices() override {
            if (cache_[173].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 173);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[173].store(*value, std::memory_order_relaxed);
            }
            return cache_[173].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_intent_broadcast_in_state_machine_cleanup() override {
            if (cache_[174].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 174);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[174].store(*value, std::memory_order_relaxed);
            }
            return cache_[174].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_mono_location_errata_api() override {
            if (cache_[175].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 175);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[175].store(*value, std::memory_order_relaxed);
            }
            return cache_[175].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_multiple_vocs_instances_api() override {
            if (cache_[176].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 176);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[176].store(*value, std::memory_order_relaxed);
            }
            return cache_[176].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_peripheral_feature() override {
            if (cache_[177].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 177);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[177].store(*value, std::memory_order_relaxed);
            }
            return cache_[177].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_set_codec_config_preference() override {
            if (cache_[178].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 178);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[178].store(*value, std::memory_order_relaxed);
            }
            return cache_[178].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_use_aggressive_params() override {
            if (cache_[179].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 179);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[179].store(*value, std::memory_order_relaxed);
            }
            return cache_[179].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_use_context_type_manager() override {
            if (cache_[180].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 180);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[180].store(*value, std::memory_order_relaxed);
            }
            return cache_[180].load(std::memory_order_relaxed);
        }
        virtual bool leaudio_use_game_sonification_as_regular_sonification() override {
            if (cache_[181].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 181);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[181].store(*value, std::memory_order_relaxed);
            }
            return cache_[181].load(std::memory_order_relaxed);
        }
        virtual bool lhdc_codec_support() override {
            if (cache_[182].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 182);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[182].store(*value, std::memory_order_relaxed);
            }
            return cache_[182].load(std::memory_order_relaxed);
        }
        virtual bool link_status_api() override {
            if (cache_[183].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 183);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[183].store(*value, std::memory_order_relaxed);
            }
            return cache_[183].load(std::memory_order_relaxed);
        }
        virtual bool maintain_call_index_after_conference() override {
            if (cache_[184].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 184);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[184].store(*value, std::memory_order_relaxed);
            }
            return cache_[184].load(std::memory_order_relaxed);
        }
        virtual bool make_socket_read_behavior_consistent() override {
            if (cache_[185].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 185);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[185].store(*value, std::memory_order_relaxed);
            }
            return cache_[185].load(std::memory_order_relaxed);
        }
        virtual bool map_client_check_access_permission() override {
            if (cache_[186].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 186);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[186].store(*value, std::memory_order_relaxed);
            }
            return cache_[186].load(std::memory_order_relaxed);
        }
        virtual bool map_continue_operation() override {
            if (cache_[187].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 187);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[187].store(*value, std::memory_order_relaxed);
            }
            return cache_[187].load(std::memory_order_relaxed);
        }
        virtual bool map_mime_multipart() override {
            if (cache_[188].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 188);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[188].store(*value, std::memory_order_relaxed);
            }
            return cache_[188].load(std::memory_order_relaxed);
        }
        virtual bool merge_call_with_held_conference() override {
            if (cache_[189].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 189);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[189].store(*value, std::memory_order_relaxed);
            }
            return cache_[189].load(std::memory_order_relaxed);
        }
        virtual bool metadata_api_inactive_audio_device_upon_connection() override {
            if (cache_[190].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 190);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[190].store(*value, std::memory_order_relaxed);
            }
            return cache_[190].load(std::memory_order_relaxed);
        }
        virtual bool metadata_api_microphone_for_call_enabled() override {
            if (cache_[191].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 191);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[191].store(*value, std::memory_order_relaxed);
            }
            return cache_[191].load(std::memory_order_relaxed);
        }
        virtual bool microphone_mute_status_sync() override {
            if (cache_[192].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 192);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[192].store(*value, std::memory_order_relaxed);
            }
            return cache_[192].load(std::memory_order_relaxed);
        }
        virtual bool mode_change_before_sco_unpark() override {
            if (cache_[193].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 193);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[193].store(*value, std::memory_order_relaxed);
            }
            return cache_[193].load(std::memory_order_relaxed);
        }
        virtual bool monitor_read_flag_on_offloaded_socket() override {
            if (cache_[194].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 194);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[194].store(*value, std::memory_order_relaxed);
            }
            return cache_[194].load(std::memory_order_relaxed);
        }
        virtual bool msft_addr_tracking_quirk() override {
            if (cache_[195].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 195);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[195].store(*value, std::memory_order_relaxed);
            }
            return cache_[195].load(std::memory_order_relaxed);
        }
        virtual bool non_bonded_device_properties() override {
            if (cache_[196].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 196);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[196].store(*value, std::memory_order_relaxed);
            }
            return cache_[196].load(std::memory_order_relaxed);
        }
        virtual bool non_conference_call_hangup() override {
            if (cache_[197].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 197);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[197].store(*value, std::memory_order_relaxed);
            }
            return cache_[197].load(std::memory_order_relaxed);
        }
        virtual bool non_zero_local_irk() override {
            if (cache_[198].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 198);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[198].store(*value, std::memory_order_relaxed);
            }
            return cache_[198].load(std::memory_order_relaxed);
        }
        virtual bool not_delete_locked_message() override {
            if (cache_[199].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 199);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[199].store(*value, std::memory_order_relaxed);
            }
            return cache_[199].load(std::memory_order_relaxed);
        }
        virtual bool nrpa_non_connectable_adv() override {
            if (cache_[200].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 200);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[200].store(*value, std::memory_order_relaxed);
            }
            return cache_[200].load(std::memory_order_relaxed);
        }
        virtual bool on_to_ble_on_via_off() override {
            if (cache_[201].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 201);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[201].store(*value, std::memory_order_relaxed);
            }
            return cache_[201].load(std::memory_order_relaxed);
        }
        virtual bool only_broadcast_to_local_user() override {
            if (cache_[202].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 202);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[202].store(*value, std::memory_order_relaxed);
            }
            return cache_[202].load(std::memory_order_relaxed);
        }
        virtual bool only_start_scan_during_ble_on() override {
            if (cache_[203].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 203);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[203].store(*value, std::memory_order_relaxed);
            }
            return cache_[203].load(std::memory_order_relaxed);
        }
        virtual bool opp_check_content_uri_permissions() override {
            if (cache_[204].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 204);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[204].store(*value, std::memory_order_relaxed);
            }
            return cache_[204].load(std::memory_order_relaxed);
        }
        virtual bool opp_device_picker_extra_intent_apis() override {
            if (cache_[205].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 205);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[205].store(*value, std::memory_order_relaxed);
            }
            return cache_[205].load(std::memory_order_relaxed);
        }
        virtual bool original_address_filter_match() override {
            if (cache_[206].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 206);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[206].store(*value, std::memory_order_relaxed);
            }
            return cache_[206].load(std::memory_order_relaxed);
        }
        virtual bool pairing_collision_with_same_device() override {
            if (cache_[207].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 207);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[207].store(*value, std::memory_order_relaxed);
            }
            return cache_[207].load(std::memory_order_relaxed);
        }
        virtual bool pbap_cleanup_use_handler() override {
            if (cache_[208].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 208);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[208].store(*value, std::memory_order_relaxed);
            }
            return cache_[208].load(std::memory_order_relaxed);
        }
        virtual bool pbap_client_check_access_permission() override {
            if (cache_[209].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 209);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[209].store(*value, std::memory_order_relaxed);
            }
            return cache_[209].load(std::memory_order_relaxed);
        }
        virtual bool pbap_client_contacts_caching() override {
            if (cache_[210].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 210);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[210].store(*value, std::memory_order_relaxed);
            }
            return cache_[210].load(std::memory_order_relaxed);
        }
        virtual bool pbap_limit_call_log() override {
            if (cache_[211].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 211);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[211].store(*value, std::memory_order_relaxed);
            }
            return cache_[211].load(std::memory_order_relaxed);
        }
        virtual bool preload_gatt_database() override {
            if (cache_[212].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 212);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[212].store(*value, std::memory_order_relaxed);
            }
            return cache_[212].load(std::memory_order_relaxed);
        }
        virtual bool prevent_adding_both_pseudo_and_identity_addr() override {
            if (cache_[213].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 213);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[213].store(*value, std::memory_order_relaxed);
            }
            return cache_[213].load(std::memory_order_relaxed);
        }
        virtual bool prevent_storage_access_without_gd_running() override {
            if (cache_[214].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 214);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[214].store(*value, std::memory_order_relaxed);
            }
            return cache_[214].load(std::memory_order_relaxed);
        }
        virtual bool prioritized_in_ear_routing() override {
            if (cache_[215].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 215);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[215].store(*value, std::memory_order_relaxed);
            }
            return cache_[215].load(std::memory_order_relaxed);
        }
        virtual bool protect_dumpsys_during_stack_shutdown() override {
            if (cache_[216].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 216);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[216].store(*value, std::memory_order_relaxed);
            }
            return cache_[216].load(std::memory_order_relaxed);
        }
        virtual bool qc_aptx_codec_negotiation() override {
            if (cache_[217].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 217);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[217].store(*value, std::memory_order_relaxed);
            }
            return cache_[217].load(std::memory_order_relaxed);
        }
        virtual bool qc_prioritize_lc3_codec() override {
            if (cache_[218].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 218);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[218].store(*value, std::memory_order_relaxed);
            }
            return cache_[218].load(std::memory_order_relaxed);
        }
        virtual bool qc_send_error_at_bcc_ibr_disabled() override {
            if (cache_[219].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 219);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[219].store(*value, std::memory_order_relaxed);
            }
            return cache_[219].load(std::memory_order_relaxed);
        }
        virtual bool queue_dis_requests() override {
            if (cache_[220].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 220);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[220].store(*value, std::memory_order_relaxed);
            }
            return cache_[220].load(std::memory_order_relaxed);
        }
        virtual bool read_ppcp_only_for_success() override {
            if (cache_[221].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 221);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[221].store(*value, std::memory_order_relaxed);
            }
            return cache_[221].load(std::memory_order_relaxed);
        }
        virtual bool read_rssi_throttling() override {
            if (cache_[222].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 222);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[222].store(*value, std::memory_order_relaxed);
            }
            return cache_[222].load(std::memory_order_relaxed);
        }
        virtual bool reboke_permission_on_unbond() override {
            if (cache_[223].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 223);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[223].store(*value, std::memory_order_relaxed);
            }
            return cache_[223].load(std::memory_order_relaxed);
        }
        virtual bool reconnect_on_hogp_connection_failure() override {
            if (cache_[224].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 224);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[224].store(*value, std::memory_order_relaxed);
            }
            return cache_[224].load(std::memory_order_relaxed);
        }
        virtual bool ref_counted_native_wakelock() override {
            if (cache_[225].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 225);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[225].store(*value, std::memory_order_relaxed);
            }
            return cache_[225].load(std::memory_order_relaxed);
        }
        virtual bool refactor_saving_messages_and_metadata() override {
            if (cache_[226].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 226);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[226].store(*value, std::memory_order_relaxed);
            }
            return cache_[226].load(std::memory_order_relaxed);
        }
        virtual bool reject_bond_request_during_bonding() override {
            if (cache_[227].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 227);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[227].store(*value, std::memory_order_relaxed);
            }
            return cache_[227].load(std::memory_order_relaxed);
        }
        virtual bool release_port_in_bta_ag_rfc_fail_before_reset_context() override {
            if (cache_[228].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 228);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[228].store(*value, std::memory_order_relaxed);
            }
            return cache_[228].load(std::memory_order_relaxed);
        }
        virtual bool remove_address_cache_from_ble_scanner() override {
            if (cache_[229].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 229);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[229].store(*value, std::memory_order_relaxed);
            }
            return cache_[229].load(std::memory_order_relaxed);
        }
        virtual bool remove_device_with_connection_manager() override {
            if (cache_[230].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 230);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[230].store(*value, std::memory_order_relaxed);
            }
            return cache_[230].load(std::memory_order_relaxed);
        }
        virtual bool remove_handler_clear() override {
            if (cache_[231].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 231);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[231].store(*value, std::memory_order_relaxed);
            }
            return cache_[231].load(std::memory_order_relaxed);
        }
        virtual bool remove_hop_from_le_adv_set_term() override {
            if (cache_[232].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 232);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[232].store(*value, std::memory_order_relaxed);
            }
            return cache_[232].load(std::memory_order_relaxed);
        }
        virtual bool replace_message_loop_thread_with_gd_handler() override {
            if (cache_[233].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 233);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[233].store(*value, std::memory_order_relaxed);
            }
            return cache_[233].load(std::memory_order_relaxed);
        }
        virtual bool reset_collision_state_on_encryption() override {
            if (cache_[234].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 234);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[234].store(*value, std::memory_order_relaxed);
            }
            return cache_[234].load(std::memory_order_relaxed);
        }
        virtual bool reset_security_flags_on_pairing_failure() override {
            if (cache_[235].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 235);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[235].store(*value, std::memory_order_relaxed);
            }
            return cache_[235].load(std::memory_order_relaxed);
        }
        virtual bool reset_service_change_ind_counter() override {
            if (cache_[236].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 236);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[236].store(*value, std::memory_order_relaxed);
            }
            return cache_[236].load(std::memory_order_relaxed);
        }
        virtual bool reset_state_when_removing_non_connected_hid_device() override {
            if (cache_[237].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 237);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[237].store(*value, std::memory_order_relaxed);
            }
            return cache_[237].load(std::memory_order_relaxed);
        }
        virtual bool resolve_address_for_adv_report() override {
            if (cache_[238].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 238);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[238].store(*value, std::memory_order_relaxed);
            }
            return cache_[238].load(std::memory_order_relaxed);
        }
        virtual bool retain_address_type() override {
            if (cache_[239].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 239);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[239].store(*value, std::memory_order_relaxed);
            }
            return cache_[239].load(std::memory_order_relaxed);
        }
        virtual bool return_correct_ble_state() override {
            if (cache_[240].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 240);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[240].store(*value, std::memory_order_relaxed);
            }
            return cache_[240].load(std::memory_order_relaxed);
        }
        virtual bool rfcomm_fix_bta_ag_rfc_acp_open_error() override {
            if (cache_[241].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 241);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[241].store(*value, std::memory_order_relaxed);
            }
            return cache_[241].load(std::memory_order_relaxed);
        }
        virtual bool rfcomm_fix_mux_collision_handling() override {
            if (cache_[242].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 242);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[242].store(*value, std::memory_order_relaxed);
            }
            return cache_[242].load(std::memory_order_relaxed);
        }
        virtual bool rnr_directly_call_gap_over_le() override {
            if (cache_[243].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 243);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[243].store(*value, std::memory_order_relaxed);
            }
            return cache_[243].load(std::memory_order_relaxed);
        }
        virtual bool rnr_validate_page_scan_repetition_mode() override {
            if (cache_[244].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 244);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[244].store(*value, std::memory_order_relaxed);
            }
            return cache_[244].load(std::memory_order_relaxed);
        }
        virtual bool role_switch_after_encryption() override {
            if (cache_[245].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 245);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[245].store(*value, std::memory_order_relaxed);
            }
            return cache_[245].load(std::memory_order_relaxed);
        }
        virtual bool rssi_scan_filter() override {
            if (cache_[246].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 246);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[246].store(*value, std::memory_order_relaxed);
            }
            return cache_[246].load(std::memory_order_relaxed);
        }
        virtual bool same_handler_for_all_modules() override {
            if (cache_[247].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 247);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[247].store(*value, std::memory_order_relaxed);
            }
            return cache_[247].load(std::memory_order_relaxed);
        }
        virtual bool save_cache_for_bonded_device() override {
            if (cache_[248].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 248);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[248].store(*value, std::memory_order_relaxed);
            }
            return cache_[248].load(std::memory_order_relaxed);
        }
        virtual bool scan_controller_thread() override {
            if (cache_[249].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 249);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[249].store(*value, std::memory_order_relaxed);
            }
            return cache_[249].load(std::memory_order_relaxed);
        }
        virtual bool sco_managed_by_audio_remove_hfp_hal() override {
            if (cache_[250].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 250);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[250].store(*value, std::memory_order_relaxed);
            }
            return cache_[250].load(std::memory_order_relaxed);
        }
        virtual bool sco_state_machine_cleanup() override {
            if (cache_[251].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 251);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[251].store(*value, std::memory_order_relaxed);
            }
            return cache_[251].load(std::memory_order_relaxed);
        }
        virtual bool sco_state_machine_update_in_codec_state() override {
            if (cache_[252].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 252);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[252].store(*value, std::memory_order_relaxed);
            }
            return cache_[252].load(std::memory_order_relaxed);
        }
        virtual bool sdp_reset_transport_status_if_disconnect() override {
            if (cache_[253].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 253);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[253].store(*value, std::memory_order_relaxed);
            }
            return cache_[253].load(std::memory_order_relaxed);
        }
        virtual bool send_ok_clcc_before_slc() override {
            if (cache_[254].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 254);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[254].store(*value, std::memory_order_relaxed);
            }
            return cache_[254].load(std::memory_order_relaxed);
        }
        virtual bool send_ok_on_no_action_on_chld() override {
            if (cache_[255].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 255);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[255].store(*value, std::memory_order_relaxed);
            }
            return cache_[255].load(std::memory_order_relaxed);
        }
        virtual bool send_opp_device_picker_extra_intent() override {
            if (cache_[256].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 256);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[256].store(*value, std::memory_order_relaxed);
            }
            return cache_[256].load(std::memory_order_relaxed);
        }
        virtual bool separate_encryption_queue() override {
            if (cache_[257].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 257);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[257].store(*value, std::memory_order_relaxed);
            }
            return cache_[257].load(std::memory_order_relaxed);
        }
        virtual bool service_discovery_on_connected_transport() override {
            if (cache_[258].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 258);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[258].store(*value, std::memory_order_relaxed);
            }
            return cache_[258].load(std::memory_order_relaxed);
        }
        virtual bool service_rediscovery_fix() override {
            if (cache_[259].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 259);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[259].store(*value, std::memory_order_relaxed);
            }
            return cache_[259].load(std::memory_order_relaxed);
        }
        virtual bool set_a2dp_active_device_through_adapter_service() override {
            if (cache_[260].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 260);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[260].store(*value, std::memory_order_relaxed);
            }
            return cache_[260].load(std::memory_order_relaxed);
        }
        virtual bool set_component_available_fix() override {
            if (cache_[261].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 261);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[261].store(*value, std::memory_order_relaxed);
            }
            return cache_[261].load(std::memory_order_relaxed);
        }
        virtual bool set_max_data_length_for_lecoc() override {
            if (cache_[262].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 262);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[262].store(*value, std::memory_order_relaxed);
            }
            return cache_[262].load(std::memory_order_relaxed);
        }
        virtual bool set_ptr_null_after_free() override {
            if (cache_[263].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 263);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[263].store(*value, std::memory_order_relaxed);
            }
            return cache_[263].load(std::memory_order_relaxed);
        }
        virtual bool settings_can_control_hap_preset() override {
            if (cache_[264].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 264);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[264].store(*value, std::memory_order_relaxed);
            }
            return cache_[264].load(std::memory_order_relaxed);
        }
        virtual bool shutdown_main_thread_before_cleanup() override {
            if (cache_[265].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 265);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[265].store(*value, std::memory_order_relaxed);
            }
            return cache_[265].load(std::memory_order_relaxed);
        }
        virtual bool simpler_hid_connection_policy() override {
            if (cache_[266].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 266);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[266].store(*value, std::memory_order_relaxed);
            }
            return cache_[266].load(std::memory_order_relaxed);
        }
        virtual bool skip_excess_name_discovery() override {
            if (cache_[267].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 267);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[267].store(*value, std::memory_order_relaxed);
            }
            return cache_[267].load(std::memory_order_relaxed);
        }
        virtual bool skip_unknown_robust_caching() override {
            if (cache_[268].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 268);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[268].store(*value, std::memory_order_relaxed);
            }
            return cache_[268].load(std::memory_order_relaxed);
        }
        virtual bool smp_connection_status_handling_when_no_acl() override {
            if (cache_[269].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 269);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[269].store(*value, std::memory_order_relaxed);
            }
            return cache_[269].load(std::memory_order_relaxed);
        }
        virtual bool sniff_offload_with_vsc_based_control() override {
            if (cache_[270].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 270);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[270].store(*value, std::memory_order_relaxed);
            }
            return cache_[270].load(std::memory_order_relaxed);
        }
        virtual bool snoop_logger_save_multiple_snoop_logs() override {
            if (cache_[271].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 271);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[271].store(*value, std::memory_order_relaxed);
            }
            return cache_[271].load(std::memory_order_relaxed);
        }
        virtual bool socket_settings_api() override {
            if (cache_[272].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 272);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[272].store(*value, std::memory_order_relaxed);
            }
            return cache_[272].load(std::memory_order_relaxed);
        }
        virtual bool stack_sdp_detect_nil_property_type() override {
            if (cache_[273].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 273);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[273].store(*value, std::memory_order_relaxed);
            }
            return cache_[273].load(std::memory_order_relaxed);
        }
        virtual bool start_discover_service_changed() override {
            if (cache_[274].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 274);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[274].store(*value, std::memory_order_relaxed);
            }
            return cache_[274].load(std::memory_order_relaxed);
        }
        virtual bool start_leaudio_subrate_for_active_set_only() override {
            if (cache_[275].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 275);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[275].store(*value, std::memory_order_relaxed);
            }
            return cache_[275].load(std::memory_order_relaxed);
        }
        virtual bool stop_le_scan_system_suspend() override {
            if (cache_[276].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 276);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[276].store(*value, std::memory_order_relaxed);
            }
            return cache_[276].load(std::memory_order_relaxed);
        }
        virtual bool support_bluetooth_quality_report_v6() override {
            if (cache_[277].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 277);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[277].store(*value, std::memory_order_relaxed);
            }
            return cache_[277].load(std::memory_order_relaxed);
        }
        virtual bool support_metadata_device_types_apis() override {
            if (cache_[278].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 278);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[278].store(*value, std::memory_order_relaxed);
            }
            return cache_[278].load(std::memory_order_relaxed);
        }
        virtual bool support_passive_scanning() override {
            if (cache_[279].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 279);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[279].store(*value, std::memory_order_relaxed);
            }
            return cache_[279].load(std::memory_order_relaxed);
        }
        virtual bool support_zoomed_in_icon_metadata() override {
            if (cache_[280].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 280);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[280].store(*value, std::memory_order_relaxed);
            }
            return cache_[280].load(std::memory_order_relaxed);
        }
        virtual bool synchronize_codec_preferences_and_priority() override {
            if (cache_[281].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 281);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[281].store(*value, std::memory_order_relaxed);
            }
            return cache_[281].load(std::memory_order_relaxed);
        }
        virtual bool synchronize_preset_can_timeout() override {
            if (cache_[282].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 282);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[282].store(*value, std::memory_order_relaxed);
            }
            return cache_[282].load(std::memory_order_relaxed);
        }
        virtual bool system_server_messenger() override {
            if (cache_[283].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 283);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[283].store(*value, std::memory_order_relaxed);
            }
            return cache_[283].load(std::memory_order_relaxed);
        }
        virtual bool tbs_gatt_no_longer_calls_framework() override {
            if (cache_[284].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 284);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[284].store(*value, std::memory_order_relaxed);
            }
            return cache_[284].load(std::memory_order_relaxed);
        }
        virtual bool tbs_set_lea_from_btservice() override {
            if (cache_[285].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 285);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[285].store(*value, std::memory_order_relaxed);
            }
            return cache_[285].load(std::memory_order_relaxed);
        }
        virtual bool temporary_pairing_tracking() override {
            if (cache_[286].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 286);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[286].store(*value, std::memory_order_relaxed);
            }
            return cache_[286].load(std::memory_order_relaxed);
        }
        virtual bool trigger_sec_proc_on_inc_access_req() override {
            if (cache_[287].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 287);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[287].store(*value, std::memory_order_relaxed);
            }
            return cache_[287].load(std::memory_order_relaxed);
        }
        virtual bool unix_file_socket_creation_failure() override {
            if (cache_[288].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 288);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[288].store(*value, std::memory_order_relaxed);
            }
            return cache_[288].load(std::memory_order_relaxed);
        }
        virtual bool unrelated_device_smp_cancellation() override {
            if (cache_[289].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 289);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[289].store(*value, std::memory_order_relaxed);
            }
            return cache_[289].load(std::memory_order_relaxed);
        }
        virtual bool update_cod_if_missing() override {
            if (cache_[290].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 290);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[290].store(*value, std::memory_order_relaxed);
            }
            return cache_[290].load(std::memory_order_relaxed);
        }
        virtual bool upgrade_le_scan_only_screen_on() override {
            if (cache_[291].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 291);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[291].store(*value, std::memory_order_relaxed);
            }
            return cache_[291].load(std::memory_order_relaxed);
        }
        virtual bool upgrade_temp_bonding_on_auth_req() override {
            if (cache_[292].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 292);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[292].store(*value, std::memory_order_relaxed);
            }
            return cache_[292].load(std::memory_order_relaxed);
        }
        virtual bool use_data_store_storage() override {
            if (cache_[293].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 293);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[293].store(*value, std::memory_order_relaxed);
            }
            return cache_[293].load(std::memory_order_relaxed);
        }
        virtual bool use_entire_message_handle() override {
            if (cache_[294].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 294);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[294].store(*value, std::memory_order_relaxed);
            }
            return cache_[294].load(std::memory_order_relaxed);
        }
        virtual bool use_returned_absolute_volume() override {
            if (cache_[295].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 295);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[295].store(*value, std::memory_order_relaxed);
            }
            return cache_[295].load(std::memory_order_relaxed);
        }
        virtual bool use_shared_promise_for_le_address_manager() override {
            if (cache_[296].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 296);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[296].store(*value, std::memory_order_relaxed);
            }
            return cache_[296].load(std::memory_order_relaxed);
        }
        virtual bool user_restriction_refactor() override {
            if (cache_[297].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 297);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[297].store(*value, std::memory_order_relaxed);
            }
            return cache_[297].load(std::memory_order_relaxed);
        }
        virtual bool user_visible_on_user_starting() override {
            if (cache_[298].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 298);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[298].store(*value, std::memory_order_relaxed);
            }
            return cache_[298].load(std::memory_order_relaxed);
        }
        virtual bool validate_connection_policy_before_accepting_connection() override {
            if (cache_[299].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 299);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[299].store(*value, std::memory_order_relaxed);
            }
            return cache_[299].load(std::memory_order_relaxed);
        }
        virtual bool vcp_handle_group_id_internally() override {
            if (cache_[300].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 300);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[300].store(*value, std::memory_order_relaxed);
            }
            return cache_[300].load(std::memory_order_relaxed);
        }
        virtual bool vcp_on_main_looper() override {
            if (cache_[301].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return false;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return false;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 301);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return false;
                }

                cache_[301].store(*value, std::memory_order_relaxed);
            }
            return cache_[301].load(std::memory_order_relaxed);
        }
        virtual bool voice_recognition_fixes() override {
            if (cache_[302].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 302);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[302].store(*value, std::memory_order_relaxed);
            }
            return cache_[302].load(std::memory_order_relaxed);
        }
        virtual bool wait_hid_disconnect_before_marking_unused() override {
            if (cache_[303].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 303);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[303].store(*value, std::memory_order_relaxed);
            }
            return cache_[303].load(std::memory_order_relaxed);
        }
        virtual bool watch_device_override_airplane_mode() override {
            if (cache_[304].load(std::memory_order_relaxed) == -1) {
                if (!package_exists_in_storage_) {
                    return true;
                }
                if (!fingerprint_matches_) {
                    ALOGE("error: package fingerprint mismtach, returning flag default value.");
                    return true;
                }

                auto value = aconfig_storage::get_boolean_flag_value(
                    *flag_value_file_,
                    boolean_start_index_ + 304);

                if (!value.ok()) {
                    ALOGE("error: failed to read flag value: %s", value.error().c_str());
                    return true;
                }

                cache_[304].store(*value, std::memory_order_relaxed);
            }
            return cache_[304].load(std::memory_order_relaxed);
        }

    private:
        std::vector<std::atomic_int8_t> cache_;

        uint32_t boolean_start_index_;

        std::unique_ptr<aconfig_storage::MappedStorageFile> flag_value_file_;

        bool package_exists_in_storage_;
        bool fingerprint_matches_;

    };

    static flag_provider_interface* get_provider_instance() {
        static flag_provider* instance_ = new flag_provider();
        return instance_;
    }

    std::unique_ptr<flag_provider_interface> provider_(get_provider_instance());
}


bool com_android_bluetooth_flags_a2dp_adjust_sbc_bitpool() {
    return com::android::bluetooth::flags::a2dp_adjust_sbc_bitpool();
}

bool com_android_bluetooth_flags_a2dp_cancel_acceptor_alarm_for_avdt_init() {
    return com::android::bluetooth::flags::a2dp_cancel_acceptor_alarm_for_avdt_init();
}

bool com_android_bluetooth_flags_a2dp_delay_disconnect() {
    return com::android::bluetooth::flags::a2dp_delay_disconnect();
}

bool com_android_bluetooth_flags_a2dp_delay_report_in_dumpsys() {
    return com::android::bluetooth::flags::a2dp_delay_report_in_dumpsys();
}

bool com_android_bluetooth_flags_a2dp_disconnect_reason_api() {
    return com::android::bluetooth::flags::a2dp_disconnect_reason_api();
}

bool com_android_bluetooth_flags_a2dp_fmq_read_exact() {
    return com::android::bluetooth::flags::a2dp_fmq_read_exact();
}

bool com_android_bluetooth_flags_a2dp_lhdc_api() {
    return com::android::bluetooth::flags::a2dp_lhdc_api();
}

bool com_android_bluetooth_flags_a2dp_pm_app_id() {
    return com::android::bluetooth::flags::a2dp_pm_app_id();
}

bool com_android_bluetooth_flags_a2dp_reject_sho_request() {
    return com::android::bluetooth::flags::a2dp_reject_sho_request();
}

bool com_android_bluetooth_flags_a2dp_sbc_underflow_recovery() {
    return com::android::bluetooth::flags::a2dp_sbc_underflow_recovery();
}

bool com_android_bluetooth_flags_a2dp_set_configuration_during_discovery() {
    return com::android::bluetooth::flags::a2dp_set_configuration_during_discovery();
}

bool com_android_bluetooth_flags_a2dp_source_null_fixed_queue() {
    return com::android::bluetooth::flags::a2dp_source_null_fixed_queue();
}

bool com_android_bluetooth_flags_abs_volume_sdp_conflict() {
    return com::android::bluetooth::flags::abs_volume_sdp_conflict();
}

bool com_android_bluetooth_flags_acl_fix_in_and_out_connection_reqs() {
    return com::android::bluetooth::flags::acl_fix_in_and_out_connection_reqs();
}

bool com_android_bluetooth_flags_adapter_suspend_advertisement() {
    return com::android::bluetooth::flags::adapter_suspend_advertisement();
}

bool com_android_bluetooth_flags_adapter_suspend_discoverability() {
    return com::android::bluetooth::flags::adapter_suspend_discoverability();
}

bool com_android_bluetooth_flags_adapter_suspend_mgmt() {
    return com::android::bluetooth::flags::adapter_suspend_mgmt();
}

bool com_android_bluetooth_flags_add_bond_loss_reason() {
    return com::android::bluetooth::flags::add_bond_loss_reason();
}

bool com_android_bluetooth_flags_add_hop_to_event_callback() {
    return com::android::bluetooth::flags::add_hop_to_event_callback();
}

bool com_android_bluetooth_flags_add_profile_as_intent_extra() {
    return com::android::bluetooth::flags::add_profile_as_intent_extra();
}

bool com_android_bluetooth_flags_adm_centralize_active_device_handling() {
    return com::android::bluetooth::flags::adm_centralize_active_device_handling();
}

bool com_android_bluetooth_flags_adm_remove_handling_wired() {
    return com::android::bluetooth::flags::adm_remove_handling_wired();
}

bool com_android_bluetooth_flags_adm_unset_others_on_hfp_changed() {
    return com::android::bluetooth::flags::adm_unset_others_on_hfp_changed();
}

bool com_android_bluetooth_flags_aics_api() {
    return com::android::bluetooth::flags::aics_api();
}

bool com_android_bluetooth_flags_allow_rearm_if_suspend_scan_params_used() {
    return com::android::bluetooth::flags::allow_rearm_if_suspend_scan_params_used();
}

bool com_android_bluetooth_flags_allow_switching_hid_and_hogp() {
    return com::android::bluetooth::flags::allow_switching_hid_and_hogp();
}

bool com_android_bluetooth_flags_always_set_identity_addr() {
    return com::android::bluetooth::flags::always_set_identity_addr();
}

bool com_android_bluetooth_flags_asha_omit_gatt_after_svc_changed() {
    return com::android::bluetooth::flags::asha_omit_gatt_after_svc_changed();
}

bool com_android_bluetooth_flags_avdt_close_on_start_failure_bad_state() {
    return com::android::bluetooth::flags::avdt_close_on_start_failure_bad_state();
}

bool com_android_bluetooth_flags_avdt_wait_for_initial_delay_report_as_initiator() {
    return com::android::bluetooth::flags::avdt_wait_for_initial_delay_report_as_initiator();
}

bool com_android_bluetooth_flags_avoid_ctkd_for_temp_pairing() {
    return com::android::bluetooth::flags::avoid_ctkd_for_temp_pairing();
}

bool com_android_bluetooth_flags_avoid_l2c_processing_while_stack_shutdown() {
    return com::android::bluetooth::flags::avoid_l2c_processing_while_stack_shutdown();
}

bool com_android_bluetooth_flags_avrcp_16_default() {
    return com::android::bluetooth::flags::avrcp_16_default();
}

bool com_android_bluetooth_flags_batch_scan_support_check() {
    return com::android::bluetooth::flags::batch_scan_support_check();
}

bool com_android_bluetooth_flags_ble_rnr_when_connected() {
    return com::android::bluetooth::flags::ble_rnr_when_connected();
}

bool com_android_bluetooth_flags_bluetooth_power_telemetry() {
    return com::android::bluetooth::flags::bluetooth_power_telemetry();
}

bool com_android_bluetooth_flags_bond_loss_transport_check() {
    return com::android::bluetooth::flags::bond_loss_transport_check();
}

bool com_android_bluetooth_flags_bond_state_machine_looper() {
    return com::android::bluetooth::flags::bond_state_machine_looper();
}

bool com_android_bluetooth_flags_bonding_initiator_state_reset() {
    return com::android::bluetooth::flags::bonding_initiator_state_reset();
}

bool com_android_bluetooth_flags_bqr_common_part_unified_length() {
    return com::android::bluetooth::flags::bqr_common_part_unified_length();
}

bool com_android_bluetooth_flags_br_edr_discover_gatt_services_over_gatt() {
    return com::android::bluetooth::flags::br_edr_discover_gatt_services_over_gatt();
}

bool com_android_bluetooth_flags_broadcast_transport_type_on_reset() {
    return com::android::bluetooth::flags::broadcast_transport_type_on_reset();
}

bool com_android_bluetooth_flags_bt_offload_socket_api() {
    return com::android::bluetooth::flags::bt_offload_socket_api();
}

bool com_android_bluetooth_flags_bt_socket_api_l2cap_cid() {
    return com::android::bluetooth::flags::bt_socket_api_l2cap_cid();
}

bool com_android_bluetooth_flags_btsec_check_controller_sc_support() {
    return com::android::bluetooth::flags::btsec_check_controller_sc_support();
}

bool com_android_bluetooth_flags_btsec_cycle_irks() {
    return com::android::bluetooth::flags::btsec_cycle_irks();
}

bool com_android_bluetooth_flags_call_sdp_free_in_main_thread() {
    return com::android::bluetooth::flags::call_sdp_free_in_main_thread();
}

bool com_android_bluetooth_flags_channel_sounding() {
    return com::android::bluetooth::flags::channel_sounding();
}

bool com_android_bluetooth_flags_channel_sounding_25q2_apis() {
    return com::android::bluetooth::flags::channel_sounding_25q2_apis();
}

bool com_android_bluetooth_flags_channel_sounding_offload() {
    return com::android::bluetooth::flags::channel_sounding_offload();
}

bool com_android_bluetooth_flags_check_call_state_atd() {
    return com::android::bluetooth::flags::check_call_state_atd();
}

bool com_android_bluetooth_flags_check_l2c_conn_status_before_param_validation() {
    return com::android::bluetooth::flags::check_l2c_conn_status_before_param_validation();
}

bool com_android_bluetooth_flags_check_peer_hf_indicator() {
    return com::android::bluetooth::flags::check_peer_hf_indicator();
}

bool com_android_bluetooth_flags_clear_pairing_state_when_no_devrec() {
    return com::android::bluetooth::flags::clear_pairing_state_when_no_devrec();
}

bool com_android_bluetooth_flags_complete_disc_if_no_rnr() {
    return com::android::bluetooth::flags::complete_disc_if_no_rnr();
}

bool com_android_bluetooth_flags_conclude_le_pairing_immediately() {
    return com::android::bluetooth::flags::conclude_le_pairing_immediately();
}

bool com_android_bluetooth_flags_concurrent_incoming_outgoing_pairing() {
    return com::android::bluetooth::flags::concurrent_incoming_outgoing_pairing();
}

bool com_android_bluetooth_flags_consider_l2c_header_bytes_for_mps_selection() {
    return com::android::bluetooth::flags::consider_l2c_header_bytes_for_mps_selection();
}

bool com_android_bluetooth_flags_consistent_battery_level() {
    return com::android::bluetooth::flags::consistent_battery_level();
}

bool com_android_bluetooth_flags_continue_queued_command_after_discovery() {
    return com::android::bluetooth::flags::continue_queued_command_after_discovery();
}

bool com_android_bluetooth_flags_delay_jv_pm_idle() {
    return com::android::bluetooth::flags::delay_jv_pm_idle();
}

bool com_android_bluetooth_flags_delay_offload_le_coc_connection_ind() {
    return com::android::bluetooth::flags::delay_offload_le_coc_connection_ind();
}

bool com_android_bluetooth_flags_delay_sniff_subrating() {
    return com::android::bluetooth::flags::delay_sniff_subrating();
}

bool com_android_bluetooth_flags_directed_advertising_api() {
    return com::android::bluetooth::flags::directed_advertising_api();
}

bool com_android_bluetooth_flags_disconnect_acl_on_gatt_timeout() {
    return com::android::bluetooth::flags::disconnect_acl_on_gatt_timeout();
}

bool com_android_bluetooth_flags_disconnect_acls_by_bredr_disabled() {
    return com::android::bluetooth::flags::disconnect_acls_by_bredr_disabled();
}

bool com_android_bluetooth_flags_distance_measurement_thread() {
    return com::android::bluetooth::flags::distance_measurement_thread();
}

bool com_android_bluetooth_flags_do_not_dump_devices_from_adapter_properties() {
    return com::android::bluetooth::flags::do_not_dump_devices_from_adapter_properties();
}

bool com_android_bluetooth_flags_do_not_hardcode_tmap_role_mask() {
    return com::android::bluetooth::flags::do_not_hardcode_tmap_role_mask();
}

bool com_android_bluetooth_flags_donot_collide_with_closed_port() {
    return com::android::bluetooth::flags::donot_collide_with_closed_port();
}

bool com_android_bluetooth_flags_donot_mandate_auth_along_with_encryption() {
    return com::android::bluetooth::flags::donot_mandate_auth_along_with_encryption();
}

bool com_android_bluetooth_flags_donot_pm_classic_on_le_traffic() {
    return com::android::bluetooth::flags::donot_pm_classic_on_le_traffic();
}

bool com_android_bluetooth_flags_dont_send_hci_disconnect_repeatedly() {
    return com::android::bluetooth::flags::dont_send_hci_disconnect_repeatedly();
}

bool com_android_bluetooth_flags_downgrade_to_basic_mode_on_no_info_resp() {
    return com::android::bluetooth::flags::downgrade_to_basic_mode_on_no_info_resp();
}

bool com_android_bluetooth_flags_dsa_use_codec_extensibility() {
    return com::android::bluetooth::flags::dsa_use_codec_extensibility();
}

bool com_android_bluetooth_flags_dump_without_promise_timeout() {
    return com::android::bluetooth::flags::dump_without_promise_timeout();
}

bool com_android_bluetooth_flags_early_incoming_hid_connection() {
    return com::android::bluetooth::flags::early_incoming_hid_connection();
}

bool com_android_bluetooth_flags_enable_battery_level_update_only_through_hf_indicator() {
    return com::android::bluetooth::flags::enable_battery_level_update_only_through_hf_indicator();
}

bool com_android_bluetooth_flags_encryption_change_broadcast() {
    return com::android::bluetooth::flags::encryption_change_broadcast();
}

bool com_android_bluetooth_flags_end_outgoing_call_on_chld() {
    return com::android::bluetooth::flags::end_outgoing_call_on_chld();
}

bool com_android_bluetooth_flags_ensure_acl_connection_is_removed_from_pending_list() {
    return com::android::bluetooth::flags::ensure_acl_connection_is_removed_from_pending_list();
}

bool com_android_bluetooth_flags_extend_and_randomize_role_switch_delay() {
    return com::android::bluetooth::flags::extend_and_randomize_role_switch_delay();
}

bool com_android_bluetooth_flags_fix_buf_len_check_for_first_k_frame() {
    return com::android::bluetooth::flags::fix_buf_len_check_for_first_k_frame();
}

bool com_android_bluetooth_flags_fix_event_handler_reg_and_dereg() {
    return com::android::bluetooth::flags::fix_event_handler_reg_and_dereg();
}

bool com_android_bluetooth_flags_fix_hfp_qual_1_9() {
    return com::android::bluetooth::flags::fix_hfp_qual_1_9();
}

bool com_android_bluetooth_flags_fix_hfp_rfcomm_collision_state_machine_error() {
    return com::android::bluetooth::flags::fix_hfp_rfcomm_collision_state_machine_error();
}

bool com_android_bluetooth_flags_fix_lecoc_socket_available() {
    return com::android::bluetooth::flags::fix_lecoc_socket_available();
}

bool com_android_bluetooth_flags_fix_ongoing_rnr_while_bonding() {
    return com::android::bluetooth::flags::fix_ongoing_rnr_while_bonding();
}

bool com_android_bluetooth_flags_fix_private_gatt_advertisement() {
    return com::android::bluetooth::flags::fix_private_gatt_advertisement();
}

bool com_android_bluetooth_flags_fix_race_in_orphaned_acls() {
    return com::android::bluetooth::flags::fix_race_in_orphaned_acls();
}

bool com_android_bluetooth_flags_fix_socket_connection_failed_no_callback() {
    return com::android::bluetooth::flags::fix_socket_connection_failed_no_callback();
}

bool com_android_bluetooth_flags_fix_started_module_race() {
    return com::android::bluetooth::flags::fix_started_module_race();
}

bool com_android_bluetooth_flags_fix_unhandled_bqr_subevent() {
    return com::android::bluetooth::flags::fix_unhandled_bqr_subevent();
}

bool com_android_bluetooth_flags_fix_use_after_object_destroyed() {
    return com::android::bluetooth::flags::fix_use_after_object_destroyed();
}

bool com_android_bluetooth_flags_flag_handle_hci_error_controller_busy() {
    return com::android::bluetooth::flags::flag_handle_hci_error_controller_busy();
}

bool com_android_bluetooth_flags_floss_separate_host_privacy_and_llprivacy() {
    return com::android::bluetooth::flags::floss_separate_host_privacy_and_llprivacy();
}

bool com_android_bluetooth_flags_gatt_clear_cache_on_factory_reset() {
    return com::android::bluetooth::flags::gatt_clear_cache_on_factory_reset();
}

bool com_android_bluetooth_flags_gatt_discovery_is_non_opportunistic_client() {
    return com::android::bluetooth::flags::gatt_discovery_is_non_opportunistic_client();
}

bool com_android_bluetooth_flags_gatt_failure_callback_on_cancel() {
    return com::android::bluetooth::flags::gatt_failure_callback_on_cancel();
}

bool com_android_bluetooth_flags_gatt_messaging_permissions() {
    return com::android::bluetooth::flags::gatt_messaging_permissions();
}

bool com_android_bluetooth_flags_gatt_multi_bearer_connections() {
    return com::android::bluetooth::flags::gatt_multi_bearer_connections();
}

bool com_android_bluetooth_flags_gatt_multi_bearer_transactions() {
    return com::android::bluetooth::flags::gatt_multi_bearer_transactions();
}

bool com_android_bluetooth_flags_gatt_offload_api() {
    return com::android::bluetooth::flags::gatt_offload_api();
}

bool com_android_bluetooth_flags_gen_key_missing_evt_only_from_iocapreq() {
    return com::android::bluetooth::flags::gen_key_missing_evt_only_from_iocapreq();
}

bool com_android_bluetooth_flags_get_all_element_attributes_empty() {
    return com::android::bluetooth::flags::get_all_element_attributes_empty();
}

bool com_android_bluetooth_flags_get_profile_oneway() {
    return com::android::bluetooth::flags::get_profile_oneway();
}

bool com_android_bluetooth_flags_get_svc_uuids_bugfix() {
    return com::android::bluetooth::flags::get_svc_uuids_bugfix();
}

bool com_android_bluetooth_flags_get_svc_uuids_from_ble_adv_data() {
    return com::android::bluetooth::flags::get_svc_uuids_from_ble_adv_data();
}

bool com_android_bluetooth_flags_graceful_disable_without_message() {
    return com::android::bluetooth::flags::graceful_disable_without_message();
}

bool com_android_bluetooth_flags_handle_delivery_sending_failure_events() {
    return com::android::bluetooth::flags::handle_delivery_sending_failure_events();
}

bool com_android_bluetooth_flags_handle_encryption_fail_before_sdp_when_paring() {
    return com::android::bluetooth::flags::handle_encryption_fail_before_sdp_when_paring();
}

bool com_android_bluetooth_flags_hap_on_main_looper() {
    return com::android::bluetooth::flags::hap_on_main_looper();
}

bool com_android_bluetooth_flags_hap_safely_erase_pending_operation_timeout() {
    return com::android::bluetooth::flags::hap_safely_erase_pending_operation_timeout();
}

bool com_android_bluetooth_flags_hci_instance_name_use_injected() {
    return com::android::bluetooth::flags::hci_instance_name_use_injected();
}

bool com_android_bluetooth_flags_hci_vendor_specific_extension() {
    return com::android::bluetooth::flags::hci_vendor_specific_extension();
}

bool com_android_bluetooth_flags_hfp_client_disconnecting_state() {
    return com::android::bluetooth::flags::hfp_client_disconnecting_state();
}

bool com_android_bluetooth_flags_hfp_sco_state_reset_when_profile_restart() {
    return com::android::bluetooth::flags::hfp_sco_state_reset_when_profile_restart();
}

bool com_android_bluetooth_flags_hh_state_update_race_fix() {
    return com::android::bluetooth::flags::hh_state_update_race_fix();
}

bool com_android_bluetooth_flags_hid_connection_timeout_in_jni_thread() {
    return com::android::bluetooth::flags::hid_connection_timeout_in_jni_thread();
}

bool com_android_bluetooth_flags_hidd_handle_set_protocol_before_interrupt_connected() {
    return com::android::bluetooth::flags::hidd_handle_set_protocol_before_interrupt_connected();
}

bool com_android_bluetooth_flags_hidh_close_in_jni_thread() {
    return com::android::bluetooth::flags::hidh_close_in_jni_thread();
}

bool com_android_bluetooth_flags_hogp_direct_connection_upgrade() {
    return com::android::bluetooth::flags::hogp_direct_connection_upgrade();
}

bool com_android_bluetooth_flags_hogp_encryption_collision() {
    return com::android::bluetooth::flags::hogp_encryption_collision();
}

bool com_android_bluetooth_flags_hold_conference_call_from_remote() {
    return com::android::bluetooth::flags::hold_conference_call_from_remote();
}

bool com_android_bluetooth_flags_idempotent_direct_connect_add() {
    return com::android::bluetooth::flags::idempotent_direct_connect_add();
}

bool com_android_bluetooth_flags_identity_address_type_api() {
    return com::android::bluetooth::flags::identity_address_type_api();
}

bool com_android_bluetooth_flags_identity_to_pseudo_addr() {
    return com::android::bluetooth::flags::identity_to_pseudo_addr();
}

bool com_android_bluetooth_flags_ignore_auth_req_when_collision_timer_active() {
    return com::android::bluetooth::flags::ignore_auth_req_when_collision_timer_active();
}

bool com_android_bluetooth_flags_ignore_le_smp_conn_when_sm_over_br_progress() {
    return com::android::bluetooth::flags::ignore_le_smp_conn_when_sm_over_br_progress();
}

bool com_android_bluetooth_flags_ignore_message_sms_disallowed() {
    return com::android::bluetooth::flags::ignore_message_sms_disallowed();
}

bool com_android_bluetooth_flags_ignore_multiple_connect_request_in_bt_services() {
    return com::android::bluetooth::flags::ignore_multiple_connect_request_in_bt_services();
}

bool com_android_bluetooth_flags_ignore_unrelated_cancel_bond() {
    return com::android::bluetooth::flags::ignore_unrelated_cancel_bond();
}

bool com_android_bluetooth_flags_immediate_encryption_after_pairing() {
    return com::android::bluetooth::flags::immediate_encryption_after_pairing();
}

bool com_android_bluetooth_flags_implement_get_image_from_descriptor_for_cover_art() {
    return com::android::bluetooth::flags::implement_get_image_from_descriptor_for_cover_art();
}

bool com_android_bluetooth_flags_increase_contact_image_resolution() {
    return com::android::bluetooth::flags::increase_contact_image_resolution();
}

bool com_android_bluetooth_flags_indicate_rfcomm_connection_complete_after_msc() {
    return com::android::bluetooth::flags::indicate_rfcomm_connection_complete_after_msc();
}

bool com_android_bluetooth_flags_initial_conn_params_p1() {
    return com::android::bluetooth::flags::initial_conn_params_p1();
}

bool com_android_bluetooth_flags_invalidate_hci_handle_on_acl_removal() {
    return com::android::bluetooth::flags::invalidate_hci_handle_on_acl_removal();
}

bool com_android_bluetooth_flags_irk_scan_bond_check_update() {
    return com::android::bluetooth::flags::irk_scan_bond_check_update();
}

bool com_android_bluetooth_flags_key_missing_count_api() {
    return com::android::bluetooth::flags::key_missing_count_api();
}

bool com_android_bluetooth_flags_key_missing_public() {
    return com::android::bluetooth::flags::key_missing_public();
}

bool com_android_bluetooth_flags_l2c_not_cancel_timeout() {
    return com::android::bluetooth::flags::l2c_not_cancel_timeout();
}

bool com_android_bluetooth_flags_l2cap_improve_segmented_sdu() {
    return com::android::bluetooth::flags::l2cap_improve_segmented_sdu();
}

bool com_android_bluetooth_flags_ldac_rate_control() {
    return com::android::bluetooth::flags::ldac_rate_control();
}

bool com_android_bluetooth_flags_le_address_map_update() {
    return com::android::bluetooth::flags::le_address_map_update();
}

bool com_android_bluetooth_flags_le_ase_read_multiple_variable() {
    return com::android::bluetooth::flags::le_ase_read_multiple_variable();
}

bool com_android_bluetooth_flags_le_audio_update_config_preference_to_hal() {
    return com::android::bluetooth::flags::le_audio_update_config_preference_to_hal();
}

bool com_android_bluetooth_flags_le_scan_msft_support() {
    return com::android::bluetooth::flags::le_scan_msft_support();
}

bool com_android_bluetooth_flags_le_subrate_api() {
    return com::android::bluetooth::flags::le_subrate_api();
}

bool com_android_bluetooth_flags_le_subrate_manager() {
    return com::android::bluetooth::flags::le_subrate_manager();
}

bool com_android_bluetooth_flags_leaudio_add_opus_codec_type() {
    return com::android::bluetooth::flags::leaudio_add_opus_codec_type();
}

bool com_android_bluetooth_flags_leaudio_add_opus_hi_res_codec_type() {
    return com::android::bluetooth::flags::leaudio_add_opus_hi_res_codec_type();
}

bool com_android_bluetooth_flags_leaudio_add_opus_hi_res_codec_type_api() {
    return com::android::bluetooth::flags::leaudio_add_opus_hi_res_codec_type_api();
}

bool com_android_bluetooth_flags_leaudio_bis_sync_control() {
    return com::android::bluetooth::flags::leaudio_bis_sync_control();
}

bool com_android_bluetooth_flags_leaudio_broadcast_allow_monitoring_on_resume() {
    return com::android::bluetooth::flags::leaudio_broadcast_allow_monitoring_on_resume();
}

bool com_android_bluetooth_flags_leaudio_broadcast_api_get_local_metadata() {
    return com::android::bluetooth::flags::leaudio_broadcast_api_get_local_metadata();
}

bool com_android_bluetooth_flags_leaudio_broadcast_api_manage_primary_group() {
    return com::android::bluetooth::flags::leaudio_broadcast_api_manage_primary_group();
}

bool com_android_bluetooth_flags_leaudio_broadcast_config_data_path_before_set_iso_data_path() {
    return com::android::bluetooth::flags::leaudio_broadcast_config_data_path_before_set_iso_data_path();
}

bool com_android_bluetooth_flags_leaudio_broadcast_fix_autonomous_source_adding() {
    return com::android::bluetooth::flags::leaudio_broadcast_fix_autonomous_source_adding();
}

bool com_android_bluetooth_flags_leaudio_broadcast_monitor_source_sync_status() {
    return com::android::bluetooth::flags::leaudio_broadcast_monitor_source_sync_status();
}

bool com_android_bluetooth_flags_leaudio_broadcast_remove_sink_metadata_on_switch_to_local() {
    return com::android::bluetooth::flags::leaudio_broadcast_remove_sink_metadata_on_switch_to_local();
}

bool com_android_bluetooth_flags_leaudio_broadcast_simplify_set_bcast_code() {
    return com::android::bluetooth::flags::leaudio_broadcast_simplify_set_bcast_code();
}

bool com_android_bluetooth_flags_leaudio_broadcast_source_channel_map_classification() {
    return com::android::bluetooth::flags::leaudio_broadcast_source_channel_map_classification();
}

bool com_android_bluetooth_flags_leaudio_broadcast_volume_control_for_connected_devices() {
    return com::android::bluetooth::flags::leaudio_broadcast_volume_control_for_connected_devices();
}

bool com_android_bluetooth_flags_leaudio_check_ecosystem_base_interval_support() {
    return com::android::bluetooth::flags::leaudio_check_ecosystem_base_interval_support();
}

bool com_android_bluetooth_flags_leaudio_config_profile_enabling() {
    return com::android::bluetooth::flags::leaudio_config_profile_enabling();
}

bool com_android_bluetooth_flags_leaudio_connection_subrating() {
    return com::android::bluetooth::flags::leaudio_connection_subrating();
}

bool com_android_bluetooth_flags_leaudio_dev_options_respect_profile_sysprops() {
    return com::android::bluetooth::flags::leaudio_dev_options_respect_profile_sysprops();
}

bool com_android_bluetooth_flags_leaudio_disable_broadcast_for_hap_device() {
    return com::android::bluetooth::flags::leaudio_disable_broadcast_for_hap_device();
}

bool com_android_bluetooth_flags_leaudio_do_not_set_autoconnecting_on_connected_device() {
    return com::android::bluetooth::flags::leaudio_do_not_set_autoconnecting_on_connected_device();
}

bool com_android_bluetooth_flags_leaudio_dynamic_data_path_change() {
    return com::android::bluetooth::flags::leaudio_dynamic_data_path_change();
}

bool com_android_bluetooth_flags_leaudio_dynamic_direction_opening() {
    return com::android::bluetooth::flags::leaudio_dynamic_direction_opening();
}

bool com_android_bluetooth_flags_leaudio_fix_stop_reconfiguration_timeout() {
    return com::android::bluetooth::flags::leaudio_fix_stop_reconfiguration_timeout();
}

bool com_android_bluetooth_flags_leaudio_improve_switching_le_audio_devices() {
    return com::android::bluetooth::flags::leaudio_improve_switching_le_audio_devices();
}

bool com_android_bluetooth_flags_leaudio_intent_broadcast_in_state_machine_cleanup() {
    return com::android::bluetooth::flags::leaudio_intent_broadcast_in_state_machine_cleanup();
}

bool com_android_bluetooth_flags_leaudio_mono_location_errata_api() {
    return com::android::bluetooth::flags::leaudio_mono_location_errata_api();
}

bool com_android_bluetooth_flags_leaudio_multiple_vocs_instances_api() {
    return com::android::bluetooth::flags::leaudio_multiple_vocs_instances_api();
}

bool com_android_bluetooth_flags_leaudio_peripheral_feature() {
    return com::android::bluetooth::flags::leaudio_peripheral_feature();
}

bool com_android_bluetooth_flags_leaudio_set_codec_config_preference() {
    return com::android::bluetooth::flags::leaudio_set_codec_config_preference();
}

bool com_android_bluetooth_flags_leaudio_use_aggressive_params() {
    return com::android::bluetooth::flags::leaudio_use_aggressive_params();
}

bool com_android_bluetooth_flags_leaudio_use_context_type_manager() {
    return com::android::bluetooth::flags::leaudio_use_context_type_manager();
}

bool com_android_bluetooth_flags_leaudio_use_game_sonification_as_regular_sonification() {
    return com::android::bluetooth::flags::leaudio_use_game_sonification_as_regular_sonification();
}

bool com_android_bluetooth_flags_lhdc_codec_support() {
    return com::android::bluetooth::flags::lhdc_codec_support();
}

bool com_android_bluetooth_flags_link_status_api() {
    return com::android::bluetooth::flags::link_status_api();
}

bool com_android_bluetooth_flags_maintain_call_index_after_conference() {
    return com::android::bluetooth::flags::maintain_call_index_after_conference();
}

bool com_android_bluetooth_flags_make_socket_read_behavior_consistent() {
    return com::android::bluetooth::flags::make_socket_read_behavior_consistent();
}

bool com_android_bluetooth_flags_map_client_check_access_permission() {
    return com::android::bluetooth::flags::map_client_check_access_permission();
}

bool com_android_bluetooth_flags_map_continue_operation() {
    return com::android::bluetooth::flags::map_continue_operation();
}

bool com_android_bluetooth_flags_map_mime_multipart() {
    return com::android::bluetooth::flags::map_mime_multipart();
}

bool com_android_bluetooth_flags_merge_call_with_held_conference() {
    return com::android::bluetooth::flags::merge_call_with_held_conference();
}

bool com_android_bluetooth_flags_metadata_api_inactive_audio_device_upon_connection() {
    return com::android::bluetooth::flags::metadata_api_inactive_audio_device_upon_connection();
}

bool com_android_bluetooth_flags_metadata_api_microphone_for_call_enabled() {
    return com::android::bluetooth::flags::metadata_api_microphone_for_call_enabled();
}

bool com_android_bluetooth_flags_microphone_mute_status_sync() {
    return com::android::bluetooth::flags::microphone_mute_status_sync();
}

bool com_android_bluetooth_flags_mode_change_before_sco_unpark() {
    return com::android::bluetooth::flags::mode_change_before_sco_unpark();
}

bool com_android_bluetooth_flags_monitor_read_flag_on_offloaded_socket() {
    return com::android::bluetooth::flags::monitor_read_flag_on_offloaded_socket();
}

bool com_android_bluetooth_flags_msft_addr_tracking_quirk() {
    return com::android::bluetooth::flags::msft_addr_tracking_quirk();
}

bool com_android_bluetooth_flags_non_bonded_device_properties() {
    return com::android::bluetooth::flags::non_bonded_device_properties();
}

bool com_android_bluetooth_flags_non_conference_call_hangup() {
    return com::android::bluetooth::flags::non_conference_call_hangup();
}

bool com_android_bluetooth_flags_non_zero_local_irk() {
    return com::android::bluetooth::flags::non_zero_local_irk();
}

bool com_android_bluetooth_flags_not_delete_locked_message() {
    return com::android::bluetooth::flags::not_delete_locked_message();
}

bool com_android_bluetooth_flags_nrpa_non_connectable_adv() {
    return com::android::bluetooth::flags::nrpa_non_connectable_adv();
}

bool com_android_bluetooth_flags_on_to_ble_on_via_off() {
    return com::android::bluetooth::flags::on_to_ble_on_via_off();
}

bool com_android_bluetooth_flags_only_broadcast_to_local_user() {
    return com::android::bluetooth::flags::only_broadcast_to_local_user();
}

bool com_android_bluetooth_flags_only_start_scan_during_ble_on() {
    return com::android::bluetooth::flags::only_start_scan_during_ble_on();
}

bool com_android_bluetooth_flags_opp_check_content_uri_permissions() {
    return com::android::bluetooth::flags::opp_check_content_uri_permissions();
}

bool com_android_bluetooth_flags_opp_device_picker_extra_intent_apis() {
    return com::android::bluetooth::flags::opp_device_picker_extra_intent_apis();
}

bool com_android_bluetooth_flags_original_address_filter_match() {
    return com::android::bluetooth::flags::original_address_filter_match();
}

bool com_android_bluetooth_flags_pairing_collision_with_same_device() {
    return com::android::bluetooth::flags::pairing_collision_with_same_device();
}

bool com_android_bluetooth_flags_pbap_cleanup_use_handler() {
    return com::android::bluetooth::flags::pbap_cleanup_use_handler();
}

bool com_android_bluetooth_flags_pbap_client_check_access_permission() {
    return com::android::bluetooth::flags::pbap_client_check_access_permission();
}

bool com_android_bluetooth_flags_pbap_client_contacts_caching() {
    return com::android::bluetooth::flags::pbap_client_contacts_caching();
}

bool com_android_bluetooth_flags_pbap_limit_call_log() {
    return com::android::bluetooth::flags::pbap_limit_call_log();
}

bool com_android_bluetooth_flags_preload_gatt_database() {
    return com::android::bluetooth::flags::preload_gatt_database();
}

bool com_android_bluetooth_flags_prevent_adding_both_pseudo_and_identity_addr() {
    return com::android::bluetooth::flags::prevent_adding_both_pseudo_and_identity_addr();
}

bool com_android_bluetooth_flags_prevent_storage_access_without_gd_running() {
    return com::android::bluetooth::flags::prevent_storage_access_without_gd_running();
}

bool com_android_bluetooth_flags_prioritized_in_ear_routing() {
    return com::android::bluetooth::flags::prioritized_in_ear_routing();
}

bool com_android_bluetooth_flags_protect_dumpsys_during_stack_shutdown() {
    return com::android::bluetooth::flags::protect_dumpsys_during_stack_shutdown();
}

bool com_android_bluetooth_flags_qc_aptx_codec_negotiation() {
    return com::android::bluetooth::flags::qc_aptx_codec_negotiation();
}

bool com_android_bluetooth_flags_qc_prioritize_lc3_codec() {
    return com::android::bluetooth::flags::qc_prioritize_lc3_codec();
}

bool com_android_bluetooth_flags_qc_send_error_at_bcc_ibr_disabled() {
    return com::android::bluetooth::flags::qc_send_error_at_bcc_ibr_disabled();
}

bool com_android_bluetooth_flags_queue_dis_requests() {
    return com::android::bluetooth::flags::queue_dis_requests();
}

bool com_android_bluetooth_flags_read_ppcp_only_for_success() {
    return com::android::bluetooth::flags::read_ppcp_only_for_success();
}

bool com_android_bluetooth_flags_read_rssi_throttling() {
    return com::android::bluetooth::flags::read_rssi_throttling();
}

bool com_android_bluetooth_flags_reboke_permission_on_unbond() {
    return com::android::bluetooth::flags::reboke_permission_on_unbond();
}

bool com_android_bluetooth_flags_reconnect_on_hogp_connection_failure() {
    return com::android::bluetooth::flags::reconnect_on_hogp_connection_failure();
}

bool com_android_bluetooth_flags_ref_counted_native_wakelock() {
    return com::android::bluetooth::flags::ref_counted_native_wakelock();
}

bool com_android_bluetooth_flags_refactor_saving_messages_and_metadata() {
    return com::android::bluetooth::flags::refactor_saving_messages_and_metadata();
}

bool com_android_bluetooth_flags_reject_bond_request_during_bonding() {
    return com::android::bluetooth::flags::reject_bond_request_during_bonding();
}

bool com_android_bluetooth_flags_release_port_in_bta_ag_rfc_fail_before_reset_context() {
    return com::android::bluetooth::flags::release_port_in_bta_ag_rfc_fail_before_reset_context();
}

bool com_android_bluetooth_flags_remove_address_cache_from_ble_scanner() {
    return com::android::bluetooth::flags::remove_address_cache_from_ble_scanner();
}

bool com_android_bluetooth_flags_remove_device_with_connection_manager() {
    return com::android::bluetooth::flags::remove_device_with_connection_manager();
}

bool com_android_bluetooth_flags_remove_handler_clear() {
    return com::android::bluetooth::flags::remove_handler_clear();
}

bool com_android_bluetooth_flags_remove_hop_from_le_adv_set_term() {
    return com::android::bluetooth::flags::remove_hop_from_le_adv_set_term();
}

bool com_android_bluetooth_flags_replace_message_loop_thread_with_gd_handler() {
    return com::android::bluetooth::flags::replace_message_loop_thread_with_gd_handler();
}

bool com_android_bluetooth_flags_reset_collision_state_on_encryption() {
    return com::android::bluetooth::flags::reset_collision_state_on_encryption();
}

bool com_android_bluetooth_flags_reset_security_flags_on_pairing_failure() {
    return com::android::bluetooth::flags::reset_security_flags_on_pairing_failure();
}

bool com_android_bluetooth_flags_reset_service_change_ind_counter() {
    return com::android::bluetooth::flags::reset_service_change_ind_counter();
}

bool com_android_bluetooth_flags_reset_state_when_removing_non_connected_hid_device() {
    return com::android::bluetooth::flags::reset_state_when_removing_non_connected_hid_device();
}

bool com_android_bluetooth_flags_resolve_address_for_adv_report() {
    return com::android::bluetooth::flags::resolve_address_for_adv_report();
}

bool com_android_bluetooth_flags_retain_address_type() {
    return com::android::bluetooth::flags::retain_address_type();
}

bool com_android_bluetooth_flags_return_correct_ble_state() {
    return com::android::bluetooth::flags::return_correct_ble_state();
}

bool com_android_bluetooth_flags_rfcomm_fix_bta_ag_rfc_acp_open_error() {
    return com::android::bluetooth::flags::rfcomm_fix_bta_ag_rfc_acp_open_error();
}

bool com_android_bluetooth_flags_rfcomm_fix_mux_collision_handling() {
    return com::android::bluetooth::flags::rfcomm_fix_mux_collision_handling();
}

bool com_android_bluetooth_flags_rnr_directly_call_gap_over_le() {
    return com::android::bluetooth::flags::rnr_directly_call_gap_over_le();
}

bool com_android_bluetooth_flags_rnr_validate_page_scan_repetition_mode() {
    return com::android::bluetooth::flags::rnr_validate_page_scan_repetition_mode();
}

bool com_android_bluetooth_flags_role_switch_after_encryption() {
    return com::android::bluetooth::flags::role_switch_after_encryption();
}

bool com_android_bluetooth_flags_rssi_scan_filter() {
    return com::android::bluetooth::flags::rssi_scan_filter();
}

bool com_android_bluetooth_flags_same_handler_for_all_modules() {
    return com::android::bluetooth::flags::same_handler_for_all_modules();
}

bool com_android_bluetooth_flags_save_cache_for_bonded_device() {
    return com::android::bluetooth::flags::save_cache_for_bonded_device();
}

bool com_android_bluetooth_flags_scan_controller_thread() {
    return com::android::bluetooth::flags::scan_controller_thread();
}

bool com_android_bluetooth_flags_sco_managed_by_audio_remove_hfp_hal() {
    return com::android::bluetooth::flags::sco_managed_by_audio_remove_hfp_hal();
}

bool com_android_bluetooth_flags_sco_state_machine_cleanup() {
    return com::android::bluetooth::flags::sco_state_machine_cleanup();
}

bool com_android_bluetooth_flags_sco_state_machine_update_in_codec_state() {
    return com::android::bluetooth::flags::sco_state_machine_update_in_codec_state();
}

bool com_android_bluetooth_flags_sdp_reset_transport_status_if_disconnect() {
    return com::android::bluetooth::flags::sdp_reset_transport_status_if_disconnect();
}

bool com_android_bluetooth_flags_send_ok_clcc_before_slc() {
    return com::android::bluetooth::flags::send_ok_clcc_before_slc();
}

bool com_android_bluetooth_flags_send_ok_on_no_action_on_chld() {
    return com::android::bluetooth::flags::send_ok_on_no_action_on_chld();
}

bool com_android_bluetooth_flags_send_opp_device_picker_extra_intent() {
    return com::android::bluetooth::flags::send_opp_device_picker_extra_intent();
}

bool com_android_bluetooth_flags_separate_encryption_queue() {
    return com::android::bluetooth::flags::separate_encryption_queue();
}

bool com_android_bluetooth_flags_service_discovery_on_connected_transport() {
    return com::android::bluetooth::flags::service_discovery_on_connected_transport();
}

bool com_android_bluetooth_flags_service_rediscovery_fix() {
    return com::android::bluetooth::flags::service_rediscovery_fix();
}

bool com_android_bluetooth_flags_set_a2dp_active_device_through_adapter_service() {
    return com::android::bluetooth::flags::set_a2dp_active_device_through_adapter_service();
}

bool com_android_bluetooth_flags_set_component_available_fix() {
    return com::android::bluetooth::flags::set_component_available_fix();
}

bool com_android_bluetooth_flags_set_max_data_length_for_lecoc() {
    return com::android::bluetooth::flags::set_max_data_length_for_lecoc();
}

bool com_android_bluetooth_flags_set_ptr_null_after_free() {
    return com::android::bluetooth::flags::set_ptr_null_after_free();
}

bool com_android_bluetooth_flags_settings_can_control_hap_preset() {
    return com::android::bluetooth::flags::settings_can_control_hap_preset();
}

bool com_android_bluetooth_flags_shutdown_main_thread_before_cleanup() {
    return com::android::bluetooth::flags::shutdown_main_thread_before_cleanup();
}

bool com_android_bluetooth_flags_simpler_hid_connection_policy() {
    return com::android::bluetooth::flags::simpler_hid_connection_policy();
}

bool com_android_bluetooth_flags_skip_excess_name_discovery() {
    return com::android::bluetooth::flags::skip_excess_name_discovery();
}

bool com_android_bluetooth_flags_skip_unknown_robust_caching() {
    return com::android::bluetooth::flags::skip_unknown_robust_caching();
}

bool com_android_bluetooth_flags_smp_connection_status_handling_when_no_acl() {
    return com::android::bluetooth::flags::smp_connection_status_handling_when_no_acl();
}

bool com_android_bluetooth_flags_sniff_offload_with_vsc_based_control() {
    return com::android::bluetooth::flags::sniff_offload_with_vsc_based_control();
}

bool com_android_bluetooth_flags_snoop_logger_save_multiple_snoop_logs() {
    return com::android::bluetooth::flags::snoop_logger_save_multiple_snoop_logs();
}

bool com_android_bluetooth_flags_socket_settings_api() {
    return com::android::bluetooth::flags::socket_settings_api();
}

bool com_android_bluetooth_flags_stack_sdp_detect_nil_property_type() {
    return com::android::bluetooth::flags::stack_sdp_detect_nil_property_type();
}

bool com_android_bluetooth_flags_start_discover_service_changed() {
    return com::android::bluetooth::flags::start_discover_service_changed();
}

bool com_android_bluetooth_flags_start_leaudio_subrate_for_active_set_only() {
    return com::android::bluetooth::flags::start_leaudio_subrate_for_active_set_only();
}

bool com_android_bluetooth_flags_stop_le_scan_system_suspend() {
    return com::android::bluetooth::flags::stop_le_scan_system_suspend();
}

bool com_android_bluetooth_flags_support_bluetooth_quality_report_v6() {
    return com::android::bluetooth::flags::support_bluetooth_quality_report_v6();
}

bool com_android_bluetooth_flags_support_metadata_device_types_apis() {
    return com::android::bluetooth::flags::support_metadata_device_types_apis();
}

bool com_android_bluetooth_flags_support_passive_scanning() {
    return com::android::bluetooth::flags::support_passive_scanning();
}

bool com_android_bluetooth_flags_support_zoomed_in_icon_metadata() {
    return com::android::bluetooth::flags::support_zoomed_in_icon_metadata();
}

bool com_android_bluetooth_flags_synchronize_codec_preferences_and_priority() {
    return com::android::bluetooth::flags::synchronize_codec_preferences_and_priority();
}

bool com_android_bluetooth_flags_synchronize_preset_can_timeout() {
    return com::android::bluetooth::flags::synchronize_preset_can_timeout();
}

bool com_android_bluetooth_flags_system_server_messenger() {
    return com::android::bluetooth::flags::system_server_messenger();
}

bool com_android_bluetooth_flags_tbs_gatt_no_longer_calls_framework() {
    return com::android::bluetooth::flags::tbs_gatt_no_longer_calls_framework();
}

bool com_android_bluetooth_flags_tbs_set_lea_from_btservice() {
    return com::android::bluetooth::flags::tbs_set_lea_from_btservice();
}

bool com_android_bluetooth_flags_temporary_pairing_tracking() {
    return com::android::bluetooth::flags::temporary_pairing_tracking();
}

bool com_android_bluetooth_flags_trigger_sec_proc_on_inc_access_req() {
    return com::android::bluetooth::flags::trigger_sec_proc_on_inc_access_req();
}

bool com_android_bluetooth_flags_unix_file_socket_creation_failure() {
    return com::android::bluetooth::flags::unix_file_socket_creation_failure();
}

bool com_android_bluetooth_flags_unrelated_device_smp_cancellation() {
    return com::android::bluetooth::flags::unrelated_device_smp_cancellation();
}

bool com_android_bluetooth_flags_update_cod_if_missing() {
    return com::android::bluetooth::flags::update_cod_if_missing();
}

bool com_android_bluetooth_flags_upgrade_le_scan_only_screen_on() {
    return com::android::bluetooth::flags::upgrade_le_scan_only_screen_on();
}

bool com_android_bluetooth_flags_upgrade_temp_bonding_on_auth_req() {
    return com::android::bluetooth::flags::upgrade_temp_bonding_on_auth_req();
}

bool com_android_bluetooth_flags_use_data_store_storage() {
    return com::android::bluetooth::flags::use_data_store_storage();
}

bool com_android_bluetooth_flags_use_entire_message_handle() {
    return com::android::bluetooth::flags::use_entire_message_handle();
}

bool com_android_bluetooth_flags_use_returned_absolute_volume() {
    return com::android::bluetooth::flags::use_returned_absolute_volume();
}

bool com_android_bluetooth_flags_use_shared_promise_for_le_address_manager() {
    return com::android::bluetooth::flags::use_shared_promise_for_le_address_manager();
}

bool com_android_bluetooth_flags_user_restriction_refactor() {
    return com::android::bluetooth::flags::user_restriction_refactor();
}

bool com_android_bluetooth_flags_user_visible_on_user_starting() {
    return com::android::bluetooth::flags::user_visible_on_user_starting();
}

bool com_android_bluetooth_flags_validate_connection_policy_before_accepting_connection() {
    return com::android::bluetooth::flags::validate_connection_policy_before_accepting_connection();
}

bool com_android_bluetooth_flags_vcp_handle_group_id_internally() {
    return com::android::bluetooth::flags::vcp_handle_group_id_internally();
}

bool com_android_bluetooth_flags_vcp_on_main_looper() {
    return com::android::bluetooth::flags::vcp_on_main_looper();
}

bool com_android_bluetooth_flags_voice_recognition_fixes() {
    return com::android::bluetooth::flags::voice_recognition_fixes();
}

bool com_android_bluetooth_flags_wait_hid_disconnect_before_marking_unused() {
    return com::android::bluetooth::flags::wait_hid_disconnect_before_marking_unused();
}

bool com_android_bluetooth_flags_watch_device_override_airplane_mode() {
    return com::android::bluetooth::flags::watch_device_override_airplane_mode();
}

