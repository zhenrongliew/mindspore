# Copyright 2020 Huawei Technologies Co., Ltd
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ============================================================================

import numpy as np
import pytest

import mindspore.context as context
import mindspore.nn as nn
from mindspore import Tensor
from mindspore.ops.operations import _inner_ops as inner


class NetSiLU(nn.Cell):
    def __init__(self):
        super(NetSiLU, self).__init__()
        self.silu = nn.SiLU()

    def construct(self, x):
        return self.silu(x)


class NetSiLUDynamic(nn.Cell):
    def __init__(self):
        super(NetSiLUDynamic, self).__init__()
        self.conv = inner.GpuConvertToDynamicShape()
        self.silu = nn.SiLU()

    def construct(self, x):
        x_conv = self.conv(x)
        return self.silu(x_conv)


@pytest.mark.level1
@pytest.mark.platform_x86_gpu_training
@pytest.mark.env_onecard
@pytest.mark.parametrize('mode', [context.GRAPH_MODE, context.PYNATIVE_MODE])
@pytest.mark.parametrize('dtype', [np.float32, np.float64])
def test_silu(mode, dtype):
    """
    Feature: silu kernel
    Description: test silu float32
    Expectation: test silu
    """
    x = Tensor(np.array([[[[-1, 1, 10],
                           [1, -1, 1],
                           [10, 1, -1]]]], dtype=dtype))
    expect = np.array([[[[-0.268941, 0.731059, 9.999546],
                         [0.731059, -0.268941, 0.731059],
                         [9.999546, 0.731059, -0.268941]]]], dtype=dtype)

    error = np.ones(shape=[1, 1, 3, 3]) * 1.0e-3

    context.set_context(mode=mode, device_target="GPU")
    silu = NetSiLU()
    output = silu(x)
    diff = output.asnumpy() - expect
    assert np.all(abs(diff) < error)


@pytest.mark.level1
@pytest.mark.platform_x86_gpu_training
@pytest.mark.env_onecard
@pytest.mark.parametrize('mode', [context.GRAPH_MODE, context.PYNATIVE_MODE])
@pytest.mark.parametrize('dtype', [np.float32, np.float64])
def test_silu_float32_dynamic_shape(mode, dtype):
    """
    Feature: silu kernel
    Description: test silu float32
    Expectation: test silu
    """
    x = Tensor(np.array([[[[-1, 1, 10],
                           [1, -1, 1],
                           [10, 1, -1]]]], dtype=dtype))
    expect = np.array([[[[-0.268941, 0.731059, 9.999546],
                         [0.731059, -0.268941, 0.731059],
                         [9.999546, 0.731059, -0.268941]]]], dtype=dtype)

    error = np.ones(shape=[1, 1, 3, 3]) * 1.0e-6

    context.set_context(mode=mode, device_target="GPU")
    silu_dynamic = NetSiLUDynamic()
    output = silu_dynamic(x)
    diff = output.asnumpy() - expect
    assert np.all(abs(diff) < error)
