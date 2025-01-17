// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_L2CAPCLASSICMODULE_BLUETOOTH_L2CAP_CLASSIC_H_
#define FLATBUFFERS_GENERATED_L2CAPCLASSICMODULE_BLUETOOTH_L2CAP_CLASSIC_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 2 &&
              FLATBUFFERS_VERSION_MINOR == 0 &&
              FLATBUFFERS_VERSION_REVISION == 7,
             "Non-compatible flatbuffers version included");

namespace bluetooth {
namespace l2cap {
namespace classic {

struct ChannelData;
struct ChannelDataBuilder;

struct LinkData;
struct LinkDataBuilder;

struct L2capClassicModuleData;
struct L2capClassicModuleDataBuilder;

struct ChannelData FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef ChannelDataBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_CID = 4
  };
  int32_t cid() const {
    return GetField<int32_t>(VT_CID, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_CID, 4) &&
           verifier.EndTable();
  }
};

struct ChannelDataBuilder {
  typedef ChannelData Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_cid(int32_t cid) {
    fbb_.AddElement<int32_t>(ChannelData::VT_CID, cid, 0);
  }
  explicit ChannelDataBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<ChannelData> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<ChannelData>(end);
    return o;
  }
};

inline flatbuffers::Offset<ChannelData> CreateChannelData(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t cid = 0) {
  ChannelDataBuilder builder_(_fbb);
  builder_.add_cid(cid);
  return builder_.Finish();
}

struct LinkData FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef LinkDataBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ADDRESS = 4,
    VT_DYNAMIC_CHANNELS = 6,
    VT_FIXED_CHANNELS = 8
  };
  const flatbuffers::String *address() const {
    return GetPointer<const flatbuffers::String *>(VT_ADDRESS);
  }
  const flatbuffers::Vector<flatbuffers::Offset<bluetooth::l2cap::classic::ChannelData>> *dynamic_channels() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<bluetooth::l2cap::classic::ChannelData>> *>(VT_DYNAMIC_CHANNELS);
  }
  const flatbuffers::Vector<flatbuffers::Offset<bluetooth::l2cap::classic::ChannelData>> *fixed_channels() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<bluetooth::l2cap::classic::ChannelData>> *>(VT_FIXED_CHANNELS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_ADDRESS) &&
           verifier.VerifyString(address()) &&
           VerifyOffset(verifier, VT_DYNAMIC_CHANNELS) &&
           verifier.VerifyVector(dynamic_channels()) &&
           verifier.VerifyVectorOfTables(dynamic_channels()) &&
           VerifyOffset(verifier, VT_FIXED_CHANNELS) &&
           verifier.VerifyVector(fixed_channels()) &&
           verifier.VerifyVectorOfTables(fixed_channels()) &&
           verifier.EndTable();
  }
};

struct LinkDataBuilder {
  typedef LinkData Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_address(flatbuffers::Offset<flatbuffers::String> address) {
    fbb_.AddOffset(LinkData::VT_ADDRESS, address);
  }
  void add_dynamic_channels(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<bluetooth::l2cap::classic::ChannelData>>> dynamic_channels) {
    fbb_.AddOffset(LinkData::VT_DYNAMIC_CHANNELS, dynamic_channels);
  }
  void add_fixed_channels(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<bluetooth::l2cap::classic::ChannelData>>> fixed_channels) {
    fbb_.AddOffset(LinkData::VT_FIXED_CHANNELS, fixed_channels);
  }
  explicit LinkDataBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<LinkData> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<LinkData>(end);
    return o;
  }
};

inline flatbuffers::Offset<LinkData> CreateLinkData(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> address = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<bluetooth::l2cap::classic::ChannelData>>> dynamic_channels = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<bluetooth::l2cap::classic::ChannelData>>> fixed_channels = 0) {
  LinkDataBuilder builder_(_fbb);
  builder_.add_fixed_channels(fixed_channels);
  builder_.add_dynamic_channels(dynamic_channels);
  builder_.add_address(address);
  return builder_.Finish();
}

inline flatbuffers::Offset<LinkData> CreateLinkDataDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *address = nullptr,
    const std::vector<flatbuffers::Offset<bluetooth::l2cap::classic::ChannelData>> *dynamic_channels = nullptr,
    const std::vector<flatbuffers::Offset<bluetooth::l2cap::classic::ChannelData>> *fixed_channels = nullptr) {
  auto address__ = address ? _fbb.CreateString(address) : 0;
  auto dynamic_channels__ = dynamic_channels ? _fbb.CreateVector<flatbuffers::Offset<bluetooth::l2cap::classic::ChannelData>>(*dynamic_channels) : 0;
  auto fixed_channels__ = fixed_channels ? _fbb.CreateVector<flatbuffers::Offset<bluetooth::l2cap::classic::ChannelData>>(*fixed_channels) : 0;
  return bluetooth::l2cap::classic::CreateLinkData(
      _fbb,
      address__,
      dynamic_channels__,
      fixed_channels__);
}

struct L2capClassicModuleData FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef L2capClassicModuleDataBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_TITLE = 4,
    VT_ACTIVE_LINKS = 6
  };
  const flatbuffers::String *title() const {
    return GetPointer<const flatbuffers::String *>(VT_TITLE);
  }
  const flatbuffers::Vector<flatbuffers::Offset<bluetooth::l2cap::classic::LinkData>> *active_links() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<bluetooth::l2cap::classic::LinkData>> *>(VT_ACTIVE_LINKS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_TITLE) &&
           verifier.VerifyString(title()) &&
           VerifyOffset(verifier, VT_ACTIVE_LINKS) &&
           verifier.VerifyVector(active_links()) &&
           verifier.VerifyVectorOfTables(active_links()) &&
           verifier.EndTable();
  }
};

struct L2capClassicModuleDataBuilder {
  typedef L2capClassicModuleData Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_title(flatbuffers::Offset<flatbuffers::String> title) {
    fbb_.AddOffset(L2capClassicModuleData::VT_TITLE, title);
  }
  void add_active_links(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<bluetooth::l2cap::classic::LinkData>>> active_links) {
    fbb_.AddOffset(L2capClassicModuleData::VT_ACTIVE_LINKS, active_links);
  }
  explicit L2capClassicModuleDataBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<L2capClassicModuleData> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<L2capClassicModuleData>(end);
    return o;
  }
};

inline flatbuffers::Offset<L2capClassicModuleData> CreateL2capClassicModuleData(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> title = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<bluetooth::l2cap::classic::LinkData>>> active_links = 0) {
  L2capClassicModuleDataBuilder builder_(_fbb);
  builder_.add_active_links(active_links);
  builder_.add_title(title);
  return builder_.Finish();
}

inline flatbuffers::Offset<L2capClassicModuleData> CreateL2capClassicModuleDataDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *title = nullptr,
    const std::vector<flatbuffers::Offset<bluetooth::l2cap::classic::LinkData>> *active_links = nullptr) {
  auto title__ = title ? _fbb.CreateString(title) : 0;
  auto active_links__ = active_links ? _fbb.CreateVector<flatbuffers::Offset<bluetooth::l2cap::classic::LinkData>>(*active_links) : 0;
  return bluetooth::l2cap::classic::CreateL2capClassicModuleData(
      _fbb,
      title__,
      active_links__);
}

inline const bluetooth::l2cap::classic::L2capClassicModuleData *GetL2capClassicModuleData(const void *buf) {
  return flatbuffers::GetRoot<bluetooth::l2cap::classic::L2capClassicModuleData>(buf);
}

inline const bluetooth::l2cap::classic::L2capClassicModuleData *GetSizePrefixedL2capClassicModuleData(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<bluetooth::l2cap::classic::L2capClassicModuleData>(buf);
}

inline bool VerifyL2capClassicModuleDataBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<bluetooth::l2cap::classic::L2capClassicModuleData>(nullptr);
}

inline bool VerifySizePrefixedL2capClassicModuleDataBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<bluetooth::l2cap::classic::L2capClassicModuleData>(nullptr);
}

inline void FinishL2capClassicModuleDataBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<bluetooth::l2cap::classic::L2capClassicModuleData> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedL2capClassicModuleDataBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<bluetooth::l2cap::classic::L2capClassicModuleData> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace classic
}  // namespace l2cap
}  // namespace bluetooth

#endif  // FLATBUFFERS_GENERATED_L2CAPCLASSICMODULE_BLUETOOTH_L2CAP_CLASSIC_H_
