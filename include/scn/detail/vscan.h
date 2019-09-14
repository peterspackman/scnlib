// Copyright 2017-2019 Elias Kosunen
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
//
// This file is a part of scnlib:
//     https://github.com/eliaskosunen/scnlib

#ifndef SCN_DETAIL_VSCAN_H
#define SCN_DETAIL_VSCAN_H

#include "context.h"
#include "visitor.h"

namespace scn {
    SCN_BEGIN_NAMESPACE

    namespace detail {
        struct default_t {
        };
    }  // namespace detail
    namespace {
        SCN_CONSTEXPR auto& default_tag =
            detail::static_const<detail::default_t>::value;
    }

    template <typename Context, typename ParseCtx>
    scan_result_for_t<Context> vscan(Context& ctx, ParseCtx& pctx)
    {
        return visit(ctx, pctx);
    }

    scan_result_for_t<basic_context<detail::range_wrapper_for_t<string_view>,
                                    basic_default_locale_ref<char>>>
    vscan(basic_context<detail::range_wrapper_for_t<string_view>,
                        basic_default_locale_ref<char>>&,
          basic_parse_context<basic_default_locale_ref<char>>&);

    scan_result_for_t<basic_context<detail::range_wrapper_for_t<string_view>,
                                    basic_default_locale_ref<char>>>
    vscan(basic_context<detail::range_wrapper_for_t<string_view>,
                        basic_default_locale_ref<char>>&,
          basic_empty_parse_context<basic_default_locale_ref<char>>&);

    scan_result_for_t<basic_context<detail::range_wrapper_for_t<string_view>,
                                    basic_default_locale_ref<char>>>
    vscan(basic_context<detail::range_wrapper_for_t<string_view>,
                        basic_locale_ref<char>>&,
          basic_parse_context<basic_default_locale_ref<char>>&);

    scan_result_for_t<basic_context<detail::range_wrapper_for_t<string_view>,
                                    basic_default_locale_ref<char>>>
    vscan(basic_context<detail::range_wrapper_for_t<string_view>,
                        basic_locale_ref<char>>&,
          basic_empty_parse_context<basic_default_locale_ref<char>>&);

    SCN_END_NAMESPACE
}  // namespace scn

#if defined(SCN_HEADER_ONLY) && SCN_HEADER_ONLY && !defined(SCN_VSCAN_CPP)
#include "vscan.cpp"
#endif

#endif  // SCN_DETAIL_VSCAN_H
