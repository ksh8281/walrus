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

#ifndef __WalrusInstance__
#define __WalrusInstance__

#include "util/Vector.h"

namespace Walrus {

class Module;
class Function;

class Instance : public gc {
    friend class Module;
    Instance(Module* module)
        : m_module(module)
    {
    }

public:
    Module* module() const { return m_module; }

    Function* function(uint32_t index) const { return m_function[index]; }

private:
    Module* m_module;
    Vector<Function*, GCUtil::gc_malloc_allocator<Function*>> m_function;
};

} // namespace Walrus

#endif // __WalrusInstance__
