/*
 * Copyright (c) 2022-present Samsung Electronics Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WABT_BINARY_READER_WALRUS_H_
#define WABT_BINARY_READER_WALRUS_H_

#define WABT_COMMON_H_

#include <cstddef>
#include <cstdarg>

#include "wabt/base-types.h"
#include "wabt/type.h"

namespace wabt {

class WASMBinaryReaderDelegate {
public:
    virtual ~WASMBinaryReaderDelegate() { }
    /* Module */
    virtual void BeginModule(uint32_t version) = 0;
    virtual void EndModule() = 0;

    virtual void OnTypeCount(Index count) = 0;
    virtual void OnFuncType(Index index, Index paramCount, Type *paramTypes, Index resultCount, Type *resultTypes) = 0;

    virtual void OnImportCount(Index count) = 0;
    virtual void OnImportFunc(Index importIndex, std::string moduleName, std::string fieldName, Index funcIndex, Index sigIndex) = 0;

    virtual void OnFunctionCount(Index count) = 0;
    virtual void OnFunction(Index index, Index sigIndex) = 0;

    virtual void OnStartFunction(Index funcIndex) = 0;

    virtual void BeginFunctionBody(Index index, Offset size) = 0;

    virtual void OnOpcode(uint32_t opcode) = 0;

    virtual void OnCallExpr(Index index) = 0;
    virtual void OnI32ConstExpr(uint32_t value) = 0;
    virtual void OnI64ConstExpr(uint64_t value) = 0;
    virtual void OnF32ConstExpr(float value) = 0;
    virtual void OnF64ConstExpr(double value) = 0;
    virtual void OnEndExpr() = 0;

    virtual void EndFunctionBody(Index index) = 0;
};

bool ReadWasmBinary(const uint8_t *data, size_t size, WASMBinaryReaderDelegate* delegate);

}  // namespace wabt

#endif /* WABT_BINARY_READER_WALRUS_H_ */
