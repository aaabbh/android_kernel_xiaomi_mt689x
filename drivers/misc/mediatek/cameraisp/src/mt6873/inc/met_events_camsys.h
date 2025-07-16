/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#undef TRACE_SYSTEM
#define TRACE_SYSTEM met_events_camsys
#if !defined(_TRACE_CAMSYS_EVENTS_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_CAMSYS_EVENTS_H
#include <linux/tracepoint.h>

// 事件1: 基本使能状态
TRACE_EVENT(ISP__Pass1_CAM_config,
    TP_PROTO(unsigned int hw_module, int imgo_en, int rrzo_en,
             int imgo_bpp, int rrzo_bpp),
    TP_ARGS(hw_module, imgo_en, rrzo_en, imgo_bpp, rrzo_bpp),
    TP_STRUCT__entry(
        __field(unsigned int, hw_module)
        __field(int, imgo_en)
        __field(int, rrzo_en)
        __field(int, imgo_bpp)
        __field(int, rrzo_bpp)
    ),
    TP_fast_assign(
        __entry->hw_module = hw_module;
        __entry->imgo_en = imgo_en;
        __entry->rrzo_en = rrzo_en;
        __entry->imgo_bpp = imgo_bpp;
        __entry->rrzo_bpp = rrzo_bpp;
    ),
    TP_printk("_id=%d, imgo_en=%d, rrzo_en=%d, imgo_bpp=%d, rrzo_bpp=%d",
        __entry->hw_module, __entry->imgo_en, __entry->rrzo_en,
        __entry->imgo_bpp, __entry->rrzo_bpp)
);

// 事件2: 图像尺寸信息
TRACE_EVENT(ISP__Pass1_CAM_size,
    TP_PROTO(unsigned int hw_module,
             int imgo_w_in_byte, int imgo_h_in_byte,
             int rrzo_w_in_byte, int rrzo_h_in_byte),
    TP_ARGS(hw_module, imgo_w_in_byte, imgo_h_in_byte, rrzo_w_in_byte, rrzo_h_in_byte),
    TP_STRUCT__entry(
        __field(unsigned int, hw_module)
        __field(int, imgo_w_in_byte)
        __field(int, imgo_h_in_byte)
        __field(int, rrzo_w_in_byte)
        __field(int, rrzo_h_in_byte)
    ),
    TP_fast_assign(
        __entry->hw_module = hw_module;
        __entry->imgo_w_in_byte = imgo_w_in_byte;
        __entry->imgo_h_in_byte = imgo_h_in_byte;
        __entry->rrzo_w_in_byte = rrzo_w_in_byte;
        __entry->rrzo_h_in_byte = rrzo_h_in_byte;
    ),
    TP_printk("_id=%d, imgo=%dx%d, rrzo=%dx%d",
        __entry->hw_module,
        __entry->imgo_w_in_byte, __entry->imgo_h_in_byte,
        __entry->rrzo_w_in_byte, __entry->rrzo_h_in_byte)
);

// 事件3: 重采样(RRZ)配置
TRACE_EVENT(ISP__Pass1_CAM_rrz,
    TP_PROTO(unsigned int hw_module,
             int rrz_src_w, int rrz_src_h, int rrz_dst_w,
             int rrz_dst_h, int rrz_hori_step, int rrz_vert_step),
    TP_ARGS(hw_module, rrz_src_w, rrz_src_h, rrz_dst_w, rrz_dst_h, rrz_hori_step, rrz_vert_step),
    TP_STRUCT__entry(
        __field(unsigned int, hw_module)
        __field(int, rrz_src_w)
        __field(int, rrz_src_h)
        __field(int, rrz_dst_w)
        __field(int, rrz_dst_h)
        __field(int, rrz_hori_step)
        __field(int, rrz_vert_step)
    ),
    TP_fast_assign(
        __entry->hw_module = hw_module;
        __entry->rrz_src_w = rrz_src_w;
        __entry->rrz_src_h = rrz_src_h;
        __entry->rrz_dst_w = rrz_dst_w;
        __entry->rrz_dst_h = rrz_dst_h;
        __entry->rrz_hori_step = rrz_hori_step;
        __entry->rrz_vert_step = rrz_vert_step;
    ),
    TP_printk("_id=%d, rrz_src=%dx%d, rrz_dst=%dx%d, step=%dx%d",
        __entry->hw_module,
        __entry->rrz_src_w, __entry->rrz_src_h,
        __entry->rrz_dst_w, __entry->rrz_dst_h,
        __entry->rrz_hori_step, __entry->rrz_vert_step)
);

// 事件4: 控制寄存器状态
TRACE_EVENT(ISP__Pass1_CAM_ctl,
    TP_PROTO(unsigned int hw_module, u32 ctl_en, u32 ctl_dma_en, u32 ctl_en2),
    TP_ARGS(hw_module, ctl_en, ctl_dma_en, ctl_en2),
    TP_STRUCT__entry(
        __field(unsigned int, hw_module)
        __field(u32, ctl_en)
        __field(u32, ctl_dma_en)
        __field(u32, ctl_en2)
    ),
    TP_fast_assign(
        __entry->hw_module = hw_module;
        __entry->ctl_en = ctl_en;
        __entry->ctl_dma_en = ctl_dma_en;
        __entry->ctl_en2 = ctl_en2;
    ),
    TP_printk("_id=%d, CTL_EN=0x%x, CTL_DMA_EN=0x%x, CTL_EN2=0x%x",
        __entry->hw_module,
        __entry->ctl_en, __entry->ctl_dma_en, __entry->ctl_en2)
);

// 保留原始离开事件
TRACE_EVENT(ISP__Pass1_CAM_leave,
    TP_PROTO(unsigned int hw_module, int dummy),
    TP_ARGS(hw_module, dummy),
    TP_STRUCT__entry(
        __field(unsigned int, hw_module)
        __field(int, dummy)
    ),
    TP_fast_assign(
        __entry->hw_module = hw_module;
        __entry->dummy = dummy;
    ),
    TP_printk("_id=%d", __entry->hw_module)
);

#endif /* _TRACE_CAMSYS_EVENTS_H */

#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH ./inc
#undef TRACE_INCLUDE_FILE
#define TRACE_INCLUDE_FILE met_events_camsys
#include <trace/define_trace.h>