/**
 * Copyright 2019-2022 Huawei Technologies Co., Ltd
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

#ifndef PYBIND_API_EXPORT_FLAGS_H_
#define PYBIND_API_EXPORT_FLAGS_H_

namespace mindspore {
extern const char PYTHON_PRIMITIVE_FLAG[];
extern const char PYTHON_CELL_AS_DICT[];
extern const char PYTHON_CELL_AS_LIST[];
extern const char PYTHON_MS_CLASS[];
extern const char PYTHON_JIT_FORBIDDEN[];
extern const char PYTHON_CLASS_MEMBER_NAMESPACE[];
extern const char PYTHON_FUNCTION_FORBID_REUSE[];
}  // namespace mindspore

#endif  // PYBIND_API_EXPORT_FLAGS_H_
