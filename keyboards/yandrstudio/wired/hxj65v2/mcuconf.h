// Copyright 2023 Y&R-studio (@superYoungMonk)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include_next <mcuconf.h>

#undef  STM32_PLLXTPRE
#define STM32_PLLXTPRE STM32_PLLXTPRE_DIV2

#undef STM32_PWM_USE_TIM2
#define STM32_PWM_USE_TIM2 TRUE
