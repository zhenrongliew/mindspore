/**
 * Copyright 2023 Huawei Technologies Co., Ltd
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
#include <vector>
#include <memory>
#include "common/common_test.h"
#include "ops/rank.h"
#include "ir/dtype/type.h"
#include "abstract/dshape.h"
#include "utils/tensor_construct_utils.h"
#include "ir/primitive.h"
#include "abstract/abstract_value.h"
#include "utils/ms_context.h"
#include "ops/test_ops.h"
#include "include/backend/optimizer/helper.h"
#include "ops/op_utils.h"

namespace mindspore {
namespace ops {
struct RankOpParams {
  ShapeVector input_shape;
  TypePtr input_type;
  TypePtr out_type;
};

class TestRank : public TestOps, public testing::WithParamInterface<RankOpParams> {};

TEST_P(TestRank, dyn_shape) {
  const auto &param = GetParam();
  auto input = std::make_shared<abstract::AbstractTensor>(param.input_type, param.input_shape);
  ASSERT_NE(input, nullptr);
  auto expect = abstract::MakeAbstract(abstract::kNoShape, param.out_type);

  ValuePtr expect_value;
  if (IsDynamicRank(param.input_shape)) {
    expect_value = kValueAny;
  } else {
    auto x_shape_rank = SizeToLong(param.input_shape.size());
    expect_value = MakeValue(x_shape_rank);
  }
  expect->set_value(expect_value);

  auto prim = std::make_shared<Primitive>(kNameRank);
  auto out_abstract = opt::CppInferShapeAndType(prim, {input});
  ASSERT_NE(out_abstract, nullptr);
  ASSERT_TRUE(*out_abstract == *expect);
}

INSTANTIATE_TEST_CASE_P(TestRankGroup, TestRank,
                        testing::Values(RankOpParams{{2, 3}, kFloat32, kInt64},
                                        RankOpParams{{-1, -1}, kFloat32, kInt64},
                                        RankOpParams{{-2}, kFloat32, kInt64}));
}  // namespace ops
}  // namespace mindspore
