/**
 * Copyright 2021 Huawei Technologies Co., Ltd
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
#ifndef NNACL_FP16_WHERE_FP16_H_
#define NNACL_FP16_WHERE_FP16_H_

#include "nnacl/op_base.h"
#include "nnacl/where_parameter.h"
#include "nnacl/kernel/where.h"

#ifdef __cplusplus
extern "C" {
#endif
void WhereWithTripleInputsFp16(const float16_t *x, const float16_t *y, float16_t *output, const WhereArgs *param,
                               int task_id, int thread_num);
#ifdef __cplusplus
}
#endif

#endif  //  NNACL_FP16_WHERE_FP16_H_
