// Copyright 2016 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef SHAKA_EMBEDDED_JS_IDB_OPEN_DB_REQUEST_H_
#define SHAKA_EMBEDDED_JS_IDB_OPEN_DB_REQUEST_H_

#include <string>

#include "shaka/optional.h"
#include "src/js/events/event_target.h"
#include "src/js/idb/request.h"
#include "src/mapping/backing_object_factory.h"

namespace shaka {
namespace js {
namespace idb {

class SqliteTransaction;

class IDBOpenDBRequest : public IDBRequest {
  DECLARE_TYPE_INFO(IDBOpenDBRequest);

 public:
  IDBOpenDBRequest(const std::string& name, optional<int64_t> version);

  void DoOperation(const std::string& db_path);

  void PerformOperation(SqliteTransaction* transaction) override;

  Listener on_upgrade_needed;

 private:
  const std::string name_;
  const optional<int64_t> version_;
};

class IDBOpenDBRequestFactory
    : public BackingObjectFactory<IDBOpenDBRequest, IDBRequest> {
 public:
  IDBOpenDBRequestFactory();
};

}  // namespace idb
}  // namespace js
}  // namespace shaka

#endif  // SHAKA_EMBEDDED_JS_IDB_OPEN_DB_REQUEST_H_
