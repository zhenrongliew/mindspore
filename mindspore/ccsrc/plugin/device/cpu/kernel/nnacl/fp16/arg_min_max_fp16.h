/**
 * Copyright 2020 Huawei Technologies Co., Ltd
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
#ifndef NNACL_FP16_ARG_MIN_MAX_FP16_H_
#define NNACL_FP16_ARG_MIN_MAX_FP16_H_

#include <float.h>
#include "nnacl/arg_min_max_parameter.h"
#include "nnacl/nnacl_common.h"
#include "nnacl/kernel/arg_min_max.h"

#ifdef __cplusplus
extern "C" {
#endif
void ArgMinMaxFp16(const float16_t *input, void *output, float16_t *output_value, const int *in_shape,
                   const ArgMinMaxComputeParam *param);
#ifdef __cplusplus
}
#endif

#endif  //  NNACL_FP16_ARG_MIN_MAX_FP16_H_
