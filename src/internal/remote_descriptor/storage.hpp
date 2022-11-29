/**
 * SPDX-FileCopyrightText: Copyright (c) 2022, NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "srf/codable/api.hpp"
#include "srf/codable/encoded_object.hpp"
#include "srf/utils/macros.hpp"

#include <cstddef>
#include <cstdint>
#include <memory>

namespace srf::internal::remote_descriptor {

class Storage final
{
  public:
    Storage() = default;
    explicit Storage(std::unique_ptr<srf::codable::EncodedStorage> storage);

    ~Storage() = default;

    DELETE_COPYABILITY(Storage);
    DEFAULT_MOVEABILITY(Storage);

    const srf::codable::IDecodableStorage& encoding() const;

    std::size_t tokens_count() const;

    std::size_t decrement_tokens(std::size_t decrement_count);

  private:
    std::unique_ptr<srf::codable::EncodedStorage> m_storage;
    std::int32_t m_tokens{INT32_MAX};
};

}  // namespace srf::internal::remote_descriptor