#ifndef NIDEVICE_GRPC_DEVICE_CONVERTERS_H
#define NIDEVICE_GRPC_DEVICE_CONVERTERS_H

#include <google/protobuf/repeated_field.h>
#include <google/protobuf/util/time_util.h>
#include <grpcpp/grpcpp.h>
#include <nidevice.pb.h>          // For common grpc types.
#include <server/common_types.h>  // For common C types.
#include <server/exceptions.h>

#include <algorithm>
#include <limits>
#include <nlohmann/json.hpp>
#include <numeric>
#include <string>
#include <vector>

namespace nidevice_grpc {
namespace converters {
inline void trim_trailing_nulls(std::string& s)
{
  // Erase from the first non-null character (going backwards) to the end.
  s.erase(
      std::find_if(
          s.rbegin(),
          s.rend(),
          [](unsigned char ch) { return ch != 0; })
          .base(),
      s.end());
}

enum MatchState {
  MISMATCH,
  MATCH,
  MATCH_OR_ZERO
};

struct LinkedArraySize {
  int size = 0;
  MatchState match_state = MatchState::MISMATCH;
};

template <size_t N>
inline LinkedArraySize calculate_linked_array_size(const std::array<int, N>& sizes, bool allow_optional)
{
  if (std::adjacent_find(sizes.begin(), sizes.end(), std::not_equal_to<>()) == sizes.end()) {
    return LinkedArraySize{sizes[0], MatchState::MATCH};
  }

  if (!allow_optional) {
    return LinkedArraySize{0, MatchState::MISMATCH};
  }

  int consensus_size = sizes[0];
  for (auto size_iter = sizes.begin() + 1; size_iter != sizes.end(); ++size_iter) {
    const auto size = *size_iter;
    if (size == consensus_size)
      ;  // pass
    else if (size == 0 || consensus_size == 0)
      consensus_size = std::max(size, consensus_size);
    else
      return LinkedArraySize{0, MatchState::MISMATCH};
  }

  return LinkedArraySize{consensus_size, MatchState::MATCH_OR_ZERO};
}

// Wrapper on std::vector that allows assigning or initializing from nullptr.
// When in an is_null_ state, data() will return nullptr.
// This class is intended to make it easier to write code that works with both
// vectors and pointers without complex, special-case codegen.
template <typename T>
class nullable_vector {
 public:
  nullable_vector(std::vector<T>&& vec) : vec_(std::move(vec)), is_null_(false)
  {
  }

  nullable_vector(std::nullptr_t) : vec_(), is_null_(true)
  {
  }

  nullable_vector<T>& operator=(std::nullptr_t)
  {
    vec_.clear();
    is_null_ = true;
    return *this;
  }

  T* data()
  {
    return is_null_ ? nullptr : vec_.data();
  }

  const T* data() const
  {
    return is_null_ ? nullptr : vec_.data();
  }

 private:
  bool is_null_;
  std::vector<T> vec_;
};

template <typename CType, typename GrpcType>
void convert_to_grpc(const CType& value, GrpcType* value_out)
{
  *value_out = static_cast<GrpcType>(value);
}

template <typename CType, typename GrpcType>
CType convert_from_grpc(const GrpcType& value)
{
  return static_cast<CType>(value);
}

template <typename CType, typename GrpcType>
inline nullable_vector<CType> convert_from_grpc(const google::protobuf::RepeatedPtrField<GrpcType>& input)
{
  auto output = std::vector<CType>();
  output.reserve(input.size());
  std::transform(
      input.begin(),
      input.end(),
      std::back_inserter(output),
      [&](GrpcType x) { return convert_from_grpc<CType>(x); });
  return nullable_vector<CType>(std::move(output));
}

template <typename CType, typename GrpcType>
inline std::vector<CType> convert_from_grpc(const google::protobuf::RepeatedField<GrpcType>& input)
{
  auto output = std::vector<CType>();
  output.reserve(input.size());
  std::transform(
      input.begin(),
      input.end(),
      std::back_inserter(output),
      [&](GrpcType x) { return convert_from_grpc<CType>(x); });
  return output;
}

template <typename GrpcType, typename CType>
inline void convert_to_grpc(const std::vector<CType>& input, google::protobuf::RepeatedPtrField<GrpcType>* output)
{
  for (auto item : input) {
    auto message = new GrpcType();
    convert_to_grpc(item, message);
    output->AddAllocated(message);
  }
}

template <typename BoolType>
inline void convert_to_grpc(const std::vector<BoolType>& input, google::protobuf::RepeatedField<bool>* output)
{
  for (auto item : input) {
    output->Add(item != BoolType(0));
  }
}

template <>
inline void convert_to_grpc(const NIComplexNumberF32_struct& input, nidevice_grpc::NIComplexNumberF32* output)
{
  output->set_real(input.real);
  output->set_imaginary(input.imaginary);
}

template <>
inline NIComplexNumberF32_struct convert_from_grpc(const nidevice_grpc::NIComplexNumberF32& input)
{
  auto output = NIComplexNumberF32_struct();
  output.real = input.real();
  output.imaginary = input.imaginary();
  return output;
}

template <>
inline void convert_to_grpc(const NIComplexSingle_struct& input, nidevice_grpc::NIComplexNumberF32* output)
{
  output->set_real(input.real);
  output->set_imaginary(input.imaginary);
}

template <>
inline NIComplexSingle_struct convert_from_grpc(const nidevice_grpc::NIComplexNumberF32& input)
{
  auto output = NIComplexSingle_struct();
  output.real = input.real();
  output.imaginary = input.imaginary();
  return output;
}

template <>
inline void convert_to_grpc(const NIComplexNumber_struct& input, nidevice_grpc::NIComplexNumber* output)
{
  output->set_real(input.real);
  output->set_imaginary(input.imaginary);
}

template <>
inline NIComplexNumber_struct convert_from_grpc(const nidevice_grpc::NIComplexNumber& input)
{
  auto output = NIComplexNumber_struct();
  output.real = input.real();
  output.imaginary = input.imaginary();
  return output;
}

template <>
inline void convert_to_grpc(const NIComplexDouble_struct& input, nidevice_grpc::NIComplexNumber* output)
{
  output->set_real(input.real);
  output->set_imaginary(input.imaginary);
}

template <>
inline NIComplexDouble_struct convert_from_grpc(const nidevice_grpc::NIComplexNumber& input)
{
  auto output = NIComplexDouble_struct();
  output.real = input.real();
  output.imaginary = input.imaginary();
  return output;
}

template <>
inline void convert_to_grpc(const NIComplexI16_struct& input, nidevice_grpc::NIComplexI16* output)
{
  output->set_real(input.real);
  output->set_imaginary(input.imaginary);
}

template <>
inline NIComplexI16_struct convert_from_grpc(const nidevice_grpc::NIComplexI16& input)
{
  auto output = NIComplexI16_struct();
  if (input.real() < (std::numeric_limits<ViInt16>::min)() || input.real() > (std::numeric_limits<ViInt16>::max)()) {
    std::string message("value ");
    message.append(std::to_string(input.real()));
    message.append(" doesn't fit in datatype ");
    message.append("ViInt16");
    throw nidevice_grpc::ValueOutOfRangeException(message);
  }
  output.real = static_cast<ViInt16>(input.real());
  if (input.imaginary() < (std::numeric_limits<ViInt16>::min)() || input.imaginary() > (std::numeric_limits<ViInt16>::max)()) {
    std::string message("value ");
    message.append(std::to_string(input.imaginary()));
    message.append(" doesn't fit in datatype ");
    message.append("ViInt16");
    throw nidevice_grpc::ValueOutOfRangeException(message);
  }
  output.imaginary = static_cast<ViInt16>(input.imaginary());
  return output;
}

template <typename SmtSpectrumInfoType>
inline void convert_to_grpc(const SmtSpectrumInfoType& input, nidevice_grpc::SmtSpectrumInfo* output)
{
  output->set_spectrum_type(input.spectrumType);
  output->set_linear_db(input.linearDB);
  output->set_window(input.window);
  output->set_window_size(input.windowSize);
  output->set_fft_size(input.FFTSize);
}

const int64 SecondsFromCVI1904EpochTo1970Epoch = 2082844800LL;
const double TwoToSixtyFour = (double)(1 << 31) * (double)(1 << 31) * (double)(1 << 2);
const double NanosecondsPerSecond = 1000000000.0;

template <>
inline void convert_to_grpc(const CVIAbsoluteTime& value, google::protobuf::Timestamp* timestamp)
{
  // msb is whole seconds after 12:00 a.m., Friday, January 1, 1904, Universal Time
  time_t unixTime = static_cast<time_t>(value.cviTime.msb - SecondsFromCVI1904EpochTo1970Epoch);
  google::protobuf::Timestamp temp_timestamp = google::protobuf::util::TimeUtil::TimeTToTimestamp(unixTime);

  timestamp->set_seconds(temp_timestamp.seconds());
  // lsb is positive fractions (2^64) of a second
  // This is losing some precision since doubles have 52 bits of precision.
  // But there are only 10^9 nanoseconds in a second which is ~31 bits of precision,
  // so it's still good enough for our purposes.
  timestamp->set_nanos(static_cast<int32>((static_cast<double>(value.cviTime.lsb) * NanosecondsPerSecond) / TwoToSixtyFour));
}

template <>
inline CVIAbsoluteTime convert_from_grpc(const google::protobuf::Timestamp& value)
{
  time_t unixTime = google::protobuf::util::TimeUtil::TimestampToTimeT(value);
  CVIAbsoluteTime cviTime;
  cviTime.cviTime.msb = static_cast<int64>(unixTime + SecondsFromCVI1904EpochTo1970Epoch);
  cviTime.cviTime.lsb = static_cast<uInt64>((static_cast<double>(value.nanos()) / NanosecondsPerSecond) * TwoToSixtyFour);
  return cviTime;
}

// Or together input_array and input_raw to implement the "bitfield_as_enum_array" feature for inputs.
// Note: TEnum is unused because protobuf C++ represents repeated enums as a int32 arrays.
template <typename TArray, typename TBitfield>
inline TBitfield convert_bitfield_as_enum_array_input(
    const TArray& input,
    TBitfield input_raw)
{
  const auto or_delegate = [](google::protobuf::int32 first, google::protobuf::int32 second) { return static_cast<TBitfield>(first | second); };
  return input_raw | std::accumulate(input.cbegin(), input.cend(), TBitfield{0}, or_delegate);
}

// TypeToStorageType should be specialized to define a (TDriverType, TGrpcType)->StorageType mapping, which
// will be used by allocate_output_storage.
template <typename TDriverType, typename TGrpcType>
struct TypeToStorageType {
  using StorageType = TDriverType;
};

// Constructs a default implementation of TypeToStorageType<TDriverType>::StorageType to use as an output_param.
// This should be customized by specializing the TypeToStorageType struct.
template <typename TDriverType, typename TGrpcType, typename... TArgs>
typename TypeToStorageType<TDriverType, TGrpcType>::StorageType allocate_output_storage(TArgs... args)
{
  using StorageType = typename TypeToStorageType<TDriverType, TGrpcType>::StorageType;
  return StorageType{args...};
}

}  // namespace converters

const int kMaxGrpcErrorDescriptionSize = 2048;

inline ::grpc::Status ApiErrorAndDescriptionToStatus(int32_t status, std::string& description, nlohmann::json& jsonError)
{
  converters::trim_trailing_nulls(description);
  jsonError["code"] = status;
  jsonError["message"] = description;
  return ::grpc::Status(grpc::StatusCode::UNKNOWN, nlohmann::to_string(jsonError));
}

inline ::grpc::Status ApiErrorAndDescriptionToStatus(int32_t status, std::string& description)
{
  nlohmann::json jsonError;
  return ApiErrorAndDescriptionToStatus(status, description, jsonError);
}

inline ::grpc::Status ApiErrorToStatus(int32_t status)
{
  std::string description("Unknown");
  return ApiErrorAndDescriptionToStatus(status, description);
}
}  // namespace nidevice_grpc

#endif /* NIDEVICE_GRPC_DEVICE_CONVERTERS_H */
