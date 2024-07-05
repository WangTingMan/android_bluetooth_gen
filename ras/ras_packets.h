
#pragma once

#include <cstdint>
#include <functional>
#include <iomanip>
#include <optional>
#include <sstream>
#include <string>
#include <type_traits>

#include "packet/base_packet_builder.h"
#include "packet/bit_inserter.h"
#include "packet/custom_field_fixed_size_interface.h"
#include "packet/iterator.h"
#include "packet/packet_builder.h"
#include "packet/packet_struct.h"
#include "packet/packet_view.h"
#include "packet/checksum_type_checker.h"
#include "packet/custom_type_checker.h"

#if __has_include(<bluetooth/log.h>)

#include <bluetooth/log.h>

#ifndef ASSERT
#define ASSERT(cond) bluetooth::log::assert_that(cond, #cond)
#endif // !defined(ASSERT)

#else

#ifndef ASSERT
#define ASSERT(cond) assert(cond)
#endif // !defined(ASSERT)

#endif // __has_include(<bluetooth/log.h>)


#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
#include "packet/raw_builder.h"
#endif


namespace bluetooth {
namespace ras {




using ::bluetooth::packet::BasePacketBuilder;
using ::bluetooth::packet::BitInserter;
using ::bluetooth::packet::CustomFieldFixedSizeInterface;
using ::bluetooth::packet::CustomTypeChecker;
using ::bluetooth::packet::Iterator;
using ::bluetooth::packet::kLittleEndian;
using ::bluetooth::packet::PacketBuilder;
using ::bluetooth::packet::PacketStruct;
using ::bluetooth::packet::PacketView;
using ::bluetooth::packet::parser::ChecksumTypeChecker;

#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
using ::bluetooth::packet::RawBuilder;
#endif
enum class PctFormat : uint8_t {IQ = 0x0,PHASE = 0x1,};


enum class RangingDoneStatus : uint8_t {ALL_RESULTS_COMPLETE = 0x0,PARTIAL_RESULTS = 0x1,ABORTED = 0xf,};


enum class SubeventDoneStatus : uint8_t {ALL_RESULTS_COMPLETE = 0x0,ABORTED = 0xf,};


enum class RangingAbortReason : uint8_t {NO_ABORT = 0x0,LOCAL_HOST_OR_REMOTE = 0x1,INSUFFICIENT_FILTERED_CHANNELS = 0x2,INSTANT_HAS_PASSED = 0x3,UNSPECIFIED = 0xf,};


enum class SubeventAbortReason : uint8_t {NO_ABORT = 0x0,LOCAL_HOST_OR_REMOTE = 0x1,NO_CS_SYNC_RECEIVED = 0x2,SCHEDULING_CONFLICTS_OR_LIMITED_RESOURCES = 0x3,UNSPECIFIED = 0xf,};


inline std::string PctFormatText(const PctFormat& param) {std::stringstream builder;switch (param) {case PctFormat::IQ:  builder << "IQ"; break;case PctFormat::PHASE:  builder << "PHASE"; break;default:  builder << "Unknown PctFormat";}builder << "(" << std::hex << "0x" << std::setfill('0')<< std::setw(2/4)<< static_cast<uint64_t>(param) << ")";return builder.str();}



inline std::string RangingDoneStatusText(const RangingDoneStatus& param) {std::stringstream builder;switch (param) {case RangingDoneStatus::ALL_RESULTS_COMPLETE:  builder << "ALL_RESULTS_COMPLETE"; break;case RangingDoneStatus::PARTIAL_RESULTS:  builder << "PARTIAL_RESULTS"; break;case RangingDoneStatus::ABORTED:  builder << "ABORTED"; break;default:  builder << "Unknown RangingDoneStatus";}builder << "(" << std::hex << "0x" << std::setfill('0')<< std::setw(4/4)<< static_cast<uint64_t>(param) << ")";return builder.str();}



inline std::string SubeventDoneStatusText(const SubeventDoneStatus& param) {std::stringstream builder;switch (param) {case SubeventDoneStatus::ALL_RESULTS_COMPLETE:  builder << "ALL_RESULTS_COMPLETE"; break;case SubeventDoneStatus::ABORTED:  builder << "ABORTED"; break;default:  builder << "Unknown SubeventDoneStatus";}builder << "(" << std::hex << "0x" << std::setfill('0')<< std::setw(4/4)<< static_cast<uint64_t>(param) << ")";return builder.str();}



inline std::string RangingAbortReasonText(const RangingAbortReason& param) {std::stringstream builder;switch (param) {case RangingAbortReason::NO_ABORT:  builder << "NO_ABORT"; break;case RangingAbortReason::LOCAL_HOST_OR_REMOTE:  builder << "LOCAL_HOST_OR_REMOTE"; break;case RangingAbortReason::INSUFFICIENT_FILTERED_CHANNELS:  builder << "INSUFFICIENT_FILTERED_CHANNELS"; break;case RangingAbortReason::INSTANT_HAS_PASSED:  builder << "INSTANT_HAS_PASSED"; break;case RangingAbortReason::UNSPECIFIED:  builder << "UNSPECIFIED"; break;default:  builder << "Unknown RangingAbortReason";}builder << "(" << std::hex << "0x" << std::setfill('0')<< std::setw(4/4)<< static_cast<uint64_t>(param) << ")";return builder.str();}



inline std::string SubeventAbortReasonText(const SubeventAbortReason& param) {std::stringstream builder;switch (param) {case SubeventAbortReason::NO_ABORT:  builder << "NO_ABORT"; break;case SubeventAbortReason::LOCAL_HOST_OR_REMOTE:  builder << "LOCAL_HOST_OR_REMOTE"; break;case SubeventAbortReason::NO_CS_SYNC_RECEIVED:  builder << "NO_CS_SYNC_RECEIVED"; break;case SubeventAbortReason::SCHEDULING_CONFLICTS_OR_LIMITED_RESOURCES:  builder << "SCHEDULING_CONFLICTS_OR_LIMITED_RESOURCES"; break;case SubeventAbortReason::UNSPECIFIED:  builder << "UNSPECIFIED"; break;default:  builder << "Unknown SubeventAbortReason";}builder << "(" << std::hex << "0x" << std::setfill('0')<< std::setw(4/4)<< static_cast<uint64_t>(param) << ")";return builder.str();}




/* Done ChecksumChecks */

class StepMode : public PacketStruct<kLittleEndian> { public:StepMode() {}
StepMode(uint8_t mode_type, uint8_t aborted)
 : mode_type_(mode_type), aborted_(aborted)
{}
 public:
  virtual ~StepMode() = default;
protected:void SerializeHeader(BitInserter& i ) const {insert(mode_type_, i,2);insert(static_cast<uint8_t>(0) /* Reserved */, i, 5 );
insert(aborted_, i,1);}

void SerializeFooter(BitInserter&) const {}

public:virtual void Serialize(BitInserter& i) const override {SerializeHeader(i);SerializeFooter(i);}

static Iterator<kLittleEndian> Parse(StepMode* to_fill, Iterator<kLittleEndian> struct_begin_it ) {auto to_bound = struct_begin_it;size_t end_index = struct_begin_it.NumBytesRemaining();if (end_index < 1){ return struct_begin_it.Subrange(0,0);}{if (to_bound.NumBytesRemaining() < 1){ return to_bound.Subrange(to_bound.NumBytesRemaining(),0);}}{auto mode_type_it = to_bound + (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;auto mode_type_ptr = &to_fill->mode_type_;auto extracted_value = mode_type_it.extract<uint8_t>();extracted_value &= 0x3;*mode_type_ptr = static_cast<uint8_t>(extracted_value);}{auto aborted_it = to_bound + (/* Bits: */ 7 + /* Dynamic: */ 0) / 8;auto aborted_ptr = &to_fill->aborted_;auto extracted_value = aborted_it.extract<uint8_t>();extracted_value >>= 7;extracted_value &= 0x1;*aborted_ptr = static_cast<uint8_t>(extracted_value);}return struct_begin_it + to_fill->size();}
protected:size_t BitsOfHeader() const {return 0 + /* Bits: */ 2 + /* Dynamic: */ 0 + /* Bits: */ 5 + /* Dynamic: */ 0 + /* Bits: */ 1 + /* Dynamic: */ 0;}

size_t BitsOfFooter() const {return 0;}

public:virtual size_t size() const override {return (BitsOfHeader() / 8) + (BitsOfFooter() / 8);}



std::string ToString() const {std::stringstream ss;ss << std::hex << std::showbase << "StepMode { ";ss << "mode_type = " << static_cast<uint64_t>(mode_type_) << ", aborted = " << static_cast<uint64_t>(aborted_);ss << " }";return ss.str();}

uint8_t mode_type_{};uint8_t aborted_{};};


class RasSubeventHeader : public PacketStruct<kLittleEndian> { public:RasSubeventHeader() {}
RasSubeventHeader(uint16_t start_acl_conn_event, uint16_t frequency_compensation, RangingDoneStatus ranging_done_status, SubeventDoneStatus subevent_done_status, RangingAbortReason ranging_abort_reason, SubeventAbortReason subevent_abort_reason, uint8_t reference_power_level, uint8_t num_steps_reported)
 : start_acl_conn_event_(start_acl_conn_event), frequency_compensation_(frequency_compensation), ranging_done_status_(ranging_done_status), subevent_done_status_(subevent_done_status), ranging_abort_reason_(ranging_abort_reason), subevent_abort_reason_(subevent_abort_reason), reference_power_level_(reference_power_level), num_steps_reported_(num_steps_reported)
{}
 public:
  virtual ~RasSubeventHeader() = default;
protected:void SerializeHeader(BitInserter& i ) const {insert(start_acl_conn_event_, i,16);insert(frequency_compensation_, i,16);insert(static_cast<uint8_t>(ranging_done_status_), i, 4);insert(static_cast<uint8_t>(subevent_done_status_), i, 4);insert(static_cast<uint8_t>(ranging_abort_reason_), i, 4);insert(static_cast<uint8_t>(subevent_abort_reason_), i, 4);i.insert_byte(reference_power_level_);i.insert_byte(num_steps_reported_);}

void SerializeFooter(BitInserter&) const {}

public:virtual void Serialize(BitInserter& i) const override {SerializeHeader(i);SerializeFooter(i);}

static Iterator<kLittleEndian> Parse(RasSubeventHeader* to_fill, Iterator<kLittleEndian> struct_begin_it ) {auto to_bound = struct_begin_it;size_t end_index = struct_begin_it.NumBytesRemaining();if (end_index < 8){ return struct_begin_it.Subrange(0,0);}{if (to_bound.NumBytesRemaining() < 8){ return to_bound.Subrange(to_bound.NumBytesRemaining(),0);}}{auto start_acl_conn_event_it = to_bound + (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;auto start_acl_conn_event_ptr = &to_fill->start_acl_conn_event_;auto extracted_value = start_acl_conn_event_it.extract<uint16_t>();*start_acl_conn_event_ptr = static_cast<uint16_t>(extracted_value);}{auto frequency_compensation_it = to_bound + (/* Bits: */ 16 + /* Dynamic: */ 0) / 8;auto frequency_compensation_ptr = &to_fill->frequency_compensation_;auto extracted_value = frequency_compensation_it.extract<uint16_t>();*frequency_compensation_ptr = static_cast<uint16_t>(extracted_value);}{auto ranging_done_status_it = to_bound + (/* Bits: */ 32 + /* Dynamic: */ 0) / 8;auto ranging_done_status_ptr = &to_fill->ranging_done_status_;auto extracted_value = ranging_done_status_it.extract<uint8_t>();extracted_value &= 0xf;*ranging_done_status_ptr = static_cast<RangingDoneStatus>(extracted_value);}{auto subevent_done_status_it = to_bound + (/* Bits: */ 36 + /* Dynamic: */ 0) / 8;auto subevent_done_status_ptr = &to_fill->subevent_done_status_;auto extracted_value = subevent_done_status_it.extract<uint8_t>();extracted_value >>= 4;extracted_value &= 0xf;*subevent_done_status_ptr = static_cast<SubeventDoneStatus>(extracted_value);}{auto ranging_abort_reason_it = to_bound + (/* Bits: */ 40 + /* Dynamic: */ 0) / 8;auto ranging_abort_reason_ptr = &to_fill->ranging_abort_reason_;auto extracted_value = ranging_abort_reason_it.extract<uint8_t>();extracted_value &= 0xf;*ranging_abort_reason_ptr = static_cast<RangingAbortReason>(extracted_value);}{auto subevent_abort_reason_it = to_bound + (/* Bits: */ 44 + /* Dynamic: */ 0) / 8;auto subevent_abort_reason_ptr = &to_fill->subevent_abort_reason_;auto extracted_value = subevent_abort_reason_it.extract<uint8_t>();extracted_value >>= 4;extracted_value &= 0xf;*subevent_abort_reason_ptr = static_cast<SubeventAbortReason>(extracted_value);}{auto reference_power_level_it = to_bound + (/* Bits: */ 48 + /* Dynamic: */ 0) / 8;auto reference_power_level_ptr = &to_fill->reference_power_level_;auto extracted_value = reference_power_level_it.extract<uint8_t>();*reference_power_level_ptr = static_cast<uint8_t>(extracted_value);}{auto num_steps_reported_it = to_bound + (/* Bits: */ 56 + /* Dynamic: */ 0) / 8;auto num_steps_reported_ptr = &to_fill->num_steps_reported_;auto extracted_value = num_steps_reported_it.extract<uint8_t>();*num_steps_reported_ptr = static_cast<uint8_t>(extracted_value);}return struct_begin_it + to_fill->size();}
protected:size_t BitsOfHeader() const {return 0 + /* Bits: */ 16 + /* Dynamic: */ 0 + /* Bits: */ 16 + /* Dynamic: */ 0 + /* Bits: */ 4 + /* Dynamic: */ 0 + /* Bits: */ 4 + /* Dynamic: */ 0 + /* Bits: */ 4 + /* Dynamic: */ 0 + /* Bits: */ 4 + /* Dynamic: */ 0 + /* Bits: */ 8 + /* Dynamic: */ 0 + /* Bits: */ 8 + /* Dynamic: */ 0;}

size_t BitsOfFooter() const {return 0;}

public:virtual size_t size() const override {return (BitsOfHeader() / 8) + (BitsOfFooter() / 8);}



std::string ToString() const {std::stringstream ss;ss << std::hex << std::showbase << "RasSubeventHeader { ";ss << "start_acl_conn_event = " << static_cast<uint64_t>(start_acl_conn_event_) << ", frequency_compensation = " << static_cast<uint64_t>(frequency_compensation_) << ", ranging_done_status = " << RangingDoneStatusText(ranging_done_status_) << ", subevent_done_status = " << SubeventDoneStatusText(subevent_done_status_) << ", ranging_abort_reason = " << RangingAbortReasonText(ranging_abort_reason_) << ", subevent_abort_reason = " << SubeventAbortReasonText(subevent_abort_reason_) << ", reference_power_level = " << static_cast<uint64_t>(reference_power_level_) << ", num_steps_reported = " << static_cast<uint64_t>(num_steps_reported_);ss << " }";return ss.str();}

uint16_t start_acl_conn_event_{};uint16_t frequency_compensation_{};RangingDoneStatus ranging_done_status_{};SubeventDoneStatus subevent_done_status_{};RangingAbortReason ranging_abort_reason_{};SubeventAbortReason subevent_abort_reason_{};uint8_t reference_power_level_{};uint8_t num_steps_reported_{};};


class RangingHeader : public PacketStruct<kLittleEndian> { public:RangingHeader() {}
RangingHeader(uint16_t ranging_counter, uint8_t configuration_id, uint8_t selected_tx_power, uint8_t antenna_paths_mask, PctFormat pct_format)
 : ranging_counter_(ranging_counter), configuration_id_(configuration_id), selected_tx_power_(selected_tx_power), antenna_paths_mask_(antenna_paths_mask), pct_format_(pct_format)
{}
 public:
  virtual ~RangingHeader() = default;
protected:void SerializeHeader(BitInserter& i ) const {insert(ranging_counter_, i,12);insert(configuration_id_, i,4);i.insert_byte(selected_tx_power_);insert(antenna_paths_mask_, i,4);insert(static_cast<uint8_t>(0) /* Reserved */, i, 2 );
insert(static_cast<uint8_t>(pct_format_), i, 2);}

void SerializeFooter(BitInserter&) const {}

public:virtual void Serialize(BitInserter& i) const override {SerializeHeader(i);SerializeFooter(i);}

static Iterator<kLittleEndian> Parse(RangingHeader* to_fill, Iterator<kLittleEndian> struct_begin_it ) {auto to_bound = struct_begin_it;size_t end_index = struct_begin_it.NumBytesRemaining();if (end_index < 4){ return struct_begin_it.Subrange(0,0);}{if (to_bound.NumBytesRemaining() < 4){ return to_bound.Subrange(to_bound.NumBytesRemaining(),0);}}{auto ranging_counter_it = to_bound + (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;auto ranging_counter_ptr = &to_fill->ranging_counter_;auto extracted_value = ranging_counter_it.extract<uint16_t>();extracted_value &= 0xfff;*ranging_counter_ptr = static_cast<uint16_t>(extracted_value);}{auto configuration_id_it = to_bound + (/* Bits: */ 12 + /* Dynamic: */ 0) / 8;auto configuration_id_ptr = &to_fill->configuration_id_;auto extracted_value = configuration_id_it.extract<uint8_t>();extracted_value >>= 4;extracted_value &= 0xf;*configuration_id_ptr = static_cast<uint8_t>(extracted_value);}{auto selected_tx_power_it = to_bound + (/* Bits: */ 16 + /* Dynamic: */ 0) / 8;auto selected_tx_power_ptr = &to_fill->selected_tx_power_;auto extracted_value = selected_tx_power_it.extract<uint8_t>();*selected_tx_power_ptr = static_cast<uint8_t>(extracted_value);}{auto antenna_paths_mask_it = to_bound + (/* Bits: */ 24 + /* Dynamic: */ 0) / 8;auto antenna_paths_mask_ptr = &to_fill->antenna_paths_mask_;auto extracted_value = antenna_paths_mask_it.extract<uint8_t>();extracted_value &= 0xf;*antenna_paths_mask_ptr = static_cast<uint8_t>(extracted_value);}{auto pct_format_it = to_bound + (/* Bits: */ 30 + /* Dynamic: */ 0) / 8;auto pct_format_ptr = &to_fill->pct_format_;auto extracted_value = pct_format_it.extract<uint8_t>();extracted_value >>= 6;extracted_value &= 0x3;*pct_format_ptr = static_cast<PctFormat>(extracted_value);}return struct_begin_it + to_fill->size();}
protected:size_t BitsOfHeader() const {return 0 + /* Bits: */ 12 + /* Dynamic: */ 0 + /* Bits: */ 4 + /* Dynamic: */ 0 + /* Bits: */ 8 + /* Dynamic: */ 0 + /* Bits: */ 4 + /* Dynamic: */ 0 + /* Bits: */ 2 + /* Dynamic: */ 0 + /* Bits: */ 2 + /* Dynamic: */ 0;}

size_t BitsOfFooter() const {return 0;}

public:virtual size_t size() const override {return (BitsOfHeader() / 8) + (BitsOfFooter() / 8);}



std::string ToString() const {std::stringstream ss;ss << std::hex << std::showbase << "RangingHeader { ";ss << "ranging_counter = " << static_cast<uint64_t>(ranging_counter_) << ", configuration_id = " << static_cast<uint64_t>(configuration_id_) << ", selected_tx_power = " << static_cast<uint64_t>(selected_tx_power_) << ", antenna_paths_mask = " << static_cast<uint64_t>(antenna_paths_mask_) << ", pct_format = " << PctFormatText(pct_format_);ss << " }";return ss.str();}

uint16_t ranging_counter_{};uint8_t configuration_id_{};uint8_t selected_tx_power_{};uint8_t antenna_paths_mask_{};PctFormat pct_format_{};};


class SegmentationHeader : public PacketStruct<kLittleEndian> { public:SegmentationHeader() {}
SegmentationHeader(uint8_t first_segment, uint8_t last_segment, uint8_t rolling_segment_counter)
 : first_segment_(first_segment), last_segment_(last_segment), rolling_segment_counter_(rolling_segment_counter)
{}
 public:
  virtual ~SegmentationHeader() = default;
protected:void SerializeHeader(BitInserter& i ) const {insert(first_segment_, i,1);insert(last_segment_, i,1);insert(rolling_segment_counter_, i,6);}

void SerializeFooter(BitInserter&) const {}

public:virtual void Serialize(BitInserter& i) const override {SerializeHeader(i);SerializeFooter(i);}

static Iterator<kLittleEndian> Parse(SegmentationHeader* to_fill, Iterator<kLittleEndian> struct_begin_it ) {auto to_bound = struct_begin_it;size_t end_index = struct_begin_it.NumBytesRemaining();if (end_index < 1){ return struct_begin_it.Subrange(0,0);}{if (to_bound.NumBytesRemaining() < 1){ return to_bound.Subrange(to_bound.NumBytesRemaining(),0);}}{auto first_segment_it = to_bound + (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;auto first_segment_ptr = &to_fill->first_segment_;auto extracted_value = first_segment_it.extract<uint8_t>();extracted_value &= 0x1;*first_segment_ptr = static_cast<uint8_t>(extracted_value);}{auto last_segment_it = to_bound + (/* Bits: */ 1 + /* Dynamic: */ 0) / 8;auto last_segment_ptr = &to_fill->last_segment_;auto extracted_value = last_segment_it.extract<uint8_t>();extracted_value >>= 1;extracted_value &= 0x1;*last_segment_ptr = static_cast<uint8_t>(extracted_value);}{auto rolling_segment_counter_it = to_bound + (/* Bits: */ 2 + /* Dynamic: */ 0) / 8;auto rolling_segment_counter_ptr = &to_fill->rolling_segment_counter_;auto extracted_value = rolling_segment_counter_it.extract<uint8_t>();extracted_value >>= 2;extracted_value &= 0x3f;*rolling_segment_counter_ptr = static_cast<uint8_t>(extracted_value);}return struct_begin_it + to_fill->size();}
protected:size_t BitsOfHeader() const {return 0 + /* Bits: */ 1 + /* Dynamic: */ 0 + /* Bits: */ 1 + /* Dynamic: */ 0 + /* Bits: */ 6 + /* Dynamic: */ 0;}

size_t BitsOfFooter() const {return 0;}

public:virtual size_t size() const override {return (BitsOfHeader() / 8) + (BitsOfFooter() / 8);}



std::string ToString() const {std::stringstream ss;ss << std::hex << std::showbase << "SegmentationHeader { ";ss << "first_segment = " << static_cast<uint64_t>(first_segment_) << ", last_segment = " << static_cast<uint64_t>(last_segment_) << ", rolling_segment_counter = " << static_cast<uint64_t>(rolling_segment_counter_);ss << " }";return ss.str();}

uint8_t first_segment_{};uint8_t last_segment_{};uint8_t rolling_segment_counter_{};};




class RasSubeventView : public PacketView<kLittleEndian> { public:static RasSubeventView Create(PacketView<kLittleEndian> packet){ return RasSubeventView(std::move(packet)); }static std::optional<RasSubeventView> CreateOptional(PacketView<kLittleEndian> packet){ auto to_validate = RasSubeventView::Create(std::move(packet));if (to_validate.IsValid()) { return to_validate; }else {return {};}}
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static RasSubeventView FromBytes(std::vector<uint8_t> bytes) {auto vec = std::make_shared<std::vector<uint8_t>>(bytes);return RasSubeventView::Create(PacketView<kLittleEndian>(vec));}
#endif
RasSubeventHeader GetSubeventHeader() const {ASSERT(was_validated_);size_t end_index = size();auto to_bound = begin();size_t field_begin = (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;size_t field_end = field_begin + (/* Bits: */ 64 + /* Dynamic: */ 0) / 8;if (field_end > end_index) { field_end = end_index; }auto subevent_header_it = to_bound.Subrange(field_begin, field_end - field_begin); RasSubeventHeader subevent_header_value{};RasSubeventHeader* subevent_header_ptr = &subevent_header_value;subevent_header_it = RasSubeventHeader::Parse(subevent_header_ptr, subevent_header_it);return subevent_header_value;}

std::vector<uint8_t> GetSubeventData() const {ASSERT(was_validated_);size_t end_index = size();auto to_bound = begin();size_t field_begin = (/* Bits: */ 64 + /* Dynamic: */ 0) / 8;size_t field_end = end_index - (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;auto subevent_data_it = to_bound.Subrange(field_begin, field_end - field_begin); std::vector<uint8_t> subevent_data_value{};std::vector<uint8_t>* subevent_data_ptr = &subevent_data_value;auto val_it = subevent_data_it;while (val_it.NumBytesRemaining() >= 1) {uint8_t val_value;uint8_t* val_ptr = &val_value;auto extracted_value = val_it.extract<uint8_t>();*val_ptr = static_cast<uint8_t>(extracted_value);if (val_ptr != nullptr) { subevent_data_ptr->push_back(val_value);}}return subevent_data_value;}

bool IsValid() {
  if (was_validated_) {
    return true;
  } else {
    was_validated_ = true;
    return (was_validated_ = Validate());
  }
}
protected:
virtual bool Validate() const {
auto it = begin() + (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;it += 8 /* Total size of the fixed fields */;if (it > end()) return false;

return true;}
bool was_validated_{false};

 public:virtual std::string ToString() const  {std::stringstream ss;ss << std::showbase << std::hex << "RasSubevent { ";ss << ""  << "subevent_header = " << GetSubeventHeader().ToString() << ", subevent_data = " << "VECTOR[";for (size_t index = 0; index < GetSubeventData().size(); index++) {ss << ((index == 0) ? "" : ", ") << static_cast<uint64_t>((GetSubeventData()[index]));}ss << "]";ss << " }";return ss.str();}

 protected:
explicit RasSubeventView(PacketView<kLittleEndian> packet)  : PacketView<kLittleEndian>(packet) { was_validated_ = false;}};


class FirstRangingDataSegmentView : public PacketView<kLittleEndian> { public:static FirstRangingDataSegmentView Create(PacketView<kLittleEndian> packet){ return FirstRangingDataSegmentView(std::move(packet)); }static std::optional<FirstRangingDataSegmentView> CreateOptional(PacketView<kLittleEndian> packet){ auto to_validate = FirstRangingDataSegmentView::Create(std::move(packet));if (to_validate.IsValid()) { return to_validate; }else {return {};}}
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static FirstRangingDataSegmentView FromBytes(std::vector<uint8_t> bytes) {auto vec = std::make_shared<std::vector<uint8_t>>(bytes);return FirstRangingDataSegmentView::Create(PacketView<kLittleEndian>(vec));}
#endif
SegmentationHeader GetSegmentationHeader() const {ASSERT(was_validated_);size_t end_index = size();auto to_bound = begin();size_t field_begin = (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;size_t field_end = field_begin + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;if (field_end > end_index) { field_end = end_index; }auto segmentation_header_it = to_bound.Subrange(field_begin, field_end - field_begin); SegmentationHeader segmentation_header_value{};SegmentationHeader* segmentation_header_ptr = &segmentation_header_value;segmentation_header_it = SegmentationHeader::Parse(segmentation_header_ptr, segmentation_header_it);return segmentation_header_value;}

RangingHeader GetRangingHeader() const {ASSERT(was_validated_);size_t end_index = size();auto to_bound = begin();size_t field_begin = (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;size_t field_end = field_begin + (/* Bits: */ 32 + /* Dynamic: */ 0) / 8;if (field_end > end_index) { field_end = end_index; }auto ranging_header_it = to_bound.Subrange(field_begin, field_end - field_begin); RangingHeader ranging_header_value{};RangingHeader* ranging_header_ptr = &ranging_header_value;ranging_header_it = RangingHeader::Parse(ranging_header_ptr, ranging_header_it);return ranging_header_value;}

std::vector<uint8_t> GetData() const {ASSERT(was_validated_);size_t end_index = size();auto to_bound = begin();size_t field_begin = (/* Bits: */ 40 + /* Dynamic: */ 0) / 8;size_t field_end = end_index - (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;auto data_it = to_bound.Subrange(field_begin, field_end - field_begin); std::vector<uint8_t> data_value{};std::vector<uint8_t>* data_ptr = &data_value;auto val_it = data_it;while (val_it.NumBytesRemaining() >= 1) {uint8_t val_value;uint8_t* val_ptr = &val_value;auto extracted_value = val_it.extract<uint8_t>();*val_ptr = static_cast<uint8_t>(extracted_value);if (val_ptr != nullptr) { data_ptr->push_back(val_value);}}return data_value;}

bool IsValid() {
  if (was_validated_) {
    return true;
  } else {
    was_validated_ = true;
    return (was_validated_ = Validate());
  }
}
protected:
virtual bool Validate() const {
auto it = begin() + (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;it += 5 /* Total size of the fixed fields */;if (it > end()) return false;


return true;}
bool was_validated_{false};

 public:virtual std::string ToString() const  {std::stringstream ss;ss << std::showbase << std::hex << "FirstRangingDataSegment { ";ss << ""  << "segmentation_header = " << GetSegmentationHeader().ToString() << ", ranging_header = " << GetRangingHeader().ToString() << ", data = " << "VECTOR[";for (size_t index = 0; index < GetData().size(); index++) {ss << ((index == 0) ? "" : ", ") << static_cast<uint64_t>((GetData()[index]));}ss << "]";ss << " }";return ss.str();}

 protected:
explicit FirstRangingDataSegmentView(PacketView<kLittleEndian> packet)  : PacketView<kLittleEndian>(packet) { was_validated_ = false;}};


class RangingDataSegmentView : public PacketView<kLittleEndian> { public:static RangingDataSegmentView Create(PacketView<kLittleEndian> packet){ return RangingDataSegmentView(std::move(packet)); }static std::optional<RangingDataSegmentView> CreateOptional(PacketView<kLittleEndian> packet){ auto to_validate = RangingDataSegmentView::Create(std::move(packet));if (to_validate.IsValid()) { return to_validate; }else {return {};}}
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static RangingDataSegmentView FromBytes(std::vector<uint8_t> bytes) {auto vec = std::make_shared<std::vector<uint8_t>>(bytes);return RangingDataSegmentView::Create(PacketView<kLittleEndian>(vec));}
#endif
SegmentationHeader GetSegmentationHeader() const {ASSERT(was_validated_);size_t end_index = size();auto to_bound = begin();size_t field_begin = (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;size_t field_end = field_begin + (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;if (field_end > end_index) { field_end = end_index; }auto segmentation_header_it = to_bound.Subrange(field_begin, field_end - field_begin); SegmentationHeader segmentation_header_value{};SegmentationHeader* segmentation_header_ptr = &segmentation_header_value;segmentation_header_it = SegmentationHeader::Parse(segmentation_header_ptr, segmentation_header_it);return segmentation_header_value;}

std::vector<uint8_t> GetData() const {ASSERT(was_validated_);size_t end_index = size();auto to_bound = begin();size_t field_begin = (/* Bits: */ 8 + /* Dynamic: */ 0) / 8;size_t field_end = end_index - (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;auto data_it = to_bound.Subrange(field_begin, field_end - field_begin); std::vector<uint8_t> data_value{};std::vector<uint8_t>* data_ptr = &data_value;auto val_it = data_it;while (val_it.NumBytesRemaining() >= 1) {uint8_t val_value;uint8_t* val_ptr = &val_value;auto extracted_value = val_it.extract<uint8_t>();*val_ptr = static_cast<uint8_t>(extracted_value);if (val_ptr != nullptr) { data_ptr->push_back(val_value);}}return data_value;}

bool IsValid() {
  if (was_validated_) {
    return true;
  } else {
    was_validated_ = true;
    return (was_validated_ = Validate());
  }
}
protected:
virtual bool Validate() const {
auto it = begin() + (/* Bits: */ 0 + /* Dynamic: */ 0) / 8;it += 1 /* Total size of the fixed fields */;if (it > end()) return false;

return true;}
bool was_validated_{false};

 public:virtual std::string ToString() const  {std::stringstream ss;ss << std::showbase << std::hex << "RangingDataSegment { ";ss << ""  << "segmentation_header = " << GetSegmentationHeader().ToString() << ", data = " << "VECTOR[";for (size_t index = 0; index < GetData().size(); index++) {ss << ((index == 0) ? "" : ", ") << static_cast<uint64_t>((GetData()[index]));}ss << "]";ss << " }";return ss.str();}

 protected:
explicit RangingDataSegmentView(PacketView<kLittleEndian> packet)  : PacketView<kLittleEndian>(packet) { was_validated_ = false;}};


class RasSubeventBuilder : public PacketBuilder<kLittleEndian> { public:  virtual ~RasSubeventBuilder() = default;static std::unique_ptr<RasSubeventBuilder> Create(RasSubeventHeader subevent_header, const std::vector<uint8_t>& subevent_data) {auto builder = std::unique_ptr<RasSubeventBuilder>(new RasSubeventBuilder(subevent_header, subevent_data));return builder;}

#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static std::unique_ptr<RasSubeventBuilder> FromView(RasSubeventView view) {if (!view.IsValid()) return nullptr;return RasSubeventBuilder::Create(view.GetSubeventHeader(), view.GetSubeventData());}
#endif

protected:void SerializeHeader(BitInserter& i ) const {subevent_header_.Serialize(i);for (const auto& val_ : subevent_data_) {i.insert_byte(val_);}
}

void SerializeFooter(BitInserter&) const {}

public:virtual void Serialize(BitInserter& i) const override {SerializeHeader(i);SerializeFooter(i);}

protected:size_t BitsOfHeader() const {return 0 + /* Bits: */ 0 + /* Dynamic: */ (subevent_header_.size() * 8) + /* Bits: */ 0 + /* Dynamic: */ (static_cast<size_t>(subevent_data_.size()) * 8);}

size_t BitsOfFooter() const {return 0;}

public:virtual size_t size() const override {return (BitsOfHeader() / 8) + (BitsOfFooter() / 8);}

 protected:
explicit RasSubeventBuilder(RasSubeventHeader subevent_header, const std::vector<uint8_t>& subevent_data) :subevent_header_(subevent_header),subevent_data_(subevent_data) {}


RasSubeventHeader subevent_header_{};std::vector<uint8_t> subevent_data_{};};
#ifdef PACKET_TESTING
#define DEFINE_AND_INSTANTIATE_RasSubeventReflectionTest(...)class RasSubeventReflectionTest : public testing::TestWithParam<std::vector<uint8_t>> { public: void CompareBytes(std::vector<uint8_t> captured_packet) {RasSubeventView view = RasSubeventView::FromBytes(captured_packet);if (!view.IsValid()) { log::info("Invalid Packet Bytes (size = {})", view.size());for (size_t i = 0; i < view.size(); i++) { log::info("{:5}:{:02x}", i, *(view.begin() + i)); }}ASSERT_TRUE(view.IsValid());auto packet = RasSubeventBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);ASSERT_EQ(*packet_bytes, captured_packet);}};TEST_P(RasSubeventReflectionTest, generatedReflectionTest) {CompareBytes(GetParam());}INSTANTIATE_TEST_SUITE_P(RasSubevent_reflection, RasSubeventReflectionTest, testing::Values(__VA_ARGS__))
#endif
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING)
#define DEFINE_RasSubeventReflectionFuzzTest() void RunRasSubeventReflectionFuzzTest(const uint8_t* data, size_t size) {auto vec = std::vector<uint8_t>(data, data + size);RasSubeventView view = RasSubeventView::FromBytes(vec);if (!view.IsValid()) { return; }auto packet = RasSubeventBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);}
#endif

#ifdef PACKET_FUZZ_TESTING
#define DEFINE_AND_REGISTER_RasSubeventReflectionFuzzTest(REGISTRY) DEFINE_RasSubeventReflectionFuzzTest(); class RasSubeventReflectionFuzzTestRegistrant {public: explicit RasSubeventReflectionFuzzTestRegistrant(std::vector<void(*)(const uint8_t*, size_t)>& fuzz_test_registry) {fuzz_test_registry.push_back(RunRasSubeventReflectionFuzzTest);}}; RasSubeventReflectionFuzzTestRegistrant RasSubevent_reflection_fuzz_test_registrant(REGISTRY);
#endif


class FirstRangingDataSegmentBuilder : public PacketBuilder<kLittleEndian> { public:  virtual ~FirstRangingDataSegmentBuilder() = default;static std::unique_ptr<FirstRangingDataSegmentBuilder> Create(SegmentationHeader segmentation_header, RangingHeader ranging_header, const std::vector<uint8_t>& data) {auto builder = std::unique_ptr<FirstRangingDataSegmentBuilder>(new FirstRangingDataSegmentBuilder(segmentation_header, ranging_header, data));return builder;}

#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static std::unique_ptr<FirstRangingDataSegmentBuilder> FromView(FirstRangingDataSegmentView view) {if (!view.IsValid()) return nullptr;return FirstRangingDataSegmentBuilder::Create(view.GetSegmentationHeader(), view.GetRangingHeader(), view.GetData());}
#endif

protected:void SerializeHeader(BitInserter& i ) const {segmentation_header_.Serialize(i);ranging_header_.Serialize(i);for (const auto& val_ : data_) {i.insert_byte(val_);}
}

void SerializeFooter(BitInserter&) const {}

public:virtual void Serialize(BitInserter& i) const override {SerializeHeader(i);SerializeFooter(i);}

protected:size_t BitsOfHeader() const {return 0 + /* Bits: */ 0 + /* Dynamic: */ (segmentation_header_.size() * 8) + /* Bits: */ 0 + /* Dynamic: */ (ranging_header_.size() * 8) + /* Bits: */ 0 + /* Dynamic: */ (static_cast<size_t>(data_.size()) * 8);}

size_t BitsOfFooter() const {return 0;}

public:virtual size_t size() const override {return (BitsOfHeader() / 8) + (BitsOfFooter() / 8);}

 protected:
explicit FirstRangingDataSegmentBuilder(SegmentationHeader segmentation_header, RangingHeader ranging_header, const std::vector<uint8_t>& data) :segmentation_header_(segmentation_header),ranging_header_(ranging_header),data_(data) {}


SegmentationHeader segmentation_header_{};RangingHeader ranging_header_{};std::vector<uint8_t> data_{};};
#ifdef PACKET_TESTING
#define DEFINE_AND_INSTANTIATE_FirstRangingDataSegmentReflectionTest(...)class FirstRangingDataSegmentReflectionTest : public testing::TestWithParam<std::vector<uint8_t>> { public: void CompareBytes(std::vector<uint8_t> captured_packet) {FirstRangingDataSegmentView view = FirstRangingDataSegmentView::FromBytes(captured_packet);if (!view.IsValid()) { log::info("Invalid Packet Bytes (size = {})", view.size());for (size_t i = 0; i < view.size(); i++) { log::info("{:5}:{:02x}", i, *(view.begin() + i)); }}ASSERT_TRUE(view.IsValid());auto packet = FirstRangingDataSegmentBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);ASSERT_EQ(*packet_bytes, captured_packet);}};TEST_P(FirstRangingDataSegmentReflectionTest, generatedReflectionTest) {CompareBytes(GetParam());}INSTANTIATE_TEST_SUITE_P(FirstRangingDataSegment_reflection, FirstRangingDataSegmentReflectionTest, testing::Values(__VA_ARGS__))
#endif
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING)
#define DEFINE_FirstRangingDataSegmentReflectionFuzzTest() void RunFirstRangingDataSegmentReflectionFuzzTest(const uint8_t* data, size_t size) {auto vec = std::vector<uint8_t>(data, data + size);FirstRangingDataSegmentView view = FirstRangingDataSegmentView::FromBytes(vec);if (!view.IsValid()) { return; }auto packet = FirstRangingDataSegmentBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);}
#endif

#ifdef PACKET_FUZZ_TESTING
#define DEFINE_AND_REGISTER_FirstRangingDataSegmentReflectionFuzzTest(REGISTRY) DEFINE_FirstRangingDataSegmentReflectionFuzzTest(); class FirstRangingDataSegmentReflectionFuzzTestRegistrant {public: explicit FirstRangingDataSegmentReflectionFuzzTestRegistrant(std::vector<void(*)(const uint8_t*, size_t)>& fuzz_test_registry) {fuzz_test_registry.push_back(RunFirstRangingDataSegmentReflectionFuzzTest);}}; FirstRangingDataSegmentReflectionFuzzTestRegistrant FirstRangingDataSegment_reflection_fuzz_test_registrant(REGISTRY);
#endif


class RangingDataSegmentBuilder : public PacketBuilder<kLittleEndian> { public:  virtual ~RangingDataSegmentBuilder() = default;static std::unique_ptr<RangingDataSegmentBuilder> Create(SegmentationHeader segmentation_header, const std::vector<uint8_t>& data) {auto builder = std::unique_ptr<RangingDataSegmentBuilder>(new RangingDataSegmentBuilder(segmentation_header, data));return builder;}

#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING) || defined(FUZZ_TARGET)
static std::unique_ptr<RangingDataSegmentBuilder> FromView(RangingDataSegmentView view) {if (!view.IsValid()) return nullptr;return RangingDataSegmentBuilder::Create(view.GetSegmentationHeader(), view.GetData());}
#endif

protected:void SerializeHeader(BitInserter& i ) const {segmentation_header_.Serialize(i);for (const auto& val_ : data_) {i.insert_byte(val_);}
}

void SerializeFooter(BitInserter&) const {}

public:virtual void Serialize(BitInserter& i) const override {SerializeHeader(i);SerializeFooter(i);}

protected:size_t BitsOfHeader() const {return 0 + /* Bits: */ 0 + /* Dynamic: */ (segmentation_header_.size() * 8) + /* Bits: */ 0 + /* Dynamic: */ (static_cast<size_t>(data_.size()) * 8);}

size_t BitsOfFooter() const {return 0;}

public:virtual size_t size() const override {return (BitsOfHeader() / 8) + (BitsOfFooter() / 8);}

 protected:
explicit RangingDataSegmentBuilder(SegmentationHeader segmentation_header, const std::vector<uint8_t>& data) :segmentation_header_(segmentation_header),data_(data) {}


SegmentationHeader segmentation_header_{};std::vector<uint8_t> data_{};};
#ifdef PACKET_TESTING
#define DEFINE_AND_INSTANTIATE_RangingDataSegmentReflectionTest(...)class RangingDataSegmentReflectionTest : public testing::TestWithParam<std::vector<uint8_t>> { public: void CompareBytes(std::vector<uint8_t> captured_packet) {RangingDataSegmentView view = RangingDataSegmentView::FromBytes(captured_packet);if (!view.IsValid()) { log::info("Invalid Packet Bytes (size = {})", view.size());for (size_t i = 0; i < view.size(); i++) { log::info("{:5}:{:02x}", i, *(view.begin() + i)); }}ASSERT_TRUE(view.IsValid());auto packet = RangingDataSegmentBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);ASSERT_EQ(*packet_bytes, captured_packet);}};TEST_P(RangingDataSegmentReflectionTest, generatedReflectionTest) {CompareBytes(GetParam());}INSTANTIATE_TEST_SUITE_P(RangingDataSegment_reflection, RangingDataSegmentReflectionTest, testing::Values(__VA_ARGS__))
#endif
#if defined(PACKET_FUZZ_TESTING) || defined(PACKET_TESTING)
#define DEFINE_RangingDataSegmentReflectionFuzzTest() void RunRangingDataSegmentReflectionFuzzTest(const uint8_t* data, size_t size) {auto vec = std::vector<uint8_t>(data, data + size);RangingDataSegmentView view = RangingDataSegmentView::FromBytes(vec);if (!view.IsValid()) { return; }auto packet = RangingDataSegmentBuilder::FromView(view);std::shared_ptr<std::vector<uint8_t>> packet_bytes = std::make_shared<std::vector<uint8_t>>();packet_bytes->reserve(packet->size());BitInserter it(*packet_bytes);packet->Serialize(it);}
#endif

#ifdef PACKET_FUZZ_TESTING
#define DEFINE_AND_REGISTER_RangingDataSegmentReflectionFuzzTest(REGISTRY) DEFINE_RangingDataSegmentReflectionFuzzTest(); class RangingDataSegmentReflectionFuzzTestRegistrant {public: explicit RangingDataSegmentReflectionFuzzTestRegistrant(std::vector<void(*)(const uint8_t*, size_t)>& fuzz_test_registry) {fuzz_test_registry.push_back(RunRangingDataSegmentReflectionFuzzTest);}}; RangingDataSegmentReflectionFuzzTestRegistrant RangingDataSegment_reflection_fuzz_test_registrant(REGISTRY);
#endif


}  //namespace ras
}  //namespace bluetooth
#if __has_include(<bluetooth/log.h>)
namespace fmt {
template <>
struct formatter<bluetooth::ras::PctFormat> : enum_formatter<bluetooth::ras::PctFormat> {};
template <>
struct formatter<bluetooth::ras::RangingDoneStatus> : enum_formatter<bluetooth::ras::RangingDoneStatus> {};
template <>
struct formatter<bluetooth::ras::SubeventDoneStatus> : enum_formatter<bluetooth::ras::SubeventDoneStatus> {};
template <>
struct formatter<bluetooth::ras::RangingAbortReason> : enum_formatter<bluetooth::ras::RangingAbortReason> {};
template <>
struct formatter<bluetooth::ras::SubeventAbortReason> : enum_formatter<bluetooth::ras::SubeventAbortReason> {};
} // namespace fmt
#endif // __has_include(<bluetooth/log.h>)
