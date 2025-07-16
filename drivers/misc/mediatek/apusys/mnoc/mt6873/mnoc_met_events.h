/*
 * Copyright (C) 2019 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */
#define MNOC_PMU_POLL_STR1 "c1=%u, c2=%u, c3=%u, c4=%u, c5=%u, c6=%u, "
#define MNOC_PMU_POLL_STR2 "c7=%u, c8=%u, c9=%u, c10=%u, c11=%u, "
#define MNOC_PMU_POLL_STR3 "c12=%u, c13=%u, c14=%u, c15=%u, c16=%u, "

#define MNOC_PMU_POLL_STR4 "c17=%u, c18=%u, c19=%u, c20=%u, c21=%u, c22=%u, "
#define MNOC_PMU_POLL_STR5 "c23=%u, c24=%u, c25=%u, c26=%u, c27=%u, "
#define MNOC_PMU_POLL_STR6 "c28=%u, c29=%u, c30=%u, c31=%u, c32=%u, "

#define MNOC_PMU_POLL_STR7 "c33=%u, c34=%u, c35=%u, c36=%u, c37=%u, c38=%u, "
#define MNOC_PMU_POLL_STR8 "c39=%u, c40=%u, c41=%u, c42=%u, c43=%u, "
#define MNOC_PMU_POLL_STR9 "c44=%u, c45=%u, c46=%u, c47=%u, c48=%u, "

#define MNOC_PMU_POLL_STR10 "c49=%u, c50=%u, c51=%u, c52=%u, c53=%u, c54=%u, "
#define MNOC_PMU_POLL_STR11 "c55=%u, c56=%u, c57=%u, c58=%u, c59=%u, "
#define MNOC_PMU_POLL_STR12 "c60=%u, c61=%u, c62=%u, c63=%u, c64=%u, "

#define MNOC_PMU_POLL_STR13 "c65=%u, c66=%u, c67=%u, c68=%u, c69=%u, c70=%u, "
#define MNOC_PMU_POLL_STR14 "c71=%u, c72=%u, c73=%u, c74=%u, c75=%u, "
#define MNOC_PMU_POLL_STR15 "c76=%u, c77=%u, c78=%u, c79=%u, c80=%u"
#undef TRACE_SYSTEM
#define TRACE_SYSTEM mnoc_met_events
#if !defined(_TRACE_MNOC_MET_EVENTS_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_MNOC_MET_EVENTS_H
#include <linux/tracepoint.h>
#include "mnoc_hw.h"
TRACE_EVENT(mnoc_pmu_polling,
    TP_PROTO(u32 *c),
    TP_ARGS(c),
    TP_STRUCT__entry(
        __dynamic_array(u32, c, NR_MNOC_PMU_CNTR * sizeof(u32))  // 显式指定大小
    ),
    TP_fast_assign(
        memcpy(__get_dynamic_array(c), c, NR_MNOC_PMU_CNTR * sizeof(u32));
    ),
    TP_printk(
        MNOC_PMU_POLL_STR1 MNOC_PMU_POLL_STR2 MNOC_PMU_POLL_STR3
        MNOC_PMU_POLL_STR4 MNOC_PMU_POLL_STR5 MNOC_PMU_POLL_STR6
        MNOC_PMU_POLL_STR7 MNOC_PMU_POLL_STR8 MNOC_PMU_POLL_STR9
        MNOC_PMU_POLL_STR10 MNOC_PMU_POLL_STR11 MNOC_PMU_POLL_STR12
        MNOC_PMU_POLL_STR13 MNOC_PMU_POLL_STR14 MNOC_PMU_POLL_STR15,
        ((u32 *)__get_dynamic_array(c))[0],  // 通过指针访问动态数组
        ((u32 *)__get_dynamic_array(c))[1],
        // ... 依次填充所有 80 个元素
        ((u32 *)__get_dynamic_array(c))[79]
    )
);

#endif /* _TRACE_MNOC_MET_EVENTS_H */
/* This part must be outside protection */
#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH .
#undef TRACE_INCLUDE_FILE
#define TRACE_INCLUDE_FILE mnoc_met_events
#include <trace/define_trace.h>
